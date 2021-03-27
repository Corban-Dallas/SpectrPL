#include "spectra_storage.h"

SpectraStorage::SpectraStorage(QWidget *parent) : QListWidget(parent) {
    //qRegisterMetaType<QVector<QPointF> >();
    //
    points = new QVector<QPointF>;
    connect(this, &SpectraStorage::itemSelectionChanged,
            this, &SpectraStorage::sendSpectrumToGraph);
}

void SpectraStorage::setRowText(QString text) {
    int index = this->currentRow();
    this->item(index)->setText(text);
}

void SpectraStorage::startSpectrum() {
    qDebug() << "[SpectraStorage] Start spectrum";
    points->clear();
}

void SpectraStorage::addPoint(double x, double y) {
    qDebug() << "[SpectraStorage] Add point";
    points->append(QPointF(x, y));
}

void SpectraStorage::finishSpectrum() {
    qDebug() << "[SpectraStorage] End spectrum";
    if (points->count() == 0) return;

    Spectrum spectrum;
    spectrum.points = *points;
    storage.append(spectrum);

    int count = this->count();
    this->addItem(QString("Not saved %1").arg(count));
    this->setCurrentRow(count);
}

bool SpectraStorage::isAllSaved() {
    //for (auto it = storage.begin(); it != storage.end(); ++it)
        //if (!it->isSaved()) return false;
    for (auto spectrum : storage)
        if (!spectrum.isSaved) return false;
    return true;
}

Spectrum* SpectraStorage::getSpectrum() {
    int index = this->currentRow();
    return &storage[index];
}


void SpectraStorage::sendSpectrumToGraph() {
    int index = this->currentRow();
    QVector<QPointF> p = storage[index].points;
    emit changePlot(p);
    return;
}

SpectraStorage::~SpectraStorage() {

}
