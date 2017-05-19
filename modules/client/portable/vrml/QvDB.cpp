#include <QvDB.h>
#include <QvInput.h>
#include <QvReadError.h>
#include <QvNode.h>
#include <QvNodes.h>
#include <QvUnknownNode.h>

const char *QvDB::versionString = "Reference VRML Parser 1.0";

void
QvDB::init()
{
    QvNode::init();
}

void
QvDB::term()
{

	QvAsciiText::term();
	QvBaseColor::term();
	QvCone::term();
	QvCoordinate3::term();
	QvCube::term();
	QvCylinder::term();
	QvDirectionalLight::term();
	QvFontStyle::term();
	QvGroup::term();
	QvIndexedFaceSet::term();
	QvIndexedLineSet::term();
	QvInfo::term();
	QvLOD::term();
	QvMaterial::term();
	QvMaterialBinding::term();
	QvMatrixTransform::term();
	QvNormal::term();
	QvNormalBinding::term();
	QvOrthographicCamera::term();
	QvPerspectiveCamera::term();
	QvPointLight::term();
	QvPointSet::term();
	QvRotation::term();
	QvScale::term();
	QvSeparator::term();
	QvShapeHints::term();
	QvSphere::term();
	QvSpotLight::term();
	QvSwitch::term();
	QvTexture2::term();
	QvTexture2Transform::term();
	QvTextureCoordinate2::term();
	QvTransform::term();
	QvTransformSeparator::term();
	QvTranslation::term();
	QvUnknownNode::term();
	QvWWWAnchor::term();
	QvWWWInline::term();
	QvSpin::term();
	QvSpinGroup::term();
	
	QvInterpolator::term();
	QvOrientationInterpolator::term();
	QvPositionInterpolator::term();
	QvSensor::term();
	QvTimeSensor::term();
	QvRoute::term();

    QvNode::term();
	QvNameEntry::term();

}

QvBool
QvDB::read(QvInput *in, QvNode *&node)
{
    QvBool ret;

	#if 1
	// Added by jwd to handle multiple top level nodes
	// We oughta post a warning here too.
	QvNode *nodeJustRead = 0, *newTop = 0;
    ret = QvNode::read(in, node);	 
	QvBool ret2;
	while(ret && ! in->eof() && (ret2 = QvNode::read(in, nodeJustRead)))
	{
		// Test for more toplevel nodes
		if(nodeJustRead)
		{
			if(!newTop)
			{
				newTop = new QvSeparator;
				newTop->children->append(node);	 // add first to new top
				node = newTop;
			}
			node->children->append(nodeJustRead);	// add this to our new top
		}
		else break;
	}

	#else

    ret = QvNode::read(in, node);
	#endif

    #if 1
    if (ret && node == NULL && ! in->eof()) {
	char	c;
	in->get(c);
	QvReadError::post(in, "Extra characters ('%c') found in input", c);
	ret = FALSE;
    }
	#endif

    return ret;
}
