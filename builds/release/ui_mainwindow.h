/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionScaning;
    QAction *actionFastScaning;
    QAction *actionMonitor;
    QAction *actionPosition;
    QAction *actionScanProfiles;
    QAction *actionSerialPort;
    QAction *actionUpdate_position;
    QAction *actionAbout;
    QAction *actionDebug_panel;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *leftLayout;
    QGroupBox *gbControl;
    QGridLayout *gridLayout;
    QSpinBox *sbEnd;
    QLabel *lbStep;
    QSpinBox *sbStep;
    QLabel *lbTime;
    QSpinBox *sbTime;
    QRadioButton *rbChanel1;
    QLabel *lbPoints;
    QSpinBox *sbPoints;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbStart;
    QPushButton *pbStop;
    QLabel *label_6;
    QDoubleSpinBox *dsb_current_wl;
    QRadioButton *rbChanel2;
    QLabel *lbBegin;
    QSpinBox *sbBegin;
    QLabel *lbEnd;
    QGroupBox *gbData;
    QVBoxLayout *verticalLayout;
    QPushButton *pbEmStop;
    QVBoxLayout *rightLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuDevice;
    QMenu *menuAbout;
    QMenu *menuDebug;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(true);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionConnect->setEnabled(true);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionDisconnect->setEnabled(false);
        actionScaning = new QAction(MainWindow);
        actionScaning->setObjectName(QStringLiteral("actionScaning"));
        actionScaning->setCheckable(true);
        actionScaning->setEnabled(false);
        actionFastScaning = new QAction(MainWindow);
        actionFastScaning->setObjectName(QStringLiteral("actionFastScaning"));
        actionFastScaning->setCheckable(true);
        actionFastScaning->setChecked(false);
        actionFastScaning->setEnabled(false);
        actionMonitor = new QAction(MainWindow);
        actionMonitor->setObjectName(QStringLiteral("actionMonitor"));
        actionMonitor->setCheckable(true);
        actionMonitor->setChecked(false);
        actionMonitor->setEnabled(false);
        actionPosition = new QAction(MainWindow);
        actionPosition->setObjectName(QStringLiteral("actionPosition"));
        actionPosition->setEnabled(false);
        actionScanProfiles = new QAction(MainWindow);
        actionScanProfiles->setObjectName(QStringLiteral("actionScanProfiles"));
        actionScanProfiles->setEnabled(false);
        actionSerialPort = new QAction(MainWindow);
        actionSerialPort->setObjectName(QStringLiteral("actionSerialPort"));
        actionUpdate_position = new QAction(MainWindow);
        actionUpdate_position->setObjectName(QStringLiteral("actionUpdate_position"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionDebug_panel = new QAction(MainWindow);
        actionDebug_panel->setObjectName(QStringLiteral("actionDebug_panel"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        leftLayout = new QVBoxLayout();
        leftLayout->setSpacing(6);
        leftLayout->setObjectName(QStringLiteral("leftLayout"));
        leftLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gbControl = new QGroupBox(centralWidget);
        gbControl->setObjectName(QStringLiteral("gbControl"));
        gridLayout = new QGridLayout(gbControl);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        sbEnd = new QSpinBox(gbControl);
        sbEnd->setObjectName(QStringLiteral("sbEnd"));
        sbEnd->setEnabled(true);
        sbEnd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbEnd->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbEnd->setMaximum(100000);
        sbEnd->setSingleStep(100);
        sbEnd->setValue(4900);

        gridLayout->addWidget(sbEnd, 1, 1, 1, 1);

        lbStep = new QLabel(gbControl);
        lbStep->setObjectName(QStringLiteral("lbStep"));

        gridLayout->addWidget(lbStep, 2, 0, 1, 1);

        sbStep = new QSpinBox(gbControl);
        sbStep->setObjectName(QStringLiteral("sbStep"));
        sbStep->setEnabled(true);
        sbStep->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbStep->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbStep->setMinimum(0);
        sbStep->setMaximum(100000);
        sbStep->setSingleStep(5);
        sbStep->setValue(20);

        gridLayout->addWidget(sbStep, 2, 1, 1, 1);

        lbTime = new QLabel(gbControl);
        lbTime->setObjectName(QStringLiteral("lbTime"));

        gridLayout->addWidget(lbTime, 3, 0, 1, 1);

        sbTime = new QSpinBox(gbControl);
        sbTime->setObjectName(QStringLiteral("sbTime"));
        sbTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbTime->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbTime->setMinimum(0);
        sbTime->setMaximum(100000);
        sbTime->setSingleStep(500);
        sbTime->setValue(2000);

        gridLayout->addWidget(sbTime, 3, 1, 1, 1);

        rbChanel1 = new QRadioButton(gbControl);
        rbChanel1->setObjectName(QStringLiteral("rbChanel1"));
        rbChanel1->setChecked(true);

        gridLayout->addWidget(rbChanel1, 6, 0, 1, 1);

        lbPoints = new QLabel(gbControl);
        lbPoints->setObjectName(QStringLiteral("lbPoints"));

        gridLayout->addWidget(lbPoints, 4, 0, 1, 1);

        sbPoints = new QSpinBox(gbControl);
        sbPoints->setObjectName(QStringLiteral("sbPoints"));
        sbPoints->setEnabled(true);
        sbPoints->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbPoints->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbPoints->setMinimum(2);
        sbPoints->setMaximum(65535);
        sbPoints->setValue(20);

        gridLayout->addWidget(sbPoints, 4, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pbStart = new QPushButton(gbControl);
        pbStart->setObjectName(QStringLiteral("pbStart"));
        pbStart->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pbStart->sizePolicy().hasHeightForWidth());
        pbStart->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pbStart);

        pbStop = new QPushButton(gbControl);
        pbStop->setObjectName(QStringLiteral("pbStop"));
        pbStop->setEnabled(false);
        sizePolicy.setHeightForWidth(pbStop->sizePolicy().hasHeightForWidth());
        pbStop->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pbStop);


        gridLayout->addLayout(horizontalLayout_2, 8, 0, 1, 2);

        label_6 = new QLabel(gbControl);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        dsb_current_wl = new QDoubleSpinBox(gbControl);
        dsb_current_wl->setObjectName(QStringLiteral("dsb_current_wl"));
        dsb_current_wl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dsb_current_wl->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dsb_current_wl->setDecimals(1);
        dsb_current_wl->setMinimum(-5e+6);
        dsb_current_wl->setMaximum(5e+6);

        gridLayout->addWidget(dsb_current_wl, 5, 1, 1, 1);

        rbChanel2 = new QRadioButton(gbControl);
        rbChanel2->setObjectName(QStringLiteral("rbChanel2"));

        gridLayout->addWidget(rbChanel2, 6, 1, 1, 1);

        lbBegin = new QLabel(gbControl);
        lbBegin->setObjectName(QStringLiteral("lbBegin"));
        lbBegin->setMinimumSize(QSize(0, 0));
        lbBegin->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lbBegin, 0, 0, 1, 1);

        sbBegin = new QSpinBox(gbControl);
        sbBegin->setObjectName(QStringLiteral("sbBegin"));
        sbBegin->setEnabled(true);
        sbBegin->setMinimumSize(QSize(0, 0));
        sbBegin->setMaximumSize(QSize(16777215, 16777215));
        sbBegin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbBegin->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbBegin->setMaximum(100000);
        sbBegin->setValue(9000);

        gridLayout->addWidget(sbBegin, 0, 1, 1, 1);

        lbEnd = new QLabel(gbControl);
        lbEnd->setObjectName(QStringLiteral("lbEnd"));

        gridLayout->addWidget(lbEnd, 1, 0, 1, 1);


        leftLayout->addWidget(gbControl);

        gbData = new QGroupBox(centralWidget);
        gbData->setObjectName(QStringLiteral("gbData"));
        verticalLayout = new QVBoxLayout(gbData);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        leftLayout->addWidget(gbData);

        pbEmStop = new QPushButton(centralWidget);
        pbEmStop->setObjectName(QStringLiteral("pbEmStop"));

        leftLayout->addWidget(pbEmStop);


        horizontalLayout->addLayout(leftLayout);

        rightLayout = new QVBoxLayout();
        rightLayout->setSpacing(6);
        rightLayout->setObjectName(QStringLiteral("rightLayout"));
        rightLayout->setSizeConstraint(QLayout::SetMaximumSize);

        horizontalLayout->addLayout(rightLayout);

        horizontalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuDevice = new QMenu(menuBar);
        menuDevice->setObjectName(QStringLiteral("menuDevice"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuAbout->setEnabled(true);
        menuDebug = new QMenu(menuBar);
        menuDebug->setObjectName(QStringLiteral("menuDebug"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(sbBegin, sbEnd);
        QWidget::setTabOrder(sbEnd, sbStep);
        QWidget::setTabOrder(sbStep, sbTime);
        QWidget::setTabOrder(sbTime, sbPoints);
        QWidget::setTabOrder(sbPoints, rbChanel1);
        QWidget::setTabOrder(rbChanel1, rbChanel2);
        QWidget::setTabOrder(rbChanel2, pbStart);
        QWidget::setTabOrder(pbStart, pbStop);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuDevice->menuAction());
        menuBar->addAction(menuDebug->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuDevice->addAction(actionConnect);
        menuDevice->addAction(actionDisconnect);
        menuDevice->addSeparator();
        menuDevice->addAction(actionSerialPort);
        menuDevice->addAction(actionPosition);
        menuDevice->addAction(actionScanProfiles);
        menuAbout->addAction(actionAbout);
        menuDebug->addAction(actionDebug_panel);
        toolBar->addAction(actionConnect);
        toolBar->addAction(actionDisconnect);
        toolBar->addSeparator();
        toolBar->addAction(actionScaning);
        toolBar->addAction(actionFastScaning);
        toolBar->addAction(actionMonitor);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SpectrPL", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save as...", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0));
        actionScaning->setText(QApplication::translate("MainWindow", "Scaning", 0));
        actionFastScaning->setText(QApplication::translate("MainWindow", "Fast Scaning", 0));
        actionMonitor->setText(QApplication::translate("MainWindow", "Monitor", 0));
        actionPosition->setText(QApplication::translate("MainWindow", "Position", 0));
        actionScanProfiles->setText(QApplication::translate("MainWindow", "Scan profiles", 0));
        actionSerialPort->setText(QApplication::translate("MainWindow", "Serial port", 0));
        actionUpdate_position->setText(QApplication::translate("MainWindow", "Update position", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionDebug_panel->setText(QApplication::translate("MainWindow", "Debug panel", 0));
        gbControl->setTitle(QApplication::translate("MainWindow", "Control panel", 0));
        sbEnd->setSuffix(QApplication::translate("MainWindow", " A", 0));
        lbStep->setText(QApplication::translate("MainWindow", "Step:", 0));
        sbStep->setSuffix(QApplication::translate("MainWindow", " A", 0));
        lbTime->setText(QApplication::translate("MainWindow", "Time:", 0));
        sbTime->setSuffix(QApplication::translate("MainWindow", " ms", 0));
        rbChanel1->setText(QApplication::translate("MainWindow", "Chanel 1", 0));
        lbPoints->setText(QApplication::translate("MainWindow", "Points:", 0));
        pbStart->setText(QApplication::translate("MainWindow", "Start", 0));
        pbStop->setText(QApplication::translate("MainWindow", "Stop", 0));
        label_6->setText(QApplication::translate("MainWindow", "Current Wavelength:", 0));
        dsb_current_wl->setSuffix(QApplication::translate("MainWindow", " A", 0));
        rbChanel2->setText(QApplication::translate("MainWindow", "Chanel 2", 0));
        lbBegin->setText(QApplication::translate("MainWindow", "Begin:", 0));
        sbBegin->setSuffix(QApplication::translate("MainWindow", " A", 0));
        lbEnd->setText(QApplication::translate("MainWindow", "End:", 0));
        gbData->setTitle(QApplication::translate("MainWindow", "Data list", 0));
        pbEmStop->setText(QApplication::translate("MainWindow", "EMERGENCY STOP", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuDevice->setTitle(QApplication::translate("MainWindow", "Device", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuDebug->setTitle(QApplication::translate("MainWindow", "Debug", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
