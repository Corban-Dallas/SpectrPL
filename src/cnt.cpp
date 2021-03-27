#include "cnt.h"

CNT::CNT(QObject *parent) : QObject(parent) {
    port = new QSerialPort(this);
}

bool CNT::openPort() {
    //emit portOpened(true);
    port->setPortName(params->port.portName);
    port->setBaudRate(QSerialPort::Baud9600);
    port->setDataBits(QSerialPort::Data8);
    port->setStopBits(QSerialPort::TwoStop);
    port->setParity(QSerialPort::NoParity);
    port->setFlowControl(QSerialPort::NoFlowControl);

    if (port->open(QIODevice::ReadWrite)) {
        port->setRequestToSend(false);
        port->setDataTerminalReady(false);
        port->clear();
        emit portOpened(true);
        setDac(params->dac);
        qDebug() << "[CNT] Serial port" << params->port.portName << "have been opened.";
        return true;
    }
    else {
        qDebug() << "[CNT] Serial port" << params->port.portName << "have not been opened.";
        emit error(7);
        return false;
    }
}

bool CNT::closePort() {
    if (port->isOpen()) {
        port->close();
        qDebug() << "Serial port" << params->port.portName << "have been closed.";
        emit portOpened(false);
        return true;
    }
    else {
        qDebug() << "Serial port" << params->port.portName << "is already closed.";
        return false;
    }
}

bool CNT::sendCommand(uchar command, uchar *data) {
    port->clear();

    // WRITE
    QByteArray wbuf;
    char check;

    wbuf.clear();
    wbuf[0] = 0x91; check = 0x91;  // 0x91 slave adress
    wbuf[1] = command;     check += command;

    int count = 0;
    if ( (command & 0xf0) == PUT1 ) count = 2;
    if ( (command & 0xf0) == PUT2 ) count = 16;
    if ( (command & 0xf0) == PUT3 ) count = 128;

    for (int i = 0; i < count; i++) {
        check += data[i];
        wbuf[2+i] = data[i];
    }

    check = -check;
    wbuf[count+2] = check;

    port->setRequestToSend(true);
    int w = port->write(wbuf);
    if (w != wbuf.length()) {
        qDebug() << "Write error.";
        emit error(8);
        return false;
    }
    port->waitForBytesWritten(200);
    port->setRequestToSend(false);

    // READ
    QByteArray rbuf;
    rbuf.clear();

    while (port->waitForReadyRead(200)) {
        rbuf = port->read(1);
        if (rbuf[0] == IDLE) continue;

        port->startTransaction();
        check = rbuf[0];

        count = 0;
        if (rbuf[0] == DAK1) count = 2;
        if (rbuf[0] == DAK2) count = 16;
        if (rbuf[0] == DAK3) count = 128;

        if (port->bytesAvailable() < count + 1) {
            port->rollbackTransaction();
            continue;
        }

        rbuf = port->read(count + 1);

        for (int i = 0; i < count; i++) {
            *data = rbuf[i];
            check += rbuf[i];
            data++;
        }
        check = -check;

        if (check != rbuf[count]) {
            qDebug() << "Read error. Wrong check.";
            emit error(9);
            return false;
        }
        port->commitTransaction();
        return true;
    }
    qDebug() << "111Read error. Wrong check.";
    return false;
}

void CNT::getValue(uchar channel) {
    // Измерение данных счётчика
    ushort st = 0;
    setCon(0x101);
    for (;;) {
        st = status();
        if (st & 0x80) break;
        if (globalRequests.stopWork) break;
    }

    uint result = getCount(channel);
    emit value(result);
    setCon(0x100);
}

uint CNT::getCount(uchar chanel) {
    // Канал либо 0 либо 1.
    if (chanel != 0 && chanel != 1) {
        emit error(10);
        return 0;
    }

    uchar data[2];
    uint result = 0;

    uchar cmd = 0x94 + chanel*2;
    if (sendCommand(cmd, data)) result = data[0] + (data[1] << 8);
    else qDebug() << "Error - CNT::getCount()";

    cmd = 0x95 + chanel*2;
    if (sendCommand(cmd, data)) result += (data[0] << 16) + (data[1] << 24);
    else qDebug() << "Error - CNT::getCount()";

    //qDebug() << result;
    return result;
}

ushort CNT::status() {
    uchar data[2];
    uchar cmd = 0x92;
    ushort st;

    if (sendCommand(cmd, data)) {
        st = data[0] + (data[1] << 8);
        //emit status(st);
        return st;
    }
    else {
        qDebug() << "Error - CNT::getStatus()";
        return 0;
    }
}

bool CNT::setAcquisition(ushort ms) {
    qDebug() << QString("[CNT] Set acquisition %1").arg(ms);
    uchar cmd = 0x10;
    uchar data[2];

    data[0] = ms & 0xff;
    data[1] = (ms >> 8) & 0xff;

    if (sendCommand(cmd, data)) return true;
    else {
        qDebug() << "Error - CommandServer::setCntTime()";
        return false;
    }
}

bool CNT::setDac(uchar dac) {
    qDebug() << "[CNT] Set dac " << dac ;
    uchar cmd = 0x12;
    uchar data[2];

    data[0] = dac;
    data[1] = 0x00;

    if (sendCommand(cmd, data)) return true;
    else {
        qDebug() << "Error - CNT::setDac()";
        return false;
    }
}

bool CNT::setSleep(ushort sleep) {
    //qDebug() << QString("CommandServer::setCntSleep(%1)").arg(sleep);
    uchar cmd = 0x11;
    uchar data[2];

    data[0] = sleep & 0xff;
    data[1] = (sleep >> 8) & 0xff;

    if (sendCommand(cmd, data)) return true;
    else {
        qDebug() << "Error - CNT::setSleep()";
        return false;
    }
}

bool CNT::setCon(ushort con) {
    qDebug() << "[CNT] Set control mode" << con;
    uchar cmd = 0x19;
    uchar data[2];

    data[0] = con & 0xff;
    data[1] = (con >> 8) & 0xff;

    if (sendCommand(cmd, data)) return true;
    else {
        qDebug() << "Error - CNT::setCon()";
        return false;
    }
}
