#ifndef BUFFERWORKER_H
#define BUFFERWORKER_H

#include <QObject>

class BufferWorker : public QObject
{
    Q_OBJECT
public:
    explicit BufferWorker(QObject *parent = nullptr);

signals:

};

#endif // BUFFERWORKER_H
