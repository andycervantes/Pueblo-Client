#ifndef  _QV_FONT_STYLE_
#define  _QV_FONT_STYLE_

#include <QvSFEnum.h>
#include <QvSFFloat.h>
#include <QvSFBitMask.h>
#include <QvSubNode.h>

class QvFontStyle : public QvNode {

    QV_NODE_HEADER(QvFontStyle);

  public:
    enum Family {
	SERIF,
	SANS,
	TYPEWRITER,
	};

    enum Style {		
	NONE	= 0x01,		
	BOLD	= 0x02,		
	ITALIC	= 0x04		
    };

   // Fields
    QvSFFloat		size;		// in object units
    QvSFEnum		family;		// font family
    QvSFBitMask		style;		// font style
};

#endif /* _QV_FONT_STYLE_ */
