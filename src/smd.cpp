#include "smd.h"
#include "globalparams.h"

//Parameters globalParams;

SMD::SMD(QObject *parent) : QObject(parent) {
    port = new QSerialPort(this);
    params->port.baudRate = QSerialPort::Baud57600;
    params->port.dataBits = QSerialPort::Data8;
    params->port.stopBits = QSerialPort::OneStop;
    params->port.parity = QSerialPort::EvenParity;
    params->port.flowControl = QSerialPort::HardwareControl;
}

bool SMD::openPort() {
    //SmdParams params = globalParams.smd;
    port->setPortName(params->port.portName);
    port->setBaudRate(params->port.baudRate);
    port->setDataBits(params->port.dataBits);
    port->setStopBits(params->port.stopBits);
    port->setParity(params->port.parity);
    port->setFlowControl(params->port.flowControl);

    if ( port->isOpen() ) port->close();

    if (port->open(QIODevice::ReadWrite)) {
        port->clear();
        qDebug() << "[SMD] Serial port" << params->port.portName << "have been opened.";
        emit portOpened(true);
        return true;
    }
    else {
        qDebug() << "[SMD] Serial port" << params->port.portName << "have not been opened.";
        emit error(2);
        return false;
    }
}

bool SMD::closePort() {
    if (port->isOpen()) {
        port->close();
        emit portOpened(false);
        qDebug() << "[SMD] Serial port" << params->port.portName << "have been closed.";
        return true;
    }
    else {
        qDebug() << "[SMD] Serial port" << params->port.portName << "is already closed.";
        return false;
    }
}

void SMD::moveTo(long int step) {
    // Движение до зананной позиции
    qDebug() << "[SMD] MoveTo" << step;
    if (current_step == step) {
        emit moveFinished();
        return;
    }

    if (current_step > step) move(current_step - step, true);
    else move(step - current_step, false);
    return;
}

void SMD::move(uint steps, bool direction) {
    // Движение на заданное число шагов, в заданном направлении
    // 0 < steps < 4294967295
    // direction = true/false. True - движение влево, false - движение вправо

    // Power check
    if (power_off) {
        emit error(11);
        emit moveStoped();
        return;
    }

    ushort start_speed = params->startSpeed;
    ushort speed = params->speed;
    short accel = params->accel;

    loadProgram();
    setStartSpeed(start_speed);
    setSpeed(speed);
    setAccel(accel);
    setDir(direction);
    setMove(steps);
    startProgram();

    // Бесконечное движение, позиция не будет отслеживаться
    if (steps == 0) return;

    int loops = steps / 65536;
    int a = steps % 65536;
    int b, steps_left;
    int start_position = current_step;
    int dir = 1;
    if (direction) dir = -1;

    forever {
        // Обновление позиции
        b = stepsLeft();
        // Выход из цикла при окончании движения двигателя
        if ((b == a) && (b == 0)) {
            current_step = start_position + dir*steps;
            emit stepChanged(current_step);
            emit moveFinished();
            break;
        }

        if (b > a) loops--;
        steps_left = b + loops*65536;
        current_step = start_position + dir*(steps - steps_left);
        emit stepChanged(current_step);
        a = b;

        // Остановка по требованию
        if (globalRequests.stopWork) {
            stop();

            b = stepsLeft();
            if (b > a) loops--;
            steps_left = b + loops*65536;
            current_step = start_position + dir*(steps - steps_left);

            emit stepChanged(current_step);
            break;
        }
    }
    return;
}

int SMD::stepsLeft() {
    QByteArray data;
    if (!sendCommand("RR1>", &data))
        return 0;
    //qDebug() << data;
    QByteArray step;
    for (int i = 4; i <= data.length()-1; i++) {
        // end
        //if (data[i,i+3] == 0x656e64) return -1;
        // \r
        if (data[i]==0x0d)
            break;
        // error
        if (data[i]==0x65)
            break;
        step.append(data[i]);
    }
    //qDebug() << step.toInt();
    return step.toInt();
}

void SMD::resetStepCounter() {
    qDebug() << "[SMD] Step counter reset";
    current_step = 0;
    emit stepChanged(0);
}

int SMD::getSpeed() {
    QByteArray data;
    if (!sendCommand("RR10>", &data))
        return 0;
    qDebug() << data;
    QByteArray speed;
    for (int i = 5; i <= data.length()-1; i++) {
        speed.append(data[i]);
    }
    qDebug() << speed.toInt();
    return speed.toInt();
}

bool SMD::powerOn() {
    if (!sendCommand("EN>", NULL)) return false;
    power_off = false;
    return true;
}

bool SMD::powerOff() {
    if (!sendCommand("DS>", NULL)) return false;
    power_off = true;
    return true;
}

bool SMD::sendCommand(QByteArray cmd, QByteArray* data) {
    // Отправка команды
    //port->clear();
    qDebug() << "[SMD port] Send command" << cmd;
    int w = port->write(cmd);
    if (w != cmd.length()) {
        emit error(1);
        qDebug() << "[SMD port] Write error, cmd length " << cmd.length() << "writed " << w;
        return false;
    }
    port->waitForBytesWritten(100);
    // Чтение ответа
    QByteArray rbuf;
    rbuf.clear();
    while (port->waitForReadyRead(75)) {
        rbuf.append(port->readAll());
    }
    qDebug() << "[SMD port] Answer is " << rbuf;
    if (data != NULL)
        *data = rbuf;
    return true;
}

bool SMD::setStartSpeed(ushort start_speed) {
    if (start_speed > 3000) {
        qDebug() << "[SMD] Wrong start speed";
        emit error(3);
        return false;
    }
    QByteArray cmd = "SS" + QString::number(start_speed).toLocal8Bit() + ">";
    return sendCommand(cmd, NULL);
}

bool SMD::setAccel(short accel) {
    if ((accel > 1000) || (accel < -1000)) {
        qDebug() << "[SMD] Wrong accel";
        emit error(5);
        return false;
    }
    QByteArray cmd = "AL" + QString::number(accel).toLocal8Bit() + ">";
    return sendCommand(cmd, NULL);
}

bool SMD::setSpeed(ushort speed) {
    if (speed > 10000) {
        qDebug() << "[SMD] Wrong speed";
        emit error(4);
        return false;
    }
    QByteArray cmd = "SD" + QString::number(speed).toLocal8Bit() + ">";
    return sendCommand(cmd, NULL);
}

bool SMD::loadProgram() {
    return sendCommand("LM>", NULL);
}

bool SMD::startProgram() {
    return sendCommand("FS>", NULL);
}

bool SMD::setDir(bool dir) {
    QByteArray cmd;
    if (dir) cmd = "DL>";
    else cmd = "DR>";
    return sendCommand(cmd, NULL);
}

bool SMD::setMove(uint steps) {
    QByteArray cmd;
    if (steps == 0) cmd = "MV>";
    else cmd = "MV" + QString::number(steps).toLocal8Bit() + ">";
    return sendCommand(cmd, NULL);
}

bool SMD::stop() {
    return sendCommand("SP>", NULL);
    emit moveStoped();
}
