#ifndef  _QV_SPIN_
#define  _QV_SPIN_

#include <QvSFString.h>
#include <QvSFFloat.h>
#include <QvSFEnum.h>
#include <QvSubNode.h>

#if defined(LOCAL)
#undef LOCAL
#endif
#if defined(GLOBAL)
#undef GLOBAL
#endif

class QvSpin : public QvNode {

	QV_NODE_HEADER(QvSpin);

	public:
	// Fields
		QvSFString	objectname;	
		QvSFFloat	xangle;
		QvSFFloat	yangle;
		QvSFFloat	zangle;
		QvSFEnum	axes;

		QvNode *m_pObject;

		enum Axes {		
			LOCAL	= 0x01,	
			GLOBAL	= 0x02		
		};              

	protected:
		virtual QvBool	readInstance(QvInput *in);
};

#endif /* _QV_SPIN_ */
