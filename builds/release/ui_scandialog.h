/********************************************************************************
** Form generated from reading UI file 'scandialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANDIALOG_H
#define UI_SCANDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ScanDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *sbDefSpeed;
    QLabel *label_2;
    QSpinBox *sbDefAccel;
    QLabel *label_25;
    QSpinBox *sbScanSpeed;
    QLabel *label_24;
    QSpinBox *sbScanAccel;
    QLabel *label_21;
    QSpinBox *sbFScanSpeed;
    QLabel *label_23;
    QSpinBox *sbFScanAccel;
    QLabel *label_7;
    QSpinBox *sbLuft;
    QPushButton *pbOk;
    QPushButton *pbDefault;
    QPushButton *pbCancel;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *sbDac;

    void setupUi(QDialog *ScanDialog)
    {
        if (ScanDialog->objectName().isEmpty())
            ScanDialog->setObjectName(QStringLiteral("ScanDialog"));
        ScanDialog->setWindowModality(Qt::WindowModal);
        ScanDialog->resize(281, 418);
        gridLayout = new QGridLayout(ScanDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(ScanDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        sbDefSpeed = new QSpinBox(groupBox);
        sbDefSpeed->setObjectName(QStringLiteral("sbDefSpeed"));
        sbDefSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbDefSpeed->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbDefSpeed->setMaximum(2000);
        sbDefSpeed->setSingleStep(100);

        formLayout->setWidget(0, QFormLayout::FieldRole, sbDefSpeed);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sbDefAccel = new QSpinBox(groupBox);
        sbDefAccel->setObjectName(QStringLiteral("sbDefAccel"));
        sbDefAccel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbDefAccel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbDefAccel->setMaximum(1000);
        sbDefAccel->setSingleStep(100);

        formLayout->setWidget(1, QFormLayout::FieldRole, sbDefAccel);

        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QStringLiteral("label_25"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_25);

        sbScanSpeed = new QSpinBox(groupBox);
        sbScanSpeed->setObjectName(QStringLiteral("sbScanSpeed"));
        sbScanSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbScanSpeed->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbScanSpeed->setMaximum(2000);
        sbScanSpeed->setSingleStep(100);

        formLayout->setWidget(2, QFormLayout::FieldRole, sbScanSpeed);

        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QStringLiteral("label_24"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_24);

        sbScanAccel = new QSpinBox(groupBox);
        sbScanAccel->setObjectName(QStringLiteral("sbScanAccel"));
        sbScanAccel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbScanAccel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbScanAccel->setMaximum(1000);
        sbScanAccel->setSingleStep(100);

        formLayout->setWidget(3, QFormLayout::FieldRole, sbScanAccel);

        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_21);

        sbFScanSpeed = new QSpinBox(groupBox);
        sbFScanSpeed->setObjectName(QStringLiteral("sbFScanSpeed"));
        sbFScanSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbFScanSpeed->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbFScanSpeed->setMaximum(2000);
        sbFScanSpeed->setSingleStep(100);

        formLayout->setWidget(4, QFormLayout::FieldRole, sbFScanSpeed);

        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QStringLiteral("label_23"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_23);

        sbFScanAccel = new QSpinBox(groupBox);
        sbFScanAccel->setObjectName(QStringLiteral("sbFScanAccel"));
        sbFScanAccel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbFScanAccel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbFScanAccel->setMaximum(1000);
        sbFScanAccel->setSingleStep(100);

        formLayout->setWidget(5, QFormLayout::FieldRole, sbFScanAccel);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        sbLuft = new QSpinBox(groupBox);
        sbLuft->setObjectName(QStringLiteral("sbLuft"));
        sbLuft->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbLuft->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbLuft->setMaximum(1000);
        sbLuft->setSingleStep(5);
        sbLuft->setValue(30);

        formLayout->setWidget(6, QFormLayout::FieldRole, sbLuft);


        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        pbOk = new QPushButton(ScanDialog);
        pbOk->setObjectName(QStringLiteral("pbOk"));

        gridLayout->addWidget(pbOk, 2, 0, 1, 2);

        pbDefault = new QPushButton(ScanDialog);
        pbDefault->setObjectName(QStringLiteral("pbDefault"));

        gridLayout->addWidget(pbDefault, 3, 0, 1, 1);

        pbCancel = new QPushButton(ScanDialog);
        pbCancel->setObjectName(QStringLiteral("pbCancel"));

        gridLayout->addWidget(pbCancel, 3, 1, 1, 1);

        groupBox_2 = new QGroupBox(ScanDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        sbDac = new QDoubleSpinBox(groupBox_2);
        sbDac->setObjectName(QStringLiteral("sbDac"));
        sbDac->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbDac->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbDac->setDecimals(3);
        sbDac->setMinimum(0);
        sbDac->setMaximum(1);
        sbDac->setSingleStep(0.1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, sbDac);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 2);


        retranslateUi(ScanDialog);

        QMetaObject::connectSlotsByName(ScanDialog);
    } // setupUi

    void retranslateUi(QDialog *ScanDialog)
    {
        ScanDialog->setWindowTitle(QApplication::translate("ScanDialog", "Scan profiles", 0));
        groupBox->setTitle(QApplication::translate("ScanDialog", "SMD", 0));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("ScanDialog", "<html><head/><body><p>steps/second</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("ScanDialog", "Default Speed:", 0));
        sbDefSpeed->setSuffix(QString());
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("ScanDialog", "<html><head/><body><p>steps/second<span style=\" vertical-align:super;\">2</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("ScanDialog", "Default Accel:", 0));
        sbDefAccel->setSuffix(QString());
#ifndef QT_NO_TOOLTIP
        label_25->setToolTip(QApplication::translate("ScanDialog", "<html><head/><body><p>steps/second</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_25->setText(QApplication::translate("ScanDialog", "Scan Speed:", 0));
        sbScanSpeed->setSuffix(QString());
#ifndef QT_NO_TOOLTIP
        label_24->setToolTip(QApplication::translate("ScanDialog", "<html><head/><body><p>steps/second<span style=\" vertical-align:super;\">2</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_24->setText(QApplication::translate("ScanDialog", "Scan Accel:", 0));
        sbScanAccel->setSuffix(QString());
#ifndef QT_NO_TOOLTIP
        label_21->setToolTip(QApplication::translate("ScanDialog", "<html><head/><body><p>steps/second</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_21->setText(QApplication::translate("ScanDialog", "Fast Scan Speed:", 0));
        sbFScanSpeed->setSuffix(QString());
#ifndef QT_NO_TOOLTIP
        label_23->setToolTip(QApplication::translate("ScanDialog", "<html><head/><body><p>steps/second<span style=\" vertical-align:super;\">2</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_23->setText(QApplication::translate("ScanDialog", "Fast Scan Accel:", 0));
        sbFScanAccel->setSuffix(QString());
        label_7->setText(QApplication::translate("ScanDialog", "Luft:", 0));
        sbLuft->setSuffix(QApplication::translate("ScanDialog", " A", 0));
        pbOk->setText(QApplication::translate("ScanDialog", "OK", 0));
        pbDefault->setText(QApplication::translate("ScanDialog", "Default", 0));
        pbCancel->setText(QApplication::translate("ScanDialog", "Cancel", 0));
        groupBox_2->setTitle(QApplication::translate("ScanDialog", "CNT", 0));
        label_3->setText(QApplication::translate("ScanDialog", "Input voltage level:", 0));
        sbDac->setSuffix(QApplication::translate("ScanDialog", " V", 0));
    } // retranslateUi

};

namespace Ui {
    class ScanDialog: public Ui_ScanDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANDIALOG_H
