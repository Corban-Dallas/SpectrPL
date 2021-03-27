/********************************************************************************
** Form generated from reading UI file 'port_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORT_DIALOG_H
#define UI_PORT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_PortDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *cbSmdPorts;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbOk;
    QPushButton *pbCancel;
    QComboBox *cbCntPorts;
    QLabel *label_2;

    void setupUi(QDialog *PortDialog)
    {
        if (PortDialog->objectName().isEmpty())
            PortDialog->setObjectName(QStringLiteral("PortDialog"));
        PortDialog->setWindowModality(Qt::WindowModal);
        PortDialog->resize(264, 110);
        gridLayout = new QGridLayout(PortDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(PortDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cbSmdPorts = new QComboBox(PortDialog);
        cbSmdPorts->setObjectName(QStringLiteral("cbSmdPorts"));

        gridLayout->addWidget(cbSmdPorts, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pbOk = new QPushButton(PortDialog);
        pbOk->setObjectName(QStringLiteral("pbOk"));

        horizontalLayout->addWidget(pbOk);

        pbCancel = new QPushButton(PortDialog);
        pbCancel->setObjectName(QStringLiteral("pbCancel"));

        horizontalLayout->addWidget(pbCancel);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        cbCntPorts = new QComboBox(PortDialog);
        cbCntPorts->setObjectName(QStringLiteral("cbCntPorts"));

        gridLayout->addWidget(cbCntPorts, 1, 1, 1, 1);

        label_2 = new QLabel(PortDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        retranslateUi(PortDialog);

        QMetaObject::connectSlotsByName(PortDialog);
    } // setupUi

    void retranslateUi(QDialog *PortDialog)
    {
        PortDialog->setWindowTitle(QApplication::translate("PortDialog", "Serial port", 0));
        label->setText(QApplication::translate("PortDialog", "SMD serial port:", 0));
        pbOk->setText(QApplication::translate("PortDialog", "OK", 0));
        pbCancel->setText(QApplication::translate("PortDialog", "Cancel", 0));
        label_2->setText(QApplication::translate("PortDialog", "CNT serial port:", 0));
    } // retranslateUi

};

namespace Ui {
    class PortDialog: public Ui_PortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORT_DIALOG_H
