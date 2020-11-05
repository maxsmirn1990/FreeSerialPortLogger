#include <QAbstractListModel>
#include "serialportlistmodel.h"
#include <serialportworker.h>



SerialPortListModel::SerialPortListModel(QObject *parent, SerialPortWorker *portWorker)
    : QAbstractListModel(parent)
{

   m_portWorker = portWorker;
   m_list.clear();
   m_list.append(QString("Нажмите кнопку обновить"));
   m_rowCount = m_list.size();

}

int SerialPortListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return m_rowCount;

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
   m_list = m_portWorker->getListSerialPortName();
   m_rowCount = m_list.size();
   emit dataChanged(createIndex(0,0), createIndex(m_list.size(),0));

}
