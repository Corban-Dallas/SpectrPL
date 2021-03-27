#include <QDir>

#include "log.h"

Log::Log(QString filename, QObject *parent) : QObject(parent)
{
    QDir dir;
    QString filepath = dir.absolutePath() + QString("//") + filename;
    file = new QFile(filepath);
    if (file->open(QIODevice::ReadWrite)) {
        logStream = new QTextStream(file);
    }
}

void Log::write(QString msg) {
    if (file->isOpen()) *logStream << msg << endl;
}
