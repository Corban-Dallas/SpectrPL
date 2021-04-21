#ifndef FAST_SCAN_WORKER_H
#define FAST_SCAN_WORKER_H

#include <QObject>
#include "command_server.h"
#include "globalparams.h"

extern Parameters globalParams;

class FastScanWorker : public QObject
{
    Q_OBJECT
public:
    explicit FastScanWorker(CommandServer *cs, ScanParameters params, QObject *parent = 0);

signals:
    void started();
    void stoped();
    void setAcquisition(ushort ms);
    void gotoWavelength(double wl);
    void reqSignalAcquire(uchar channel);
    void newPoint(double x, double y);

public slots:
    void start();
    void gotoNextPosition();
    void stop();

    void updateWavelength(double wl);
    void registerSignal(uint signal);

private:
    double begin, end;
    uchar channel;
    ushort acquisition;
    char scanDirection;

    bool isLuft = true;
    double luft = 30;
    double wavelength;

    bool last_point = false;
};

#endif // FAST_SCAN_WORKER_H
