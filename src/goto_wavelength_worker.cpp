#include "goto_wavelength_worker.h"

GotoWavelengthWorker::GotoWavelengthWorker(CommandServer *cs, double wl, QObject *parent) : QObject(parent) {
    globalParams.smd.speed = globalParams.app.defSpeed;
    globalParams.smd.accel = globalParams.app.defAccel;
    globalParams.smd.startSpeed = globalParams.app.defStartSpeed;
    wavelength = wl;

    connect(this, &GotoWavelengthWorker::gotoWavelength,
            cs, &CommandServer::gotoWavelength);
    connect(cs, &CommandServer::moveStoped,
            this, &GotoWavelengthWorker::stop);
    connect(cs, &CommandServer::moveFinished,
            this, &GotoWavelengthWorker::stop);
}

void GotoWavelengthWorker::start() {
    double luft = globalParams.app.luft;
    emit gotoWavelength(wavelength + luft);
    emit started();
}

void GotoWavelengthWorker::stop() {
    if (globalRequests.stopWork) {
        qDebug() << "[GotoWorker] Stoped";
        globalRequests.stopWork = false;
        emit stoped();
        return;
    }
    if (is_luft_position) {
        emit gotoWavelength(wavelength);
        is_luft_position = false;
    }
    qDebug() << "[GotoWorker] Finished";
    globalRequests.stopWork = false;
    emit stoped();
}
