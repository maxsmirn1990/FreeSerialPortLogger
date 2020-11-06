#ifndef SERIALPORTWORKER_H
#define SERIALPORTWORKER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "Singleton.h"


class SerialPortWorker : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortWorker(QObject *parent = nullptr);
    QList<QString> getListSerialPortName();
    void setBaud(int baud);
    void setPortName(QString name);
    void openPort(QString portName);


signals:


private:
    QSerialPort::DataBits m_dataBits;
    QSerialPort::FlowControl m_flowControl;
    QSerialPort::Parity m_parity;
    QSerialPort::StopBits m_stopBits;
    int m_baudRate;

    QString m_serialPortName;
    QSerialPort m_serialPort;
    QList<QSerialPortInfo> m_listInfo;
    QList<QString> m_portNameList;

};

typedef  Singleton<SerialPortWorker> portWorker;

#endif // SERIALPORTWORKER_H
