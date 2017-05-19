#ifndef  _QV_MF_ROTATION_
#define  _QV_MF_ROTATION_

#include <QvSubField.h>

class QvOrientation
{
	public:
		QvOrientation() :
			angle(0)
		{ 	
			axis[0] = axis[1] = 0;
			axis[2] = 1;
		};

		float axis[3];
		float angle;
};

class QvMFRotation : public QvMField {
  public:
    QvOrientation *values;
    QV_MFIELD_HEADER(QvMFRotation);
};

#endif /* _QV_MF_ROTATION_ */
