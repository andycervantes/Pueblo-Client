# Microsoft Visual C++ generated build script - Do not modify

PROJ = CHGR16
DEBUG = 1
PROGTYPE = 1
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = -d_DEBUG
R_RCDEFINES = -dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = G:\CHACO\MODULES\CLIENT\MSW\CHGRAPHX\
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC =             
FIRSTCPP = DLL.CPP     
RC = rc
CFLAGS_D_WDLL = /nologo /G2 /W3 /Zi /ALw /Od /D "WIN16"="1" /D "_DEBUG" /D "CH_MSW" /D "CH_CLIENT" /D "_AFXDLL" /D "CH_EXCEPTIONS" /D "CH_ARCH_16" /D "CH_NO_GRAPHICS_MAZE" /D "NO_TEMPLATES" /FR /GD /Fd"CHGRAPHX.PDB"
CFLAGS_R_WDLL = /nologo /W3 /ALw /O1 /D "WIN16"="1" /D "NDEBUG" /D "CH_MSW" /D "CH_CLIENT" /D "_AFXDLL" /D "CH_EXCEPTIONS" /D "CH_ARCH_16" /D "CH_NO_GRAPHICS_MAZE" /D "NO_TEMPLATES" /FR /GD 
LFLAGS_D_WDLL = /NOLOGO /NOD /NOE /PACKC:61440 /SEG:250 /ALIGN:16 /ONERROR:NOEXE /CO /MAP:FULL
LFLAGS_R_WDLL = /NOLOGO /NOD /NOE /PACKC:61440 /SEG:250 /ALIGN:16 /ONERROR:NOEXE /MAP:FULL
LIBS_D_WDLL = mfc250d mfcn250d oldnames libw ldllcew winsock.lib pueblw16.lib 3dr.lib 3dgwt.lib commdlg.lib olecli.lib olesvr.lib shell.lib 
LIBS_R_WDLL = mfc250 mfcn250 oldnames libw ldllcew winsock.lib pueblw16.lib 3dr.lib 3drspiws.lib commdlg.lib olecli.lib olesvr.lib shell.lib 
RCFLAGS = /nologo
RESFLAGS = /nologo
RUNFLAGS = 
DEFFILE = CHGR16.DEF
OBJS_EXT = 
LIBS_EXT = 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WDLL)
LFLAGS = $(LFLAGS_D_WDLL)
LIBS = $(LIBS_D_WDLL)
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
!else
CFLAGS = $(CFLAGS_R_WDLL)
LFLAGS = $(LFLAGS_R_WDLL)
LIBS = $(LIBS_R_WDLL)
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = DLL.SBR \
		HEADERS.SBR \
		CHGRAPHX.SBR \
		CHGRDEP.SBR \
		CHGRVW.SBR \
		CHGRMOD.SBR \
		CHPANMOD.SBR \
		CHSTRLST.SBR \
		CHGRPLST.SBR \
		CHHTPVW.SBR


DLL_DEP = g:\chaco\modules\client\msw\chgraphx\headers.h \
	g:\chaco\include\chtypes.h \
	g:\chaco\include\chmodule.h \
	g:\chaco\include\chstrmbl.h \
	g:\chaco\include\chvers.h \
	g:\chaco\include\chmsg.h \
	g:\chaco\include\chmdata.h \
	g:\chaco\include\chdata.h \
	g:\chaco\include\chmsgcon.h \
	g:\chaco\include\chconn.h \
	g:\chaco\include\socketxx.h \
	g:\chaco\include\chsock.h \
	g:\chaco\include\sockstrm.h \
	h:\tools\msvc\include\winsock.h \
	g:\chaco\include\sockinet.h \
	g:\chaco\include\chsplay.h \
	g:\chaco\include\templcls\chsockbf.h \
	g:\chaco\include\protocol.h \
	g:\chaco\include\chdispat.h \
	g:\chaco\include\chmsgtyp.h \
	g:\chaco\include\charch.h \
	g:\chaco\include\chtime.h \
	g:\chaco\include\chacct.h \
	g:\chaco\include\chclinfo.h \
	g:\chaco\include\chlist.h \
	g:\chaco\include\templcls\chlsthlp.inl \
	g:\chaco\modules\client\msw\chgraphx\chgrmod.h \
	g:\chaco\include\chgrvw.h \
	g:\chaco\include\chscrwnd.h \
	g:\chaco\include\chdib.h \
	g:\chaco\include\chsplit.h \
	g:\chaco\include\chreg.h \
	g:\chaco\include\chdb.h \
	g:\chaco\include\chgraphx.h \
	g:\chaco\include\chmodmgr.h \
	g:\chaco\include\templcls\chmodtre.h \
	g:\chaco\include\chcore.h \
	g:\chaco\include\chperfrm.h \
	g:\chaco\include\templcls\chmqlst.h \
	g:\chaco\include\templcls\chmqlst.inl \
	g:\chaco\include\templcls\chntfyls.h \
	g:\chaco\include\templcls\chntfyls.inl \
	g:\chaco\modules\client\msw\chgraphx\chgrdep.h \
	g:\chaco\modules\client\msw\chgraphx\templcls/chgrplst.h \
	g:\chaco\include\templcls\chstrlst.h \
	g:\chaco\include\chhttp.h \
	g:\chaco\include\chhook.h \
	g:\chaco\include\chclmod.h \
	g:\chaco\include\chuser.h


HEADERS_DEP = g:\chaco\modules\client\msw\chgraphx\headers.h \
	g:\chaco\include\chtypes.h \
	g:\chaco\include\chmodule.h \
	g:\chaco\include\chstrmbl.h \
	g:\chaco\include\chvers.h \
	g:\chaco\include\chmsg.h \
	g:\chaco\include\chmdata.h \
	g:\chaco\include\chdata.h \
	g:\chaco\include\chmsgcon.h \
	g:\chaco\include\chconn.h \
	g:\chaco\include\socketxx.h \
	g:\chaco\include\chsock.h \
	g:\chaco\include\sockstrm.h \
	h:\tools\msvc\include\winsock.h \
	g:\chaco\include\sockinet.h \
	g:\chaco\include\chsplay.h \
	g:\chaco\include\templcls\chsockbf.h \
	g:\chaco\include\protocol.h \
	g:\chaco\include\chdispat.h \
	g:\chaco\include\chmsgtyp.h \
	g:\chaco\include\charch.h \
	g:\chaco\include\chtime.h \
	g:\chaco\include\chacct.h \
	g:\chaco\include\chclinfo.h \
	g:\chaco\include\chlist.h \
	g:\chaco\include\templcls\chlsthlp.inl


CHGRAPHX_DEP = g:\chaco\modules\client\msw\chgraphx\headers.h \
	g:\chaco\include\chtypes.h \
	g:\chaco\include\chmodule.h \
	g:\chaco\include\chstrmbl.h \
	g:\chaco\include\chvers.h \
	g:\chaco\include\chmsg.h \
	g:\chaco\include\chmdata.h \
	g:\chaco\include\chdata.h \
	g:\chaco\include\chmsgcon.h \
	g:\chaco\include\chconn.h \
	g:\chaco\include\socketxx.h \
	g:\chaco\include\chsock.h \
	g:\chaco\include\sockstrm.h \
	h:\tools\msvc\include\winsock.h \
	g:\chaco\include\sockinet.h \
	g:\chaco\include\chsplay.h \
	g:\chaco\include\templcls\chsockbf.h \
	g:\chaco\include\protocol.h \
	g:\chaco\include\chdispat.h \
	g:\chaco\include\chmsgtyp.h \
	g:\chaco\include\charch.h \
	g:\chaco\include\chtime.h \
	g:\chaco\include\chacct.h \
	g:\chaco\include\chclinfo.h \
	g:\chaco\include\chlist.h \
	g:\chaco\include\templcls\chlsthlp.inl \
	g:\chaco\include\chgraphx.h \
	g:\chaco\include\chmodmgr.h \
	g:\chaco\include\templcls\chmodtre.h \
	g:\chaco\include\chcore.h \
	g:\chaco\include\chperfrm.h \
	g:\chaco\include\templcls\chmqlst.h \
	g:\chaco\include\templcls\chmqlst.inl \
	g:\chaco\include\templcls\chntfyls.h \
	g:\chaco\include\templcls\chntfyls.inl \
	g:\chaco\modules\client\msw\chgraphx\chgrmod.h \
	g:\chaco\include\chgrvw.h \
	g:\chaco\include\chscrwnd.h \
	g:\chaco\include\chdib.h \
	g:\chaco\include\chsplit.h \
	g:\chaco\include\chreg.h \
	g:\chaco\include\chdb.h \
	g:\chaco\modules\client\msw\chgraphx\chgrdep.h \
	g:\chaco\modules\client\msw\chgraphx\templcls/chgrplst.h \
	g:\chaco\include\templcls\chstrlst.h \
	g:\chaco\include\chhttp.h \
	g:\chaco\include\chhook.h \
	g:\chaco\include\chclmod.h \
	g:\chaco\include\chuser.h \
	g:\chaco\modules\client\msw\chgraphx\chpanmod.h \
	g:\chaco\modules\client\msw\chgraphx\templcls\chhtpvw.h


CHGRDEP_DEP = g:\chaco\modules\client\msw\chgraphx\headers.h \
	g:\chaco\include\chtypes.h \
	g:\chaco\include\chmodule.h \
	g:\chaco\include\chstrmbl.h \
	g:\chaco\include\chvers.h \
	g:\chaco\include\chmsg.h \
	g:\chaco\include\chmdata.h \
	g:\chaco\include\chdata.h \
	g:\chaco\include\chmsgcon.h \
	g:\chaco\include\chconn.h \
	g:\chaco\include\socketxx.h \
	g:\chaco\include\chsock.h \
	g:\chaco\include\sockstrm.h \
	h:\tools\msvc\include\winsock.h \
	g:\chaco\include\sockinet.h \
	g:\chaco\include\chsplay.h \
	g:\chaco\include\templcls\chsockbf.h \
	g:\chaco\include\protocol.h \
	g:\chaco\include\chdispat.h \
	g:\chaco\include\chmsgtyp.h \
	g:\chaco\include\charch.h \
	g:\chaco\include\chtime.h \
	g:\chaco\include\chacct.h \
	g:\chaco\include\chclinfo.h \
	g:\chaco\include\chlist.h \
	g:\chaco\include\templcls\chlsthlp.inl \
	g:\chaco\modules\client\msw\chgraphx\chgrdep.h \
	g:\chaco\include\chgrvw.h \
	g:\chaco\modules\client\msw\chgraphx\templcls/chgrplst.h \
	g:\chaco\include\templcls\chstrlst.h


CHGRVW_DEP = g:\chaco\modules\client\msw\chgraphx\headers.h \
	g:\chaco\include\chtypes.h \
	g:\chaco\include\chmodule.h \
	g:\chaco\include\chstrmbl.h \
	g:\chaco\include\chvers.h \
	g:\chaco\include\chmsg.h \
	g:\chaco\include\chmdata.h \
	g:\chaco\include\chdata.h \
	g:\chaco\include\chmsgcon.h \
	g:\chaco\include\chconn.h \
	g:\chaco\include\socketxx.h \
	g:\chaco\include\chsock.h \
	g:\chaco\include\sockstrm.h \
	h:\tools\msvc\include\winsock.h \
	g:\chaco\include\sockinet.h \
	g:\chaco\include\chsplay.h \
	g:\chaco\include\templcls\chsockbf.h \
	g:\chaco\include\protocol.h \
	g:\chaco\include\chdispat.h \
	g:\chaco\include\chmsgtyp.h \
	g:\chaco\include\charch.h \
	g:\chaco\include\chtime.h \
	g:\chaco\include\chacct.h \
	g:\chaco\include\chclinfo.h \
	g:\chaco\include\chlist.h \
	g:\chaco\include\templcls\chlsthlp.inl \
	g:\chaco\include\chgrvw.h \
	g:\chaco\include\chscrwnd.h \
	g:\chaco\include\chdib.h \
	g:\chaco\include\chsplit.h \
	g:\chaco\include\chreg.h \
	g:\chaco\include\chdb.h


CHGRMOD_DEP = g:\chaco\modules\client\msw\chgraphx\headers.h \
	g:\chaco\include\chtypes.h \
	g:\chaco\include\chmodule.h \
	g:\chaco\include\chstrmbl.h \
	g:\chaco\include\chvers.h \
	g:\chaco\include\chmsg.h \
	g:\chaco\include\chmdata.h \
	g:\chaco\include\chdata.h \
	g:\chaco\include\chmsgcon.h \
	g:\chaco\include\chconn.h \
	g:\chaco\include\socketxx.h \
	g:\chaco\include\chsock.h \
	g:\chaco\include\sockstrm.h \
	h:\tools\msvc\include\winsock.h \
	g:\chaco\include\sockinet.h \
	g:\chaco\include\chsplay.h \
	g:\chaco\include\templcls\chsockbf.h \
	g:\chaco\include\protocol.h \
	g:\chaco\include\chdispat.h \
	g:\chaco\include\chmsgtyp.h \
	g:\chaco\include\charch.h \
	g:\chaco\include\chtime.h \
	g:\chaco\include\chacct.h \
	g:\chaco\include\chclinfo.h \
	g:\chaco\include\chlist.h \
	g:\chaco\include\templcls\chlsthlp.inl \
	g:\chaco\include\chcore.h \
	g:\chaco\include\chmodmgr.h \
	g:\chaco\include\chperfrm.h \
	g:\chaco\include\templcls\chmqlst.h \
	g:\chaco\include\templcls\chmqlst.inl \
	g:\chaco\include\templcls\chntfyls.h \
	g:\chaco\include\templcls\chntfyls.inl \
	g:\chaco\include\chsplit.h \
	g:\chaco\include\chreg.h \
	g:\chaco\include\chdb.h \
	g:\chaco\modules\client\msw\chgraphx\chgrmod.h \
	g:\chaco\include\chgrvw.h \
	g:\chaco\include\chscrwnd.h \
	g:\chaco\include\chdib.h \
	g:\chaco\include\chgraphx.h \
	g:\chaco\include\templcls\chmodtre.h \
	g:\chaco\modules\client\msw\chgraphx\chgrdep.h \
	g:\chaco\modules\client\msw\chgraphx\templcls/chgrplst.h \
	g:\chaco\include\templcls\chstrlst.h \
	g:\chaco\include\chhttp.h \
	g:\chaco\include\chhook.h \
	g:\chaco\include\chclmod.h \
	g:\chaco\include\chuser.h \
	g:\chaco\modules\client\msw\chgraphx\chanidep.h \
	g:\chaco\modules\client\msw\chgraphx\chanim.h \
	g:\chaco\modules\client\msw\chgraphx\chspritn.h \
	g:\chaco\modules\client\msw\chgraphx\chsprite.h \
	g:\chaco\modules\client\msw\chgraphx\chsplstn.h \
	g:\chaco\modules\client\msw\chgraphx\chsprlst.h \
	g:\chaco\modules\client\msw\chgraphx\chphsprt.h


CHGRAPHX_RCDEP = g:\chaco\modules\client\msw\chgraphx\res\pointer.cur \
	g:\chaco\modules\client\msw\chgraphx\res\chgraphx.rc2


CHPANMOD_DEP = g:\chaco\modules\client\msw\chgraphx\headers.h \
	g:\chaco\include\chtypes.h \
	g:\chaco\include\chmodule.h \
	g:\chaco\include\chstrmbl.h \
	g:\chaco\include\chvers.h \
	g:\chaco\include\chmsg.h \
	g:\chaco\include\chmdata.h \
	g:\chaco\include\chdata.h \
	g:\chaco\include\chmsgcon.h \
	g:\chaco\include\chconn.h \
	g:\chaco\include\socketxx.h \
	g:\chaco\include\chsock.h \
	g:\chaco\include\sockstrm.h \
	h:\tools\msvc\include\winsock.h \
	g:\chaco\include\sockinet.h \
	g:\chaco\include\chsplay.h \
	g:\chaco\include\templcls\chsockbf.h \
	g:\chaco\include\protocol.h \
	g:\chaco\include\chdispat.h \
	g:\chaco\include\chmsgtyp.h \
	g:\chaco\include\charch.h \
	g:\chaco\include\chtime.h \
	g:\chaco\include\chacct.h \
	g:\chaco\include\chclinfo.h \
	g:\chaco\include\chlist.h \
	g:\chaco\include\templcls\chlsthlp.inl \
	g:\chaco\include\chcore.h \
	g:\chaco\include\chmodmgr.h \
	g:\chaco\include\chperfrm.h \
	g:\chaco\include\templcls\chmqlst.h \
	g:\chaco\include\templcls\chmqlst.inl \
	g:\chaco\include\templcls\chntfyls.h \
	g:\chaco\include\templcls\chntfyls.inl \
	g:\chaco\include\chsplit.h \
	g:\chaco\include\chreg.h \
	g:\chaco\include\chdb.h \
	g:\chaco\modules\client\msw\chgraphx\chpanmod.h \
	g:\chaco\modules\client\msw\chgraphx\chgrmod.h \
	g:\chaco\include\chgrvw.h \
	g:\chaco\include\chscrwnd.h \
	g:\chaco\include\chdib.h \
	g:\chaco\include\chgraphx.h \
	g:\chaco\include\templcls\chmodtre.h \
	g:\chaco\modules\client\msw\chgraphx\chgrdep.h \
	g:\chaco\modules\client\msw\chgraphx\templcls/chgrplst.h \
	g:\chaco\include\templcls\chstrlst.h \
	g:\chaco\include\chhttp.h \
	g:\chaco\include\chhook.h \
	g:\chaco\include\chclmod.h \
	g:\chaco\include\chuser.h \
	g:\chaco\modules\client\msw\chgraphx\templcls\chhtpvw.h \
	g:\chaco\include\chtext.h \
	g:\chaco\include\chhtmwnd.h \
	g:\chaco\include\chtxtwnd.h \
	g:\chaco\include\chrect.h \
	g:\chaco\include\chscrlvw.h \
	g:\chaco\include\chsize.h \
	g:\chaco\include\chdc.h \
	g:\chaco\include\chfont.h \
	g:\chaco\include\chtxtobj.h \
	g:\chaco\include\chhtmfrm.h \
	g:\chaco\include\templcls\chpstrls.h \
	g:\chaco\include\templcls\chhtfmls.h \
	g:\chaco\include\templcls\chhtfmls.inl \
	g:\chaco\include\templcls\chfechls.h \
	g:\chaco\include\templcls\chfechls.inl \
	g:\chaco\include\templcls\chhtmspl.h \
	g:\chaco\include\chutil.h


CHSTRLST_DEP = g:\chaco\modules\client\msw\chgraphx\headers.h \
	g:\chaco\include\chtypes.h \
	g:\chaco\include\chmodule.h \
	g:\chaco\include\chstrmbl.h \
	g:\chaco\include\chvers.h \
	g:\chaco\include\chmsg.h \
	g:\chaco\include\chmdata.h \
	g:\chaco\include\chdata.h \
	g:\chaco\include\chmsgcon.h \
	g:\chaco\include\chconn.h \
	g:\chaco\include\socketxx.h \
	g:\chaco\include\chsock.h \
	g:\chaco\include\sockstrm.h \
	h:\tools\msvc\include\winsock.h \
	g:\chaco\include\sockinet.h \
	g:\chaco\include\chsplay.h \
	g:\chaco\include\templcls\chsockbf.h \
	g:\chaco\include\protocol.h \
	g:\chaco\include\chdispat.h \
	g:\chaco\include\chmsgtyp.h \
	g:\chaco\include\charch.h \
	g:\chaco\include\chtime.h \
	g:\chaco\include\chacct.h \
	g:\chaco\include\chclinfo.h \
	g:\chaco\include\chlist.h \
	g:\chaco\include\templcls\chlsthlp.inl \
	g:\chaco\include\templcls\chstrlst.h \
	g:\chaco\include\templcls\chstrlst.inl


CHGRPLST_DEP = g:\chaco\modules\client\msw\chgraphx\headers.h \
	g:\chaco\include\chtypes.h \
	g:\chaco\include\chmodule.h \
	g:\chaco\include\chstrmbl.h \
	g:\chaco\include\chvers.h \
	g:\chaco\include\chmsg.h \
	g:\chaco\include\chmdata.h \
	g:\chaco\include\chdata.h \
	g:\chaco\include\chmsgcon.h \
	g:\chaco\include\chconn.h \
	g:\chaco\include\socketxx.h \
	g:\chaco\include\chsock.h \
	g:\chaco\include\sockstrm.h \
	h:\tools\msvc\include\winsock.h \
	g:\chaco\include\sockinet.h \
	g:\chaco\include\chsplay.h \
	g:\chaco\include\templcls\chsockbf.h \
	g:\chaco\include\protocol.h \
	g:\chaco\include\chdispat.h \
	g:\chaco\include\chmsgtyp.h \
	g:\chaco\include\charch.h \
	g:\chaco\include\chtime.h \
	g:\chaco\include\chacct.h \
	g:\chaco\include\chclinfo.h \
	g:\chaco\include\chlist.h \
	g:\chaco\include\templcls\chlsthlp.inl \
	g:\chaco\modules\client\msw\chgraphx\templcls\chgrplst.h \
	g:\chaco\modules\client\msw\chgraphx\templcls\chgrplst.inl


CHHTPVW_DEP = g:\chaco\modules\client\msw\chgraphx\headers.h \
	g:\chaco\include\chtypes.h \
	g:\chaco\include\chmodule.h \
	g:\chaco\include\chstrmbl.h \
	g:\chaco\include\chvers.h \
	g:\chaco\include\chmsg.h \
	g:\chaco\include\chmdata.h \
	g:\chaco\include\chdata.h \
	g:\chaco\include\chmsgcon.h \
	g:\chaco\include\chconn.h \
	g:\chaco\include\socketxx.h \
	g:\chaco\include\chsock.h \
	g:\chaco\include\sockstrm.h \
	h:\tools\msvc\include\winsock.h \
	g:\chaco\include\sockinet.h \
	g:\chaco\include\chsplay.h \
	g:\chaco\include\templcls\chsockbf.h \
	g:\chaco\include\protocol.h \
	g:\chaco\include\chdispat.h \
	g:\chaco\include\chmsgtyp.h \
	g:\chaco\include\charch.h \
	g:\chaco\include\chtime.h \
	g:\chaco\include\chacct.h \
	g:\chaco\include\chclinfo.h \
	g:\chaco\include\chlist.h \
	g:\chaco\include\templcls\chlsthlp.inl \
	g:\chaco\modules\client\msw\chgraphx\templcls\chhtpvw.h


all:	$(PROJ).DLL $(PROJ).BSC

DLL.OBJ:	DLL.CPP $(DLL_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c DLL.CPP

HEADERS.OBJ:	HEADERS.CPP $(HEADERS_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c HEADERS.CPP

CHGRAPHX.OBJ:	CHGRAPHX.CPP $(CHGRAPHX_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHGRAPHX.CPP

CHGRDEP.OBJ:	CHGRDEP.CPP $(CHGRDEP_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHGRDEP.CPP

CHGRVW.OBJ:	CHGRVW.CPP $(CHGRVW_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHGRVW.CPP

CHGRMOD.OBJ:	CHGRMOD.CPP $(CHGRMOD_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHGRMOD.CPP

CHGRAPHX.RES:	CHGRAPHX.RC $(CHGRAPHX_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r CHGRAPHX.RC

CHPANMOD.OBJ:	CHPANMOD.CPP $(CHPANMOD_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHPANMOD.CPP

CHSTRLST.OBJ:	TEMPLCLS\CHSTRLST.CPP $(CHSTRLST_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c TEMPLCLS\CHSTRLST.CPP

CHGRPLST.OBJ:	TEMPLCLS\CHGRPLST.CPP $(CHGRPLST_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c TEMPLCLS\CHGRPLST.CPP

CHHTPVW.OBJ:	TEMPLCLS\CHHTPVW.CPP $(CHHTPVW_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c TEMPLCLS\CHHTPVW.CPP


$(PROJ).DLL::	CHGRAPHX.RES

$(PROJ).DLL::	DLL.OBJ HEADERS.OBJ CHGRAPHX.OBJ CHGRDEP.OBJ CHGRVW.OBJ CHGRMOD.OBJ \
	CHPANMOD.OBJ CHSTRLST.OBJ CHGRPLST.OBJ CHHTPVW.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
DLL.OBJ +
HEADERS.OBJ +
CHGRAPHX.OBJ +
CHGRDEP.OBJ +
CHGRVW.OBJ +
CHGRMOD.OBJ +
CHPANMOD.OBJ +
CHSTRLST.OBJ +
CHGRPLST.OBJ +
CHHTPVW.OBJ +
$(OBJS_EXT)
$(PROJ).DLL
$(MAPFILE)
h:\tools\msvc\lib\+
h:\tools\msvc\mfc\lib\+
g:\chaco\lib\+
h:\3dr\sdk\+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) CHGRAPHX.RES $@
	@copy $(PROJ).CRF MSVC.BND
	implib /nowep $(PROJ).LIB $(PROJ).DLL

$(PROJ).DLL::	CHGRAPHX.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) CHGRAPHX.RES $@

run: $(PROJ).DLL
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
