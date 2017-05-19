#include <QvMFString.h>

QV_MFIELD_OBJ_SOURCE(QvMFString, QvString, 1);
QV_MFIELD_ASSIGN(QvMFString, QvString, 1);

QvBool
QvMFString::read1Value(QvInput *in, int index)
{
    return in->read(values[index]);
}
