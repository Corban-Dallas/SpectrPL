/********************************************************************************
** Form generated from reading UI file 'statuswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSWIDGET_H
#define UI_STATUSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatusWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLabel *lbSmdPosition;
    QLabel *label_5;
    QLabel *lbStatus;
    QLabel *label;
    QLabel *lbCntStatus;
    QLabel *label_2;
    QLabel *lbSmdStatus;
    QLabel *label_3;
    QLabel *lbCntErrorCount;
    QLabel *label_4;
    QLabel *lbSmdErrorCount;
    QLabel *label_6;
    QLabel *lbSecondRead;

    void setupUi(QWidget *StatusWidget)
    {
        if (StatusWidget->objectName().isEmpty())
            StatusWidget->setObjectName(QStringLiteral("StatusWidget"));
        StatusWidget->resize(789, 17);
        horizontalLayout = new QHBoxLayout(StatusWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        label_7 = new QLabel(StatusWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        lbSmdPosition = new QLabel(StatusWidget);
        lbSmdPosition->setObjectName(QStringLiteral("lbSmdPosition"));

        horizontalLayout->addWidget(lbSmdPosition);

        label_5 = new QLabel(StatusWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        lbStatus = new QLabel(StatusWidget);
        lbStatus->setObjectName(QStringLiteral("lbStatus"));

        horizontalLayout->addWidget(lbStatus);

        label = new QLabel(StatusWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lbCntStatus = new QLabel(StatusWidget);
        lbCntStatus->setObjectName(QStringLiteral("lbCntStatus"));

        horizontalLayout->addWidget(lbCntStatus);

        label_2 = new QLabel(StatusWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lbSmdStatus = new QLabel(StatusWidget);
        lbSmdStatus->setObjectName(QStringLiteral("lbSmdStatus"));

        horizontalLayout->addWidget(lbSmdStatus);

        label_3 = new QLabel(StatusWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lbCntErrorCount = new QLabel(StatusWidget);
        lbCntErrorCount->setObjectName(QStringLiteral("lbCntErrorCount"));

        horizontalLayout->addWidget(lbCntErrorCount);

        label_4 = new QLabel(StatusWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        lbSmdErrorCount = new QLabel(StatusWidget);
        lbSmdErrorCount->setObjectName(QStringLiteral("lbSmdErrorCount"));

        horizontalLayout->addWidget(lbSmdErrorCount);

        label_6 = new QLabel(StatusWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        lbSecondRead = new QLabel(StatusWidget);
        lbSecondRead->setObjectName(QStringLiteral("lbSecondRead"));

        horizontalLayout->addWidget(lbSecondRead);


        retranslateUi(StatusWidget);

        QMetaObject::connectSlotsByName(StatusWidget);
    } // setupUi

    void retranslateUi(QWidget *StatusWidget)
    {
        StatusWidget->setWindowTitle(QApplication::translate("StatusWidget", "Form", 0));
        label_7->setText(QApplication::translate("StatusWidget", "SMD positon", 0));
        lbSmdPosition->setText(QApplication::translate("StatusWidget", "##", 0));
        label_5->setText(QApplication::translate("StatusWidget", "Status:", 0));
        lbStatus->setText(QApplication::translate("StatusWidget", "##", 0));
        label->setText(QApplication::translate("StatusWidget", "CNT status:", 0));
        lbCntStatus->setText(QApplication::translate("StatusWidget", "##", 0));
        label_2->setText(QApplication::translate("StatusWidget", "SMD status:", 0));
        lbSmdStatus->setText(QApplication::translate("StatusWidget", "##", 0));
        label_3->setText(QApplication::translate("StatusWidget", "CNT error count:", 0));
        lbCntErrorCount->setText(QApplication::translate("StatusWidget", "0", 0));
        label_4->setText(QApplication::translate("StatusWidget", "SMD error count:", 0));
        lbSmdErrorCount->setText(QApplication::translate("StatusWidget", "0", 0));
        label_6->setText(QApplication::translate("StatusWidget", "Secnod read:", 0));
        lbSecondRead->setText(QApplication::translate("StatusWidget", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class StatusWidget: public Ui_StatusWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSWIDGET_H
