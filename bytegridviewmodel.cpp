#include "bytegridviewmodel.h"
#include <serialportworker.h>
#include <QFile>
#include <QDebug>

ByteGridViewModel::ByteGridViewModel(QObject *parent)
    : QAbstractListModel(parent)
{

    connect(portWorker::Instance(),
            SIGNAL(serialDataChanged(QByteArray)),
            this,
            SLOT (addReadingByte(QByteArray)));


    qDebug()<<"Construktor316354164 otrabotal";
}

int ByteGridViewModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()){
        return 0;
    }

    return m_ByteArr.size(); //test
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
    bt.append(m_ByteArr.at(rowIndex));
    s = bt.toHex();
    s.insert(0,"0x");

    return QVariant::fromValue<QString>(s);

}

void ByteGridViewModel::saveModelData(const QString url)
{
    QString winUrl;
    for(int i=8;i<url.length();i++){
        if(url.at(i)=="/"){
            winUrl.append("\\");
            winUrl.append("\\");
        }else{
            winUrl.append(url.at(i));
        }
    }
    QFile file(winUrl);
    if (file.open(QIODevice::OpenModeFlag::Append)){
        file.write(m_ByteArr);
        file.close();
    }else{
        qDebug()<<"Dont open file "<<winUrl;
    }

}

void ByteGridViewModel::addReadingByte(const QByteArray bytes){

    qDebug()<<"Catch signal whit array: "<<bytes.toHex();//"Сигнал о готовности к выводу пойман";

    int a = m_ByteArr.size();
    int b = bytes.size();
    beginInsertRows(QModelIndex(),a,(a+b)-1);
    m_ByteArr.append(bytes);
    endInsertRows();
}
