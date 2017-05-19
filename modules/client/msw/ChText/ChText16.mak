# Microsoft Visual C++ generated build script - Do not modify

PROJ = CHTEXT16
DEBUG = 1
PROGTYPE = 1
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = -d_DEBUG
R_RCDEFINES = -dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = D:\CHACO\MODULES\CLIENT\MSW\CHTEXT\
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC =             
FIRSTCPP = CHHIST.CPP  
RC = rc
CFLAGS_D_WDLL = /nologo /G2 /W3 /Zi /ALw /Od /D "_DEBUG" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /FR /GD /GEf /Fd"CHTXT16.PDB"
CFLAGS_R_WDLL = /nologo /W3 /ALw /O1 /D "NDEBUG" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /FR /GD /GEf 
LFLAGS_D_WDLL = /NOLOGO /NOD /NOE /PACKC:61440 /ALIGN:16 /ONERROR:NOEXE /CO /MAP:FULL
LFLAGS_R_WDLL = /NOLOGO /NOD /NOE /PACKC:61440 /ALIGN:16 /ONERROR:NOEXE /MAP:FULL
LIBS_D_WDLL = mfc250d oldnames libw ldllcew pueblo16 commdlg.lib olecli.lib olesvr.lib shell.lib 
LIBS_R_WDLL = mfc250 oldnames libw ldllcew pueblo16 commdlg.lib olecli.lib olesvr.lib shell.lib 
RCFLAGS = /nologo
RESFLAGS = /nologo
RUNFLAGS = 
DEFFILE = CHTEXT16.DEF
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
SBRS = CHHIST.SBR \
		CHTEXT.SBR \
		CHTXTIN.SBR \
		CHTXTOUT.SBR \
		DLL.SBR \
		HEADERS.SBR \
		STDAFX.SBR \
		CHSTRLST.SBR


CHHIST_DEP = d:\chaco\modules\client\msw\chtext\headers.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chmdata.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chconn.h \
	d:\chaco\include\socketxx.h \
	d:\chaco\include\chsock.h \
	d:\chaco\include\sockstrm.h \
	c:\tools\msvc\include\winsock.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\include\templcls\chsockbf.h \
	d:\chaco\include\protocol.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\include\charch.h \
	d:\chaco\include\chtime.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chtext.h \
	d:\chaco\modules\client\msw\chtext\chhist.h \
	d:\chaco\include\chsermod.h \
	d:\chaco\include\chuser.h \
	d:\chaco\include\chmodbar.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chstrlst.h \
	d:\chaco\include\templcls\chstrlst.inl


CHTEXT_DEP = d:\chaco\modules\client\msw\chtext\headers.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chmdata.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chconn.h \
	d:\chaco\include\socketxx.h \
	d:\chaco\include\chsock.h \
	d:\chaco\include\sockstrm.h \
	c:\tools\msvc\include\winsock.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\include\templcls\chsockbf.h \
	d:\chaco\include\protocol.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\include\charch.h \
	d:\chaco\include\chtime.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chtext.h \
	d:\chaco\modules\client\msw\chtext\chtxtin.h \
	d:\chaco\include\chsermod.h \
	d:\chaco\include\chuser.h \
	d:\chaco\include\chmodbar.h \
	d:\chaco\modules\client\msw\chtext\chhist.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chstrlst.h \
	d:\chaco\include\templcls\chstrlst.inl \
	d:\chaco\include\chmenu.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\templcls\chmnptrl.h \
	d:\chaco\include\templcls\chmnptrl.inl \
	d:\chaco\include\chhook.h \
	d:\chaco\modules\client\msw\chtext\chtxtout.h \
	d:\chaco\include\chhtmwnd.h \
	d:\chaco\include\chtxtwnd.h \
	d:\chaco\include\chscrwnd.h \
	d:\chaco\include\chrect.h \
	d:\chaco\include\chscrlvw.h \
	d:\chaco\include\chsize.h \
	d:\chaco\include\chdc.h \
	d:\chaco\include\chfont.h \
	d:\chaco\include\templcls\chpstrls.h \
	d:\chaco\include\templcls\chhtmspl.h


CHTXTIN_DEP = d:\chaco\modules\client\msw\chtext\headers.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chmdata.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chconn.h \
	d:\chaco\include\socketxx.h \
	d:\chaco\include\chsock.h \
	d:\chaco\include\sockstrm.h \
	c:\tools\msvc\include\winsock.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\include\templcls\chsockbf.h \
	d:\chaco\include\protocol.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\include\charch.h \
	d:\chaco\include\chtime.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chtext.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\templcls\chmodtre.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\chperfrm.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\modules\client\msw\chtext\chtxtin.h \
	d:\chaco\include\chsermod.h \
	d:\chaco\include\chuser.h \
	d:\chaco\include\chmodbar.h \
	d:\chaco\modules\client\msw\chtext\chhist.h \
	d:\chaco\include\templcls\chstrlst.h \
	d:\chaco\include\templcls\chstrlst.inl \
	d:\chaco\include\chmenu.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\templcls\chmnptrl.h \
	d:\chaco\include\templcls\chmnptrl.inl \
	d:\chaco\include\chhook.h


CHTXTOUT_DEP = d:\chaco\modules\client\msw\chtext\headers.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chmdata.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chconn.h \
	d:\chaco\include\socketxx.h \
	d:\chaco\include\chsock.h \
	d:\chaco\include\sockstrm.h \
	c:\tools\msvc\include\winsock.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\include\templcls\chsockbf.h \
	d:\chaco\include\protocol.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\include\charch.h \
	d:\chaco\include\chtime.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chtext.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\templcls\chmodtre.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\chperfrm.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chsplit.h \
	d:\chaco\modules\client\msw\chtext\chtxtout.h \
	d:\chaco\include\chhtmwnd.h \
	d:\chaco\include\chtxtwnd.h \
	d:\chaco\include\chscrwnd.h \
	d:\chaco\include\chrect.h \
	d:\chaco\include\chscrlvw.h \
	d:\chaco\include\chsize.h \
	d:\chaco\include\chdc.h \
	d:\chaco\include\chfont.h \
	d:\chaco\include\templcls\chpstrls.h \
	d:\chaco\include\templcls\chhtmspl.h \
	d:\chaco\include\chmenu.h \
	d:\chaco\include\chhook.h


DLL_DEP = d:\chaco\modules\client\msw\chtext\headers.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chmdata.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chconn.h \
	d:\chaco\include\socketxx.h \
	d:\chaco\include\chsock.h \
	d:\chaco\include\sockstrm.h \
	c:\tools\msvc\include\winsock.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\include\templcls\chsockbf.h \
	d:\chaco\include\protocol.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\include\charch.h \
	d:\chaco\include\chtime.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chtext.h


HEADERS_DEP = d:\chaco\modules\client\msw\chtext\headers.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chmdata.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chconn.h \
	d:\chaco\include\socketxx.h \
	d:\chaco\include\chsock.h \
	d:\chaco\include\sockstrm.h \
	c:\tools\msvc\include\winsock.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\include\templcls\chsockbf.h \
	d:\chaco\include\protocol.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\include\charch.h \
	d:\chaco\include\chtime.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chtext.h


STDAFX_DEP = d:\chaco\modules\client\msw\chtext\stdafx.h


CHTEXT_RCDEP = d:\chaco\modules\client\msw\chtext\res\chtext.rc2


CHSTRLST_DEP = d:\chaco\modules\client\msw\chtext\headers.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chmdata.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chconn.h \
	d:\chaco\include\socketxx.h \
	d:\chaco\include\chsock.h \
	d:\chaco\include\sockstrm.h \
	c:\tools\msvc\include\winsock.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\include\templcls\chsockbf.h \
	d:\chaco\include\protocol.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\include\charch.h \
	d:\chaco\include\chtime.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chtext.h \
	d:\chaco\include\templcls\chstrlst.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chstrlst.inl


all:	$(PROJ).DLL $(PROJ).BSC

CHHIST.OBJ:	CHHIST.CPP $(CHHIST_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c CHHIST.CPP

CHTEXT.OBJ:	CHTEXT.CPP $(CHTEXT_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHTEXT.CPP

CHTXTIN.OBJ:	CHTXTIN.CPP $(CHTXTIN_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHTXTIN.CPP

CHTXTOUT.OBJ:	CHTXTOUT.CPP $(CHTXTOUT_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHTXTOUT.CPP

DLL.OBJ:	DLL.CPP $(DLL_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c DLL.CPP

HEADERS.OBJ:	HEADERS.CPP $(HEADERS_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c HEADERS.CPP

STDAFX.OBJ:	STDAFX.CPP $(STDAFX_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c STDAFX.CPP

CHTEXT.RES:	CHTEXT.RC $(CHTEXT_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r CHTEXT.RC

CHSTRLST.OBJ:	TEMPLCLS\CHSTRLST.CPP $(CHSTRLST_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c TEMPLCLS\CHSTRLST.CPP


$(PROJ).DLL::	CHTEXT.RES

$(PROJ).DLL::	CHHIST.OBJ CHTEXT.OBJ CHTXTIN.OBJ CHTXTOUT.OBJ DLL.OBJ HEADERS.OBJ \
	STDAFX.OBJ CHSTRLST.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
CHHIST.OBJ +
CHTEXT.OBJ +
CHTXTIN.OBJ +
CHTXTOUT.OBJ +
DLL.OBJ +
HEADERS.OBJ +
STDAFX.OBJ +
CHSTRLST.OBJ +
$(OBJS_EXT)
$(PROJ).DLL
$(MAPFILE)
C:\TOOLS\MSVC\LIB\+
C:\TOOLS\MSVC\MFC\LIB\+
D:\TOOLS\MSVC20\LIB\+
d:\chaco\lib\+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) CHTEXT.RES $@
	@copy $(PROJ).CRF MSVC.BND
	implib /nowep $(PROJ).LIB $(PROJ).DLL

$(PROJ).DLL::	CHTEXT.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) CHTEXT.RES $@

run: $(PROJ).DLL
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
