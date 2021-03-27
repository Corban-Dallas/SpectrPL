/********************************************************************************
** Form generated from reading UI file 'graph_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_DIALOG_H
#define UI_GRAPH_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GraphDialog
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label;
    QDoubleSpinBox *sbFromH;
    QDoubleSpinBox *sbToH;
    QCheckBox *cbAutoH;
    QLabel *label_2;
    QDoubleSpinBox *sbFromV;
    QDoubleSpinBox *sbToV;
    QCheckBox *cbAutoV;
    QCheckBox *cbLogV;
    QPushButton *pbOk;
    QPushButton *pbCancel;

    void setupUi(QDialog *GraphDialog)
    {
        if (GraphDialog->objectName().isEmpty())
            GraphDialog->setObjectName(QStringLiteral("GraphDialog"));
        GraphDialog->resize(289, 171);
        groupBox = new QGroupBox(GraphDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(9, 9, 270, 117));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 3, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(40, 0));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        sbFromH = new QDoubleSpinBox(groupBox);
        sbFromH->setObjectName(QStringLiteral("sbFromH"));
        sbFromH->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbFromH->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbFromH->setMaximum(100000);

        gridLayout->addWidget(sbFromH, 1, 1, 1, 1);

        sbToH = new QDoubleSpinBox(groupBox);
        sbToH->setObjectName(QStringLiteral("sbToH"));
        sbToH->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbToH->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbToH->setMaximum(100000);

        gridLayout->addWidget(sbToH, 1, 2, 1, 1);

        cbAutoH = new QCheckBox(groupBox);
        cbAutoH->setObjectName(QStringLiteral("cbAutoH"));

        gridLayout->addWidget(cbAutoH, 1, 3, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(40, 0));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        sbFromV = new QDoubleSpinBox(groupBox);
        sbFromV->setObjectName(QStringLiteral("sbFromV"));
        sbFromV->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbFromV->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbFromV->setMinimum(1);
        sbFromV->setMaximum(5e+8);

        gridLayout->addWidget(sbFromV, 2, 1, 1, 1);

        sbToV = new QDoubleSpinBox(groupBox);
        sbToV->setObjectName(QStringLiteral("sbToV"));
        sbToV->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbToV->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbToV->setMinimum(1);
        sbToV->setMaximum(5e+8);

        gridLayout->addWidget(sbToV, 2, 2, 1, 1);

        cbAutoV = new QCheckBox(groupBox);
        cbAutoV->setObjectName(QStringLiteral("cbAutoV"));

        gridLayout->addWidget(cbAutoV, 2, 3, 1, 1);

        cbLogV = new QCheckBox(groupBox);
        cbLogV->setObjectName(QStringLiteral("cbLogV"));
        cbLogV->setEnabled(false);

        gridLayout->addWidget(cbLogV, 2, 4, 1, 1);

        pbOk = new QPushButton(GraphDialog);
        pbOk->setObjectName(QStringLiteral("pbOk"));
        pbOk->setGeometry(QRect(110, 139, 80, 23));
        pbCancel = new QPushButton(GraphDialog);
        pbCancel->setObjectName(QStringLiteral("pbCancel"));
        pbCancel->setGeometry(QRect(200, 140, 80, 23));

        retranslateUi(GraphDialog);

        QMetaObject::connectSlotsByName(GraphDialog);
    } // setupUi

    void retranslateUi(QDialog *GraphDialog)
    {
        GraphDialog->setWindowTitle(QApplication::translate("GraphDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("GraphDialog", "Scale", 0));
        label_3->setText(QApplication::translate("GraphDialog", "From", 0));
        label_4->setText(QApplication::translate("GraphDialog", "To", 0));
        label_6->setText(QApplication::translate("GraphDialog", "Auto", 0));
        label_5->setText(QApplication::translate("GraphDialog", "Log", 0));
        label->setText(QApplication::translate("GraphDialog", "Hor", 0));
        cbAutoH->setText(QString());
        label_2->setText(QApplication::translate("GraphDialog", "Ver", 0));
        cbAutoV->setText(QString());
        cbLogV->setText(QString());
        pbOk->setText(QApplication::translate("GraphDialog", "OK", 0));
        pbCancel->setText(QApplication::translate("GraphDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphDialog: public Ui_GraphDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_DIALOG_H
