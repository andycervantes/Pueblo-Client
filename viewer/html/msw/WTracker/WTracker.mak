# Microsoft Visual C++ Generated NMAKE File, Format Version 2.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Debug" && "$(CFG)" != "Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "WTracker.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
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
# PROP Output_Dir "WinDebug"
# PROP Intermediate_Dir "WinDebug"
OUTDIR=.\WinDebug
INTDIR=.\WinDebug

ALL : $(OUTDIR)/WTracker.dll $(OUTDIR)/WTracker.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"WTracker.pch" /Yu"stdafx.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"WTracker.pdb" /c 
CPP_OBJS=.\WinDebug/
# ADD BASE RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo$(INTDIR)/"WTracker.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"WTracker.bsc" 
BSC32_SBRS= \
	$(INTDIR)/StdAFX.sbr \
	$(INTDIR)/WTracker.sbr \
	$(INTDIR)/ChMFrame.sbr \
	$(INTDIR)/ChHtmDsp.sbr \
	$(INTDIR)/ChBaseVw.sbr \
	$(INTDIR)/ChLocBar.sbr \
	$(INTDIR)/ChBasDoc.sbr \
	$(INTDIR)/ChUtils.sbr \
	$(INTDIR)/ChPrefs.sbr \
	$(INTDIR)/ChPrNet.sbr \
	$(INTDIR)/OpenLoc.sbr \
	$(INTDIR)/ChPrFont.sbr \
	$(INTDIR)/ChAbout.sbr \
	$(INTDIR)/ChWebTracker.sbr

$(OUTDIR)/WTracker.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /DEF:"WTracker.def" /IMPLIB:"WTracker.lib"
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 \chaco\lib\PbUtil32.lib \chaco\lib\Pueblo32.lib /NOLOGO /BASE:0x2a000000 /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /DEF:"WTracker.def" /OUT:"/chaco/bin/debug/WTracker.dll" /PDB:"/chaco/bin/debug/WTracker.pdb" /OUT:"/chaco/bin/debug/WTracker.dll" /PDB:"/chaco/bin/debug/WTracker.pdb" /OUT:"/chaco/bin/debug/WTracker.dll" /IMPLIB:"/chaco/lib/WTracker.lib"
LINK32_FLAGS=\chaco\lib\PbUtil32.lib \chaco\lib\Pueblo32.lib /NOLOGO\
 /BASE:0x2a000000 /SUBSYSTEM:windows /DLL /INCREMENTAL:yes\
 /PDB:$(OUTDIR)/"WTracker.pdb" /DEBUG /MACHINE:I386 /DEF:"WTracker.def"\
 /OUT:$(OUTDIR)/"WTracker.dll" /IMPLIB:$(OUTDIR)/"WTracker.lib"\
 /OUT:"/chaco/bin/debug/WTracker.dll" /PDB:"/chaco/bin/debug/WTracker.pdb"\
 /OUT:"/chaco/bin/debug/WTracker.dll" /PDB:"/chaco/bin/debug/WTracker.pdb"\
 /OUT:"/chaco/bin/debug/WTracker.dll" /IMPLIB:"/chaco/lib/WTracker.lib"  
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/StdAFX.obj \
	$(INTDIR)/WTracker.obj \
	$(INTDIR)/WTracker.res \
	$(INTDIR)/ChMFrame.obj \
	$(INTDIR)/ChHtmDsp.obj \
	$(INTDIR)/ChBaseVw.obj \
	$(INTDIR)/ChLocBar.obj \
	$(INTDIR)/ChBasDoc.obj \
	$(INTDIR)/ChUtils.obj \
	$(INTDIR)/ChPrefs.obj \
	$(INTDIR)/ChPrNet.obj \
	$(INTDIR)/OpenLoc.obj \
	$(INTDIR)/ChPrFont.obj \
	$(INTDIR)/ChAbout.obj \
	$(INTDIR)/ChWebTracker.obj

$(OUTDIR)/WTracker.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
OUTDIR=.\WinRel
INTDIR=.\WinRel

ALL : $(OUTDIR)/WTracker.dll $(OUTDIR)/WTracker.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"WTracker.pch" /Yu"stdafx.h" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\WinRel/
# ADD BASE RSC /l 0x0 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo$(INTDIR)/"WTracker.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"WTracker.bsc" 
BSC32_SBRS= \
	$(INTDIR)/StdAFX.sbr \
	$(INTDIR)/WTracker.sbr \
	$(INTDIR)/ChMFrame.sbr \
	$(INTDIR)/ChHtmDsp.sbr \
	$(INTDIR)/ChBaseVw.sbr \
	$(INTDIR)/ChLocBar.sbr \
	$(INTDIR)/ChBasDoc.sbr \
	$(INTDIR)/ChUtils.sbr \
	$(INTDIR)/ChPrefs.sbr \
	$(INTDIR)/ChPrNet.sbr \
	$(INTDIR)/OpenLoc.sbr \
	$(INTDIR)/ChPrFont.sbr \
	$(INTDIR)/ChAbout.sbr \
	$(INTDIR)/ChWebTracker.sbr

$(OUTDIR)/WTracker.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386 /DEF:"WTracker.def" /IMPLIB:"WTracker.lib"
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 \chaco\lib\PbUtil32.lib \chaco\lib\Pueblo32.lib /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386 /DEF:"WTracker.def" /PDB:"/chaco/bin/release/WTracker.pdb" /OUT:"/chaco/bin/release/WTracker.dll" /OUT:"/chaco/bin/release/WTracker.dll" /IMPLIB:"/chaco/lib/WTracker.lib"
# SUBTRACT LINK32 /PDB:none
LINK32_FLAGS=\chaco\lib\PbUtil32.lib \chaco\lib\Pueblo32.lib /NOLOGO\
 /SUBSYSTEM:windows /DLL /INCREMENTAL:no /PDB:$(OUTDIR)/"WTracker.pdb"\
 /MACHINE:I386 /DEF:"WTracker.def" /OUT:$(OUTDIR)/"WTracker.dll"\
 /IMPLIB:$(OUTDIR)/"WTracker.lib" /PDB:"/chaco/bin/release/WTracker.pdb"\
 /OUT:"/chaco/bin/release/WTracker.dll" /OUT:"/chaco/bin/release/WTracker.dll"\
 /IMPLIB:"/chaco/lib/WTracker.lib"  
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/StdAFX.obj \
	$(INTDIR)/WTracker.obj \
	$(INTDIR)/WTracker.res \
	$(INTDIR)/ChMFrame.obj \
	$(INTDIR)/ChHtmDsp.obj \
	$(INTDIR)/ChBaseVw.obj \
	$(INTDIR)/ChLocBar.obj \
	$(INTDIR)/ChBasDoc.obj \
	$(INTDIR)/ChUtils.obj \
	$(INTDIR)/ChPrefs.obj \
	$(INTDIR)/ChPrNet.obj \
	$(INTDIR)/OpenLoc.obj \
	$(INTDIR)/ChPrFont.obj \
	$(INTDIR)/ChAbout.obj \
	$(INTDIR)/ChWebTracker.obj

$(OUTDIR)/WTracker.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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
DEP_STDAF=\
	.\StdAFX.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h

!IF  "$(CFG)" == "Win32 Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

$(INTDIR)/StdAFX.obj :  $(SOURCE)  $(DEP_STDAF) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"WTracker.pch" /Yc"stdafx.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"WTracker.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

$(INTDIR)/StdAFX.obj :  $(SOURCE)  $(DEP_STDAF) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"WTracker.pch" /Yc"stdafx.h" /Fo$(INTDIR)/ /c\
  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\WTracker.cpp
DEP_WTRAC=\
	.\StdAFX.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h

$(INTDIR)/WTracker.obj :  $(SOURCE)  $(DEP_WTRAC) $(INTDIR)\
 $(INTDIR)/StdAFX.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\WTracker.rc
DEP_WTRACK=\
	.\res\idr_main.ico\
	.\res\toolbar.bmp\
	.\res\WTracker.rc2

$(INTDIR)/WTracker.res :  $(SOURCE)  $(DEP_WTRACK) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\readme.txt
# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMFrame.cpp
DEP_CHMFR=\
	.\StdAFX.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChImgUtil.h\
	.\ChAbout.h\
	.\ChPrefs.h\
	.\ChPrNet.h\
	.\ChPrFont.h\
	.\OpenLoc.h\
	.\ChMFrame.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChList.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChSplay.h\
	.\ChLocBar.h\
	.\ChBaseVw.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChImgConsumer.h\
	.\ChHtmDsp.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChHtmWnd.h

$(INTDIR)/ChMFrame.obj :  $(SOURCE)  $(DEP_CHMFR) $(INTDIR)\
 $(INTDIR)/StdAFX.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmDsp.cpp
DEP_CHHTM=\
	.\StdAFX.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChHtmlSettings.h\
	.\ChMFrame.h\
	.\ChHtmDsp.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChList.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChSplay.h\
	.\ChLocBar.h\
	.\ChBaseVw.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChHtmDsp.obj :  $(SOURCE)  $(DEP_CHHTM) $(INTDIR)\
 $(INTDIR)/StdAFX.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChBaseVw.cpp
DEP_CHBAS=\
	.\StdAFX.h\
	.\ChMFrame.h\
	.\ChBaseVw.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChHtpCon.h\
	.\ChLocBar.h\
	.\ChHtmDsp.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChBaseVw.obj :  $(SOURCE)  $(DEP_CHBAS) $(INTDIR)\
 $(INTDIR)/StdAFX.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChLocBar.cpp
DEP_CHLOC=\
	.\StdAFX.h\
	\chaco\include\ChReg.h\
	.\ChLocBar.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDb.h

$(INTDIR)/ChLocBar.obj :  $(SOURCE)  $(DEP_CHLOC) $(INTDIR)\
 $(INTDIR)/StdAFX.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChBasDoc.cpp
DEP_CHBASD=\
	.\StdAFX.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	.\ChBasDoc.h\
	.\ChBaseVw.h\
	.\ChHtmDsp.h\
	.\ChMFrame.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChHtpCon.h\
	.\ChLocBar.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChBasDoc.obj :  $(SOURCE)  $(DEP_CHBASD) $(INTDIR)\
 $(INTDIR)/StdAFX.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChUtils.cpp
DEP_CHUTI=\
	.\StdAFX.h\
	.\ChUtils.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h

$(INTDIR)/ChUtils.obj :  $(SOURCE)  $(DEP_CHUTI) $(INTDIR) $(INTDIR)/StdAFX.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrefs.cpp
DEP_CHPRE=\
	.\StdAFX.h\
	.\ChPrefs.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h

$(INTDIR)/ChPrefs.obj :  $(SOURCE)  $(DEP_CHPRE) $(INTDIR) $(INTDIR)/StdAFX.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrNet.cpp
DEP_CHPRN=\
	.\StdAFX.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChReg.h\
	.\ChMFrame.h\
	.\ChPrNet.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChSplay.h\
	.\ChLocBar.h\
	.\ChBaseVw.h\
	.\ChHtmDsp.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChPrNet.obj :  $(SOURCE)  $(DEP_CHPRN) $(INTDIR) $(INTDIR)/StdAFX.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\OpenLoc.cpp
DEP_OPENL=\
	.\StdAFX.h\
	.\OpenLoc.h\
	.\ChHtmDsp.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/OpenLoc.obj :  $(SOURCE)  $(DEP_OPENL) $(INTDIR) $(INTDIR)/StdAFX.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPrFont.cpp
DEP_CHPRF=\
	.\StdAFX.h\
	\chaco\include\ChReg.h\
	.\ChMFrame.h\
	.\ChPrFont.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChHtpCon.h\
	.\ChLocBar.h\
	.\ChBaseVw.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	.\ChHtmDsp.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChPrFont.obj :  $(SOURCE)  $(DEP_CHPRF) $(INTDIR)\
 $(INTDIR)/StdAFX.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAbout.cpp
DEP_CHABO=\
	.\StdAFX.h\
	.\ChAbout.h\
	.\ChMFrame.h\
	\chaco\include\ChDibDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChHtpCon.h\
	.\ChLocBar.h\
	.\ChBaseVw.h\
	\chaco\include\ChImageDecoder.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	.\ChHtmDsp.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChAbout.obj :  $(SOURCE)  $(DEP_CHABO) $(INTDIR) $(INTDIR)/StdAFX.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWebTracker.cpp
DEP_CHWEB=\
	.\StdAFX.h\
	.\ChMFrame.h\
	.\ChBasDoc.h\
	.\ChBaseVw.h\
	\chaco\include\ChWebTracker.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChHtpCon.h\
	.\ChLocBar.h\
	.\ChHtmDsp.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChWebTracker.obj :  $(SOURCE)  $(DEP_CHWEB) $(INTDIR)\
 $(INTDIR)/StdAFX.obj

# End Source File
# End Group
# End Project
################################################################################
