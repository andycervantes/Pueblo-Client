#include <QvSFTime.h>

QV_SFIELD_SOURCE(QvSFTime);

QvBool
QvSFTime::readValue(QvInput *in)
{
    return in->read(value);
}
