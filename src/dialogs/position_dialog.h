#ifndef POSITIONDIALOG_H
#define POSITIONDIALOG_H

#include <QDialog>
#include "../globalparams.h"

extern Parameters globalParams;

namespace Ui {
class PositionDialog;
}

class PositionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PositionDialog(QWidget *parent = 0);

    QPushButton *pbOk;
    ~PositionDialog();

public slots:
    void show();
    void updatePosition(long int);

private slots:
    void on_pbOk_clicked();
    void on_pbCancel_clicked();
    void on_gbSpectrometer_clicked(bool checked);
    void on_gbSmd_clicked(bool checked);

private:
    SmdParams *smd_params = &globalParams.smd;

    ApplicationParams *app_params = &globalParams.app;
    Ui::PositionDialog *ui;
signals:
    void resetPosition();
    void okClicked();
    //void currentStepChanged(int step);
};

#endif // POSITIONDIALOG_H
