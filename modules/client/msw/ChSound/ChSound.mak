# Microsoft Visual C++ Generated NMAKE File, Format Version 2.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Release" && "$(CFG)" != "Win32 Debug" && "$(CFG)" !=\
 "TNT Debug" && "$(CFG)" != "TNT Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "ChSound.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TNT Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TNT Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

################################################################################
# Begin Project
# PROP Target_Last_Scanned "VAPI Debug"
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

ALL : $(OUTDIR)/ChSound.dll $(OUTDIR)/ChSound.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE CPP /nologo /MT /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /MD /W3 /GX /YX"headers.h" /Og /Oi /Os /Oy /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /c
# SUBTRACT CPP /Oa /Fr
CPP_PROJ=/nologo /MD /W3 /GX /YX"headers.h" /Og /Oi /Os /Oy /D "NDEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D\
 "_AFXDLL" /D "_MBCS" /Fp$(OUTDIR)/"ChSound.pch" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\release/
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"ChSound.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChSound.bsc" 
BSC32_SBRS= \
	

$(OUTDIR)/ChSound.bsc : $(OUTDIR)  $(BSC32_SBRS)
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386
# ADD LINK32 winmm.lib Pueblo32.lib rt32dcmp.lib /NOLOGO /BASE:0x24000000 /SUBSYSTEM:windows /DLL /MACHINE:I386
LINK32_FLAGS=winmm.lib Pueblo32.lib rt32dcmp.lib /NOLOGO /BASE:0x24000000\
 /SUBSYSTEM:windows /DLL /INCREMENTAL:no /PDB:$(OUTDIR)/"ChSound.pdb"\
 /MACHINE:I386 /DEF:".\ChSound.def" /OUT:$(OUTDIR)/"ChSound.dll"\
 /IMPLIB:$(OUTDIR)/"ChSound.lib" 
DEF_FILE=.\ChSound.def
LINK32_OBJS= \
	.\release\ChSound.obj \
	.\release\headers.obj \
	.\release\ChSound.res \
	.\release\Dll.obj \
	.\release\ChMPlay.obj \
	.\release\ChNotify.obj \
	.\release\ChSPrefs.obj \
	.\release\ChSOpen.obj \
	.\release\ChSoundStream.obj \
	.\release\ChSpeechPrefs.obj \
	.\release\ChSoundUtils.obj \
	.\release\ChTNT.obj

$(OUTDIR)/ChSound.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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
# PROP Output_Dir "/chaco/bin/debug/modules"
# PROP Intermediate_Dir "debug"
OUTDIR=/chaco/bin/debug/modules
INTDIR=.\debug

ALL : $(OUTDIR)/ChSound.dll $(OUTDIR)/ChSound.bsc

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
 "_MBCS" /FR$(INTDIR)/ /Fp$(OUTDIR)/"ChSound.pch" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChSound.pdb" /c 
CPP_OBJS=.\debug/
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"ChSound.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChSound.bsc" 
BSC32_SBRS= \
	.\debug\ChSound.sbr \
	.\debug\headers.sbr \
	.\debug\Dll.sbr \
	.\debug\ChMPlay.sbr \
	.\debug\ChNotify.sbr \
	.\debug\ChSPrefs.sbr \
	.\debug\ChSOpen.sbr \
	.\debug\ChSoundStream.sbr \
	.\debug\ChSpeechPrefs.sbr \
	.\debug\ChSoundUtils.sbr \
	.\debug\ChTNT.sbr

$(OUTDIR)/ChSound.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386
# ADD LINK32 winmm.lib Pueblo32.lib rt32dcmp.lib tv32util.lib /NOLOGO /BASE:0x24000000 /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /OUT:"/chaco/bin/debug/modules/ChSound.dll"
LINK32_FLAGS=winmm.lib Pueblo32.lib rt32dcmp.lib tv32util.lib /NOLOGO\
 /BASE:0x24000000 /SUBSYSTEM:windows /DLL /INCREMENTAL:yes\
 /PDB:$(OUTDIR)/"ChSound.pdb" /DEBUG /MACHINE:I386 /DEF:".\ChSound.def"\
 /OUT:$(OUTDIR)/"ChSound.dll" /IMPLIB:$(OUTDIR)/"ChSound.lib"\
 /OUT:"/chaco/bin/debug/modules/ChSound.dll"  
DEF_FILE=.\ChSound.def
LINK32_OBJS= \
	.\debug\ChSound.obj \
	.\debug\headers.obj \
	.\debug\ChSound.res \
	.\debug\Dll.obj \
	.\debug\ChMPlay.obj \
	.\debug\ChNotify.obj \
	.\debug\ChSPrefs.obj \
	.\debug\ChSOpen.obj \
	.\debug\ChSoundStream.obj \
	.\debug\ChSpeechPrefs.obj \
	.\debug\ChSoundUtils.obj \
	.\debug\ChTNT.obj

$(OUTDIR)/ChSound.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "TNT Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "VAPI_Deb"
# PROP BASE Intermediate_Dir "VAPI_Deb"
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "/chaco/bin/debug/modules"
# PROP Intermediate_Dir "TNT_Debug"
OUTDIR=/chaco/bin/debug/modules
INTDIR=.\TNT_Debug

ALL : $(OUTDIR)/ChSound.dll $(OUTDIR)/ChSound.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE CPP /nologo /G5 /MD /W3 /GX /Zi /YX"headers.h" /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /D "USE_SLIDERS" /FR /c
# ADD CPP /nologo /G5 /MD /W3 /GX /Zi /YX"headers.h" /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /D "CH_VAPI" /FR /c
CPP_PROJ=/nologo /G5 /MD /W3 /GX /Zi /YX"headers.h" /Od /D "_DEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D\
 "_MBCS" /D "CH_VAPI" /FR$(INTDIR)/ /Fp$(OUTDIR)/"ChSound.pch" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChSound.pdb" /c 
CPP_OBJS=.\TNT_Debug/
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"ChSound.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChSound.bsc" 
BSC32_SBRS= \
	.\TNT_Debug\ChSound.sbr \
	.\TNT_Debug\headers.sbr \
	.\TNT_Debug\Dll.sbr \
	.\TNT_Debug\ChMPlay.sbr \
	.\TNT_Debug\ChNotify.sbr \
	.\TNT_Debug\ChSPrefs.sbr \
	.\TNT_Debug\ChSOpen.sbr \
	.\TNT_Debug\ChSoundStream.sbr \
	.\TNT_Debug\ChSpeechPrefs.sbr \
	.\TNT_Debug\ChSoundUtils.sbr \
	.\TNT_Debug\ChTNT.sbr

$(OUTDIR)/ChSound.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 winmm.lib Pueblo32.lib rt32dcmp.lib tv32util.lib /NOLOGO /BASE:0x24000000 /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /OUT:"/chaco/bin/debug/modules/ChSound.dll"
# ADD LINK32 winmm.lib Pueblo32.lib tnt32200.lib /NOLOGO /BASE:0x24000000 /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /OUT:"/chaco/bin/debug/modules/ChSound.dll" /OUT:"/chaco/bin/debug/modules/ChSound.dll" /OUT:"/chaco/bin/debug/modules/ChSound.dll" /OUT:"/chaco/bin/debug/modules/ChSound.dll" /OUT:"/chaco/bin/debug/modules/ChSound.dll" /OUT:"/chaco/bin/debug/modules/ChSound.dll"
LINK32_FLAGS=winmm.lib Pueblo32.lib tnt32200.lib /NOLOGO /BASE:0x24000000\
 /SUBSYSTEM:windows /DLL /INCREMENTAL:yes /PDB:$(OUTDIR)/"ChSound.pdb" /DEBUG\
 /MACHINE:I386 /DEF:".\ChSound.def" /OUT:$(OUTDIR)/"ChSound.dll"\
 /IMPLIB:$(OUTDIR)/"ChSound.lib" /OUT:"/chaco/bin/debug/modules/ChSound.dll"\
 /OUT:"/chaco/bin/debug/modules/ChSound.dll"\
 /OUT:"/chaco/bin/debug/modules/ChSound.dll"\
 /OUT:"/chaco/bin/debug/modules/ChSound.dll"\
 /OUT:"/chaco/bin/debug/modules/ChSound.dll"\
 /OUT:"/chaco/bin/debug/modules/ChSound.dll"  
DEF_FILE=.\ChSound.def
LINK32_OBJS= \
	.\TNT_Debug\ChSound.obj \
	.\TNT_Debug\headers.obj \
	.\TNT_Debug\ChSound.res \
	.\TNT_Debug\Dll.obj \
	.\TNT_Debug\ChMPlay.obj \
	.\TNT_Debug\ChNotify.obj \
	.\TNT_Debug\ChSPrefs.obj \
	.\TNT_Debug\ChSOpen.obj \
	.\TNT_Debug\ChSoundStream.obj \
	.\TNT_Debug\ChSpeechPrefs.obj \
	.\TNT_Debug\ChSoundUtils.obj \
	.\TNT_Debug\ChTNT.obj

$(OUTDIR)/ChSound.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "TNT Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "VAPI_Rel"
# PROP BASE Intermediate_Dir "VAPI_Rel"
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "/chaco/bin/release/modules"
# PROP Intermediate_Dir "TNT_Release"
OUTDIR=/chaco/bin/release/modules
INTDIR=.\TNT_Release

ALL : $(OUTDIR)/ChSound.dll $(OUTDIR)/ChSound.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE CPP /nologo /MD /W3 /GX /YX"headers.h" /Og /Oi /Os /Oy /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /D "USE_SLIDERS" /c
# SUBTRACT BASE CPP /Oa /Fr
# ADD CPP /nologo /MD /W3 /GX /YX"headers.h" /Og /Oi /Os /Oy /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /D "CH_VAPI" /c
# SUBTRACT CPP /Oa /Fr
CPP_PROJ=/nologo /MD /W3 /GX /YX"headers.h" /Og /Oi /Os /Oy /D "NDEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D\
 "_AFXDLL" /D "_MBCS" /D "CH_VAPI" /Fp$(OUTDIR)/"ChSound.pch" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\TNT_Release/
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"ChSound.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChSound.bsc" 
BSC32_SBRS= \
	

$(OUTDIR)/ChSound.bsc : $(OUTDIR)  $(BSC32_SBRS)
LINK32=link.exe
# ADD BASE LINK32 winmm.lib Pueblo32.lib rt32dcmp.lib /NOLOGO /BASE:0x24000000 /SUBSYSTEM:windows /DLL /MACHINE:I386
# ADD LINK32 winmm.lib Pueblo32.lib tnt32200.lib /NOLOGO /BASE:0x24000000 /SUBSYSTEM:windows /DLL /MACHINE:I386 /OUT:"/chaco/bin/release/modules/ChSound.dll" /OUT:"/chaco/bin/release/modules/ChSound.dll" /OUT:"/chaco/bin/release/modules/ChSound.dll" /OUT:"/chaco/bin/release/modules/ChSound.dll" /OUT:"/chaco/bin/release/modules/ChSound.dll"
LINK32_FLAGS=winmm.lib Pueblo32.lib tnt32200.lib /NOLOGO /BASE:0x24000000\
 /SUBSYSTEM:windows /DLL /INCREMENTAL:no /PDB:$(OUTDIR)/"ChSound.pdb"\
 /MACHINE:I386 /DEF:".\ChSound.def" /OUT:$(OUTDIR)/"ChSound.dll"\
 /IMPLIB:$(OUTDIR)/"ChSound.lib" /OUT:"/chaco/bin/release/modules/ChSound.dll"\
 /OUT:"/chaco/bin/release/modules/ChSound.dll"\
 /OUT:"/chaco/bin/release/modules/ChSound.dll"\
 /OUT:"/chaco/bin/release/modules/ChSound.dll"\
 /OUT:"/chaco/bin/release/modules/ChSound.dll"  
DEF_FILE=.\ChSound.def
LINK32_OBJS= \
	.\TNT_Release\ChSound.obj \
	.\TNT_Release\headers.obj \
	.\TNT_Release\ChSound.res \
	.\TNT_Release\Dll.obj \
	.\TNT_Release\ChMPlay.obj \
	.\TNT_Release\ChNotify.obj \
	.\TNT_Release\ChSPrefs.obj \
	.\TNT_Release\ChSOpen.obj \
	.\TNT_Release\ChSoundStream.obj \
	.\TNT_Release\ChSpeechPrefs.obj \
	.\TNT_Release\ChSoundUtils.obj \
	.\TNT_Release\ChTNT.obj

$(OUTDIR)/ChSound.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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

SOURCE=.\ChSound.cpp
DEP_CHSOU=\
	.\headers.h\
	.\ChMPlay.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChMenu.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChSound.h\
	\chaco\include\ChWorld.h\
	.\ChSoundInfo.h\
	.\ChSoundStream.h\
	.\ChTNT.h\
	.\ChSpeechPrefs.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChUtil.h\
	.\ChNotify.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChMnPtrl.h\
	\chaco\include\templcls\ChMnPtrl.inl\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	.\ChSPrefs.h\
	\chaco\include\ChHttpStream.h\
	\bin\voxware\tnt\tnt.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

!IF  "$(CFG)" == "Win32 Release"

.\release\ChSound.obj :  $(SOURCE)  $(DEP_CHSOU) $(INTDIR)

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\debug\ChSound.obj :  $(SOURCE)  $(DEP_CHSOU) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Debug"

.\TNT_Debug\ChSound.obj :  $(SOURCE)  $(DEP_CHSOU) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Release"

.\TNT_Release\ChSound.obj :  $(SOURCE)  $(DEP_CHSOU) $(INTDIR)

!ENDIF 

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
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

!IF  "$(CFG)" == "Win32 Release"

.\release\headers.obj :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\debug\headers.obj :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Debug"

.\TNT_Debug\headers.obj :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Release"

.\TNT_Release\headers.obj :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSound.def
# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSound.rc

!IF  "$(CFG)" == "Win32 Release"

.\release\ChSound.res :  $(SOURCE)  $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\debug\ChSound.res :  $(SOURCE)  $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "TNT Debug"

.\TNT_Debug\ChSound.res :  $(SOURCE)  $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "TNT Release"

.\TNT_Release\ChSound.res :  $(SOURCE)  $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

!ENDIF 

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
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

!IF  "$(CFG)" == "Win32 Release"

.\release\Dll.obj :  $(SOURCE)  $(DEP_DLL_C) $(INTDIR)

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\debug\Dll.obj :  $(SOURCE)  $(DEP_DLL_C) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Debug"

.\TNT_Debug\Dll.obj :  $(SOURCE)  $(DEP_DLL_C) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Release"

.\TNT_Release\Dll.obj :  $(SOURCE)  $(DEP_DLL_C) $(INTDIR)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMPlay.cpp
DEP_CHMPL=\
	.\headers.h\
	\bin\voxware\tnt\tnt.h\
	\chaco\include\ChCore.h\
	.\ChMPlay.h\
	.\ChSoundInfo.h\
	\chaco\include\tvGetStr.c\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	.\ChNotify.h\
	\chaco\include\ChReg.h\
	.\ChSPrefs.h\
	.\ChTNT.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChDb.h\
	\chaco\include\ChPage.h

!IF  "$(CFG)" == "Win32 Release"

.\release\ChMPlay.obj :  $(SOURCE)  $(DEP_CHMPL) $(INTDIR)

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\debug\ChMPlay.obj :  $(SOURCE)  $(DEP_CHMPL) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Debug"

.\TNT_Debug\ChMPlay.obj :  $(SOURCE)  $(DEP_CHMPL) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Release"

.\TNT_Release\ChMPlay.obj :  $(SOURCE)  $(DEP_CHMPL) $(INTDIR)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChNotify.cpp
DEP_CHNOT=\
	.\headers.h\
	\chaco\include\ChSound.h\
	.\ChNotify.h\
	.\ChMPlay.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
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
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

!IF  "$(CFG)" == "Win32 Release"

.\release\ChNotify.obj :  $(SOURCE)  $(DEP_CHNOT) $(INTDIR)

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\debug\ChNotify.obj :  $(SOURCE)  $(DEP_CHNOT) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Debug"

.\TNT_Debug\ChNotify.obj :  $(SOURCE)  $(DEP_CHNOT) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Release"

.\TNT_Release\ChNotify.obj :  $(SOURCE)  $(DEP_CHNOT) $(INTDIR)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSPrefs.cpp
DEP_CHSPR=\
	.\headers.h\
	\chaco\include\ChUtil.h\
	.\ChSOpen.h\
	.\ChSPrefs.h\
	.\ChSoundInfo.h\
	.\ChSoundUtils.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChList.h\
	.\ChMPlay.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChPage.h\
	.\ChTNT.h\
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
	.\ChNotify.h\
	\chaco\include\ChDb.h\
	\bin\voxware\tnt\tnt.h\
	\chaco\include\ChData.h

!IF  "$(CFG)" == "Win32 Release"

.\release\ChSPrefs.obj :  $(SOURCE)  $(DEP_CHSPR) $(INTDIR)

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\debug\ChSPrefs.obj :  $(SOURCE)  $(DEP_CHSPR) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Debug"

.\TNT_Debug\ChSPrefs.obj :  $(SOURCE)  $(DEP_CHSPR) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Release"

.\TNT_Release\ChSPrefs.obj :  $(SOURCE)  $(DEP_CHSPR) $(INTDIR)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSOpen.cpp
DEP_CHSOP=\
	.\headers.h\
	\chaco\include\ChSound.h\
	.\ChSOpen.h\
	.\ChSoundInfo.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	.\ChMPlay.h\
	\chaco\include\ChReg.h\
	.\ChSPrefs.h\
	.\ChTNT.h\
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
	.\ChNotify.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChPage.h\
	\bin\voxware\tnt\tnt.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

!IF  "$(CFG)" == "Win32 Release"

.\release\ChSOpen.obj :  $(SOURCE)  $(DEP_CHSOP) $(INTDIR)

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\debug\ChSOpen.obj :  $(SOURCE)  $(DEP_CHSOP) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Debug"

.\TNT_Debug\ChSOpen.obj :  $(SOURCE)  $(DEP_CHSOP) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Release"

.\TNT_Release\ChSOpen.obj :  $(SOURCE)  $(DEP_CHSOP) $(INTDIR)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSoundStream.cpp
DEP_CHSOUN=\
	.\headers.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChMsgTyp.h\
	.\ChSoundInfo.h\
	.\ChSoundStream.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChReg.h\
	.\ChSPrefs.h\
	.\ChTNT.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChDb.h\
	.\ChMPlay.h\
	\chaco\include\ChPage.h\
	\bin\voxware\tnt\tnt.h\
	.\ChNotify.h

!IF  "$(CFG)" == "Win32 Release"

.\release\ChSoundStream.obj :  $(SOURCE)  $(DEP_CHSOUN) $(INTDIR)

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\debug\ChSoundStream.obj :  $(SOURCE)  $(DEP_CHSOUN) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Debug"

.\TNT_Debug\ChSoundStream.obj :  $(SOURCE)  $(DEP_CHSOUN) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Release"

.\TNT_Release\ChSoundStream.obj :  $(SOURCE)  $(DEP_CHSOUN) $(INTDIR)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSpeechPrefs.cpp
DEP_CHSPE=\
	.\headers.h\
	\chaco\include\ChUtil.h\
	.\ChSpeechPrefs.h\
	.\ChSoundInfo.h\
	.\ChSoundUtils.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChList.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChPage.h\
	.\ChSPrefs.h\
	.\ChTNT.h\
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
	.\ChMPlay.h\
	\bin\voxware\tnt\tnt.h\
	\chaco\include\ChData.h\
	.\ChNotify.h

!IF  "$(CFG)" == "Win32 Release"

.\release\ChSpeechPrefs.obj :  $(SOURCE)  $(DEP_CHSPE) $(INTDIR)

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\debug\ChSpeechPrefs.obj :  $(SOURCE)  $(DEP_CHSPE) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Debug"

.\TNT_Debug\ChSpeechPrefs.obj :  $(SOURCE)  $(DEP_CHSPE) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Release"

.\TNT_Release\ChSpeechPrefs.obj :  $(SOURCE)  $(DEP_CHSPE) $(INTDIR)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSoundUtils.cpp
DEP_CHSOUND=\
	.\headers.h\
	.\ChSoundUtils.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChReg.h\
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
	\chaco\include\ChDb.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

!IF  "$(CFG)" == "Win32 Release"

.\release\ChSoundUtils.obj :  $(SOURCE)  $(DEP_CHSOUND) $(INTDIR)

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\debug\ChSoundUtils.obj :  $(SOURCE)  $(DEP_CHSOUND) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Debug"

.\TNT_Debug\ChSoundUtils.obj :  $(SOURCE)  $(DEP_CHSOUND) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Release"

.\TNT_Release\ChSoundUtils.obj :  $(SOURCE)  $(DEP_CHSOUND) $(INTDIR)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTNT.cpp
DEP_CHTNT=\
	.\headers.h\
	\chaco\include\ChReg.h\
	.\ChTNT.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChDb.h\
	\bin\voxware\tnt\tnt.h\
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
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

!IF  "$(CFG)" == "Win32 Release"

.\release\ChTNT.obj :  $(SOURCE)  $(DEP_CHTNT) $(INTDIR)

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\debug\ChTNT.obj :  $(SOURCE)  $(DEP_CHTNT) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Debug"

.\TNT_Debug\ChTNT.obj :  $(SOURCE)  $(DEP_CHTNT) $(INTDIR)

!ELSEIF  "$(CFG)" == "TNT Release"

.\TNT_Release\ChTNT.obj :  $(SOURCE)  $(DEP_CHTNT) $(INTDIR)

!ENDIF 

# End Source File
# End Group
# End Project
################################################################################
