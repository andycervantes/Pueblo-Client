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

	Declaration for the ChQvRenderData class and derivations, 
	which are used to store renderer specific object data for 3d graphics renderers 
	associated with QvNodes. 

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChScriptData.h,v 2.2 1996/06/27 03:43:47 jimd Exp $
//
#if !defined( _CHSCRIPTDATA_H )
#define _CHSCRIPTDATA_H

#include "ChRenderData.h"


/*----------------------------------------------------------------------------
	ChQvScriptRenderData class - all script or animation node types
----------------------------------------------------------------------------*/

class ChQvScriptRenderData : public ChQvRenderBaseData
{	   
							

	private:
		//static ChVrmlDispatcher		*m_pDispatcher;

	public:
		ChQvScriptRenderData(QvNode* pNode);
		virtual ~ChQvScriptRenderData();
		
		// VRML 2.0 Event Handlers

 		//virtual ChVrmlDispatcher *GetDispatcher() {return m_pDispatcher;};

		void Init();

		static void Term();

		virtual void AddInstance(ChQvInstance *pTarget);

};

class ChQvSpinRenderData : public ChQvScriptRenderData
{	   
							

	private:
		//static ChVrmlDispatcher		*m_pDispatcher;
		QvNode *m_pTarget;
		float m_step;
		GxTransform3Wf	m_spinTransform;

	public:
		ChQvSpinRenderData(QvNode* pNode);
		virtual ~ChQvSpinRenderData();
		
		// VRML 2.0 Event Handlers

 		//virtual ChVrmlDispatcher *GetDispatcher() {return m_pDispatcher;};

		void Init();

		static void Term();

		virtual void AddInstance(ChQvInstance *pTarget);

		void Spin(ChQvInstance *pTarget);

};

// An iterator for installing scripts to the renderdata of a target
#if defined(CH_USE_RLAB) || defined(CH_USE_D3D)
class MyInstallScriptIterator: public 	  ChQvRenderBaseDataIterator
{
	public:
		MyInstallScriptIterator( const ChQvRenderBaseData& rbd, ChQvInstance *pInst ) : 
			ChQvRenderBaseDataIterator(rbd), m_pInst(pInst) {};


		virtual int DoScript(ChQvScriptRenderData& script)
		{
			script.AddInstance(m_pInst);
			return true;
		};


   protected:

   private:
		ChQvInstance *m_pInst;
											/* Disable copy constructor and
												assignment operator */

		inline MyInstallScriptIterator( const MyInstallScriptIterator& ) {}
		inline MyInstallScriptIterator& operator=( const MyInstallScriptIterator& )
      			{
      				return *this;
      			}
};
#endif

#endif // _CHSCRIPTDATA_H
