#include "scan_worker.h"

ScanWorker::ScanWorker(CommandServer *cs, ScanParameters params,
                       QObject *parent) : QObject(parent) {
    begin = params.begin;
    end = params.end;
    step = params.step;
    channel = params.channel;
    acquisition = params.acquisition;
    if (end > begin) dir = -1;
    else dir = 1;

    globalParams.smd.speed = globalParams.app.scanSpeed;
    globalParams.smd.accel = globalParams.app.scanAccel;
    globalParams.smd.startSpeed = globalParams.app.scanStartSpeed;

    connect(cs, &CommandServer::moveFinished,
            this, &ScanWorker::measureSignal);
    connect(this, &ScanWorker::reqSignalAcquire,
            cs, &CommandServer::beginSignalAcquire);
    connect(cs, &CommandServer::signalAcquired,
            this, &ScanWorker::registerSignal);
    connect(cs, &CommandServer::signalAcquired,
            this, &ScanWorker::gotoNextPoint);

    connect(this, &ScanWorker::setSmdPowerOn,
            cs, &CommandServer::reqSmdPowerOn);
    connect(this, &ScanWorker::setSmdPowerOff,
            cs, &CommandServer::reqSmdPowerOff);

    connect(cs, &CommandServer::moveStoped,
            this, &ScanWorker::stop);
    connect(this, &ScanWorker::setAcquisition,
            cs, &CommandServer::setCntAcquisition);
    connect(this, &ScanWorker::gotoWavelength,
            cs, &CommandServer::gotoWavelength);
    connect(cs, &CommandServer::wlUpdated,
            this, &ScanWorker::updateWavelength);
}

void ScanWorker::start() {
    if (step == 0) {
        qDebug() << "[ScanWorker] Zero step";
        stop();
        return;
    }

    emit setAcquisition(acquisition);
    emit gotoWavelength(begin + luft*dir);

    emit started();
    qDebug() << "[ScanWorker] Started";
}

void ScanWorker::measureSignal() {
    if (power_off_while_read_signal) {
        emit setSmdPowerOff();
        QThread::msleep(300);
    }
    // First point is luft
    if (is_luft) {
        gotoNextPoint();
        is_luft = false;
        return;
    }
    else reqSignalAcquire(channel);
}

void ScanWorker::registerSignal(uint signal) {
    emit newPoint(wavelength, 1000*signal/acquisition);
}

void ScanWorker::gotoNextPoint() {
    // if stop requested
    if (globalRequests.stopWork) {
        stop();
        return;
    }
    // no points left
    if ((begin - end)*dir - step*n_step < 0) {
        stop();
        return;
    }
    // go to next point
    if (power_off_while_read_signal) emit setSmdPowerOn();

    emit gotoWavelength(begin - dir*step*n_step);
    n_step++;
}

void ScanWorker::stop() {
    qDebug() << "[ScanWorker] Stoped";
    globalRequests.stopWork = false;
    emit stoped();
}

void ScanWorker::updateWavelength(double wl) {
    wavelength = wl;
}
