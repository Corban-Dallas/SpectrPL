#include "monitor_worker.h"

MonitorWorker::MonitorWorker(CommandServer *cs, ushort a, uchar c,
                             QObject *parent) : QObject(parent) {
    channel = c;
    acquisition = a;

    connect(this, &MonitorWorker::reqSignalAcquire,
            cs, &CommandServer::beginSignalAcquire);
    connect(cs, &CommandServer::signalAcquired,
            this, &MonitorWorker::registerSignal);
    connect(cs, &CommandServer::signalAcquired,
            this, &MonitorWorker::proceed);
    connect(this, &MonitorWorker::setAcquisition,
            cs, &CommandServer::setCntAcquisition);
}

void MonitorWorker::start() {
    qDebug() << "[Worker] Start monitor";
    emit setAcquisition(acquisition);
    emit reqSignalAcquire(channel);
    emit started();
}

void MonitorWorker::registerSignal(uint signal) {
    emit newPoint(signal);
}

void MonitorWorker::proceed() {
    if (globalRequests.stopWork) {
        stop();
        return;
    }
    emit reqSignalAcquire(channel);
}

void MonitorWorker::stop() {
    qDebug() << "[Worker] Stop monitor";
    globalRequests.stopWork = false;
    emit stoped();
    return;
}
