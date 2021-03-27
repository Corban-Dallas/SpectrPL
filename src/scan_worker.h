#ifndef SCAN_WORKER_H
#define SCAN_WORKER_H

#include <QObject>
#include <QThread>
#include "command_server.h"
#include "globalparams.h"

extern Parameters globalParams;
extern GlobalRequests globalRequests;

class ScanWorker : public QObject
{
    Q_OBJECT
public:
    explicit ScanWorker(CommandServer *cs, ScanParameters params, QObject *parent = 0);

signals:
    void started();
    void reqSignalAcquire(uchar chanel);
    void newPoint(double x, double y);
    void gotoWavelength(double wl);
    void stoped();

    void setSmdPowerOn();
    void setSmdPowerOff();
    void setAcquisition(ushort ms);

public slots:
    void start();
    void measureSignal();
    void registerSignal(uint signal);
    void gotoNextPoint();
    void stop();

private:
    double begin, end, step;
    uchar channel;
    ushort acquisition;
    char dir;

    double coefA, coefB, error;
    double luft = 30; // Angstrem
    double wavelength;

    int n_step = 0;
    bool is_luft = true;

    bool power_off_while_read_signal = false;

private slots:
    void updateWavelength(double wl);


};

#endif // SCAN_WORKER_H
