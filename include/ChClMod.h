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

	This file consists of the interface for the ChClientModule class.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/include/ChClMod.h,v 2.5 1995/10/14 16:57:07 coyote Exp $

#if (!defined( _CHCLMOD_H ))
#define _CHCLMOD_H

#include <ChModule.h>
#include <ChUser.h>


#if defined( CH_MSW ) && defined( CH_ARCH_16 )
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA    
#endif

/*----------------------------------------------------------------------------
	ChClientModule class
----------------------------------------------------------------------------*/

class CH_EXPORT_CLASS ChClientModule : public ChModule
{
	public:
		#if defined( CH_SERVER )

			ChClientModule( const ChUser &user, const string& strModule,
							const string& strLibraryName = "",
							const string& strLoadParam = "",
							ChModuleID idServerModule = CH_CORE_MODULE_ID,
							bool boolOptional = false,
							bool boolUseExisting = true );

			inline ChUser& GetUser() { return m_user; }

		#elif defined( CH_CLIENT )

			ChClientModule( const ChModuleID& idModule );

		#endif	// defined( CH_CLIENT )

		virtual ~ChClientModule();

		static ChModuleID GetCoreID() { return CH_CORE_MODULE_ID; }
		static const string& GetCoreName()
		{
			#if defined( CH_UNIX )
			{								/* Unix has trouble with static
												members being initialized, so
												we hack around for now */

				static string	coreName = "_Chaco Client Core_";

				return coreName;
			}
			#else	// defined( CH_UNIX )
			{
				return ChClientModule::m_strCoreName;
			}
			#endif	// defined( CH_UNIX )
		}

		inline const ChModuleID& GetModuleID() const { return m_idModule; }

	public:
		virtual void Serialize( ChArchive& ar );

	public:
		#if defined( CH_CLIENT )

			chparam Send( ChMsg& msg ) const;

		#endif	// defined( CH_CLIENT )

		void Post( ChMsg& msg, chflag16 fPriority = 0 ) const;
		void Post( chint32 lMessage, chparam param1 = 0,
					chparam param2 = 0, chflag16 fPriority = 0 ) const;

	protected:
		ChModuleID		m_idModule;
		static string	m_strCoreName;

		#if defined( CH_SERVER )

		ChUser			m_user;
		ChMsgConn*		m_pConn;

		#endif	// defined( CH_SERVER )
};

#if defined( CH_MSW ) && defined( CH_ARCH_16 )
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR    
#endif

#endif	// !defined( _CHCLMOD_H )

// Local Variables: ***
// tab-width:4 ***
// End: ***
