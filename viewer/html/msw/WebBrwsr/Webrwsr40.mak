# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Webrwsr - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Webrwsr - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Webrwsr - Win32 Debug" && "$(CFG)" !=\
 "Webrwsr - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Webrwsr40.mak" CFG="Webrwsr - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Webrwsr - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Webrwsr - Win32 Release" (based on "Win32 (x86) Application")
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
RSC=rc.exe
MTL=mktyplib.exe
CPP=cl.exe

!IF  "$(CFG)" == "Webrwsr - Win32 Debug"

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

ALL : "$(OUTDIR)\Webrwsr.exe" ".\WinDebug\Webrwsr40.pch"

CLEAN : 
	-@erase "$(INTDIR)\Pueblo.obj"
	-@erase "$(INTDIR)\Pueblo.res"
	-@erase "$(INTDIR)\StdAFX.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\Webrwsr40.pch"
	-@erase "$(OUTDIR)\Webrwsr.exe"
	-@erase "$(OUTDIR)\Webrwsr.ilk"
	-@erase "$(OUTDIR)\Webrwsr.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /YX"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /D "_DEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS"\
 /Fp"$(INTDIR)/Webrwsr40.pch" /YX"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\WinDebug/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Pueblo.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Webrwsr40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 WTracker.lib Pueblo32.lib wsock32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"/chaco/bin/debug/Webrwsr.exe" /PDB:"/chaco/bin/debug/WebTrker.pdb" /OUT:"/chaco/bin/debug/WebTrker.exe" /PDB:"/chaco/bin/debug/WebTrker.pdb" /OUT:"/chaco/bin/debug/WebTrker.exe"
LINK32_FLAGS=WTracker.lib Pueblo32.lib wsock32.lib /nologo /subsystem:windows\
 /incremental:yes /pdb:"$(OUTDIR)/Webrwsr.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/Webrwsr.exe" /PDB:"/chaco/bin/debug/WebTrker.pdb"\
 /OUT:"/chaco/bin/debug/WebTrker.exe" /PDB:"/chaco/bin/debug/WebTrker.pdb"\
 /OUT:"/chaco/bin/debug/WebTrker.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Pueblo.obj" \
	"$(INTDIR)\Pueblo.res" \
	"$(INTDIR)\StdAFX.obj"

"$(OUTDIR)\Webrwsr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Webrwsr - Win32 Release"

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

ALL : "$(OUTDIR)\Webrwsr.exe" ".\WinRel\Webrwsr40.pch"

CLEAN : 
	-@erase "$(INTDIR)\Pueblo.obj"
	-@erase "$(INTDIR)\Pueblo.res"
	-@erase "$(INTDIR)\StdAFX.obj"
	-@erase "$(INTDIR)\Webrwsr40.pch"
	-@erase "$(OUTDIR)\Webrwsr.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /Og /Oi /Os /Oy /I "\chaco\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /YX"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MD /W3 /GX /Og /Oi /Os /Oy /I "\chaco\include" /D "NDEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS"\
 /Fp"$(INTDIR)/Webrwsr40.pch" /YX"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\WinRel/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Pueblo.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Webrwsr40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 WTracker.lib Pueblo32.lib wsock32.lib /nologo /subsystem:windows /machine:I386 /out:"/chaco/bin/release/Webrwsr.exe" /OUT:"/chaco/bin/release/WebTrcker.exe" /PDB:"/chaco/bin/release/WebTrcker.pdb"
LINK32_FLAGS=WTracker.lib Pueblo32.lib wsock32.lib /nologo /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)/Webrwsr.pdb" /machine:I386\
 /out:"$(OUTDIR)/Webrwsr.exe" /OUT:"/chaco/bin/release/WebTrcker.exe"\
 /PDB:"/chaco/bin/release/WebTrcker.pdb" 
LINK32_OBJS= \
	"$(INTDIR)\Pueblo.obj" \
	"$(INTDIR)\Pueblo.res" \
	"$(INTDIR)\StdAFX.obj"

"$(OUTDIR)\Webrwsr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "Webrwsr - Win32 Debug"
# Name "Webrwsr - Win32 Release"

!IF  "$(CFG)" == "Webrwsr - Win32 Debug"

!ELSEIF  "$(CFG)" == "Webrwsr - Win32 Release"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\StdAFX.cpp
DEP_CPP_STDAF=\
	".\stdafx.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChTypes.h"\
	

!IF  "$(CFG)" == "Webrwsr - Win32 Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /D "_DEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS"\
 /Fp"$(INTDIR)/Webrwsr40.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c\
 $(SOURCE) \
	

"$(INTDIR)\StdAFX.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Webrwsr40.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Webrwsr - Win32 Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /Og /Oi /Os /Oy /I "\chaco\include" /D "NDEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS"\
 /Fp"$(INTDIR)/Webrwsr40.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAFX.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Webrwsr40.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo.rc

"$(INTDIR)\Pueblo.res" : $(SOURCE) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo.cpp
DEP_CPP_PUEBL=\
	".\Pueblo.h"\
	".\stdafx.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChHtpCon.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUrlMap.h"\
	"\chaco\include\ChWebTracker.h"\
	

"$(INTDIR)\Pueblo.obj" : $(SOURCE) $(DEP_CPP_PUEBL) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
