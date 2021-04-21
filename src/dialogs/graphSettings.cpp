#include "graphSettings.h"
#include "ui_graphSettings.h"

GraphDialog::GraphDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphSettings)
{
    ui->setupUi(this);
    //params = &globalParams.graph;

    ui->cbAutoH->setChecked(params->autoX);
    ui->cbAutoV->setChecked(params->autoY);
    ui->cbLogV->setChecked(params->logY);
    ui->sbFromH->setValue(params->minX);
    ui->sbFromH->setEnabled(!params->autoX);
    ui->sbToH->setValue(params->maxX);
    ui->sbToH->setEnabled(!params->autoX);
    ui->sbFromV->setValue(params->minY);
    ui->sbFromV->setEnabled(!params->autoY);
    ui->sbToV->setValue(params->maxY);
    ui->sbToV->setEnabled(!params->autoY);
}

void GraphDialog::show() {
    ui->cbAutoH->setChecked(params->autoX);
    ui->cbAutoV->setChecked(params->autoY);
    ui->cbLogV->setChecked(params->logY);
    ui->sbFromH->setValue(params->minX);
    ui->sbFromH->setEnabled(!params->autoX);
    ui->sbToH->setValue(params->maxX);
    ui->sbToH->setEnabled(!params->autoX);
    ui->sbFromV->setValue(params->minY);
    ui->sbFromV->setEnabled(!params->autoY);
    ui->sbToV->setValue(params->maxY);
    ui->sbToV->setEnabled(!params->autoY);

    QDialog::show();
}

void GraphDialog::on_pbOk_clicked() {
    params->autoX = ui->cbAutoH->isChecked();
    if (!params->autoX) {
        params->minX = ui->sbFromH->value();
        params->maxX = ui->sbToH->value();
    }

    params->autoY = ui->cbAutoV->isChecked();
    if (!params->autoY) {
        params->minY = ui->sbFromV->value();
        params->maxY = ui->sbToV->value();
    }
    params->logY = ui->cbLogV->isChecked();
    emit paramsUpdated();
    close();
}

void GraphDialog::on_pbCancel_clicked() {
    close();
}

void GraphDialog::on_cbAutoH_clicked(bool checked) {
    ui->sbFromH->setEnabled(!checked);
    ui->sbToH->setEnabled(!checked);
}

void GraphDialog::on_cbAutoV_clicked(bool checked) {
    ui->sbFromV->setEnabled(!checked);
    ui->sbToV->setEnabled(!checked);
}

GraphDialog::~GraphDialog() {
    delete ui;
}
