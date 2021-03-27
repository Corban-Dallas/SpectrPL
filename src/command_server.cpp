#include "command_server.h"

CommandServer::CommandServer(SMD *smd, CNT *cnt, QObject *parent) : QObject(parent) {
    // SMD
    connect(this, &CommandServer::reqSmdMoveTo,
            smd, &SMD::moveTo);
    connect(smd, &SMD::stepChanged,
            this, &CommandServer::updatePosition);
    connect(smd, &SMD::moveStoped,
            this, &CommandServer::moveStoped);
    connect(smd, &SMD::moveFinished,
            this, &CommandServer::moveFinished);
    connect(this, &CommandServer::reqSmdResetStep,
            smd, &SMD::resetStepCounter);
    connect(this, &CommandServer::reqSmdPowerOff,
            smd, &SMD::powerOff);
    connect(this, &CommandServer::reqSmdPowerOn,
            smd, &SMD::powerOn);
    // CNT
    connect(this, &CommandServer::beginSignalAcquire,
            cnt, &CNT::getValue);
    connect(cnt, &CNT::value, this, &CommandServer::signalAcquired);
    connect(this, &CommandServer::setCntAcquisition,
            cnt, &CNT::setAcquisition);
    connect(this, &CommandServer::setCntDac,
            cnt, &CNT::setDac);

    emit reqSmdResetStep();
}

void CommandServer::gotoWavelength(double wl) {
    double coefA = globalParams.app.coefA;
    double coefB = globalParams.app.coefB;
    double error = globalParams.app.error;

    long int steps = (wl - coefB - error) / coefA;
    emit reqSmdMoveTo(steps);
}

void CommandServer::updatePosition(long int smd_step) {
    qDebug() << "[CS] Update position";
    double coefA = globalParams.app.coefA;
    double coefB = globalParams.app.coefB;
    double error = globalParams.app.error;

    wavelength = coefA*smd_step + coefB + error;
    emit wlUpdated(wavelength);
    emit stUpdated(smd_step);
}
