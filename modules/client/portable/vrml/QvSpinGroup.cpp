#include <QvSpinGroup.h>

QV_NODE_SOURCE(QvSpinGroup);

QvSpinGroup::QvSpinGroup()
{
    QV_NODE_CONSTRUCTOR(QvSpinGroup);
    isBuiltIn = TRUE;

    QV_NODE_ADD_FIELD(local);
    QV_NODE_ADD_FIELD(rotation);

    local.value = TRUE;

    rotation.axis[0] = 0.0;
    rotation.axis[1] = 0.0;
    rotation.axis[2] = 1.0;
    rotation.angle = 0.0;

}

QvSpinGroup::~QvSpinGroup()
{
}
