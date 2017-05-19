#include <QvSFNode.h>
#include <QvNode.h>

//typedef QvNode *pQvNode;

QV_SFIELD_SOURCE(QvSFNode);

QvBool
QvSFNode::readValue(QvInput *in)
{
    return QvNode::read(in, value);
}
