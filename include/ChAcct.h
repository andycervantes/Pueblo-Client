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

	This file consists of the interface for the ChAccountInfo class.

----------------------------------------------------------------------------*/

#if (!defined( _CHACCT_H ))
#define _CHACCT_H        

#include <ChTypes.h>
#include <ChData.h>
#include <ChStrmbl.h>    

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA AFXAPI_DATA    
#endif


/*----------------------------------------------------------------------------
	ChAccountInfo class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS ChAccountInfo : public ChStreamable
{
	public:
		typedef enum tagGender { male = 1, female, other, noyb } Gender;

	public:
		ChAccountInfo();
		~ChAccountInfo();

		inline const string& GetFirstName() { return m_strFirstName; }
		inline const string& GetMiddleName() { return m_strMiddleName; }
		inline const string& GetSurname() { return m_strSurname; }
		inline const string& GetStreet() { return m_strStreet; }
		inline const string& GetApartment() { return m_strApt; }
		inline const string& GetCity() { return m_strCity; }
		inline const string& GetState() { return m_strState; }
		inline const string& GetZip() { return m_strZip; }
		inline const string& GetCountry() { return m_strCountry; }
		inline const string& GetEMail() { return m_strEMail; }
		inline Gender GetGender() { return m_gender; }
		inline const string& GetMiscFields() { return m_strMisc; }

		inline void SetFirstName( const string& strFirstName )
							{ m_strFirstName = strFirstName; }
		inline void SetMiddleName( const string& strMiddleName )
							{ m_strMiddleName = strMiddleName; }
		inline void SetSurname( const string& strSurname )
							{ m_strSurname = strSurname; }
		inline void SetStreet( const string& strStreet )
							{ m_strStreet = strStreet; }
		inline void SetApartment( const string& strApartment )
							{ m_strApt = strApartment; }
		inline void SetCity( const string& strCity ) { m_strCity = strCity; }
		inline void SetState( const string& strState )
							{ m_strState = strState; }
		inline void SetZip( const string& strZip ) { m_strZip = strZip; }
		inline void SetCountry( const string& strCountry )
							{ m_strCountry = strCountry; }
		inline void SetEMail( const string& strEMail ) { m_strEMail = strEMail; }
		inline void SetGender( Gender gender ) { m_gender = gender; }

		void SetName( const string& strFirstName, const string& strMiddleName,
						const string& strSurname );
		void SetAddress( const string& strStreet, const string& strApartment,
							const string& strCity, const string& strState,
							const string& strZip, const string& strCountry,
							const string& strEMail );
		inline void SetPersonal( Gender gender )
							{
								SetGender( gender );
							}

		void AddMiscField( const string& strLabel, const string& strValue );

											// Overrides
		virtual void Serialize( ChArchive& ar );

	private:
		string		m_strFirstName;
		string		m_strMiddleName;
		string		m_strSurname;			// Last or family name
		
		string		m_strStreet;
		string		m_strApt;
		string		m_strCity;
		string		m_strState;				// or Province
		string		m_strZip;
		string		m_strCountry;

		string		m_strEMail;

		Gender		m_gender;

		string		m_strMisc;
}; 

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR 
#endif


#endif	// !defined( _CHACCT_H )
