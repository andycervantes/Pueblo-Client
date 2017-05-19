# Microsoft Visual C++ generated build script - Do not modify

PROJ = PUEBLO16
DEBUG = 1
PROGTYPE = 0
CALLER = 
ARGS = 
DLLS = d:\chaco\bin\chtext16.dll
D_RCDEFINES = /d_DEBUG, /dCH_ARCH_16 
R_RCDEFINES = /dNDEBUG, /dCH_ARCH_16 
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = D:\CHACO\CLIENT\MSW\
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC =             
FIRSTCPP = CHABOUT.CPP 
RC = rc
CFLAGS_D_WEXE = /nologo /G2 /W3 /Gf /Zi /AL /Gt65534 /Od /D "_DEBUG" /D "_AFXDLL" /D "CH_MSW" /D "CH_EXCEPTIONS" /FR /GA /GEf /Fd"CHACO16.PDB"
CFLAGS_R_WEXE = /nologo /W3 /AL /Gt65534 /O1 /D "NDEBUG" /D "_AFXDLL" /D "CH_MSW" /D "CH_EXCEPTIONS" /FR /GA /GEf 
LFLAGS_D_WEXE = /NOLOGO /NOD /NOE /PACKC:61440 /STACK:24084 /ALIGN:16 /ONERROR:NOEXE /CO  
LFLAGS_R_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE  
LIBS_D_WEXE = mfc250d mfcn250d oldnames libw llibcew winsock pueblo16 ctl3d commdlg.lib olecli.lib olesvr.lib shell.lib 
LIBS_R_WEXE = mfc250 mfcn250 oldnames libw llibcew winsock pueblo16 ctl3d commdlg.lib olecli.lib olesvr.lib shell.lib 
RCFLAGS = /nologo 
RESFLAGS = /nologo 
RUNFLAGS = 
DEFFILE = PUEBLO16.DEF
OBJS_EXT = 
LIBS_EXT = 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WEXE)
LFLAGS = $(LFLAGS_D_WEXE)
LIBS = $(LIBS_D_WEXE)
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
!else
CFLAGS = $(CFLAGS_R_WEXE)
LFLAGS = $(LFLAGS_R_WEXE)
LIBS = $(LIBS_R_WEXE)
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = CHABOUT.SBR \
		CHCLCORE.SBR \
		CHLOGIND.SBR \
		CHMFRAME.SBR \
		CHNLIST.SBR \
		CHPRCONN.SBR \
		CHPRDBG.SBR \
		CHPREFS.SBR \
		CHPRFONT.SBR \
		CHUTILS.SBR \
		STDAFX.SBR \
		PUEBLO.SBR \
		CHACCDLG.SBR \
		CHBASDOC.SBR \
		CHBASEVW.SBR \
		CHLICDLG.SBR \
		CHPRNET.SBR


CHABOUT_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\client\msw\chabout.h \
	d:\chaco\include\chhtmwnd.h \
	d:\chaco\include\chtxtwnd.h \
	d:\chaco\include\chscrwnd.h \
	d:\chaco\include\chrect.h \
	d:\chaco\include\chscrlvw.h \
	d:\chaco\include\chsize.h \
	d:\chaco\include\chdc.h \
	d:\chaco\include\chfont.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chpstrls.h \
	d:\chaco\include\templcls\chhtmspl.h


CHCLCORE_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\include\chreg.h \
	d:\chaco\include\chrmenu.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chstrmbl.h \
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
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chmenu.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chmnptrl.h \
	d:\chaco\include\templcls\chmnptrl.inl \
	d:\chaco\include\templcls\chmnitem.h \
	d:\chaco\include\templcls\chmnmap.h \
	d:\chaco\include\templcls\chmnlist.h \
	d:\chaco\include\templcls\chmnlist.inl \
	d:\chaco\include\templcls\chmnblk.h \
	d:\chaco\include\templcls\chmnblk.inl \
	d:\chaco\include\templcls\chmitspl.h \
	d:\chaco\include\templcls\chmnsply.h \
	d:\chaco\include\templcls\chmnitls.h \
	d:\chaco\include\templcls\chmnitls.inl \
	d:\chaco\include\templcls\chstrlst.h \
	d:\chaco\include\templcls\chstrlst.inl \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\include\charch.h \
	d:\chaco\include\chtime.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\client\msw\chmframe.h \
	d:\chaco\include\chsplit.h \
	d:\chaco\include\chperfrm.h \
	d:\chaco\client\msw\chlogind.h \
	d:\chaco\client\msw\chnlist.h \
	d:\chaco\client\msw\chaccdlg.h \
	d:\chaco\client\msw\chlicdlg.h \
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
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\templcls\chmodtre.h \
	d:\chaco\client\msw\chclcore.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\chhook.h \
	d:\chaco\include\chgraphx.h


CHLOGIND_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\client\msw\chlogind.h \
	d:\chaco\client\msw\chnlist.h \
	d:\chaco\include\chreg.h \
	d:\chaco\client\msw\chmframe.h \
	d:\chaco\include\chsplit.h \
	d:\chaco\include\chperfrm.h \
	d:\chaco\client\msw\chclcore.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chhook.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chmsgtyp.h


CHMFRAME_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\client\msw\pueblo.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\client\msw\chabout.h \
	d:\chaco\include\chhtmwnd.h \
	d:\chaco\include\chtxtwnd.h \
	d:\chaco\include\chscrwnd.h \
	d:\chaco\include\chrect.h \
	d:\chaco\include\chscrlvw.h \
	d:\chaco\include\chsize.h \
	d:\chaco\include\chdc.h \
	d:\chaco\include\chfont.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chpstrls.h \
	d:\chaco\include\templcls\chhtmspl.h \
	d:\chaco\client\msw\chclcore.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chperfrm.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chhook.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\include\chsplit.h \
	d:\chaco\include\chrmenu.h \
	d:\chaco\include\chmdata.h \
	d:\chaco\include\chconn.h \
	d:\chaco\include\socketxx.h \
	d:\chaco\include\chsock.h \
	d:\chaco\include\sockstrm.h \
	c:\tools\msvc\include\winsock.h \
	d:\chaco\include\templcls\chsockbf.h \
	d:\chaco\include\protocol.h \
	d:\chaco\include\chmenu.h \
	d:\chaco\include\templcls\chmnptrl.h \
	d:\chaco\include\templcls\chmnptrl.inl \
	d:\chaco\include\templcls\chmnitem.h \
	d:\chaco\include\templcls\chmnmap.h \
	d:\chaco\include\templcls\chmnlist.h \
	d:\chaco\include\templcls\chmnlist.inl \
	d:\chaco\include\templcls\chmnblk.h \
	d:\chaco\include\templcls\chmnblk.inl \
	d:\chaco\include\templcls\chmitspl.h \
	d:\chaco\include\templcls\chmnsply.h \
	d:\chaco\include\templcls\chmnitls.h \
	d:\chaco\include\templcls\chmnitls.inl \
	d:\chaco\include\templcls\chstrlst.h \
	d:\chaco\include\templcls\chstrlst.inl \
	d:\chaco\include\charch.h \
	d:\chaco\include\chtime.h \
	d:\chaco\include\chreg.h \
	d:\chaco\client\msw\chmframe.h


CHNLIST_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\include\chreg.h \
	d:\chaco\client\msw\chnlist.h


CHPRCONN_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\include\chreg.h \
	d:\chaco\client\msw\chclcore.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\chperfrm.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chhook.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\client\msw\chprconn.h


CHPRDBG_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\client\msw\pueblo.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\client\msw\chabout.h \
	d:\chaco\include\chhtmwnd.h \
	d:\chaco\include\chtxtwnd.h \
	d:\chaco\include\chscrwnd.h \
	d:\chaco\include\chrect.h \
	d:\chaco\include\chscrlvw.h \
	d:\chaco\include\chsize.h \
	d:\chaco\include\chdc.h \
	d:\chaco\include\chfont.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chpstrls.h \
	d:\chaco\include\templcls\chhtmspl.h \
	d:\chaco\client\msw\chclcore.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chperfrm.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chhook.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\client\msw\chprdbg.h \
	d:\chaco\include\chreg.h


CHPREFS_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\client\msw\pueblo.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\client\msw\chabout.h \
	d:\chaco\include\chhtmwnd.h \
	d:\chaco\include\chtxtwnd.h \
	d:\chaco\include\chscrwnd.h \
	d:\chaco\include\chrect.h \
	d:\chaco\include\chscrlvw.h \
	d:\chaco\include\chsize.h \
	d:\chaco\include\chdc.h \
	d:\chaco\include\chfont.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chpstrls.h \
	d:\chaco\include\templcls\chhtmspl.h \
	d:\chaco\client\msw\chclcore.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chperfrm.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chhook.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\client\msw\chprefs.h


CHPRFONT_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\include\chreg.h \
	d:\chaco\include\chhtmwnd.h \
	d:\chaco\include\chtxtwnd.h \
	d:\chaco\include\chscrwnd.h \
	d:\chaco\include\chrect.h \
	d:\chaco\include\chscrlvw.h \
	d:\chaco\include\chsize.h \
	d:\chaco\include\chdc.h \
	d:\chaco\include\chfont.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chpstrls.h \
	d:\chaco\include\templcls\chhtmspl.h \
	d:\chaco\client\msw\chclcore.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chperfrm.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chhook.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\client\msw\chprfont.h


CHUTILS_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\client\msw\chutils.h


STDAFX_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h


PUEBLO_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\client\msw\pueblo.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\client\msw\chabout.h \
	d:\chaco\include\chhtmwnd.h \
	d:\chaco\include\chtxtwnd.h \
	d:\chaco\include\chscrwnd.h \
	d:\chaco\include\chrect.h \
	d:\chaco\include\chscrlvw.h \
	d:\chaco\include\chsize.h \
	d:\chaco\include\chdc.h \
	d:\chaco\include\chfont.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chpstrls.h \
	d:\chaco\include\templcls\chhtmspl.h \
	d:\chaco\client\msw\chclcore.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chperfrm.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chhook.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\client\msw\chbasdoc.h \
	d:\chaco\client\msw\chbasevw.h \
	d:\chaco\client\msw\chmframe.h \
	d:\chaco\include\chsplit.h \
	d:\chaco\client\msw\chprefs.h \
	d:\chaco\client\msw\chprconn.h \
	d:\chaco\include\chreg.h \
	d:\chaco\client\msw\chprdbg.h \
	d:\chaco\client\msw\chprfont.h \
	d:\chaco\client\msw\chlogind.h \
	d:\chaco\client\msw\chnlist.h \
	d:\chaco\client\msw\chprnet.h \
	d:\chaco\include\chrmenu.h \
	d:\chaco\include\chmdata.h \
	d:\chaco\include\chconn.h \
	d:\chaco\include\socketxx.h \
	d:\chaco\include\chsock.h \
	d:\chaco\include\sockstrm.h \
	c:\tools\msvc\include\winsock.h \
	d:\chaco\include\templcls\chsockbf.h \
	d:\chaco\include\protocol.h \
	d:\chaco\include\chmenu.h \
	d:\chaco\include\templcls\chmnptrl.h \
	d:\chaco\include\templcls\chmnptrl.inl \
	d:\chaco\include\templcls\chmnitem.h \
	d:\chaco\include\templcls\chmnmap.h \
	d:\chaco\include\templcls\chmnlist.h \
	d:\chaco\include\templcls\chmnlist.inl \
	d:\chaco\include\templcls\chmnblk.h \
	d:\chaco\include\templcls\chmnblk.inl \
	d:\chaco\include\templcls\chmitspl.h \
	d:\chaco\include\templcls\chmnsply.h \
	d:\chaco\include\templcls\chmnitls.h \
	d:\chaco\include\templcls\chmnitls.inl \
	d:\chaco\include\templcls\chstrlst.h \
	d:\chaco\include\templcls\chstrlst.inl \
	c:\tools\msvc\include\ctl3d.h


CHACCDLG_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\client\msw\pueblo.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\client\msw\chabout.h \
	d:\chaco\include\chhtmwnd.h \
	d:\chaco\include\chtxtwnd.h \
	d:\chaco\include\chscrwnd.h \
	d:\chaco\include\chrect.h \
	d:\chaco\include\chscrlvw.h \
	d:\chaco\include\chsize.h \
	d:\chaco\include\chdc.h \
	d:\chaco\include\chfont.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chpstrls.h \
	d:\chaco\include\templcls\chhtmspl.h \
	d:\chaco\client\msw\chclcore.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chperfrm.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chhook.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\client\msw\chaccdlg.h


CHBASDOC_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\client\msw\pueblo.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\client\msw\chabout.h \
	d:\chaco\include\chhtmwnd.h \
	d:\chaco\include\chtxtwnd.h \
	d:\chaco\include\chscrwnd.h \
	d:\chaco\include\chrect.h \
	d:\chaco\include\chscrlvw.h \
	d:\chaco\include\chsize.h \
	d:\chaco\include\chdc.h \
	d:\chaco\include\chfont.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chpstrls.h \
	d:\chaco\include\templcls\chhtmspl.h \
	d:\chaco\client\msw\chclcore.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chperfrm.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chhook.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\client\msw\chbasdoc.h


CHBASEVW_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\client\msw\pueblo.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\client\msw\chabout.h \
	d:\chaco\include\chhtmwnd.h \
	d:\chaco\include\chtxtwnd.h \
	d:\chaco\include\chscrwnd.h \
	d:\chaco\include\chrect.h \
	d:\chaco\include\chscrlvw.h \
	d:\chaco\include\chsize.h \
	d:\chaco\include\chdc.h \
	d:\chaco\include\chfont.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chpstrls.h \
	d:\chaco\include\templcls\chhtmspl.h \
	d:\chaco\client\msw\chclcore.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chperfrm.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chhook.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\client\msw\chbasevw.h


CHLICDLG_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\client\msw\pueblo.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\client\msw\chabout.h \
	d:\chaco\include\chhtmwnd.h \
	d:\chaco\include\chtxtwnd.h \
	d:\chaco\include\chscrwnd.h \
	d:\chaco\include\chrect.h \
	d:\chaco\include\chscrlvw.h \
	d:\chaco\include\chsize.h \
	d:\chaco\include\chdc.h \
	d:\chaco\include\chfont.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chpstrls.h \
	d:\chaco\include\templcls\chhtmspl.h \
	d:\chaco\client\msw\chclcore.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chperfrm.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chhook.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\include\chreg.h \
	d:\chaco\client\msw\chlicdlg.h


CHPRNET_DEP = d:\chaco\client\msw\stdafx.h \
	d:\chaco\include\chtypes.h \
	d:\chaco\include\chexcept.h \
	d:\chaco\include\chconst.h \
	d:\chaco\include\chreg.h \
	d:\chaco\client\msw\pueblo.h \
	d:\chaco\include\chmodule.h \
	d:\chaco\include\chstrmbl.h \
	d:\chaco\include\chvers.h \
	d:\chaco\include\chmsg.h \
	d:\chaco\include\chdispat.h \
	d:\chaco\include\chsplay.h \
	d:\chaco\client\msw\chabout.h \
	d:\chaco\include\chhtmwnd.h \
	d:\chaco\include\chtxtwnd.h \
	d:\chaco\include\chscrwnd.h \
	d:\chaco\include\chrect.h \
	d:\chaco\include\chscrlvw.h \
	d:\chaco\include\chsize.h \
	d:\chaco\include\chdc.h \
	d:\chaco\include\chfont.h \
	d:\chaco\include\chlist.h \
	d:\chaco\include\templcls\chlsthlp.inl \
	d:\chaco\include\templcls\chpstrls.h \
	d:\chaco\include\templcls\chhtmspl.h \
	d:\chaco\client\msw\chclcore.h \
	d:\chaco\include\chcore.h \
	d:\chaco\include\chmodmgr.h \
	d:\chaco\include\chsysinf.h \
	d:\chaco\include\chperfrm.h \
	d:\chaco\include\templcls\chmqlst.h \
	d:\chaco\include\templcls\chmqlst.inl \
	d:\chaco\include\templcls\chntfyls.h \
	d:\chaco\include\templcls\chntfyls.inl \
	d:\chaco\include\chmsgcon.h \
	d:\chaco\include\chhttp.h \
	d:\chaco\include\sockinet.h \
	d:\chaco\include\chacct.h \
	d:\chaco\include\chclinfo.h \
	d:\chaco\include\chdata.h \
	d:\chaco\include\chhook.h \
	d:\chaco\include\chmsgtyp.h \
	d:\chaco\client\msw\chprnet.h


PUEBLO_RCDEP = d:\chaco\client\msw\res\idr_main.ico \
	d:\chaco\client\msw\res\chaco.bmp \
	d:\chaco\client\msw\res\chaco.rc2


all:	$(PROJ).EXE $(PROJ).BSC

CHABOUT.OBJ:	CHABOUT.CPP $(CHABOUT_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c CHABOUT.CPP

CHCLCORE.OBJ:	CHCLCORE.CPP $(CHCLCORE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHCLCORE.CPP

CHLOGIND.OBJ:	CHLOGIND.CPP $(CHLOGIND_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHLOGIND.CPP

CHMFRAME.OBJ:	CHMFRAME.CPP $(CHMFRAME_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHMFRAME.CPP

CHNLIST.OBJ:	CHNLIST.CPP $(CHNLIST_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHNLIST.CPP

CHPRCONN.OBJ:	CHPRCONN.CPP $(CHPRCONN_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHPRCONN.CPP

CHPRDBG.OBJ:	CHPRDBG.CPP $(CHPRDBG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHPRDBG.CPP

CHPREFS.OBJ:	CHPREFS.CPP $(CHPREFS_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHPREFS.CPP

CHPRFONT.OBJ:	CHPRFONT.CPP $(CHPRFONT_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHPRFONT.CPP

CHUTILS.OBJ:	CHUTILS.CPP $(CHUTILS_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHUTILS.CPP

STDAFX.OBJ:	STDAFX.CPP $(STDAFX_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c STDAFX.CPP

PUEBLO.OBJ:	PUEBLO.CPP $(PUEBLO_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c PUEBLO.CPP

CHACCDLG.OBJ:	CHACCDLG.CPP $(CHACCDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHACCDLG.CPP

CHBASDOC.OBJ:	CHBASDOC.CPP $(CHBASDOC_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHBASDOC.CPP

CHBASEVW.OBJ:	CHBASEVW.CPP $(CHBASEVW_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHBASEVW.CPP

CHLICDLG.OBJ:	CHLICDLG.CPP $(CHLICDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHLICDLG.CPP

CHPRNET.OBJ:	CHPRNET.CPP $(CHPRNET_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CHPRNET.CPP

PUEBLO.RES:	PUEBLO.RC $(PUEBLO_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r PUEBLO.RC


$(PROJ).EXE::	PUEBLO.RES

$(PROJ).EXE::	CHABOUT.OBJ CHCLCORE.OBJ CHLOGIND.OBJ CHMFRAME.OBJ CHNLIST.OBJ CHPRCONN.OBJ \
	CHPRDBG.OBJ CHPREFS.OBJ CHPRFONT.OBJ CHUTILS.OBJ STDAFX.OBJ PUEBLO.OBJ CHACCDLG.OBJ \
	CHBASDOC.OBJ CHBASEVW.OBJ CHLICDLG.OBJ CHPRNET.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
CHABOUT.OBJ +
CHCLCORE.OBJ +
CHLOGIND.OBJ +
CHMFRAME.OBJ +
CHNLIST.OBJ +
CHPRCONN.OBJ +
CHPRDBG.OBJ +
CHPREFS.OBJ +
CHPRFONT.OBJ +
CHUTILS.OBJ +
STDAFX.OBJ +
PUEBLO.OBJ +
CHACCDLG.OBJ +
CHBASDOC.OBJ +
CHBASEVW.OBJ +
CHLICDLG.OBJ +
CHPRNET.OBJ +
$(OBJS_EXT)
$(PROJ).EXE
$(MAPFILE)
C:\TOOLS\MSVC\LIB\+
C:\TOOLS\MSVC\MFC\LIB\+
D:\TOOLS\MSVC20\LIB\+
d:\chaco\lib\+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) PUEBLO.RES $@
	@copy $(PROJ).CRF MSVC.BND

$(PROJ).EXE::	PUEBLO.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) PUEBLO.RES $@

run: $(PROJ).EXE
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
