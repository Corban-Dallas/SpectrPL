#ifndef MOVE_TO_POSITION_WORKER_H
#define MOVE_TO_POSITION_WORKER_H

#include <QObject>
#include "command_server.h"
#include "globalparams.h"

//extern Parameters globalParams;
extern GlobalRequests globalRequests;
extern Parameters globalParams;

class GotoWavelengthWorker : public QObject
{
    Q_OBJECT
public:
    explicit GotoWavelengthWorker(CommandServer *cs, double wavelength, QObject *parent = 0);

signals:
    void gotoWavelength(double wl);
    void started();
    void stoped();

public slots:
    void start();
    void stop();

private:
    int wavelength;
    bool is_luft_position = true;
};

#endif // MOVE_TO_POSITION_WORKER_H
