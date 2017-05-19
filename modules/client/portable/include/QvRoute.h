#ifndef  _QV_ROUTE_
#define  _QV_ROUTE_

#include <QvSubNode.h>
#include <QvSFFloat.h>
#include <QvMFFloat.h>
#include <QvSensor.h>
#include <QvString.h>
#include <QvSFString.h>

// not really a node but for now it'll do

class QvRoute : public QvNode {

		QV_NODE_HEADER(QvRoute);

	public:
		inline QvField *GetDestination() { return m_pDestination; };
		inline QvField *GetSource() { return m_pSource; };

		inline void SetDestination(QvField *pDestination);
		inline void SetSource(QvField *pSource);
		static QvBool 	readRoute(QvInput *in, QvNode *&node);
		static QvBool split(const QvString &name, QvString &nodeName, QvString &fieldName);
		static QvBool findConnection(QvInput *in, QvString &name, QvField *&fld, QvBool boolEventIn);
		static QvBool findConnection(QvNode *pNode, const QvString &eventname, QvField *&fld, QvBool boolEventIn);

	protected:
		QvField *m_pDestination;
		QvField *m_pSource;

	protected:
		QvSFString source;
		QvSFString destination;

};

#endif /* _QV_ROUTE_ */
