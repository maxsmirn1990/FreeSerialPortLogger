#include "bytegridviewmodel.h"
#include <QDebug>

ByteGridViewModel::ByteGridViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
    for(int i=0;i<100;i++){
    m_testByteArr.insert(i, 0x00+i);
    }
    emit dataChanged(createIndex(0,0), createIndex(100,0));
    qDebug()<<"Construktor316354164 otrabotal";
}

int ByteGridViewModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()){
        return 0;
    }

    return m_testByteArr.size(); //test
}

QVariant ByteGridViewModel::data(const QModelIndex &index,
                                 int role) const
{
    if (!index.isValid())
        return QVariant("NULL");
    if (!(role==Qt::DisplayRole)){
        role=Qt::DisplayRole;
    }
    if(!index.isValid()||role!=Qt::DisplayRole){
            return QVariant("NULL");
    }
    const int rowIndex(index.row());
    QString s;
    QByteArray bt;
    bt.append(m_testByteArr.at(rowIndex));
    s = bt.toHex();
    s.insert(0,"0x");

    return QVariant::fromValue<QString>(s);

}
