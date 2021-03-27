#include "spectrum.h"
#include <QDebug>

Spectrum::Spectrum() { }

void Spectrum::setPoints(QVector<QPointF> *points) {
    _points = *points;
}

QVector<QPointF> Spectrum::points() {
    return _points;
}

void Spectrum::setSaved(bool s) {
    saved = s;
}

bool Spectrum::isSaved() {
    return saved;
}
