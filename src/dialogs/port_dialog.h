#ifndef PORTDIALOG_H
#define PORTDIALOG_H

#include <QDialog>
#include "../globalparams.h"

extern Parameters globalParams;

namespace Ui {
class PortDialog;
}

class PortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PortDialog(QWidget *parent = 0);
    ~PortDialog();
public slots:
    void show();

private:
    Ui::PortDialog *ui;
    PortParams *cntPort, *smdPort;

private slots:
    void on_pbOk_clicked();
    void on_pbCancel_clicked();
};

#endif // PORTDIALOG_H
