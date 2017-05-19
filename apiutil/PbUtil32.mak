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
!MESSAGE NMAKE /f "PbUtil32.mak" CFG="Win32 Debug"
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
# PROP Output_Dir "\chaco\bin\debug"
# PROP Intermediate_Dir "debug"
OUTDIR=\chaco\bin\debug
INTDIR=.\debug

ALL : $(OUTDIR)/PbUtil32.dll $(OUTDIR)/PbUtil32.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /FR /Yu"headers.h" /c
CPP_PROJ=/nologo /G5 /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_MBCS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"PbUtil32.pch" /Yu"headers.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"PbUtil32.pdb" /c 
CPP_OBJS=.\debug/
# ADD BASE RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo$(INTDIR)/"PbUtil32.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"PbUtil32.bsc" 
BSC32_SBRS= \
	$(INTDIR)/PbUtil32.sbr \
	$(INTDIR)/headers.sbr \
	$(INTDIR)/jcomapi.sbr \
	$(INTDIR)/jdapi.sbr \
	$(INTDIR)/jdatasrc.sbr \
	$(INTDIR)/jdcoefct.sbr \
	$(INTDIR)/jdcolor.sbr \
	$(INTDIR)/jddctmgr.sbr \
	$(INTDIR)/jdhuff.sbr \
	$(INTDIR)/jdmainct.sbr \
	$(INTDIR)/jdmarker.sbr \
	$(INTDIR)/jdmaster.sbr \
	$(INTDIR)/jdmerge.sbr \
	$(INTDIR)/jdpostct.sbr \
	$(INTDIR)/jdsample.sbr \
	$(INTDIR)/jerror.sbr \
	$(INTDIR)/jfdctint.sbr \
	$(INTDIR)/jidctflt.sbr \
	$(INTDIR)/jidctint.sbr \
	$(INTDIR)/jmemmgr.sbr \
	$(INTDIR)/jquant1.sbr \
	$(INTDIR)/jquant2.sbr \
	$(INTDIR)/jutils.sbr \
	$(INTDIR)/ChJPEG.sbr \
	$(INTDIR)/ChUnzip.sbr \
	$(INTDIR)/explode.sbr \
	$(INTDIR)/extract.sbr \
	$(INTDIR)/file_io.sbr \
	$(INTDIR)/inflate.sbr \
	$(INTDIR)/match.sbr \
	$(INTDIR)/unreduce.sbr \
	$(INTDIR)/unshrink.sbr \
	$(INTDIR)/ChGIF.sbr \
	$(INTDIR)/ChDibUtl.sbr \
	$(INTDIR)/ChDibTransparent.sbr \
	$(INTDIR)/ChDibImage.sbr \
	$(INTDIR)/ChDibDecoder.sbr \
	$(INTDIR)/ChDibPal.sbr \
	$(INTDIR)/ChDibBmp.sbr \
	$(INTDIR)/ChSFImage.sbr

$(OUTDIR)/PbUtil32.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /DEF:"PbUtil32.def" /IMPLIB:"PbUtil32.lib"
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 lz32.lib winmm.lib /NOLOGO /BASE:0x18000000 /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /DEF:"PbUtil32.def" /IMPLIB:"/chaco/lib/PbUtil32.lib"
# SUBTRACT LINK32 /PDB:none
LINK32_FLAGS=lz32.lib winmm.lib /NOLOGO /BASE:0x18000000 /SUBSYSTEM:windows\
 /DLL /INCREMENTAL:yes /PDB:$(OUTDIR)/"PbUtil32.pdb" /DEBUG /MACHINE:I386\
 /DEF:"PbUtil32.def" /OUT:$(OUTDIR)/"PbUtil32.dll"\
 /IMPLIB:$(OUTDIR)/"PbUtil32.lib" /IMPLIB:"/chaco/lib/PbUtil32.lib"  
DEF_FILE=.\PbUtil32.def
LINK32_OBJS= \
	$(INTDIR)/PbUtil32.obj \
	$(INTDIR)/PbUtil32.res \
	$(INTDIR)/headers.obj \
	$(INTDIR)/jcomapi.obj \
	$(INTDIR)/jdapi.obj \
	$(INTDIR)/jdatasrc.obj \
	$(INTDIR)/jdcoefct.obj \
	$(INTDIR)/jdcolor.obj \
	$(INTDIR)/jddctmgr.obj \
	$(INTDIR)/jdhuff.obj \
	$(INTDIR)/jdmainct.obj \
	$(INTDIR)/jdmarker.obj \
	$(INTDIR)/jdmaster.obj \
	$(INTDIR)/jdmerge.obj \
	$(INTDIR)/jdpostct.obj \
	$(INTDIR)/jdsample.obj \
	$(INTDIR)/jerror.obj \
	$(INTDIR)/jfdctint.obj \
	$(INTDIR)/jidctflt.obj \
	$(INTDIR)/jidctint.obj \
	$(INTDIR)/jmemmgr.obj \
	$(INTDIR)/jquant1.obj \
	$(INTDIR)/jquant2.obj \
	$(INTDIR)/jutils.obj \
	$(INTDIR)/ChJPEG.obj \
	$(INTDIR)/ChUnzip.obj \
	$(INTDIR)/explode.obj \
	$(INTDIR)/extract.obj \
	$(INTDIR)/file_io.obj \
	$(INTDIR)/inflate.obj \
	$(INTDIR)/match.obj \
	$(INTDIR)/unreduce.obj \
	$(INTDIR)/unshrink.obj \
	$(INTDIR)/ChGIF.obj \
	$(INTDIR)/ChDibUtl.obj \
	$(INTDIR)/ChDibTransparent.obj \
	$(INTDIR)/ChDibImage.obj \
	$(INTDIR)/ChDibDecoder.obj \
	$(INTDIR)/ChDibPal.obj \
	$(INTDIR)/ChDibBmp.obj \
	$(INTDIR)/ChSFImage.obj

$(OUTDIR)/PbUtil32.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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
# PROP Output_Dir "\chaco\bin\release"
# PROP Intermediate_Dir "release"
OUTDIR=\chaco\bin\release
INTDIR=.\release

ALL : $(OUTDIR)/PbUtil32.dll $(OUTDIR)/PbUtil32.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /FR /Yu"headers.h" /c
CPP_PROJ=/nologo /G5 /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"PbUtil32.pch" /Yu"headers.h" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\release/
# ADD BASE RSC /l 0x0 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo$(INTDIR)/"PbUtil32.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"PbUtil32.bsc" 
BSC32_SBRS= \
	$(INTDIR)/PbUtil32.sbr \
	$(INTDIR)/headers.sbr \
	$(INTDIR)/jcomapi.sbr \
	$(INTDIR)/jdapi.sbr \
	$(INTDIR)/jdatasrc.sbr \
	$(INTDIR)/jdcoefct.sbr \
	$(INTDIR)/jdcolor.sbr \
	$(INTDIR)/jddctmgr.sbr \
	$(INTDIR)/jdhuff.sbr \
	$(INTDIR)/jdmainct.sbr \
	$(INTDIR)/jdmarker.sbr \
	$(INTDIR)/jdmaster.sbr \
	$(INTDIR)/jdmerge.sbr \
	$(INTDIR)/jdpostct.sbr \
	$(INTDIR)/jdsample.sbr \
	$(INTDIR)/jerror.sbr \
	$(INTDIR)/jfdctint.sbr \
	$(INTDIR)/jidctflt.sbr \
	$(INTDIR)/jidctint.sbr \
	$(INTDIR)/jmemmgr.sbr \
	$(INTDIR)/jquant1.sbr \
	$(INTDIR)/jquant2.sbr \
	$(INTDIR)/jutils.sbr \
	$(INTDIR)/ChJPEG.sbr \
	$(INTDIR)/ChUnzip.sbr \
	$(INTDIR)/explode.sbr \
	$(INTDIR)/extract.sbr \
	$(INTDIR)/file_io.sbr \
	$(INTDIR)/inflate.sbr \
	$(INTDIR)/match.sbr \
	$(INTDIR)/unreduce.sbr \
	$(INTDIR)/unshrink.sbr \
	$(INTDIR)/ChGIF.sbr \
	$(INTDIR)/ChDibUtl.sbr \
	$(INTDIR)/ChDibTransparent.sbr \
	$(INTDIR)/ChDibImage.sbr \
	$(INTDIR)/ChDibDecoder.sbr \
	$(INTDIR)/ChDibPal.sbr \
	$(INTDIR)/ChDibBmp.sbr \
	$(INTDIR)/ChSFImage.sbr

$(OUTDIR)/PbUtil32.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386 /DEF:"PbUtil32.def" /IMPLIB:"PbUtil32.lib"
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 lz32.lib winmm.lib /NOLOGO /BASE:0x18000000 /SUBSYSTEM:windows /DLL /MACHINE:I386 /DEF:"PbUtil32.def" /IMPLIB:"/chaco/lib/PbUtil32.lib"
# SUBTRACT LINK32 /PDB:none /INCREMENTAL:yes
LINK32_FLAGS=lz32.lib winmm.lib /NOLOGO /BASE:0x18000000 /SUBSYSTEM:windows\
 /DLL /INCREMENTAL:no /PDB:$(OUTDIR)/"PbUtil32.pdb" /MACHINE:I386\
 /DEF:"PbUtil32.def" /OUT:$(OUTDIR)/"PbUtil32.dll"\
 /IMPLIB:$(OUTDIR)/"PbUtil32.lib" /IMPLIB:"/chaco/lib/PbUtil32.lib"  
DEF_FILE=.\PbUtil32.def
LINK32_OBJS= \
	$(INTDIR)/PbUtil32.obj \
	$(INTDIR)/PbUtil32.res \
	$(INTDIR)/headers.obj \
	$(INTDIR)/jcomapi.obj \
	$(INTDIR)/jdapi.obj \
	$(INTDIR)/jdatasrc.obj \
	$(INTDIR)/jdcoefct.obj \
	$(INTDIR)/jdcolor.obj \
	$(INTDIR)/jddctmgr.obj \
	$(INTDIR)/jdhuff.obj \
	$(INTDIR)/jdmainct.obj \
	$(INTDIR)/jdmarker.obj \
	$(INTDIR)/jdmaster.obj \
	$(INTDIR)/jdmerge.obj \
	$(INTDIR)/jdpostct.obj \
	$(INTDIR)/jdsample.obj \
	$(INTDIR)/jerror.obj \
	$(INTDIR)/jfdctint.obj \
	$(INTDIR)/jidctflt.obj \
	$(INTDIR)/jidctint.obj \
	$(INTDIR)/jmemmgr.obj \
	$(INTDIR)/jquant1.obj \
	$(INTDIR)/jquant2.obj \
	$(INTDIR)/jutils.obj \
	$(INTDIR)/ChJPEG.obj \
	$(INTDIR)/ChUnzip.obj \
	$(INTDIR)/explode.obj \
	$(INTDIR)/extract.obj \
	$(INTDIR)/file_io.obj \
	$(INTDIR)/inflate.obj \
	$(INTDIR)/match.obj \
	$(INTDIR)/unreduce.obj \
	$(INTDIR)/unshrink.obj \
	$(INTDIR)/ChGIF.obj \
	$(INTDIR)/ChDibUtl.obj \
	$(INTDIR)/ChDibTransparent.obj \
	$(INTDIR)/ChDibImage.obj \
	$(INTDIR)/ChDibDecoder.obj \
	$(INTDIR)/ChDibPal.obj \
	$(INTDIR)/ChDibBmp.obj \
	$(INTDIR)/ChSFImage.obj

$(OUTDIR)/PbUtil32.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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

SOURCE=.\PbUtil32.cpp
DEP_PBUTI=\
	.\headers.h\
	\chaco\include\ChTypes.h

$(INTDIR)/PbUtil32.obj :  $(SOURCE)  $(DEP_PBUTI) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PbUtil32.rc
DEP_PBUTIL=\
	.\res\PbUtil32.rc2

$(INTDIR)/PbUtil32.res :  $(SOURCE)  $(DEP_PBUTIL) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PbUtil32.def
# End Source File
################################################################################
# Begin Source File

SOURCE=.\headers.cpp
DEP_HEADE=\
	.\headers.h\
	\chaco\include\ChTypes.h

!IF  "$(CFG)" == "Win32 Debug"

# ADD CPP /Yc"headers.h"

$(INTDIR)/headers.obj :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)
   $(CPP) /nologo /G5 /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_MBCS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"PbUtil32.pch" /Yc"headers.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"PbUtil32.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# ADD CPP /Yc"headers.h"

$(INTDIR)/headers.obj :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)
   $(CPP) /nologo /G5 /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"PbUtil32.pch" /Yc"headers.h" /Fo$(INTDIR)/ /c\
  $(SOURCE) 

!ENDIF 

# End Source File
# End Group
################################################################################
# Begin Group "JPEG"

################################################################################
# Begin Source File

SOURCE=.\jcomapi.cpp
DEP_JCOMA=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jcomapi.obj :  $(SOURCE)  $(DEP_JCOMA) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdapi.cpp
DEP_JDAPI=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChImgUtil.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h

$(INTDIR)/jdapi.obj :  $(SOURCE)  $(DEP_JDAPI) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdatasrc.cpp
DEP_JDATA=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	.\jerror.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jdatasrc.obj :  $(SOURCE)  $(DEP_JDATA) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdcoefct.cpp
DEP_JDCOE=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jdcoefct.obj :  $(SOURCE)  $(DEP_JDCOE) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdcolor.cpp
DEP_JDCOL=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jdcolor.obj :  $(SOURCE)  $(DEP_JDCOL) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jddctmgr.cpp
DEP_JDDCT=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	.\jdct.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jddctmgr.obj :  $(SOURCE)  $(DEP_JDDCT) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdhuff.cpp
DEP_JDHUF=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jdhuff.obj :  $(SOURCE)  $(DEP_JDHUF) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdmainct.cpp
DEP_JDMAI=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jdmainct.obj :  $(SOURCE)  $(DEP_JDMAI) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdmarker.cpp
DEP_JDMAR=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jdmarker.obj :  $(SOURCE)  $(DEP_JDMAR) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdmaster.cpp
DEP_JDMAS=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jdmaster.obj :  $(SOURCE)  $(DEP_JDMAS) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdmerge.cpp
DEP_JDMER=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jdmerge.obj :  $(SOURCE)  $(DEP_JDMER) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdpostct.cpp
DEP_JDPOS=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jdpostct.obj :  $(SOURCE)  $(DEP_JDPOS) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jdsample.cpp
DEP_JDSAM=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jdsample.obj :  $(SOURCE)  $(DEP_JDSAM) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jerror.cpp
DEP_JERRO=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	.\jversion.h\
	.\jerror.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jerror.obj :  $(SOURCE)  $(DEP_JERRO) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jfdctint.cpp
DEP_JFDCT=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	.\jdct.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jfdctint.obj :  $(SOURCE)  $(DEP_JFDCT) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jidctflt.cpp
DEP_JIDCT=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	.\jdct.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jidctflt.obj :  $(SOURCE)  $(DEP_JIDCT) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jidctint.cpp
DEP_JIDCTI=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	.\jdct.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jidctint.obj :  $(SOURCE)  $(DEP_JIDCTI) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jmemmgr.cpp
DEP_JMEMM=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jmemmgr.obj :  $(SOURCE)  $(DEP_JMEMM) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jquant1.cpp
DEP_JQUAN=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jquant1.obj :  $(SOURCE)  $(DEP_JQUAN) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jquant2.cpp
DEP_JQUANT=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jquant2.obj :  $(SOURCE)  $(DEP_JQUANT) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\jutils.cpp
DEP_JUTIL=\
	.\headers.h\
	.\jinclude.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChTypes.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h

$(INTDIR)/jutils.obj :  $(SOURCE)  $(DEP_JUTIL) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChJPEG.cpp
DEP_CHJPE=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	.\jpegint.h\
	.\jerror.h

$(INTDIR)/ChJPEG.obj :  $(SOURCE)  $(DEP_CHJPE) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
# End Group
################################################################################
# Begin Group "ZIP"

################################################################################
# Begin Source File

SOURCE=.\ChUnzip.cpp
DEP_CHUNZ=\
	.\headers.h\
	\chaco\include\ChUnzip.h\
	\chaco\include\ChTypes.h\
	\chaco\include\unzip.h

$(INTDIR)/ChUnzip.obj :  $(SOURCE)  $(DEP_CHUNZ) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\explode.cpp
DEP_EXPLO=\
	.\headers.h\
	\chaco\include\ChUnzip.h\
	\chaco\include\ChTypes.h\
	\chaco\include\unzip.h

$(INTDIR)/explode.obj :  $(SOURCE)  $(DEP_EXPLO) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\extract.cpp
DEP_EXTRA=\
	.\headers.h\
	\chaco\include\ChUnzip.h\
	\chaco\include\ChTypes.h\
	\chaco\include\unzip.h

$(INTDIR)/extract.obj :  $(SOURCE)  $(DEP_EXTRA) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\file_io.cpp
DEP_FILE_=\
	.\headers.h\
	\chaco\include\ChUnzip.h\
	\chaco\include\ChTypes.h\
	\chaco\include\unzip.h

$(INTDIR)/file_io.obj :  $(SOURCE)  $(DEP_FILE_) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\inflate.cpp
DEP_INFLA=\
	.\headers.h\
	\chaco\include\ChUnzip.h\
	\chaco\include\ChTypes.h\
	\chaco\include\unzip.h

$(INTDIR)/inflate.obj :  $(SOURCE)  $(DEP_INFLA) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\match.cpp
DEP_MATCH=\
	.\headers.h\
	\chaco\include\ChUnzip.h\
	\chaco\include\ChTypes.h\
	\chaco\include\unzip.h

$(INTDIR)/match.obj :  $(SOURCE)  $(DEP_MATCH) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\unreduce.cpp
DEP_UNRED=\
	.\headers.h\
	\chaco\include\ChUnzip.h\
	\chaco\include\ChTypes.h\
	\chaco\include\unzip.h

$(INTDIR)/unreduce.obj :  $(SOURCE)  $(DEP_UNRED) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\unshrink.cpp
DEP_UNSHR=\
	.\headers.h\
	\chaco\include\ChUnzip.h\
	\chaco\include\ChTypes.h\
	\chaco\include\unzip.h

$(INTDIR)/unshrink.obj :  $(SOURCE)  $(DEP_UNSHR) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
# End Group
################################################################################
# Begin Group "GIF"

################################################################################
# Begin Source File

SOURCE=.\ChGIF.cpp
DEP_CHGIF=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChGifDecoder.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h

$(INTDIR)/ChGIF.obj :  $(SOURCE)  $(DEP_CHGIF) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
# End Group
################################################################################
# Begin Group "DIB"

################################################################################
# Begin Source File

SOURCE=.\ChDibUtl.cpp
DEP_CHDIB=\
	.\headers.h\
	\chaco\include\ChImgUtil.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h

$(INTDIR)/ChDibUtl.obj :  $(SOURCE)  $(DEP_CHDIB) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDibTransparent.cpp
DEP_CHDIBT=\
	.\headers.h\
	\chaco\include\ChImgUtil.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h

$(INTDIR)/ChDibTransparent.obj :  $(SOURCE)  $(DEP_CHDIBT) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDibImage.cpp
DEP_CHDIBI=\
	.\headers.h\
	\chaco\include\ChImgUtil.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h

$(INTDIR)/ChDibImage.obj :  $(SOURCE)  $(DEP_CHDIBI) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDibDecoder.cpp
DEP_CHDIBD=\
	.\headers.h\
	\chaco\include\ChImgUtil.h\
	\chaco\include\ChDibDecoder.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChImageDecoder.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h

$(INTDIR)/ChDibDecoder.obj :  $(SOURCE)  $(DEP_CHDIBD) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDibPal.cpp
DEP_CHDIBP=\
	.\headers.h\
	\chaco\include\ChDibBmp.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h

$(INTDIR)/ChDibPal.obj :  $(SOURCE)  $(DEP_CHDIBP) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDibBmp.cpp
DEP_CHDIBB=\
	.\headers.h\
	\chaco\include\ChImgUtil.h\
	\chaco\include\ChDibBmp.h\
	\chaco\include\ChGrVw.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChPane.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChMData.h

$(INTDIR)/ChDibBmp.obj :  $(SOURCE)  $(DEP_CHDIBB) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
# End Group
################################################################################
# Begin Group "SFImage"

################################################################################
# Begin Source File

SOURCE=.\ChSFImage.cpp
DEP_CHSFI=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChSFImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChSFImage.obj :  $(SOURCE)  $(DEP_CHSFI) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
# End Group
# End Project
################################################################################
