#include "position_dialog.h"
#include "ui_position_dialog.h"
#include <QDebug>

PositionDialog::PositionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PositionDialog)
{
    ui->setupUi(this);
    setFixedSize(geometry().width(),geometry().height());
}

void PositionDialog::show() {
    ui->sbError->setValue(globalParams.app.error);
    ui->sbCoefA->setValue(globalParams.app.coefA);
    ui->sbCoefB->setValue(globalParams.app.coefB);

    if (globalParams.app.coefA == 1.0) ui->cbGratings->setCurrentIndex(0);
    else if (globalParams.app.coefA == 100.0) ui->cbGratings->setCurrentIndex(1);
    else if (globalParams.app.coefA == 0.005) ui->cbGratings->setCurrentIndex(2);
    else if (globalParams.app.coefA == 300.0) ui->cbGratings->setCurrentIndex(3);
    else ui->cbGratings->setCurrentIndex(4);
    QDialog::show();
}

void PositionDialog::updatePosition(long int smd_step) {
    double coefA = globalParams.app.coefA;
    double coefB = globalParams.app.coefB;
    double error = globalParams.app.error;

    ui->sbStep->setValue(smd_step);
    ui->sbWavelength->setValue(smd_step*coefA + coefB);
}

void PositionDialog::on_pbOk_clicked() {
    if (ui->gbSpectrometer->isChecked()) {
        switch (ui->cbGratings->currentIndex()) {
        case 0: // 100 grating
            globalParams.app.coefA = 1.0;
            break;
        case 1: // 300 grating
            globalParams.app.coefA = 0.01;
            break;
        case 2: // 600 grating
            globalParams.app.coefA = 0.005; // 0.005
            break;
        case 3: // 1200 grating
            globalParams.app.coefA = 1.0/300;
            break;
        default:
            //globalParams.app.coefA = globalParams.app.coefA;
            break;
        }
        globalParams.app.coefB = ui->sbWavelength->value();
        globalParams.app.error = ui->sbError->value();
    }
    else {
        globalParams.app.coefA = ui->sbCoefA->value();
        globalParams.app.coefB = ui->sbCoefB->value();
        globalParams.app.error = 0;
    }
    emit resetPosition();
    emit okClicked();
    close();
}

void PositionDialog::on_pbCancel_clicked() {
    close();
}

void PositionDialog::on_gbSpectrometer_clicked(bool checked) {
    ui->gbSmd->setChecked(!checked);
}

void PositionDialog::on_gbSmd_clicked(bool checked) {
    ui->gbSpectrometer->setChecked(!checked);
}

PositionDialog::~PositionDialog() {
    delete ui;
}
