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
!MESSAGE NMAKE /f "ChText.mak" CFG="Win32 Debug"
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
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "/chaco/bin/Release"
# PROP Intermediate_Dir "WinRel"
OUTDIR=/chaco/bin/Release
INTDIR=.\WinRel

ALL : $(OUTDIR)/ChText.dll $(OUTDIR)/ChText.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE CPP /nologo /MT /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /G5 /MD /W3 /GX /YX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /G5 /MD /W3 /GX /YX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS"\
 /Fp$(OUTDIR)/"ChText.pch" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\WinRel/
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"ChText.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChText.bsc" 
BSC32_SBRS= \
	

$(OUTDIR)/ChText.bsc : $(OUTDIR)  $(BSC32_SBRS)
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib Pueblo32.lib /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib Pueblo32.lib /NOLOGO /SUBSYSTEM:windows /DLL\
 /INCREMENTAL:no /PDB:$(OUTDIR)/"ChText.pdb" /MACHINE:I386 /DEF:".\ChText.def"\
 /OUT:$(OUTDIR)/"ChText.dll" /IMPLIB:$(OUTDIR)/"ChText.lib" 
DEF_FILE=.\ChText.def
LINK32_OBJS= \
	$(INTDIR)/headers.obj \
	$(INTDIR)/Dll.obj \
	$(INTDIR)/ChText.obj \
	$(INTDIR)/ChTxtIn.obj \
	$(INTDIR)/ChTxtOut.obj \
	$(INTDIR)/ChText.res \
	$(INTDIR)/ChHist.obj \
	$(INTDIR)/ChPrefs.obj \
	$(INTDIR)/ChKeyMapType.obj \
	$(INTDIR)/ChTextStream.obj \
	$(INTDIR)/TinTinVars.obj \
	$(INTDIR)/TinTinUtils.obj \
	$(INTDIR)/TinTinParse.obj \
	$(INTDIR)/TinTinMisc.obj \
	$(INTDIR)/TinTinList.obj \
	$(INTDIR)/TinTinAction.obj \
	$(INTDIR)/TinTinAlias.obj \
	$(INTDIR)/TinTinWizList.obj \
	$(INTDIR)/TinTinFiles.obj \
	$(INTDIR)/TinTinInfo.obj

$(OUTDIR)/ChText.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "/chaco/bin/Debug"
# PROP Intermediate_Dir "WinDebug"
OUTDIR=/chaco/bin/Debug
INTDIR=.\WinDebug

ALL : $(OUTDIR)/ChText.dll $(OUTDIR)/ChText.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /YX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /G5 /MD /W3 /GX /Zi /YX /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /FR /c
CPP_PROJ=/nologo /G5 /MD /W3 /GX /Zi /YX /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"ChText.pch" /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChText.pdb"\
 /c 
CPP_OBJS=.\WinDebug/
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"ChText.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChText.bsc" 
BSC32_SBRS= \
	$(INTDIR)/headers.sbr \
	$(INTDIR)/Dll.sbr \
	$(INTDIR)/ChText.sbr \
	$(INTDIR)/ChTxtIn.sbr \
	$(INTDIR)/ChTxtOut.sbr \
	$(INTDIR)/ChHist.sbr \
	$(INTDIR)/ChPrefs.sbr \
	$(INTDIR)/ChKeyMapType.sbr \
	$(INTDIR)/ChTextStream.sbr \
	$(INTDIR)/TinTinVars.sbr \
	$(INTDIR)/TinTinUtils.sbr \
	$(INTDIR)/TinTinParse.sbr \
	$(INTDIR)/TinTinMisc.sbr \
	$(INTDIR)/TinTinList.sbr \
	$(INTDIR)/TinTinAction.sbr \
	$(INTDIR)/TinTinAlias.sbr \
	$(INTDIR)/TinTinWizList.sbr \
	$(INTDIR)/TinTinFiles.sbr \
	$(INTDIR)/TinTinInfo.sbr

$(OUTDIR)/ChText.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib Pueblo32.lib /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib Pueblo32.lib /NOLOGO /SUBSYSTEM:windows /DLL\
 /INCREMENTAL:yes /PDB:$(OUTDIR)/"ChText.pdb" /DEBUG /MACHINE:I386\
 /DEF:".\ChText.def" /OUT:$(OUTDIR)/"ChText.dll" /IMPLIB:$(OUTDIR)/"ChText.lib" 
DEF_FILE=.\ChText.def
LINK32_OBJS= \
	$(INTDIR)/headers.obj \
	$(INTDIR)/Dll.obj \
	$(INTDIR)/ChText.obj \
	$(INTDIR)/ChTxtIn.obj \
	$(INTDIR)/ChTxtOut.obj \
	$(INTDIR)/ChText.res \
	$(INTDIR)/ChHist.obj \
	$(INTDIR)/ChPrefs.obj \
	$(INTDIR)/ChKeyMapType.obj \
	$(INTDIR)/ChTextStream.obj \
	$(INTDIR)/TinTinVars.obj \
	$(INTDIR)/TinTinUtils.obj \
	$(INTDIR)/TinTinParse.obj \
	$(INTDIR)/TinTinMisc.obj \
	$(INTDIR)/TinTinList.obj \
	$(INTDIR)/TinTinAction.obj \
	$(INTDIR)/TinTinAlias.obj \
	$(INTDIR)/TinTinWizList.obj \
	$(INTDIR)/TinTinFiles.obj \
	$(INTDIR)/TinTinInfo.obj

$(OUTDIR)/ChText.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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

SOURCE=.\ChText.def
# End Source File
################################################################################
# Begin Source File

SOURCE=.\headers.cpp
DEP_HEADE=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChText.h\
	.\Text.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChMsgCon.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChData.h\
	\chaco\include\ChConn.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/headers.obj :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)

# End Source File
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
	\chaco\include\ChText.h\
	.\Text.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChMsgCon.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChData.h\
	\chaco\include\ChConn.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/Dll.obj :  $(SOURCE)  $(DEP_DLL_C) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChText.cpp
DEP_CHTEX=\
	.\headers.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChText.h\
	.\ChTxtIn.h\
	.\ChTxtOut.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChUtil.h\
	.\Text.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChClMod.h\
	\chaco\include\ChSerMod.h\
	\chaco\include\ChMenu.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChKeyMap.h\
	.\ChHist.h\
	.\ChKeyMapType.h\
	.\TinTin.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChPane.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMsgCon.h\
	\chaco\include\ChList.h\
	\chaco\include\ChData.h\
	\chaco\include\ChUser.h\
	\chaco\include\ChExcept.h\
	\chaco\include\templcls\ChMnPtrl.h\
	\chaco\include\templcls\ChMnPtrl.inl\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChConn.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDib.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChText.obj :  $(SOURCE)  $(DEP_CHTEX) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTxtIn.cpp
DEP_CHTXT=\
	.\headers.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChSplit.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWorld.h\
	.\ChTxtIn.h\
	.\ChPrefs.h\
	.\ChKeyMapType.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChText.h\
	.\Text.h\
	\chaco\include\ChModMgr.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\templcls\ChMqLst.h\
	\chaco\include\templcls\ChMqLst.inl\
	\chaco\include\templcls\ChNtfyLs.h\
	\chaco\include\templcls\ChNtfyLs.inl\
	\chaco\include\ChReg.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChClMod.h\
	\chaco\include\ChSerMod.h\
	\chaco\include\ChMenu.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChKeyMap.h\
	.\ChHist.h\
	.\TinTin.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChMsgCon.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\templcls\ChModTre.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChDb.h\
	\chaco\include\ChUser.h\
	\chaco\include\ChExcept.h\
	\chaco\include\templcls\ChMnPtrl.h\
	\chaco\include\templcls\ChMnPtrl.inl\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChConn.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChTxtIn.obj :  $(SOURCE)  $(DEP_CHTXT) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTxtOut.cpp
DEP_CHTXTO=\
	.\headers.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChClMod.h\
	\chaco\include\ChPane.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChWorld.h\
	.\ChTextStream.h\
	.\ChTxtOut.h\
	.\ChPrefs.h\
	\chaco\include\ChTypes.h\
	..\..\unix\ChText\TextPriv.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChText.h\
	.\Text.h\
	\chaco\include\ChModMgr.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\templcls\ChMqLst.h\
	\chaco\include\templcls\ChMqLst.inl\
	\chaco\include\templcls\ChNtfyLs.h\
	\chaco\include\templcls\ChNtfyLs.inl\
	\chaco\include\ChUser.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChMenu.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChReg.h\
	.\ChTxtIn.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChSerMod.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChMsgCon.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\templcls\ChModTre.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	\chaco\include\ChExcept.h\
	\chaco\include\templcls\ChMnPtrl.h\
	\chaco\include\templcls\ChMnPtrl.inl\
	\chaco\include\ChDb.h\
	\chaco\include\ChKeyMap.h\
	.\ChHist.h\
	.\ChKeyMapType.h\
	.\TinTin.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChConn.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\ChDib.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChTxtOut.obj :  $(SOURCE)  $(DEP_CHTXTO) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChText.rc
DEP_CHTEXT=\
	.\res\ChText.rc2

$(INTDIR)/ChText.res :  $(SOURCE)  $(DEP_CHTEXT) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

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
	\chaco\include\ChText.h\
	.\Text.h\
	\chaco\include\ChSerMod.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChMsgCon.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChUser.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChData.h\
	\chaco\include\ChConn.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChHist.obj :  $(SOURCE)  $(DEP_CHHIS) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrefs.cpp
DEP_CHPRE=\
	.\headers.h\
	\chaco\include\ChText.h\
	.\ChPrefs.h\
	.\ChKeyMapType.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	.\Text.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChReg.h\
	.\ChTxtIn.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChKeyMap.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChMsgCon.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChClMod.h\
	\chaco\include\ChSerMod.h\
	\chaco\include\ChMenu.h\
	\chaco\include\ChHook.h\
	.\ChHist.h\
	.\TinTin.h\
	\chaco\include\ChData.h\
	\chaco\include\ChConn.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChUser.h\
	\chaco\include\ChExcept.h\
	\chaco\include\templcls\ChMnPtrl.h\
	\chaco\include\templcls\ChMnPtrl.inl\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChPrefs.obj :  $(SOURCE)  $(DEP_CHPRE) $(INTDIR)

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
	\chaco\include\ChText.h\
	.\Text.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChKeyMap.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChMsgCon.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChConn.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChKeyMapType.obj :  $(SOURCE)  $(DEP_CHKEY) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTextStream.cpp
DEP_CHTEXTS=\
	.\headers.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChMsgTyp.h\
	.\ChTextStream.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChText.h\
	.\Text.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChModMgr.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\templcls\ChMqLst.h\
	\chaco\include\templcls\ChMqLst.inl\
	\chaco\include\templcls\ChNtfyLs.h\
	\chaco\include\templcls\ChNtfyLs.inl\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsgCon.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\templcls\ChModTre.h\
	\chaco\include\ChData.h\
	\chaco\include\ChConn.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChTextStream.obj :  $(SOURCE)  $(DEP_CHTEXTS) $(INTDIR)

# End Source File
# End Group
################################################################################
# Begin Group "TinTin"

################################################################################
# Begin Source File

SOURCE=.\TinTinVars.cpp
DEP_TINTI=\
	\chaco\include\ChTypes.h\
	.\TinTin.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinVars.obj :  $(SOURCE)  $(DEP_TINTI) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinUtils.cpp
DEP_TINTIN=\
	\chaco\include\ChTypes.h\
	.\TinTin.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinUtils.obj :  $(SOURCE)  $(DEP_TINTIN) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinParse.cpp
DEP_TINTINP=\
	\chaco\include\ChTypes.h\
	.\TinTin.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinParse.obj :  $(SOURCE)  $(DEP_TINTINP) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinMisc.cpp
DEP_TINTINM=\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDlg.h\
	.\TinTin.h\
	.\TinTinInfo.h\
	.\TinTinWizList.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinMisc.obj :  $(SOURCE)  $(DEP_TINTINM) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinList.cpp
DEP_TINTINL=\
	\chaco\include\ChTypes.h\
	.\TinTin.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinList.obj :  $(SOURCE)  $(DEP_TINTINL) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinAction.cpp
DEP_TINTINA=\
	\chaco\include\ChTypes.h\
	.\TinTin.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinAction.obj :  $(SOURCE)  $(DEP_TINTINA) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinAlias.cpp
DEP_TINTINAL=\
	\chaco\include\ChTypes.h\
	.\TinTin.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinAlias.obj :  $(SOURCE)  $(DEP_TINTINAL) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinWizList.cpp
DEP_TINTINW=\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDlg.h\
	.\headers.h\
	\chaco\include\ChText.h\
	.\TinTinWizList.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	.\Text.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChMsgCon.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChData.h\
	\chaco\include\ChConn.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/TinTinWizList.obj :  $(SOURCE)  $(DEP_TINTINW) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinFiles.cpp
DEP_TINTINF=\
	\chaco\include\ChTypes.h\
	\chaco\include\ChUtil.h\
	.\TinTin.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/TinTinFiles.obj :  $(SOURCE)  $(DEP_TINTINF) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinInfo.cpp
DEP_TINTINI=\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDlg.h\
	.\headers.h\
	\chaco\include\ChText.h\
	.\TinTinInfo.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	.\Text.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChMsgCon.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChData.h\
	\chaco\include\ChConn.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/TinTinInfo.obj :  $(SOURCE)  $(DEP_TINTINI) $(INTDIR)

# End Source File
# End Group
# End Project
################################################################################
