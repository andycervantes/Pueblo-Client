#include <QvBaseColor.h>

QV_NODE_SOURCE(QvBaseColor);

QvBaseColor::QvBaseColor()
{
    QV_NODE_CONSTRUCTOR(QvBaseColor);
    isBuiltIn = TRUE;

    QV_NODE_ADD_FIELD(rgb);

    rgb.values[0]=rgb.values[1]=rgb.values[2] = 0.2F;
}

QvBaseColor::~QvBaseColor()
{
}
