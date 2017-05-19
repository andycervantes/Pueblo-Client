#ifdef CH_MSW
#include <QvSFString.h>
#endif
#include <QvWWWInline.h>

QV_NODE_SOURCE(QvWWWInline);

QvWWWInline::QvWWWInline()
{
    QV_NODE_CONSTRUCTOR(QvWWWInline);
    isBuiltIn = TRUE;

    QV_NODE_ADD_FIELD(name);
    QV_NODE_ADD_FIELD(bboxSize);
    QV_NODE_ADD_FIELD(bboxCenter);

    name.value = "";
    bboxSize.value[0] = bboxSize.value[1] = bboxSize.value[2] = 0.0;
    bboxCenter.value[0] = bboxCenter.value[1] = bboxCenter.value[2] = 0.0;
}

QvWWWInline::~QvWWWInline()
{
}
