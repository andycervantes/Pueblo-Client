# Microsoft Visual C++ Generated NMAKE File, Format Version 2.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Release" && "$(CFG)" != "Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "ChWorld.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

################################################################################
# Begin Project
# PROP Target_Last_Scanned "Win32 Debug"
MTL=MkTypLib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "/chaco/bin/Release/modules"
# PROP Intermediate_Dir "release"
OUTDIR=/chaco/bin/Release/modules
INTDIR=.\release

ALL : $(OUTDIR)/ChWorld.dll $(OUTDIR)/ChWorld.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE CPP /nologo /MT /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /G5 /MD /W3 /GX /Zi /YX"headers.h" /Og /Oi /Os /Oy /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /Fr /c
CPP_PROJ=/nologo /G5 /MD /W3 /GX /Zi /YX"headers.h" /Og /Oi /Os /Oy /D "NDEBUG"\
 /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D\
 "_AFXDLL" /D "_MBCS" /Fr$(INTDIR)/ /Fp$(OUTDIR)/"ChWorld.pch" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChWorld.pdb" /c 
CPP_OBJS=.\release/
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"ChWorld.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChWorld.bsc" 
BSC32_SBRS= \
	$(INTDIR)/Dll.sbr \
	$(INTDIR)/ChWInfo.sbr \
	$(INTDIR)/ChWListD.sbr \
	$(INTDIR)/ChWList.sbr \
	$(INTDIR)/ChWConn.sbr \
	$(INTDIR)/ChWorld.sbr \
	$(INTDIR)/ChSCWiz.sbr \
	$(INTDIR)/ChSaveAs.sbr \
	$(INTDIR)/ChHist.sbr \
	$(INTDIR)/ChKeyMapType.sbr \
	$(INTDIR)/ChTextInput.sbr \
	$(INTDIR)/ChPrefsNotify.sbr \
	$(INTDIR)/ChPrefsWorld.sbr \
	$(INTDIR)/ChTextOutput.sbr \
	$(INTDIR)/ChWorldStream.sbr \
	$(INTDIR)/ChAbout.sbr \
	$(INTDIR)/ChWorldCmdLine.sbr \
	$(INTDIR)/ChQuickConnect.sbr \
	$(INTDIR)/ChConnectDlg.sbr \
	$(INTDIR)/TinTinVars.sbr \
	$(INTDIR)/TinTinAction.sbr \
	$(INTDIR)/TinTinUtils.sbr \
	$(INTDIR)/TinTinList.sbr \
	$(INTDIR)/TinTinInfo.sbr \
	$(INTDIR)/TinTinFiles.sbr \
	$(INTDIR)/TinTinMisc.sbr \
	$(INTDIR)/TinTinParse.sbr \
	$(INTDIR)/TinTinAlias.sbr \
	$(INTDIR)/TinTinMain.sbr \
	$(INTDIR)/TinTinPath.sbr \
	$(INTDIR)/TinTinIf.sbr \
	$(INTDIR)/TinTinTicks.sbr \
	$(INTDIR)/TinTinSubs.sbr \
	$(INTDIR)/TinTinSettings.sbr \
	$(INTDIR)/TinTinSession.sbr

$(OUTDIR)/ChWorld.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386
# ADD LINK32 winmm.lib Pueblo32.lib /NOLOGO /BASE:0x20000000 /SUBSYSTEM:windows /DLL /MACHINE:I386
# SUBTRACT LINK32 /DEBUG
LINK32_FLAGS=winmm.lib Pueblo32.lib /NOLOGO /BASE:0x20000000 /SUBSYSTEM:windows\
 /DLL /INCREMENTAL:no /PDB:$(OUTDIR)/"ChWorld.pdb" /MACHINE:I386\
 /DEF:".\ChWorld.def" /OUT:$(OUTDIR)/"ChWorld.dll"\
 /IMPLIB:$(OUTDIR)/"ChWorld.lib" 
DEF_FILE=.\ChWorld.def
LINK32_OBJS= \
	$(INTDIR)/Dll.obj \
	$(INTDIR)/ChWInfo.obj \
	$(INTDIR)/ChWListD.obj \
	$(INTDIR)/ChWList.obj \
	$(INTDIR)/ChWConn.obj \
	$(INTDIR)/ChWorld.res \
	$(INTDIR)/ChWorld.obj \
	$(INTDIR)/ChSCWiz.obj \
	$(INTDIR)/ChSaveAs.obj \
	$(INTDIR)/ChHist.obj \
	$(INTDIR)/ChKeyMapType.obj \
	$(INTDIR)/ChTextInput.obj \
	$(INTDIR)/ChPrefsNotify.obj \
	$(INTDIR)/ChPrefsWorld.obj \
	$(INTDIR)/ChTextOutput.obj \
	$(INTDIR)/ChWorldStream.obj \
	$(INTDIR)/ChAbout.obj \
	$(INTDIR)/ChWorldCmdLine.obj \
	$(INTDIR)/ChQuickConnect.obj \
	$(INTDIR)/ChConnectDlg.obj \
	$(INTDIR)/TinTinVars.obj \
	$(INTDIR)/TinTinAction.obj \
	$(INTDIR)/TinTinUtils.obj \
	$(INTDIR)/TinTinList.obj \
	$(INTDIR)/TinTinInfo.obj \
	$(INTDIR)/TinTinFiles.obj \
	$(INTDIR)/TinTinMisc.obj \
	$(INTDIR)/TinTinParse.obj \
	$(INTDIR)/TinTinAlias.obj \
	$(INTDIR)/TinTinMain.obj \
	$(INTDIR)/TinTinPath.obj \
	$(INTDIR)/TinTinIf.obj \
	$(INTDIR)/TinTinTicks.obj \
	$(INTDIR)/TinTinSubs.obj \
	$(INTDIR)/TinTinSettings.obj \
	$(INTDIR)/TinTinSession.obj

$(OUTDIR)/ChWorld.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "/chaco/bin/debug/modules/"
# PROP Intermediate_Dir "debug"
OUTDIR=/chaco/bin/debug/modules
INTDIR=.\debug

ALL : $(OUTDIR)/ChWorld.dll $(OUTDIR)/ChWorld.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /YX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /G5 /MD /W3 /GX /Zi /YX"headers.h" /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /FR /c
CPP_PROJ=/nologo /G5 /MD /W3 /GX /Zi /YX"headers.h" /Od /D "_DEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D\
 "_MBCS" /FR$(INTDIR)/ /Fp$(OUTDIR)/"ChWorld.pch" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChWorld.pdb" /c 
CPP_OBJS=.\debug/
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"ChWorld.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChWorld.bsc" 
BSC32_SBRS= \
	$(INTDIR)/Dll.sbr \
	$(INTDIR)/ChWInfo.sbr \
	$(INTDIR)/ChWListD.sbr \
	$(INTDIR)/ChWList.sbr \
	$(INTDIR)/ChWConn.sbr \
	$(INTDIR)/ChWorld.sbr \
	$(INTDIR)/ChSCWiz.sbr \
	$(INTDIR)/ChSaveAs.sbr \
	$(INTDIR)/ChHist.sbr \
	$(INTDIR)/ChKeyMapType.sbr \
	$(INTDIR)/ChTextInput.sbr \
	$(INTDIR)/ChPrefsNotify.sbr \
	$(INTDIR)/ChPrefsWorld.sbr \
	$(INTDIR)/ChTextOutput.sbr \
	$(INTDIR)/ChWorldStream.sbr \
	$(INTDIR)/ChAbout.sbr \
	$(INTDIR)/ChWorldCmdLine.sbr \
	$(INTDIR)/ChQuickConnect.sbr \
	$(INTDIR)/ChConnectDlg.sbr \
	$(INTDIR)/TinTinVars.sbr \
	$(INTDIR)/TinTinAction.sbr \
	$(INTDIR)/TinTinUtils.sbr \
	$(INTDIR)/TinTinList.sbr \
	$(INTDIR)/TinTinInfo.sbr \
	$(INTDIR)/TinTinFiles.sbr \
	$(INTDIR)/TinTinMisc.sbr \
	$(INTDIR)/TinTinParse.sbr \
	$(INTDIR)/TinTinAlias.sbr \
	$(INTDIR)/TinTinMain.sbr \
	$(INTDIR)/TinTinPath.sbr \
	$(INTDIR)/TinTinIf.sbr \
	$(INTDIR)/TinTinTicks.sbr \
	$(INTDIR)/TinTinSubs.sbr \
	$(INTDIR)/TinTinSettings.sbr \
	$(INTDIR)/TinTinSession.sbr

$(OUTDIR)/ChWorld.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386
# ADD LINK32 winmm.lib Pueblo32.lib /NOLOGO /BASE:0x20000000 /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /OUT:"/chaco/bin/debug/modules/ChWorld.dll"
# SUBTRACT LINK32 /MAP /NODEFAULTLIB
LINK32_FLAGS=winmm.lib Pueblo32.lib /NOLOGO /BASE:0x20000000 /SUBSYSTEM:windows\
 /DLL /INCREMENTAL:yes /PDB:$(OUTDIR)/"ChWorld.pdb" /DEBUG /MACHINE:I386\
 /DEF:".\ChWorld.def" /OUT:$(OUTDIR)/"ChWorld.dll"\
 /IMPLIB:$(OUTDIR)/"ChWorld.lib" /OUT:"/chaco/bin/debug/modules/ChWorld.dll"  
DEF_FILE=.\ChWorld.def
LINK32_OBJS= \
	$(INTDIR)/Dll.obj \
	$(INTDIR)/ChWInfo.obj \
	$(INTDIR)/ChWListD.obj \
	$(INTDIR)/ChWList.obj \
	$(INTDIR)/ChWConn.obj \
	$(INTDIR)/ChWorld.res \
	$(INTDIR)/ChWorld.obj \
	$(INTDIR)/ChSCWiz.obj \
	$(INTDIR)/ChSaveAs.obj \
	$(INTDIR)/ChHist.obj \
	$(INTDIR)/ChKeyMapType.obj \
	$(INTDIR)/ChTextInput.obj \
	$(INTDIR)/ChPrefsNotify.obj \
	$(INTDIR)/ChPrefsWorld.obj \
	$(INTDIR)/ChTextOutput.obj \
	$(INTDIR)/ChWorldStream.obj \
	$(INTDIR)/ChAbout.obj \
	$(INTDIR)/ChWorldCmdLine.obj \
	$(INTDIR)/ChQuickConnect.obj \
	$(INTDIR)/ChConnectDlg.obj \
	$(INTDIR)/TinTinVars.obj \
	$(INTDIR)/TinTinAction.obj \
	$(INTDIR)/TinTinUtils.obj \
	$(INTDIR)/TinTinList.obj \
	$(INTDIR)/TinTinInfo.obj \
	$(INTDIR)/TinTinFiles.obj \
	$(INTDIR)/TinTinMisc.obj \
	$(INTDIR)/TinTinParse.obj \
	$(INTDIR)/TinTinAlias.obj \
	$(INTDIR)/TinTinMain.obj \
	$(INTDIR)/TinTinPath.obj \
	$(INTDIR)/TinTinIf.obj \
	$(INTDIR)/TinTinTicks.obj \
	$(INTDIR)/TinTinSubs.obj \
	$(INTDIR)/TinTinSettings.obj \
	$(INTDIR)/TinTinSession.obj

$(OUTDIR)/ChWorld.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Group "Source Files"

################################################################################
# Begin Source File

SOURCE=.\Dll.cpp
DEP_DLL_C=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/Dll.obj :  $(SOURCE)  $(DEP_DLL_C) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWInfo.cpp
DEP_CHWIN=\
	.\headers.h\
	\chaco\include\ChCore.h\
	.\ChSCWiz.h\
	.\ChWInfo.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChWizard.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChWInfo.obj :  $(SOURCE)  $(DEP_CHWIN) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWListD.cpp
DEP_CHWLI=\
	.\headers.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChUtil.h\
	.\ChWListD.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChDlg.h\
	.\ChWList.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChDb.h\
	.\templcls\ChMdPLst.h\
	.\templcls\ChMdPLst.inl

$(INTDIR)/ChWListD.obj :  $(SOURCE)  $(DEP_CHWLI) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWList.cpp
DEP_CHWLIS=\
	.\headers.h\
	.\ChWInfo.h\
	.\ChWList.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChList.h\
	\chaco\include\ChReg.h\
	.\templcls\ChMdPLst.h\
	.\templcls\ChMdPLst.inl\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChDb.h\
	\chaco\include\ChData.h

$(INTDIR)/ChWList.obj :  $(SOURCE)  $(DEP_CHWLIS) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWConn.cpp
DEP_CHWCO=\
	.\headers.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChSound.h\
	.\World.h\
	.\ChWConn.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChConn.h\
	.\ChWorldCmdLine.h\
	.\TinTin.h\
	.\ChTextOutput.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	.\TinTinSettings.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChHtmlSettings.h\
	\chaco\include\ChPane.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	.\TinTinList.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChWnd.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChWConn.obj :  $(SOURCE)  $(DEP_CHWCO) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWorld.rc
DEP_CHWOR=\
	.\res\planet.ico\
	.\res\wheel.ico\
	.\res\chaco.ico

$(INTDIR)/ChWorld.res :  $(SOURCE)  $(DEP_CHWOR) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWorld.cpp
DEP_CHWORL=\
	.\headers.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChGraphx.h\
	..\..\unix\ChWorld\UnixRes.h\
	.\ChWList.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChMenu.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChSound.h\
	\chaco\include\ChWorld.h\
	.\World.h\
	.\ChWConn.h\
	.\ChTextInput.h\
	.\ChWorldStream.h\
	.\ChConnectDlg.h\
	.\ChWListD.h\
	.\ChAbout.h\
	.\ChPrefsWorld.h\
	.\ChPrefsNotify.h\
	.\ChQuickConnect.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChUtil.h\
	.\ChWInfo.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChList.h\
	.\templcls\ChMdPLst.h\
	.\templcls\ChMdPLst.inl\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChVers.h\
	\chaco\include\templcls\ChMnPtrl.h\
	\chaco\include\templcls\ChMnPtrl.inl\
	\chaco\include\ChConn.h\
	.\ChWorldCmdLine.h\
	.\TinTin.h\
	.\ChTextOutput.h\
	.\ChHist.h\
	.\ChKeyMapType.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChPuebloScript.h\
	\chaco\include\ChDlg.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	.\TinTinSettings.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChHtmlSettings.h\
	\chaco\include\ChPane.h\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChKeyMap.h\
	\chaco\include\ChArgList.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	.\TinTinList.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChWnd.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChWorld.obj :  $(SOURCE)  $(DEP_CHWORL) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWorld.def
# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSCWiz.cpp
DEP_CHSCW=\
	.\headers.h\
	\chaco\include\ChCore.h\
	.\ChSCWiz.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChWizard.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChSCWiz.obj :  $(SOURCE)  $(DEP_CHSCW) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSaveAs.cpp
DEP_CHSAV=\
	.\headers.h\
	\chaco\include\ChSound.h\
	.\ChSaveAs.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChSaveAs.obj :  $(SOURCE)  $(DEP_CHSAV) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHist.cpp
DEP_CHHIS=\
	.\headers.h\
	.\ChHist.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChWType.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChData.h

$(INTDIR)/ChHist.obj :  $(SOURCE)  $(DEP_CHHIS) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChKeyMapType.cpp
DEP_CHKEY=\
	.\headers.h\
	\chaco\include\ChArch.h\
	.\ChKeyMapType.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChKeyMap.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChKeyMapType.obj :  $(SOURCE)  $(DEP_CHKEY) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTextInput.cpp
DEP_CHTEX=\
	.\headers.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChSplit.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChHtpCon.h\
	.\World.h\
	.\ChTextInput.h\
	.\ChTextOutput.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChConn.h\
	.\ChWorldCmdLine.h\
	.\TinTin.h\
	.\ChHist.h\
	.\ChKeyMapType.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChHtmlSettings.h\
	\chaco\include\ChPane.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChDb.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	.\TinTinSettings.h\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChKeyMap.h\
	\chaco\include\ChWnd.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	.\TinTinList.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChTextInput.obj :  $(SOURCE)  $(DEP_CHTEX) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrefsNotify.cpp
DEP_CHPRE=\
	.\headers.h\
	\chaco\include\ChWorld.h\
	.\ChPrefsNotify.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	.\ChWInfo.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\ChDb.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChPrefsNotify.obj :  $(SOURCE)  $(DEP_CHPRE) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrefsWorld.cpp
DEP_CHPREF=\
	.\headers.h\
	\chaco\include\ChWorld.h\
	.\ChPrefsWorld.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	.\ChWInfo.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChPage.h\
	.\ChKeyMapType.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChKeyMap.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChPrefsWorld.obj :  $(SOURCE)  $(DEP_CHPREF) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTextOutput.cpp
DEP_CHTEXT=\
	.\headers.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChCore.h\
	.\World.h\
	.\ChTextOutput.h\
	.\ChTextInput.h\
	.\ChWorldStream.h\
	.\ChSaveAs.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChConn.h\
	.\ChWorldCmdLine.h\
	.\TinTin.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChHtmlSettings.h\
	\chaco\include\ChPane.h\
	.\ChHist.h\
	.\ChKeyMapType.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChPuebloScript.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	.\TinTinSettings.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChWnd.h\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChKeyMap.h\
	\chaco\include\ChArgList.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	.\TinTinList.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChTextOutput.obj :  $(SOURCE)  $(DEP_CHTEXT) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWorldStream.cpp
DEP_CHWORLD=\
	.\headers.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChCore.h\
	.\World.h\
	.\ChWorldStream.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChConn.h\
	.\ChWorldCmdLine.h\
	.\TinTin.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChPuebloScript.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChWType.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChData.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	.\TinTinSettings.h\
	\chaco\include\ChArgList.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	.\TinTinList.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChWorldStream.obj :  $(SOURCE)  $(DEP_CHWORLD) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAbout.cpp
DEP_CHABO=\
	.\headers.h\
	.\ChAbout.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChAbout.obj :  $(SOURCE)  $(DEP_CHABO) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWorldCmdLine.cpp
DEP_CHWORLDC=\
	.\headers.h\
	\chaco\include\ChArgList.h\
	.\ChWorldCmdLine.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChWType.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChData.h

$(INTDIR)/ChWorldCmdLine.obj :  $(SOURCE)  $(DEP_CHWORLDC) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChQuickConnect.cpp
DEP_CHQUI=\
	.\headers.h\
	\chaco\include\ChWorld.h\
	.\ChQuickConnect.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	.\ChWInfo.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChDlg.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChQuickConnect.obj :  $(SOURCE)  $(DEP_CHQUI) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChConnectDlg.cpp
DEP_CHCON=\
	.\headers.h\
	.\World.h\
	.\ChConnectDlg.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChConn.h\
	.\ChWorldCmdLine.h\
	.\TinTin.h\
	\chaco\include\ChDlg.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	.\TinTinSettings.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	.\TinTinList.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChConnectDlg.obj :  $(SOURCE)  $(DEP_CHCON) $(INTDIR)

# End Source File
# End Group
################################################################################
# Begin Group "TinTin"

################################################################################
# Begin Source File

SOURCE=.\TinTinVars.cpp
DEP_TINTI=\
	.\headers.h\
	.\TinTin.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	.\TinTinSettings.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	.\TinTinList.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinVars.obj :  $(SOURCE)  $(DEP_TINTI) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinAction.cpp
DEP_TINTIN=\
	.\headers.h\
	.\TinTin.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	.\TinTinSettings.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	.\TinTinList.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinAction.obj :  $(SOURCE)  $(DEP_TINTIN) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinUtils.cpp
DEP_TINTINU=\
	\chaco\include\ChTypes.h\
	.\TinTin.h\
	.\TinTinSettings.h\
	.\TinTinList.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinUtils.obj :  $(SOURCE)  $(DEP_TINTINU) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinList.cpp
DEP_TINTINL=\
	\chaco\include\ChTypes.h\
	.\TinTin.h\
	.\TinTinSettings.h\
	.\TinTinList.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinList.obj :  $(SOURCE)  $(DEP_TINTINL) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinInfo.cpp
DEP_TINTINI=\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDlg.h\
	.\headers.h\
	.\TinTinInfo.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinInfo.obj :  $(SOURCE)  $(DEP_TINTINI) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinFiles.cpp
DEP_TINTINF=\
	.\headers.h\
	.\TinTin.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	.\TinTinSettings.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	.\TinTinList.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinFiles.obj :  $(SOURCE)  $(DEP_TINTINF) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinMisc.cpp
DEP_TINTINM=\
	\chaco\include\ChTypes.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChDlg.h\
	.\headers.h\
	.\World.h\
	.\ChTextInput.h\
	.\ChTextOutput.h\
	.\TinTin.h\
	.\TinTinInfo.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChConn.h\
	.\ChWorldCmdLine.h\
	.\ChHist.h\
	.\ChKeyMapType.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChHtmlSettings.h\
	\chaco\include\ChPane.h\
	.\TinTinSettings.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChWType.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChKeyMap.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChWnd.h\
	.\TinTinList.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/TinTinMisc.obj :  $(SOURCE)  $(DEP_TINTINM) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinParse.cpp
DEP_TINTINP=\
	.\headers.h\
	\chaco\include\ChCore.h\
	.\TinTin.h\
	.\World.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	.\TinTinSettings.h\
	\chaco\include\ChConn.h\
	.\ChWorldCmdLine.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	.\TinTinList.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/TinTinParse.obj :  $(SOURCE)  $(DEP_TINTINP) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinAlias.cpp
DEP_TINTINA=\
	.\headers.h\
	.\TinTin.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	.\TinTinSettings.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	.\TinTinList.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinAlias.obj :  $(SOURCE)  $(DEP_TINTINA) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinMain.cpp
DEP_TINTINMA=\
	.\headers.h\
	\chaco\include\ChReg.h\
	.\TinTin.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChDb.h\
	.\TinTinSettings.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	.\TinTinList.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinMain.obj :  $(SOURCE)  $(DEP_TINTINMA) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinPath.cpp
DEP_TINTINPA=\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDlg.h\
	.\headers.h\
	.\World.h\
	.\ChTextInput.h\
	.\ChTextOutput.h\
	.\TinTin.h\
	.\TinTinInfo.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChConn.h\
	.\ChWorldCmdLine.h\
	.\ChHist.h\
	.\ChKeyMapType.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChHtmlSettings.h\
	\chaco\include\ChPane.h\
	.\TinTinSettings.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChKeyMap.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChWnd.h\
	.\TinTinList.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/TinTinPath.obj :  $(SOURCE)  $(DEP_TINTINPA) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinIf.cpp
DEP_TINTINIF=\
	.\headers.h\
	.\TinTin.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	.\TinTinSettings.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	.\TinTinList.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinIf.obj :  $(SOURCE)  $(DEP_TINTINIF) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinTicks.cpp
DEP_TINTINT=\
	.\headers.h\
	.\World.h\
	.\TinTin.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChConn.h\
	.\ChWorldCmdLine.h\
	.\TinTinSettings.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	.\TinTinList.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/TinTinTicks.obj :  $(SOURCE)  $(DEP_TINTINT) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinSubs.cpp
DEP_TINTINS=\
	.\headers.h\
	.\TinTin.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	.\TinTinSettings.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	.\TinTinList.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinSubs.obj :  $(SOURCE)  $(DEP_TINTINS) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinSettings.cpp
DEP_TINTINSE=\
	\chaco\include\ChTypes.h\
	.\TinTin.h\
	.\TinTinSettings.h\
	.\TinTinList.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinSettings.obj :  $(SOURCE)  $(DEP_TINTINSE) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinSession.cpp
DEP_TINTINSES=\
	.\headers.h\
	\chaco\include\ChCore.h\
	.\TinTin.h\
	.\World.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChWInfo.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	.\TinTinSettings.h\
	\chaco\include\ChConn.h\
	.\ChWorldCmdLine.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	.\TinTinList.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/TinTinSession.obj :  $(SOURCE)  $(DEP_TINTINSES) $(INTDIR)

# End Source File
# End Group
# End Project
################################################################################
