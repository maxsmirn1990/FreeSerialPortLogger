#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include "serialportworker.h"
#include <QDebug>

SerialPortWorker::SerialPortWorker(QObject *parent) : QThread(parent = nullptr)
{
   connect(&m_serialPort, SIGNAL(readyRead()),
           this, SLOT(serialRecive()));
   m_listInfo = QSerialPortInfo::availablePorts();
   m_serialPortName = m_listInfo.at(0).portName();
   m_dataBits = QSerialPort::Data8;
   m_flowControl = QSerialPort::NoFlowControl;
   m_parity = QSerialPort::NoParity;
   m_stopBits = QSerialPort::OneStop;

   connect(&m_serialPort, SIGNAL(readyRead()), SLOT(serialRecive()));
}

SerialPortWorker::~SerialPortWorker()
{
    m_serialPort.close();
}

QList<QString> SerialPortWorker::getListSerialPortName()
{
    if (!m_listInfo.isEmpty()){
        m_listInfo.clear();
    }
    if (!m_portNameList.isEmpty()){
        m_portNameList.clear();
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
    qDebug() << QString("установли BaudRate = ") << m_baudRate;
}

void SerialPortWorker::setPortName(QString name)
{
    m_serialPortName = name;
    qDebug() << QString("установли portName = ") << m_serialPortName;
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
    m_serialPort.open(QIODevice::ReadOnly);
    if (m_serialPort.isOpen())
    {
        qDebug()<<"SerialPort " + m_serialPort.portName() + " is open";
    }
    //run();

}

int SerialPortWorker::numberOfPort()
{
    return m_listInfo.size();
}

void SerialPortWorker::closePort()
{
    m_serialPort.close();
    m_serialData.clear();
    qDebug()<<"READ IS OVER";
    m_serialData.clear();
    qDebug()<<"SerialPort " + m_serialPort.portName() + " is closed";
}

void SerialPortWorker::serialRecive()
{

   m_serialData.clear();

   m_serialData = m_serialPort.readAll();

      qDebug()<<"QByteArray read:  "<<m_serialData.toHex();
      emit serialDataChanged(m_serialData);
      qDebug()<<"emit signal with byte array";
    }


void SerialPortWorker::run()
{
    qDebug()<<"Run work";
    this->exec();
}




