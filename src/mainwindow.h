#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QtCharts/QLineSeries>

#include "smd.h"
#include "cnt.h"

#include "scan_worker.h"
#include "fast_scan_worker.h"
#include "monitor_worker.h"
#include "goto_wavelength_worker.h"

// GUI widgets
#include "graph.h"
#include "spectra_storage.h"

#include "position_dialog.h"
#include "debug_dialog.h"
#include "scandialog.h"
#include "port_dialog.h"

QT_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void saveSpectra();
    void showErrorMessage(QString msg);
    void on_pbStart_clicked();
    void on_pbStop_clicked();
    void updateSmdPortState(bool);
    void updateCntPortState(bool);
    void recalcFastScanStep();
    //void recalcFastScanStep(int time);


    void on_actionAbout_triggered();
    void on_actionMonitor_triggered();
    void on_actionFastScaning_triggered();
    void on_actionScaning_triggered();

public slots:
    void setGuiMode(GuiMode);
    //void setGuiModeReady();
    //void setGuiModeWorking();
    //void setGuiModeNotReady();

private:
    Ui::MainWindow *ui;
    QSettings *settings;

    // Устройства
    SMD *smd;
    CNT *cnt;
    CommandServer *cs;

    ScanWorker *scanWorker;
    FastScanWorker *fastScanWorker;
    MonitorWorker *monitorWorker;
    GotoWavelengthWorker *gotoWorker;

    QThread *smdThread;
    QThread *cntThread;
    QThread *workerThread;

    // Диалоги
    PortDialog *portDialog;
    PositionDialog *posDialog;
    ScanDialog *scanDialog;
    DebugDialog *debugDialog;

    // Дополнительные виджеты
    Graph *graph;
    SpectraStorage *storage;

    bool smdConnected = false;
    bool cntConnected = false;

    void StartScan(double begin, double end, double step,
                   ushort acquisition, uchar channel);
    void StartFastScan(double begin, double end,
                       ushort acquisition, uchar channel);
    void StartMonitor(ushort acquisition, uchar channel);
    void ChangePosition(double new_position);

    void readSettings();
    void writeSettings();
    void closeEvent(QCloseEvent *event);

    void createDebugDialog();

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
