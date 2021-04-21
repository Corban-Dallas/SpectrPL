#-------------------------------------------------
#
# Project created by QtCreator 2021-03-26T17:29:42
#
#-------------------------------------------------

QT       += core gui serialport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpectrPL
TEMPLATE = app

SOURCES +=\
    src/cnt.cpp \
    src/command_server.cpp \
    src/dialogs/debug_dialog.cpp \
    src/dialogs/graphSettings.cpp \
    src/dialogs/port_dialog.cpp \
    src/dialogs/position_dialog.cpp \
    src/dialogs/scanDialog.cpp \
    src/fast_scan_worker.cpp \
    src/goto_wavelength_worker.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/monitor_worker.cpp \
    src/scan_worker.cpp \
    src/smd.cpp \
    src/widgets/graph.cpp \
    src/widgets/spectraList.cpp \
    src/widgets/statuswidget.cpp

HEADERS  += \
    src/cnt.h \
    src/command_server.h \
    src/dialogs/debug_dialog.h \
    src/dialogs/graphSettings.h \
    src/dialogs/port_dialog.h \
    src/dialogs/position_dialog.h \
    src/dialogs/scandialog.h \
    src/fast_scan_worker.h \
    src/globalparams.h \
    src/goto_wavelength_worker.h \
    src/mainwindow.h \
    src/monitor_worker.h \
    src/scan_worker.h \
    src/smd.h \
    src/widgets/graph.h \
    src/widgets/spectraList.h \
    src/widgets/statuswidget.h

FORMS += \
    src/dialogs/debug_dialog.ui \
    src/dialogs/graphSettings.ui \
    src/dialogs/port_dialog.ui \
    src/dialogs/position_dialog.ui \
    src/dialogs/scanDialog.ui \
    src/mainwindow.ui \
    src/widgets/statuswidget.ui
