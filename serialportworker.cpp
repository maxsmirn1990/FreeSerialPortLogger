#include <QSerialPort>
#include <QSerialPortInfo>
#include "serialportworker.h"
#include <QDebug>

SerialPortWorker::SerialPortWorker(QObject *parent) : QObject(parent)
{
    m_serialPortList = QSerialPortInfo::availablePorts();
    m_serialPortName = m_serialPortList.at(0).portName();

    //DEBUG
    qDebug() << QString("Прошла инициализация");
    qDebug() << QString("Список СОМ портов:");
    for(int i=0;i<m_serialPortList.size();i++){
    qDebug() << m_serialPortList.at(i).portName() \
                + QString("  ") \
                + m_serialPortList.at(i).description();
    }
    qDebug() << QString("Имя выбранного СОМ порта ") \
                + m_serialPortName;
}

QList<QString> SerialPortWorker::getListSerialPortName()
{
     QList<QString> tempList;
     tempList.clear();
     m_serialPortList.clear();
     m_serialPortList = QSerialPortInfo::availablePorts();

     // Проверка на наличие СОМ портов
     if(m_serialPortList.isEmpty()){
         tempList.append(QString("Нет СОМ портов"));
         return tempList;
     }

    for(int i=0;i<m_serialPortList.size();i++){
        tempList.append(m_serialPortList.at(i).portName());
    }
    return tempList;
}

