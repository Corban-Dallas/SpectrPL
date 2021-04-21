#ifndef GRAPHDIALOG_H
#define GRAPHDIALOG_H

#include <QDialog>
#include "..\globalparams.h"

extern Parameters globalParams;

namespace Ui {
class GraphSettings;
}

class GraphDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GraphDialog(QWidget *parent = 0);
    ~GraphDialog();

public slots:
    void show();

private slots:
    void on_pbOk_clicked();
    void on_pbCancel_clicked();
    void on_cbAutoH_clicked(bool checked);
    void on_cbAutoV_clicked(bool checked);

private:
    Ui::GraphSettings *ui;
    GraphParameters *const params = &globalParams.graph;

signals:
    void paramsUpdated();
};

#endif // GRAPHDIALOG_H
