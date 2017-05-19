#include <QvFields.h>
#include <QvSFNode.h>
#include <QvMFNode.h>
#include <QvNode.h>
#include <memory.h>


// This needs to grow num

#define DEFAULT_SET1VALUE(fieldType, type, size)	\
QvBool fieldType::set1Value(const void *in, int index)	\
{	\
	if(index >= num) 	\
		makeRoom(index + 1);	\
    type *valuePtr = ((type *)values) + index * size;	\
	\
	type *pIn = (type *)in;	  \
    for(int i = 0; i < size; i++)	\
    {	\
		valuePtr[i] = pIn[i];	\
    }	\
    return (TRUE);	\
}	\

#define DEFAULT_SETVALUES(fieldType, type, size)	\
QvBool fieldType::setValues(const void *in, int startIndex, int count)	\
{	\
	if(getHandler())   ((getContainer()->*(getHandler()))(in));	\
	else {	\
		if(startIndex + count - 1 >= num) 	\
			makeRoom(startIndex + count);	\
	    type *valuePtr = (type *)values + startIndex * size;	\
		\
		type *pIn = (type *)in;	  \
	    for(int i = 0; i < size * count; i++)	\
	    {	\
			valuePtr[i] = pIn[i];	\
	    }	\
	}	\
	pumpData();		\
	if(getContainer()->GetRenderData())	getContainer()->GetRenderData()->SetDirty(true);	\
    return (TRUE);	\
}	\

#define DEFAULT_SETVALUE(fieldType, type)	\
QvBool fieldType::setValue(const void *in)	\
{	\
	if(getHandler())   ((getContainer()->*(getHandler()))(in));	\
	else value = *((type *)in);	\
	pumpData();		\
	if(getContainer()->GetRenderData())	getContainer()->GetRenderData()->SetDirty(true);	\
    return (TRUE);	\
}	\


#define DEFAULT_SETVALUEARRAY(fieldType, type, size)	\
QvBool fieldType::setValue(const void *in)	\
{	\
	if(getHandler())   ((getContainer()->*(getHandler()))(in));	\
	else {	\
		type *pIn = (type *)in;	  \
	    for(int i = 0; i < size; i++)	\
	    {	\
			value[i] = pIn[i];	\
	    }	\
	}	\
	pumpData();		\
	if(getContainer()->GetRenderData())	getContainer()->GetRenderData()->SetDirty(true);	\
    return (TRUE);	\
}

// TODO SFNode and MFNode must use/release ref counts!!!!

DEFAULT_SET1VALUE(QvMFColor, float, 3);

DEFAULT_SETVALUES(QvMFColor, float, 3);

DEFAULT_SETVALUEARRAY(QvSFColor, float, 3);

DEFAULT_SET1VALUE(QvMFFloat, float, 1);
DEFAULT_SET1VALUE(QvMFLong, long, 1);
DEFAULT_SET1VALUE(QvMFVec2f, float, 2);
DEFAULT_SET1VALUE(QvMFVec3f, float, 3);

DEFAULT_SETVALUES(QvMFFloat, float, 1);
DEFAULT_SETVALUES(QvMFLong, long, 1);
DEFAULT_SETVALUES(QvMFVec2f, float, 2);
DEFAULT_SETVALUES(QvMFVec3f, float, 3);

DEFAULT_SETVALUE(QvSFBitMask, int);
DEFAULT_SETVALUE(QvSFBool, QvBool);
DEFAULT_SETVALUE(QvSFEnum, int);
//DEFAULT_SETVALUE(QvSFFloat, float);
DEFAULT_SETVALUE(QvSFLong, long);
DEFAULT_SETVALUE(QvSFNode, QvNode*);
DEFAULT_SETVALUE(QvSFTime, double);

DEFAULT_SETVALUEARRAY(QvSFVec2f, float, 2);
DEFAULT_SETVALUEARRAY(QvSFVec3f, float, 3);


DEFAULT_SETVALUE(QvSFString, char*);
DEFAULT_SET1VALUE(QvMFString, char*, 1);
DEFAULT_SETVALUES(QvMFString, char*, 1);

DEFAULT_SET1VALUE(QvMFNode, QvNode*, 1);
DEFAULT_SETVALUES(QvMFNode, QvNode*, 1);
                  
QvBool QvSFRotation::setValue(const void *in)
{	
	float *pIn = (float *)in;
	for(int j = 0; j < 3; j++)
	{
		axis[j] = *pIn++;
	}
	angle = *pIn;
	pumpData();	
	if(getContainer()->GetRenderData())	getContainer()->GetRenderData()->SetDirty(true);
    return (TRUE);	
}	


QvBool QvSFMatrix::setValue(const void *in)
{	
	memmove(value, in, 16 * sizeof(float));
    return (TRUE);	
}	

//QvSFImage, float, 1);
QvBool QvSFImage::setValue(const void *in)
{	
	// You'd better set size and numComponents first!!
	//memmove(bytes, in, size[0] * size[1] * numComponents);
    //return (TRUE);	
	// Since this is almost useless, we'll just do nothing
	return FALSE;
}	

DEFAULT_SET1VALUE(QvMFRotation, QvOrientation, 1);
DEFAULT_SETVALUES(QvMFRotation, QvOrientation, 1);
                  
DEFAULT_SET1VALUE(QvMFTime, double, 1);
DEFAULT_SETVALUES(QvMFTime, double, 1);
                  
// for debugging
QvBool QvSFFloat::setValue(const void *datain)
{
	if(getHandler())   ((getContainer()->*(getHandler()))(datain));
	else value = *((float *)datain);
	pumpData();
	if(getContainer()->GetRenderData())	getContainer()->GetRenderData()->SetDirty(true);
    return (TRUE);
}


