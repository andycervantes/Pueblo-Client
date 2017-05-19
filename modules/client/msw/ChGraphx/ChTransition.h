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

----------------------------------------------------------------------------*/

#if !defined( _CHTRANSITION_H_ )
#define _CHTRANSITION_H_

class ChStateTransition
{
	public:
		// Designed to be in a matrix indexed by 
		//	int	iState;
		//	int iEvent;
		typedef bool (ChStateTransition::*ChTransitionActionHandler)();
		class transition
		{
			public:	
				int m_iNewState;
				ChTransitionActionHandler	m_action;
				transition () {};
				transition (int iNewState, ChTransitionActionHandler	action) :
					m_iNewState(iNewState), m_action(action) {};


		};

	protected:
		int 			m_iState;
		chuint32		m_uData;
		int				m_numStates;
		int 			m_numEvents;
		transition		*m_pMatrix;

	public:
		ChStateTransition(int numStates, int numEvents = 1);
		ChStateTransition();
		virtual ~ChStateTransition();

		inline void SetState(int iState = 0) { m_iState = iState; };   // Mainly to reset - don't abuse!
		inline void SetData(chuint32 uData = 0) { m_uData = uData; };

		bool ProcessKeyEvent(int keyMsg, int key, chuint32 modifiers);
		bool ProcessMouseEvent(int mouseMsg, int x, int y, chuint32 uFlags);
		bool ProcessEvent(int iMsg, void *pMsgData);
		bool SetCell( int iState, int iEvent, int iNewState, ChTransitionActionHandler	action)
		{
			return SetCell(iState, iEvent, transition(iNewState, action));
		}
	protected:
		void Init();

		// Overrides
	public:
		virtual bool SetCell( int iState, int iEvent, const transition &trans);

	protected:
		virtual bool TranslateKeyEvent(int keyMsg, int key, chuint32 modifiers, int &event, chuint32 *&pData) = 0;
		virtual bool TranslateMouseEvent(int mouseMsg, int x, int y, chuint32 uFlags, int &event, chuint32 *&pData) = 0;
		virtual bool TranslateEvent(int iMsg, void *pMsgData,  int &event, chuint32 *&pData) = 0;
		

		virtual transition * GetMatrix() {return m_pMatrix;};
		virtual bool GrowMatrix(int numStates, int numEvents);

		// Default handler for null entries
		bool DefaultHandler() { return true; };		// does nothing except allow transition
		void InitCell(transition &cell, int iState)
		{
			cell.m_iNewState = iState;
			cell.m_action = DefaultHandler;
		}

		inline int index(int iState, int iEvent) {return iEvent * m_numStates + iState;};
};



#endif	// _CHTRANSITION_H_
