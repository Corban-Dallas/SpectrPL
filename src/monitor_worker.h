#ifndef MONITOR_WORKER_H
#define MONITOR_WORKER_H

#include <QObject>
#include <QtDebug>
#include "globalparams.h"
#include "command_server.h"

extern GlobalRequests globalRequests;

class MonitorWorker : public QObject
{
    Q_OBJECT
public:
    explicit MonitorWorker(CommandServer *cs, ushort acquisition,
                           uchar channel, QObject *parent = 0);

signals:
    void started();
    void stoped();
    void newPoint(uint);

    void reqSignalAcquire(uchar chanel);


    void cntRequestValue(int chanel);
    void setAcquisition(ushort ms);

public slots:
    void start();
    void registerSignal(uint signal);
    void proceed();
    void stop();


private:
    uchar channel;
    ushort acquisition;
};

#endif // MONITOR_WORKER_H
