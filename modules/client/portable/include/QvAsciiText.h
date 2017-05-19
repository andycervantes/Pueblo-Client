#ifndef  _QV_ASCII_TEXT_
#define  _QV_ASCII_TEXT_

#include <QvMFString.h>
#include <QvSFFloat.h>
#include <QvSFEnum.h>
#include <QvMFFloat.h>
#include <QvSubNode.h>


class QvAsciiText : public QvNode {

    QV_NODE_HEADER(QvAsciiText);

  public:
    enum Justification {
	LEFT,
	CENTER,
	RIGHT,
    };
 
   // Fields:
    QvMFString		string;				// String(s) to print
    QvSFFloat		spacing;			// vertical spacing
    QvSFEnum		justification;		// text justification
    QvMFFloat		width;				// width of each line; 0 is 'natural'
};

#endif /* _QV_ASCII_TEXT_ */
