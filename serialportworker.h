#ifndef SERIALPORTWORKER_H
#define SERIALPORTWORKER_H

#include <QObject>
#include <QThread>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "Singleton.h"


class SerialPortWorker : public QThread
{
    Q_OBJECT


public:

    explicit SerialPortWorker(QObject *parent = nullptr);
    ~SerialPortWorker();
    QList<QString> getListSerialPortName();
    void setBaud(int baud);
    void setPortName(QString name);
    void openPort(QString portName);
    int numberOfPort();
    void closePort();



    void setSerialData(QByteArray m_serialData);

signals:
    void serialDataChanged(QByteArray m_serialData);

private slots:
    void serialRecive();

private:
    QSerialPort::DataBits m_dataBits;
    QSerialPort::FlowControl m_flowControl;
    QSerialPort::Parity m_parity;
    QSerialPort::StopBits m_stopBits;
    int m_baudRate;

    QString m_serialPortName="";
    QSerialPort m_serialPort;
    QList<QSerialPortInfo> m_listInfo;
    QList<QString> m_portNameList;

    QByteArray m_serialData;


    // QThread interface
protected:
    virtual void run() override;
};

typedef  Singleton<SerialPortWorker> portWorker;

#endif // SERIALPORTWORKER_H
