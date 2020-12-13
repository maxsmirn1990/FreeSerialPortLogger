#include "bufferworker.h"

BufferWorker::BufferWorker(QObject *parent) : QObject(parent)
{
    m_buf.open(QBuffer::ReadWrite);
}

BufferWorker::~BufferWorker()
{
    m_buf.close();
}


