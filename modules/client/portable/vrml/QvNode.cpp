#include <ctype.h>
#include <QvDB.h>
#include <QvInput.h>
#include <QvDebugError.h>
#include <QvReadError.h>
#include <QvField.h>
#include <QvFieldData.h>
#include <QvNodes.h>
#include <QvUnknownNode.h>

// The global name dictionary
QvDict		*QvNode::nameDict = NULL;

// Syntax for writing instances to files
#define OPEN_BRACE		'{'
#define CLOSE_BRACE		'}'
#define DEFINITION_KEYWORD	"DEF"
#define REFERENCE_KEYWORD	"USE"
#define NULL_KEYWORD		"NULL"
#define ROUTE_NAME			"ROUTE"

void
QvNode::init()
{
    if (nameDict == NULL)
	nameDict = new QvDict;
}

// Added by jwd chaco in quest of plugging leaks
void
QvNode::term()
{
	delete nameDict;
	nameDict = NULL;
}

QvNode::QvNode() : m_iUsage(1), m_pRenderData(0) 
{
    objName = new QvName("");
}

QvNode::~QvNode()
{
    if (! !(*objName))
	removeName(this, objName->getString());
    delete objName;
	delete m_pRenderData;
	m_pRenderData = 0;
}

const QvName &
QvNode::getName() const
{
    return *objName;
}

void
QvNode::setName(const QvName &newName)
{
    if (! !(*objName)) {
	removeName(this, objName->getString());
    }
    delete objName;

    const char *str = newName.getString();
    QvBool isBad = 0;

    if (newName.getLength() > 0 &&
	!QvName::isNodeNameStartChar(str[0])) isBad = TRUE;

    int i;
    for (i = 1; i < newName.getLength() && !isBad; i++) {
	isBad = !QvName::isNodeNameChar(str[i]);
    }

    if (isBad) {
	QvString goodString;

	if (!QvName::isNodeNameStartChar(str[0])) {
	    goodString += "_";
	}
	for (i = 0; i < newName.getLength(); i++) {
	    char temp[2];
	    temp[0] = str[i]; temp[1] = '\0';
	    if (!QvName::isNodeNameChar(str[i]))
		goodString += "_";
	    else
		goodString += temp;
	}
#ifdef DEBUG
	QvDebugError::post("QvNode::setName", "Bad characters in"
			   " name '%s'.  Replacing with name '%s'",
			   str, goodString.getString());
#endif       
	objName = new QvName(goodString);
    }
    else {
	objName = new QvName(newName);
    }
    if (! !(*objName)) {
	addName(this, objName->getString());
    }
}

void
QvNode::addName(QvNode *b, const char *name)
{
    QvPList *list;
    void *t;
    if (!nameDict->find((u_long)name, t)) {
	list = new QvPList;
	nameDict->enter((u_long)name, list, TRUE);
    }
    else {
	list = (QvPList *)t;
    }

    list->append(b);
}

void
QvNode::removeName(QvNode *b, const char *name)
{
    QvPList	*list;
    QvBool	found;
    void	*t;
    int		i;

    found = nameDict->find((u_long) name, t);

    if (found) {
	list = (QvPList *) t;
	i    = list->find(b);

	if (i < 0)
	    found = FALSE;

	else
	    list->remove(i);
    }

    if (! found)
	QvDebugError::post("QvNode::removeName",
			   "Name \"%s\" (node %x) is not in dictionary",
			   name, b);
}

QvBool
QvNode::read(QvInput *in, QvNode *&node)
{
    QvBool	ret;
    QvName	name;

    if (! in->read(name, TRUE)) {
	node = NULL;
	ret = in->headerOk;
    }

    else if (! name || name == NULL_KEYWORD) {
	node = NULL;
	ret = TRUE;
    }

    else if (name == REFERENCE_KEYWORD) {
	node = readReference(in);
	ret = (node != NULL);
    }

    else
	ret = readNode(in, name, node);

    return ret;
}

QvBool
QvNode::readInstance(QvInput *in)
{
    QvName	typeString;
    QvFieldData	*fieldData = getFieldData();

    if (in->read(typeString, TRUE)) {
	if (typeString == "fields") {
	    if (! fieldData->readFieldTypes(in, this)) {
		QvReadError::post(in, "Bad field specifications for node");
		return FALSE;
	    }
	}
	else
	    in->putBack(typeString.getString());
    }

    if (! fieldData->read(in, this))
        return FALSE;

    return TRUE;
}

QvNode *
QvNode::readReference(QvInput *in)
{
    QvName	refName;
    QvNode	*node;

    if (! in->read(refName, FALSE)) {
	QvReadError::post(in, "Premature end of file after "
			  REFERENCE_KEYWORD);
	node = NULL;
    }

    else if ((node = in->findReference(refName)) == NULL)
	QvReadError::post(in, "Unknown reference \"%s\"",
			  refName.getString());
	if (node) node->Use();	// jwd to add usage count
    return node;
}

QvBool
QvNode::readNode(QvInput *in, QvName &className, QvNode *&node)
{
    QvBool	gotChar;
    QvName	refName;
    char	c;
    QvBool	ret = TRUE, flush = FALSE;

    node = NULL;

    if (className == DEFINITION_KEYWORD) {
		if (! in->read(refName, FALSE) || ! in->read(className, TRUE)) {
		    QvReadError::post(in, "Premature end of file after "
				      DEFINITION_KEYWORD);
		    ret = FALSE;
		}

		if (! refName) {
		    QvReadError::post(in, "No name given after ", DEFINITION_KEYWORD);
		    ret = FALSE;
		}

		if (! className) {
		    QvReadError::post(in, "Invalid definition of %s",
				      refName.getString());
		    ret = FALSE;
		}
    }

    if (ret) {
		if(className == ROUTE_NAME)
		{
			ret = QvRoute::readRoute(in, node);
		}
		else
		{

			if (! (gotChar = in->read(c)) || c != OPEN_BRACE) {
			    if (gotChar)
				QvReadError::post(in, "Expected '%c'; got '%c'",
						  OPEN_BRACE, c);
			    else
				QvReadError::post(in, "Expected '%c'; got EOF", OPEN_BRACE);
			    ret = FALSE;
			}

			else {
			    ret = readNodeInstance(in, className, refName, node);

			    if (! ret)
				flush = TRUE;

			    else if (! (gotChar = in->read(c)) || c != CLOSE_BRACE) {
				if (gotChar)
				    QvReadError::post(in, "Expected '%c'; got '%c'",
						      CLOSE_BRACE, c);
				else
				    QvReadError::post(in, "Expected '%c'; got EOF",
						      CLOSE_BRACE);
				ret = FALSE;
			    }
			}
		}
    }

    if (! ret && flush)
	flushInput(in);

    return ret;
}

QvBool
QvNode::readNodeInstance(QvInput *in, const QvName &className,
			 const QvName &refName, QvNode *&node)
{
    node = createInstance(in, className);
    if (node == NULL)
	return FALSE;

    if (! (! refName))
	in->addReference(refName, node);

    return node->readInstance(in);
}

QvNode *
QvNode::createInstance(QvInput *in, const QvName &className)
{
    QvNode		*instance;
    QvString            unknownString;

    instance = createInstanceFromName(className);

    if (instance == NULL) {

		// Changed to allow empty unknown nodes - jwd for Chaco
		if (! in->read(unknownString) )
		{  
		    QvReadError::post(in, "Unknown class \"%s\". Parsing failed.",
				      className.getString());
	    	return NULL;
		}
		else if (unknownString != "fields" && unknownString != "}") 
		{
									// Try to recover, skip to matching brace

			if(skipToBrace(in))
			{
				#if 0
		    	QvReadError::postWarning(in, "Unknown class \"%s\". Node ignored.",
				      className.getString());
				#endif
				// Recovered!
			    QvUnknownNode *tmpNode = new QvUnknownNode;
			    tmpNode->setClassName(className.getString());
			    instance = tmpNode;
			}
			else
			{
		    	QvReadError::post(in, "Unknown class \"%s\". Parsing failed.",
				      className.getString());
		    	return NULL;
			}
		}

		else if (unknownString == "fields")
		{
			// Rather than trying to read it, just skip it and be done
			// with it - this prevents leaks of fieldNames - jwd 5/13/96
			if(skipToBrace(in))
			{
			    QvUnknownNode *tmpNode = new QvUnknownNode;
			    tmpNode->setClassName(className.getString());
			    instance = tmpNode;
			}
			else
			{
		    	QvReadError::post(in, "Unknown class \"%s\". Parsing failed.",
				      className.getString());
		    	return NULL;
			}
		}
		else if ( unknownString == "}")
		{
		    QvUnknownNode *tmpNode = new QvUnknownNode;
		    tmpNode->setClassName(className.getString());
		    instance = tmpNode;
		    in->putBack(unknownString.getString());
		}
    }

    return instance;
}

QvNode *
QvNode::createInstanceFromName(const QvName &className)
{
#define TRY_CLASS(name, class)						      \
    else if (className == name)						      \
	inst = new class

    QvNode *inst = NULL;

    if (0) ;			// So "else" works in first TRY_CLASS
    TRY_CLASS("AsciiText",			QvAsciiText);
    TRY_CLASS("Background",			QvBackground);
    TRY_CLASS("BaseColor",			QvBaseColor);
    TRY_CLASS("Cone",			QvCone);
    TRY_CLASS("Coordinate3",		QvCoordinate3);
    TRY_CLASS("Cube",			QvCube);
    TRY_CLASS("Cylinder",		QvCylinder);
    TRY_CLASS("DirectionalLight",	QvDirectionalLight);
    TRY_CLASS("FontStyle",	QvFontStyle);
    TRY_CLASS("Group",			QvGroup);
    TRY_CLASS("IndexedFaceSet",		QvIndexedFaceSet);
    TRY_CLASS("IndexedLineSet",		QvIndexedLineSet);
    TRY_CLASS("Info",			QvInfo);
    TRY_CLASS("LOD",		QvLOD);
    TRY_CLASS("Material",		QvMaterial);
    TRY_CLASS("MaterialBinding",	QvMaterialBinding);
    TRY_CLASS("MatrixTransform",	QvMatrixTransform);
    TRY_CLASS("Normal",			QvNormal);
    TRY_CLASS("NormalBinding",		QvNormalBinding);
    TRY_CLASS("OrthographicCamera",	QvOrthographicCamera);
    TRY_CLASS("PerspectiveCamera",	QvPerspectiveCamera);
    TRY_CLASS("PointLight",		QvPointLight);
    TRY_CLASS("PointSet",		QvPointSet);
    TRY_CLASS("Rotation",		QvRotation);
    TRY_CLASS("Scale",			QvScale);
    TRY_CLASS("Separator",		QvSeparator);
    TRY_CLASS("ShapeHints",		QvShapeHints);
    TRY_CLASS("Sphere",			QvSphere);
    TRY_CLASS("Spin",			QvSpin);
    TRY_CLASS("SpinGroup",			QvSpinGroup);
    TRY_CLASS("SpotLight",		QvSpotLight);
    TRY_CLASS("Switch",			QvSwitch);
    TRY_CLASS("Texture2",		QvTexture2);
    TRY_CLASS("Texture2Transform",	QvTexture2Transform);
    TRY_CLASS("TextureCoordinate2",	QvTextureCoordinate2);
    TRY_CLASS("Transform",		QvTransform);
    TRY_CLASS("TransformSeparator",	QvTransformSeparator);
    TRY_CLASS("Translation",		QvTranslation);
    TRY_CLASS("WWWAnchor",		QvWWWAnchor);
    TRY_CLASS("WWWInline",		QvWWWInline);
    
    TRY_CLASS("TimeSensor",		QvTimeSensor);
    TRY_CLASS("OrientationInterpolator",		QvOrientationInterpolator);
    TRY_CLASS("PositionInterpolator",		QvPositionInterpolator);
    TRY_CLASS("NavigationInfo",			QvNavigationInfo);
    
    return inst;

#undef TRY_CLASS
}

void
QvNode::flushInput(QvInput *in)
{
    int		nestLevel = 1;
    char	c;

    while (nestLevel > 0 && in->get(c)) {

	if (c == CLOSE_BRACE)
	    nestLevel--;

	else if (c == OPEN_BRACE)
	    nestLevel++;
    }
}

// Added by jwd to skip bad node defns
QvBool
QvNode::skipToBrace(QvInput *in)
{
    QvString            unknownString;
	int count = 1;


	while (count > 0 && in->read(unknownString) )
	{
		if (unknownString == "}")  count --;
		if (unknownString == "{")  count ++;
	}
	if(count > 0) return FALSE;

    in->putBack(unknownString.getString());
    return TRUE;
}


#undef OPEN_BRACE
#undef CLOSE_BRACE
#undef DEFINITION_KEYWORD
#undef REFERENCE_KEYWORD
#undef NULL_KEYWORD
#undef ROUTE_NAME
