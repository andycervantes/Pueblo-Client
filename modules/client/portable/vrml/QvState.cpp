#include <QvState.h>
#if defined(CH_MSW)
#include <windows.h>
#endif

const char *QvState::stackNames[NumStacks] = {
    "Camera",
    "Coordinate3",
    "Light",
    "MaterialBinding",
    "Material",
    "NormalBinding",
    "Normal",
    "ShapeHints",
    "Texture2",
    "Texture2Transformation",
    "TextureCoordinate2",
    "Transformation",
};

QvState::QvState()
{
    stacks = new QvElement * [NumStacks];

    for (int i = 0; i < NumStacks; i++)
	stacks[i] = NULL;

    depth = 0;
}

QvState::~QvState()
{
    while (depth > 0)
	pop();

    delete [] stacks;
}

void
QvState::addElement(StackIndex stackIndex, QvElement *elt)
{
    elt->depth = depth;
    elt->next = stacks[stackIndex];
    stacks[stackIndex] = elt;
}

void
QvState::push()
{
    depth++;
}

void
QvState::pop()
{
    depth--;

    for (int i = 0; i < NumStacks; i++)
	while (stacks[i] != NULL && stacks[i]->depth > depth)
	    popElement((StackIndex) i);
}

void
QvState::popElement(StackIndex stackIndex)
{
    QvElement *elt = stacks[stackIndex];
    stacks[stackIndex] = elt->next;
    delete elt;
}

void
QvState::print()
{
 	#if 0
   //OutputDebugString("Traversal state:\r\n");
    //TRACE("Traversal state:\r\n");
    for (int i = 0; i < NumStacks; i++) {
	char buf[500];
	wsprintf(buf, "\tStack [%2d] (%s):\r\n", i, stackNames[i]);
	//OutputDebugString(buf);
	TRACE(buf);
	if (stacks[i] == NULL)
	    //OutputDebugString("\t\tNULL\r\n");
	    TRACE("\t\tNULL\r\n");

	else
	    for (QvElement *elt = stacks[i]; elt != NULL; elt = elt->next)
		elt->print();
    }
	#endif
}
