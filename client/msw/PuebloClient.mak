# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Pueblo - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Pueblo - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Pueblo - Win32 Debug" && "$(CFG)" != "Pueblo - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "PuebloClient.mak" CFG="Pueblo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Pueblo - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Pueblo - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "Pueblo - Win32 Debug"
MTL=mktyplib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

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

ALL : "$(OUTDIR)\Pueblo.exe"

CLEAN : 
	-@erase "$(INTDIR)\ChAbout.obj"
	-@erase "$(INTDIR)\ChAccDlg.obj"
	-@erase "$(INTDIR)\ChBaseVw.obj"
	-@erase "$(INTDIR)\ChClCore.obj"
	-@erase "$(INTDIR)\ChCoreHandlers.obj"
	-@erase "$(INTDIR)\ChCoreStream.obj"
	-@erase "$(INTDIR)\ChDDE.obj"
	-@erase "$(INTDIR)\ChDDECli.obj"
	-@erase "$(INTDIR)\ChDDESrv.obj"
	-@erase "$(INTDIR)\ChLicDlg.obj"
	-@erase "$(INTDIR)\ChMFrame.obj"
	-@erase "$(INTDIR)\ChNList.obj"
	-@erase "$(INTDIR)\ChPagMgr.obj"
	-@erase "$(INTDIR)\ChPbModuleMgr.obj"
	-@erase "$(INTDIR)\ChPrApps.obj"
	-@erase "$(INTDIR)\ChPrDbg.obj"
	-@erase "$(INTDIR)\ChPrefs.obj"
	-@erase "$(INTDIR)\ChPrefsProxy.obj"
	-@erase "$(INTDIR)\ChPrefsTrace.obj"
	-@erase "$(INTDIR)\ChPrFont.obj"
	-@erase "$(INTDIR)\ChPrNet.obj"
	-@erase "$(INTDIR)\ChPuebloFrameMgr.obj"
	-@erase "$(INTDIR)\ChRunTimeInfo.obj"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(INTDIR)\Pueblo.obj"
	-@erase "$(INTDIR)\Pueblo.res"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Pueblo.exe"
	-@erase "$(OUTDIR)\Pueblo.ilk"
	-@erase "$(OUTDIR)\Pueblo.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /YX"headers.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /G5 /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /D "_DEBUG"\
 /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS"\
 /Fp"$(INTDIR)/PuebloClient.pch" /YX"headers.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/"\
 /c 
CPP_OBJS=.\debug/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Pueblo.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/PuebloClient.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 wsock32.lib Pueblo32.lib WTracker.lib version.lib /nologo /subsystem:windows /debug /machine:I386 /out:"\chaco\bin\debug/Pueblo.exe"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=wsock32.lib Pueblo32.lib WTracker.lib version.lib /nologo\
 /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)/Pueblo.pdb" /debug\
 /machine:I386 /out:"$(OUTDIR)/Pueblo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChAbout.obj" \
	"$(INTDIR)\ChAccDlg.obj" \
	"$(INTDIR)\ChBaseVw.obj" \
	"$(INTDIR)\ChClCore.obj" \
	"$(INTDIR)\ChCoreHandlers.obj" \
	"$(INTDIR)\ChCoreStream.obj" \
	"$(INTDIR)\ChDDE.obj" \
	"$(INTDIR)\ChDDECli.obj" \
	"$(INTDIR)\ChDDESrv.obj" \
	"$(INTDIR)\ChLicDlg.obj" \
	"$(INTDIR)\ChMFrame.obj" \
	"$(INTDIR)\ChNList.obj" \
	"$(INTDIR)\ChPagMgr.obj" \
	"$(INTDIR)\ChPbModuleMgr.obj" \
	"$(INTDIR)\ChPrApps.obj" \
	"$(INTDIR)\ChPrDbg.obj" \
	"$(INTDIR)\ChPrefs.obj" \
	"$(INTDIR)\ChPrefsProxy.obj" \
	"$(INTDIR)\ChPrefsTrace.obj" \
	"$(INTDIR)\ChPrFont.obj" \
	"$(INTDIR)\ChPrNet.obj" \
	"$(INTDIR)\ChPuebloFrameMgr.obj" \
	"$(INTDIR)\ChRunTimeInfo.obj" \
	"$(INTDIR)\headers.obj" \
	"$(INTDIR)\Pueblo.obj" \
	"$(INTDIR)\Pueblo.res" \
	"..\..\lib\PbUtil32.lib"

"$(OUTDIR)\Pueblo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

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

ALL : "$(OUTDIR)\Pueblo.exe"

CLEAN : 
	-@erase "$(INTDIR)\ChAbout.obj"
	-@erase "$(INTDIR)\ChAccDlg.obj"
	-@erase "$(INTDIR)\ChBaseVw.obj"
	-@erase "$(INTDIR)\ChClCore.obj"
	-@erase "$(INTDIR)\ChCoreHandlers.obj"
	-@erase "$(INTDIR)\ChCoreStream.obj"
	-@erase "$(INTDIR)\ChDDE.obj"
	-@erase "$(INTDIR)\ChDDECli.obj"
	-@erase "$(INTDIR)\ChDDESrv.obj"
	-@erase "$(INTDIR)\ChLicDlg.obj"
	-@erase "$(INTDIR)\ChMFrame.obj"
	-@erase "$(INTDIR)\ChNList.obj"
	-@erase "$(INTDIR)\ChPagMgr.obj"
	-@erase "$(INTDIR)\ChPbModuleMgr.obj"
	-@erase "$(INTDIR)\ChPrApps.obj"
	-@erase "$(INTDIR)\ChPrDbg.obj"
	-@erase "$(INTDIR)\ChPrefs.obj"
	-@erase "$(INTDIR)\ChPrefsProxy.obj"
	-@erase "$(INTDIR)\ChPrefsTrace.obj"
	-@erase "$(INTDIR)\ChPrFont.obj"
	-@erase "$(INTDIR)\ChPrNet.obj"
	-@erase "$(INTDIR)\ChPuebloFrameMgr.obj"
	-@erase "$(INTDIR)\ChRunTimeInfo.obj"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(INTDIR)\Pueblo.obj"
	-@erase "$(INTDIR)\Pueblo.res"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Pueblo.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MD /W3 /Gm /GX /Zi /Og /Oi /Os /Oy /I "\chaco\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /c
# SUBTRACT CPP /Fr /Yu
CPP_PROJ=/nologo /G5 /MD /W3 /Gm /GX /Zi /Og /Oi /Os /Oy /I "\chaco\include" /D\
 "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_EXCEPTIONS" /D "_AFXDLL"\
 /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\release/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Pueblo.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/PuebloClient.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 wsock32.lib Pueblo32.lib WTracker.lib version.lib /nologo /subsystem:windows /machine:I386 /out:"\chaco\bin\release/Pueblo.exe"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=wsock32.lib Pueblo32.lib WTracker.lib version.lib /nologo\
 /subsystem:windows /incremental:no /pdb:"$(OUTDIR)/Pueblo.pdb" /machine:I386\
 /out:"$(OUTDIR)/Pueblo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChAbout.obj" \
	"$(INTDIR)\ChAccDlg.obj" \
	"$(INTDIR)\ChBaseVw.obj" \
	"$(INTDIR)\ChClCore.obj" \
	"$(INTDIR)\ChCoreHandlers.obj" \
	"$(INTDIR)\ChCoreStream.obj" \
	"$(INTDIR)\ChDDE.obj" \
	"$(INTDIR)\ChDDECli.obj" \
	"$(INTDIR)\ChDDESrv.obj" \
	"$(INTDIR)\ChLicDlg.obj" \
	"$(INTDIR)\ChMFrame.obj" \
	"$(INTDIR)\ChNList.obj" \
	"$(INTDIR)\ChPagMgr.obj" \
	"$(INTDIR)\ChPbModuleMgr.obj" \
	"$(INTDIR)\ChPrApps.obj" \
	"$(INTDIR)\ChPrDbg.obj" \
	"$(INTDIR)\ChPrefs.obj" \
	"$(INTDIR)\ChPrefsProxy.obj" \
	"$(INTDIR)\ChPrefsTrace.obj" \
	"$(INTDIR)\ChPrFont.obj" \
	"$(INTDIR)\ChPrNet.obj" \
	"$(INTDIR)\ChPuebloFrameMgr.obj" \
	"$(INTDIR)\ChRunTimeInfo.obj" \
	"$(INTDIR)\headers.obj" \
	"$(INTDIR)\Pueblo.obj" \
	"$(INTDIR)\Pueblo.res" \
	"..\..\lib\PbUtil32.lib"

"$(OUTDIR)\Pueblo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "Pueblo - Win32 Debug"
# Name "Pueblo - Win32 Release"

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ChPrefs.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_CHPRE=\
	".\ChAbout.h"\
	".\ChPagMgr.h"\
	".\ChPrefs.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChPrefs.obj" : $(SOURCE) $(DEP_CPP_CHPRE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_CHPRE=\
	".\ChAbout.h"\
	".\ChPagMgr.h"\
	".\ChPrefs.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChPrefs.obj" : $(SOURCE) $(DEP_CPP_CHPRE) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChClCore.cpp
DEP_CPP_CHCLC=\
	".\ChAbout.h"\
	".\ChAccDlg.h"\
	".\ChClCore.h"\
	".\ChCoreStream.h"\
	".\ChLicDlg.h"\
	".\Chmframe.h"\
	".\ChPagMgr.h"\
	".\ChPbModuleMgr.h"\
	".\ChPrApps.h"\
	".\ChRunTimeInfo.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDDE.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMenu.h"\
	"\chaco\include\ChModMgr.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChRMenu.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChSplit.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTlBar.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWebTracker.h"\
	"\chaco\include\ChWizard.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChMItSpl.h"\
	"\chaco\include\TemplCls\ChMnBlk.h"\
	"\chaco\include\TemplCls\ChMnBlk.inl"\
	"\chaco\include\TemplCls\ChMnItem.h"\
	"\chaco\include\TemplCls\ChMnItLs.h"\
	"\chaco\include\TemplCls\ChMnItLs.inl"\
	"\chaco\include\TemplCls\ChMnList.h"\
	"\chaco\include\TemplCls\ChMnList.inl"\
	"\chaco\include\TemplCls\ChMnMap.h"\
	"\chaco\include\TemplCls\ChMnPtrL.h"\
	"\chaco\include\TemplCls\ChMnPtrL.inl"\
	"\chaco\include\TemplCls\ChMnSply.h"\
	"\chaco\include\TemplCls\ChModTre.h"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\Sys\Stat.h"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\ChClCore.obj" : $(SOURCE) $(DEP_CPP_CHCLC) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChNList.cpp
DEP_CPP_CHNLI=\
	".\ChNList.h"\
	".\Headers.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChNList.obj" : $(SOURCE) $(DEP_CPP_CHNLI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrDbg.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_CHPRD=\
	".\ChAbout.h"\
	".\ChPagMgr.h"\
	".\ChPrDbg.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChPrDbg.obj" : $(SOURCE) $(DEP_CPP_CHPRD) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_CHPRD=\
	".\ChAbout.h"\
	".\ChPagMgr.h"\
	".\ChPrDbg.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChPrDbg.obj" : $(SOURCE) $(DEP_CPP_CHPRD) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrFont.cpp
DEP_CPP_CHPRF=\
	".\ChClCore.h"\
	".\ChPrFont.h"\
	".\Headers.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\ChPrFont.obj" : $(SOURCE) $(DEP_CPP_CHPRF) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo.rc
DEP_RSC_PUEBL=\
	".\res\Chaco.rc2"\
	".\res\idr_main.ico"\
	".\res\idr_shor.ico"\
	".\res\toolbar.bmp"\
	

"$(INTDIR)\Pueblo.res" : $(SOURCE) $(DEP_RSC_PUEBL) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_PUEBLO=\
	".\ChAbout.h"\
	".\ChBaseVw.h"\
	".\ChClCore.h"\
	".\Chmframe.h"\
	".\ChPagMgr.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDDE.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMenu.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPblDoc.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChRMenu.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChSplit.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTlBar.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChMItSpl.h"\
	"\chaco\include\TemplCls\ChMnBlk.h"\
	"\chaco\include\TemplCls\ChMnBlk.inl"\
	"\chaco\include\TemplCls\ChMnItem.h"\
	"\chaco\include\TemplCls\ChMnItLs.h"\
	"\chaco\include\TemplCls\ChMnItLs.inl"\
	"\chaco\include\TemplCls\ChMnList.h"\
	"\chaco\include\TemplCls\ChMnList.inl"\
	"\chaco\include\TemplCls\ChMnMap.h"\
	"\chaco\include\TemplCls\ChMnPtrL.h"\
	"\chaco\include\TemplCls\ChMnPtrL.inl"\
	"\chaco\include\TemplCls\ChMnSply.h"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\Pueblo.obj" : $(SOURCE) $(DEP_CPP_PUEBLO) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_PUEBLO=\
	".\ChAbout.h"\
	".\ChBaseVw.h"\
	".\ChClCore.h"\
	".\Chmframe.h"\
	".\ChPagMgr.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDDE.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMenu.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPblDoc.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChRMenu.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChSplit.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTlBar.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChMItSpl.h"\
	"\chaco\include\TemplCls\ChMnBlk.h"\
	"\chaco\include\TemplCls\ChMnBlk.inl"\
	"\chaco\include\TemplCls\ChMnItem.h"\
	"\chaco\include\TemplCls\ChMnItLs.h"\
	"\chaco\include\TemplCls\ChMnItLs.inl"\
	"\chaco\include\TemplCls\ChMnList.h"\
	"\chaco\include\TemplCls\ChMnList.inl"\
	"\chaco\include\TemplCls\ChMnMap.h"\
	"\chaco\include\TemplCls\ChMnPtrL.h"\
	"\chaco\include\TemplCls\ChMnPtrL.inl"\
	"\chaco\include\TemplCls\ChMnSply.h"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\Pueblo.obj" : $(SOURCE) $(DEP_CPP_PUEBLO) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAccDlg.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_CHACC=\
	".\ChAbout.h"\
	".\ChAccDlg.h"\
	".\ChPagMgr.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWizard.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChAccDlg.obj" : $(SOURCE) $(DEP_CPP_CHACC) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_CHACC=\
	".\ChAbout.h"\
	".\ChAccDlg.h"\
	".\ChPagMgr.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWizard.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChAccDlg.obj" : $(SOURCE) $(DEP_CPP_CHACC) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChBaseVw.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_CHBAS=\
	".\ChAbout.h"\
	".\ChBaseVw.h"\
	".\ChPagMgr.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChBaseVw.obj" : $(SOURCE) $(DEP_CPP_CHBAS) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_CHBAS=\
	".\ChAbout.h"\
	".\ChBaseVw.h"\
	".\ChPagMgr.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChBaseVw.obj" : $(SOURCE) $(DEP_CPP_CHBAS) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrNet.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_CHPRN=\
	".\ChAbout.h"\
	".\ChPagMgr.h"\
	".\ChPrNet.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChPrNet.obj" : $(SOURCE) $(DEP_CPP_CHPRN) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_CHPRN=\
	".\ChAbout.h"\
	".\ChPagMgr.h"\
	".\ChPrNet.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChPrNet.obj" : $(SOURCE) $(DEP_CPP_CHPRN) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChLicDlg.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_CHLIC=\
	".\ChAbout.h"\
	".\ChLicDlg.h"\
	".\ChPagMgr.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChLicDlg.obj" : $(SOURCE) $(DEP_CPP_CHLIC) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_CHLIC=\
	".\ChAbout.h"\
	".\ChLicDlg.h"\
	".\ChPagMgr.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChLicDlg.obj" : $(SOURCE) $(DEP_CPP_CHLIC) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPagMgr.cpp
DEP_CPP_CHPAG=\
	".\ChClCore.h"\
	".\ChPagMgr.h"\
	".\Headers.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\ChPagMgr.obj" : $(SOURCE) $(DEP_CPP_CHPAG) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\headers.cpp
DEP_CPP_HEADE=\
	".\Headers.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\headers.obj" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAbout.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_CHABO=\
	".\ChAbout.h"\
	".\ChPagMgr.h"\
	".\Headers.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibDecoder.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImageDecoder.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChAbout.obj" : $(SOURCE) $(DEP_CPP_CHABO) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_CHABO=\
	".\ChAbout.h"\
	".\ChPagMgr.h"\
	".\Headers.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibDecoder.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImageDecoder.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChAbout.obj" : $(SOURCE) $(DEP_CPP_CHABO) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMFrame.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_CHMFR=\
	".\ChAbout.h"\
	".\ChClCore.h"\
	".\Chmframe.h"\
	".\ChPagMgr.h"\
	".\ChPrefs.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChImgUtil.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMenu.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChRMenu.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChSplit.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTlBar.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWebTracker.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChMItSpl.h"\
	"\chaco\include\TemplCls\ChMnBlk.h"\
	"\chaco\include\TemplCls\ChMnBlk.inl"\
	"\chaco\include\TemplCls\ChMnItem.h"\
	"\chaco\include\TemplCls\ChMnItLs.h"\
	"\chaco\include\TemplCls\ChMnItLs.inl"\
	"\chaco\include\TemplCls\ChMnList.h"\
	"\chaco\include\TemplCls\ChMnList.inl"\
	"\chaco\include\TemplCls\ChMnMap.h"\
	"\chaco\include\TemplCls\ChMnPtrL.h"\
	"\chaco\include\TemplCls\ChMnPtrL.inl"\
	"\chaco\include\TemplCls\ChMnSply.h"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\ChMFrame.obj" : $(SOURCE) $(DEP_CPP_CHMFR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_CHMFR=\
	".\ChAbout.h"\
	".\ChClCore.h"\
	".\Chmframe.h"\
	".\ChPagMgr.h"\
	".\ChPrefs.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChImgUtil.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMenu.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChRMenu.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChSplit.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTlBar.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWebTracker.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChMItSpl.h"\
	"\chaco\include\TemplCls\ChMnBlk.h"\
	"\chaco\include\TemplCls\ChMnBlk.inl"\
	"\chaco\include\TemplCls\ChMnItem.h"\
	"\chaco\include\TemplCls\ChMnItLs.h"\
	"\chaco\include\TemplCls\ChMnItLs.inl"\
	"\chaco\include\TemplCls\ChMnList.h"\
	"\chaco\include\TemplCls\ChMnList.inl"\
	"\chaco\include\TemplCls\ChMnMap.h"\
	"\chaco\include\TemplCls\ChMnPtrL.h"\
	"\chaco\include\TemplCls\ChMnPtrL.inl"\
	"\chaco\include\TemplCls\ChMnSply.h"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\ChMFrame.obj" : $(SOURCE) $(DEP_CPP_CHMFR) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\lib\PbUtil32.lib

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrApps.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_CHPRA=\
	".\ChAbout.h"\
	".\ChPagMgr.h"\
	".\ChPrApps.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChPrApps.obj" : $(SOURCE) $(DEP_CPP_CHPRA) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_CHPRA=\
	".\ChAbout.h"\
	".\ChPagMgr.h"\
	".\ChPrApps.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChPrApps.obj" : $(SOURCE) $(DEP_CPP_CHPRA) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrefsProxy.cpp
DEP_CPP_CHPREF=\
	".\ChClCore.h"\
	".\ChPrefsProxy.h"\
	".\Headers.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\ChPrefsProxy.obj" : $(SOURCE) $(DEP_CPP_CHPREF) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRunTimeInfo.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_CHRUN=\
	".\ChCoreStream.h"\
	".\ChPbModuleMgr.h"\
	".\ChRunTimeInfo.h"\
	".\Headers.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChRunTimeInfo.obj" : $(SOURCE) $(DEP_CPP_CHRUN) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_CHRUN=\
	".\ChCoreStream.h"\
	".\ChPbModuleMgr.h"\
	".\ChRunTimeInfo.h"\
	".\Headers.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChRunTimeInfo.obj" : $(SOURCE) $(DEP_CPP_CHRUN) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPbModuleMgr.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_CHPBM=\
	".\ChClCore.h"\
	".\ChCoreStream.h"\
	".\ChPbModuleMgr.h"\
	".\ChRunTimeInfo.h"\
	".\Headers.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\ChPbModuleMgr.obj" : $(SOURCE) $(DEP_CPP_CHPBM) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_CHPBM=\
	".\ChClCore.h"\
	".\ChCoreStream.h"\
	".\ChPbModuleMgr.h"\
	".\ChRunTimeInfo.h"\
	".\Headers.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\ChPbModuleMgr.obj" : $(SOURCE) $(DEP_CPP_CHPBM) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChCoreHandlers.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_CHCOR=\
	".\ChAbout.h"\
	".\ChClCore.h"\
	".\ChPagMgr.h"\
	".\ChPrApps.h"\
	".\ChPrConn.h"\
	".\ChPrDbg.h"\
	".\ChPrefsProxy.h"\
	".\ChPrefsTrace.h"\
	".\ChPrFont.h"\
	".\ChPrNet.h"\
	".\Headers.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMenu.h"\
	"\chaco\include\ChModMgr.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChRMenu.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChMItSpl.h"\
	"\chaco\include\TemplCls\ChMnBlk.h"\
	"\chaco\include\TemplCls\ChMnBlk.inl"\
	"\chaco\include\TemplCls\ChMnItem.h"\
	"\chaco\include\TemplCls\ChMnItLs.h"\
	"\chaco\include\TemplCls\ChMnItLs.inl"\
	"\chaco\include\TemplCls\ChMnList.h"\
	"\chaco\include\TemplCls\ChMnList.inl"\
	"\chaco\include\TemplCls\ChMnMap.h"\
	"\chaco\include\TemplCls\ChMnPtrL.h"\
	"\chaco\include\TemplCls\ChMnPtrL.inl"\
	"\chaco\include\TemplCls\ChMnSply.h"\
	"\chaco\include\TemplCls\ChModTre.h"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\ChCoreHandlers.obj" : $(SOURCE) $(DEP_CPP_CHCOR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_CHCOR=\
	".\ChAbout.h"\
	".\ChClCore.h"\
	".\ChPagMgr.h"\
	".\ChPrApps.h"\
	".\ChPrConn.h"\
	".\ChPrDbg.h"\
	".\ChPrefsProxy.h"\
	".\ChPrefsTrace.h"\
	".\ChPrFont.h"\
	".\ChPrNet.h"\
	".\Headers.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChMenu.h"\
	"\chaco\include\ChModMgr.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChRMenu.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChMItSpl.h"\
	"\chaco\include\TemplCls\ChMnBlk.h"\
	"\chaco\include\TemplCls\ChMnBlk.inl"\
	"\chaco\include\TemplCls\ChMnItem.h"\
	"\chaco\include\TemplCls\ChMnItLs.h"\
	"\chaco\include\TemplCls\ChMnItLs.inl"\
	"\chaco\include\TemplCls\ChMnList.h"\
	"\chaco\include\TemplCls\ChMnList.inl"\
	"\chaco\include\TemplCls\ChMnMap.h"\
	"\chaco\include\TemplCls\ChMnPtrL.h"\
	"\chaco\include\TemplCls\ChMnPtrL.inl"\
	"\chaco\include\TemplCls\ChMnSply.h"\
	"\chaco\include\TemplCls\ChModTre.h"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\ChCoreHandlers.obj" : $(SOURCE) $(DEP_CPP_CHCOR) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPuebloFrameMgr.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

DEP_CPP_CHPUE=\
	".\ChAbout.h"\
	".\ChClCore.h"\
	".\Chmframe.h"\
	".\ChPagMgr.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChSplit.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTlBar.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\ChPuebloFrameMgr.obj" : $(SOURCE) $(DEP_CPP_CHPUE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

DEP_CPP_CHPUE=\
	".\ChAbout.h"\
	".\ChClCore.h"\
	".\Chmframe.h"\
	".\ChPagMgr.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChSplit.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTlBar.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\ChPuebloFrameMgr.obj" : $(SOURCE) $(DEP_CPP_CHPUE) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChCoreStream.cpp
DEP_CPP_CHCORE=\
	".\ChClCore.h"\
	".\ChCoreStream.h"\
	".\ChPbModuleMgr.h"\
	".\ChRunTimeInfo.h"\
	".\Headers.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChArgList.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConn.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSock.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\protocol.h"\
	"\chaco\include\SocketXX.h"\
	"\chaco\include\sockinet.h"\
	"\chaco\include\sockstrm.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChSockBf.h"\
	{$(INCLUDE)}"\Sys\Types.h"\
	

"$(INTDIR)\ChCoreStream.obj" : $(SOURCE) $(DEP_CPP_CHCORE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrefsTrace.cpp

!IF  "$(CFG)" == "Pueblo - Win32 Debug"

# PROP Exclude_From_Build 0
DEP_CPP_CHPREFS=\
	".\ChAbout.h"\
	".\ChPagMgr.h"\
	".\ChPrefsTrace.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChPrefsTrace.obj" : $(SOURCE) $(DEP_CPP_CHPREFS) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Pueblo - Win32 Release"

# PROP Exclude_From_Build 0
DEP_CPP_CHPREFS=\
	".\ChAbout.h"\
	".\ChPagMgr.h"\
	".\ChPrefsTrace.h"\
	".\Headers.h"\
	".\Pueblo.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChPrefsTrace.obj" : $(SOURCE) $(DEP_CPP_CHPREFS) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\api\ChDDE.cpp
DEP_CPP_CHDDE=\
	"..\..\api\ChDDEPrv.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDDE.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChDDE.obj" : $(SOURCE) $(DEP_CPP_CHDDE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\api\ChDDESrv.cpp
DEP_CPP_CHDDES=\
	"..\..\api\ChDDEPrv.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChDDE.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChDDESrv.obj" : $(SOURCE) $(DEP_CPP_CHDDES) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\api\ChDDECli.cpp
DEP_CPP_CHDDEC=\
	"..\..\api\ChDDEPrv.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChDDE.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChDDECli.obj" : $(SOURCE) $(DEP_CPP_CHDDEC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
# End Target
# End Project
################################################################################
