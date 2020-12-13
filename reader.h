#ifndef READER_H
#define READER_H

#include <QObject>

class Reader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString m_readData READ readData WRITE setReadData NOTIFY readDataChanged);
public:
    explicit Reader(QObject *parent = nullptr);
    QString readData();


public slots:
    void setReadData(QString readData);

signals:
    void readDataChanged();

private:
    QString m_readData="";

};

#endif // READER_H
