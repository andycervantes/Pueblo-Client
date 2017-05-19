#include <QvInfo.h>

QV_NODE_SOURCE(QvInfo);

QvInfo::QvInfo()
{
    QV_NODE_CONSTRUCTOR(QvInfo);
    isBuiltIn = TRUE;

    QV_NODE_ADD_FIELD(string);

    string.value = QV_UNDEFINED_INFO;
}

QvInfo::~QvInfo()
{
}
