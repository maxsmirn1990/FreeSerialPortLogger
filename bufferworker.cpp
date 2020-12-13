#include "bufferworker.h"

BufferWorker::BufferWorker(QObject *parent) : QObject(parent)
{

}

QBuffer BufferWorker::openBuffer()
{
    m_buf.open(QBuffer::ReadWrite);
}


