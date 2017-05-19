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
!MESSAGE NMAKE /f "ChAd.mak" CFG="Win32 Debug"
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
# PROP Output_Dir "/chaco/bin/release"
# PROP Intermediate_Dir "release"
OUTDIR=/chaco/bin/release
INTDIR=.\release

ALL : $(OUTDIR)/ChAd.dll $(OUTDIR)/ChAd.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE CPP /nologo /MT /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /G5 /MD /W3 /GX /YX"headers.h" /Og /Oi /Os /Oy /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /D "CH_NOTIFY_MODULE" /c
# SUBTRACT CPP /Oa /Fr
CPP_PROJ=/nologo /G5 /MD /W3 /GX /YX"headers.h" /Og /Oi /Os /Oy /D "NDEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D\
 "_AFXDLL" /D "_MBCS" /D "CH_NOTIFY_MODULE" /Fp$(OUTDIR)/"ChAd.pch"\
 /Fo$(INTDIR)/ /c 
CPP_OBJS=.\release/
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"ChAd.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChAd.bsc" 
BSC32_SBRS= \
	

$(OUTDIR)/ChAd.bsc : $(OUTDIR)  $(BSC32_SBRS)
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386
# ADD LINK32 winmm.lib Pueblo32.lib /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386
LINK32_FLAGS=winmm.lib Pueblo32.lib /NOLOGO /SUBSYSTEM:windows /DLL\
 /INCREMENTAL:no /PDB:$(OUTDIR)/"ChAd.pdb" /MACHINE:I386 /DEF:".\ChAd.def"\
 /OUT:$(OUTDIR)/"ChAd.dll" /IMPLIB:$(OUTDIR)/"ChAd.lib" 
DEF_FILE=.\ChAd.def
LINK32_OBJS= \
	$(INTDIR)/Dll.obj \
	$(INTDIR)/ChAd.obj \
	$(INTDIR)/ChAd.res \
	$(INTDIR)/ChAdHtml.obj

$(OUTDIR)/ChAd.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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
# PROP Output_Dir "/chaco/bin/debug"
# PROP Intermediate_Dir "debug"
OUTDIR=/chaco/bin/debug
INTDIR=.\debug

ALL : $(OUTDIR)/ChAd.dll $(OUTDIR)/ChAd.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /YX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /G5 /MD /W3 /GX /Zi /YX"headers.h" /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /D "CH_NOTIFY_MODULE" /FR /c
CPP_PROJ=/nologo /G5 /MD /W3 /GX /Zi /YX"headers.h" /Od /D "_DEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D\
 "_MBCS" /D "CH_NOTIFY_MODULE" /FR$(INTDIR)/ /Fp$(OUTDIR)/"ChAd.pch"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChAd.pdb" /c 
CPP_OBJS=.\debug/
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"ChAd.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChAd.bsc" 
BSC32_SBRS= \
	$(INTDIR)/Dll.sbr \
	$(INTDIR)/ChAd.sbr \
	$(INTDIR)/ChAdHtml.sbr

$(OUTDIR)/ChAd.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386
# ADD LINK32 winmm.lib Pueblo32.lib /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386
LINK32_FLAGS=winmm.lib Pueblo32.lib /NOLOGO /SUBSYSTEM:windows /DLL\
 /INCREMENTAL:yes /PDB:$(OUTDIR)/"ChAd.pdb" /DEBUG /MACHINE:I386\
 /DEF:".\ChAd.def" /OUT:$(OUTDIR)/"ChAd.dll" /IMPLIB:$(OUTDIR)/"ChAd.lib" 
DEF_FILE=.\ChAd.def
LINK32_OBJS= \
	$(INTDIR)/Dll.obj \
	$(INTDIR)/ChAd.obj \
	$(INTDIR)/ChAd.res \
	$(INTDIR)/ChAdHtml.obj

$(OUTDIR)/ChAd.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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
	.\ChAdHtml.h\
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
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChPane.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChWnd.h

$(INTDIR)/Dll.obj :  $(SOURCE)  $(DEP_DLL_C) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAd.def
# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAd.cpp
DEP_CHAD_=\
	.\headers.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChMenu.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChPane.h\
	.\ChAdHtml.h\
	\chaco\include\ChAd.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChUtil.h\
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
	\chaco\include\ChWnd.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChAd.obj :  $(SOURCE)  $(DEP_CHAD_) $(INTDIR)

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAd.rc

$(INTDIR)/ChAd.res :  $(SOURCE)  $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAdHtml.cpp
DEP_CHADH=\
	.\headers.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChReg.h\
	.\ChAdHtml.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChPane.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChWnd.h

$(INTDIR)/ChAdHtml.obj :  $(SOURCE)  $(DEP_CHADH) $(INTDIR)

# End Source File
# End Group
# End Project
################################################################################
