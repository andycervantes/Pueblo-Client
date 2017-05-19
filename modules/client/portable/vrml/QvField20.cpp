#include <QvFields.h>
#include <QvRoute.h>
#include <ChTypes.h>
#include <ChList.h>

// VRML 2.0 style routing
class QvRoute;

class QvRouteList : public ChPtrList<QvRoute>
{
	public:
		QvRouteList() : ChPtrList<QvRoute>() {} ;
		virtual ~QvRouteList() {};
};

QvBool
QvField::pumpData()
{
	if(m_pRoutes && !m_pRoutes->IsEmpty())
	{
		ChPosition pos = m_pRoutes->GetHeadPosition();
		while(pos)
		{
			QvRoute *pRoute = m_pRoutes->GetNext(pos);
			QvField *pTarget = pRoute->GetDestination();
			propagate(pTarget);
		}

	}
	return TRUE;
}

void QvField::propagate(QvField *dest)
{
	//*dest = *this; ??
}

void QvField::addRoute(QvRoute *pRoute)
{
	if(!m_pRoutes) m_pRoutes = new QvRouteList;
	if(m_pRoutes)
	{
		ChPosition pos = m_pRoutes->Find(pRoute);
		if(!pos)
		{
			m_pRoutes->AddTail(pRoute);
		}

	}
}

void QvField::removeRoutes()
{
	if(m_pRoutes)
	{
		while(!m_pRoutes->IsEmpty())
		{
			QvRoute *pRoute = m_pRoutes->RemoveHead();
			pRoute->SetSource(0);
		}
		delete m_pRoutes;
	}
}

void QvField::removeRoute(QvRoute *pRoute)
{
	if(m_pRoutes)
	{
		ChPosition pos = m_pRoutes->Find(pRoute);
		if(pos)
		{
			m_pRoutes->Remove(pos);
		}
	}
}
