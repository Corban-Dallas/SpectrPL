#ifndef LOG_H
#define LOG_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class Log : public QObject
{
    Q_OBJECT
public:
    explicit Log(QString filename, QObject *parent = 0);

signals:

public slots:
    void write(QString);

private:
    QFile *file;
    QTextStream *logStream;


};

#endif // LOG_H
