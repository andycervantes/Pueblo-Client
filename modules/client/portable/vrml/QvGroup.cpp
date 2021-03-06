#include <QvInput.h>
#include <QvReadError.h>
#include <QvFieldData.h>
#include <QvChildList.h>
#include <QvGroup.h>

QV_NODE_SOURCE(QvGroup);

QvGroup::QvGroup()
{
    children = new QvChildList();
    QV_NODE_CONSTRUCTOR(QvGroup);
    isBuiltIn = TRUE;
}

QvGroup::~QvGroup()
{
	// Added by jwd to delete entire tree
	for ( int i = 0; i < getNumChildren(); i++)
	{
		getChild(i)->Release();
	}
	// end addition jwd

    delete children;
}

QvNode *
QvGroup::getChild(int index) const
{
    return(*children)[index];
}

int
QvGroup::getNumChildren() const
{
    return children->getLength();
}

QvChildList *
QvGroup::getChildren() const
{
    return children;
}

QvBool
QvGroup::readInstance(QvInput *in)
{
    QvName	typeString;
    QvFieldData	*fieldData = getFieldData();

    //if (! isBuiltIn) to make redefining fields ok
    {
        if (in->read(typeString, TRUE)) {
	    if (typeString == "fields") {
		if (! fieldData->readFieldTypes(in, this)) {
		    QvReadError::post(in, "Bad field specifications for node");
		    return FALSE;
		}
	    }
	    else
		if(typeString != "") in->putBack(typeString.getString());	// jwd to prevent overwrite of prev string
	}
    }

    return (fieldData->read(in, this, FALSE) && readChildren(in));
}

QvBool
QvGroup::readChildren(QvInput *in)
{
    QvNode	*child;
    QvBool	ret = TRUE;

    while (TRUE) {
	if (read(in, child)) {
	    if (child != NULL)
		children->append(child);
	    else
		break;
	}
	else {
	    ret = FALSE;
	    break;
	}
    }

    return ret;
}
