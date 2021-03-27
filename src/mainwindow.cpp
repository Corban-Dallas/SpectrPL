#include <QHBoxLayout>
#include <QDir>
#include <QtDebug>
#include <QMessageBox>
#include <QSerialPort>

#include "mainwindow.h"
#include "ui_mainwindow.h"

Parameters globalParams;
GlobalRequests globalRequests;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Читаем файл параметров
    readSettings();

    // SMD and CNT
    smd = new SMD();
    cnt = new CNT();
    smdThread = new QThread();
    cntThread = new QThread();

    smd->moveToThread(smdThread);
    cnt->moveToThread(cntThread);
    smdThread->start();
    cntThread->start();

    connect(ui->actionConnect, &QAction::triggered, smd, &SMD::openPort);
    connect(ui->actionConnect, &QAction::triggered, cnt, &CNT::openPort);
    connect(ui->actionDisconnect, &QAction::triggered, smd, &SMD::closePort);
    connect(ui->actionDisconnect, &QAction::triggered, cnt, &CNT::closePort);

    connect(smd, &SMD::portOpened, this, &MainWindow::updateSmdPortState);
    connect(cnt, &CNT::portOpened, this, &MainWindow::updateCntPortState);

    // Command Server
    cs = new CommandServer(smd, cnt, this);
    connect(cs, &CommandServer::wlUpdated,
            ui->dsb_current_wl, &QDoubleSpinBox::setValue);

    // WokerThread
    workerThread = new QThread();

    connect(workerThread, &QThread::started,
            this, &MainWindow::setGuiModeWorking);
    connect(workerThread, &QThread::finished,
            this, &MainWindow::setGuiModeReady);
    connect(workerThread, &QThread::started,
            smd, &SMD::powerOn);
    connect(workerThread, &QThread::finished,
            smd, &SMD::powerOff);

    // Emergency Stop
    connect(ui->pbEmStop, &QPushButton::clicked,
            smd, &SMD::stop);

    // Port Dialog
    portDialog = new PortDialog(this);

    connect(ui->actionSerialPort, &QAction::triggered,
            portDialog, &PortDialog::show);

    // Position Dialog
    posDialog = new PositionDialog(this);

    connect(cs, &CommandServer::stUpdated,
            posDialog, &PositionDialog::updatePosition);
    connect(posDialog, &PositionDialog::resetPosition,
            cs, &CommandServer::reqSmdResetStep);
    connect(posDialog, SIGNAL(okClicked()),
            this, SLOT(recalcFastScanStep()));
    connect(ui->actionPosition, &QAction::triggered,
            posDialog, &PositionDialog::show);

    // Scan Profiles Dialog
    scanDialog = new ScanDialog(this);

    connect(scanDialog, SIGNAL(okClicked()),
            this, SLOT(recalcFastScanStep()));
    connect(ui->actionScanProfiles, &QAction::triggered,
            scanDialog, &ScanDialog::show);
    connect(scanDialog, &ScanDialog::setCntDac,
            cs, &CommandServer::setCntDac);

    // Debug Dialog
    debugDialog = new DebugDialog(smd);
    connect(ui->actionDebug_panel, &QAction::triggered,
            debugDialog, &DebugDialog::show);
    connect(cs, &CommandServer::stUpdated,
            debugDialog, &DebugDialog::updatePosition);

    // Log
    log = new Log("log.txt");

    // Spectra Storage Widget
    storage = new SpectraStorage();
    ui->gbData->layout()->addWidget(storage);

    // Graph Widget
    graph = new Graph();
    ui->rightLayout->addWidget(graph);
    connect(storage, &SpectraStorage::changePlot,
            graph, &Graph::plot);

    // Connect other slots
    connect(ui->actionSave, &QAction::triggered,
            this, &MainWindow::saveSpectra);
    connect(ui->sbTime, SIGNAL(valueChanged(int)),
            this, SLOT(recalcFastScanStep()));


    // Initial state
    ui->actionFastScaning->trigger();
    //setGuiModeNotReady();
    setGuiModeReady();
}

void MainWindow::writeSettings() {
    settings->beginGroup("SMD");
    settings->setValue("portName", globalParams.smd.port.portName);
    settings->endGroup();

    settings->beginGroup("CNT");
    settings->setValue("portName", globalParams.cnt.port.portName);
    settings->setValue("acquisition", globalParams.cnt.acquisition);
    settings->setValue("dac", globalParams.cnt.dac);
    settings->endGroup();

    settings->beginGroup("APPLICATION");
    settings->setValue("defSpeed", globalParams.app.defSpeed);
    settings->setValue("defAccel", globalParams.app.defAccel);
    settings->setValue("scanSpeed", globalParams.app.scanSpeed);
    settings->setValue("scanAccel", globalParams.app.scanAccel);
    settings->setValue("fScanSpeed", globalParams.app.fScanSpeed);
    settings->setValue("fScanAccel", globalParams.app.fScanAccel);
    settings->setValue("luft", globalParams.app.luft);
    settings->setValue("coefA", globalParams.app.coefA);
    settings->setValue("coefB", ui->dsb_current_wl->value() - globalParams.app.error);
    settings->setValue("error", globalParams.app.error);
    settings->endGroup();

    settings->beginGroup("GRAPH");
    settings->setValue("autoX", globalParams.graph.autoX);
    settings->setValue("autoY", globalParams.graph.autoY);
    settings->setValue("logY", globalParams.graph.logY);
    settings->setValue("monitorPointsCount", globalParams.graph.monitorPoints);
    settings->endGroup();
}

void MainWindow::readSettings() {
    qDebug() << "[MainWindow] Read settings";
    QDir dir;
    settings = new QSettings(dir.absolutePath() + "/SpectrPL.ini", QSettings::IniFormat);

    settings->beginGroup("SMD");
    globalParams.smd.port.portName = settings->value("portName", "ttyUSB").toString();
    settings->endGroup();

    settings->beginGroup("CNT");
    globalParams.cnt.port.portName = settings->value("portName", "tty0").toString();
    globalParams.cnt.acquisition = settings->value("acquisition", 1).toInt();
    globalParams.cnt.dac = settings->value("dac", 254).toInt();
    settings->endGroup();

    settings->beginGroup("APPLICATION");
    globalParams.app.defSpeed = settings->value("defSpeed", globalParams.app.defSpeed).toInt();
    globalParams.app.defAccel = settings->value("defAccel", globalParams.app.defAccel).toInt();
    globalParams.app.scanSpeed = settings->value("scanSpeed", globalParams.app.scanSpeed).toInt();
    globalParams.app.scanAccel = settings->value("scanAccel", globalParams.app.scanAccel).toInt();
    globalParams.app.fScanSpeed = settings->value("fScanSpeed", globalParams.app.fScanSpeed).toInt();
    globalParams.app.fScanAccel = settings->value("fScanAccel", globalParams.app.fScanAccel).toInt();
    globalParams.app.luft = settings->value("luft", globalParams.app.luft).toInt();
    globalParams.app.coefA = settings->value("coefA", globalParams.app.coefA).toDouble();
    globalParams.app.coefB = settings->value("coefB", globalParams.app.coefB).toDouble();
    globalParams.app.error = settings->value("error", globalParams.app.error).toDouble();
    settings->endGroup();

    settings->beginGroup("GRAPH");
    globalParams.graph.autoX = settings->value("autoX", globalParams.graph.autoX).toBool();
    globalParams.graph.autoY = settings->value("autoY", globalParams.graph.autoY).toBool();
    globalParams.graph.logY = settings->value("logY", globalParams.graph.logY).toBool();
    globalParams.graph.monitorPoints = settings->value("monitorPoints", globalParams.graph.monitorPoints).toInt();
    settings->endGroup();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    bool focus = ui->dsb_current_wl->hasFocus();
    bool read_only = ui->dsb_current_wl->isReadOnly();

    if (event->key() == Qt::Key_Return && !read_only && focus) {
        int new_position = ui->dsb_current_wl->value();
        qDebug() << "[MainWindow] Go to wavelength " << new_position;
        ChangePosition(new_position);
    }
    else QMainWindow::keyPressEvent(event);
}

void MainWindow::updateSmdPortState(bool connected) {
    smdConnected = connected;
    if ((smdConnected && cntConnected) == true) setGuiModeReady();
    else setGuiModeNotReady();
}

void MainWindow::updateCntPortState(bool connected) {
    cntConnected = connected;
    if ((smdConnected && cntConnected) == true) setGuiModeReady();
    else setGuiModeNotReady();
}

// PUBLIC SLOTS
void MainWindow::setGuiModeReady() {
    // Actions
    ui->actionScaning->setEnabled(true);
    ui->actionFastScaning->setEnabled(true);
    ui->actionMonitor->setEnabled(true);
    ui->actionConnect->setEnabled(false);
    ui->actionDisconnect->setEnabled(true);
    ui->actionPosition->setEnabled(true);
    ui->actionScanProfiles->setEnabled(true);
    ui->actionSerialPort->setEnabled(false);
    // Control box
    ui->gbControl->setEnabled(true);
    ui->sbBegin->setReadOnly(false);
    ui->sbEnd->setReadOnly(false);
    ui->sbStep->setReadOnly(false);
    ui->sbTime->setReadOnly(false);
    ui->sbPoints->setReadOnly(false);
    ui->dsb_current_wl->setReadOnly(false);
    ui->pbStart->setEnabled(true);
    ui->pbStop->setEnabled(false);
    ui->rbChanel1->setEnabled(true);
    ui->rbChanel2->setEnabled(true);
    // Data box
    ui->gbData->setEnabled(true);
}

void MainWindow::setGuiModeNotReady() {
    // Actions
    ui->actionScaning->setEnabled(false);
    ui->actionFastScaning->setEnabled(false);
    ui->actionMonitor->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionPosition->setEnabled(false);
    ui->actionScanProfiles->setEnabled(false);
    ui->actionSerialPort->setEnabled(true);
    // Control box
    ui->gbControl->setEnabled(false);
}

void MainWindow::setGuiModeWorking() {
    // Actions
    ui->actionScaning->setEnabled(false);
    ui->actionFastScaning->setEnabled(false);
    ui->actionMonitor->setEnabled(false);
    ui->actionConnect->setEnabled(false);
    ui->actionDisconnect->setEnabled(false);
    ui->actionPosition->setEnabled(false);
    ui->actionScanProfiles->setEnabled(false);
    // Control box
    ui->sbBegin->setReadOnly(true);
    ui->sbEnd->setReadOnly(true);
    ui->sbStep->setReadOnly(true);
    ui->sbTime->setReadOnly(true);
    ui->sbPoints->setReadOnly(true);
    ui->dsb_current_wl->setReadOnly(true);
    ui->pbStart->setEnabled(false);
    ui->pbStop->setEnabled(true);
    ui->rbChanel1->setEnabled(false);
    ui->rbChanel2->setEnabled(false);
    // Data box
    ui->gbData->setEnabled(false);
}

void MainWindow::saveSpectra() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save storage", "", "ANSI (*.dat)");
    if (fileName.isEmpty()) {
        qDebug() << "[MainWindow] No file was chosen.";
        return;
    }
    if (!fileName.endsWith(".dat")) fileName += ".dat";

    QFile saveFile(fileName);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qDebug() << "[MainWindow] Can't open file for writing";
        return;
    }
    QTextStream stream(&saveFile);

    QVector<QPointF> points = storage->getSpectrum()->points();

    for (auto point : points)
        stream << QString("%1 %2\r").arg(point.x(),0, 'f', 2).arg(point.y(),0,'f',1) << endl;

    saveFile.close();
    storage->getSpectrum()->setSaved(true);
    storage->setRowText(fileName);
    qDebug() << "[MainWindow] Spectrum saved";
}

void MainWindow::showErrorMessage(QString msg) {
    QMessageBox::critical(this, "Error", msg);
}

void MainWindow::on_pbStart_clicked() {  
    double begin = ui->sbBegin->value();
    double end = ui->sbEnd->value();
    double step = ui->sbStep->value();
    ushort acquisition = ui->sbTime->value();
    uchar channel = 0;
    if (ui->rbChanel1->isChecked()) channel = 1;

    // SCANING
    if (ui->actionScaning->isChecked()) StartScan(begin, end, step, acquisition, channel);
    // FAST SCANING
    if (ui->actionFastScaning->isChecked()) StartFastScan(begin, end, acquisition, channel);
    // MONITOR        
    if (ui->actionMonitor->isChecked()) StartMonitor(acquisition, channel);
    return;
}

void MainWindow::on_pbStop_clicked() {
    globalRequests.stopWork = true;
}

void MainWindow::StartScan(double begin, double end, double step,
                           ushort acquisition, uchar channel) {
    qDebug() << "[MainWindow] Start ScanWorker";

    if (end > begin) graph->setXRange(begin, end);
    else graph->setXRange(end, begin);

    ScanParameters params;
    params.begin = begin;
    params.end = end;
    params.step = step;
    params.acquisition = acquisition;
    params.channel = channel;

    scanWorker = new ScanWorker(cs, params);
    scanWorker->moveToThread(workerThread);

    // Start
    connect(workerThread, &QThread::started,
            scanWorker, &ScanWorker::start);
    connect(scanWorker, &ScanWorker::started,
            graph, &Graph::startPlot);
    connect(scanWorker, &ScanWorker::started,
            storage, &SpectraStorage::startSpectrum);

    // Proceed
    connect(scanWorker, &ScanWorker::newPoint,
            graph, &Graph::addPoint);
    connect(scanWorker, &ScanWorker::newPoint,
            storage, &SpectraStorage::addPoint);

    // Stop
    connect(scanWorker, &ScanWorker::stoped,
            graph, &Graph::finishPlot);
    connect(scanWorker, &ScanWorker::stoped,
            storage, &SpectraStorage::finishSpectrum);
    connect(scanWorker, &ScanWorker::stoped,
            workerThread, &QThread::quit);
    connect(workerThread, &QThread::finished,
            scanWorker, &ScanWorker::deleteLater);

    workerThread->start();
}

void MainWindow::StartFastScan(double begin, double end,
                           ushort acquisition, uchar channel) {
    qDebug() << "[MainWindow] FastStart ScanWorker";

    if (end > begin) graph->setXRange(begin, end);
    else graph->setXRange(end, begin);

    ScanParameters params;
    params.begin = begin;
    params.end = end;
    params.acquisition = acquisition;
    params.channel = channel;

    fastScanWorker = new FastScanWorker(cs, params);
    fastScanWorker->moveToThread(workerThread);

    // Start
    connect(workerThread, &QThread::started,
            fastScanWorker, &FastScanWorker::start);
    connect(fastScanWorker, &FastScanWorker::started,
            graph, &Graph::startPlot);
    connect(fastScanWorker, &FastScanWorker::started,
            storage, &SpectraStorage::startSpectrum);
    // Proceed
    connect(fastScanWorker, &FastScanWorker::newPoint,
            graph, &Graph::addPoint);
    connect(fastScanWorker, &FastScanWorker::newPoint,
            storage, &SpectraStorage::addPoint);
    // End
    connect(fastScanWorker, &FastScanWorker::stoped,
            graph, &Graph::finishPlot);
    connect(fastScanWorker, &FastScanWorker::stoped,
            storage, &SpectraStorage::finishSpectrum);
    connect(fastScanWorker, &FastScanWorker::stoped,
            workerThread, &QThread::quit);
    connect(workerThread, &QThread::finished,
            fastScanWorker, &FastScanWorker::deleteLater);

    workerThread->start();
}

void MainWindow::StartMonitor(ushort acquisition, uchar channel) {
    qDebug() << "[MainWindow] Start MonitorWorker";

    monitorWorker = new MonitorWorker(cs, acquisition, channel);
    monitorWorker->moveToThread(workerThread);

    // Start
    connect(workerThread, &QThread::started,
            monitorWorker, &MonitorWorker::start);
    connect(monitorWorker, &MonitorWorker::started,
            graph, &Graph::startMonitor);

    // Proceed
    connect(monitorWorker, &MonitorWorker::newPoint,
            graph, &Graph::addMonitorPoint);

    // Stop
    connect(monitorWorker, &MonitorWorker::stoped,
            graph, &Graph::stopMonitor);
    connect(monitorWorker, &MonitorWorker::stoped,
            workerThread, &QThread::quit);
    connect(workerThread, &QThread::finished,
            monitorWorker, &MonitorWorker::deleteLater);

    workerThread->start();
}

void MainWindow::ChangePosition(double wavelength) {
    gotoWorker = new GotoWavelengthWorker(cs, wavelength);
    gotoWorker->moveToThread(workerThread);

    // m2pWorker & Thread
    connect(workerThread, &QThread::started,
            gotoWorker, &GotoWavelengthWorker::start);
    connect(gotoWorker, &GotoWavelengthWorker::stoped,
            workerThread, &QThread::quit);
    connect(workerThread, &QThread::finished,
            gotoWorker, &GotoWavelengthWorker::deleteLater);

    workerThread->start();
}

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, "About", "Organisation: ISP SB RAS\n"
                                      "Author: Grogory Krivyakin\n"
                                      "Contact: krivyakin@isp.nsc.ru");
}

void MainWindow::closeEvent(QCloseEvent *event) {
    qDebug() << "[MainWindow] Close event";
    qDebug() << "[MainWindow] All data are saved:" << storage->isAllSaved();

    if (!storage->isAllSaved()) {
        QMessageBox::StandardButton answer;
        answer = QMessageBox::question(this, "Exit",
            "Not all data were saved. Do you realy want to quit?");
            if (answer == QMessageBox::StandardButton::Yes) {
                globalRequests.stopSmd = true;
                //globalRequests.stopSubthread = true;
                ui->actionDisconnect->trigger();
                writeSettings();
                //if (port->isOpen()) port->close();
                event->accept();
                return;
            }
            else event->ignore();
    }
    else {
        ui->actionDisconnect->trigger();
        writeSettings();
        event->accept();
    }
}

void MainWindow::on_actionMonitor_triggered() {
    ui->actionFastScaning->setChecked(false);
    ui->actionScaning->setChecked(false);
    ui->actionMonitor->setChecked(true);
    ui->lbBegin->hide();
    ui->sbBegin->hide();
    ui->lbEnd->hide();
    ui->sbEnd->hide();
    ui->lbStep->hide();
    ui->sbStep->hide();
    ui->lbPoints->show();
    ui->sbPoints->show();
}

void MainWindow::on_actionFastScaning_triggered() {
    ui->actionScaning->setChecked(false);
    ui->actionMonitor->setChecked(false);
    ui->actionFastScaning->setChecked(true);
    ui->lbBegin->show();
    ui->sbBegin->show();
    ui->lbEnd->show();
    ui->sbEnd->show();
    ui->lbStep->show();
    ui->sbStep->show();
    ui->sbStep->setReadOnly(true);
    ui->sbStep->setPrefix("~");
    ui->lbPoints->hide();
    ui->sbPoints->hide();
    recalcFastScanStep();
}

void MainWindow::on_actionScaning_triggered() {
    ui->actionFastScaning->setChecked(false);
    ui->actionMonitor->setChecked(false);
    ui->actionScaning->setChecked(true);
    ui->lbBegin->show();
    ui->sbBegin->show();
    ui->lbEnd->show();
    ui->sbEnd->show();
    ui->lbStep->show();
    ui->sbStep->show();
    ui->sbStep->setReadOnly(false);
    ui->sbStep->setPrefix("");
    ui->lbPoints->hide();
    ui->sbPoints->hide();
}

void MainWindow::recalcFastScanStep() {
    if (ui->actionFastScaning->isChecked())
        ui->sbStep->setValue(ui->sbTime->value()*globalParams.app.coefA*globalParams.app.fScanSpeed/1000);
}

MainWindow::~MainWindow() {
    delete ui;
}
