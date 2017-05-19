#include <QvBackground.h>

QV_NODE_SOURCE(QvBackground);

QvBackground::QvBackground()
{
    QV_NODE_CONSTRUCTOR(QvBackground);
    isBuiltIn = TRUE;

    QV_NODE_ADD_FIELD(groundColor);
    QV_NODE_ADD_FIELD(skyColor);
    QV_NODE_ADD_FIELD(groundRange);
    QV_NODE_ADD_FIELD(skyRange);
    QV_NODE_ADD_FIELD(panorama);

	// These aren't right, but they're ignored for now
    groundColor.values[0]=groundColor.values[1]=groundColor.values[2] = 0.2;
    skyColor.values[0]=skyColor.values[1]=skyColor.values[2] = 0.8;

	// These should be ok as defaults
    groundRange.values[0]=.785;
    skyRange.values[0]=.785;
    panorama.values[0]="";
}

QvBackground::~QvBackground()
{
}
