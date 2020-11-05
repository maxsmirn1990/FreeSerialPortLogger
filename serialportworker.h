#ifndef SERIALPORTWORKER_H
#define SERIALPORTWORKER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialPortWorker : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortWorker(QObject *parent = nullptr);
    QList<QString> getListSerialPortName();
    void setBaud(int baud);
    void setPortName(QString name);


signals:


private:
    QSerialPort m_serialPort;
    QList<QSerialPortInfo> m_listInfo;
    QList<QString> m_portNameList;

};

#endif // SERIALPORTWORKER_H
