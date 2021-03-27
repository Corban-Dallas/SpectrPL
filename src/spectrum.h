#ifndef SPECTRUM_H
#define SPECTRUM_H

#include <QObject>
#include <QVector>
#include <QPointF>

class Spectrum {
public:
    Spectrum();
    void setPoints(QVector<QPointF> *points);
    void setSaved(bool);

    QVector<QPointF> points();
    bool isSaved();

private:
    QVector<QPointF> _points;
    bool saved = false;
};

class DataVault
{
public:
    DataVault();
    void addSpectrum(QVector<QPointF> points);
    Spectrum* getSpectrum(int index);
    int count();
    bool isAllSaved();

private:
    QVector<Spectrum> storage;
};

#endif // SPECTRUM_H
