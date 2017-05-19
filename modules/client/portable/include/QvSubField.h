#ifndef  _QV_SUB_FIELD_
#define  _QV_SUB_FIELD_

#include <QvField.h>
#include <QvInput.h>

/////////////////////////////////////////////////////////////////////////////

#define QV_SFIELD_HEADER(className)					      \
  public:								      \
    className();							      \
    virtual ~className();						      \
    virtual QvBool readValue(QvInput *in);	\
    virtual QvBool	setValue(const void *in);			\
	virtual void propagate(QvField *dest);		\
	className& operator=( const className& v );



/////////////////////////////////////////////////////////////////////////////

#define QV_MFIELD_HEADER(className)					      \
  public:								      \
    className();							      \
    virtual ~className();						      \
    virtual QvBool	read1Value(QvInput *in, int index);		      \
    void		allocValues(int newNum);				  \
    virtual QvBool	setValues(const void *in, int index, int count);			\
    virtual QvBool	set1Value(const void *in, int index);			\
	virtual void propagate(QvField *dest);		\
	className& operator=( const className& v );


/////////////////////////////////////////////////////////////////////////////

#define QV_SFIELD_SOURCE_BASE(className)					      \
									      \
className::className()							      \
{									      \
 	setType(type##className);	\
}									      \
className::~className()							      \
{									      \
}											\
void className::propagate(QvField *dest)							\
{											\
	*((className*)dest) = *this;	\
}

/////////////////////////////////////////////////////////////////////////////

#define QV_MFIELD_SOURCE_BASE(className, valueType, numValues)		      \
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
	free((char *) values);						      \
}									      \
									      \
void									      \
className::allocValues(int newNum)					      \
{									      \
    if (values == NULL) {						      \
	if (newNum > 0)							      \
	    values = (valueType *)					      \
		malloc(numValues * sizeof(valueType) * newNum);		      \
    }									      \
    else {								      \
	if (newNum > 0)							      \
	    values = (valueType *)					      \
		realloc(values, numValues * sizeof(valueType) * newNum);      \
	else {								      \
	    free((char *) values);					      \
	    values = NULL;						      \
	}								      \
    }									      \
    num = maxNum = newNum;						      \
}											\
void className::propagate(QvField *dest)							\
{											\
	/* not implemented */	\
}

////////////////// Source for object-containers - need to new so we init the member values
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

		   

#define QV_MFIELD_ASSIGN(className, valueType, numValues)		      \
className& className::operator=( const className& v )	\
{											\
	/* not implemented */	\
	return *this;			\
}

#define QV_SFIELD_ASSIGN(className)					      \
className& className::operator=( const className& v )	\
{											\
	setValue(&v.value);	\
	return *this;			\
}

#define QV_SFIELD_ASSIGN_ARRAY(className, numValues)					      \
className& className::operator=( const className& v )	\
{											\
	for(int i=0;i<(numValues);i++) value[i] = v.value[i];	\
	return *this;			\
}

#define QV_SFIELD_ASSIGN_COPY(className)					      \
className& className::operator=( const className& v )	\
{											\
	memcpy(&value, &v.value, sizeof(value));	\
	return *this;			\
}

#define QV_MFIELD_SOURCE(className, valueType, numValues)		      \
QV_MFIELD_SOURCE_BASE(className, valueType, numValues);QV_MFIELD_ASSIGN(className, valueType, numValues)	\

//

#define QV_SFIELD_SOURCE(className)					      \
QV_SFIELD_SOURCE_BASE(className); QV_SFIELD_ASSIGN(className)

#endif /* _QV_SUB_FIELD_ */
