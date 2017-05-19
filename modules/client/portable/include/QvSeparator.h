#ifndef  _QV_SEPARATOR_
#define  _QV_SEPARATOR_

#include <QvSFEnum.h>
#include <QvGroup.h>

#include <QvSFBitMask.h>

class QvSeparator : public QvGroup {

    QV_NODE_HEADER(QvSeparator);

  public:
    enum CullEnabled {		// Possible values for culling
	OFF,			// Never cull
	ON,			// Always cull
	AUTO,			// Decide based on some heuristic
    };
	#if 0
    enum CacheEnabled {		// Possible values for caching	// jwd for chaco added
	OFF,			// Never cache
	ON,			// Always cache
	AUTO,			// Decide based on some heuristic
    };
	#endif
    // Fields
    QvSFEnum renderCulling;
    QvSFEnum renderCaching;
};

#endif /* _QV_SEPARATOR_ */
