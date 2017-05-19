#ifndef  _QV_NAVIGATIONINFO_
#define  _QV_NAVIGATIONINFO_

#include <QvMFString.h>
#include <QvMFFloat.h>
#include <QvSFBool.h>
#include <QvSFFloat.h>
#include <QvSubNode.h>

//	NavigationInfo {
//	  eventIn      SFBool   set_bind
//	  exposedField MFFloat  avatarSize       [ 0.25, 1.6, 0.75 ]
//	  exposedField SFBool   headlight        TRUE
//	  exposedField SFFloat  speed            1.0 
//	  exposedField MFString type             "WALK" 
//	  exposedField SFFloat  visibilityLimit  0.0 
//	  eventOut     SFBool   isBound
//	}


class QvNavigationInfo : public QvNode {

    QV_NODE_HEADER(QvNavigationInfo);

  public:
    // Fields
	QvMFFloat  avatarSize;     
	QvSFBool   headlight;      
	QvSFFloat  speed;          
	QvMFString type;           
	QvSFFloat  visibilityLimit;
	QvSFBool   isBound;        
};

#endif /* _QV_NAVIGATIONINFO_ */
