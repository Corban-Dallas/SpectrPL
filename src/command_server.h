#ifndef COMMAND_SERVER_H
#define COMMAND_SERVER_H

#include <QObject>
#include "smd.h"
#include "cnt.h"
#include "globalparams.h"

extern Parameters globalParams;
extern GlobalRequests globalRequests;

class CommandServer : public QObject
{
    Q_OBJECT
public:
    explicit CommandServer(SMD *smd, CNT *cnt, QObject *parent = 0);

signals:
    // Public
    void wlUpdated(double wavelength);
    void stUpdated(long int smd_step);
    void moveStoped();
    void moveFinished();
    void signalAcquired(uint count);
    void setCntAcquisition(ushort ms);
    void setCntDac(uchar dac);
    void beginSignalAcquire(uchar chanel);
    void reqSmdResetStep();


    // Private
    void reqSmdMoveTo(long int step);
    void reqSmdStop();
    void reqSmdPowerOff();
    void reqSmdPowerOn();
    void reqCntValue();

private:
    double coefA, coefB, error;
    double wavelength = 0;

private slots:
    void updatePosition(long int smd_step);

public slots:
    //void setWavelength(double wavelength);
    void gotoWavelength(double wavelength);
};

#endif // COMMAND_SERVER_H
