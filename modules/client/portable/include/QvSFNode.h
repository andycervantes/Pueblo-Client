#ifndef  _QV_SF_NODE_
#define  _QV_SF_NODE_

#include <QvSubField.h>

class QvNode;

class QvSFNode : public QvSField {
  public:
    QvNode * value;
    QV_SFIELD_HEADER(QvSFNode);
};

#endif /* _QV_SF_NODE_ */
