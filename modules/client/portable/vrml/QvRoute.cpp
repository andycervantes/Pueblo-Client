#include <QvRoute.h>

QV_NODE_SOURCE(QvRoute);

QvBool eventToFieldName(const QvString &event, QvString &fieldName, QvBool eventIn);

QvRoute::QvRoute()
{
    QV_NODE_CONSTRUCTOR(QvRoute);
    isBuiltIn = TRUE;

    QV_NODE_ADD_FIELD(destination);
    QV_NODE_ADD_FIELD(source);

	m_pDestination = 0; 
	m_pSource      = 0; 
}					   

QvRoute::~QvRoute()
{
	if(m_pSource) m_pSource->removeRoute(this);
}

QvBool QvRoute::readRoute(QvInput *in, QvNode *&node)
{
	
    QvString            srcString;
    QvString            toString;
    QvString            destString;
	QvField *fldSrc, *fldDest;

	if (in->read(srcString) &&
		in->read(toString) &&
		toString == "TO" &&
		in->read(destString))
	{
		QvRoute * route;
		node = route = new QvRoute;
		route->destination.value =	destString;
		route->source.value = srcString;

		route->findConnection(in, destString, fldDest, TRUE);
		route->findConnection(in, srcString, fldSrc, FALSE);

		// If we got one, is it a legal route?
		// types must match!
		if(fldSrc && fldDest && fldSrc->getType() == fldDest->getType())
		{
			route->SetDestination(fldDest);
			route->SetSource(fldSrc);
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}

    return TRUE;
}

QvBool QvRoute::findConnection(QvInput *in, QvString &name, QvField *&fld, QvBool boolEventIn)
{
	// Attempt to connect to source and destination
	QvString nodeName, eventName;

	split(name, nodeName, eventName);
	QvName refName(nodeName);
	QvNode *node;
	if ((node = in->findReference(refName)) != NULL)
	{
		return findConnection(node, eventName, fld, boolEventIn);
	}

	return FALSE;
}

QvBool QvRoute::findConnection(QvNode *node, const QvString &eventName, QvField *&fld, QvBool boolEventIn)
{
	// Attempt to connect to source or destination
	bool boolFound = FALSE;
	if (node != NULL)
	{
		QvString fieldName;
		if(eventToFieldName(eventName, fieldName, boolEventIn))
		{
			fld = 0;
			QvFieldData *data = node->getFieldData();
		    int numFields =	data->getNumFields();
			for(int j= 0; j < numFields; j++)
			{


			    if(data->getFieldName(j) == fieldName)
				{
					fld = data->getField(node, j);
					boolFound = TRUE;
					break;
				}
			}

		}
	}
	
	return boolFound;
}

QvBool QvRoute::split(const QvString &name, QvString &nodeName, QvString &fieldName)
{
	// split name into node.field names
	nodeName = "";
	fieldName = "";

	char *buf = new char[name.getLength() + 1];

	strcpy(buf, name.getString());

	char *pDot = strrchr(buf, '.');
	if(pDot)
	{
		*pDot = 0;
		fieldName = pDot + 1;
	}
	nodeName = buf;

	delete [] buf;

	return TRUE;
}

QvBool eventToFieldName(const QvString &event, QvString &fieldName, QvBool eventIn)
{
	const char *strEvent = event.getString();
	if(eventIn)
	{
		if(!strncmp(strEvent, "set_", 4))
		{
			fieldName = strEvent + 4;
		}
		else 
		{
			return FALSE;
		}
	}
	else
	{
		char *buf = new char[event.getLength() + 1];
		strcpy(buf, event.getString());
		char *pBar = strrchr(buf, '_');
		if(pBar)
		{
			if(!strcmp(pBar, "_changed"))
			{
				*pBar = 0;
				fieldName = buf;
			}
			else
			{
				delete [] buf;
				return FALSE;
			}
		}
		else 
		{
			delete [] buf;
			return FALSE;
		}
		delete [] buf;
	}
	return TRUE;

}

void QvRoute::SetDestination(QvField *pDestination)
{  
	m_pDestination = pDestination;
};

void QvRoute::SetSource(QvField *pSource)
{
	if(m_pSource)
	{
		m_pSource->removeRoute(this);
	}  
	m_pSource = pSource; 
	if(m_pSource)
	{
		m_pSource->addRoute(this);
	}  
};
