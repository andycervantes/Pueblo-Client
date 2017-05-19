#ifndef  _QV_ORIENTATIONINTERPOLATOR_
#define  _QV_ORIENTATIONINTERPOLATOR_

#include <QvSubNode.h>
#include <QvInterpolator.h>
#include <QvSFRotation.h>
#include <QvMFRotation.h>

class QvOrientationInterpolator : public QvInterpolator {

    QV_NODE_HEADER(QvOrientationInterpolator);

	public:

		virtual QvBool    set_fraction(const void *pvFrac);

		bool 	GetValue(QvSFRotation &rotation) {rotation = value; return true;};
		bool	SetValues(QvMFRotation &vals);
		bool	SetValues(int count, QvSFRotation vals[]);

	protected:

		QvSFRotation value;
		QvMFRotation values;

};

#endif /* _QV_ORIENTATIONINTERPOLATOR_ */
