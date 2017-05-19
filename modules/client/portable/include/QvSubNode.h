#ifndef  _QV_SUB_NODE_
#define  _QV_SUB_NODE_

#include <QvFieldData.h>
#include <QvNode.h>

#define QV_NODE_HEADER(className)					      \
  public:								      \
    className::className();						      \
    virtual ~className();						      \
    virtual void	traverse(QvState *state);			      \
	static void term() 					\
		{ delete fieldData; fieldData = 0; firstInstance = TRUE; };	\
	/*virtual int GetBounds(QvState *state, ChQvBounds * pBounds);*/	\
	 virtual void write(ostream &strm);				 \
	 	 virtual int GetType(string & strType);	\
  private:								      \
    static QvBool	firstInstance;					      \
    static QvFieldData	*fieldData;					      \
    virtual QvFieldData *getFieldData() { return fieldData; }

#define QV_NODE_SOURCE(className)					      \
    QvFieldData	       *className::fieldData;				      \
    QvBool		className::firstInstance = TRUE;

#define QV_NODE_CONSTRUCTOR(className)					      \
    if (fieldData == NULL)						      \
	fieldData = new QvFieldData;					      \
    else								      \
	firstInstance = FALSE;						      \
    isBuiltIn = FALSE;							      \

#define QV_NODE_IS_FIRST_INSTANCE() (firstInstance == TRUE)

#define QV_NODE_ADD_FIELD(fieldName)					      \
    if (firstInstance)							      \
	fieldData->addField(this, QV__QUOTE(fieldName), &this->fieldName);    \
    this->fieldName.setContainer(this);

#define QV_NODE_DEFINE_ENUM_VALUE(enumType,enumValue)			      \
    if (firstInstance)							      \
	fieldData->addEnumValue(QV__QUOTE(enumType),			      \
				QV__QUOTE(enumValue), enumValue)

// Need to refine this definition TODO!!
#define QV_NODE_EVENTOUT  QV_NODE_ADD_FIELD

#define QV_NODE_ADD_EXPOSED_FIELD  QV_NODE_ADD_FIELD

#define QV_NODE_SET_EVENT_IN(fieldName)	\
    this->fieldName.setHandler(QvField::QvSetValueHandler(set_##fieldName));

#endif /* _QV_SUB_NODE_ */

