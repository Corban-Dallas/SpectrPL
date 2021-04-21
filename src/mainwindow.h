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
#include "widgets/graph.h"
#include "widgets/spectraList.h"

// Diologs
#include "dialogs/position_dialog.h"
#include "dialogs/debug_dialog.h"
#include "dialogs/scandialog.h"
#include "dialogs/port_dialog.h"

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

    // Dialogs
    void createPortDialog();
    void createPositionDialog();
    void createScanProfilesDialog();

    // Widgets
    void createSpectraListWidget();
    void createGraphWidget();

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
    SpectraList *spectraList;

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
