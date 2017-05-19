# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=ChSound - Win32 TNT Debug
!MESSAGE No configuration specified.  Defaulting to ChSound - Win32 TNT Debug.
!ENDIF 

!IF "$(CFG)" != "ChSound - Win32 Release" && "$(CFG)" !=\
 "ChSound - Win32 Debug" && "$(CFG)" != "ChSound - Win32 TNT Debug" && "$(CFG)"\
 != "ChSound - Win32 TNT Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "ChSound40.mak" CFG="ChSound - Win32 TNT Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ChSound - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ChSound - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ChSound - Win32 TNT Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ChSound - Win32 TNT Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
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
# PROP Target_Last_Scanned "ChSound - Win32 TNT Release"
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "ChSound - Win32 Release"

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

ALL : "$(OUTDIR)\ChSound.dll"

CLEAN : 
	-@erase "$(INTDIR)\ChMPlay.obj"
	-@erase "$(INTDIR)\ChNotify.obj"
	-@erase "$(INTDIR)\ChSOpen.obj"
	-@erase "$(INTDIR)\ChSound.obj"
	-@erase "$(INTDIR)\ChSound.res"
	-@erase "$(INTDIR)\ChSoundStream.obj"
	-@erase "$(INTDIR)\ChSoundUtils.obj"
	-@erase "$(INTDIR)\ChSpeechPrefs.obj"
	-@erase "$(INTDIR)\ChSPrefs.obj"
	-@erase "$(INTDIR)\ChTNT.obj"
	-@erase "$(INTDIR)\Dll.obj"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(OUTDIR)\ChSound.dll"
	-@erase "$(OUTDIR)\ChSound.exp"
	-@erase "$(OUTDIR)\ChSound.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

$(OUTDIR)/ChSound.bsc : $(OUTDIR)  $(BSC32_SBRS)
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /YX /c
# ADD CPP /nologo /MD /W3 /GX /Og /Oi /Os /Oy /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /YX"headers.h" /c
# SUBTRACT CPP /Oa /Fr
CPP_PROJ=/nologo /MD /W3 /GX /Og /Oi /Os /Oy /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/ChSound40.pch" /YX"headers.h"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/ChSound.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/ChSound40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 winmm.lib Pueblo32.lib /nologo /base:0x24000000 /subsystem:windows /dll /machine:I386 /out:"\chaco\bin\Release\modules/ChSound.dll" /implib:"/chaco/bin/Release/modules/ChSound.lib"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=winmm.lib Pueblo32.lib /nologo /base:0x24000000 /subsystem:windows\
 /dll /incremental:no /pdb:"$(OUTDIR)/ChSound.pdb" /machine:I386\
 /def:".\ChSound.def" /out:"$(OUTDIR)/ChSound.dll"\
 /implib:"$(OUTDIR)/ChSound.lib"\
 /implib:"/chaco/bin/Release/modules/ChSound.lib" 
DEF_FILE= \
	".\ChSound.def"
LINK32_OBJS= \
	"$(INTDIR)\ChMPlay.obj" \
	"$(INTDIR)\ChNotify.obj" \
	"$(INTDIR)\ChSOpen.obj" \
	"$(INTDIR)\ChSound.obj" \
	"$(INTDIR)\ChSound.res" \
	"$(INTDIR)\ChSoundStream.obj" \
	"$(INTDIR)\ChSoundUtils.obj" \
	"$(INTDIR)\ChSpeechPrefs.obj" \
	"$(INTDIR)\ChSPrefs.obj" \
	"$(INTDIR)\ChTNT.obj" \
	"$(INTDIR)\Dll.obj" \
	"$(INTDIR)\headers.obj"

"$(OUTDIR)\ChSound.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"

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

ALL : "$(OUTDIR)\ChSound40.dll" "$(OUTDIR)\ChSound40.bsc"

CLEAN : 
	-@erase "$(INTDIR)\ChMPlay.obj"
	-@erase "$(INTDIR)\ChMPlay.sbr"
	-@erase "$(INTDIR)\ChNotify.obj"
	-@erase "$(INTDIR)\ChNotify.sbr"
	-@erase "$(INTDIR)\ChSOpen.obj"
	-@erase "$(INTDIR)\ChSOpen.sbr"
	-@erase "$(INTDIR)\ChSound.obj"
	-@erase "$(INTDIR)\ChSound.res"
	-@erase "$(INTDIR)\ChSound.sbr"
	-@erase "$(INTDIR)\ChSoundStream.obj"
	-@erase "$(INTDIR)\ChSoundStream.sbr"
	-@erase "$(INTDIR)\ChSoundUtils.obj"
	-@erase "$(INTDIR)\ChSoundUtils.sbr"
	-@erase "$(INTDIR)\ChSpeechPrefs.obj"
	-@erase "$(INTDIR)\ChSpeechPrefs.sbr"
	-@erase "$(INTDIR)\ChSPrefs.obj"
	-@erase "$(INTDIR)\ChSPrefs.sbr"
	-@erase "$(INTDIR)\ChTNT.obj"
	-@erase "$(INTDIR)\ChTNT.sbr"
	-@erase "$(INTDIR)\Dll.obj"
	-@erase "$(INTDIR)\Dll.sbr"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(INTDIR)\headers.sbr"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\ChSound40.bsc"
	-@erase "$(OUTDIR)\ChSound40.dll"
	-@erase "$(OUTDIR)\ChSound40.exp"
	-@erase "$(OUTDIR)\ChSound40.ilk"
	-@erase "$(OUTDIR)\ChSound40.lib"
	-@erase "$(OUTDIR)\ChSound40.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX /c
# ADD CPP /nologo /G5 /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /FR /YX"headers.h" /c
CPP_PROJ=/nologo /G5 /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D\
 "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/ChSound40.pch"\
 /YX"headers.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\debug/
CPP_SBRS=.\debug/
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/ChSound.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/ChSound40.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ChMPlay.sbr" \
	"$(INTDIR)\ChNotify.sbr" \
	"$(INTDIR)\ChSOpen.sbr" \
	"$(INTDIR)\ChSound.sbr" \
	"$(INTDIR)\ChSoundStream.sbr" \
	"$(INTDIR)\ChSoundUtils.sbr" \
	"$(INTDIR)\ChSpeechPrefs.sbr" \
	"$(INTDIR)\ChSPrefs.sbr" \
	"$(INTDIR)\ChTNT.sbr" \
	"$(INTDIR)\Dll.sbr" \
	"$(INTDIR)\headers.sbr"

"$(OUTDIR)\ChSound40.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 winmm.lib Pueblo32.lib /nologo /base:0x24000000 /subsystem:windows /dll /debug /machine:I386 /out:"/chaco/bin/debug/modules/ChSound.dll" /pdb:"/chaco/bin/debug/modules/ChSound.pdb"
LINK32_FLAGS=winmm.lib Pueblo32.lib /nologo /base:0x24000000 /subsystem:windows\
 /dll /incremental:yes /pdb:"$(OUTDIR)/ChSound40.pdb" /debug /machine:I386\
 /def:".\ChSound.def" /out:"$(OUTDIR)/ChSound40.dll"\
 /implib:"$(OUTDIR)/ChSound40.lib" /out:"/chaco/bin/debug/modules/ChSound.dll"\
 /pdb:"/chaco/bin/debug/modules/ChSound.pdb" 
DEF_FILE= \
	".\ChSound.def"
LINK32_OBJS= \
	"$(INTDIR)\ChMPlay.obj" \
	"$(INTDIR)\ChNotify.obj" \
	"$(INTDIR)\ChSOpen.obj" \
	"$(INTDIR)\ChSound.obj" \
	"$(INTDIR)\ChSound.res" \
	"$(INTDIR)\ChSoundStream.obj" \
	"$(INTDIR)\ChSoundUtils.obj" \
	"$(INTDIR)\ChSpeechPrefs.obj" \
	"$(INTDIR)\ChSPrefs.obj" \
	"$(INTDIR)\ChTNT.obj" \
	"$(INTDIR)\Dll.obj" \
	"$(INTDIR)\headers.obj"

"$(OUTDIR)\ChSound40.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "ChSound_"
# PROP BASE Intermediate_Dir "ChSound_"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "d:\chaco\bin\debug\modules\"
# PROP Intermediate_Dir "TNT_Debug"
# PROP Target_Dir ""
OUTDIR=d:\chaco\bin\debug\modules
INTDIR=.\TNT_Debug

ALL : "$(OUTDIR)\ChSound.dll" "$(OUTDIR)\ChSound40.bsc"

CLEAN : 
	-@erase "$(INTDIR)\ChMPlay.obj"
	-@erase "$(INTDIR)\ChMPlay.sbr"
	-@erase "$(INTDIR)\ChNotify.obj"
	-@erase "$(INTDIR)\ChNotify.sbr"
	-@erase "$(INTDIR)\ChSOpen.obj"
	-@erase "$(INTDIR)\ChSOpen.sbr"
	-@erase "$(INTDIR)\ChSound.obj"
	-@erase "$(INTDIR)\ChSound.res"
	-@erase "$(INTDIR)\ChSound.sbr"
	-@erase "$(INTDIR)\ChSoundStream.obj"
	-@erase "$(INTDIR)\ChSoundStream.sbr"
	-@erase "$(INTDIR)\ChSoundUtils.obj"
	-@erase "$(INTDIR)\ChSoundUtils.sbr"
	-@erase "$(INTDIR)\ChSpeechPrefs.obj"
	-@erase "$(INTDIR)\ChSpeechPrefs.sbr"
	-@erase "$(INTDIR)\ChSPrefs.obj"
	-@erase "$(INTDIR)\ChSPrefs.sbr"
	-@erase "$(INTDIR)\ChTNT.obj"
	-@erase "$(INTDIR)\ChTNT.sbr"
	-@erase "$(INTDIR)\Dll.obj"
	-@erase "$(INTDIR)\Dll.sbr"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(INTDIR)\headers.sbr"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\ChSound.dll"
	-@erase "$(OUTDIR)\ChSound.exp"
	-@erase "$(OUTDIR)\ChSound.ilk"
	-@erase "$(OUTDIR)\ChSound.lib"
	-@erase "$(OUTDIR)\ChSound.pdb"
	-@erase "$(OUTDIR)\ChSound40.bsc"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /G5 /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "CH_VAPI" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /FR /YX"headers.h" /c
# ADD CPP /nologo /G5 /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "CH_VAPI" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "CH_USE_VOXWARE" /FR /YX"headers.h" /c
CPP_PROJ=/nologo /G5 /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "CH_VAPI" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "CH_USE_VOXWARE" /FR"$(INTDIR)/"\
 /Fp"$(INTDIR)/ChSound40.pch" /YX"headers.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\TNT_Debug/
CPP_SBRS=.\TNT_Debug/
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/ChSound.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/ChSound40.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ChMPlay.sbr" \
	"$(INTDIR)\ChNotify.sbr" \
	"$(INTDIR)\ChSOpen.sbr" \
	"$(INTDIR)\ChSound.sbr" \
	"$(INTDIR)\ChSoundStream.sbr" \
	"$(INTDIR)\ChSoundUtils.sbr" \
	"$(INTDIR)\ChSpeechPrefs.sbr" \
	"$(INTDIR)\ChSPrefs.sbr" \
	"$(INTDIR)\ChTNT.sbr" \
	"$(INTDIR)\Dll.sbr" \
	"$(INTDIR)\headers.sbr"

"$(OUTDIR)\ChSound40.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 tv32util.lib winmm.lib Pueblo32.lib vapi.lib rt32dcmp.lib /nologo /base:0x24000000 /subsystem:windows /dll /debug /machine:I386 /out:"/chaco/bin/debug/modules/ChSound.dll" /OUT:"/chaco/bin/debug/modules/ChSound.dll" /OUT:"/chaco/bin/debug/modules/ChSound.dll" /OUT:"/chaco/bin/debug/modules/ChSound.dll" /OUT:"/chaco/bin/debug/modules/ChSound.dll" /OUT:"/chaco/bin/debug/modules/ChSound.dll" /OUT:"/chaco/bin/debug/modules/ChSound.dll"
# ADD LINK32 winmm.lib Pueblo32.lib tnt32200.lib /nologo /base:0x24000000 /subsystem:windows /dll /debug /machine:I386 /out:"d:\chaco\bin\debug\modules\ChSound.dll"
LINK32_FLAGS=winmm.lib Pueblo32.lib tnt32200.lib /nologo /base:0x24000000\
 /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)/ChSound.pdb" /debug\
 /machine:I386 /def:".\ChSound.def" /out:"$(OUTDIR)/ChSound.dll"\
 /implib:"$(OUTDIR)/ChSound.lib" 
DEF_FILE= \
	".\ChSound.def"
LINK32_OBJS= \
	"$(INTDIR)\ChMPlay.obj" \
	"$(INTDIR)\ChNotify.obj" \
	"$(INTDIR)\ChSOpen.obj" \
	"$(INTDIR)\ChSound.obj" \
	"$(INTDIR)\ChSound.res" \
	"$(INTDIR)\ChSoundStream.obj" \
	"$(INTDIR)\ChSoundUtils.obj" \
	"$(INTDIR)\ChSpeechPrefs.obj" \
	"$(INTDIR)\ChSPrefs.obj" \
	"$(INTDIR)\ChTNT.obj" \
	"$(INTDIR)\Dll.obj" \
	"$(INTDIR)\headers.obj"

"$(OUTDIR)\ChSound.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ChSound0"
# PROP BASE Intermediate_Dir "ChSound0"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "d:\chaco\bin\release\modules\"
# PROP Intermediate_Dir "TNT_Release"
# PROP Target_Dir ""
OUTDIR=d:\chaco\bin\release\modules
INTDIR=.\TNT_Release

ALL : "$(OUTDIR)\ChSound.dll"

CLEAN : 
	-@erase "$(INTDIR)\ChMPlay.obj"
	-@erase "$(INTDIR)\ChNotify.obj"
	-@erase "$(INTDIR)\ChSOpen.obj"
	-@erase "$(INTDIR)\ChSound.obj"
	-@erase "$(INTDIR)\ChSound.res"
	-@erase "$(INTDIR)\ChSoundStream.obj"
	-@erase "$(INTDIR)\ChSoundUtils.obj"
	-@erase "$(INTDIR)\ChSpeechPrefs.obj"
	-@erase "$(INTDIR)\ChSPrefs.obj"
	-@erase "$(INTDIR)\ChTNT.obj"
	-@erase "$(INTDIR)\Dll.obj"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(OUTDIR)\ChSound.dll"
	-@erase "$(OUTDIR)\ChSound.exp"
	-@erase "$(OUTDIR)\ChSound.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /Og /Oi /Os /Oy /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "CH_VAPI" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /YX"headers.h" /c
# SUBTRACT BASE CPP /Oa /Fr
# ADD CPP /nologo /MD /W3 /GX /Og /Oi /Os /Oy /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "CH_VAPI" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "CH_USE_VOXWARE" /YX"headers.h" /c
# SUBTRACT CPP /Oa /Fr
CPP_PROJ=/nologo /MD /W3 /GX /Og /Oi /Os /Oy /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "CH_VAPI" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "CH_USE_VOXWARE"\
 /Fp"$(INTDIR)/ChSound40.pch" /YX"headers.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\TNT_Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/ChSound.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/ChSound40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 winmm.lib Pueblo32.lib rt32dcmp.lib vapi.lib /nologo /base:0x24000000 /subsystem:windows /dll /machine:I386 /out:"/chaco/bin/release/modules/ChSound.dll" /OUT:"/chaco/bin/release/modules/ChSound.dll" /OUT:"/chaco/bin/release/modules/ChSound.dll" /OUT:"/chaco/bin/release/modules/ChSound.dll" /OUT:"/chaco/bin/release/modules/ChSound.dll" /OUT:"/chaco/bin/release/modules/ChSound.dll"
# ADD LINK32 winmm.lib Pueblo32.lib tnt32200.lib /nologo /base:0x24000000 /subsystem:windows /dll /machine:I386 /out:"d:\chaco\bin\release\modules\ChSound.dll"
LINK32_FLAGS=winmm.lib Pueblo32.lib tnt32200.lib /nologo /base:0x24000000\
 /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)/ChSound.pdb"\
 /machine:I386 /def:".\ChSound.def" /out:"$(OUTDIR)/ChSound.dll"\
 /implib:"$(OUTDIR)/ChSound.lib" 
DEF_FILE= \
	".\ChSound.def"
LINK32_OBJS= \
	"$(INTDIR)\ChMPlay.obj" \
	"$(INTDIR)\ChNotify.obj" \
	"$(INTDIR)\ChSOpen.obj" \
	"$(INTDIR)\ChSound.obj" \
	"$(INTDIR)\ChSound.res" \
	"$(INTDIR)\ChSoundStream.obj" \
	"$(INTDIR)\ChSoundUtils.obj" \
	"$(INTDIR)\ChSpeechPrefs.obj" \
	"$(INTDIR)\ChSPrefs.obj" \
	"$(INTDIR)\ChTNT.obj" \
	"$(INTDIR)\Dll.obj" \
	"$(INTDIR)\headers.obj"

"$(OUTDIR)\ChSound.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "ChSound - Win32 Release"
# Name "ChSound - Win32 Debug"
# Name "ChSound - Win32 TNT Debug"
# Name "ChSound - Win32 TNT Release"

!IF  "$(CFG)" == "ChSound - Win32 Release"

!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"

!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"

!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ChSound.cpp
DEP_CPP_CHSOU=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSoundInfo.h"\
	".\ChSoundStream.h"\
	".\ChSpeechPrefs.h"\
	".\ChSpeechStatus.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHttpStream.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChMenu.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSound.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\templcls\ChMnPtrl.h"\
	{$(INCLUDE)}"\templcls\ChMnPtrl.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSOU=\
	"..\..\unix\ChTxtMud\UnixRes.h"\
	".\vwrres.h"\
	

!IF  "$(CFG)" == "ChSound - Win32 Release"


"$(INTDIR)\ChSound.obj" : $(SOURCE) $(DEP_CPP_CHSOU) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"


"$(INTDIR)\ChSound.obj" : $(SOURCE) $(DEP_CPP_CHSOU) "$(INTDIR)"

"$(INTDIR)\ChSound.sbr" : $(SOURCE) $(DEP_CPP_CHSOU) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"


"$(INTDIR)\ChSound.obj" : $(SOURCE) $(DEP_CPP_CHSOU) "$(INTDIR)"

"$(INTDIR)\ChSound.sbr" : $(SOURCE) $(DEP_CPP_CHSOU) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"


"$(INTDIR)\ChSound.obj" : $(SOURCE) $(DEP_CPP_CHSOU) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\headers.cpp

!IF  "$(CFG)" == "ChSound - Win32 Release"

DEP_CPP_HEADE=\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\headers.obj" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"

DEP_CPP_HEADE=\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\headers.obj" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"

"$(INTDIR)\headers.sbr" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"

DEP_CPP_HEADE=\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\headers.obj" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"

"$(INTDIR)\headers.sbr" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"

DEP_CPP_HEADE=\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\headers.obj" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSound.def

!IF  "$(CFG)" == "ChSound - Win32 Release"

!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"

!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"

!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSound.rc

!IF  "$(CFG)" == "ChSound - Win32 Release"


"$(INTDIR)\ChSound.res" : $(SOURCE) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"


"$(INTDIR)\ChSound.res" : $(SOURCE) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"


"$(INTDIR)\ChSound.res" : $(SOURCE) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"


"$(INTDIR)\ChSound.res" : $(SOURCE) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dll.cpp

!IF  "$(CFG)" == "ChSound - Win32 Release"

DEP_CPP_DLL_C=\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\Dll.obj" : $(SOURCE) $(DEP_CPP_DLL_C) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"

DEP_CPP_DLL_C=\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\Dll.obj" : $(SOURCE) $(DEP_CPP_DLL_C) "$(INTDIR)"

"$(INTDIR)\Dll.sbr" : $(SOURCE) $(DEP_CPP_DLL_C) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"

DEP_CPP_DLL_C=\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\Dll.obj" : $(SOURCE) $(DEP_CPP_DLL_C) "$(INTDIR)"

"$(INTDIR)\Dll.sbr" : $(SOURCE) $(DEP_CPP_DLL_C) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"

DEP_CPP_DLL_C=\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\Dll.obj" : $(SOURCE) $(DEP_CPP_DLL_C) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMPlay.cpp

!IF  "$(CFG)" == "ChSound - Win32 Release"

DEP_CPP_CHMPL=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSoundInfo.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHMPL=\
	".\vwrres.h"\
	

"$(INTDIR)\ChMPlay.obj" : $(SOURCE) $(DEP_CPP_CHMPL) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"

DEP_CPP_CHMPL=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSoundInfo.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHMPL=\
	".\vwrres.h"\
	

"$(INTDIR)\ChMPlay.obj" : $(SOURCE) $(DEP_CPP_CHMPL) "$(INTDIR)"

"$(INTDIR)\ChMPlay.sbr" : $(SOURCE) $(DEP_CPP_CHMPL) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"

DEP_CPP_CHMPL=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSoundInfo.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHMPL=\
	".\vwrres.h"\
	

"$(INTDIR)\ChMPlay.obj" : $(SOURCE) $(DEP_CPP_CHMPL) "$(INTDIR)"

"$(INTDIR)\ChMPlay.sbr" : $(SOURCE) $(DEP_CPP_CHMPL) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"

DEP_CPP_CHMPL=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSoundInfo.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHMPL=\
	".\vwrres.h"\
	

"$(INTDIR)\ChMPlay.obj" : $(SOURCE) $(DEP_CPP_CHMPL) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChNotify.cpp

!IF  "$(CFG)" == "ChSound - Win32 Release"

DEP_CPP_CHNOT=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChSound.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChNotify.obj" : $(SOURCE) $(DEP_CPP_CHNOT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"

DEP_CPP_CHNOT=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChSound.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChNotify.obj" : $(SOURCE) $(DEP_CPP_CHNOT) "$(INTDIR)"

"$(INTDIR)\ChNotify.sbr" : $(SOURCE) $(DEP_CPP_CHNOT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"

DEP_CPP_CHNOT=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChSound.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChNotify.obj" : $(SOURCE) $(DEP_CPP_CHNOT) "$(INTDIR)"

"$(INTDIR)\ChNotify.sbr" : $(SOURCE) $(DEP_CPP_CHNOT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"

DEP_CPP_CHNOT=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChSound.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChNotify.obj" : $(SOURCE) $(DEP_CPP_CHNOT) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSPrefs.cpp

!IF  "$(CFG)" == "ChSound - Win32 Release"

DEP_CPP_CHSPR=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSOpen.h"\
	".\ChSoundInfo.h"\
	".\ChSoundUtils.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSPR=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSPrefs.obj" : $(SOURCE) $(DEP_CPP_CHSPR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"

DEP_CPP_CHSPR=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSOpen.h"\
	".\ChSoundInfo.h"\
	".\ChSoundUtils.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSPR=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSPrefs.obj" : $(SOURCE) $(DEP_CPP_CHSPR) "$(INTDIR)"

"$(INTDIR)\ChSPrefs.sbr" : $(SOURCE) $(DEP_CPP_CHSPR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"

DEP_CPP_CHSPR=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSOpen.h"\
	".\ChSoundInfo.h"\
	".\ChSoundUtils.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSPR=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSPrefs.obj" : $(SOURCE) $(DEP_CPP_CHSPR) "$(INTDIR)"

"$(INTDIR)\ChSPrefs.sbr" : $(SOURCE) $(DEP_CPP_CHSPR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"

DEP_CPP_CHSPR=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSOpen.h"\
	".\ChSoundInfo.h"\
	".\ChSoundUtils.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSPR=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSPrefs.obj" : $(SOURCE) $(DEP_CPP_CHSPR) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSOpen.cpp

!IF  "$(CFG)" == "ChSound - Win32 Release"

DEP_CPP_CHSOP=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSOpen.h"\
	".\ChSoundInfo.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSound.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSOP=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSOpen.obj" : $(SOURCE) $(DEP_CPP_CHSOP) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"

DEP_CPP_CHSOP=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSOpen.h"\
	".\ChSoundInfo.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSound.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSOP=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSOpen.obj" : $(SOURCE) $(DEP_CPP_CHSOP) "$(INTDIR)"

"$(INTDIR)\ChSOpen.sbr" : $(SOURCE) $(DEP_CPP_CHSOP) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"

DEP_CPP_CHSOP=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSOpen.h"\
	".\ChSoundInfo.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSound.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSOP=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSOpen.obj" : $(SOURCE) $(DEP_CPP_CHSOP) "$(INTDIR)"

"$(INTDIR)\ChSOpen.sbr" : $(SOURCE) $(DEP_CPP_CHSOP) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"

DEP_CPP_CHSOP=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSOpen.h"\
	".\ChSoundInfo.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSound.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSOP=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSOpen.obj" : $(SOURCE) $(DEP_CPP_CHSOP) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSoundStream.cpp
DEP_CPP_CHSOUN=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSoundInfo.h"\
	".\ChSoundStream.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHttpStream.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSOUN=\
	".\vwrres.h"\
	

!IF  "$(CFG)" == "ChSound - Win32 Release"


"$(INTDIR)\ChSoundStream.obj" : $(SOURCE) $(DEP_CPP_CHSOUN) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"


"$(INTDIR)\ChSoundStream.obj" : $(SOURCE) $(DEP_CPP_CHSOUN) "$(INTDIR)"

"$(INTDIR)\ChSoundStream.sbr" : $(SOURCE) $(DEP_CPP_CHSOUN) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"


"$(INTDIR)\ChSoundStream.obj" : $(SOURCE) $(DEP_CPP_CHSOUN) "$(INTDIR)"

"$(INTDIR)\ChSoundStream.sbr" : $(SOURCE) $(DEP_CPP_CHSOUN) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"


"$(INTDIR)\ChSoundStream.obj" : $(SOURCE) $(DEP_CPP_CHSOUN) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSpeechPrefs.cpp

!IF  "$(CFG)" == "ChSound - Win32 Release"

DEP_CPP_CHSPE=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSoundInfo.h"\
	".\ChSoundUtils.h"\
	".\ChSpeechPrefs.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSPE=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSpeechPrefs.obj" : $(SOURCE) $(DEP_CPP_CHSPE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"

DEP_CPP_CHSPE=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSoundInfo.h"\
	".\ChSoundUtils.h"\
	".\ChSpeechPrefs.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSPE=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSpeechPrefs.obj" : $(SOURCE) $(DEP_CPP_CHSPE) "$(INTDIR)"

"$(INTDIR)\ChSpeechPrefs.sbr" : $(SOURCE) $(DEP_CPP_CHSPE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"

DEP_CPP_CHSPE=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSoundInfo.h"\
	".\ChSoundUtils.h"\
	".\ChSpeechPrefs.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSPE=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSpeechPrefs.obj" : $(SOURCE) $(DEP_CPP_CHSPE) "$(INTDIR)"

"$(INTDIR)\ChSpeechPrefs.sbr" : $(SOURCE) $(DEP_CPP_CHSPE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"

DEP_CPP_CHSPE=\
	".\ChMPlay.h"\
	".\ChNotify.h"\
	".\ChSoundInfo.h"\
	".\ChSoundUtils.h"\
	".\ChSpeechPrefs.h"\
	".\ChSPrefs.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHSPE=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSpeechPrefs.obj" : $(SOURCE) $(DEP_CPP_CHSPE) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSoundUtils.cpp

!IF  "$(CFG)" == "ChSound - Win32 Release"

DEP_CPP_CHSOUND=\
	".\ChSoundUtils.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChSoundUtils.obj" : $(SOURCE) $(DEP_CPP_CHSOUND) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"

DEP_CPP_CHSOUND=\
	".\ChSoundUtils.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChSoundUtils.obj" : $(SOURCE) $(DEP_CPP_CHSOUND) "$(INTDIR)"

"$(INTDIR)\ChSoundUtils.sbr" : $(SOURCE) $(DEP_CPP_CHSOUND) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"

DEP_CPP_CHSOUND=\
	".\ChSoundUtils.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChSoundUtils.obj" : $(SOURCE) $(DEP_CPP_CHSOUND) "$(INTDIR)"

"$(INTDIR)\ChSoundUtils.sbr" : $(SOURCE) $(DEP_CPP_CHSOUND) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"

DEP_CPP_CHSOUND=\
	".\ChSoundUtils.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChSoundUtils.obj" : $(SOURCE) $(DEP_CPP_CHSOUND) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTNT.cpp

!IF  "$(CFG)" == "ChSound - Win32 Release"

DEP_CPP_CHTNT=\
	".\ChSpeechPrefs.h"\
	".\ChSpeechStatus.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHTNT=\
	".\vwrres.h"\
	

"$(INTDIR)\ChTNT.obj" : $(SOURCE) $(DEP_CPP_CHTNT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 Debug"

DEP_CPP_CHTNT=\
	".\ChSpeechPrefs.h"\
	".\ChSpeechStatus.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHTNT=\
	".\vwrres.h"\
	

"$(INTDIR)\ChTNT.obj" : $(SOURCE) $(DEP_CPP_CHTNT) "$(INTDIR)"

"$(INTDIR)\ChTNT.sbr" : $(SOURCE) $(DEP_CPP_CHTNT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Debug"

DEP_CPP_CHTNT=\
	".\ChSpeechPrefs.h"\
	".\ChSpeechStatus.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHTNT=\
	".\vwrres.h"\
	

"$(INTDIR)\ChTNT.obj" : $(SOURCE) $(DEP_CPP_CHTNT) "$(INTDIR)"

"$(INTDIR)\ChTNT.sbr" : $(SOURCE) $(DEP_CPP_CHTNT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ChSound - Win32 TNT Release"

DEP_CPP_CHTNT=\
	".\ChSpeechPrefs.h"\
	".\ChSpeechStatus.h"\
	".\ChTNT.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\tnt.h"\
	
NODEP_CPP_CHTNT=\
	".\vwrres.h"\
	

"$(INTDIR)\ChTNT.obj" : $(SOURCE) $(DEP_CPP_CHTNT) "$(INTDIR)"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
