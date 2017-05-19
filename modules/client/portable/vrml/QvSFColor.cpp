#include <QvSFColor.h>

QV_SFIELD_SOURCE_BASE(QvSFColor);
QV_SFIELD_ASSIGN_ARRAY(QvSFColor, 3);

QvBool
QvSFColor::readValue(QvInput *in)
{
    return (in->read(value[0]) &&
	    in->read(value[1]) &&
	    in->read(value[2]));
}

