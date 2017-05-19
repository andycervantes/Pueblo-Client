#ifndef  _QV_MF_TIME_
#define  _QV_MF_TIME_

#include <QvSubField.h>

class QvMFTime : public QvMField {
  public:
    double *values;
    QV_MFIELD_HEADER(QvMFTime);
};

#endif /* _QV_MF_TIME_ */
