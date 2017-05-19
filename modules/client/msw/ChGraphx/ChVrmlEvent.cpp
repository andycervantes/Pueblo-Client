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

	Implementation for WM event processing in VRML/RenderLab

----------------------------------------------------------------------------*/

#include "grheader.h"
#ifdef CH_MSW
#include <windows.h>
#endif
#ifdef HUGE
#undef HUGE
#endif
#include "ChVrmlEvent.h"
#include "QvNode.h"
#include "QvField.h"

// Class ChIVrmlEvent

ChIVrmlEvent::ChIVrmlEvent() :
	m_eventType(ChVRMLEvent::invalid),
	m_dataSize(0),
	m_bytes(0),
	m_eventTime(0),
	m_nextEvent(0)
{
	
};

ChIVrmlEvent::ChIVrmlEvent(const ChVRMLEvent::type theType, const string &name) :
	m_eventType(theType),
	m_dataSize(0),
	m_bytes(0),
	m_eventTime(0),
	m_nextEvent(0),
	m_eventName(name)
{
	
};

ChIVrmlEvent::~ChIVrmlEvent()
{
	m_dataSize = 0;
	delete [] m_bytes;
	m_bytes = 0;
}

QvField::type ChIVrmlEvent::GetFieldType()
{
	switch (m_eventType)
	{
		case ChVRMLEvent::SFBitMask:
			return QvField::typeQvSFBitMask; 
		case ChVRMLEvent::SFBool:
			return QvField::typeQvSFBool; 
		case ChVRMLEvent::SFColor:
			return QvField::typeQvSFColor; 
		case ChVRMLEvent::SFEnum:
			return QvField::typeQvSFEnum; 
		case ChVRMLEvent::SFFloat:
			return QvField::typeQvSFFloat; 
		case ChVRMLEvent::SFImage:
			return QvField::typeQvSFImage; 
		case ChVRMLEvent::SFLong:
			return QvField::typeQvSFLong; 
		case ChVRMLEvent::SFMatrix:
			return QvField::typeQvSFMatrix; 
		case ChVRMLEvent::SFNode:
			return QvField::typeQvSFNode; 
		case ChVRMLEvent::SFRotation:
			return QvField::typeQvSFRotation; 
		case ChVRMLEvent::SFString:
			return QvField::typeQvSFString; 
		case ChVRMLEvent::SFVec2f:
			return QvField::typeQvSFVec2f; 
		case ChVRMLEvent::SFVec3f:
			return QvField::typeQvSFVec3f; 
		case ChVRMLEvent::SFTime:
			return QvField::typeQvSFTime; 
		case ChVRMLEvent::SFPick:
			return QvField::typeQvSFPick; 
		case ChVRMLEvent::SFProximity:
			return QvField::typeQvSFProximity; 
		case ChVRMLEvent::SFCollision:
			return QvField::typeQvSFCollision; 
		case ChVRMLEvent::MFBitMask:
			return QvField::typeQvMFBitMask; 
		case ChVRMLEvent::MFBool:
			return QvField::typeQvMFBool; 
		case ChVRMLEvent::MFColor:
			return QvField::typeQvMFColor; 
		case ChVRMLEvent::MFEnum:
			return QvField::typeQvMFEnum; 
		case ChVRMLEvent::MFFloat:
			return QvField::typeQvMFFloat; 
		case ChVRMLEvent::MFImage:
			return QvField::typeQvMFImage; 
		case ChVRMLEvent::MFLong:
			return QvField::typeQvMFLong; 
		case ChVRMLEvent::MFMatrix:
			return QvField::typeQvMFMatrix; 
		case ChVRMLEvent::MFNode:
			return QvField::typeQvMFNode; 
		case ChVRMLEvent::MFRotation:
			return QvField::typeQvMFRotation; 
		case ChVRMLEvent::MFString:
			return QvField::typeQvMFString; 
		case ChVRMLEvent::MFVec2f:
			return QvField::typeQvMFVec2f; 
		case ChVRMLEvent::MFVec3f:
			return QvField::typeQvMFVec3f; 
		case ChVRMLEvent::MFTime:
			return QvField::typeQvMFTime; 
		case ChVRMLEvent::MFPick:
			return QvField::typeQvMFPick; 
		case ChVRMLEvent::MFProximity:
			return QvField::typeQvMFProximity; 
		case ChVRMLEvent::MFCollision:
			return QvField::typeQvMFCollision;
	
	}
	return QvField::typeInvalid;
}

ChIVrmlEvent * ChIVrmlEvent::Create(const ChVRMLEvent &anEvent)
{
	ChIVrmlEvent *pList = 0, *pTail = 0, *pEvent = 0;
	const ChVRMLEvent *pSrc	 = &anEvent;

	while(pSrc)
	{
		switch(pSrc->eventType)
		{
			case  ChVRMLEvent::SFNode :
			{
				pEvent = (ChIVrmlEvent *)(new ChNodeEvent(*pSrc));
				break;
			}

			default:
			{
				break;
			}
		}

		if(pList)
		{
			pTail->Append(pEvent);
			pTail = pEvent;
		}
		else
		{
			pList = pTail = pEvent;
		}
		pSrc = pSrc->nextEvent;
	} 

	return pList;
}

ChIVrmlEvent * ChIVrmlEvent::Append(ChIVrmlEvent * pTail )
{
	m_nextEvent = pTail;
	return pTail;		// This lets you do a->append()->append() && also allows Append(0) to delete tail	
}

void ChIVrmlEvent::Copy(const ChVRMLEvent &anEvent)
{
	m_nextEvent = 0;
	m_eventType = anEvent.eventType;
	m_eventTime= anEvent.eventTime;
	m_eventName= anEvent.eventName;
	m_dataSize= anEvent.dataSize;
	m_bytes = new char[m_dataSize];

	SetBytes((char*)anEvent.bytes);

}

void ChIVrmlEvent::Copy(const ChIVrmlEvent &anEvent)
{
	m_nextEvent = 0;
	m_eventType = anEvent.m_eventType;
	m_eventTime= anEvent.m_eventTime;
	m_eventName= anEvent.m_eventName;
	m_dataSize= anEvent.m_dataSize;
	m_bytes = new char[m_dataSize];

	SetBytes(anEvent.m_bytes);

}

void ChIVrmlEvent::SetBytes(const char *bytes)
{
	memmove(m_bytes, bytes, m_dataSize);
} 
	
bool ChIVrmlEvent::SetSize(int iNewDataSize)
{
	if(iNewDataSize == m_dataSize) return true;	// no need to do anything
	char * pNew = new char [iNewDataSize];
	if(!pNew) return 0; // oughta throw
	int iSize = min(iNewDataSize, m_dataSize);	// truncate if new is smaller
	if(iSize > 0)
	{ 
		memmove(pNew, m_bytes, iSize);
	}
	delete [] m_bytes;
	m_bytes = pNew;
	m_dataSize = iNewDataSize;
	return true;
}

// ChNodeEvent

ChNodeEvent::ChNodeEvent(const string &name, ChNode* const value) : 
	ChIVrmlEvent(ChVRMLEvent::SFNode, name)
{
	AppendData(value);
}

ChNodeEvent::ChNodeEvent(const string &name, const int count, ChNode **values) :
	ChIVrmlEvent(ChVRMLEvent::SFNode, name)
{
	AppendData(count, values);
}

ChNodeEvent::ChNodeEvent(const ChNodeEvent &event) : ChIVrmlEvent()
{
	Copy(event);
};

ChNodeEvent::ChNodeEvent(const ChVRMLEvent &event) : ChIVrmlEvent()
{
	Copy(event);
};

ChNodeEvent::~ChNodeEvent()
{
	int num = m_dataSize / sizeof(ChNode*);
	for(int i = 0; i < num; i++)
	{
		Release(i);
	}
	// Super class will delete bytes

}
int ChNodeEvent::AppendData(ChNode* const value)
{
	int iNext = GetCount();	 // 1 ptr per datum
	if(!SetSize(m_dataSize + (sizeof(ChNode*)))) return false;

	ChNode **pData = (ChNode**)m_bytes;
	pData += iNext;

	*pData = value;
	((QvNode*)value)->Use();
	return 1;
};             
int ChNodeEvent::AppendData(const int count,  ChNode ** values)
{
	int iNext = GetCount();
	if(!SetSize(m_dataSize + count * (sizeof(ChNode *)))) return false;
	ChNode **pData = (ChNode **)m_bytes;
	pData += iNext;

	for(int i = 0; i < count * 4; i++)
	{
		((QvNode*)(*values))->Use();
		*pData++ = *values++;
	}

	return 1;
} 

 
int ChNodeEvent::GetCount()
{
	return m_dataSize / (sizeof(ChNode *));
}


bool ChNodeEvent::GetValue(const int index, ChNode * &value)
{
	if(index >= GetCount()) return false;
	ChNode* *pData = (ChNode**)m_bytes;

	pData += index;
	value = *pData;
	return true;
}

bool ChNodeEvent::GetValue(ChNode * &value)
{
	return GetValue(0, value);
}

void ChNodeEvent::Use()
{
	int num = m_dataSize / sizeof(ChNode*);
	for(int i = 0; i < num; i++) Use(i);
}

void ChNodeEvent::Use(int index)
{
	QvNode *pNode = ((QvNode**)m_bytes)[index];
	if(pNode) pNode->Use();
}

void ChNodeEvent::Release(int index)
{
	QvNode *pNode = ((QvNode**)m_bytes)[index];
	if(pNode) pNode->Release();
}

void ChNodeEvent::SetBytes(const char *bytes)
{
	memmove(m_bytes, bytes, m_dataSize);
	Use();
} 


// ChRotationEvent
ChRotationEvent::ChRotationEvent(const string &name, float axis[3], float angle) : 
	ChIVrmlEvent(ChVRMLEvent::SFRotation, name)
{
	AppendData(axis, angle);
}
ChRotationEvent::ChRotationEvent(const string &name, float x, float y, float z, float angle) : 
	ChIVrmlEvent(ChVRMLEvent::SFRotation, name)
{
	AppendData(x, y, z, angle);
}

ChRotationEvent::ChRotationEvent(const string &name, int count, float *values) :
	ChIVrmlEvent(ChVRMLEvent::SFRotation, name)
{
	AppendData(count, values);
}

ChRotationEvent::ChRotationEvent(const ChRotationEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChRotationEvent::ChRotationEvent(const ChVRMLEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChRotationEvent::~ChRotationEvent() {}

int ChRotationEvent::AppendData(float axis[3], float angle)
{
	return AppendData(axis[0], axis[1], axis[2], angle);
}
             
int ChRotationEvent::AppendData(float x, float y, float z, float angle)
{
	int iNext = GetCount() * 4;	 // 4 floats per datum
	if(!SetSize(m_dataSize + (sizeof(float) * 4))) return false;

	float *pData = (float*)m_bytes;
	pData += iNext;

	*pData++ = x;
	*pData++ = y;
	*pData++ = z;
	*pData = angle;
	return 1;
} 
int ChRotationEvent::AppendData(int count, float *values)
{
	int iNext = GetCount() * 4;
	if(!SetSize(m_dataSize + count * (sizeof(float) * 4))) return false;
	float *pData = (float*)m_bytes;
	pData += iNext;

	for(int i = 0; i < count * 4; i++)
	{
		*pData++ = *values++;
	}

	return 1;
} 
int ChRotationEvent::GetCount()
{
	return m_dataSize / (sizeof(float) * 4);
}
bool ChRotationEvent::GetValue(int index, float axis[3], float &angle)
{
	if(index >= GetCount()) return false;
	float *pData = (float*)m_bytes;

	pData += index;
	for(int i = 0; i < 3; i++) axis[i] = *pData++;
	angle = *pData;
	return true;
}
bool ChRotationEvent::GetValue(float axis[3], float &angle)
{
	return GetValue(0, axis, angle);
}

// ChVec3fEvent
ChVec3fEvent::ChVec3fEvent(const string &name, float vec[3]) : 
	ChIVrmlEvent(ChVRMLEvent::SFVec3f, name)
{
	AppendData(vec);
}
ChVec3fEvent::ChVec3fEvent(const string &name, float x, float y, float z) : 
	ChIVrmlEvent(ChVRMLEvent::SFVec3f, name)
{
	AppendData(x, y, z);
}

ChVec3fEvent::ChVec3fEvent(const string &name, int count, float *values) :
	ChIVrmlEvent(ChVRMLEvent::SFVec3f, name)
{
	AppendData(count, values);
}

ChVec3fEvent::ChVec3fEvent(const ChVec3fEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChVec3fEvent::ChVec3fEvent(const ChVRMLEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChVec3fEvent::~ChVec3fEvent() {}

int ChVec3fEvent::AppendData(float vec[3])
{
	return AppendData(vec[0], vec[1], vec[2]);
}
             
int ChVec3fEvent::AppendData(float x, float y, float z)
{
	int iNext = GetCount() * 3;	 // 3 floats per datum
	if(!SetSize(m_dataSize + (sizeof(float) * 3))) return false;

	float *pData = (float*)m_bytes;
	pData += iNext;

	*pData++ = x;
	*pData++ = y;
	*pData++ = z;
	return 1;
} 
int ChVec3fEvent::AppendData(int count, float *values)
{
	int iNext = GetCount() * 3;
	if(!SetSize(m_dataSize + count * (sizeof(float) * 3))) return false;
	float *pData = (float*)m_bytes;
	pData += iNext;

	for(int i = 0; i < count * 3; i++)
	{
		*pData++ = *values++;
	}

	return 1;
} 
int ChVec3fEvent::GetCount()
{
	return m_dataSize / (sizeof(float) * 3);
}
bool ChVec3fEvent::GetValue(int index, float vec[3])
{
	if(index >= GetCount()) return false;
	float *pData = (float*)m_bytes;

	pData += index;
	for(int i = 0; i < 3; i++) vec[i] = *pData++;
	return true;
}
bool ChVec3fEvent::GetValue(float vec[3])
{
	return GetValue(0, vec);
}


// ChLongEvent
ChLongEvent::ChLongEvent(const string &name, long value) : 
	ChIVrmlEvent(ChVRMLEvent::SFLong, name)
{
	AppendData(value);
}

ChLongEvent::ChLongEvent(const string &name, int count, long *values) :
	ChIVrmlEvent(ChVRMLEvent::SFLong, name)
{
	AppendData(count, values);
}

ChLongEvent::ChLongEvent(const ChLongEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChLongEvent::ChLongEvent(const ChVRMLEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChLongEvent::~ChLongEvent() {}

             
int ChLongEvent::AppendData(long value)
{
	int iNext = GetCount();	 // 1 longs per datum
	if(!SetSize(m_dataSize + (sizeof(long)))) return false;

	long *pData = (long*)m_bytes;
	pData += iNext;

	*pData = value;
	return 1;
} 
int ChLongEvent::AppendData(int count, long *values)
{
	int iNext = GetCount();
	if(!SetSize(m_dataSize + count * (sizeof(long)))) return false;
	long *pData = (long*)m_bytes;
	pData += iNext;

	for(int i = 0; i < count; i++)
	{
		*pData++ = *values++;
	}

	return 1;
} 
int ChLongEvent::GetCount()
{
	return m_dataSize / (sizeof(long));
}
bool ChLongEvent::GetValue(int index, long &value)
{
	if(index >= GetCount()) return false;
	long *pData = (long*)m_bytes;

	pData += index;
	value = *pData;
	return true;
}
bool ChLongEvent::GetValue(long &value)
{
	return GetValue(0, value);
}

// ChTimeEvent

ChTimeEvent::ChTimeEvent(const string &name, double value) : 
	ChIVrmlEvent(ChVRMLEvent::SFTime, name)
{
	AppendData(value);
}

ChTimeEvent::ChTimeEvent(const string &name, int count, double *values) :
	ChIVrmlEvent(ChVRMLEvent::SFTime, name)
{
	AppendData(count, values);
}

ChTimeEvent::ChTimeEvent(const ChTimeEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChTimeEvent::ChTimeEvent(const ChVRMLEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChTimeEvent::~ChTimeEvent() {}

             
int ChTimeEvent::AppendData(double value)
{
	int iNext = GetCount();	 // 1 doubles per datum
	if(!SetSize(m_dataSize + (sizeof(double)))) return false;

	double *pData = (double*)m_bytes;
	pData += iNext;

	*pData = value;
	return 1;
}
 
int ChTimeEvent::AppendData(int count, double *values)
{
	int iNext = GetCount();
	if(!SetSize(m_dataSize + count * (sizeof(double)))) return false;
	double *pData = (double*)m_bytes;
	pData += iNext;

	for(int i = 0; i < count; i++)
	{
		*pData++ = *values++;
	}

	return 1;
} 
int ChTimeEvent::GetCount()
{
	return m_dataSize / (sizeof(double));
}
bool ChTimeEvent::GetValue(int index, double &value)
{
	if(index >= GetCount()) return false;
	double *pData = (double*)m_bytes;

	pData += index;
	value = *pData;
	return true;
}
bool ChTimeEvent::GetValue(double &value)
{
	return GetValue(0, value);
}
// ChBoolEvent
ChBoolEvent::ChBoolEvent(const string &name, bool value) : 
	ChIVrmlEvent(ChVRMLEvent::SFBool, name)
{
	AppendData(value);
}

ChBoolEvent::ChBoolEvent(const string &name, int count, bool *values) :
	ChIVrmlEvent(ChVRMLEvent::SFBool, name)
{
	AppendData(count, values);
}

ChBoolEvent::ChBoolEvent(const ChBoolEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChBoolEvent::ChBoolEvent(const ChVRMLEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChBoolEvent::~ChBoolEvent() {}

             
int ChBoolEvent::AppendData(bool value)
{
	int iNext = GetCount();	 // 1 bools per datum
	if(!SetSize(m_dataSize + (sizeof(bool)))) return false;

	bool *pData = (bool*)m_bytes;
	pData += iNext;

	*pData = value;
	return 1;
} 
int ChBoolEvent::AppendData(int count, bool *values)
{
	int iNext = GetCount();
	if(!SetSize(m_dataSize + count * (sizeof(bool)))) return false;
	bool *pData = (bool*)m_bytes;
	pData += iNext;

	for(int i = 0; i < count; i++)
	{
		*pData++ = *values++;
	}

	return 1;
} 
int ChBoolEvent::GetCount()
{
	return m_dataSize / (sizeof(bool));
}
bool ChBoolEvent::GetValue(int index, bool &value)
{
	if(index >= GetCount()) return false;
	bool *pData = (bool*)m_bytes;

	pData += index;
	value = *pData;
	return true;
}
bool ChBoolEvent::GetValue(bool &value)
{
	return GetValue(0, value);
}
// ChFloatEvent
ChFloatEvent::ChFloatEvent(const string &name, float value) : 
	ChIVrmlEvent(ChVRMLEvent::SFBool, name)
{
	AppendData(value);
}

ChFloatEvent::ChFloatEvent(const string &name, int count, float *values) :
	ChIVrmlEvent(ChVRMLEvent::SFBool, name)
{
	AppendData(count, values);
}

ChFloatEvent::ChFloatEvent(const ChFloatEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChFloatEvent::ChFloatEvent(const ChVRMLEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChFloatEvent::~ChFloatEvent() {}

             
int ChFloatEvent::AppendData(float value)
{
	int iNext = GetCount();	 // 1 floats per datum
	if(!SetSize(m_dataSize + (sizeof(float)))) return false;

	float *pData = (float*)m_bytes;
	pData += iNext;

	*pData = value;
	return 1;
} 
int ChFloatEvent::AppendData(int count, float *values)
{
	int iNext = GetCount();
	if(!SetSize(m_dataSize + count * (sizeof(float)))) return false;
	float *pData = (float*)m_bytes;
	pData += iNext;

	for(int i = 0; i < count; i++)
	{
		*pData++ = *values++;
	}

	return 1;
} 
int ChFloatEvent::GetCount()
{
	return m_dataSize / (sizeof(float));
}
bool ChFloatEvent::GetValue(int index, float &value)
{
	if(index >= GetCount()) return false;
	float *pData = (float*)m_bytes;

	pData += index;
	value = *pData;
	return true;
}
bool ChFloatEvent::GetValue(float &value)
{
	return GetValue(0, value);
}
// ChMatrixEvent
ChMatrixEvent::ChMatrixEvent(const string &name, ChVrmlMatrix &mat) : 
	ChIVrmlEvent(ChVRMLEvent::SFVec3f, name)
{
	AppendData(mat);
}

ChMatrixEvent::ChMatrixEvent(const string &name, int count, float *values) :
	ChIVrmlEvent(ChVRMLEvent::SFVec3f, name)
{
	AppendData(count, values);
}

ChMatrixEvent::ChMatrixEvent(const ChMatrixEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChMatrixEvent::ChMatrixEvent(const ChVRMLEvent &event) : 
	ChIVrmlEvent()
{
	Copy(event);
}

ChMatrixEvent::~ChMatrixEvent() {}

             
int ChMatrixEvent::AppendData(ChVrmlMatrix &mat)
{
	int iNext = GetCount() * 16;	 // 16 floats per datum
	if(!SetSize(m_dataSize + (sizeof(float) * 16))) return false;

	float *pData = (float*)m_bytes;
	pData += iNext;

	memcpy(pData, &mat, 16 * sizeof(float));
	return 1;
} 
int ChMatrixEvent::AppendData(int count, float *values)
{
	int iNext = GetCount() * 16;
	if(!SetSize(m_dataSize + count * (sizeof(float) * 16))) return false;
	float *pData = (float*)m_bytes;
	pData += iNext;

	for(int i = 0; i < count * 16; i++)
	{
		*pData++ = *values++;
	}

	return 1;
} 
int ChMatrixEvent::GetCount()
{
	return m_dataSize / (sizeof(float) * 16);
}
bool ChMatrixEvent::GetValue(int index, ChVrmlMatrix &mat)
{
	if(index >= GetCount()) return false;
	float *pData = (float*)m_bytes;

	pData += index;
	float *vec = (float*)&mat;
	for(int i = 0; i < 16; i++) vec[i] = *pData++;
	return true;
}
bool ChMatrixEvent::GetValue(ChVrmlMatrix &mat)
{
	return GetValue(0, mat);
}

