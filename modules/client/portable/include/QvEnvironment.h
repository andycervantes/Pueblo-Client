#ifndef  _QV_ENVIRONMENT_
#define  _QV_ENVIRONMENT_

#include <QvSFFloat.h>
#include <QvSFColor.h>
#include <QvSFVec3f.h>
#include <QvSFEnum.h>
#include <QvSFBitMask.h>
#include <QvSubNode.h>

class QvEnvironment : public QvNode {

    QV_NODE_HEADER(QvEnvironment);

  public:

    enum FogType {		
	NONE	= 0x01,		
	HAZE	= 0x02,		
	FOG	= 0x04		
    };
	
   // Fields
	QvSFFloat 	ambientIntensity;   // 0.0          # SFFloat
	QvSFColor 	ambientColor;       // 1.0 1.0 1.0  # SFColor
	QvSFVec3f 	attenuation;        // 0.0 0.0 1.0  # SFVec3f
	QvSFEnum	fogType;            // NONE         # enum (NONE, HAZE, FOG)
	QvSFColor	fogColor;           // 0.0 0.0 0.0  # SFColor
	QvSFFloat	fogVisibility;      // 0.0          # SFFloat
	QvSFVec3f	soundAttenuation;   // 0.0 0.0 1.0  # SFVec3f
									
};

#endif /* _QV_ENVIRONMENT_ */
