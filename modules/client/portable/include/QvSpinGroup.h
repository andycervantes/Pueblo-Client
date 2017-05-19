#ifndef  _QV_SPINGROUP_
#define  _QV_SPINGROUP_

#include <QvSFBool.h>
#include <QvSFRotation.h>
#include <QvGroup.h>

#include <QvSFBitMask.h>

class QvSpinGroup : public QvGroup {

    QV_NODE_HEADER(QvSpinGroup);

  public:
    // Fields
    QvSFBool local;
	QvSFRotation	rotation;
};

#endif /* _QV_SPINGROUP_ */
