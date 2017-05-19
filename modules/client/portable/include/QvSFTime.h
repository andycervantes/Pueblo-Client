#ifndef  _QV_SF_TIME_
#define  _QV_SF_TIME_

#include <QvSubField.h>

class QvSFTime : public QvSField {
  public:
    double value;
    QV_SFIELD_HEADER(QvSFTime);

	operator double() const { return value; }

};

#endif /* _QV_SF_TIME_ */
