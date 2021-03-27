#include "scandialog.h"
#include "ui_scandialog.h"

ScanDialog::ScanDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScanDialog)
{
    ui->setupUi(this);
    updateValues();
    ui->sbDac->setSingleStep(1/255.0);
}

void ScanDialog::show() {
    updateValues();
    QDialog::show();
}

void ScanDialog::updateValues() {
    ui->sbDefAccel->setValue(app->defAccel);
    ui->sbDefSpeed->setValue(app->defSpeed);
    ui->sbScanAccel->setValue(app->scanAccel);
    ui->sbScanSpeed->setValue(app->scanSpeed);
    ui->sbFScanAccel->setValue(app->fScanAccel);
    ui->sbFScanSpeed->setValue(app->fScanSpeed);
    ui->sbLuft->setValue(app->luft);
    ui->sbDac->setValue(cnt->dac/255.0);
}

ScanDialog::~ScanDialog() {
    delete ui;
}

void ScanDialog::on_pbOk_clicked() {
    app->defAccel = ui->sbDefAccel->value();
    app->defSpeed = ui->sbDefSpeed->value();
    app->scanAccel = ui->sbScanAccel->value();
    app->scanSpeed = ui->sbScanSpeed->value();
    app->fScanAccel = ui->sbFScanAccel->value();
    app->fScanSpeed = ui->sbFScanSpeed->value();
    app->luft = ui->sbLuft->value();
    cnt->dac = 255*ui->sbDac->value();
    emit setCntDac(255*ui->sbDac->value());
    emit okClicked();
    close();
}

void ScanDialog::on_pbCancel_clicked() {
    close();

}

void ScanDialog::on_pbDefault_clicked() {
    ApplicationParams def_app;
    CntParams def_cnt;
    ui->sbDefAccel->setValue(def_app.defAccel);
    ui->sbDefSpeed->setValue(def_app.defSpeed);
    ui->sbScanAccel->setValue(def_app.scanAccel);
    ui->sbScanSpeed->setValue(def_app.scanSpeed);
    ui->sbFScanAccel->setValue(def_app.fScanAccel);
    ui->sbFScanSpeed->setValue(def_app.fScanSpeed);
    ui->sbLuft->setValue(def_app.luft);
    ui->sbDac->setValue(def_cnt.dac/255.0);

}
