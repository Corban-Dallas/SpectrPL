#ifndef STATUSWIDGET_H
#define STATUSWIDGET_H

#include <QWidget>

namespace Ui {
class StatusWidget;
}

class StatusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatusWidget(QWidget *parent = 0);
    ~StatusWidget();

public slots:
    void updateCntStatus(ushort);
    void updateSmdStatus(ushort);
    void updatePosition(int);

    void updateCntErrorCount();
    void updateSmdErrorCount();

    void updateSecondReadCount();

    void updateStatus(QString);

private:
    Ui::StatusWidget *ui;
    int secondReadCount = 0;

    int cntErrorCount = 0;
    int smdErrorCount = 0;
};

#endif // STATUSWIDGET_H
