#ifndef  _QV_FIELD_
#define  _QV_FIELD_

#include <QvString.h>
#include <QvNode.h>

class QvInput;
class QvNode;
class QvRouteList;
class QvRoute;
class QvField;


class QvField {
	public:
		enum type { typeInvalid = 0,
			typeQvSFBitMask = 1, typeQvSFBool, typeQvSFColor, typeQvSFEnum, typeQvSFFloat, typeQvSFImage, typeQvSFLong, typeQvSFMatrix, typeQvSFNode,
			typeQvSFRotation, typeQvSFString, typeQvSFVec2f, typeQvSFVec3f, typeQvSFTime, typeQvSFPick, typeQvSFProximity, typeQvSFCollision,
			typeQvMFBitMask = 0x8001, typeQvMFBool, typeQvMFColor, typeQvMFEnum, typeQvMFFloat, typeQvMFImage, typeQvMFLong, typeQvMFMatrix, typeQvMFNode,
			typeQvMFRotation, typeQvMFString, typeQvMFVec2f, typeQvMFVec3f, typeQvMFTime, typeQvMFPick, typeQvMFProximity, typeQvMFCollision
		};

  public:
    virtual ~QvField();

    void		setIgnored(QvBool ig)	{ flags.ignored = ig;   }
    QvBool		isIgnored() const	{ return flags.ignored; }

    QvBool		isDefault() const	{ return flags.hasDefault; }

    QvNode *		getContainer() const	{ return container; }

    void		setDefault(QvBool def)	{ flags.hasDefault = def; }
    void		setContainer(QvNode *cont);
    QvBool		read(QvInput *in, const QvName &name);

    QvField() : m_pRoutes(0), m_handler(0)
    	{ flags.hasDefault = TRUE; flags.ignored = FALSE; }

	void addRoute(QvRoute *pRoute);
	void removeRoute(QvRoute *pRoute);
	void removeRoutes();

	typedef QvBool (QvNode::*QvSetValueHandler)(const void *data);
	void setHandler(QvSetValueHandler proc) {m_handler = proc;};
	QvSetValueHandler getHandler() {return m_handler;};
	inline type getType() { return m_type;};


	protected:
		inline void setType(type t) {m_type = t;};

  public:
  	// Assignment should copy values only - so override default here
	QvField& operator=( const QvField& v )
	{
		return *this;
	}

  private:
    struct {
	unsigned int hasDefault		: 1; // Field is set to default value
	unsigned int ignored		: 1; // Field value is to be ignored
    }			flags;

    QvNode		*container;

    static QvField *	createInstanceFromName(const QvName &className);
    virtual QvBool	readValue(QvInput *in) = 0;
	type m_type;


  public:
	// 2.0 style data flow methods
	virtual void propagate(QvField *dest);
	QvBool pumpData();

	private:
		QvRouteList *m_pRoutes;
		QvSetValueHandler m_handler;

friend class QvFieldData;
};

class QvSField : public QvField {
  public:
    virtual ~QvSField();
    virtual QvBool	setValue(const void *in) = 0;

  protected:
    QvSField();

  private:
    virtual QvBool	readValue(QvInput *in) = 0;
};


class QvMField : public QvField {

  public:
    int			num;		// Number of values
    int			maxNum;		// Number of values allocated

    // Destructor
    virtual ~QvMField();
    virtual QvBool	setValues(const void *in, int index, int count) = 0;
    virtual QvBool	set1Value(const void *in, int index) = 0;

  protected:
    QvMField();
    virtual void	makeRoom(int newNum);

  private:
    virtual void	allocValues(int num) = 0;
    virtual QvBool	readValue(QvInput *in);
    virtual QvBool	read1Value(QvInput *in, int index) = 0;


};

#endif /* _QV_FIELD_ */
