#include <QvMFNode.h>
#include <QvNode.h>

typedef QvNode *pQvNode;

QV_MFIELD_SOURCE(QvMFNode, pQvNode, 1);

QvBool
QvMFNode::read1Value(QvInput *in, int index)
{
	QvBool ret;
    ret = QvNode::read(in, values[index]);	 
    return ret;
}
