#include <QvSFRotation.h>

QV_SFIELD_SOURCE_BASE(QvSFRotation);

QvBool
QvSFRotation::readValue(QvInput *in)
{
    return (in->read(axis[0]) &&
	    in->read(axis[1]) &&
	    in->read(axis[2]) &&
	    in->read(angle));
}

QvSFRotation& QvSFRotation::operator=( const QvSFRotation& v )
{
    axis[0] = v.axis[0];
	axis[1] = v.axis[1];
	axis[2] = v.axis[2];
	angle = v.angle;

	pumpData();	
	if(getContainer()->GetRenderData())	getContainer()->GetRenderData()->SetDirty(true);
	return *this;
}
