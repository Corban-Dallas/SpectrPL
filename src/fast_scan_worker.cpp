#include "fast_scan_worker.h"

FastScanWorker::FastScanWorker(CommandServer *cs, ScanParameters params,
                               QObject *parent) : QObject(parent)
{
    begin = params.begin;
    end = params.end;
    channel = params.channel;
    acquisition = params.acquisition;

    if (end > begin) scanDirection = 1;
    else scanDirection = -1;

    globalParams.smd.speed = globalParams.app.fScanSpeed;
    globalParams.smd.accel = globalParams.app.fScanAccel;
    globalParams.smd.startSpeed = globalParams.app.fScanStartSpeed;

    connect(cs, &CommandServer::moveFinished,
            this, &FastScanWorker::gotoNextPosition);
    connect(this, &FastScanWorker::reqSignalAcquire,
            cs, &CommandServer::beginSignalAcquire);
    connect(cs, &CommandServer::signalAcquired,
            this, &FastScanWorker::registerSignal);
    connect(cs, &CommandServer::wlUpdated,
            this, &FastScanWorker::updateWavelength);

    connect(cs, &CommandServer::moveStoped,
            this, &FastScanWorker::stop);
    connect(this, &FastScanWorker::setAcquisition,
            cs, &CommandServer::setCntAcquisition);
    connect(this, &FastScanWorker::gotoWavelength,
            cs, &CommandServer::gotoWavelength);
    connect(cs, &CommandServer::wlUpdated,
            this, &FastScanWorker::updateWavelength);
}

void FastScanWorker::start() {
    qDebug() << "[FastScanWorker] Start";
    emit setAcquisition(acquisition);

    double wl = begin;
    if (isLuft) wl = begin - scanDirection*luft;

    emit gotoWavelength(wl);
    emit started();
}

void FastScanWorker::gotoNextPosition() {
    if (isLuft) {
        isLuft = false;
        emit gotoWavelength(end);
        emit reqSignalAcquire(channel);
    }
    else {
        globalRequests.stopWork = false;
        last_point = true;
    }
}

void FastScanWorker::registerSignal(uint signal) {
    qDebug() << "[FastScanWorker] RegisterSignal";

    emit newPoint(wavelength, 1000*signal/acquisition);
    if (!last_point) emit reqSignalAcquire(channel);
    // Если это последняя точка, останавливаем измерение
    else emit stoped();
}


void FastScanWorker::stop() {
    globalRequests.stopWork = false;
    if (isLuft) emit stoped();
    else last_point = true;
}

void FastScanWorker::updateWavelength(double wl) {
    wavelength = wl;
}
