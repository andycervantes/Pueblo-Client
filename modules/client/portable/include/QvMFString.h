#ifndef  _QV_MF_STRING_
#define  _QV_MF_STRING_

#include <QvSubField.h>

#if 1
#define QV_MFIELD_OBJ_SOURCE(className, valueType, numValues)		      \
									      \
className::className()							      \
{									      \
 	setType(type##className);	\
    values = NULL;							      \
    /* Make room for 1 value to start */				      \
    allocValues(1);							      \
}									      \
									      \
className::~className()							      \
{									      \
    if (values != NULL)							      \
	delete [] values;						      \
}									      \
									      \
void									      \
className::allocValues(int newNum)					      \
{									      \
    if (values == NULL) {						      \
		if (newNum > 0)							      \
		    values = (valueType *)					      \
				new valueType[numValues * newNum];		      \
    }									      \
    else {								      \
		if (newNum > 0)							\
		{								      \
		    valueType *newValues;			\
		    newValues = (valueType *)					      \
				new valueType[numValues * newNum];		      \
			for(int j=0; j<num; j++) newValues[j] = values[j];	\
			delete [] values;	\
			values = newValues;		\
		}	\
		else {								      \
		    free((char *) values);					      \
		    values = NULL;						      \
		}								      \
    }									      \
    num = maxNum = newNum;						      \
}	\
void className::propagate(QvField *dest)							\
{											\
	*((className*)dest) = *this;	\
}
#endif


class QvMFString : public QvMField {
  public:
    QvString *values;
    QV_MFIELD_HEADER(QvMFString);
};

#endif /* _QV_SF_STRING_ */
