#ifndef  _QV_STATE_
#define  _QV_STATE_

#include <QvElement.h>

class QvState {

  public:

    // Stack indices, based on type of elements in them:
    enum StackIndex {
	CameraIndex,
	Coordinate3Index,
	LightIndex,
	MaterialBindingIndex,
	MaterialIndex,
	NormalBindingIndex,
	NormalIndex,
	ShapeHintsIndex,
	Texture2Index,
	Texture2TransformationIndex,
	TextureCoordinate2Index,
	TransformationIndex,

	FontStyleIndex,
	BaseColorIndex,

	// Chaco added stacks
	InfoIndex,
	// End Chaco stacks

	// This has to be last!!!
	NumStacks,
    };

    static const char *stackNames[NumStacks];	// Names of stacks

    int		depth;		// Current state depth
    QvElement	**stacks;	// Stacks of elements

    QvState();
    ~QvState();

    // Adds an element instance to the indexed stack
    void	addElement(StackIndex stackIndex, QvElement *elt);

    // Returns top element on a stack
    QvElement *	getTopElement(StackIndex stackIndex)
	{ return stacks[stackIndex]; }

    // Pushes/pops the stacks
    void	push();
    void	pop();

    // Pops top element off one stack
    virtual void	popElement(StackIndex stackIndex); 		// jwd: needs to be virtual for derivation

    // Prints contents for debugging, mostly
    void	print();
};

#endif /* _QV_STATE_ */
