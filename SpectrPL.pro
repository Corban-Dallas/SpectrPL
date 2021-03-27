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
    src/debug_dialog.cpp \
    src/fast_scan_worker.cpp \
    src/goto_wavelength_worker.cpp \
    src/graph.cpp \
    src/graph_dialog.cpp \
    src/log.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/monitor_worker.cpp \
    src/port_dialog.cpp \
    src/position_dialog.cpp \
    src/scan_worker.cpp \
    src/scandialog.cpp \
    src/smd.cpp \
    src/spectra_storage.cpp \
    src/spectrum.cpp \
    src/statuswidget.cpp

HEADERS  += \
    src/cnt.h \
    src/command_server.h \
    src/debug_dialog.h \
    src/fast_scan_worker.h \
    src/globalparams.h \
    src/goto_wavelength_worker.h \
    src/graph.h \
    src/graph_dialog.h \
    src/log.h \
    src/mainwindow.h \
    src/monitor_worker.h \
    src/port_dialog.h \
    src/position_dialog.h \
    src/scan_worker.h \
    src/scandialog.h \
    src/smd.h \
    src/spectra_storage.h \
    src/spectrum.h \
    src/statuswidget.h

FORMS += \
    src/debug_dialog.ui \
    src/graph_dialog.ui \
    src/mainwindow.ui \
    src/port_dialog.ui \
    src/position_dialog.ui \
    src/scandialog.ui \
    src/statuswidget.ui
