/********************************************************************************
** Form generated from reading UI file 'debug_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUG_DIALOG_H
#define UI_DEBUG_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DebugDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QPushButton *pbCurrentOn;
    QPushButton *pbCurrentOff;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *sbStep;
    QDoubleSpinBox *sbCoefA;
    QDoubleSpinBox *sbCoefB;
    QDoubleSpinBox *sbError;
    QPushButton *pbClose;

    void setupUi(QDialog *DebugDialog)
    {
        if (DebugDialog->objectName().isEmpty())
            DebugDialog->setObjectName(QStringLiteral("DebugDialog"));
        DebugDialog->resize(213, 246);
        verticalLayout = new QVBoxLayout(DebugDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(DebugDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        pbCurrentOn = new QPushButton(groupBox);
        pbCurrentOn->setObjectName(QStringLiteral("pbCurrentOn"));

        formLayout->setWidget(0, QFormLayout::LabelRole, pbCurrentOn);

        pbCurrentOff = new QPushButton(groupBox);
        pbCurrentOff->setObjectName(QStringLiteral("pbCurrentOff"));

        formLayout->setWidget(0, QFormLayout::FieldRole, pbCurrentOff);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        sbStep = new QSpinBox(groupBox);
        sbStep->setObjectName(QStringLiteral("sbStep"));
        sbStep->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbStep->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbStep->setMinimum(-10000000);
        sbStep->setMaximum(10000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, sbStep);

        sbCoefA = new QDoubleSpinBox(groupBox);
        sbCoefA->setObjectName(QStringLiteral("sbCoefA"));
        sbCoefA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbCoefA->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbCoefA->setMinimum(-1e+7);
        sbCoefA->setMaximum(1e+7);

        formLayout->setWidget(2, QFormLayout::FieldRole, sbCoefA);

        sbCoefB = new QDoubleSpinBox(groupBox);
        sbCoefB->setObjectName(QStringLiteral("sbCoefB"));
        sbCoefB->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbCoefB->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbCoefB->setMinimum(-1e+7);
        sbCoefB->setMaximum(1e+7);

        formLayout->setWidget(3, QFormLayout::FieldRole, sbCoefB);

        sbError = new QDoubleSpinBox(groupBox);
        sbError->setObjectName(QStringLiteral("sbError"));
        sbError->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbError->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbError->setMinimum(-1e+7);
        sbError->setMaximum(1e+7);

        formLayout->setWidget(4, QFormLayout::FieldRole, sbError);


        verticalLayout->addWidget(groupBox);

        pbClose = new QPushButton(DebugDialog);
        pbClose->setObjectName(QStringLiteral("pbClose"));

        verticalLayout->addWidget(pbClose);


        retranslateUi(DebugDialog);

        QMetaObject::connectSlotsByName(DebugDialog);
    } // setupUi

    void retranslateUi(QDialog *DebugDialog)
    {
        DebugDialog->setWindowTitle(QApplication::translate("DebugDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("DebugDialog", "SMD", 0));
        pbCurrentOn->setText(QApplication::translate("DebugDialog", "CurrentOn", 0));
        pbCurrentOff->setText(QApplication::translate("DebugDialog", "CurrentOff", 0));
        label->setText(QApplication::translate("DebugDialog", "Step", 0));
        label_2->setText(QApplication::translate("DebugDialog", "CoefA", 0));
        label_3->setText(QApplication::translate("DebugDialog", "CoefB", 0));
        label_4->setText(QApplication::translate("DebugDialog", "Error", 0));
        pbClose->setText(QApplication::translate("DebugDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class DebugDialog: public Ui_DebugDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUG_DIALOG_H
