#ifndef BYTEGRIDVIEWMODEL_H
#define BYTEGRIDVIEWMODEL_H

#include <QAbstractListModel>

class ByteGridViewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ByteGridViewModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QByteArray m_testByteArr;
    QString m_ByteString="NULL";

};

#endif // BYTEGRIDVIEWMODEL_H
