#ifndef CNT_H
#define CNT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include "globalparams.h"

extern Parameters globalParams;
extern GlobalRequests globalRequests;

class CNT : public QObject
{
    Q_OBJECT
public:
    explicit CNT(QObject *parent = 0);

signals:
    void portOpened(bool);
    void value(uint count);
    void status(ushort status);
    void error(int number);

public slots:
    bool openPort();
    bool closePort();

    void getValue(uchar channel);

    ushort status();
    bool setAcquisition(ushort seconds);
    bool setDac(uchar);
    bool setSleep(ushort);
    bool setCon(ushort);

private:
    bool sendCommand(uchar command, uchar *data);
    uint getCount(uchar channel);
    CntParams *params = &globalParams.cnt;

    QSerialPort *port;

    // Answers
    uchar FIN = 0x03;
    uchar RQ = 0x04;
    uchar PUT1 = 0x10;
    uchar PUT2 = 0x20;
    uchar PUT3 = 0x30;
    uchar GET1 = 0x80;
    uchar GET2 = 0x70;
    uchar GET3 = 0x60;
    uchar DAK1 = 0x08;
    uchar DAK2 = 0x07;
    uchar DAK3 = 0x06;
    uchar IDLE = 0xff;
    uchar MARK = 0xff;
    uchar UNK = 0x01;
    uchar NAK = 0x02;
    uchar ACK = 0x05;
    uchar WAK = 0x04;
    uchar XON = 0x5;
};

#endif // CNT_H
