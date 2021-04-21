#ifndef SCANDIALOG_H
#define SCANDIALOG_H

#include <QDialog>
#include "../globalparams.h"

extern Parameters globalParams;

namespace Ui {
class ScanDialog;
}

class ScanDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScanDialog(QWidget *parent = 0);
    ~ScanDialog();

public slots:
    void show();

signals:
    void okClicked();
    void setCntDac(uchar);

private:
    Ui::ScanDialog *ui;
    CntParams *const cnt = &globalParams.cnt;
    ApplicationParams *const app = &globalParams.app;
    void updateValues();

private slots:
    void on_pbOk_clicked();
    void on_pbCancel_clicked();
    void on_pbDefault_clicked();
};

#endif // SCANDIALOG_H
