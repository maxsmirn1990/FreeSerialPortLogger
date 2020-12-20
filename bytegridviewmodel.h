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
    Q_INVOKABLE void saveModelData(const QString url);


private slots:
    void addReadingByte(const QByteArray bytes);

private:
    QByteArray m_ByteArr;

};

#endif // BYTEGRIDVIEWMODEL_H
