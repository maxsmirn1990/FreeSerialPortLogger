#ifndef SPEEDLISTMODEL_H
#define SPEEDLISTMODEL_H

#include <QAbstractListModel>
#include <QSerialPort>
#include "serialportworker.h"

class SpeedListModel : public QAbstractListModel
{
    Q_OBJECT

       struct baudRate{
       int baud;
       QString description;

    };

public:
    explicit SpeedListModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE void setSpeed(int index);

private:

   QList<baudRate> speedlist;





};

#endif // SPEEDLISTMODEL_H
