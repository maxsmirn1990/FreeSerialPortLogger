#include "serialportworker.h"
#include "reader.h"

Reader::Reader(QObject *parent) : QObject(parent)
{
    connect(portWorker::Instance(),
            SIGNAL(serialDataChanged(QByteArray)),
            this,
            SLOT (setReadData(QByteArray)));
}

QByteArray Reader::readData()
{
    return m_readData;
}



void Reader::setReadData(QByteArray readData)
{
//    if (m_readData == readData)
//        return;

    m_readData.append(readData);
    m_readData.append("\n\r");
    m_readData.toHex(' ');
    emit readDataChanged();
}
