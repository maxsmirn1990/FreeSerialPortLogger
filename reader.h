#ifndef READER_H
#define READER_H

#include <QObject>

class Reader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QByteArray m_readData READ readData WRITE setReadData NOTIFY readDataChanged);
public:
    explicit Reader(QObject *parent = nullptr);
    QByteArray readData();


public slots:
    void setReadData(QByteArray readData);

signals:
    void readDataChanged();

private:
    QByteArray m_readData;

};

#endif // READER_H
