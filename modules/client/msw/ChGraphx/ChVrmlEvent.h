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

	Implementation for collision detection in VRML/RenderLab

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChVrmlEvent.h,v 2.11 1996/08/22 22:45:16 jimd Exp $

#if !defined( _CHVRMLEVENT_H_ )
#define _CHVRMLEVENT_H_
#include "grheader.h"
#ifdef CH_MSW
#include <windows.h>
#endif
#ifdef HUGE
#undef HUGE
#endif

#if defined(CH_VRML_EVENTS) && defined( CH_VRML_PLUGIN )
#include <ChIVRMLViewer.h>
#else
#include "VrmlEvent.h"
#endif

#include <QvField.h>

class ChNode;
class ChVrmlBrowser;
class ChIVrmlEvent;


// Note that ChVrmlEvent is a local class only; event structs are copied across RPC
// including the pointers' contents. 
class ChIVrmlEvent
{
	public:



	protected:
		ChIVrmlEvent *m_nextEvent;
		ChVRMLEvent::type 		m_eventType;
		double 		m_eventTime;
		string 		m_eventName;
		int 		m_dataSize;
		char		*m_bytes;

	public:
		ChIVrmlEvent();
		ChIVrmlEvent(const ChVRMLEvent::type theType, const string &name);
		virtual ~ChIVrmlEvent();

		static ChIVrmlEvent * Create(const ChVRMLEvent &anEvent);
		ChIVrmlEvent * Append(ChIVrmlEvent * pEvent );

		inline ChVRMLEvent::type GetType() {return ChVRMLEvent::type(m_eventType & 0x7fffffff);};
		inline ChIVrmlEvent* GetNextEvent() {return m_nextEvent;};
 		inline char * GetBytes() {return m_bytes;};

		// Also need this to make OLE transportable list
		ChVRMLEvent * EventStruct();	// This does -not- bump usage counts

		inline string &GetName() { return m_eventName; };

		inline void SetMultiple(bool boolMulti = false)
		{
			if(boolMulti)
				m_eventType = (ChVRMLEvent::type)(0x8000 | m_eventType);
			else						  
				m_eventType = (ChVRMLEvent::type)(~0x8000 & m_eventType);
		}

		static bool IsMultiple(ChVRMLEvent::type aType) {return !!(aType & 0x8000);};
		bool IsMultiple() { return IsMultiple(m_eventType);};
		virtual int GetCount() {return 1;};

		QvField::type GetFieldType();



	protected:

		virtual void SetBytes(const char *someBytes);	// 
		void Copy(const ChVRMLEvent &anEvent);	
		void Copy(const ChIVrmlEvent &anEvent);
		bool SetSize(int iNewDataSize);
	
};

class ChFloatEvent : public ChIVrmlEvent
{
	public:
		ChFloatEvent(const string &name, float value);
		ChFloatEvent(const string &name, int count, float *values);
		ChFloatEvent(const ChFloatEvent &event);
		ChFloatEvent(const ChVRMLEvent &event);
		virtual ~ChFloatEvent();

		int AppendData(float value);             
		int AppendData(int count, float *values); 
		virtual int GetCount();
		bool GetValue(int index, float &value);
		bool GetValue(float &value);

};


class ChNodeEvent : public ChIVrmlEvent
{
	public:
		ChNodeEvent(const string &name, ChNode * const value);	
		ChNodeEvent(const string &name, const int count,  ChNode **values);
		ChNodeEvent(const ChNodeEvent &event);
		ChNodeEvent(const ChVRMLEvent &event);
		virtual ~ChNodeEvent();

		int AppendData(ChNode* const value);             
		int AppendData(const int count, ChNode **values); 
		virtual int GetCount();
		bool GetValue(const int index, ChNode * &value);
		bool GetValue(ChNode * &value);
		void Use();

		
	protected:
		void Use(int index);
		void Release(int index);
		virtual void SetBytes(const char *someBytes);	// 
		
};

class ChRotationEvent : public ChIVrmlEvent
{
	public:
		ChRotationEvent(const string &name, float axis[3], float angle);
		ChRotationEvent(const string &name, int count, float *values);
		ChRotationEvent(const ChRotationEvent &event);
		ChRotationEvent(const ChVRMLEvent &event);
		ChRotationEvent(const string &name, float x, float y, float z, float angle);
		virtual ~ChRotationEvent();

		int AppendData(float axis[3], float angle);             
		int AppendData(float x, float y, float z, float angle); 
		int AppendData(int count, float *values); 
		virtual int GetCount();
		bool GetValue(float axis[3], float &angle);
		bool GetValue(int i, float axis[3], float &angle);
};

class ChVec3fEvent : public ChIVrmlEvent
{
	public:
		ChVec3fEvent(const string &name, float vec[3]);
		ChVec3fEvent(const string &name, int count, float *values);
		ChVec3fEvent(const ChVec3fEvent &event);
		ChVec3fEvent(const ChVRMLEvent &event);
		ChVec3fEvent(const string &name, float x, float y, float z);
		virtual ~ChVec3fEvent();

		int AppendData(float vec[3]);             
		int AppendData(float x, float y, float z); 
		int AppendData(int count, float *values); 
		virtual int GetCount();
		bool GetValue(float vec[3]);
		bool GetValue(int i, float vec[3]);
};

class ChLongEvent : public ChIVrmlEvent
{
	public:
		ChLongEvent(const string &name, long value);
		ChLongEvent(const string &name, int count, long *values);
		ChLongEvent(const ChLongEvent &event);
		ChLongEvent(const ChVRMLEvent &event);
		virtual ~ChLongEvent();

		int AppendData(long value);             
		int AppendData(int count, long *values); 
		virtual int GetCount();
		bool GetValue(int index, long &value);
		bool GetValue(long &value);
};

class ChTimeEvent : public ChIVrmlEvent
{
	public:
		ChTimeEvent(const string &name, double value);
		ChTimeEvent(const string &name, int count, double *values);
		ChTimeEvent(const ChTimeEvent &event);
		ChTimeEvent(const ChVRMLEvent &event);
		virtual ~ChTimeEvent();

		int AppendData(double value);             
		int AppendData(int count, double *values); 
		virtual int GetCount();
		bool GetValue(int index, double &value);
		bool GetValue(double &value);
};

class ChBoolEvent : public ChIVrmlEvent
{
	public:
		ChBoolEvent(const string &name, bool value);
		ChBoolEvent(const string &name, int count, bool *values);
		ChBoolEvent(const ChBoolEvent &event);
		ChBoolEvent(const ChVRMLEvent &event);
		virtual ~ChBoolEvent();

		int AppendData(bool value);             
		int AppendData(int count, bool *values); 
		virtual int GetCount();
		bool GetValue(int index, bool &value);
		bool GetValue(bool &value);
};

typedef float ChVrmlMatrix[4][4];
class ChMatrixEvent : public ChIVrmlEvent
{
	public:
		ChMatrixEvent(const string &name, ChVrmlMatrix &value);
		ChMatrixEvent(const string &name, int count, float *values);
		ChMatrixEvent(const ChMatrixEvent &event);
		ChMatrixEvent(const ChVRMLEvent &event);
		virtual ~ChMatrixEvent();

		int AppendData(ChVrmlMatrix &value);             
		int AppendData(int count, float *values); 
		virtual int GetCount();
		bool GetValue(int index, ChVrmlMatrix &value);
		bool GetValue(ChVrmlMatrix &value);
};


// TODO: all the other types

// ---------------

class ChApplet;

class  ChEventMsg
{
	protected:
		ChNode 			*m_pNode;
		ChApplet 		*m_pApplet;
		ChIVrmlEvent	*m_pEvent;

	public:
		ChEventMsg(ChNode *pNode, ChApplet *pApplet, ChIVrmlEvent* pEvent) :
			m_pNode(pNode),
			m_pApplet(pApplet),
			m_pEvent(pEvent)
			{ };
		~ChEventMsg() {};

		inline ChNode *GetNode() { return m_pNode; }
		inline ChApplet *GetApplet() { return m_pApplet; }
		inline ChIVrmlEvent *GetEvent() { return m_pEvent; }
};

#endif // _CHVRMLEVENT_H_
