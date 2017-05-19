#ifndef  _QV_WWW_ANCHOR_
#define  _QV_WWW_ANCHOR_

#include <QvSFEnum.h>
#include <QvSFString.h>
#include <QvGroup.h>

class QvWWWAnchor : public QvGroup {

    QV_NODE_HEADER(QvWWWAnchor);

  public:

    enum Map {			// Map types:
	NONE,				// Leave URL name alone
	POINT,				// Add object coords to URL name
    };

    // Fields
    QvSFString		name;		// URL name
    QvSFString		description;		// description/hint
    QvSFEnum		map;		// How to map pick to URL name
    QvSFString		target;		// frame

	// Chaco renderer fields
	void UpdateSensor(QvState * state);
};

#endif /* _QV_WWW_ANCHOR_ */
