#include "statuswidget.h"
#include "ui_statuswidget.h"

StatusWidget::StatusWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusWidget)
{
    ui->setupUi(this);
}

void StatusWidget::updateCntStatus(ushort status) {

    ui->lbCntStatus->setText(QString::number(status));
}

void StatusWidget::updateSmdStatus(ushort status) {
    ui->lbSmdStatus->setText(QString::number(status));
}

void StatusWidget::updatePosition(int position) {
    ui->lbSmdPosition->setText(QString::number(position));
}


void StatusWidget::updateCntErrorCount() {
    cntErrorCount++;
    ui->lbCntErrorCount->setText(QString::number(cntErrorCount));
}

void StatusWidget::updateSmdErrorCount() {
    smdErrorCount++;
    ui->lbSmdErrorCount->setText(QString::number(smdErrorCount));
}

void StatusWidget::updateStatus(QString status) {
    ui->lbStatus->setText(status);
}

void StatusWidget::updateSecondReadCount() {
    secondReadCount++;
    ui->lbSecondRead->setText(QString::number(secondReadCount));
}


StatusWidget::~StatusWidget() {
    delete ui;
}
