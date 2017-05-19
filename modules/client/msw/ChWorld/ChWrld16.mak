# Microsoft Visual C++ generated build script - Do not modify

PROJ = CHTXTM16
DEBUG = 1
PROGTYPE = 1
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = -d_DEBUG
R_RCDEFINES = -dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = D:\CHACO\MODULES\CLIENT\MSW\CHTXTMUD\
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC =             
FIRSTCPP = CHMINFO.CPP 
RC = rc
CFLAGS_D_WDLL = /nologo /G2 /W3 /Zi /ALw /Od /D "_DEBUG" /D "_AFXDLL" /D "CH_CLIENT" /D "CH_MSW" /FR /GD /GEf /Fd"CHTMUD16.PDB"
CFLAGS_R_WDLL = /nologo /W3 /ALw /O1 /D "NDEBUG" /D "_AFXDLL" /D "CH_CLIENT" /D "CH_MSW" /FR /GD /GEf 
LFLAGS_D_WDLL = /NOLOGO /NOD /NOE /PACKC:61440 /ALIGN:16 /ONERROR:NOEXE /CO /MAP:FULL
LFLAGS_R_WDLL = /NOLOGO /NOD /NOE /PACKC:61440 /ALIGN:16 /ONERROR:NOEXE /MAP:FULL
LIBS_D_WDLL = mfc250d oldnames libw ldllcew pueblo16 commdlg.lib olecli.lib olesvr.lib shell.lib 
LIBS_R_WDLL = mfc250 oldnames libw ldllcew pueblo16 commdlg.lib olecli.lib olesvr.lib shell.lib 
RCFLAGS = /nologo
RESFLAGS = /nologo
RUNFLAGS = 
DEFFILE = CHTXTM16.DEF
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
SBRS = CHMINFO.SBR \
		CHMLIST.SBR \
		CHMLISTD.SBR \
		CHMTYPE.SBR \
		CHTXTMUD.SBR \
		DLL.SBR \
		HEADERS.SBR \
		STDAFX.SBR \
		CHMDPLST.SBR \
		CHPRFDLG.SBR


CHMINFO_DEP = d:\chaco\modules\client\msw\chtxtmud\headers.h \
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
	d:\chaco\modules\client\msw\chtxtmud\txtmud.h \
	d:\chaco\modules\client\msw\chtxtmud\chminfo.h \
	d:\chaco\modules\client\msw\chtxtmud\chmtype.h


CHMLIST_DEP = d:\chaco\modules\client\msw\chtxtmud\headers.h \
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
	d:\chaco\modules\client\msw\chtxtmud\txtmud.h \
	d:\chaco\modules\client\msw\chtxtmud\chminfo.h \
	d:\chaco\modules\client\msw\chtxtmud\chmtype.h \
	d:\chaco\modules\client\msw\chtxtmud\chmlist.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\chreg.h \
	d:\chaco\modules\client\msw\chtxtmud\templcls\chmdplst.h \
	d:\chaco\modules\client\msw\chtxtmud\templcls\chmdplst.inl


CHMLISTD_DEP = d:\chaco\modules\client\msw\chtxtmud\headers.h \
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
	d:\chaco\modules\client\msw\chtxtmud\txtmud.h \
	d:\chaco\modules\client\msw\chtxtmud\chminfo.h \
	d:\chaco\modules\client\msw\chtxtmud\chmtype.h \
	d:\chaco\modules\client\msw\chtxtmud\chmlistd.h \
	d:\chaco\include\chreg.h \
	d:\chaco\modules\client\msw\chtxtmud\chmlist.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\modules\client\msw\chtxtmud\templcls\chmdplst.h \
	d:\chaco\modules\client\msw\chtxtmud\templcls\chmdplst.inl


CHMTYPE_DEP = d:\chaco\modules\client\msw\chtxtmud\headers.h \
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
	d:\chaco\modules\client\msw\chtxtmud\txtmud.h \
	d:\chaco\modules\client\msw\chtxtmud\chminfo.h \
	d:\chaco\modules\client\msw\chtxtmud\chmtype.h


CHTXTMUD_DEP = d:\chaco\modules\client\msw\chtxtmud\headers.h \
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
	d:\chaco\modules\client\msw\chtxtmud\txtmud.h \
	d:\chaco\modules\client\msw\chtxtmud\chminfo.h \
	d:\chaco\modules\client\msw\chtxtmud\chmtype.h \
	d:\chaco\include\chreg.h \
	d:\chaco\include\chclmod.h \
	d:\chaco\include\chuser.h \
	d:\chaco\include\chsermod.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chmenu.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chmnptrl.h \
	d:\chaco\include\templcls\chmnptrl.inl \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\chtext.h \
	d:\chaco\include\chtxtmud.h \
	d:\chaco\modules\client\msw\chtxtmud\chmlistd.h \
	d:\chaco\modules\client\msw\chtxtmud\chmlist.h \
	d:\chaco\modules\client\msw\chtxtmud\templcls\chmdplst.h \
	d:\chaco\modules\client\msw\chtxtmud\templcls\chmdplst.inl \
	d:\chaco\modules\client\msw\chtxtmud\chprfdlg.h


DLL_DEP = d:\chaco\modules\client\msw\chtxtmud\headers.h \
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
	d:\chaco\modules\client\msw\chtxtmud\txtmud.h \
	d:\chaco\modules\client\msw\chtxtmud\chminfo.h \
	d:\chaco\modules\client\msw\chtxtmud\chmtype.h


HEADERS_DEP = d:\chaco\modules\client\msw\chtxtmud\headers.h \
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
	d:\chaco\modules\client\msw\chtxtmud\txtmud.h \
	d:\chaco\modules\client\msw\chtxtmud\chminfo.h \
	d:\chaco\modules\client\msw\chtxtmud\chmtype.h


STDAFX_DEP = d:\chaco\modules\client\msw\chtxtmud\stdafx.h


CHMDPLST_DEP = d:\chaco\modules\client\msw\chtxtmud\headers.h


CHMDPLST_DEP = d:\chaco\include\chtypes.h \
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
	d:\chaco\modules\client\msw\chtxtmud\txtmud.h \
	d:\chaco\modules\client\msw\chtxtmud\chminfo.h \
	d:\chaco\modules\client\msw\chtxtmud\chmtype.h \
	d:\chaco\modules\client\msw\chtxtmud\templcls\chmdplst.h \
	d:\chaco\include\chlist.h \
	d:\chaco\modules\client\msw\chtxtmud\templcls\chmdplst.inl


CHPRFDLG_DEP = d:\chaco\modules\client\msw\chtxtmud\headers.h \
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
	d:\chaco\modules\client\msw\chtxtmud\txtmud.h \
	d:\chaco\modules\client\msw\chtxtmud\chminfo.h \
	d:\chaco\modules\client\msw\chtxtmud\chmtype.h \
	d:\chaco\modules\client\msw\chtxtmud\chprfdlg.h \
	d:\chaco\include\chreg.h


all:	$(PROJ).DLL $(PROJ).BSC

CHMINFO.OBJ:	CHMINFO.CPP $(CHMINFO_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c CHMINFO.CPP

CHMLIST.OBJ:	CHMLIST.CPP $(CHMLIST_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHMLIST.CPP

CHMLISTD.OBJ:	CHMLISTD.CPP $(CHMLISTD_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHMLISTD.CPP

CHMTYPE.OBJ:	CHMTYPE.CPP $(CHMTYPE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHMTYPE.CPP

CHTXTMUD.OBJ:	CHTXTMUD.CPP $(CHTXTMUD_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHTXTMUD.CPP

DLL.OBJ:	DLL.CPP $(DLL_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c DLL.CPP

HEADERS.OBJ:	HEADERS.CPP $(HEADERS_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c HEADERS.CPP

STDAFX.OBJ:	STDAFX.CPP $(STDAFX_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c STDAFX.CPP

CHTXTMUD.RES:	CHTXTMUD.RC $(CHTXTMUD_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r CHTXTMUD.RC

CHMDPLST.OBJ:	TEMPLCLS\CHMDPLST.CPP $(CHMDPLST_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c TEMPLCLS\CHMDPLST.CPP

CHPRFDLG.OBJ:	CHPRFDLG.CPP $(CHPRFDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHPRFDLG.CPP


$(PROJ).DLL::	CHTXTMUD.RES

$(PROJ).DLL::	CHMINFO.OBJ CHMLIST.OBJ CHMLISTD.OBJ CHMTYPE.OBJ CHTXTMUD.OBJ DLL.OBJ \
	HEADERS.OBJ STDAFX.OBJ CHMDPLST.OBJ CHPRFDLG.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
CHMINFO.OBJ +
CHMLIST.OBJ +
CHMLISTD.OBJ +
CHMTYPE.OBJ +
CHTXTMUD.OBJ +
DLL.OBJ +
HEADERS.OBJ +
STDAFX.OBJ +
CHMDPLST.OBJ +
CHPRFDLG.OBJ +
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
	$(RC) $(RESFLAGS) CHTXTMUD.RES $@
	@copy $(PROJ).CRF MSVC.BND
	implib /nowep $(PROJ).LIB $(PROJ).DLL

$(PROJ).DLL::	CHTXTMUD.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) CHTXTMUD.RES $@

run: $(PROJ).DLL
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
