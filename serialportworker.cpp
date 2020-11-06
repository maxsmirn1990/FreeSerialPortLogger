#include <QSerialPort>
#include <QSerialPortInfo>
#include "serialportworker.h"
#include <QDebug>

SerialPortWorker::SerialPortWorker(QObject *parent) : QObject(parent)
{
   int m_dataBits = QSerialPort::Data8;
   int m_flowControl = QSerialPort::NoFlowControl;
   int m_parity = QSerialPort::NoParity;
   int m_stopBits = QSerialPort::OneStop;
}

QList<QString> SerialPortWorker::getListSerialPortName()
{
    if (!m_listInfo.isEmpty()){
        m_listInfo.clear();
    }

    m_listInfo = QSerialPortInfo::availablePorts();

    // Проверка на наличие СОМ портов
     if(m_listInfo.isEmpty()){
         m_portNameList.append(QString("Нет доступных СОМ портов"));
         return m_portNameList;
     }

    for(int i=0;i<m_listInfo.size();i++){
        m_portNameList.append(m_listInfo.at(i).portName());
    }

   return m_portNameList;
}

void SerialPortWorker::setBaud(int baud)
{
    m_baudRate = baud;
    qDebug() << QString("установли BaudRate = ") << m_serialPort.baudRate();
}

void SerialPortWorker::setPortName(QString name)
{
    m_serialPortName = name;
    qDebug() << QString("установли portName = ") << m_serialPort.portName();
}

void SerialPortWorker::openPort(QString portName)
{
    m_serialPortName = portName;
    m_serialPort.setPortName(m_serialPortName);
    m_serialPort.setBaudRate(m_baudRate);
    m_serialPort.setDataBits(m_dataBits);
    m_serialPort.setFlowControl(m_flowControl);
    m_serialPort.setParity(m_parity);
    m_serialPort.setStopBits(m_stopBits);

}




