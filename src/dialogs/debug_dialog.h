#ifndef DEBUB_DIALOG_H
#define DEBUB_DIALOG_H

#include <QDialog>
#include "../smd.h"
#include "../globalparams.h"

extern Parameters globalParams;

namespace Ui {
class DebugDialog;
}

class DebugDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DebugDialog(SMD *s, QWidget *parent = 0);
    ~DebugDialog();

public slots:
    void updatePosition(int);

private:
    SMD *smd;
    Ui::DebugDialog *ui;
};

#endif // DEBUB_DIALOG_H
