#include <QvEnvironment.h>

QV_NODE_SOURCE(QvEnvironment);

QvEnvironment::QvEnvironment()
{
    QV_NODE_CONSTRUCTOR(QvEnvironment);
    isBuiltIn = TRUE;

    QV_NODE_ADD_FIELD(ambientIntensity);
    QV_NODE_ADD_FIELD(ambientColor);
    QV_NODE_ADD_FIELD(attenuation);
    QV_NODE_ADD_FIELD(fogType);
    QV_NODE_ADD_FIELD(fogColor);
    QV_NODE_ADD_FIELD(fogVisibility);
    QV_NODE_ADD_FIELD(soundAttenuation);

	ambientIntensity.value =  0.0;          
	ambientColor.value[0] = ambientColor.value[1] =  ambientColor.value[2] =  1.0;  
	attenuation.value[0] =  0.0;  
	attenuation.value[1] =  0.0;  
	attenuation.value[2] =  1.0;
	fogType.value =  NONE;
	         
	fogColor.value[0] = fogColor.value[1] = fogColor.value[2] =  0.0;
	  
	fogVisibility.value =  0.0; 

	soundAttenuation.value[0] = 0.0;  
	soundAttenuation.value[1] = 0.0;  
	soundAttenuation.value[2] = 1.0;

    QV_NODE_DEFINE_ENUM_VALUE(FogType, NONE);
    QV_NODE_DEFINE_ENUM_VALUE(FogType, HAZE);
    QV_NODE_DEFINE_ENUM_VALUE(FogType, FOG);

    QV_NODE_SET_SF_ENUM_TYPE(fogType, FogType);
}

QvEnvironment::~QvEnvironment()
{
}
