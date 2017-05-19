#ifndef  _QV_POSITIONINTERPOLATOR_
#define  _QV_POSITIONINTERPOLATOR_

#include <QvSubNode.h>
#include <QvInterpolator.h>
#include <QvSFVec3f.h>
#include <QvMFVec3f.h>

class QvPositionInterpolator : public QvInterpolator {

    QV_NODE_HEADER(QvPositionInterpolator);

	public:

		virtual QvBool    set_fraction(const void *pvFrac);

		//bool 	GetValue(QvSFVec3f &vec) {vec = value; return true;};
		//bool	SetValues(QvMFRotation &vals);
		//bool	SetValues(int count, QvSFRotation vals[]);

	protected:

		QvSFVec3f value;
		QvMFVec3f values;

};

#endif /* _QV_POSITIONINTERPOLATOR_ */
