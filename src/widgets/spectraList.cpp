#include "spectraList.h"

SpectraList::SpectraList(QWidget *parent) : QListWidget(parent) {
    //qRegisterMetaType<QVector<QPointF> >();
    //
    points = new QVector<QPointF>;
    connect(this, &SpectraList::itemSelectionChanged,
            this, &SpectraList::sendSpectrumToGraph);
}

void SpectraList::setRowText(QString text) {
    int index = this->currentRow();
    this->item(index)->setText(text);
}

void SpectraList::startSpectrum() {
    qDebug() << "[SpectraStorage] Start spectrum";
    points->clear();
}

void SpectraList::addPoint(double x, double y) {
    qDebug() << "[SpectraStorage] Add point";
    points->append(QPointF(x, y));
}

void SpectraList::finishSpectrum() {
    qDebug() << "[SpectraStorage] End spectrum";
    if (points->count() == 0) return;

    Spectrum spectrum;
    spectrum.points = *points;
    storage.append(spectrum);

    int count = this->count();
    this->addItem(QString("Not saved %1").arg(count));
    this->setCurrentRow(count);
}

bool SpectraList::isAllSaved() {
    //for (auto it = storage.begin(); it != storage.end(); ++it)
        //if (!it->isSaved()) return false;
    for (auto spectrum : storage)
        if (!spectrum.isSaved) return false;
    return true;
}

Spectrum* SpectraList::getSpectrum() {
    int index = this->currentRow();
    return &storage[index];
}


void SpectraList::sendSpectrumToGraph() {
    int index = this->currentRow();
    QVector<QPointF> p = storage[index].points;
    emit changePlot(p);
    return;
}

SpectraList::~SpectraList() {

}
