#include <QAbstractListModel>
#include "serialportlistmodel.h"
#include <serialportworker.h>



SerialPortListModel::SerialPortListModel(QObject *parent)
    : QAbstractListModel(parent)
{

   m_list.clear();
   m_list = portWorker::Instance()->getListSerialPortName();
   //m_list.append(QString("Нажмите кнопку обновить"));
   m_rowCount = m_list.size();

}

int SerialPortListModel::rowCount(const QModelIndex &parent) const
{

    if (parent.isValid())
        return 0;
    int s = portWorker::Instance()->numberOfPort();
    return s;

}

QVariant SerialPortListModel::data(const QModelIndex &index, int role) const
{
    role =0;
    if(!index.isValid()||role!=Qt::DisplayRole){
            return QVariant("Не присвоено значений");
    }
    const int rowIndex(index.row());
    return QVariant::fromValue<QString>(m_list.at(rowIndex));

}

void SerialPortListModel::refresh()
{
   m_list.clear();
   m_list = portWorker::Instance()->getListSerialPortName();
   m_rowCount = m_list.size();
   emit dataChanged(createIndex(0,0), createIndex(m_list.size(),0));
}

void SerialPortListModel::setPort(int index)
{

    portWorker::Instance()->setPortName(m_list.at(index));
}

void SerialPortListModel::startRead(int index)
{
    portWorker::Instance()->openPort(m_list.at(index));

}

void SerialPortListModel::closePort()
{
    portWorker::Instance()->closePort();
}


