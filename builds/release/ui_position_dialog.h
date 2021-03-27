/********************************************************************************
** Form generated from reading UI file 'position_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITION_DIALOG_H
#define UI_POSITION_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_PositionDialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *gbSpectrometer;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *cbGratings;
    QLabel *label_2;
    QDoubleSpinBox *sbWavelength;
    QLabel *label_3;
    QSpinBox *sbError;
    QGroupBox *gbSmd;
    QFormLayout *formLayout;
    QLabel *label_4;
    QSpinBox *sbStep;
    QLabel *label_6;
    QDoubleSpinBox *sbCoefA;
    QLabel *label_7;
    QDoubleSpinBox *sbCoefB;
    QPushButton *pbOk;
    QPushButton *pbCancel;

    void setupUi(QDialog *PositionDialog)
    {
        if (PositionDialog->objectName().isEmpty())
            PositionDialog->setObjectName(QStringLiteral("PositionDialog"));
        PositionDialog->setWindowModality(Qt::WindowModal);
        PositionDialog->resize(279, 322);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PositionDialog->sizePolicy().hasHeightForWidth());
        PositionDialog->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(PositionDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gbSpectrometer = new QGroupBox(PositionDialog);
        gbSpectrometer->setObjectName(QStringLiteral("gbSpectrometer"));
        gbSpectrometer->setCheckable(true);
        gridLayout = new QGridLayout(gbSpectrometer);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(gbSpectrometer);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cbGratings = new QComboBox(gbSpectrometer);
        cbGratings->setObjectName(QStringLiteral("cbGratings"));

        gridLayout->addWidget(cbGratings, 0, 1, 1, 1);

        label_2 = new QLabel(gbSpectrometer);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        sbWavelength = new QDoubleSpinBox(gbSpectrometer);
        sbWavelength->setObjectName(QStringLiteral("sbWavelength"));
        sbWavelength->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbWavelength->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbWavelength->setMaximum(1e+6);

        gridLayout->addWidget(sbWavelength, 1, 1, 1, 1);

        label_3 = new QLabel(gbSpectrometer);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        sbError = new QSpinBox(gbSpectrometer);
        sbError->setObjectName(QStringLiteral("sbError"));
        sbError->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbError->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbError->setMinimum(-1000);
        sbError->setMaximum(1000);

        gridLayout->addWidget(sbError, 2, 1, 1, 1);


        gridLayout_2->addWidget(gbSpectrometer, 0, 0, 1, 2);

        gbSmd = new QGroupBox(PositionDialog);
        gbSmd->setObjectName(QStringLiteral("gbSmd"));
        gbSmd->setEnabled(true);
        gbSmd->setCheckable(true);
        gbSmd->setChecked(false);
        formLayout = new QFormLayout(gbSmd);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_4 = new QLabel(gbSmd);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        sbStep = new QSpinBox(gbSmd);
        sbStep->setObjectName(QStringLiteral("sbStep"));
        sbStep->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbStep->setReadOnly(true);
        sbStep->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbStep->setMaximum(1000000000);

        formLayout->setWidget(0, QFormLayout::FieldRole, sbStep);

        label_6 = new QLabel(gbSmd);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        sbCoefA = new QDoubleSpinBox(gbSmd);
        sbCoefA->setObjectName(QStringLiteral("sbCoefA"));
        sbCoefA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbCoefA->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbCoefA->setDecimals(3);
        sbCoefA->setMinimum(-1e+6);
        sbCoefA->setMaximum(1e+6);

        formLayout->setWidget(1, QFormLayout::FieldRole, sbCoefA);

        label_7 = new QLabel(gbSmd);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        sbCoefB = new QDoubleSpinBox(gbSmd);
        sbCoefB->setObjectName(QStringLiteral("sbCoefB"));
        sbCoefB->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbCoefB->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbCoefB->setDecimals(3);
        sbCoefB->setMinimum(-1e+6);
        sbCoefB->setMaximum(1e+6);

        formLayout->setWidget(2, QFormLayout::FieldRole, sbCoefB);


        gridLayout_2->addWidget(gbSmd, 1, 0, 1, 2);

        pbOk = new QPushButton(PositionDialog);
        pbOk->setObjectName(QStringLiteral("pbOk"));

        gridLayout_2->addWidget(pbOk, 2, 0, 1, 1);

        pbCancel = new QPushButton(PositionDialog);
        pbCancel->setObjectName(QStringLiteral("pbCancel"));

        gridLayout_2->addWidget(pbCancel, 2, 1, 1, 1);


        retranslateUi(PositionDialog);

        cbGratings->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(PositionDialog);
    } // setupUi

    void retranslateUi(QDialog *PositionDialog)
    {
        PositionDialog->setWindowTitle(QApplication::translate("PositionDialog", "Position", 0));
        gbSpectrometer->setTitle(QApplication::translate("PositionDialog", "Spectrometer", 0));
        label->setText(QApplication::translate("PositionDialog", "Grating's spacing:", 0));
        cbGratings->clear();
        cbGratings->insertItems(0, QStringList()
         << QApplication::translate("PositionDialog", "100", 0)
         << QApplication::translate("PositionDialog", "300", 0)
         << QApplication::translate("PositionDialog", "600", 0)
         << QApplication::translate("PositionDialog", "1200", 0)
         << QApplication::translate("PositionDialog", "Custom", 0)
        );
        label_2->setText(QApplication::translate("PositionDialog", "Wavelength:", 0));
        label_3->setText(QApplication::translate("PositionDialog", "Display error:", 0));
        gbSmd->setTitle(QApplication::translate("PositionDialog", "SMD", 0));
        label_4->setText(QApplication::translate("PositionDialog", "Current step:", 0));
        label_6->setText(QApplication::translate("PositionDialog", "Coef A:", 0));
        label_7->setText(QApplication::translate("PositionDialog", "Coef B:", 0));
        pbOk->setText(QApplication::translate("PositionDialog", "OK", 0));
        pbCancel->setText(QApplication::translate("PositionDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class PositionDialog: public Ui_PositionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITION_DIALOG_H
