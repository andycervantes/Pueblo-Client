#include <QvLevelOfDetail.h>

QV_NODE_SOURCE(QvLOD);

QvLOD::QvLOD()
{
    QV_NODE_CONSTRUCTOR(QvLOD);
    isBuiltIn = TRUE;

    QV_NODE_ADD_FIELD(range);
    QV_NODE_ADD_FIELD(center);

    range.values[0] = 0;
    center.value[0] = 0.0;
    center.value[1] = 0.0;
    center.value[2] = 0.0;
}

QvLOD::~QvLOD()
{
}
