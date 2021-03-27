#include "debug_dialog.h"
#include "ui_debug_dialog.h"

DebugDialog::DebugDialog(SMD *s, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DebugDialog)
{
    smd = s;
    ui->setupUi(this);
    connect(ui->pbCurrentOn, &QPushButton::clicked,
            smd, &SMD::powerOn);
    connect(ui->pbCurrentOff, &QPushButton::clicked,
            smd, &SMD::powerOff);
    connect(ui->pbClose, &QPushButton::clicked,
            this, &DebugDialog::close);
}

void DebugDialog::updatePosition(int step) {
    ui->sbStep->setValue(step);
    ui->sbCoefA->setValue(globalParams.app.coefA);
    ui->sbCoefB->setValue(globalParams.app.coefB);
    ui->sbError->setValue(globalParams.app.error);
}

DebugDialog::~DebugDialog()
{
    delete ui;
}
