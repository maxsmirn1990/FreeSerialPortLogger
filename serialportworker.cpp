#include <QSerialPort>
#include <QSerialPortInfo>
#include "serialportworker.h"
#include <QDebug>

SerialPortWorker::SerialPortWorker(QObject *parent) : QObject(parent)
{

    m_listInfo = QSerialPortInfo::availablePorts();
    m_portNameList.append(m_listInfo.at(0).portName());
    m_serialPort.setPortName(m_listInfo.at(0).portName());
    m_serialPort.setBaudRate(QSerialPort::Baud9600);

    //DEBUG
    qDebug() << QString("Прошла инициализация");
    qDebug() << QString("Список СОМ портов:");
    for(int i=0;i<m_portNameList.size();i++){
    qDebug() << m_portNameList.at(i);
   }
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

    //-------------------------------------------------------
    //Тест

    m_portNameList.append(QString("Тестовый СОМ порт"));

    //-------------------------------------------------------

    //DEBUG
    qDebug() << QString("Список СОМ портов:");
    for(int i=0;i<m_portNameList.size();i++){
    qDebug() << m_portNameList.at(i);
   }

    return m_portNameList;

}

void SerialPortWorker::setBaud(int baud)
{
    m_serialPort.setBaudRate(baud);
    qDebug() << QString("установли BaudRate = ") << m_serialPort.baudRate();
    qDebug() << QString("установли portName = ") << m_serialPort.portName();
}

void SerialPortWorker::setPortName(QString name)
{
    m_serialPort.setPortName(name);
    qDebug() << QString("установли BaudRate = ") << m_serialPort.baudRate();
    qDebug() << QString("установли portName = ") << m_serialPort.portName();
}




