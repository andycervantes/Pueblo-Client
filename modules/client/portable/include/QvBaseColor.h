#ifndef  _QV_BASECOLOR_
#define  _QV_BASECOLOR_

#include <QvMFColor.h>
#include <QvMFFloat.h>
#include <QvSubNode.h>

class QvBaseColor : public QvNode {

    QV_NODE_HEADER(QvBaseColor);

  public:
    // Fields
    QvMFColor       rgb;   // base color
};

#endif /* _QV_BASECOLOR_ */
