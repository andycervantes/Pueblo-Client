#include <QvSFVec2f.h>

QV_SFIELD_SOURCE_BASE(QvSFVec2f);
QV_SFIELD_ASSIGN_ARRAY(QvSFVec2f, 2);

QvBool
QvSFVec2f::readValue(QvInput *in)
{
    return (in->read(value[0]) &&
	    in->read(value[1]));
}
