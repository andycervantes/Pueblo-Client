#include <QvSpin.h>
#include <QvReadError.h>

QV_NODE_SOURCE(QvSpin);

QvSpin::QvSpin()
{
    QV_NODE_CONSTRUCTOR(QvSpin);
    isBuiltIn = TRUE;

    QV_NODE_ADD_FIELD(objectname);
    QV_NODE_ADD_FIELD(xangle);
    QV_NODE_ADD_FIELD(yangle);
    QV_NODE_ADD_FIELD(zangle);
    QV_NODE_ADD_FIELD(axes);

    objectname.value = "";
	xangle.value = 0.0;
	yangle.value = 0.0;
	zangle.value = 0.0;

    #if 1
	//axes.value = LOCAL;	 // ??????
	axes.value = GLOBAL;	 // ??????
    QV_NODE_DEFINE_ENUM_VALUE(Axes, LOCAL);
    QV_NODE_DEFINE_ENUM_VALUE(Axes, GLOBAL);
	#else
	axes.value = eLOCAL;	 // ??????
    if (firstInstance)
	{
		fieldData->addEnumValue("Axes", "LOCAL", eLOCAL);
		fieldData->addEnumValue("Axes", "GLOBAL", eGLOBAL);
	}
	#endif


    QV_NODE_SET_SF_ENUM_TYPE(axes, Axes);

	m_pObject = 0;

}

QvSpin::~QvSpin()
{
}

QvBool
QvSpin::readInstance(QvInput *in)
{
    QvBool readOK = QvNode::readInstance(in);

	// Resolve the pointer to the object to be spun
    if (readOK &&  (objectname.value != ""))
    {
		QvName name = objectname.value;
	    if((m_pObject = in->findReference(name)) == NULL)
		{
			QvReadError::post(in, "Unknown reference \"%s\" in Spin node; Spin ignored.",
				  objectname.value.getString());
		}
    }

    return readOK;
}

