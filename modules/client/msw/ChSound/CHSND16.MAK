# Microsoft Visual C++ generated build script - Do not modify

PROJ = CHSND16
DEBUG = 1
PROGTYPE = 1
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = -d_DEBUG
R_RCDEFINES = -dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = G:\CHACO\MODULES\CLIENT\MSW\CHSOUND\
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC =             
FIRSTCPP = CHMPLAY.CPP 
RC = rc
CFLAGS_D_WDLL = /nologo /G2 /W3 /Zi /ALw /Od /D "_DEBUG" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "NO_TEMPLATES" /FR /GD /GEf /Fd"CHSND16.PDB"
CFLAGS_R_WDLL = /nologo /W3 /ALw /O1 /D "NDEBUG" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "NO_TEMPLATES" /FR /GD /GEf 
LFLAGS_D_WDLL = /NOLOGO /NOD /NOE /PACKC:61440 /ALIGN:16 /ONERROR:NOEXE /CO /MAP:FULL
LFLAGS_R_WDLL = /NOLOGO /NOD /NOE /PACKC:61440 /ALIGN:16 /ONERROR:NOEXE /MAP:FULL
LIBS_D_WDLL = mfc250d oldnames libw ldllcew pueblw16 commdlg.lib mmsystem.lib olecli.lib olesvr.lib shell.lib 
LIBS_R_WDLL = mfc250 oldnames libw ldllcew pueblw16 commdlg.lib olecli.lib olesvr.lib shell.lib 
RCFLAGS = /nologo
RESFLAGS = /nologo
RUNFLAGS = 
DEFFILE = CHSND16.DEF
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
SBRS = CHMPLAY.SBR \
		CHNOTIFY.SBR \
		CHSOPEN.SBR \
		CHSOUND.SBR \
		CHSPREFS.SBR \
		DLL.SBR \
		HEADERS.SBR


CHMPLAY_DEP = g:\chaco\modules\client\msw\chsound\headers.h \
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
	f:\tools\msvc\include\winsock.h \
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
	g:\chaco\modules\client\msw\chsound\chmplay.h \
	g:\chaco\modules\client\msw\chsound\chnotify.h


CHNOTIFY_DEP = g:\chaco\modules\client\msw\chsound\headers.h \
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
	f:\tools\msvc\include\winsock.h \
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
	g:\chaco\include\chsound.h \
	g:\chaco\modules\client\msw\chsound\chnotify.h \
	g:\chaco\modules\client\msw\chsound\chmplay.h


CHSOPEN_DEP = g:\chaco\modules\client\msw\chsound\headers.h \
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
	f:\tools\msvc\include\winsock.h \
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
	g:\chaco\include\chsound.h \
	g:\chaco\modules\client\msw\chsound\chsopen.h \
	g:\chaco\modules\client\msw\chsound\chmplay.h \
	g:\chaco\modules\client\msw\chsound\chnotify.h


CHSOUND_DEP = g:\chaco\modules\client\msw\chsound\headers.h \
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
	f:\tools\msvc\include\winsock.h \
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
	g:\chaco\modules\client\msw\chsound\chmplay.h \
	g:\chaco\modules\client\msw\chsound\chnotify.h \
	g:\chaco\include\chreg.h \
	g:\chaco\include\chdb.h \
	g:\chaco\include\chclmod.h \
	g:\chaco\include\chuser.h \
	g:\chaco\include\chsermod.h \
	g:\chaco\include\chexcept.h \
	g:\chaco\include\chmenu.h \
	g:\chaco\include\chlist.h \
	g:\chaco\include\templcls\chlsthlp.inl \
	g:\chaco\include\templcls\chmnptrl.h \
	g:\chaco\include\templcls\chmnptrl.inl \
	g:\chaco\include\chhtmwnd.h \
	g:\chaco\include\chhttp.h \
	g:\chaco\include\chtxtwnd.h \
	g:\chaco\include\chscrwnd.h \
	g:\chaco\include\chrect.h \
	g:\chaco\include\chscrlvw.h \
	g:\chaco\include\chsize.h \
	g:\chaco\include\chdc.h \
	g:\chaco\include\chfont.h \
	g:\chaco\include\chtxtobj.h \
	g:\chaco\include\chgif.h \
	g:\chaco\include\chdib.h \
	g:\chaco\include\chhtmfrm.h \
	g:\chaco\include\templcls\chpstrls.h \
	g:\chaco\include\templcls\chhtfmls.h \
	g:\chaco\include\templcls\chhtfmls.inl \
	g:\chaco\include\templcls\chhtmspl.h \
	g:\chaco\include\chtext.h \
	g:\chaco\include\chsound.h \
	g:\chaco\modules\client\msw\chsound\chsprefs.h \
	g:\chaco\include\chpage.h


CHSPREFS_DEP = g:\chaco\modules\client\msw\chsound\headers.h \
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
	f:\tools\msvc\include\winsock.h \
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
	g:\chaco\modules\client\msw\chsound\chsopen.h \
	g:\chaco\modules\client\msw\chsound\chmplay.h \
	g:\chaco\modules\client\msw\chsound\chnotify.h \
	g:\chaco\modules\client\msw\chsound\chsprefs.h \
	g:\chaco\include\chreg.h \
	g:\chaco\include\chpage.h


DLL_DEP = g:\chaco\modules\client\msw\chsound\headers.h \
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
	f:\tools\msvc\include\winsock.h \
	g:\chaco\include\sockinet.h \
	g:\chaco\include\chsplay.h \
	g:\chaco\include\templcls\chsockbf.h \
	g:\chaco\include\protocol.h \
	g:\chaco\include\chdispat.h \
	g:\chaco\include\chmsgtyp.h \
	g:\chaco\include\charch.h \
	g:\chaco\include\chtime.h \
	g:\chaco\include\chacct.h \
	g:\chaco\include\chclinfo.h


HEADERS_DEP = g:\chaco\modules\client\msw\chsound\headers.h \
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
	f:\tools\msvc\include\winsock.h \
	g:\chaco\include\sockinet.h \
	g:\chaco\include\chsplay.h \
	g:\chaco\include\templcls\chsockbf.h \
	g:\chaco\include\protocol.h \
	g:\chaco\include\chdispat.h \
	g:\chaco\include\chmsgtyp.h \
	g:\chaco\include\charch.h \
	g:\chaco\include\chtime.h \
	g:\chaco\include\chacct.h \
	g:\chaco\include\chclinfo.h


all:	$(PROJ).DLL $(PROJ).BSC

CHMPLAY.OBJ:	CHMPLAY.CPP $(CHMPLAY_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c CHMPLAY.CPP

CHNOTIFY.OBJ:	CHNOTIFY.CPP $(CHNOTIFY_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHNOTIFY.CPP

CHSOPEN.OBJ:	CHSOPEN.CPP $(CHSOPEN_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHSOPEN.CPP

CHSOUND.OBJ:	CHSOUND.CPP $(CHSOUND_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHSOUND.CPP

CHSPREFS.OBJ:	CHSPREFS.CPP $(CHSPREFS_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHSPREFS.CPP

DLL.OBJ:	DLL.CPP $(DLL_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c DLL.CPP

HEADERS.OBJ:	HEADERS.CPP $(HEADERS_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c HEADERS.CPP

CHSOUND.RES:	CHSOUND.RC $(CHSOUND_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r CHSOUND.RC


$(PROJ).DLL::	CHSOUND.RES

$(PROJ).DLL::	CHMPLAY.OBJ CHNOTIFY.OBJ CHSOPEN.OBJ CHSOUND.OBJ CHSPREFS.OBJ DLL.OBJ \
	HEADERS.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
CHMPLAY.OBJ +
CHNOTIFY.OBJ +
CHSOPEN.OBJ +
CHSOUND.OBJ +
CHSPREFS.OBJ +
DLL.OBJ +
HEADERS.OBJ +
$(OBJS_EXT)
$(PROJ).DLL
$(MAPFILE)
f:\TOOLS\MSVC\LIB\+
f:\TOOLS\MSVC\MFC\LIB\+
f:\TOOLS\MSVC20\LIB\+
g:\chaco\lib\+
h:\3dr\sdk\+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) CHSOUND.RES $@
	@copy $(PROJ).CRF MSVC.BND
	implib /nowep $(PROJ).LIB $(PROJ).DLL

$(PROJ).DLL::	CHSOUND.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) CHSOUND.RES $@

run: $(PROJ).DLL
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
