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
    static QList<QString> getListSerialPortName();
    static void setBaud(int baud);


signals:


private:
   static QSerialPort m_serialPort;
   static QList<QSerialPortInfo> m_listInfo;
   static QList<QString> m_portNameList;

};

#endif // SERIALPORTWORKER_H
