# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=WTracker - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to WTracker - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "WTracker - Win32 Debug" && "$(CFG)" !=\
 "WTracker - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "WTracker40.mak" CFG="WTracker - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WTracker - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "WTracker - Win32 Release" (based on\
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
RSC=rc.exe
MTL=mktyplib.exe
CPP=cl.exe

!IF  "$(CFG)" == "WTracker - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WinDebug"
# PROP Intermediate_Dir "WinDebug"
OUTDIR=.\WinDebug
INTDIR=.\WinDebug

ALL : "..\..\..\..\bin\debug\WTracker.dll"

CLEAN : 
	-@erase "$(INTDIR)\ChAbout.obj"
	-@erase "$(INTDIR)\ChBasDoc.obj"
	-@erase "$(INTDIR)\ChBaseVw.obj"
	-@erase "$(INTDIR)\ChHtmDsp.obj"
	-@erase "$(INTDIR)\ChLocBar.obj"
	-@erase "$(INTDIR)\ChMFrame.obj"
	-@erase "$(INTDIR)\ChPrefs.obj"
	-@erase "$(INTDIR)\ChPrFont.obj"
	-@erase "$(INTDIR)\ChPrNet.obj"
	-@erase "$(INTDIR)\ChUtils.obj"
	-@erase "$(INTDIR)\ChWebTracker.obj"
	-@erase "$(INTDIR)\OpenLoc.obj"
	-@erase "$(INTDIR)\StdAFX.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\WTracker.obj"
	-@erase "$(INTDIR)\WTracker.res"
	-@erase "$(INTDIR)\WTracker40.pch"
	-@erase "$(OUTDIR)\WTracker.exp"
	-@erase "$(OUTDIR)\WTracker.lib"
	-@erase "$(OUTDIR)\WTracker.pdb"
	-@erase "..\..\..\..\bin\debug\WTracker.dll"
	-@erase "..\..\..\..\bin\debug\WTracker.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fp"$(INTDIR)/WTracker40.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\WinDebug/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo"$(INTDIR)/WTracker.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/WTracker40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /def:"WTracker.def" /implib:"WTracker.lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 \chaco\lib\PbUtil32.lib \chaco\lib\Pueblo32.lib /nologo /base:0x2a000000 /subsystem:windows /dll /debug /machine:I386 /def:"WTracker.def" /out:"\chaco\bin\debug/WTracker.dll" /OUT:"/chaco/bin/debug/WTracker.dll" /PDB:"/chaco/bin/debug/WTracker.pdb" /OUT:"/chaco/bin/debug/WTracker.dll" /PDB:"/chaco/bin/debug/WTracker.pdb" /OUT:"/chaco/bin/debug/WTracker.dll" /IMPLIB:"/chaco/lib/WTracker.lib"
LINK32_FLAGS=\chaco\lib\PbUtil32.lib \chaco\lib\Pueblo32.lib /nologo\
 /base:0x2a000000 /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)/WTracker.pdb" /debug /machine:I386 /def:"WTracker.def"\
 /out:"\chaco\bin\debug/WTracker.dll" /implib:"$(OUTDIR)/WTracker.lib"\
 /OUT:"/chaco/bin/debug/WTracker.dll" /PDB:"/chaco/bin/debug/WTracker.pdb"\
 /OUT:"/chaco/bin/debug/WTracker.dll" /PDB:"/chaco/bin/debug/WTracker.pdb"\
 /OUT:"/chaco/bin/debug/WTracker.dll" /IMPLIB:"/chaco/lib/WTracker.lib" 
LINK32_OBJS= \
	"$(INTDIR)\ChAbout.obj" \
	"$(INTDIR)\ChBasDoc.obj" \
	"$(INTDIR)\ChBaseVw.obj" \
	"$(INTDIR)\ChHtmDsp.obj" \
	"$(INTDIR)\ChLocBar.obj" \
	"$(INTDIR)\ChMFrame.obj" \
	"$(INTDIR)\ChPrefs.obj" \
	"$(INTDIR)\ChPrFont.obj" \
	"$(INTDIR)\ChPrNet.obj" \
	"$(INTDIR)\ChUtils.obj" \
	"$(INTDIR)\ChWebTracker.obj" \
	"$(INTDIR)\OpenLoc.obj" \
	"$(INTDIR)\StdAFX.obj" \
	"$(INTDIR)\WTracker.obj" \
	"$(INTDIR)\WTracker.res"

"..\..\..\..\bin\debug\WTracker.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "WTracker - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
OUTDIR=.\WinRel
INTDIR=.\WinRel

ALL : "..\..\..\..\bin\release\WTracker.dll"

CLEAN : 
	-@erase "$(INTDIR)\ChAbout.obj"
	-@erase "$(INTDIR)\ChBasDoc.obj"
	-@erase "$(INTDIR)\ChBaseVw.obj"
	-@erase "$(INTDIR)\ChHtmDsp.obj"
	-@erase "$(INTDIR)\ChLocBar.obj"
	-@erase "$(INTDIR)\ChMFrame.obj"
	-@erase "$(INTDIR)\ChPrefs.obj"
	-@erase "$(INTDIR)\ChPrFont.obj"
	-@erase "$(INTDIR)\ChPrNet.obj"
	-@erase "$(INTDIR)\ChUtils.obj"
	-@erase "$(INTDIR)\ChWebTracker.obj"
	-@erase "$(INTDIR)\OpenLoc.obj"
	-@erase "$(INTDIR)\StdAFX.obj"
	-@erase "$(INTDIR)\WTracker.obj"
	-@erase "$(INTDIR)\WTracker.res"
	-@erase "$(INTDIR)\WTracker40.pch"
	-@erase "$(OUTDIR)\WTracker.exp"
	-@erase "$(OUTDIR)\WTracker.lib"
	-@erase "..\..\..\..\bin\release\WTracker.dll"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS"\
 /Fp"$(INTDIR)/WTracker40.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\WinRel/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x0 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo"$(INTDIR)/WTracker.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/WTracker40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386 /def:"WTracker.def" /implib:"WTracker.lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 \chaco\lib\PbUtil32.lib \chaco\lib\Pueblo32.lib /nologo /subsystem:windows /dll /machine:I386 /def:"WTracker.def" /out:"\chaco\bin\release/WTracker.dll" /PDB:"/chaco/bin/release/WTracker.pdb" /OUT:"/chaco/bin/release/WTracker.dll" /OUT:"/chaco/bin/release/WTracker.dll" /IMPLIB:"/chaco/lib/WTracker.lib"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=\chaco\lib\PbUtil32.lib \chaco\lib\Pueblo32.lib /nologo\
 /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)/WTracker.pdb"\
 /machine:I386 /def:"WTracker.def" /out:"\chaco\bin\release/WTracker.dll"\
 /implib:"$(OUTDIR)/WTracker.lib" /PDB:"/chaco/bin/release/WTracker.pdb"\
 /OUT:"/chaco/bin/release/WTracker.dll" /OUT:"/chaco/bin/release/WTracker.dll"\
 /IMPLIB:"/chaco/lib/WTracker.lib" 
LINK32_OBJS= \
	"$(INTDIR)\ChAbout.obj" \
	"$(INTDIR)\ChBasDoc.obj" \
	"$(INTDIR)\ChBaseVw.obj" \
	"$(INTDIR)\ChHtmDsp.obj" \
	"$(INTDIR)\ChLocBar.obj" \
	"$(INTDIR)\ChMFrame.obj" \
	"$(INTDIR)\ChPrefs.obj" \
	"$(INTDIR)\ChPrFont.obj" \
	"$(INTDIR)\ChPrNet.obj" \
	"$(INTDIR)\ChUtils.obj" \
	"$(INTDIR)\ChWebTracker.obj" \
	"$(INTDIR)\OpenLoc.obj" \
	"$(INTDIR)\StdAFX.obj" \
	"$(INTDIR)\WTracker.obj" \
	"$(INTDIR)\WTracker.res"

"..\..\..\..\bin\release\WTracker.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "WTracker - Win32 Debug"
# Name "WTracker - Win32 Release"

!IF  "$(CFG)" == "WTracker - Win32 Debug"

!ELSEIF  "$(CFG)" == "WTracker - Win32 Release"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\StdAFX.cpp
DEP_CPP_STDAF=\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

!IF  "$(CFG)" == "WTracker - Win32 Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fp"$(INTDIR)/WTracker40.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAFX.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\WTracker40.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "WTracker - Win32 Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS"\
 /Fp"$(INTDIR)/WTracker40.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAFX.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\WTracker40.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\WTracker.cpp
DEP_CPP_WTRAC=\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\WTracker.obj" : $(SOURCE) $(DEP_CPP_WTRAC) "$(INTDIR)"\
 "$(INTDIR)\WTracker40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\WTracker.rc
DEP_RSC_WTRACK=\
	".\res\idr_main.ico"\
	".\res\toolbar.bmp"\
	".\res\WTracker.rc2"\
	

"$(INTDIR)\WTracker.res" : $(SOURCE) $(DEP_RSC_WTRACK) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\readme.txt

!IF  "$(CFG)" == "WTracker - Win32 Debug"

!ELSEIF  "$(CFG)" == "WTracker - Win32 Release"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMFrame.cpp
DEP_CPP_CHMFR=\
	".\ChAbout.h"\
	".\ChBaseVw.h"\
	".\ChHtmDsp.h"\
	".\ChLocBar.h"\
	".\ChMFrame.h"\
	".\ChPrefs.h"\
	".\ChPrFont.h"\
	".\ChPrNet.h"\
	".\OpenLoc.h"\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChImgUtil.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChMFrame.obj" : $(SOURCE) $(DEP_CPP_CHMFR) "$(INTDIR)"\
 "$(INTDIR)\WTracker40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmDsp.cpp
DEP_CPP_CHHTM=\
	".\ChBaseVw.h"\
	".\ChHtmDsp.h"\
	".\ChLocBar.h"\
	".\ChMFrame.h"\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	
NODEP_CPP_CHHTM=\
	"..\..\unix\ChText\TextPriv.h"\
	

"$(INTDIR)\ChHtmDsp.obj" : $(SOURCE) $(DEP_CPP_CHHTM) "$(INTDIR)"\
 "$(INTDIR)\WTracker40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChBaseVw.cpp
DEP_CPP_CHBAS=\
	".\ChBaseVw.h"\
	".\ChHtmDsp.h"\
	".\ChLocBar.h"\
	".\ChMFrame.h"\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChBaseVw.obj" : $(SOURCE) $(DEP_CPP_CHBAS) "$(INTDIR)"\
 "$(INTDIR)\WTracker40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChLocBar.cpp
DEP_CPP_CHLOC=\
	".\ChLocBar.h"\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChLocBar.obj" : $(SOURCE) $(DEP_CPP_CHLOC) "$(INTDIR)"\
 "$(INTDIR)\WTracker40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChBasDoc.cpp
DEP_CPP_CHBASD=\
	".\ChBasDoc.h"\
	".\ChBaseVw.h"\
	".\ChHtmDsp.h"\
	".\ChLocBar.h"\
	".\ChMFrame.h"\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChBasDoc.obj" : $(SOURCE) $(DEP_CPP_CHBASD) "$(INTDIR)"\
 "$(INTDIR)\WTracker40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChUtils.cpp
DEP_CPP_CHUTI=\
	".\ChUtils.h"\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChUtils.obj" : $(SOURCE) $(DEP_CPP_CHUTI) "$(INTDIR)"\
 "$(INTDIR)\WTracker40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrefs.cpp
DEP_CPP_CHPRE=\
	".\ChPrefs.h"\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChPrefs.obj" : $(SOURCE) $(DEP_CPP_CHPRE) "$(INTDIR)"\
 "$(INTDIR)\WTracker40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrNet.cpp
DEP_CPP_CHPRN=\
	".\ChBaseVw.h"\
	".\ChHtmDsp.h"\
	".\ChLocBar.h"\
	".\ChMFrame.h"\
	".\ChPrNet.h"\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChPrNet.obj" : $(SOURCE) $(DEP_CPP_CHPRN) "$(INTDIR)"\
 "$(INTDIR)\WTracker40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\OpenLoc.cpp
DEP_CPP_OPENL=\
	".\ChHtmDsp.h"\
	".\OpenLoc.h"\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\OpenLoc.obj" : $(SOURCE) $(DEP_CPP_OPENL) "$(INTDIR)"\
 "$(INTDIR)\WTracker40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrFont.cpp
DEP_CPP_CHPRF=\
	".\ChBaseVw.h"\
	".\ChHtmDsp.h"\
	".\ChLocBar.h"\
	".\ChMFrame.h"\
	".\ChPrFont.h"\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChPrFont.obj" : $(SOURCE) $(DEP_CPP_CHPRF) "$(INTDIR)"\
 "$(INTDIR)\WTracker40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAbout.cpp
DEP_CPP_CHABO=\
	".\ChAbout.h"\
	".\ChBaseVw.h"\
	".\ChHtmDsp.h"\
	".\ChLocBar.h"\
	".\ChMFrame.h"\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDibDecoder.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChAbout.obj" : $(SOURCE) $(DEP_CPP_CHABO) "$(INTDIR)"\
 "$(INTDIR)\WTracker40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWebTracker.cpp
DEP_CPP_CHWEB=\
	".\ChBasDoc.h"\
	".\ChBaseVw.h"\
	".\ChHtmDsp.h"\
	".\ChLocBar.h"\
	".\ChMFrame.h"\
	".\StdAFX.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChWebTracker.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChWebTracker.obj" : $(SOURCE) $(DEP_CPP_CHWEB) "$(INTDIR)"\
 "$(INTDIR)\WTracker40.pch"


# End Source File
# End Target
# End Project
################################################################################
