#include <QvNavigationInfo.h>

QV_NODE_SOURCE(QvNavigationInfo);

//	NavigationInfo {
//	  eventIn      SFBool   set_bind
//	  exposedField MFFloat  avatarSize       [ 0.25, 1.6, 0.75 ]
//	  exposedField SFBool   headlight        TRUE
//	  exposedField SFFloat  speed            1.0 
//	  exposedField MFString type             "WALK" 
//	  exposedField SFFloat  visibilityLimit  0.0 
//	  eventOut     SFBool   isBound
//	}

QvNavigationInfo::QvNavigationInfo()
{
    QV_NODE_CONSTRUCTOR(QvNavigationInfo);
    isBuiltIn = TRUE;

    QV_NODE_ADD_FIELD(avatarSize);
    QV_NODE_ADD_FIELD(headlight);
    QV_NODE_ADD_FIELD(speed);
    QV_NODE_ADD_FIELD(type);
    QV_NODE_ADD_FIELD(visibilityLimit);
    QV_NODE_ADD_FIELD(isBound);

	avatarSize.values[0] =	0.25;
	avatarSize.values[1] =	1.6;
	avatarSize.values[2] =	0.75;
	headlight.value =TRUE;
	speed.value = 1.0;
    type.values[0] = "WALK";
	visibilityLimit.value	= 0.0;
	isBound.value = TRUE;
}

QvNavigationInfo::~QvNavigationInfo()
{
}
