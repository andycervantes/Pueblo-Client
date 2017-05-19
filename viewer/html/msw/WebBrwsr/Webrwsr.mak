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
!MESSAGE NMAKE /f "Webrwsr.mak" CFG="Win32 Debug"
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
# PROP Intermediate_Dir "WinDebug"
OUTDIR=/chaco/bin/debug
INTDIR=.\WinDebug

ALL : $(OUTDIR)/Webrwsr.exe $(OUTDIR)/Webrwsr.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /Zi /YX"stdafx.h" /Od /I "\chaco\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_EXCEPTIONS" /FR /c
CPP_PROJ=/nologo /MD /W3 /GX /Zi /YX"stdafx.h" /Od /I "\chaco\include" /D\
 "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_EXCEPTIONS" /FR$(INTDIR)/ /Fp$(OUTDIR)/"Webrwsr.pch" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"Webrwsr.pdb" /c 
CPP_OBJS=.\WinDebug/
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"Pueblo.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"Webrwsr.bsc" 
BSC32_SBRS= \
	$(INTDIR)/StdAFX.sbr \
	$(INTDIR)/Pueblo.sbr

$(OUTDIR)/Webrwsr.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /DEBUG /MACHINE:I386
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 WTracker.lib Pueblo32.lib wsock32.lib /NOLOGO /SUBSYSTEM:windows /DEBUG /MACHINE:I386 /PDB:"/chaco/bin/debug/WebTrker.pdb" /OUT:"/chaco/bin/debug/WebTrker.exe" /PDB:"/chaco/bin/debug/WebTrker.pdb" /OUT:"/chaco/bin/debug/WebTrker.exe"
LINK32_FLAGS=WTracker.lib Pueblo32.lib wsock32.lib /NOLOGO /SUBSYSTEM:windows\
 /INCREMENTAL:yes /PDB:$(OUTDIR)/"Webrwsr.pdb" /DEBUG /MACHINE:I386\
 /OUT:$(OUTDIR)/"Webrwsr.exe" /PDB:"/chaco/bin/debug/WebTrker.pdb"\
 /OUT:"/chaco/bin/debug/WebTrker.exe" /PDB:"/chaco/bin/debug/WebTrker.pdb"\
 /OUT:"/chaco/bin/debug/WebTrker.exe"  
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/StdAFX.obj \
	$(INTDIR)/Pueblo.res \
	$(INTDIR)/Pueblo.obj

$(OUTDIR)/Webrwsr.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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
# PROP Intermediate_Dir "WinRel"
OUTDIR=/chaco/bin/release
INTDIR=.\WinRel

ALL : $(OUTDIR)/Webrwsr.exe $(OUTDIR)/Webrwsr.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /YX"stdafx.h" /Og /Oi /Os /Oy /I "\chaco\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_EXCEPTIONS" /FR /c
CPP_PROJ=/nologo /MD /W3 /GX /YX"stdafx.h" /Og /Oi /Os /Oy /I "\chaco\include"\
 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_EXCEPTIONS" /FR$(INTDIR)/ /Fp$(OUTDIR)/"Webrwsr.pch" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\WinRel/
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"Pueblo.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"Webrwsr.bsc" 
BSC32_SBRS= \
	$(INTDIR)/StdAFX.sbr \
	$(INTDIR)/Pueblo.sbr

$(OUTDIR)/Webrwsr.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /MACHINE:I386
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 WTracker.lib Pueblo32.lib wsock32.lib /NOLOGO /SUBSYSTEM:windows /MACHINE:I386 /OUT:"/chaco/bin/release/WebTrcker.exe" /PDB:"/chaco/bin/release/WebTrcker.pdb"
LINK32_FLAGS=WTracker.lib Pueblo32.lib wsock32.lib /NOLOGO /SUBSYSTEM:windows\
 /INCREMENTAL:no /PDB:$(OUTDIR)/"Webrwsr.pdb" /MACHINE:I386\
 /OUT:$(OUTDIR)/"Webrwsr.exe" /OUT:"/chaco/bin/release/WebTrcker.exe"\
 /PDB:"/chaco/bin/release/WebTrcker.pdb"  
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/StdAFX.obj \
	$(INTDIR)/Pueblo.res \
	$(INTDIR)/Pueblo.obj

$(OUTDIR)/Webrwsr.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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

SOURCE=.\StdAFX.cpp

!IF  "$(CFG)" == "Win32 Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

$(INTDIR)/StdAFX.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /D "_DEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_EXCEPTIONS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"Webrwsr.pch" /Yc"stdafx.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"Webrwsr.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

$(INTDIR)/StdAFX.obj :  $(SOURCE)  $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Og /Oi /Os /Oy /I "\chaco\include" /D "NDEBUG"\
 /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_EXCEPTIONS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"Webrwsr.pch" /Yc"stdafx.h" /Fo$(INTDIR)/ /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo.rc

$(INTDIR)/Pueblo.res :  $(SOURCE)  $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo.cpp
DEP_PUEBL=\
	\CHACO\INCLUDE\ChHtpCon.h\
	.\Pueblo.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\INCLUDE\ChUrlMap.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChTypes.h

$(INTDIR)/Pueblo.obj :  $(SOURCE)  $(DEP_PUEBL) $(INTDIR)

# End Source File
# End Group
# End Project
################################################################################
