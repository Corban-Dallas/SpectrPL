#include "graph.h"
#include <QDebug>

Graph::Graph(QWidget *parent) : QtCharts::QChartView(parent)
{
    //params = &globalParams.graph;
    chart = new QtCharts::QChart();
    chart->setTitle("Photolumenesence spectra");

    createAxises();
    chart->addAxis(axisX, Qt::AlignBottom);
    if (params->logY) chart->addAxis(logAxisY, Qt::AlignLeft);
    else chart->addAxis(axisY, Qt::AlignLeft);

    setChart(chart);
    setRenderHint(QPainter::Antialiasing);

    currentSeries = new QtCharts::QLineSeries();
    chart->addSeries(currentSeries);
    currentSeries->attachAxis(axisX);
    if (params->logY) currentSeries->attachAxis(logAxisY);
    else currentSeries->attachAxis(axisY);

    // Context menu
    createGraphDialog();
    createContextMenu();
}

void Graph::plot(QVector<QPointF> points) {
    currentSeries->replace(points);
    rescale();
}

QVector<QPointF> Graph::points() {
    return currentSeries->pointsVector();
}

void Graph::setXRange(double begin, double end) {
    if (begin == end) return;

    if (begin < end) {
        axisX->setMin(begin);
        axisX->setMax(end);
    }
    else {
        axisX->setMin(end);
        axisY->setMax(begin);
    }
}

// PUBLIC SLOTS
void Graph::startPlot() {
    qDebug() << "[Graph] Start plot";
    mode = GraphMode::Plotting;
    currentSeries->clear();

    if (!params->autoX) {
        axisX->setMin(params->minX);
        axisX->setMax(params->maxX);
    }

    if (!params->autoY) {
        axisY->setMin(params->minY);
        axisY->setMax(params->maxY);
    }
}

void Graph::addPoint(double x, double y) {
    qDebug() << "[Graph] Add point";
    if (y == 0) y = 2;
    currentSeries->append(QPointF(x, y));
    rescale();
}

void Graph::finishPlot() {
    qDebug() << "[Graph] Stop plot";
    mode = GraphMode::Idle;
}

void Graph::startMonitor() {
    qDebug() << "[Graph] Start monitor";
    mode = GraphMode::Monitoring;
    axisX->setMin(1);
    axisX->setMax(params->monitorPoints);

    vectorY = new QVector<double>(params->monitorPoints, 1);
}

void Graph::stopMonitor() {
    qDebug() << "[Graph] Stop monitor";
    axisX->setMin(params->minX);
    axisX->setMax(params->maxX);
    mode = GraphMode::Idle;
}

void Graph::addMonitorPoint(uint count) {
    qDebug() << "[Graph] Add monitor point";
    if (count == 0) count = 1;
    vectorY->removeFirst();
    vectorY->append(count);

    QVector<QPointF> points;
    for (int i = 0; i < params->monitorPoints; i++)
        points.append(QPointF(i, vectorY->value(i)));

    currentSeries->replace(points);
    rescale();
}

// PRIVATE SLOTS
void Graph::updateParams() {
    if (params->logY && (chart->axisY() == axisY)) {
        currentSeries->detachAxis(axisY);
        chart->removeAxis(axisY);
        chart->addAxis(logAxisY, Qt::AlignLeft);
        currentSeries->attachAxis(logAxisY);

    }
    if (!params->logY && (chart->axisY() == logAxisY)) {
        currentSeries->detachAxis(logAxisY);
        chart->removeAxis(logAxisY);
        chart->addAxis(axisY, Qt::AlignLeft);
        currentSeries->attachAxis(axisY);
    }
    rescale();
}

void Graph::rescale() {
    QVector<QPointF> points = currentSeries->pointsVector();
    if (points.count() < 2) return;



    switch (mode) {
    case (GraphMode::Idle):
        if (params->autoX) {
            double minX = points[0].x();
            double maxX = points[0].x();

            for (auto point : points) {
                if (point.x() < minX) minX = point.x();
                if (point.x() > maxX) maxX = point.x();
            }
            axisX->setMin(minX);
            axisX->setMax(maxX);
        }
        else {
            axisX->setMin(params->minX);
            axisX->setMax(params->maxX);
        }
        break;

    case (GraphMode::Monitoring):
        axisX->setMin(0);
        axisX->setMax(params->monitorPoints);
        break;
    }

    uint minY = points[0].y();
    uint maxY = points[0].y();
    for (auto point : points) {
        if (point.y() < minY) minY = point.y();
        if (point.y() > maxY) maxY = point.y();
    }

    if (params->autoY) {
        axisY->setMin(minY*0.9);
        axisY->setMax(maxY*1.1);
        logAxisY->setMin(minY*0.9);
        logAxisY->setMax(maxY*1.1);
    }
    else {
        axisY->setMin(params->minY);
        axisY->setMax(params->maxY);
        logAxisY->setMin(params->minY);
        logAxisY->setMax(params->maxY);
    }
}

void Graph::showContextMenu(const QPoint& pos) {
    QPoint globalPos = mapToGlobal(pos);
    contextMenu->exec(globalPos);
}

// PRIVATE
void Graph::createGraphDialog() {
    graphDialog = new GraphDialog(this);
    connect(graphDialog, &GraphDialog::paramsUpdated, this, &Graph::updateParams);
}

void Graph::createContextMenu() {
    contextMenu = new QMenu();
    formatAction = new QAction("Format");
    rescaleAction = new QAction("Rescale");

    contextMenu->addAction(formatAction);
    contextMenu->addAction(rescaleAction);

    connect(formatAction, &QAction::triggered, graphDialog, &GraphDialog::show);
    connect(rescaleAction, &QAction::triggered, this, &Graph::rescale);

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QtCharts::QChartView::customContextMenuRequested, this, &Graph::showContextMenu);
}

void Graph::createAxises() {
    axisX = new QtCharts::QValueAxis;
    axisX->setLabelFormat("%d");
    axisX->setTitleText("Wavelength, A");
    axisX->setTickCount(5);
    axisX->setMin(1);
    axisX->setMax(100);

    axisY = new QtCharts::QValueAxis;
    axisY->setLabelFormat("%g");
    axisY->setTitleText("Intensity, arb. u.");
    axisX->setTickCount(5);
    axisY->setMin(1);
    axisY->setMax(100);

    logAxisY = new QtCharts::QLogValueAxis;
    logAxisY->setLabelFormat("%g");
    logAxisY->setTitleText("Intensity, arb. u.");
    logAxisY->setBase(10);
    logAxisY->setMin(1);
    logAxisY->setMax(100);
}

Graph::~Graph() {

}
