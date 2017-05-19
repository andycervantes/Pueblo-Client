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

	Contains the interface for the ChWorldInfo class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChWorld/ChWInfo.h,v 2.19 1996/09/30 19:50:09 pritham Exp $

#if !defined( _CHWINFO_H )
#define _CHWINFO_H

#include <ChWType.h>

class ChCore;
class ifstream;


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define WORLD_NAME_SEPARATOR		'/'


/*----------------------------------------------------------------------------
	ChWorldInfo class
----------------------------------------------------------------------------*/

class ChWorldInfo
{
	public:
		ChWorldInfo( const string& strCommand );
		ChWorldInfo( const string& strName, const string& strDesc,
						const string& strHost, chint16 sPort,
						const ChWorldType& type, ChLoginType login,
						const string& strUsername, const string& strPassword,
						const string& strHomePage );
		ChWorldInfo( const string& strName, const string& strDesc,
						const string& strHost, const string& strAddr,
						chint16 sPort, const ChWorldType& type,
						ChLoginType login, const string& strUsername,
						const string& strPassword, const string& strHomePage );
		
		ChWorldInfo( ifstream& ifile  );

		virtual ~ChWorldInfo() {}

		inline bool IsValid() { return m_boolValid; }

		inline const string& GetName() const { return m_strName; }
		inline const string& GetDesc() const { return m_strDesc; }
		inline const string& GetHost() const { return m_strHost; }
		inline const string& GetAddr() const
								{
									if (m_strAddr.GetLength() > 0)
									{
										return m_strAddr;
									}
									else
									{
										return m_strHost;
									}
								}
		inline chint16 GetPort() const { return m_sPort; }
		inline const ChWorldType& GetType() const { return m_type; }
		inline ChLoginType GetLoginType() const { return m_loginType; }
		inline const string& GetUsername() const { return m_strUsername; }
		inline const string& GetPassword() const { return m_strPassword; }
		inline const string& GetHomePage() const { return m_strHomePage; }
	
	#if defined( CH_PUEBLO_PLUGIN )
		inline const string& GetOnDisconnect() const { return m_strOnDisconnect; }
	#endif

		inline void SetAddr( const string& strAddr ) { m_strAddr = strAddr; }

		void Stringize( string& strWorld );
		void CreateShortcut( ChCore* pCore );

		void Set( const string& strDesc, const string& strHost,
					chint16 sPort, const ChWorldType& type, ChLoginType login,
					const string& strUsername = "",
					const string& strPassword = "",
					const string& strHomePage = "" );
		void Set( const string& strDesc, const string& strHost,
					const string& strAddr, chint16 sPort,
					const ChWorldType& type, ChLoginType login,
					const string& strUsername = "",
					const string& strPassword = "",
					const string& strHomePage = "" );

	protected:
		bool GetKey( string& strCommand );
		void ProcessKey( const string& strKey, const string& strValue );
		void Validate();
		void Escape( string& strValue );

		void RemoveIllegalChars( string& strValue );

		#if defined( CH_MSW )

		void CreateWindowsShortcut( ChCore* pCore );
		bool WriteWindowsShortcutFile( ChCore* pCore, const string& strPath,
										const string& strFilePath,
										const string& strGroupName,
										const string& strName,
										const string& strUsername,
										const string& strPassword,
										const string& strHost,
										const string& strHomePage,
										chint16 sPort,
										const ChWorldType& type,
										ChLoginType loginType );
		void CreateProgmanIcon( const string& strFilePath,
									const string& strGroupName,
									const string& strName  );

		#endif	// defined( CH_MSW )

	private :
		bool FindTag( ifstream& ifile, const char* pstrTag, string& strVal );
		bool FindTag( ifstream& ifile, const char* pstrTag, chint16& sVal );
		bool FindTag( ifstream& ifile, const char* pstrTag, chuint16& suVal );
		bool FindTag( ifstream& ifile, const char* pstrTag, chint32& lVal );
		bool FindTag( ifstream& ifile, const char* pstrTag, chuint32& luVal );


	protected:
		bool		m_boolValid;
		string		m_strName;
		string		m_strDesc;
		ChWorldType	m_type;
		ChLoginType	m_loginType;
		string		m_strHost;
		string		m_strAddr;
		chint16		m_sPort;
		string		m_strUsername;
		string		m_strPassword;
		string		m_strHomePage;
#if defined( CH_PUEBLO_PLUGIN )
		string		 m_strOnDisconnect;
#endif

};


#endif	// !defined( _CHWINFO_H )

// Local Variables: ***
// tab-width:4 ***
// End: ***
