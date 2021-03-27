#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>
#include <QWidget>
#include <QtCharts>
#include "graph_dialog.h"
#include "globalparams.h"

extern Parameters globalParams;

class Graph : public QtCharts::QChartView
{
    Q_OBJECT
public:
    explicit Graph(QWidget *parent = 0);

    QVector<QPointF> points();
    ~Graph();

public slots:
    void startMonitor();
    void stopMonitor();
    void addMonitorPoint(uint);

    void startPlot();
    void addPoint(double, double);
    void finishPlot();

    void plot(QVector<QPointF> points);
    void setXRange(double, double);

private slots:
    void showContextMenu(const QPoint& pos);
    void updateParams();
    void rescale();

private:
    GraphDialog *graphDialog;
    GraphParameters *const params = &globalParams.graph;

    QtCharts::QChart *chart;
    QtCharts::QValueAxis *axisX;
    QtCharts::QValueAxis *axisY;
    QtCharts::QLogValueAxis *logAxisY;

    QtCharts::QLineSeries *currentSeries;

    QVector<double> *vectorY;
    uchar mode = GraphMode::Idle;

    QMenu *contextMenu;
    QAction *formatAction;
    QAction *rescaleAction;

    void createContextMenu();
    void createGraphDialog();
    void createAxises();

    double scanBegin;
    double scanEnd;

    enum GraphMode : uchar {
        Monitoring, // Когда включени монитор
        Plotting,   // Когда идёт сканирование
        Idle        // Когда устройство бездействует
    };
};

#endif // GRAPH_H
