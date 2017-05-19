#include <QvSFVec3f.h>

QV_SFIELD_SOURCE_BASE(QvSFVec3f);
QV_SFIELD_ASSIGN(QvSFVec3f);

QvBool
QvSFVec3f::readValue(QvInput *in)
{
    return (in->read(value[0]) &&
	    in->read(value[1]) &&
	    in->read(value[2]));
}
