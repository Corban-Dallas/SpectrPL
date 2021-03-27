#ifndef PARAMETRS_H
#define PARAMETRS_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

// Здесь хранятся параметры по умолчанию устройства и
// графического интерфейса.

// Параметры порта
struct PortParams {
    QString portName;
    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::StopBits stopBits;
    QSerialPort::Parity parity;
    QSerialPort::FlowControl flowControl;
};

// Параметры сканирования
struct ScanParameters {
    double begin = 0;
    double end = 0;
    double step = 0;
    uchar channel = 0;
    ushort acquisition = 1000;
};

struct GraphParameters {
    //double plotBegin;
    //double plotEnd;

    double minX = 4500;
    double maxX = 9000;

    uint minY = 100;
    uint maxY = 10000;

    bool autoX = true;
    bool autoY = true;

    bool logX = false;
    bool logY = false;

    ushort monitorPoints = 20;
};

// Gui
enum GuiMode {
    deviceConnected,
    deviceDisconnected,
    deviceIsWorking,
    deviceIsIdle
};


struct ApplicationParams {
    int defSpeed = 800;
    int defStartSpeed = 200;
    int defAccel = 50;

    int scanSpeed = 800;
    int scanStartSpeed = 200;
    int scanAccel = 50;

    int fScanSpeed = 800;
    int fScanStartSpeed = 200;
    int fScanAccel = 50;

    int luft = 30;

    double coefA = 1;
    double coefB = 0;
    double error = 0;
};

struct CntParams {
    PortParams port;
    uchar dac = 254;
    uchar acquisition = 1;
};

struct SmdParams {
    PortParams port;
    int speed = 400;
    int startSpeed = 200;
    int accel = 50;
};

struct Parameters {
    //ScanParameters scanParams;
    SmdParams smd;
    CntParams cnt;
    ApplicationParams app;
    GraphParameters graph;
};

struct GlobalRequests {
    bool stopSmd = false;
    bool stopWork = false;
};

#endif // PARAMETRS_H
