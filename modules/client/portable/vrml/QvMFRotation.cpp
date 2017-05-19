#include <QvMFRotation.h>

QV_MFIELD_OBJ_SOURCE(QvMFRotation, QvOrientation, 1);
QV_MFIELD_ASSIGN(QvMFRotation, QvOrientation, 1);

QvBool
QvMFRotation::read1Value(QvInput *in, int index)
{
	// Reading not implemented yet
	return   (in->read(values[index].axis[0]) &&
	    in->read(values[index].axis[1]) &&
	    in->read(values[index].axis[2]) &&
	    in->read(values[index].angle));

    return FALSE;
}
