# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (x86) Static Library" 0x0104

!IF "$(CFG)" == ""
CFG=TinTin - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to TinTin - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "ChWorld - Win32 Release" && "$(CFG)" !=\
 "ChWorld - Win32 Debug" && "$(CFG)" != "TinTin - Win32 Release" && "$(CFG)" !=\
 "TinTin - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "ChWorld40.mak" CFG="TinTin - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ChWorld - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ChWorld - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TinTin - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "TinTin - Win32 Debug" (based on "Win32 (x86) Static Library")
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
# PROP Target_Last_Scanned "ChWorld - Win32 Debug"

!IF  "$(CFG)" == "ChWorld - Win32 Release"

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

ALL : "TinTin - Win32 Release" "$(OUTDIR)\ChWorld.dll"

CLEAN : 
	-@erase "$(INTDIR)\ChAbout.obj"
	-@erase "$(INTDIR)\ChConnectDlg.obj"
	-@erase "$(INTDIR)\ChHist.obj"
	-@erase "$(INTDIR)\ChKeyMapType.obj"
	-@erase "$(INTDIR)\ChPrefsNotify.obj"
	-@erase "$(INTDIR)\ChPrefsWorld.obj"
	-@erase "$(INTDIR)\ChQuickConnect.obj"
	-@erase "$(INTDIR)\ChSaveAs.obj"
	-@erase "$(INTDIR)\ChSCWiz.obj"
	-@erase "$(INTDIR)\ChTextInput.obj"
	-@erase "$(INTDIR)\ChTextOutput.obj"
	-@erase "$(INTDIR)\ChWConn.obj"
	-@erase "$(INTDIR)\ChWInfo.obj"
	-@erase "$(INTDIR)\ChWList.obj"
	-@erase "$(INTDIR)\ChWListD.obj"
	-@erase "$(INTDIR)\ChWorld.obj"
	-@erase "$(INTDIR)\ChWorld.res"
	-@erase "$(INTDIR)\ChWorldCmdLine.obj"
	-@erase "$(INTDIR)\ChWorldStream.obj"
	-@erase "$(INTDIR)\Dll.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\ChWorld.dll"
	-@erase "$(OUTDIR)\ChWorld.exp"
	-@erase "$(OUTDIR)\ChWorld.ilk"
	-@erase "$(OUTDIR)\ChWorld.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /YX /c
# ADD CPP /nologo /G5 /MD /W3 /Gm /GX /Zi /Og /Oi /Os /Oy /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /YX"headers.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /G5 /MD /W3 /Gm /GX /Zi /Og /Oi /Os /Oy /D "NDEBUG" /D "WIN32"\
 /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/ChWorld40.pch" /YX"headers.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\release/
CPP_SBRS=.\.

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

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/ChWorld.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/ChWorld40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 winmm.lib Pueblo32.lib /nologo /base:0x20000000 /subsystem:windows /dll /incremental:yes /machine:I386 /out:"\chaco\bin\Release\modules/ChWorld.dll"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=winmm.lib Pueblo32.lib /nologo /base:0x20000000 /subsystem:windows\
 /dll /incremental:yes /pdb:"$(OUTDIR)/ChWorld.pdb" /machine:I386\
 /def:".\ChWorld.def" /out:"$(OUTDIR)/ChWorld.dll"\
 /implib:"$(OUTDIR)/ChWorld.lib" 
DEF_FILE= \
	".\ChWorld.def"
LINK32_OBJS= \
	"$(INTDIR)\ChAbout.obj" \
	"$(INTDIR)\ChConnectDlg.obj" \
	"$(INTDIR)\ChHist.obj" \
	"$(INTDIR)\ChKeyMapType.obj" \
	"$(INTDIR)\ChPrefsNotify.obj" \
	"$(INTDIR)\ChPrefsWorld.obj" \
	"$(INTDIR)\ChQuickConnect.obj" \
	"$(INTDIR)\ChSaveAs.obj" \
	"$(INTDIR)\ChSCWiz.obj" \
	"$(INTDIR)\ChTextInput.obj" \
	"$(INTDIR)\ChTextOutput.obj" \
	"$(INTDIR)\ChWConn.obj" \
	"$(INTDIR)\ChWInfo.obj" \
	"$(INTDIR)\ChWList.obj" \
	"$(INTDIR)\ChWListD.obj" \
	"$(INTDIR)\ChWorld.obj" \
	"$(INTDIR)\ChWorld.res" \
	"$(INTDIR)\ChWorldCmdLine.obj" \
	"$(INTDIR)\ChWorldStream.obj" \
	"$(INTDIR)\Dll.obj" \
	".\TinTin\Release\TinTin.lib"

"$(OUTDIR)\ChWorld.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ChWorld - Win32 Debug"

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

ALL : "TinTin - Win32 Debug" "$(OUTDIR)\ChWorld.dll"

CLEAN : 
	-@erase "$(INTDIR)\ChAbout.obj"
	-@erase "$(INTDIR)\ChConnectDlg.obj"
	-@erase "$(INTDIR)\ChHist.obj"
	-@erase "$(INTDIR)\ChKeyMapType.obj"
	-@erase "$(INTDIR)\ChPrefsNotify.obj"
	-@erase "$(INTDIR)\ChPrefsWorld.obj"
	-@erase "$(INTDIR)\ChQuickConnect.obj"
	-@erase "$(INTDIR)\ChSaveAs.obj"
	-@erase "$(INTDIR)\ChSCWiz.obj"
	-@erase "$(INTDIR)\ChTextInput.obj"
	-@erase "$(INTDIR)\ChTextOutput.obj"
	-@erase "$(INTDIR)\ChWConn.obj"
	-@erase "$(INTDIR)\ChWInfo.obj"
	-@erase "$(INTDIR)\ChWList.obj"
	-@erase "$(INTDIR)\ChWListD.obj"
	-@erase "$(INTDIR)\ChWorld.obj"
	-@erase "$(INTDIR)\ChWorld.res"
	-@erase "$(INTDIR)\ChWorldCmdLine.obj"
	-@erase "$(INTDIR)\ChWorldStream.obj"
	-@erase "$(INTDIR)\Dll.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\ChWorld.dll"
	-@erase "$(OUTDIR)\ChWorld.exp"
	-@erase "$(OUTDIR)\ChWorld.ilk"
	-@erase "$(OUTDIR)\ChWorld.lib"
	-@erase "$(OUTDIR)\ChWorld.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX /c
# ADD CPP /nologo /G5 /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /YX"headers.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /G5 /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/ChWorld40.pch" /YX"headers.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\debug/
CPP_SBRS=.\.

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

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/ChWorld.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/ChWorld40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 winmm.lib Pueblo32.lib /nologo /base:0x20000000 /subsystem:windows /dll /debug /machine:I386 /out:"\chaco\bin\debug\modules/ChWorld.dll" /implib:"/chaco/bin/debug/modules/ChWorld.lib"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=winmm.lib Pueblo32.lib /nologo /base:0x20000000 /subsystem:windows\
 /dll /incremental:yes /pdb:"$(OUTDIR)/ChWorld.pdb" /debug /machine:I386\
 /def:".\ChWorld.def" /out:"$(OUTDIR)/ChWorld.dll"\
 /implib:"$(OUTDIR)/ChWorld.lib" /implib:"/chaco/bin/debug/modules/ChWorld.lib" 
DEF_FILE= \
	".\ChWorld.def"
LINK32_OBJS= \
	"$(INTDIR)\ChAbout.obj" \
	"$(INTDIR)\ChConnectDlg.obj" \
	"$(INTDIR)\ChHist.obj" \
	"$(INTDIR)\ChKeyMapType.obj" \
	"$(INTDIR)\ChPrefsNotify.obj" \
	"$(INTDIR)\ChPrefsWorld.obj" \
	"$(INTDIR)\ChQuickConnect.obj" \
	"$(INTDIR)\ChSaveAs.obj" \
	"$(INTDIR)\ChSCWiz.obj" \
	"$(INTDIR)\ChTextInput.obj" \
	"$(INTDIR)\ChTextOutput.obj" \
	"$(INTDIR)\ChWConn.obj" \
	"$(INTDIR)\ChWInfo.obj" \
	"$(INTDIR)\ChWList.obj" \
	"$(INTDIR)\ChWListD.obj" \
	"$(INTDIR)\ChWorld.obj" \
	"$(INTDIR)\ChWorld.res" \
	"$(INTDIR)\ChWorldCmdLine.obj" \
	"$(INTDIR)\ChWorldStream.obj" \
	"$(INTDIR)\Dll.obj" \
	".\TinTin\Debug\TinTin.lib"

"$(OUTDIR)\ChWorld.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "TinTin - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "TinTin\Release"
# PROP BASE Intermediate_Dir "TinTin\Release"
# PROP BASE Target_Dir "TinTin"
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "TinTin\Release"
# PROP Intermediate_Dir "TinTin\Release"
# PROP Target_Dir "TinTin"
OUTDIR=.\TinTin\Release
INTDIR=.\TinTin\Release

ALL : "$(OUTDIR)\TinTin.lib"

CLEAN : 
	-@erase "$(INTDIR)\TinTinAction.obj"
	-@erase "$(INTDIR)\TinTinAlias.obj"
	-@erase "$(INTDIR)\TinTinFiles.obj"
	-@erase "$(INTDIR)\TinTinIf.obj"
	-@erase "$(INTDIR)\TinTinInfo.obj"
	-@erase "$(INTDIR)\TinTinList.obj"
	-@erase "$(INTDIR)\TinTinMain.obj"
	-@erase "$(INTDIR)\TinTinMisc.obj"
	-@erase "$(INTDIR)\TinTinParse.obj"
	-@erase "$(INTDIR)\TinTinPath.obj"
	-@erase "$(INTDIR)\TinTinSession.obj"
	-@erase "$(INTDIR)\TinTinSettings.obj"
	-@erase "$(INTDIR)\TinTinSubs.obj"
	-@erase "$(INTDIR)\TinTinTicks.obj"
	-@erase "$(INTDIR)\TinTinUtils.obj"
	-@erase "$(INTDIR)\TinTinVars.obj"
	-@erase "$(OUTDIR)\TinTin.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /YX /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS"\
 /Fp"$(INTDIR)/TinTin.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\TinTin\Release/
CPP_SBRS=.\.

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

BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/TinTin.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/TinTin.lib" 
LIB32_OBJS= \
	"$(INTDIR)\TinTinAction.obj" \
	"$(INTDIR)\TinTinAlias.obj" \
	"$(INTDIR)\TinTinFiles.obj" \
	"$(INTDIR)\TinTinIf.obj" \
	"$(INTDIR)\TinTinInfo.obj" \
	"$(INTDIR)\TinTinList.obj" \
	"$(INTDIR)\TinTinMain.obj" \
	"$(INTDIR)\TinTinMisc.obj" \
	"$(INTDIR)\TinTinParse.obj" \
	"$(INTDIR)\TinTinPath.obj" \
	"$(INTDIR)\TinTinSession.obj" \
	"$(INTDIR)\TinTinSettings.obj" \
	"$(INTDIR)\TinTinSubs.obj" \
	"$(INTDIR)\TinTinTicks.obj" \
	"$(INTDIR)\TinTinUtils.obj" \
	"$(INTDIR)\TinTinVars.obj"

"$(OUTDIR)\TinTin.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "TinTin - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "TinTin\Debug"
# PROP BASE Intermediate_Dir "TinTin\Debug"
# PROP BASE Target_Dir "TinTin"
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "TinTin\Debug"
# PROP Intermediate_Dir "TinTin\Debug"
# PROP Target_Dir "TinTin"
OUTDIR=.\TinTin\Debug
INTDIR=.\TinTin\Debug

ALL : "$(OUTDIR)\TinTin.lib"

CLEAN : 
	-@erase "$(INTDIR)\TinTinAction.obj"
	-@erase "$(INTDIR)\TinTinAlias.obj"
	-@erase "$(INTDIR)\TinTinFiles.obj"
	-@erase "$(INTDIR)\TinTinIf.obj"
	-@erase "$(INTDIR)\TinTinInfo.obj"
	-@erase "$(INTDIR)\TinTinList.obj"
	-@erase "$(INTDIR)\TinTinMain.obj"
	-@erase "$(INTDIR)\TinTinMisc.obj"
	-@erase "$(INTDIR)\TinTinParse.obj"
	-@erase "$(INTDIR)\TinTinPath.obj"
	-@erase "$(INTDIR)\TinTinSession.obj"
	-@erase "$(INTDIR)\TinTinSettings.obj"
	-@erase "$(INTDIR)\TinTinSubs.obj"
	-@erase "$(INTDIR)\TinTinTicks.obj"
	-@erase "$(INTDIR)\TinTinUtils.obj"
	-@erase "$(INTDIR)\TinTinVars.obj"
	-@erase "$(OUTDIR)\TinTin.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MDd /W3 /GX /Z7 /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS" /YX /c
CPP_PROJ=/nologo /MDd /W3 /GX /Z7 /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_AFXDLL" /D "_MBCS"\
 /Fp"$(INTDIR)/TinTin.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\TinTin\Debug/
CPP_SBRS=.\.

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

BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/TinTin.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/TinTin.lib" 
LIB32_OBJS= \
	"$(INTDIR)\TinTinAction.obj" \
	"$(INTDIR)\TinTinAlias.obj" \
	"$(INTDIR)\TinTinFiles.obj" \
	"$(INTDIR)\TinTinIf.obj" \
	"$(INTDIR)\TinTinInfo.obj" \
	"$(INTDIR)\TinTinList.obj" \
	"$(INTDIR)\TinTinMain.obj" \
	"$(INTDIR)\TinTinMisc.obj" \
	"$(INTDIR)\TinTinParse.obj" \
	"$(INTDIR)\TinTinPath.obj" \
	"$(INTDIR)\TinTinSession.obj" \
	"$(INTDIR)\TinTinSettings.obj" \
	"$(INTDIR)\TinTinSubs.obj" \
	"$(INTDIR)\TinTinTicks.obj" \
	"$(INTDIR)\TinTinUtils.obj" \
	"$(INTDIR)\TinTinVars.obj"

"$(OUTDIR)\TinTin.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 

################################################################################
# Begin Target

# Name "ChWorld - Win32 Release"
# Name "ChWorld - Win32 Debug"

!IF  "$(CFG)" == "ChWorld - Win32 Release"

!ELSEIF  "$(CFG)" == "ChWorld - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\Dll.cpp
DEP_CPP_DLL_C=\
	".\ChWInfo.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\Dll.obj" : $(SOURCE) $(DEP_CPP_DLL_C) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWInfo.cpp
DEP_CPP_CHWIN=\
	".\ChSCWiz.h"\
	".\ChWInfo.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWizard.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_CHWIN=\
	".\vwrres.h"\
	

"$(INTDIR)\ChWInfo.obj" : $(SOURCE) $(DEP_CPP_CHWIN) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWListD.cpp
DEP_CPP_CHWLI=\
	".\ChWInfo.h"\
	".\ChWList.h"\
	".\ChWListD.h"\
	".\headers.h"\
	".\templcls\ChMdPLst.h"\
	".\templcls\ChMdPLst.inl"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChDlg.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_CHWLI=\
	".\vwrres.h"\
	

"$(INTDIR)\ChWListD.obj" : $(SOURCE) $(DEP_CPP_CHWLI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWList.cpp
DEP_CPP_CHWLIS=\
	".\ChWInfo.h"\
	".\ChWList.h"\
	".\headers.h"\
	".\templcls\ChMdPLst.h"\
	".\templcls\ChMdPLst.inl"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChWList.obj" : $(SOURCE) $(DEP_CPP_CHWLIS) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWConn.cpp
DEP_CPP_CHWCO=\
	".\ChTextOutput.h"\
	".\ChWConn.h"\
	".\ChWInfo.h"\
	".\ChWorldCmdLine.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
	".\World.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConn.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSound.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\protocol.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\templcls\ChSockBf.h"\
	
NODEP_CPP_CHWCO=\
	".\vwrres.h"\
	

"$(INTDIR)\ChWConn.obj" : $(SOURCE) $(DEP_CPP_CHWCO) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWorld.rc
DEP_RSC_CHWOR=\
	".\res\chaco.ico"\
	".\res\planet.ico"\
	".\res\wheel.ico"\
	

"$(INTDIR)\ChWorld.res" : $(SOURCE) $(DEP_RSC_CHWOR) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWorld.cpp
DEP_CPP_CHWORL=\
	"..\..\unix\ChWorld\UnixRes.h"\
	".\ChAbout.h"\
	".\ChConnectDlg.h"\
	".\ChHist.h"\
	".\ChKeyMapType.h"\
	".\ChPrefsNotify.h"\
	".\ChPrefsWorld.h"\
	".\ChQuickConnect.h"\
	".\ChTextInput.h"\
	".\ChTextOutput.h"\
	".\ChWConn.h"\
	".\ChWInfo.h"\
	".\ChWList.h"\
	".\ChWListD.h"\
	".\ChWorldCmdLine.h"\
	".\ChWorldStream.h"\
	".\headers.h"\
	".\templcls\ChMdPLst.h"\
	".\templcls\ChMdPLst.inl"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
	".\World.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChArgList.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConn.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChDlg.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChGraphx.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHttpStream.h"\
	{$(INCLUDE)}"\ChKeyMap.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChMenu.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChPuebloScript.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSound.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\protocol.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\templcls\ChMnPtrl.h"\
	{$(INCLUDE)}"\templcls\ChMnPtrl.inl"\
	{$(INCLUDE)}"\templcls\ChSockBf.h"\
	{$(INCLUDE)}"\templcls\ChStrLst.h"\
	{$(INCLUDE)}"\templcls\ChStrLst.inl"\
	
NODEP_CPP_CHWORL=\
	".\vwrres.h"\
	

"$(INTDIR)\ChWorld.obj" : $(SOURCE) $(DEP_CPP_CHWORL) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWorld.def

!IF  "$(CFG)" == "ChWorld - Win32 Release"

!ELSEIF  "$(CFG)" == "ChWorld - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSCWiz.cpp
DEP_CPP_CHSCW=\
	".\ChSCWiz.h"\
	".\ChWInfo.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWizard.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_CHSCW=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSCWiz.obj" : $(SOURCE) $(DEP_CPP_CHSCW) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSaveAs.cpp
DEP_CPP_CHSAV=\
	".\ChSaveAs.h"\
	".\ChWInfo.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_CHSAV=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSaveAs.obj" : $(SOURCE) $(DEP_CPP_CHSAV) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHist.cpp
DEP_CPP_CHHIS=\
	".\ChHist.h"\
	".\ChWInfo.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\templcls\ChStrLst.h"\
	{$(INCLUDE)}"\templcls\ChStrLst.inl"\
	

"$(INTDIR)\ChHist.obj" : $(SOURCE) $(DEP_CPP_CHHIS) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChKeyMapType.cpp
DEP_CPP_CHKEY=\
	".\ChKeyMapType.h"\
	".\ChWInfo.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChKeyMap.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChKeyMapType.obj" : $(SOURCE) $(DEP_CPP_CHKEY) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTextInput.cpp
DEP_CPP_CHTEX=\
	".\ChHist.h"\
	".\ChKeyMapType.h"\
	".\ChTextInput.h"\
	".\ChTextOutput.h"\
	".\ChWInfo.h"\
	".\ChWorldCmdLine.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
	".\World.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConn.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChKeyMap.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChSplit.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\protocol.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\templcls\ChSockBf.h"\
	{$(INCLUDE)}"\templcls\ChStrLst.h"\
	{$(INCLUDE)}"\templcls\ChStrLst.inl"\
	

"$(INTDIR)\ChTextInput.obj" : $(SOURCE) $(DEP_CPP_CHTEX) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrefsNotify.cpp
DEP_CPP_CHPRE=\
	".\ChPrefsNotify.h"\
	".\ChWInfo.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_CHPRE=\
	".\vwrres.h"\
	

"$(INTDIR)\ChPrefsNotify.obj" : $(SOURCE) $(DEP_CPP_CHPRE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrefsWorld.cpp
DEP_CPP_CHPREF=\
	".\ChKeyMapType.h"\
	".\ChPrefsWorld.h"\
	".\ChWInfo.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChKeyMap.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_CHPREF=\
	".\vwrres.h"\
	

"$(INTDIR)\ChPrefsWorld.obj" : $(SOURCE) $(DEP_CPP_CHPREF) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTextOutput.cpp
DEP_CPP_CHTEXT=\
	".\ChHist.h"\
	".\ChKeyMapType.h"\
	".\ChSaveAs.h"\
	".\ChTextInput.h"\
	".\ChTextOutput.h"\
	".\ChWInfo.h"\
	".\ChWorldCmdLine.h"\
	".\ChWorldStream.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
	".\World.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChArgList.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConn.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHttpStream.h"\
	{$(INCLUDE)}"\ChKeyMap.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChPuebloScript.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChSplit.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\protocol.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\templcls\ChSockBf.h"\
	{$(INCLUDE)}"\templcls\ChStrLst.h"\
	{$(INCLUDE)}"\templcls\ChStrLst.inl"\
	
NODEP_CPP_CHTEXT=\
	".\vwrres.h"\
	

"$(INTDIR)\ChTextOutput.obj" : $(SOURCE) $(DEP_CPP_CHTEXT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWorldStream.cpp
DEP_CPP_CHWORLD=\
	".\ChWInfo.h"\
	".\ChWorldCmdLine.h"\
	".\ChWorldStream.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
	".\World.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChArgList.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConn.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHttpStream.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChPuebloScript.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\protocol.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\templcls\ChSockBf.h"\
	
NODEP_CPP_CHWORLD=\
	".\vwrres.h"\
	

"$(INTDIR)\ChWorldStream.obj" : $(SOURCE) $(DEP_CPP_CHWORLD) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAbout.cpp
DEP_CPP_CHABO=\
	".\ChAbout.h"\
	".\ChWInfo.h"\
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
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_CHABO=\
	".\vwrres.h"\
	

"$(INTDIR)\ChAbout.obj" : $(SOURCE) $(DEP_CPP_CHABO) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWorldCmdLine.cpp
DEP_CPP_CHWORLDC=\
	".\ChWInfo.h"\
	".\ChWorldCmdLine.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChArgList.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChWorldCmdLine.obj" : $(SOURCE) $(DEP_CPP_CHWORLDC) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChQuickConnect.cpp
DEP_CPP_CHQUI=\
	".\ChQuickConnect.h"\
	".\ChWInfo.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChDlg.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_CHQUI=\
	".\vwrres.h"\
	

"$(INTDIR)\ChQuickConnect.obj" : $(SOURCE) $(DEP_CPP_CHQUI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChConnectDlg.cpp
DEP_CPP_CHCON=\
	".\ChConnectDlg.h"\
	".\ChWInfo.h"\
	".\ChWorldCmdLine.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
	".\World.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConn.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChDlg.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\protocol.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\templcls\ChSockBf.h"\
	
NODEP_CPP_CHCON=\
	".\vwrres.h"\
	

"$(INTDIR)\ChConnectDlg.obj" : $(SOURCE) $(DEP_CPP_CHCON) "$(INTDIR)"


# End Source File
################################################################################
# Begin Project Dependency

# Project_Dep_Name "TinTin"

!IF  "$(CFG)" == "ChWorld - Win32 Release"

"TinTin - Win32 Release" : 
   $(MAKE) /$(MAKEFLAGS) /F ".\ChWorld40.mak" CFG="TinTin - Win32 Release" 

!ELSEIF  "$(CFG)" == "ChWorld - Win32 Debug"

"TinTin - Win32 Debug" : 
   $(MAKE) /$(MAKEFLAGS) /F ".\ChWorld40.mak" CFG="TinTin - Win32 Debug" 

!ENDIF 

# End Project Dependency
# End Target
################################################################################
# Begin Target

# Name "TinTin - Win32 Release"
# Name "TinTin - Win32 Debug"

!IF  "$(CFG)" == "TinTin - Win32 Release"

!ELSEIF  "$(CFG)" == "TinTin - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\TinTinAction.cpp
DEP_CPP_TINTI=\
	".\ChWInfo.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_TINTI=\
	".\vwrres.h"\
	

"$(INTDIR)\TinTinAction.obj" : $(SOURCE) $(DEP_CPP_TINTI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinAlias.cpp
DEP_CPP_TINTIN=\
	".\ChWInfo.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_TINTIN=\
	".\vwrres.h"\
	

"$(INTDIR)\TinTinAlias.obj" : $(SOURCE) $(DEP_CPP_TINTIN) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinFiles.cpp
DEP_CPP_TINTINF=\
	".\ChWInfo.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_TINTINF=\
	".\vwrres.h"\
	

"$(INTDIR)\TinTinFiles.obj" : $(SOURCE) $(DEP_CPP_TINTINF) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinIf.cpp
DEP_CPP_TINTINI=\
	".\ChWInfo.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_TINTINI=\
	".\vwrres.h"\
	

"$(INTDIR)\TinTinIf.obj" : $(SOURCE) $(DEP_CPP_TINTINI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinInfo.cpp
DEP_CPP_TINTININ=\
	".\ChWInfo.h"\
	".\headers.h"\
	".\TinTinInfo.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChDlg.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_TINTININ=\
	".\vwrres.h"\
	

"$(INTDIR)\TinTinInfo.obj" : $(SOURCE) $(DEP_CPP_TINTININ) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinList.cpp
DEP_CPP_TINTINL=\
	".\ChWInfo.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\TinTinList.obj" : $(SOURCE) $(DEP_CPP_TINTINL) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinMain.cpp
DEP_CPP_TINTINM=\
	".\ChWInfo.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\TinTinMain.obj" : $(SOURCE) $(DEP_CPP_TINTINM) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinMisc.cpp
DEP_CPP_TINTINMI=\
	".\ChHist.h"\
	".\ChKeyMapType.h"\
	".\ChTextInput.h"\
	".\ChTextOutput.h"\
	".\ChWInfo.h"\
	".\ChWorldCmdLine.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinInfo.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
	".\World.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConn.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChDlg.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChKeyMap.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\protocol.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\templcls\ChSockBf.h"\
	{$(INCLUDE)}"\templcls\ChStrLst.h"\
	{$(INCLUDE)}"\templcls\ChStrLst.inl"\
	
NODEP_CPP_TINTINMI=\
	".\vwrres.h"\
	

"$(INTDIR)\TinTinMisc.obj" : $(SOURCE) $(DEP_CPP_TINTINMI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinParse.cpp
DEP_CPP_TINTINP=\
	".\ChWInfo.h"\
	".\ChWorldCmdLine.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
	".\World.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConn.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\protocol.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\templcls\ChSockBf.h"\
	
NODEP_CPP_TINTINP=\
	".\vwrres.h"\
	

"$(INTDIR)\TinTinParse.obj" : $(SOURCE) $(DEP_CPP_TINTINP) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinPath.cpp
DEP_CPP_TINTINPA=\
	".\ChHist.h"\
	".\ChKeyMapType.h"\
	".\ChTextInput.h"\
	".\ChTextOutput.h"\
	".\ChWInfo.h"\
	".\ChWorldCmdLine.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinInfo.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
	".\World.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConn.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChDlg.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChKeyMap.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\protocol.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\templcls\ChSockBf.h"\
	{$(INCLUDE)}"\templcls\ChStrLst.h"\
	{$(INCLUDE)}"\templcls\ChStrLst.inl"\
	
NODEP_CPP_TINTINPA=\
	".\vwrres.h"\
	

"$(INTDIR)\TinTinPath.obj" : $(SOURCE) $(DEP_CPP_TINTINPA) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinSession.cpp
DEP_CPP_TINTINS=\
	".\ChWInfo.h"\
	".\ChWorldCmdLine.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
	".\World.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConn.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\protocol.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\templcls\ChSockBf.h"\
	
NODEP_CPP_TINTINS=\
	".\vwrres.h"\
	

"$(INTDIR)\TinTinSession.obj" : $(SOURCE) $(DEP_CPP_TINTINS) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinSettings.cpp
DEP_CPP_TINTINSE=\
	".\ChWInfo.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\TinTinSettings.obj" : $(SOURCE) $(DEP_CPP_TINTINSE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinSubs.cpp
DEP_CPP_TINTINSU=\
	".\ChWInfo.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_TINTINSU=\
	".\vwrres.h"\
	

"$(INTDIR)\TinTinSubs.obj" : $(SOURCE) $(DEP_CPP_TINTINSU) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinTicks.cpp
DEP_CPP_TINTINT=\
	".\ChWInfo.h"\
	".\ChWorldCmdLine.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
	".\World.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConn.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\protocol.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	{$(INCLUDE)}"\templcls\ChSockBf.h"\
	
NODEP_CPP_TINTINT=\
	".\vwrres.h"\
	

"$(INTDIR)\TinTinTicks.obj" : $(SOURCE) $(DEP_CPP_TINTINT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinUtils.cpp
DEP_CPP_TINTINU=\
	".\ChWInfo.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\TinTinUtils.obj" : $(SOURCE) $(DEP_CPP_TINTINU) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TinTinVars.cpp
DEP_CPP_TINTINV=\
	".\ChWInfo.h"\
	".\headers.h"\
	".\TinTin.h"\
	".\TinTinList.h"\
	".\TinTinSettings.h"\
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
	{$(INCLUDE)}"\ChWorld.h"\
	{$(INCLUDE)}"\ChWType.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_TINTINV=\
	".\vwrres.h"\
	

"$(INTDIR)\TinTinVars.obj" : $(SOURCE) $(DEP_CPP_TINTINV) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
