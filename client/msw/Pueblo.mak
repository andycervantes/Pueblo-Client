# Microsoft Visual C++ Generated NMAKE File, Format Version 2.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Debug" && "$(CFG)" != "Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Pueblo.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

################################################################################
# Begin Project
# PROP Target_Last_Scanned "Win32 Debug"
MTL=MkTypLib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "/chaco/bin/debug"
# PROP Intermediate_Dir "debug"
OUTDIR=/chaco/bin/debug
INTDIR=.\debug

ALL : $(OUTDIR)/Pueblo.exe $(OUTDIR)/Pueblo.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MD /W3 /GX /Zi /YX"headers.h" /Od /I "\chaco\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_EXCEPTIONS" /FR /c
CPP_PROJ=/nologo /G5 /MD /W3 /GX /Zi /YX"headers.h" /Od /I "\chaco\include" /D\
 "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_EXCEPTIONS" /FR$(INTDIR)/ /Fp$(OUTDIR)/"Pueblo.pch" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"Pueblo.pdb" /c 
CPP_OBJS=.\debug/
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"Pueblo.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"Pueblo.bsc" 
BSC32_SBRS= \
	$(INTDIR)/ChPrefs.sbr \
	$(INTDIR)/ChClCore.sbr \
	$(INTDIR)/ChNList.sbr \
	$(INTDIR)/ChPrDbg.sbr \
	$(INTDIR)/ChPrFont.sbr \
	$(INTDIR)/Pueblo.sbr \
	$(INTDIR)/ChAccDlg.sbr \
	$(INTDIR)/ChBaseVw.sbr \
	$(INTDIR)/ChPrNet.sbr \
	$(INTDIR)/ChLicDlg.sbr \
	$(INTDIR)/ChPagMgr.sbr \
	$(INTDIR)/headers.sbr \
	$(INTDIR)/ChAbout.sbr \
	$(INTDIR)/ChMFrame.sbr \
	$(INTDIR)/ChPrApps.sbr \
	$(INTDIR)/ChPrefsProxy.sbr \
	$(INTDIR)/ChRunTimeInfo.sbr \
	$(INTDIR)/ChPbModuleMgr.sbr \
	$(INTDIR)/ChCoreHandlers.sbr \
	$(INTDIR)/ChPuebloFrameMgr.sbr \
	$(INTDIR)/ChCoreStream.sbr \
	$(INTDIR)/ChPrefsTrace.sbr \
	$(INTDIR)/ChDDE.sbr \
	$(INTDIR)/ChDDESrv.sbr \
	$(INTDIR)/ChDDECli.sbr

$(OUTDIR)/Pueblo.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /DEBUG /MACHINE:I386
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 wsock32.lib Pueblo32.lib WTracker.lib version.lib /NOLOGO /SUBSYSTEM:windows /DEBUG /MACHINE:I386
# SUBTRACT LINK32 /PDB:none /INCREMENTAL:no
LINK32_FLAGS=wsock32.lib Pueblo32.lib WTracker.lib version.lib /NOLOGO\
 /SUBSYSTEM:windows /INCREMENTAL:yes /PDB:$(OUTDIR)/"Pueblo.pdb" /DEBUG\
 /MACHINE:I386 /OUT:$(OUTDIR)/"Pueblo.exe" 
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/ChPrefs.obj \
	$(INTDIR)/ChClCore.obj \
	$(INTDIR)/ChNList.obj \
	$(INTDIR)/ChPrDbg.obj \
	$(INTDIR)/ChPrFont.obj \
	$(INTDIR)/Pueblo.res \
	$(INTDIR)/Pueblo.obj \
	$(INTDIR)/ChAccDlg.obj \
	$(INTDIR)/ChBaseVw.obj \
	$(INTDIR)/ChPrNet.obj \
	$(INTDIR)/ChLicDlg.obj \
	$(INTDIR)/ChPagMgr.obj \
	$(INTDIR)/headers.obj \
	$(INTDIR)/ChAbout.obj \
	$(INTDIR)/ChMFrame.obj \
	\chaco\lib\PbUtil32.lib \
	$(INTDIR)/ChPrApps.obj \
	$(INTDIR)/ChPrefsProxy.obj \
	$(INTDIR)/ChRunTimeInfo.obj \
	$(INTDIR)/ChPbModuleMgr.obj \
	$(INTDIR)/ChCoreHandlers.obj \
	$(INTDIR)/ChPuebloFrameMgr.obj \
	$(INTDIR)/ChCoreStream.obj \
	$(INTDIR)/ChPrefsTrace.obj \
	$(INTDIR)/ChDDE.obj \
	$(INTDIR)/ChDDESrv.obj \
	$(INTDIR)/ChDDECli.obj

$(OUTDIR)/Pueblo.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "/chaco/bin/release"
# PROP Intermediate_Dir "release"
OUTDIR=/chaco/bin/release
INTDIR=.\release

ALL : $(OUTDIR)/Pueblo.exe $(OUTDIR)/Pueblo.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MD /W3 /GX /Zi /Og /Oi /Os /Oy /I "\chaco\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_EXCEPTIONS" /Fr /c
# SUBTRACT CPP /Yu
CPP_PROJ=/nologo /G5 /MD /W3 /GX /Zi /Og /Oi /Os /Oy /I "\chaco\include" /D\
 "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_EXCEPTIONS" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"Pueblo.pdb" /c 
CPP_OBJS=.\release/
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"Pueblo.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"Pueblo.bsc" 
BSC32_SBRS= \
	$(INTDIR)/ChPrefs.sbr \
	$(INTDIR)/ChClCore.sbr \
	$(INTDIR)/ChNList.sbr \
	$(INTDIR)/ChPrDbg.sbr \
	$(INTDIR)/ChPrFont.sbr \
	$(INTDIR)/Pueblo.sbr \
	$(INTDIR)/ChAccDlg.sbr \
	$(INTDIR)/ChBaseVw.sbr \
	$(INTDIR)/ChPrNet.sbr \
	$(INTDIR)/ChLicDlg.sbr \
	$(INTDIR)/ChPagMgr.sbr \
	$(INTDIR)/headers.sbr \
	$(INTDIR)/ChAbout.sbr \
	$(INTDIR)/ChMFrame.sbr \
	$(INTDIR)/ChPrApps.sbr \
	$(INTDIR)/ChPrefsProxy.sbr \
	$(INTDIR)/ChRunTimeInfo.sbr \
	$(INTDIR)/ChPbModuleMgr.sbr \
	$(INTDIR)/ChCoreHandlers.sbr \
	$(INTDIR)/ChPuebloFrameMgr.sbr \
	$(INTDIR)/ChCoreStream.sbr \
	$(INTDIR)/ChPrefsTrace.sbr \
	$(INTDIR)/ChDDE.sbr \
	$(INTDIR)/ChDDESrv.sbr \
	$(INTDIR)/ChDDECli.sbr

$(OUTDIR)/Pueblo.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /MACHINE:I386
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 wsock32.lib Pueblo32.lib WTracker.lib version.lib /NOLOGO /SUBSYSTEM:windows /MACHINE:I386
# SUBTRACT LINK32 /PDB:none /DEBUG
LINK32_FLAGS=wsock32.lib Pueblo32.lib WTracker.lib version.lib /NOLOGO\
 /SUBSYSTEM:windows /INCREMENTAL:no /PDB:$(OUTDIR)/"Pueblo.pdb" /MACHINE:I386\
 /OUT:$(OUTDIR)/"Pueblo.exe" 
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/ChPrefs.obj \
	$(INTDIR)/ChClCore.obj \
	$(INTDIR)/ChNList.obj \
	$(INTDIR)/ChPrDbg.obj \
	$(INTDIR)/ChPrFont.obj \
	$(INTDIR)/Pueblo.res \
	$(INTDIR)/Pueblo.obj \
	$(INTDIR)/ChAccDlg.obj \
	$(INTDIR)/ChBaseVw.obj \
	$(INTDIR)/ChPrNet.obj \
	$(INTDIR)/ChLicDlg.obj \
	$(INTDIR)/ChPagMgr.obj \
	$(INTDIR)/headers.obj \
	$(INTDIR)/ChAbout.obj \
	$(INTDIR)/ChMFrame.obj \
	\chaco\lib\PbUtil32.lib \
	$(INTDIR)/ChPrApps.obj \
	$(INTDIR)/ChPrefsProxy.obj \
	$(INTDIR)/ChRunTimeInfo.obj \
	$(INTDIR)/ChPbModuleMgr.obj \
	$(INTDIR)/ChCoreHandlers.obj \
	$(INTDIR)/ChPuebloFrameMgr.obj \
	$(INTDIR)/ChCoreStream.obj \
	$(INTDIR)/ChPrefsTrace.obj \
	$(INTDIR)/ChDDE.obj \
	$(INTDIR)/ChDDESrv.obj \
	$(INTDIR)/ChDDECli.obj

$(OUTDIR)/Pueblo.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

MTL_PROJ=

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

SOURCE=.\ChPrefs.cpp
DEP_CHPRE=\
	.\headers.h\
	.\Pueblo.h\
	.\ChPrefs.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChSplay.h\
	.\ChAbout.h\
	.\ChPagMgr.h\
	\chaco\include\ChList.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChPrefs.obj :  $(SOURCE)  $(DEP_CHPRE) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChClCore.cpp
DEP_CHCLC=\
	.\headers.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChRMenu.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChDDE.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChWebTracker.h\
	.\ChPrApps.h\
	.\ChLicDlg.h\
	.\ChAccDlg.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChModMgr.h\
	\chaco\include\ChPerFrm.h\
	.\ChPbModuleMgr.h\
	.\Pueblo.h\
	.\chmframe.h\
	.\ChClCore.h\
	.\ChCoreStream.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMenu.h\
	\chaco\include\templcls\ChMnItem.h\
	\chaco\include\templcls\ChMnMap.h\
	\chaco\include\templcls\ChMnList.h\
	\chaco\include\templcls\ChMnList.inl\
	\chaco\include\templcls\ChMnBlk.h\
	\chaco\include\templcls\ChMnBlk.inl\
	\chaco\include\templcls\ChMItSpl.h\
	\chaco\include\templcls\ChMnSply.h\
	\chaco\include\templcls\ChMnItLs.h\
	\chaco\include\templcls\ChMnItLs.inl\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChWizard.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChHook.h\
	\chaco\include\templcls\ChModTre.h\
	\chaco\include\ChHtpCon.h\
	.\ChRunTimeInfo.h\
	.\ChAbout.h\
	\chaco\include\ChSplit.h\
	\chaco\include\ChTlBar.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChConn.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\templcls\ChMnPtrl.h\
	\chaco\include\templcls\ChMnPtrl.inl\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChUrlMap.h\
	.\ChPagMgr.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChRect.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChClCore.obj :  $(SOURCE)  $(DEP_CHCLC) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChNList.cpp
DEP_CHNLI=\
	.\headers.h\
	\chaco\include\ChReg.h\
	.\ChNList.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChNList.obj :  $(SOURCE)  $(DEP_CHNLI) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrDbg.cpp
DEP_CHPRD=\
	.\headers.h\
	.\Pueblo.h\
	.\ChPrDbg.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChSplay.h\
	.\ChAbout.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChList.h\
	.\ChPagMgr.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChDb.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChPrDbg.obj :  $(SOURCE)  $(DEP_CHPRD) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrFont.cpp
DEP_CHPRF=\
	.\headers.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChUtil.h\
	.\ChClCore.h\
	.\ChPrFont.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChList.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChConn.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChPage.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChMData.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChPrFont.obj :  $(SOURCE)  $(DEP_CHPRF) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo.rc
DEP_PUEBL=\
	.\res\idr_main.ico\
	.\res\idr_shor.ico\
	.\res\toolbar.bmp\
	.\res\Chaco.rc2

$(INTDIR)/Pueblo.res :  $(SOURCE)  $(DEP_PUEBL) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo.cpp
DEP_PUEBLO=\
	.\headers.h\
	.\Pueblo.h\
	\chaco\include\ChDDE.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChTime.h\
	.\ChBaseVw.h\
	.\chmframe.h\
	.\ChClCore.h\
	\chaco\include\ChPblDoc.h\
	\chaco\include\ChRMenu.h\
	\chaco\include\ChSock.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChSplay.h\
	.\ChAbout.h\
	\chaco\include\ChList.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChSplit.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChTlBar.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChConn.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMenu.h\
	\chaco\include\templcls\ChMnItem.h\
	\chaco\include\templcls\ChMnMap.h\
	\chaco\include\templcls\ChMnList.h\
	\chaco\include\templcls\ChMnList.inl\
	\chaco\include\templcls\ChMnBlk.h\
	\chaco\include\templcls\ChMnBlk.inl\
	\chaco\include\templcls\ChMItSpl.h\
	\chaco\include\templcls\ChMnSply.h\
	\chaco\include\templcls\ChMnItLs.h\
	\chaco\include\templcls\ChMnItLs.inl\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	.\ChPagMgr.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChPage.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChReg.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChMData.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\ChData.h\
	\chaco\include\ChArch.h\
	\chaco\include\templcls\ChMnPtrl.h\
	\chaco\include\templcls\ChMnPtrl.inl\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChDb.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/Pueblo.obj :  $(SOURCE)  $(DEP_PUEBLO) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAccDlg.cpp
DEP_CHACC=\
	.\headers.h\
	.\Pueblo.h\
	.\ChAccDlg.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChSplay.h\
	.\ChAbout.h\
	\chaco\include\ChWizard.h\
	\chaco\include\ChList.h\
	.\ChPagMgr.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChPage.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChAccDlg.obj :  $(SOURCE)  $(DEP_CHACC) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChBaseVw.cpp
DEP_CHBAS=\
	.\headers.h\
	.\Pueblo.h\
	.\ChBaseVw.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChSplay.h\
	.\ChAbout.h\
	\chaco\include\ChList.h\
	.\ChPagMgr.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChPage.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChBaseVw.obj :  $(SOURCE)  $(DEP_CHBAS) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrNet.cpp
DEP_CHPRN=\
	.\headers.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChHtpCon.h\
	.\Pueblo.h\
	.\ChPrNet.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChList.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChSplay.h\
	.\ChAbout.h\
	\chaco\include\ChPage.h\
	\chaco\include\templcls\ChLstHlp.inl\
	.\ChPagMgr.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChPrNet.obj :  $(SOURCE)  $(DEP_CHPRN) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChLicDlg.cpp
DEP_CHLIC=\
	.\headers.h\
	.\Pueblo.h\
	\chaco\include\ChReg.h\
	.\ChLicDlg.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChSplay.h\
	.\ChAbout.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChList.h\
	.\ChPagMgr.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChPage.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChLicDlg.obj :  $(SOURCE)  $(DEP_CHLIC) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPagMgr.cpp
DEP_CHPAG=\
	.\headers.h\
	.\ChClCore.h\
	\chaco\include\ChReg.h\
	.\ChPagMgr.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChConn.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChList.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChMData.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChPagMgr.obj :  $(SOURCE)  $(DEP_CHPAG) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\headers.cpp
DEP_HEADE=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/headers.obj :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAbout.cpp
DEP_CHABO=\
	.\headers.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChDibDecoder.h\
	.\ChAbout.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChImageDecoder.h\
	.\ChPagMgr.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChList.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h

$(INTDIR)/ChAbout.obj :  $(SOURCE)  $(DEP_CHABO) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMFrame.cpp
DEP_CHMFR=\
	.\headers.h\
	.\Pueblo.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChRMenu.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChImgUtil.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChWebTracker.h\
	.\ChClCore.h\
	\chaco\include\ChRect.h\
	.\chmframe.h\
	.\ChPrefs.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChSplay.h\
	.\ChAbout.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMenu.h\
	\chaco\include\templcls\ChMnItem.h\
	\chaco\include\templcls\ChMnMap.h\
	\chaco\include\templcls\ChMnList.h\
	\chaco\include\templcls\ChMnList.inl\
	\chaco\include\templcls\ChMnBlk.h\
	\chaco\include\templcls\ChMnBlk.inl\
	\chaco\include\templcls\ChMItSpl.h\
	\chaco\include\templcls\ChMnSply.h\
	\chaco\include\templcls\ChMnItLs.h\
	\chaco\include\templcls\ChMnItLs.inl\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChList.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChConn.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChSplit.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChTlBar.h\
	.\ChPagMgr.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\templcls\ChMnPtrl.h\
	\chaco\include\templcls\ChMnPtrl.inl\
	\chaco\include\ChData.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChFont.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChHook.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChSize.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChMFrame.obj :  $(SOURCE)  $(DEP_CHMFR) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\lib\PbUtil32.lib
# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrApps.cpp
DEP_CHPRA=\
	.\headers.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChUtil.h\
	.\Pueblo.h\
	.\ChPrApps.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChList.h\
	\chaco\include\ChSplay.h\
	.\ChAbout.h\
	\chaco\include\ChPage.h\
	\chaco\include\templcls\ChLstHlp.inl\
	.\ChPagMgr.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChPrApps.obj :  $(SOURCE)  $(DEP_CHPRA) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrefsProxy.cpp
DEP_CHPREF=\
	.\headers.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChSock.h\
	\chaco\include\ChUtil.h\
	.\ChClCore.h\
	.\ChPrefsProxy.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChList.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChConn.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChPage.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChMData.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\ChData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChPrefsProxy.obj :  $(SOURCE)  $(DEP_CHPREF) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRunTimeInfo.cpp
DEP_CHRUN=\
	.\headers.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsgTyp.h\
	.\ChPbModuleMgr.h\
	.\ChRunTimeInfo.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChHtpCon.h\
	.\ChCoreStream.h\
	\chaco\include\ChList.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChRunTimeInfo.obj :  $(SOURCE)  $(DEP_CHRUN) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPbModuleMgr.cpp
DEP_CHPBM=\
	.\headers.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChUtil.h\
	.\ChPbModuleMgr.h\
	.\ChClCore.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChList.h\
	\chaco\include\ChHtpCon.h\
	.\ChRunTimeInfo.h\
	.\ChCoreStream.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChConn.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChMData.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\ChData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChPbModuleMgr.obj :  $(SOURCE)  $(DEP_CHPBM) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChCoreHandlers.cpp
DEP_CHCOR=\
	.\headers.h\
	\chaco\include\ChReg.h\
	.\ChPrConn.h\
	.\ChPrDbg.h\
	.\ChPrFont.h\
	.\ChPrNet.h\
	.\ChPrApps.h\
	.\ChPrefsProxy.h\
	.\ChPrefsTrace.h\
	.\ChAbout.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChModMgr.h\
	\chaco\include\ChRMenu.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChPerFrm.h\
	.\ChClCore.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChPage.h\
	.\ChPagMgr.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\templcls\ChModTre.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMenu.h\
	\chaco\include\templcls\ChMnItem.h\
	\chaco\include\templcls\ChMnMap.h\
	\chaco\include\templcls\ChMnList.h\
	\chaco\include\templcls\ChMnList.inl\
	\chaco\include\templcls\ChMnBlk.h\
	\chaco\include\templcls\ChMnBlk.inl\
	\chaco\include\templcls\ChMItSpl.h\
	\chaco\include\templcls\ChMnSply.h\
	\chaco\include\templcls\ChMnItLs.h\
	\chaco\include\templcls\ChMnItLs.inl\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChConn.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChList.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\templcls\ChMnPtrl.h\
	\chaco\include\templcls\ChMnPtrl.inl\
	\chaco\include\ChData.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChCoreHandlers.obj :  $(SOURCE)  $(DEP_CHCOR) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPuebloFrameMgr.cpp
DEP_CHPUE=\
	.\headers.h\
	.\Pueblo.h\
	.\chmframe.h\
	.\ChClCore.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChSplay.h\
	.\ChAbout.h\
	\chaco\include\ChSplit.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChTlBar.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChConn.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChList.h\
	.\ChPagMgr.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChMData.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\ChData.h\
	\chaco\include\ChArch.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChDb.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChPuebloFrameMgr.obj :  $(SOURCE)  $(DEP_CHPUE) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChCoreStream.cpp
DEP_CHCORE=\
	.\headers.h\
	\chaco\include\ChReg.h\
	.\ChClCore.h\
	.\ChCoreStream.h\
	.\ChPbModuleMgr.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChConn.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChHtpCon.h\
	.\ChRunTimeInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChMData.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChCoreStream.obj :  $(SOURCE)  $(DEP_CHCORE) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrefsTrace.cpp
DEP_CHPREFS=\
	.\headers.h\
	.\Pueblo.h\
	.\ChPrefsTrace.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChSplay.h\
	.\ChAbout.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	.\ChPagMgr.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h
# PROP Exclude_From_Build 0

$(INTDIR)/ChPrefsTrace.obj :  $(SOURCE)  $(DEP_CHPREFS) $(INTDIR)

# End Source File
# End Group
################################################################################
# Begin Group "DDE"

################################################################################
# Begin Source File

SOURCE=\chaco\api\ChDDE.cpp
DEP_CHDDE=\
	\chaco\include\grheader.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChDDE.h\
	\chaco\include\ChHtpCon.h\
	\chaco\api\ChDDEPrv.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChMData.h

$(INTDIR)/ChDDE.obj :  $(SOURCE)  $(DEP_CHDDE) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\api\ChDDESrv.cpp
DEP_CHDDES=\
	\chaco\include\grheader.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChDDE.h\
	\chaco\api\ChDDEPrv.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChDDESrv.obj :  $(SOURCE)  $(DEP_CHDDES) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\api\ChDDECli.cpp
DEP_CHDDEC=\
	\chaco\include\grheader.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChDDE.h\
	\chaco\api\ChDDEPrv.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChDDECli.obj :  $(SOURCE)  $(DEP_CHDDEC) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
# End Group
# End Project
################################################################################
