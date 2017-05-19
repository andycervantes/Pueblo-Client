#ifndef  _QV_BACKGROUND_
#define  _QV_BACKGROUND_

#include <QvMFColor.h>
#include <QvMFFloat.h>
#include <QvMFString.h>
#include <QvSubNode.h>

// This is a VRML 2.0 node that we support for 1.0 also
class QvBackground : public QvNode {

    QV_NODE_HEADER(QvBackground);

  public:
    // Fields
    QvMFColor		groundColor;
    QvMFColor		skyColor;	
    QvMFFloat		groundRange;
    QvMFFloat		skyRange;	
    QvMFString		panorama;	
};

#endif /* _QV_BACKGROUND_ */
