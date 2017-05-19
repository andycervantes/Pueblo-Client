#include <QvUnknownNode.h>

QV_NODE_SOURCE(QvUnknownNode);

QvUnknownNode::QvUnknownNode()
{
	int wasNull = (fieldData == 0);
    QV_NODE_CONSTRUCTOR(QvUnknownNode);

    className = NULL;

    // Set global field data to this instance's
    instanceFieldData = new QvFieldData;
	if(wasNull) delete fieldData;  // delete the first one, but not if someone else put it there
    fieldData = instanceFieldData;
}

void
QvUnknownNode::setClassName(const char *name)
{
    className = strdup(name);
}

QvUnknownNode::~QvUnknownNode()
{
    if (className != NULL)
	free((void *) className);
	delete instanceFieldData;				//I think this is a leak but who knows? jwd 2/27/96
	if(fieldData == instanceFieldData) fieldData = 0;
	instanceFieldData = 0;
}
