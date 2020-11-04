#ifndef SERIALPORTWORKER_H
#define SERIALPORTWORKER_H

#include <QObject>
#include <QSerialPort>

class SerialPortWorker : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortWorker(QObject *parent = nullptr);
    QList<QString> getListSerialPortName();


signals:


private:
    QString m_serialPortName;
    QList<QSerialPortInfo> m_serialPortList;

};

#endif // SERIALPORTWORKER_H
