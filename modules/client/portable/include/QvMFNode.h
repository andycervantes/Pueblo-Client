#ifndef  _QV_MF_NODE_
#define  _QV_MF_NODE_

#include <QvSubField.h>

class QvNode;

class QvMFNode : public QvMField {
  public:
    QvNode **values;
    QV_MFIELD_HEADER(QvMFNode);
};

#endif /* _QV_MF_NODE_ */
