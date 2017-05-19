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

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChConstruct.cpp,v 1.6 1996/06/27 03:43:04 jimd Exp $

#include "grheader.h"

#if (defined(CH_USE_RLAB) || defined(CH_USE_D3D))
#include <QvInfo.h>
#include <QvState.h>
#include "ChMaze.h"
#include "CvInstnc.h"



UINT ConstructionThread( LPVOID pData )
{
	ChUnderConstruction	*pProject = (ChUnderConstruction	*)pData;

	TRACE( "Start construction thread.. \n" );

	// Do the work
	pProject->GetContext()->ConstructScene(pProject->GetRoot());

	// Send a event that I am terminating, this is used by the main
	// thread to block till the thread terminates.

	HANDLE hEvent = pProject->GetContext()->GetEndConstructEvent();

	delete pProject;

	TRACE( "End construction thread\n" );

	::SetEvent( hEvent );



	AfxEndThread( 0 );

	return 0;
}


UINT ReConstructInstanceThread( LPVOID pData )
{

	ChRenderContext	*pRndrContext = (ChRenderContext*)pData;

	TRACE( "Start Reconstruction thread.. \n" );

 	DWORD	dwStatus;

	while (WAIT_FAILED !=
			(dwStatus =
				::WaitForMultipleObjects( pRndrContext->GetTotalReConstructEvents(),
											pRndrContext->GetReConstructEvents(), false,
							   				INFINITE )))
	{
		DWORD				lEvent = dwStatus - WAIT_OBJECT_0;

 		if ( pRndrContext->TerminateReconstruct( lEvent ) )
		{
											// Delete the current thread
			TRACE( "End Reconstruction thread : Terminate on event\n" );
			// Notify that abort was done and it is now clear to proceed
			::SetEvent( pRndrContext->GetEndConstructEvent() );

			AfxEndThread( 0 );
			return ( 0 );
		}
		else if ( pRndrContext->AbortReconstruct( lEvent ) )
		{
											// cleanup the current reconstuct requests

			TRACE( "Aborting all Reconstruction requests \n" );

			pRndrContext->ClearReconstruction();

			// Notify that abort was done and it is now clear to proceed
			::SetEvent( pRndrContext->GetEndConstructEvent() );


		}
		else
		{   // should be construct event
			ChQvInstance *pInst;
	

			while ( pRndrContext->ContinueConstruction() 
						&& (pInst = pRndrContext->GetNextReconstruction( false )) )
			{
				//TRACE( "Starting  a new reconstruction\n" );
			 	pInst->Reconstruct( pRndrContext );
				pRndrContext->RemoveReconstruction(pInst);
			}
			// Force a redraw
			//pRndrContext->LockScene();
			//pRndrContext->SetDirty();
			//pRndrContext->UnlockScene();

		}


	}
	TRACE( "End Reconstruction thread : Terminate on failure\n" );


	AfxEndThread( 0 );

	return 0;
}


#endif // RLAB
