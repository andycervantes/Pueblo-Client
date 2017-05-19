#ifndef  _QV_NODE_
#define  _QV_NODE_

#include <QvString.h>
#include <ChTypes.h>

#define new DEBUG_NEW

class QvChildList;
class QvDict;
class QvFieldData;
class QvInput;
class QvNodeList;
class QvState;

// Chaco classes
class ChQvBounds;
class ChRenderContext;
class ostream;
class ChQvRenderData;

// Abstract Chaco class to hold renderer-specific data in a Qv node
// Derive for each class and each renderer as needed 
class ChQvRenderData
{
	protected:
		bool m_boolDirty;

	public:
		ChQvRenderData() : m_boolDirty(true) {};
		virtual ~ChQvRenderData() {};

		inline bool IsDirty() { return m_boolDirty; };
		virtual void SetDirty( bool boolDirty = true ) 
			{ 
				m_boolDirty = boolDirty;
				return;
			};
};

class QvNode {

  public:
    enum Stage {
	FIRST_INSTANCE,		// First real instance being constructed
	PROTO_INSTANCE,		// Prototype instance being constructed
	OTHER_INSTANCE,		// Subsequent instance being constructed
    };

    QvFieldData	*fieldData;
    QvChildList	*children;
    QvBool	isBuiltIn;

    QvName		*objName;
    QvNode();
    virtual ~QvNode();

    const QvName &	getName() const;
    void		setName(const QvName &name);

    static void		init();
    static void		term();
    static QvBool	read(QvInput *in, QvNode *&node);

    virtual QvFieldData *getFieldData() = 0;

    virtual void	traverse(QvState *state) = 0;
	// Use and Release and GetBounds added by Chaco
	virtual int Use() { return ++m_iUsage; };
	virtual int Release()
		 {
		 	int usage = --m_iUsage;
			if(usage <= 0) delete this;
			return usage;
		  };
	 inline int GetUsage() { return m_iUsage; };
	 #if 0
	 virtual int GetBounds(QvState *state, ChQvBounds * pBounds) {return 0;}; 
	 #endif
	 virtual void write(ostream &strm) {};
	 virtual void Invalidate(ChRenderContext *pRC);
	 virtual int GetType(string & strType) = 0;
	 static QvBool		skipToBrace(QvInput *in);


  protected:
    virtual QvBool	readInstance(QvInput *in);
	int	m_iUsage;
	ChQvRenderData	*m_pRenderData;
  public:
  	ChQvRenderData	*GetRenderData()
  	 {
  	 	return m_pRenderData;
  	 };

  private:
    static QvDict	*nameDict;

    static void		addName(QvNode *, const char *);
    static void		removeName(QvNode *, const char *);
    static QvNode *	readReference(QvInput *in);
    static QvBool	readNode(QvInput *in, QvName &className,QvNode *&node);
    static QvBool	readNodeInstance(QvInput *in, const QvName &className,
					 const QvName &refName, QvNode *&node);
    static QvNode *	createInstance(QvInput *in, const QvName &className);
    static QvNode *	createInstanceFromName(const QvName &className);
    static void		flushInput(QvInput *in);

};

#endif /* _QV_NODE_ */
