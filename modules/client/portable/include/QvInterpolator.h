#ifndef  _QV_INTERPOLATOR_
#define  _QV_INTERPOLATOR_

#include <QvSubNode.h>
#include <QvSFFloat.h>
#include <QvMFFloat.h>

class QvInterpolator : public QvNode {

		QV_NODE_HEADER(QvInterpolator);

	public:

		virtual bool    set_fraction(float frac);


		float		GetKey(int index) const;
		int			GetNumKeys() const;
		float		SetKeys(int count, float *keys);
		float		SetKeys(QvMFFloat &keys);

	protected:

		QvMFFloat keys;
		QvSFFloat fraction;

	protected:
		bool lookup(float frac, int &low, int &high);

};

#endif /* _QV_INTERPOLATOR_ */
