#include "speedlistmodel.h"
#include <QSerialPort>
#include "serialportworker.h"

SpeedListModel::SpeedListModel(QObject *parent)
    : QAbstractListModel(parent)
{

    speedlist.append({QSerialPort::Baud1200, "1200 baud"});
    speedlist.append({QSerialPort::Baud2400, "2400 baud"});
    speedlist.append({QSerialPort::Baud4800, "4800 baud"});
    speedlist.append({QSerialPort::Baud9600, "9600 baud"});
    speedlist.append({QSerialPort::Baud19200, "19200 baud"});
    speedlist.append({QSerialPort::Baud38400, "38400 baud"});
    speedlist.append({QSerialPort::Baud57600, "57600 baud"});
    speedlist.append({QSerialPort::Baud115200, "115200 baud"});

}



int SpeedListModel::rowCount(const QModelIndex &parent) const
{

    if (parent.isValid())
        return 0;

    return speedlist.size();
}

QVariant SpeedListModel::data(const QModelIndex &index, int role) const
{
    role =0;
    if (!index.isValid())
        return QVariant();

    const int rowIndex(index.row());
    return QVariant::fromValue<QString>(speedlist.at(rowIndex).description);
}

void SpeedListModel::setSpeed(int index)
{
        //setBaud(speedlist.at(index).baud);
    portWorker::Instance()->setBaud(speedlist.at(index).baud);

}
