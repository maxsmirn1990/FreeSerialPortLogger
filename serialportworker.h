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
    Q_PROPERTY(QByteArray serialData READ serialData WRITE setSerialData NOTIFY serialDataChanged);
    explicit SerialPortWorker(QObject *parent = nullptr);
    ~SerialPortWorker();
    QList<QString> getListSerialPortName();
    void setBaud(int baud);
    void setPortName(QString name);
    void openPort(QString portName);
    int numberOfPort();
    void closePort();


    QByteArray serialData() const;
    void setSerialData(QByteArray serialData);

signals:
    void serialDataChanged(QByteArray serialData);

private slots:
    void serialRecive();

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

    //Переменные, которые пробрасываются в QML
    QByteArray m_serialData;

};

typedef  Singleton<SerialPortWorker> portWorker;

#endif // SERIALPORTWORKER_H
