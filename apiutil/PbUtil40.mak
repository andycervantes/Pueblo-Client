# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=PbUtil32 - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to PbUtil32 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "PbUtil32 - Win32 Debug" && "$(CFG)" !=\
 "PbUtil32 - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "PbUtil40.mak" CFG="PbUtil32 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PbUtil32 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "PbUtil32 - Win32 Release" (based on\
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

!IF  "$(CFG)" == "PbUtil32 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "\chaco\bin\debug"
# PROP Intermediate_Dir "debug"
OUTDIR=\chaco\bin\debug
INTDIR=.\debug

ALL : "$(OUTDIR)\PbUtil32.dll"

CLEAN : 
	-@erase "$(INTDIR)\ChDibBmp.obj"
	-@erase "$(INTDIR)\ChDibDecoder.obj"
	-@erase "$(INTDIR)\ChDibImage.obj"
	-@erase "$(INTDIR)\ChDibPal.obj"
	-@erase "$(INTDIR)\ChDibTransparent.obj"
	-@erase "$(INTDIR)\ChDibUtl.obj"
	-@erase "$(INTDIR)\ChGIF.obj"
	-@erase "$(INTDIR)\ChJPEG.obj"
	-@erase "$(INTDIR)\ChSFImage.obj"
	-@erase "$(INTDIR)\ChUnzip.obj"
	-@erase "$(INTDIR)\explode.obj"
	-@erase "$(INTDIR)\extract.obj"
	-@erase "$(INTDIR)\file_io.obj"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(INTDIR)\inflate.obj"
	-@erase "$(INTDIR)\jcomapi.obj"
	-@erase "$(INTDIR)\jdapi.obj"
	-@erase "$(INTDIR)\jdatasrc.obj"
	-@erase "$(INTDIR)\jdcoefct.obj"
	-@erase "$(INTDIR)\jdcolor.obj"
	-@erase "$(INTDIR)\jddctmgr.obj"
	-@erase "$(INTDIR)\jdhuff.obj"
	-@erase "$(INTDIR)\jdmainct.obj"
	-@erase "$(INTDIR)\jdmarker.obj"
	-@erase "$(INTDIR)\jdmaster.obj"
	-@erase "$(INTDIR)\jdmerge.obj"
	-@erase "$(INTDIR)\jdpostct.obj"
	-@erase "$(INTDIR)\jdsample.obj"
	-@erase "$(INTDIR)\jerror.obj"
	-@erase "$(INTDIR)\jfdctint.obj"
	-@erase "$(INTDIR)\jidctflt.obj"
	-@erase "$(INTDIR)\jidctint.obj"
	-@erase "$(INTDIR)\jmemmgr.obj"
	-@erase "$(INTDIR)\jquant1.obj"
	-@erase "$(INTDIR)\jquant2.obj"
	-@erase "$(INTDIR)\jutils.obj"
	-@erase "$(INTDIR)\match.obj"
	-@erase "$(INTDIR)\PbUtil32.obj"
	-@erase "$(INTDIR)\PbUtil32.res"
	-@erase "$(INTDIR)\PbUtil40.pch"
	-@erase "$(INTDIR)\unreduce.obj"
	-@erase "$(INTDIR)\unshrink.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\PbUtil32.dll"
	-@erase "$(OUTDIR)\PbUtil32.exp"
	-@erase "$(OUTDIR)\PbUtil32.ilk"
	-@erase "$(OUTDIR)\PbUtil32.lib"
	-@erase "$(OUTDIR)\PbUtil32.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"headers.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /G5 /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/PbUtil40.pch" /Yu"headers.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\debug/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo"$(INTDIR)/PbUtil32.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/PbUtil40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /def:"PbUtil32.def" /implib:"PbUtil32.lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 lz32.lib winmm.lib /nologo /base:0x18000000 /subsystem:windows /dll /debug /machine:I386 /def:"PbUtil32.def" /out:"\chaco\bin\debug/PbUtil32.dll" /IMPLIB:"/chaco/lib/PbUtil32.lib"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=lz32.lib winmm.lib /nologo /base:0x18000000 /subsystem:windows\
 /dll /incremental:yes /pdb:"$(OUTDIR)/PbUtil32.pdb" /debug /machine:I386\
 /def:"PbUtil32.def" /out:"$(OUTDIR)/PbUtil32.dll"\
 /implib:"$(OUTDIR)/PbUtil32.lib" /IMPLIB:"/chaco/lib/PbUtil32.lib" 
DEF_FILE= \
	".\PbUtil32.def"
LINK32_OBJS= \
	"$(INTDIR)\ChDibBmp.obj" \
	"$(INTDIR)\ChDibDecoder.obj" \
	"$(INTDIR)\ChDibImage.obj" \
	"$(INTDIR)\ChDibPal.obj" \
	"$(INTDIR)\ChDibTransparent.obj" \
	"$(INTDIR)\ChDibUtl.obj" \
	"$(INTDIR)\ChGIF.obj" \
	"$(INTDIR)\ChJPEG.obj" \
	"$(INTDIR)\ChSFImage.obj" \
	"$(INTDIR)\ChUnzip.obj" \
	"$(INTDIR)\explode.obj" \
	"$(INTDIR)\extract.obj" \
	"$(INTDIR)\file_io.obj" \
	"$(INTDIR)\headers.obj" \
	"$(INTDIR)\inflate.obj" \
	"$(INTDIR)\jcomapi.obj" \
	"$(INTDIR)\jdapi.obj" \
	"$(INTDIR)\jdatasrc.obj" \
	"$(INTDIR)\jdcoefct.obj" \
	"$(INTDIR)\jdcolor.obj" \
	"$(INTDIR)\jddctmgr.obj" \
	"$(INTDIR)\jdhuff.obj" \
	"$(INTDIR)\jdmainct.obj" \
	"$(INTDIR)\jdmarker.obj" \
	"$(INTDIR)\jdmaster.obj" \
	"$(INTDIR)\jdmerge.obj" \
	"$(INTDIR)\jdpostct.obj" \
	"$(INTDIR)\jdsample.obj" \
	"$(INTDIR)\jerror.obj" \
	"$(INTDIR)\jfdctint.obj" \
	"$(INTDIR)\jidctflt.obj" \
	"$(INTDIR)\jidctint.obj" \
	"$(INTDIR)\jmemmgr.obj" \
	"$(INTDIR)\jquant1.obj" \
	"$(INTDIR)\jquant2.obj" \
	"$(INTDIR)\jutils.obj" \
	"$(INTDIR)\match.obj" \
	"$(INTDIR)\PbUtil32.obj" \
	"$(INTDIR)\PbUtil32.res" \
	"$(INTDIR)\unreduce.obj" \
	"$(INTDIR)\unshrink.obj"

"$(OUTDIR)\PbUtil32.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PbUtil32 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "\chaco\bin\release"
# PROP Intermediate_Dir "release"
OUTDIR=\chaco\bin\release
INTDIR=.\release

ALL : "$(OUTDIR)\PbUtil32.dll"

CLEAN : 
	-@erase "$(INTDIR)\ChDibBmp.obj"
	-@erase "$(INTDIR)\ChDibDecoder.obj"
	-@erase "$(INTDIR)\ChDibImage.obj"
	-@erase "$(INTDIR)\ChDibPal.obj"
	-@erase "$(INTDIR)\ChDibTransparent.obj"
	-@erase "$(INTDIR)\ChDibUtl.obj"
	-@erase "$(INTDIR)\ChGIF.obj"
	-@erase "$(INTDIR)\ChJPEG.obj"
	-@erase "$(INTDIR)\ChSFImage.obj"
	-@erase "$(INTDIR)\ChUnzip.obj"
	-@erase "$(INTDIR)\explode.obj"
	-@erase "$(INTDIR)\extract.obj"
	-@erase "$(INTDIR)\file_io.obj"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(INTDIR)\inflate.obj"
	-@erase "$(INTDIR)\jcomapi.obj"
	-@erase "$(INTDIR)\jdapi.obj"
	-@erase "$(INTDIR)\jdatasrc.obj"
	-@erase "$(INTDIR)\jdcoefct.obj"
	-@erase "$(INTDIR)\jdcolor.obj"
	-@erase "$(INTDIR)\jddctmgr.obj"
	-@erase "$(INTDIR)\jdhuff.obj"
	-@erase "$(INTDIR)\jdmainct.obj"
	-@erase "$(INTDIR)\jdmarker.obj"
	-@erase "$(INTDIR)\jdmaster.obj"
	-@erase "$(INTDIR)\jdmerge.obj"
	-@erase "$(INTDIR)\jdpostct.obj"
	-@erase "$(INTDIR)\jdsample.obj"
	-@erase "$(INTDIR)\jerror.obj"
	-@erase "$(INTDIR)\jfdctint.obj"
	-@erase "$(INTDIR)\jidctflt.obj"
	-@erase "$(INTDIR)\jidctint.obj"
	-@erase "$(INTDIR)\jmemmgr.obj"
	-@erase "$(INTDIR)\jquant1.obj"
	-@erase "$(INTDIR)\jquant2.obj"
	-@erase "$(INTDIR)\jutils.obj"
	-@erase "$(INTDIR)\match.obj"
	-@erase "$(INTDIR)\PbUtil32.obj"
	-@erase "$(INTDIR)\PbUtil32.res"
	-@erase "$(INTDIR)\PbUtil40.pch"
	-@erase "$(INTDIR)\unreduce.obj"
	-@erase "$(INTDIR)\unshrink.obj"
	-@erase "$(OUTDIR)\PbUtil32.dll"
	-@erase "$(OUTDIR)\PbUtil32.exp"
	-@erase "$(OUTDIR)\PbUtil32.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"headers.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /G5 /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/PbUtil40.pch" /Yu"headers.h" /Fo"$(INTDIR)/"\
 /c 
CPP_OBJS=.\release/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x0 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo"$(INTDIR)/PbUtil32.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/PbUtil40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386 /def:"PbUtil32.def" /implib:"PbUtil32.lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 lz32.lib winmm.lib /nologo /base:0x18000000 /subsystem:windows /dll /machine:I386 /def:"PbUtil32.def" /out:"\chaco\bin\release/PbUtil32.dll" /IMPLIB:"/chaco/lib/PbUtil32.lib"
# SUBTRACT LINK32 /pdb:none /incremental:yes
LINK32_FLAGS=lz32.lib winmm.lib /nologo /base:0x18000000 /subsystem:windows\
 /dll /incremental:no /pdb:"$(OUTDIR)/PbUtil32.pdb" /machine:I386\
 /def:"PbUtil32.def" /out:"$(OUTDIR)/PbUtil32.dll"\
 /implib:"$(OUTDIR)/PbUtil32.lib" /IMPLIB:"/chaco/lib/PbUtil32.lib" 
DEF_FILE= \
	".\PbUtil32.def"
LINK32_OBJS= \
	"$(INTDIR)\ChDibBmp.obj" \
	"$(INTDIR)\ChDibDecoder.obj" \
	"$(INTDIR)\ChDibImage.obj" \
	"$(INTDIR)\ChDibPal.obj" \
	"$(INTDIR)\ChDibTransparent.obj" \
	"$(INTDIR)\ChDibUtl.obj" \
	"$(INTDIR)\ChGIF.obj" \
	"$(INTDIR)\ChJPEG.obj" \
	"$(INTDIR)\ChSFImage.obj" \
	"$(INTDIR)\ChUnzip.obj" \
	"$(INTDIR)\explode.obj" \
	"$(INTDIR)\extract.obj" \
	"$(INTDIR)\file_io.obj" \
	"$(INTDIR)\headers.obj" \
	"$(INTDIR)\inflate.obj" \
	"$(INTDIR)\jcomapi.obj" \
	"$(INTDIR)\jdapi.obj" \
	"$(INTDIR)\jdatasrc.obj" \
	"$(INTDIR)\jdcoefct.obj" \
	"$(INTDIR)\jdcolor.obj" \
	"$(INTDIR)\jddctmgr.obj" \
	"$(INTDIR)\jdhuff.obj" \
	"$(INTDIR)\jdmainct.obj" \
	"$(INTDIR)\jdmarker.obj" \
	"$(INTDIR)\jdmaster.obj" \
	"$(INTDIR)\jdmerge.obj" \
	"$(INTDIR)\jdpostct.obj" \
	"$(INTDIR)\jdsample.obj" \
	"$(INTDIR)\jerror.obj" \
	"$(INTDIR)\jfdctint.obj" \
	"$(INTDIR)\jidctflt.obj" \
	"$(INTDIR)\jidctint.obj" \
	"$(INTDIR)\jmemmgr.obj" \
	"$(INTDIR)\jquant1.obj" \
	"$(INTDIR)\jquant2.obj" \
	"$(INTDIR)\jutils.obj" \
	"$(INTDIR)\match.obj" \
	"$(INTDIR)\PbUtil32.obj" \
	"$(INTDIR)\PbUtil32.res" \
	"$(INTDIR)\unreduce.obj" \
	"$(INTDIR)\unshrink.obj"

"$(OUTDIR)\PbUtil32.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "PbUtil32 - Win32 Debug"
# Name "PbUtil32 - Win32 Release"

!IF  "$(CFG)" == "PbUtil32 - Win32 Debug"

!ELSEIF  "$(CFG)" == "PbUtil32 - Win32 Release"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\PbUtil32.cpp
DEP_CPP_PBUTI=\
	".\headers.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\PbUtil32.obj" : $(SOURCE) $(DEP_CPP_PBUTI) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PbUtil32.rc
DEP_RSC_PBUTIL=\
	".\res\gray.pal"\
	".\res\PbUtil32.rc2"\
	

"$(INTDIR)\PbUtil32.res" : $(SOURCE) $(DEP_RSC_PBUTIL) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PbUtil32.def

!IF  "$(CFG)" == "PbUtil32 - Win32 Debug"

!ELSEIF  "$(CFG)" == "PbUtil32 - Win32 Release"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\headers.cpp
DEP_CPP_HEADE=\
	".\headers.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

!IF  "$(CFG)" == "PbUtil32 - Win32 Debug"

# ADD CPP /Yc"headers.h"

BuildCmds= \
	$(CPP) /nologo /G5 /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/PbUtil40.pch" /Yc"headers.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\headers.obj" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\PbUtil40.pch" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "PbUtil32 - Win32 Release"

# ADD CPP /Yc"headers.h"

BuildCmds= \
	$(CPP) /nologo /G5 /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /D "_WINDLL" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/PbUtil40.pch" /Yc"headers.h" /Fo"$(INTDIR)/"\
 /c $(SOURCE) \
	

"$(INTDIR)\headers.obj" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\PbUtil40.pch" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jcomapi.cpp
DEP_CPP_JCOMA=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jcomapi.obj" : $(SOURCE) $(DEP_CPP_JCOMA) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdapi.cpp
DEP_CPP_JDAPI=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChImgUtil.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jdapi.obj" : $(SOURCE) $(DEP_CPP_JDAPI) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdatasrc.cpp
DEP_CPP_JDATA=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jdatasrc.obj" : $(SOURCE) $(DEP_CPP_JDATA) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdcoefct.cpp
DEP_CPP_JDCOE=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jdcoefct.obj" : $(SOURCE) $(DEP_CPP_JDCOE) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdcolor.cpp
DEP_CPP_JDCOL=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jdcolor.obj" : $(SOURCE) $(DEP_CPP_JDCOL) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jddctmgr.cpp
DEP_CPP_JDDCT=\
	".\headers.h"\
	".\jdct.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jddctmgr.obj" : $(SOURCE) $(DEP_CPP_JDDCT) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdhuff.cpp
DEP_CPP_JDHUF=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jdhuff.obj" : $(SOURCE) $(DEP_CPP_JDHUF) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdmainct.cpp
DEP_CPP_JDMAI=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jdmainct.obj" : $(SOURCE) $(DEP_CPP_JDMAI) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdmarker.cpp
DEP_CPP_JDMAR=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jdmarker.obj" : $(SOURCE) $(DEP_CPP_JDMAR) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdmaster.cpp
DEP_CPP_JDMAS=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jdmaster.obj" : $(SOURCE) $(DEP_CPP_JDMAS) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdmerge.cpp
DEP_CPP_JDMER=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jdmerge.obj" : $(SOURCE) $(DEP_CPP_JDMER) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdpostct.cpp
DEP_CPP_JDPOS=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jdpostct.obj" : $(SOURCE) $(DEP_CPP_JDPOS) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdsample.cpp
DEP_CPP_JDSAM=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jdsample.obj" : $(SOURCE) $(DEP_CPP_JDSAM) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jerror.cpp
DEP_CPP_JERRO=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	".\jversion.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jerror.obj" : $(SOURCE) $(DEP_CPP_JERRO) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jfdctint.cpp
DEP_CPP_JFDCT=\
	".\headers.h"\
	".\jdct.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jfdctint.obj" : $(SOURCE) $(DEP_CPP_JFDCT) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jidctflt.cpp
DEP_CPP_JIDCT=\
	".\headers.h"\
	".\jdct.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jidctflt.obj" : $(SOURCE) $(DEP_CPP_JIDCT) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jidctint.cpp
DEP_CPP_JIDCTI=\
	".\headers.h"\
	".\jdct.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jidctint.obj" : $(SOURCE) $(DEP_CPP_JIDCTI) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jmemmgr.cpp
DEP_CPP_JMEMM=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jmemmgr.obj" : $(SOURCE) $(DEP_CPP_JMEMM) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jquant1.cpp
DEP_CPP_JQUAN=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jquant1.obj" : $(SOURCE) $(DEP_CPP_JQUAN) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jquant2.cpp
DEP_CPP_JQUANT=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jquant2.obj" : $(SOURCE) $(DEP_CPP_JQUANT) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jutils.cpp
DEP_CPP_JUTIL=\
	".\headers.h"\
	".\jerror.h"\
	".\jinclude.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\jutils.obj" : $(SOURCE) $(DEP_CPP_JUTIL) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChJPEG.cpp
DEP_CPP_CHJPE=\
	".\headers.h"\
	".\jerror.h"\
	".\jpegint.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\ChJPEG.obj" : $(SOURCE) $(DEP_CPP_CHJPE) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChUnzip.cpp
DEP_CPP_CHUNZ=\
	".\headers.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUnzip.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\unzip.h"\
	

"$(INTDIR)\ChUnzip.obj" : $(SOURCE) $(DEP_CPP_CHUNZ) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\explode.cpp
DEP_CPP_EXPLO=\
	".\headers.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUnzip.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\unzip.h"\
	

"$(INTDIR)\explode.obj" : $(SOURCE) $(DEP_CPP_EXPLO) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\extract.cpp
DEP_CPP_EXTRA=\
	".\headers.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUnzip.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\unzip.h"\
	

"$(INTDIR)\extract.obj" : $(SOURCE) $(DEP_CPP_EXTRA) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\file_io.cpp
DEP_CPP_FILE_=\
	".\headers.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUnzip.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\unzip.h"\
	

"$(INTDIR)\file_io.obj" : $(SOURCE) $(DEP_CPP_FILE_) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\inflate.cpp
DEP_CPP_INFLA=\
	".\headers.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUnzip.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\unzip.h"\
	

"$(INTDIR)\inflate.obj" : $(SOURCE) $(DEP_CPP_INFLA) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\match.cpp
DEP_CPP_MATCH=\
	".\headers.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUnzip.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\unzip.h"\
	

"$(INTDIR)\match.obj" : $(SOURCE) $(DEP_CPP_MATCH) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\unreduce.cpp
DEP_CPP_UNRED=\
	".\headers.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUnzip.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\unzip.h"\
	

"$(INTDIR)\unreduce.obj" : $(SOURCE) $(DEP_CPP_UNRED) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\unshrink.cpp
DEP_CPP_UNSHR=\
	".\headers.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUnzip.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\unzip.h"\
	

"$(INTDIR)\unshrink.obj" : $(SOURCE) $(DEP_CPP_UNSHR) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGIF.cpp
DEP_CPP_CHGIF=\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChGifDecoder.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\ChGIF.obj" : $(SOURCE) $(DEP_CPP_CHGIF) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSFImage.cpp
DEP_CPP_CHSFI=\
	".\headers.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChSFImage.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChSFImage.obj" : $(SOURCE) $(DEP_CPP_CHSFI) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDibBmp.cpp
DEP_CPP_CHDIB=\
	".\headers.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibBmp.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChGrVw.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChImgUtil.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\templcls\ChLstHlp.inl"\
	

"$(INTDIR)\ChDibBmp.obj" : $(SOURCE) $(DEP_CPP_CHDIB) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDibUtl.cpp
DEP_CPP_CHDIBU=\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgUtil.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	
NODEP_CPP_CHDIBU=\
	".\vwrres.h"\
	

"$(INTDIR)\ChDibUtl.obj" : $(SOURCE) $(DEP_CPP_CHDIBU) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDibDecoder.cpp
DEP_CPP_CHDIBD=\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibDecoder.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChImgUtil.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChDibDecoder.obj" : $(SOURCE) $(DEP_CPP_CHDIBD) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDibImage.cpp
DEP_CPP_CHDIBI=\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChImgUtil.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChDibImage.obj" : $(SOURCE) $(DEP_CPP_CHDIBI) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDibPal.cpp
DEP_CPP_CHDIBP=\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibBmp.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChDibPal.obj" : $(SOURCE) $(DEP_CPP_CHDIBP) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDibTransparent.cpp
DEP_CPP_CHDIBT=\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChImgUtil.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChDibTransparent.obj" : $(SOURCE) $(DEP_CPP_CHDIBT) "$(INTDIR)"\
 "$(INTDIR)\PbUtil40.pch"


# End Source File
# End Target
# End Project
################################################################################
