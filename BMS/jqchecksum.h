#ifndef JQCHECKSUM_H
#define JQCHECKSUM_H
#include <QByteArray>

namespace JQChecksum
{

quint16 crc16ForModbus(const QByteArray &data);

}

#endif
