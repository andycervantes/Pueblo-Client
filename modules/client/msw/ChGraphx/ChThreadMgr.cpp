/*----------------------------------------------------------------------------
                        _                              _ _       
        /\             | |                            | (_)      
       /  \   _ __   __| |_ __ ___  _ __ ___   ___  __| |_  __ _ 
      / /\ \ | '_ \ / _` | '__/ _ \| '_ ` _ \ / _ \/ _` | |/ _` |
     / ____ \| | | | (_| | | | (_) | | | | | |  __/ (_| | | (_| |
    /_/    \_\_| |_|\__,_|_|  \___/|_| |_| |_|\___|\__,_|_|\__,_|

    The contents of this file are subject to the Andromedia Public
	License Version 1.0 (the "License"); you may not use this file
	except in compliance with the License. You may obtain a copy of
	the License at http://www.andromedia.com/APL/

    Software distributed under the License is distributed on an
	"AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
	implied. See the License for the specific language governing
	rights and limitations under the License.

    The Original Code is Pueblo client code, released November 4, 1998.

    The Initial Developer of the Original Code is Andromedia Incorporated.
	Portions created by Andromedia are Copyright (C) 1998 Andromedia
	Incorporated.  All Rights Reserved.

	Andromedia Incorporated                         415.365.6700
	818 Mission Street - 2nd Floor                  415.365.6701 fax
	San Francisco, CA 94103

    Contributor(s):
	--------------------------------------------------------------------------
	   Chaco team:  Dan Greening, Glenn Crocker, Jim Doubek,
	                Coyote Lussier, Pritham Shetty.

					Wrote and designed original codebase.

------------------------------------------------------------------------------

	Implementation of all thread entry functions.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChThreadMgr.cpp,v 2.6 1996/06/27 03:43:53 jimd Exp $

#include "grheader.h"

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#include <QvInfo.h>
#include <QvState.h>
#include "ChMaze.h"
#include "CvInstnc.h"


//////////////////////////////////////////////////////////////////////////////
////////////// Construction thread related methods
//////////////

long ChRenderContext::NumPendingConstructionThreads()
{
	if( IsThreaded() )
	{
		::EnterCriticalSection(&m_constructionCriticalSection );
	}
	// Number of threads
	long lCount = m_constructionThreadList.GetCount();

	if( IsThreaded() )
	{
		::LeaveCriticalSection(&m_constructionCriticalSection );
	}

	return lCount;
}

bool ChRenderContext::AddConstruction(ChQvInstance *pRoot )
{	
	bool boolFound = false;

	if( IsThreaded() )
	{
		::EnterCriticalSection(&m_constructionCriticalSection );
	}


	if(!m_constructionThreadList.IsEmpty())
	{
		boolFound =  (m_constructionThreadList.Find(pRoot) != 0);
	}

	if(!boolFound)
	{
		m_constructionThreadList.AddTail(pRoot);
		pRoot->Use(true);
	}


	if( IsThreaded() )
	{
		::LeaveCriticalSection(&m_constructionCriticalSection );
	}

	return !boolFound;
}

bool ChRenderContext::RemoveConstruction(ChQvInstance *pRoot )
{
	bool boolFound = false;
	::EnterCriticalSection(&m_constructionCriticalSection );

	if(!m_constructionThreadList.IsEmpty())
	{
		ChPosition pos = m_constructionThreadList.Find(pRoot);
		if(pos)
		{
			boolFound = true;

			m_constructionThreadList.Remove(pos);
			TRACE("Releasing construction tree\n");

			pRoot->Release(true);
		}
	}
	::LeaveCriticalSection(&m_constructionCriticalSection );
	
	return !boolFound;
}


ChRenderContext *ChRenderContext::StartConstruction(ChQvInstance *pRoot /*= 0*/)
{
	// If it's MT, spin a thread and build, otherwise, post ourselves the
	// build message
	if ( ContinueConstruction() )
	{
		if (!pRoot) pRoot = m_pRootInstance;

		// If this is a unique construction add it to the list and update the
		// use count
		if(pRoot)
		{
			if ( AddConstruction( pRoot ) )
			{

				if( IsThreaded() )
				{
					ChUnderConstruction	*pProject = new  ChUnderConstruction(this, pRoot);

					CWinThread *pConstructionThread = ::AfxBeginThread(ConstructionThread, 
												(void*)pProject ); //, THREAD_PRIORITY_BELOW_NORMAL ); 
					ASSERT( pConstructionThread );
				}
				else
				{

					// Post message to wnd to say we're ready to build
					//#pragma message("nonthreaded not done")
					ConstructScene( pRoot );
				}
			}
		}
	}
	return this;
}

bool ChRenderContext::ConstructScene(ChQvInstance *pRoot)
{
	// Traverse the instance tree, drawing the shapes
	// !!!!! TODO
	// reset work counter and timers for non MT
	ASSERT( pRoot );

	ChConstructionIterator drawIt(this);


	drawIt.Attach(pRoot);
	drawIt.Iterate();

	if ( ContinueConstruction() )
	{
		LockScene();
		SetDirty();		  // force the draw
		UnlockScene();
	}

	// I am done remove it from the list and release
	RemoveConstruction( pRoot );

	return drawIt.IsCompleted();  // will only be incomplete if non MT
}

//////////////////////////////////////////////////////////////////////////////
////////////// Reconstruction thread related methods
//////////////

bool ChRenderContext::AddSynchReconstruction(int iWork)
{
	if(m_iTotalWork + iWork <= MaxWorkPerRender || m_iTotalWork == 0)
	{
		m_iTotalWork += iWork;
		return true;
	}
	return false;
}

bool ChRenderContext::AddReconstruction(ChQvInstance *pInst)
{	
	bool boolFound = false;

	::EnterCriticalSection(&m_reconstructionCriticalSection );


	if(!m_reconstructionThreadList.IsEmpty())
	{
		boolFound =  (m_reconstructionThreadList.Find(pInst) != 0);
	}
	if(!boolFound)
	{
		m_reconstructionThreadList.AddTail(pInst);
		pInst->Use(true);
	}


	::LeaveCriticalSection(&m_reconstructionCriticalSection );

	if ( !boolFound )
	{ // Notify thread to procees the reconstruction request

		::SetEvent( m_hReconstructEvents[reconstructInstance] );
		
	}
	
	return !boolFound;
}

bool ChRenderContext::RemoveReconstruction(ChQvInstance *pInst)
{
	bool boolFound = false;
	::EnterCriticalSection(&m_reconstructionCriticalSection );

	if(!m_reconstructionThreadList.IsEmpty())
	{
		ChPosition pos = m_reconstructionThreadList.Find(pInst);
		if(pos)
		{
			boolFound = true;

			m_reconstructionThreadList.Remove(pos);
			pInst->Release(true);
		}
	}
	::LeaveCriticalSection(&m_reconstructionCriticalSection );
	
	return !boolFound;
}

ChQvInstance * ChRenderContext::GetNextReconstruction(bool boolRemove /* = false */)
{
	// Fetches - but DOES NOT REMOVE next reconstruction to do unless requested
	ChQvInstance *pInst = 0;

	::EnterCriticalSection(&m_reconstructionCriticalSection );

	if(!m_reconstructionThreadList.IsEmpty())
	{
		pInst = m_reconstructionThreadList.GetHead();
		if(boolRemove)
		{
			m_reconstructionThreadList.RemoveHead();
			pInst->Release(true);
		}
	}

	::LeaveCriticalSection(&m_reconstructionCriticalSection );
	
	return pInst;
}

void ChRenderContext::ClearReconstruction( )
{

	::EnterCriticalSection(&m_reconstructionCriticalSection );
	ChQvInstance *pInst = 0;

	while(!m_reconstructionThreadList.IsEmpty())
	{
		//m_reconstructions.Empty();
		pInst = m_reconstructionThreadList.RemoveHead();
		pInst->Release(true);
	}
	::LeaveCriticalSection(&m_reconstructionCriticalSection );
}


void ChRenderContext::LockReconstruction()
{
	::EnterCriticalSection(&m_reconstructionCriticalSection );
}
void ChRenderContext::UnlockReconstruction()
{
	::LeaveCriticalSection(&m_reconstructionCriticalSection );
}

void ChRenderContext::LowerConstructionThreads(bool)
{
}

#endif // rlab


