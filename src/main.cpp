#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    qRegisterMetaType<long int>("long int");
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("ISP SB RAS");
    QCoreApplication::setOrganizationDomain("isp.nsc.ru");
    QCoreApplication::setApplicationName("SpectrPL");
    MainWindow w;
    w.show();

    return a.exec();
}
