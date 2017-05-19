#include <QvMFTime.h>

QV_MFIELD_SOURCE(QvMFTime, double, 1);

QvBool
QvMFTime::read1Value(QvInput *in, int index)
{
    return in->read(values[index]);
}
