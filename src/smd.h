#ifndef SMD_H
#define SMD_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QDebug>

#include "globalparams.h"
extern Parameters globalParams;
extern GlobalRequests globalRequests;

class SMD : public QObject
{
    Q_OBJECT
public:
    explicit SMD(QObject *parent = 0);

    void change_dir(int);
    bool isRotating();
    int stepsLeft();

signals:
    void moveFinished();
    void moveStoped();
    void stepChanged(long int position);
    void error(int);
    void portOpened(bool);
    void portClosed();

public slots:
    // Serial port
    bool openPort();
    bool closePort();

    // SMD control
    void moveTo(long int position);
    bool stop();

    void resetStepCounter();

    bool powerOn();
    bool powerOff();

private:
    QSerialPort *port;
    SmdParams *params = &globalParams.smd;

    void move(uint steps, bool dir_left);

    bool setAccel(short);
    bool setSpeed(ushort);
    bool setStartSpeed(ushort);
    bool loadProgram();
    bool startProgram();
    bool setDir(bool);
    bool setMove(uint);

    int getSpeed();

    bool sendCommand(QByteArray cmd, QByteArray* answer);

    int current_step = 0;
    bool power_off = true;
};

#endif // SMD_H
