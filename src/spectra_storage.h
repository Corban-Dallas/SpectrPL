#ifndef SPECTRA_STORAGE_H
#define SPECTRA_STORAGE_H

#include <QObject>
#include <QListWidget>
#include <QDebug>

// Single spectrum container
struct Spectrum {
    QVector<QPointF> points;
    bool isSaved = false;
};

// Widget which stores multiple spectra and interacts with graph
class SpectraStorage : public QListWidget
{
    Q_OBJECT

signals:
    void changePlot(QVector<QPointF>);

public:
    explicit SpectraStorage(QWidget *parent = 0);
    ~SpectraStorage();

    Spectrum* getSpectrum();
    void setRowText(QString text);
    bool isAllSaved();

public slots:
    void startSpectrum();
    void addPoint(double x, double y);
    void finishSpectrum();

private:
    QVector<Spectrum> storage;
    QVector<QPointF> *points;

private slots:
    void sendSpectrumToGraph();
};



#endif // SPECTRA_STORAGE_H
