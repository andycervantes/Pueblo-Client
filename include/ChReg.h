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

	This file consists of the interface for the ChRegistry class, used to
	manipulate registry information on Microsoft Windows.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChReg.h,v 2.8 1996/09/25 03:16:16 pritham Exp $

#if !defined( _CHREG_H )
#define _CHREG_H


#if defined( CH_MSW )
											/* Disable warnings about non-
												exported classes for MSW */
	#pragma warning( disable: 4275 )
	#pragma warning( disable: 4251 )

#endif	// defined( CH_MSW )


#if defined( CH_MSW ) && defined( CH_ARCH_16 )
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA    
#endif

#if defined( CH_UNIX )

	#include <ChDb.h>

	typedef void *HKEY;

	#define CH_REG_DB_NAME		"registry"

#endif


/*----------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------*/

#define CH_COMPANY_NAME		"Andromedia Incorporated"

#if  defined( CH_PUEBLO_PLUGIN )
   //  Pueblo plugin
	#define	CH_PRODUCT_NAME	"Pueblo Plug-In"

#else
	// Pueblo standalone
	#define CH_PRODUCT_NAME		"Pueblo"

#endif
#define CH_VERSION_DEFAULT	""
#define CH_GROUP_PATH		"path"
#define CH_KEY_HELPFILES	"HelpFiles"

/*----------------------------------------------------------------------------
	ChRegistry class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS ChRegistry
{
	public:
		ChRegistry( const string& strCompanyName, const string& strProduct,
						const string& strGroup,
						const string& strVersion = CH_VERSION_DEFAULT );
		ChRegistry( const string& strGroup,
						const string& strVersion = CH_VERSION_DEFAULT );
		~ChRegistry();

		bool GetHelpPath( string& strHelpFiles );

		bool Erase( const string& strLabel );

		bool WriteBool( const string& strLabel, bool boolVal );
		bool Write( const string& strLabel, chint32 lVal );
		bool Write( const string& strLabel, const string& strVal );
		bool Read( const string& strLabel, chint32& lVal,
					chint32 lDefault = 0 );
		inline bool Read( const string& strLabel, chuint32& luVal,
							chuint32 luDefault = 0 )
				{
					chint32		lVal( luVal );
					bool		boolReturn;

					boolReturn = Read( strLabel, lVal, (chint32)luDefault );
					luVal = lVal;

					return boolReturn;
				}
		bool Read( const string& strLabel, chint16& sVal,
					chint16 sDefault = 0 );
		inline bool Read( const string& strLabel, chuint16& suVal,
							chuint16 suDefault = 0 )
				{
					chint16		sVal( suVal );
					bool		boolReturn;

					boolReturn = Read( strLabel, sVal, (chint16)suDefault );
					suVal = sVal;

					return boolReturn;
				}
		bool ReadBool( const string& strLabel, bool& boolVal,
						bool boolDefault );
		bool Read( const string& strLabel, string& strVal,
						const string& strDefault = "" );

	protected:
		void Construct( const string& strCompanyName, const string& strProduct,
						const string& strGroup, const string& strVersion );

	private:  
		string		m_strCompanyName;
		string		m_strProduct;
		string		m_strGroup;
		string		m_strVersion;

		string		m_strMasterKey;
		HKEY		m_hMasterKey;

		#ifdef CH_UNIX
		static ChDataBase* m_pRegDB;
		static chuint32 m_luRefCount;
		void 	OpenDb(void);

		friend chint32 RegSetValue( HKEY hKey, const string& strLabel, chuint32 luFlags,
									char* pstrBuffer, chuint32 lLen );
		friend chint32 RegQueryValue( HKEY hKey, const string& strLabel, char* pstrBuffer,
									  chint32* pLen );
		#endif
};

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR    
#endif

#endif	// !defined( _CHREG_H )

// Local Variables: ***
// tab-width:4 ***
// End: ***
