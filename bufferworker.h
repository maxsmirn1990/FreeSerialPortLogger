#ifndef BUFFERWORKER_H
#define BUFFERWORKER_H

#include <QObject>
#include <QBuffer>

class BufferWorker : public QObject
{
    Q_OBJECT
public:
    explicit BufferWorker(QObject *parent = nullptr);


signals:
private:
    QBuffer openBuffer();


    QBuffer m_buf;
};

#endif // BUFFERWORKER_H
