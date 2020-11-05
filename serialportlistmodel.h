#ifndef SERIALPORTLISTMODEL_H
#define SERIALPORTLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <serialportworker.h>

class SerialPortListModel : public QAbstractListModel
{
    Q_OBJECT

public:

    explicit SerialPortListModel(QObject *parent = nullptr,\
                                SerialPortWorker* portWorker=nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE void refresh();
    Q_INVOKABLE void setPort(int index);

private:
    int m_rowCount;
    QList<QString> m_list;
    SerialPortWorker* m_portWorker;
};

#endif // SERIALPORTLISTMODEL_H
