#include "port_dialog.h"
#include "ui_port_dialog.h"
#include <QDebug>

PortDialog::PortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortDialog)
{
    ui->setupUi(this);
    //params = &globalParams.port;

    const auto ports = QSerialPortInfo::availablePorts();
    if (ports.isEmpty()) return;
    for (auto port : ports) {
        ui->cbSmdPorts->addItem(port.portName());
        ui->cbCntPorts->addItem(port.portName());
    }
    cntPort = &globalParams.cnt.port;
    smdPort = &globalParams.smd.port;
}

void PortDialog::show() {
    for (int i = 0; i < ui->cbSmdPorts->count(); i++) {
        if (ui->cbSmdPorts->itemText(i) == smdPort->portName) {
            ui->cbSmdPorts->setCurrentIndex(i);
        }
    }
    for (int i = 0; i < ui->cbCntPorts->count(); i++) {
        if (ui->cbCntPorts->itemText(i) == cntPort->portName) {
            ui->cbCntPorts->setCurrentIndex(i);
        }
    }
    QDialog::show();
}

PortDialog::~PortDialog()
{
    delete ui;
}

void PortDialog::on_pbOk_clicked() {
    if (ui->cbSmdPorts->count() != 0) {
        smdPort->portName = ui->cbSmdPorts->currentText();
        cntPort->portName = ui->cbCntPorts->currentText();
    }
    close();
}

void PortDialog::on_pbCancel_clicked() {
    close();
}
