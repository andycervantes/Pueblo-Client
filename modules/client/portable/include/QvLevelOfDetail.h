#ifndef  _QV_LEVEL_OF_DETAIL_
#define  _QV_LEVEL_OF_DETAIL_

#include <QvMFFloat.h>
#include <QvSFVec3f.h>
#include <QvGroup.h>

class QvLOD : public QvGroup {

    QV_NODE_HEADER(QvLOD);

  public:
    // Fields
    QvMFFloat		range;	// Ranges to use for comparison
    QvSFVec3f		center;	// Center of subgraph to use for ranging
};

#endif /* _QV_LEVEL_OF_DETAIL_ */
