#include "serialportworker.h"
#include "reader.h"

Reader::Reader(QObject *parent) : QObject(parent)
{
    connect(portWorker::Instance(),
            SIGNAL(serialDataChanged(QString)),
            this,
            SLOT (setReadData(QString)));
}

QString Reader::readData()
{
   return m_readData;
}



void Reader::setReadData(QString readData)
{
    m_readData.clear();
    m_readData.append(readData);
    m_readData = m_readData.toUpper();
    m_readData.insert(0, "0x");
    emit readDataChanged();
}
