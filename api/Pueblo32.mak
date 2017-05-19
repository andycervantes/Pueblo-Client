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
!MESSAGE NMAKE /f "Pueblo32.mak" CFG="Win32 Debug"
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
# PROP Output_Dir "/chaco/bin/debug"
# PROP Intermediate_Dir "debug"
OUTDIR=/chaco/bin/debug
INTDIR=.\debug

ALL : $(OUTDIR)/Pueblo32.dll $(OUTDIR)/Pueblo32.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MD /W3 /GX /Z7 /Od /I "\chaco\include\\" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "_MBCS" /D "CH_EXCEPTIONS" /D "CH_USE_UNZIP" /D "CH_NOTIFY_MODULE" /Fr /Yu"headers.h" /Fp"/chaco/bin/debug/Pueblo32.pch" /c
CPP_PROJ=/nologo /G5 /MD /W3 /GX /Z7 /Od /I "\chaco\include\\" /D "_DEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D\
 "_MBCS" /D "CH_EXCEPTIONS" /D "CH_USE_UNZIP" /D "CH_NOTIFY_MODULE"\
 /Fr$(INTDIR)/ /Fp$(OUTDIR)/"Pueblo32.pch" /Yu"headers.h" /Fo$(INTDIR)/\
 /Fp"/chaco/bin/debug/Pueblo32.pch" /c 
CPP_OBJS=.\debug/
# ADD BASE RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"Pueblo.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# SUBTRACT BSC32 /nologo
BSC32_FLAGS=/o$(OUTDIR)/"Pueblo32.bsc" 
BSC32_SBRS= \
	$(INTDIR)/ChMsg.sbr \
	$(INTDIR)/ChModule.sbr \
	$(INTDIR)/headers.sbr \
	$(INTDIR)/ChDispat.sbr \
	$(INTDIR)/ChStrmbl.sbr \
	$(INTDIR)/ChUser.sbr \
	$(INTDIR)/ChConn.sbr \
	$(INTDIR)/ChReg.sbr \
	$(INTDIR)/ChMData.sbr \
	$(INTDIR)/ChData.sbr \
	$(INTDIR)/ChArch.sbr \
	$(INTDIR)/ChMsgTyp.sbr \
	$(INTDIR)/ChExcept.sbr \
	$(INTDIR)/ChSplay.sbr \
	$(INTDIR)/ChVers.sbr \
	$(INTDIR)/ChSplit.sbr \
	$(INTDIR)/ChRMenu.sbr \
	$(INTDIR)/ChMenu.sbr \
	$(INTDIR)/ChList.sbr \
	$(INTDIR)/ChHook.sbr \
	$(INTDIR)/ChTime.sbr \
	$(INTDIR)/ChScrWnd.sbr \
	$(INTDIR)/ChSock.sbr \
	$(INTDIR)/ChAcct.sbr \
	$(INTDIR)/ChClInfo.sbr \
	$(INTDIR)/ChPerFrm.sbr \
	$(INTDIR)/Pueblo.sbr \
	$(INTDIR)/ChPage.sbr \
	$(INTDIR)/ChUtil.sbr \
	$(INTDIR)/ChKeyMap.sbr \
	$(INTDIR)/ChDlg.sbr \
	$(INTDIR)/ChWType.sbr \
	$(INTDIR)/ChPane.sbr \
	$(INTDIR)/ChPblDoc.sbr \
	$(INTDIR)/ChWizard.sbr \
	$(INTDIR)/ChSocksProxy.sbr \
	$(INTDIR)/ChCore.sbr \
	$(INTDIR)/ChArgList.sbr \
	$(INTDIR)/ChPuebloScript.sbr \
	$(INTDIR)/ChHtmFrm.sbr \
	$(INTDIR)/ChHtmMsg.sbr \
	$(INTDIR)/ChHtmWnd.sbr \
	$(INTDIR)/ChTxRndr.sbr \
	$(INTDIR)/ChTxtEng.sbr \
	$(INTDIR)/ChTxtObj.sbr \
	$(INTDIR)/ChTxtWnd.sbr \
	$(INTDIR)/ChHtmSym.sbr \
	$(INTDIR)/ChPlgInMgr.sbr \
	$(INTDIR)/ChPlugInAPI.sbr \
	$(INTDIR)/ChPlgInInst.sbr \
	$(INTDIR)/ChFontElements.sbr \
	$(INTDIR)/ChHtmlTag.sbr \
	$(INTDIR)/ChPlainTag.sbr \
	$(INTDIR)/ChBodyElement.sbr \
	$(INTDIR)/ChBodyTags.sbr \
	$(INTDIR)/ChFormTags.sbr \
	$(INTDIR)/ChInlineTag.sbr \
	$(INTDIR)/ChHtmlParser.sbr \
	$(INTDIR)/ChHeadElement.sbr \
	$(INTDIR)/ChHtmlArgs.sbr \
	$(INTDIR)/ChHtmlSettings.sbr \
	$(INTDIR)/ChDefnTag.sbr \
	$(INTDIR)/ChCreateTag.sbr \
	$(INTDIR)/ChHTMLStream.sbr \
	$(INTDIR)/ChHtmlView.sbr \
	$(INTDIR)/ChHtmlFrameMgr.sbr \
	$(INTDIR)/ChHtmlPane.sbr \
	$(INTDIR)/ChPaneTag.sbr \
	$(INTDIR)/ChTxtAnimation.sbr \
	$(INTDIR)/ChHTNtfy.sbr \
	$(INTDIR)/ChHTPriv.sbr \
	$(INTDIR)/ChHTTP.sbr \
	$(INTDIR)/ChThread.sbr \
	$(INTDIR)/ChUrlMap.sbr \
	$(INTDIR)/ChHtUtil.sbr \
	$(INTDIR)/ChHttpStream.sbr \
	$(INTDIR)/ChHttpCookie.sbr \
	$(INTDIR)/ChHttpThreadMgr.sbr \
	$(INTDIR)/ChDb.sbr \
	$(INTDIR)/ChNdbm.sbr

$(OUTDIR)/Pueblo32.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /DEF:"Pueblo32.def" /IMPLIB:"Pueblo32.lib"
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 wsock32.lib lz32.lib winmm.lib version.lib \chaco\lib\PbUtil32.lib /NOLOGO /BASE:0x10000000 /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /PDB:"/chaco/bin/debug/Pueblo32.pdb" /OUT:"/chaco/bin/debug/Pueblo32.dll" /IMPLIB:"/chaco/lib/Pueblo32.lib"
LINK32_FLAGS=wsock32.lib lz32.lib winmm.lib version.lib \chaco\lib\PbUtil32.lib\
 /NOLOGO /BASE:0x10000000 /SUBSYSTEM:windows /DLL /INCREMENTAL:yes\
 /PDB:$(OUTDIR)/"Pueblo32.pdb" /DEBUG /MACHINE:I386 /DEF:".\Pueblo32.def"\
 /OUT:$(OUTDIR)/"Pueblo32.dll" /IMPLIB:$(OUTDIR)/"Pueblo32.lib"\
 /PDB:"/chaco/bin/debug/Pueblo32.pdb" /OUT:"/chaco/bin/debug/Pueblo32.dll"\
 /IMPLIB:"/chaco/lib/Pueblo32.lib"  
DEF_FILE=.\Pueblo32.def
LINK32_OBJS= \
	$(INTDIR)/ChMsg.obj \
	$(INTDIR)/ChModule.obj \
	$(INTDIR)/headers.obj \
	$(INTDIR)/ChDispat.obj \
	$(INTDIR)/ChStrmbl.obj \
	$(INTDIR)/ChUser.obj \
	$(INTDIR)/ChConn.obj \
	$(INTDIR)/ChReg.obj \
	$(INTDIR)/ChMData.obj \
	$(INTDIR)/ChData.obj \
	$(INTDIR)/ChArch.obj \
	$(INTDIR)/ChMsgTyp.obj \
	$(INTDIR)/ChExcept.obj \
	$(INTDIR)/ChSplay.obj \
	$(INTDIR)/ChVers.obj \
	$(INTDIR)/ChSplit.obj \
	$(INTDIR)/ChRMenu.obj \
	$(INTDIR)/ChMenu.obj \
	$(INTDIR)/ChList.obj \
	$(INTDIR)/ChHook.obj \
	$(INTDIR)/ChTime.obj \
	$(INTDIR)/ChScrWnd.obj \
	$(INTDIR)/ChSock.obj \
	$(INTDIR)/ChAcct.obj \
	$(INTDIR)/ChClInfo.obj \
	$(INTDIR)/ChPerFrm.obj \
	$(INTDIR)/Pueblo.obj \
	$(INTDIR)/Pueblo.res \
	$(INTDIR)/ChPage.obj \
	$(INTDIR)/ChUtil.obj \
	$(INTDIR)/ChKeyMap.obj \
	$(INTDIR)/ChDlg.obj \
	$(INTDIR)/ChWType.obj \
	$(INTDIR)/ChPane.obj \
	$(INTDIR)/ChPblDoc.obj \
	$(INTDIR)/ChWizard.obj \
	$(INTDIR)/ChSocksProxy.obj \
	$(INTDIR)/ChCore.obj \
	$(INTDIR)/ChArgList.obj \
	$(INTDIR)/ChPuebloScript.obj \
	$(INTDIR)/ChHtmFrm.obj \
	$(INTDIR)/ChHtmMsg.obj \
	$(INTDIR)/ChHtmWnd.obj \
	$(INTDIR)/ChTxRndr.obj \
	$(INTDIR)/ChTxtEng.obj \
	$(INTDIR)/ChTxtObj.obj \
	$(INTDIR)/ChTxtWnd.obj \
	$(INTDIR)/ChHtmSym.obj \
	$(INTDIR)/ChPlgInMgr.obj \
	$(INTDIR)/ChPlugInAPI.obj \
	$(INTDIR)/ChPlgInInst.obj \
	$(INTDIR)/ChFontElements.obj \
	$(INTDIR)/ChHtmlTag.obj \
	$(INTDIR)/ChPlainTag.obj \
	$(INTDIR)/ChBodyElement.obj \
	$(INTDIR)/ChBodyTags.obj \
	$(INTDIR)/ChFormTags.obj \
	$(INTDIR)/ChInlineTag.obj \
	$(INTDIR)/ChHtmlParser.obj \
	$(INTDIR)/ChHeadElement.obj \
	$(INTDIR)/ChHtmlArgs.obj \
	$(INTDIR)/ChHtmlSettings.obj \
	$(INTDIR)/ChDefnTag.obj \
	$(INTDIR)/ChCreateTag.obj \
	$(INTDIR)/ChHTMLStream.obj \
	$(INTDIR)/ChHtmlView.obj \
	$(INTDIR)/ChHtmlFrameMgr.obj \
	$(INTDIR)/ChHtmlPane.obj \
	$(INTDIR)/ChPaneTag.obj \
	$(INTDIR)/ChTxtAnimation.obj \
	$(INTDIR)/ChHTNtfy.obj \
	$(INTDIR)/ChHTPriv.obj \
	$(INTDIR)/ChHTTP.obj \
	$(INTDIR)/ChThread.obj \
	$(INTDIR)/ChUrlMap.obj \
	$(INTDIR)/ChHtUtil.obj \
	$(INTDIR)/ChHttpStream.obj \
	$(INTDIR)/ChHttpCookie.obj \
	$(INTDIR)/ChHttpThreadMgr.obj \
	$(INTDIR)/ChDb.obj \
	$(INTDIR)/ChNdbm.obj

$(OUTDIR)/Pueblo32.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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
# PROP Intermediate_Dir "release"
OUTDIR=/chaco/bin/release
INTDIR=.\release

ALL : $(OUTDIR)/Pueblo32.dll $(OUTDIR)/Pueblo32.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MD /W3 /GX /Og /Oi /Os /Oy /Ob1 /I "\chaco\include\\" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "_MBCS" /D "CH_EXCEPTIONS" /D "CH_USE_UNZIP" /D "CH_NOTIFY_MODULE" /c
# SUBTRACT CPP /YX /Ox /Oa /Ow /Fr /Yc /Yu
CPP_PROJ=/nologo /G5 /MD /W3 /GX /Og /Oi /Os /Oy /Ob1 /I "\chaco\include\\" /D\
 "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "_MBCS" /D "CH_EXCEPTIONS" /D "CH_USE_UNZIP" /D\
 "CH_NOTIFY_MODULE" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\release/
# ADD BASE RSC /l 0x0 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo$(INTDIR)/"Pueblo.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# SUBTRACT BSC32 /nologo
BSC32_FLAGS=/o$(OUTDIR)/"Pueblo32.bsc" 
BSC32_SBRS= \
	

$(OUTDIR)/Pueblo32.bsc : $(OUTDIR)  $(BSC32_SBRS)
LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386 /DEF:"Pueblo32.def" /IMPLIB:"Pueblo32.lib"
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 wsock32.lib lz32.lib winmm.lib version.lib \chaco\lib\PbUtil32.lib /NOLOGO /BASE:0x10000000 /SUBSYSTEM:windows /DLL /MACHINE:I386 /DEF:"Pueblo32.def" /PDB:"/chaco/bin/release/Pueblo32.pdb" /OUT:"/chaco/bin/release/Pueblo32.dll" /IMPLIB:"/chaco/lib/Pueblo32.lib"
LINK32_FLAGS=wsock32.lib lz32.lib winmm.lib version.lib \chaco\lib\PbUtil32.lib\
 /NOLOGO /BASE:0x10000000 /SUBSYSTEM:windows /DLL /INCREMENTAL:no\
 /PDB:$(OUTDIR)/"Pueblo32.pdb" /MACHINE:I386 /DEF:"Pueblo32.def"\
 /OUT:$(OUTDIR)/"Pueblo32.dll" /IMPLIB:$(OUTDIR)/"Pueblo32.lib"\
 /PDB:"/chaco/bin/release/Pueblo32.pdb" /OUT:"/chaco/bin/release/Pueblo32.dll"\
 /IMPLIB:"/chaco/lib/Pueblo32.lib"  
DEF_FILE=.\Pueblo32.def
LINK32_OBJS= \
	$(INTDIR)/ChMsg.obj \
	$(INTDIR)/ChModule.obj \
	$(INTDIR)/headers.obj \
	$(INTDIR)/ChDispat.obj \
	$(INTDIR)/ChStrmbl.obj \
	$(INTDIR)/ChUser.obj \
	$(INTDIR)/ChConn.obj \
	$(INTDIR)/ChReg.obj \
	$(INTDIR)/ChMData.obj \
	$(INTDIR)/ChData.obj \
	$(INTDIR)/ChArch.obj \
	$(INTDIR)/ChMsgTyp.obj \
	$(INTDIR)/ChExcept.obj \
	$(INTDIR)/ChSplay.obj \
	$(INTDIR)/ChVers.obj \
	$(INTDIR)/ChSplit.obj \
	$(INTDIR)/ChRMenu.obj \
	$(INTDIR)/ChMenu.obj \
	$(INTDIR)/ChList.obj \
	$(INTDIR)/ChHook.obj \
	$(INTDIR)/ChTime.obj \
	$(INTDIR)/ChScrWnd.obj \
	$(INTDIR)/ChSock.obj \
	$(INTDIR)/ChAcct.obj \
	$(INTDIR)/ChClInfo.obj \
	$(INTDIR)/ChPerFrm.obj \
	$(INTDIR)/Pueblo.obj \
	$(INTDIR)/Pueblo.res \
	$(INTDIR)/ChPage.obj \
	$(INTDIR)/ChUtil.obj \
	$(INTDIR)/ChKeyMap.obj \
	$(INTDIR)/ChDlg.obj \
	$(INTDIR)/ChWType.obj \
	$(INTDIR)/ChPane.obj \
	$(INTDIR)/ChPblDoc.obj \
	$(INTDIR)/ChWizard.obj \
	$(INTDIR)/ChSocksProxy.obj \
	$(INTDIR)/ChCore.obj \
	$(INTDIR)/ChArgList.obj \
	$(INTDIR)/ChPuebloScript.obj \
	$(INTDIR)/ChHtmFrm.obj \
	$(INTDIR)/ChHtmMsg.obj \
	$(INTDIR)/ChHtmWnd.obj \
	$(INTDIR)/ChTxRndr.obj \
	$(INTDIR)/ChTxtEng.obj \
	$(INTDIR)/ChTxtObj.obj \
	$(INTDIR)/ChTxtWnd.obj \
	$(INTDIR)/ChHtmSym.obj \
	$(INTDIR)/ChPlgInMgr.obj \
	$(INTDIR)/ChPlugInAPI.obj \
	$(INTDIR)/ChPlgInInst.obj \
	$(INTDIR)/ChFontElements.obj \
	$(INTDIR)/ChHtmlTag.obj \
	$(INTDIR)/ChPlainTag.obj \
	$(INTDIR)/ChBodyElement.obj \
	$(INTDIR)/ChBodyTags.obj \
	$(INTDIR)/ChFormTags.obj \
	$(INTDIR)/ChInlineTag.obj \
	$(INTDIR)/ChHtmlParser.obj \
	$(INTDIR)/ChHeadElement.obj \
	$(INTDIR)/ChHtmlArgs.obj \
	$(INTDIR)/ChHtmlSettings.obj \
	$(INTDIR)/ChDefnTag.obj \
	$(INTDIR)/ChCreateTag.obj \
	$(INTDIR)/ChHTMLStream.obj \
	$(INTDIR)/ChHtmlView.obj \
	$(INTDIR)/ChHtmlFrameMgr.obj \
	$(INTDIR)/ChHtmlPane.obj \
	$(INTDIR)/ChPaneTag.obj \
	$(INTDIR)/ChTxtAnimation.obj \
	$(INTDIR)/ChHTNtfy.obj \
	$(INTDIR)/ChHTPriv.obj \
	$(INTDIR)/ChHTTP.obj \
	$(INTDIR)/ChThread.obj \
	$(INTDIR)/ChUrlMap.obj \
	$(INTDIR)/ChHtUtil.obj \
	$(INTDIR)/ChHttpStream.obj \
	$(INTDIR)/ChHttpCookie.obj \
	$(INTDIR)/ChHttpThreadMgr.obj \
	$(INTDIR)/ChDb.obj \
	$(INTDIR)/ChNdbm.obj

$(OUTDIR)/Pueblo32.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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

SOURCE=.\ChMsg.cpp
DEP_CHMSG=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChMsg.obj :  $(SOURCE)  $(DEP_CHMSG) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChModule.cpp
DEP_CHMOD=\
	.\headers.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChMsg.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChMData.h

$(INTDIR)/ChModule.obj :  $(SOURCE)  $(DEP_CHMOD) $(INTDIR)\
 $(INTDIR)/headers.obj

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
   $(CPP) /nologo /G5 /MD /W3 /GX /Z7 /Od /I "\chaco\include\\" /D "_DEBUG" /D\
 "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D\
 "_MBCS" /D "CH_EXCEPTIONS" /D "CH_USE_UNZIP" /D "CH_NOTIFY_MODULE"\
 /Fr$(INTDIR)/ /Fp$(OUTDIR)/"Pueblo32.pch" /Yc"headers.h" /Fo$(INTDIR)/\
 /Fp"/chaco/bin/debug/Pueblo32.pch" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/headers.obj :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)
   $(CPP) /nologo /G5 /MD /W3 /GX /Og /Oi /Os /Oy /Ob1 /I "\chaco\include\\" /D\
 "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "_MBCS" /D "CH_EXCEPTIONS" /D "CH_USE_UNZIP" /D\
 "CH_NOTIFY_MODULE" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDispat.cpp
DEP_CHDIS=\
	.\headers.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChDispat.obj :  $(SOURCE)  $(DEP_CHDIS) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChStrmbl.cpp
DEP_CHSTR=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChStrmbl.obj :  $(SOURCE)  $(DEP_CHSTR) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChUser.cpp
DEP_CHUSE=\
	.\headers.h\
	\chaco\include\ChUser.h\
	\chaco\include\ChTypes.h

$(INTDIR)/ChUser.obj :  $(SOURCE)  $(DEP_CHUSE) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChConn.cpp
DEP_CHCON=\
	.\headers.h\
	\chaco\include\ChConn.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChTypes.h\
	\chaco\include\SocketXX.h\
	\chaco\include\protocol.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChVers.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChSplay.h\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChConn.obj :  $(SOURCE)  $(DEP_CHCON) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChReg.cpp
DEP_CHREG=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChList.h\
	\chaco\include\ChDb.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChReg.obj :  $(SOURCE)  $(DEP_CHREG) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMData.cpp
DEP_CHMDA=\
	.\headers.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChData.h

$(INTDIR)/ChMData.obj :  $(SOURCE)  $(DEP_CHMDA) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChData.cpp
DEP_CHDAT=\
	.\headers.h\
	\chaco\include\ChData.h\
	\chaco\include\ChTypes.h

$(INTDIR)/ChData.obj :  $(SOURCE)  $(DEP_CHDAT) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChArch.cpp
DEP_CHARC=\
	.\headers.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChArch.obj :  $(SOURCE)  $(DEP_CHARC) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMsgTyp.cpp
DEP_CHMSGT=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChGraphx.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChList.h\
	\chaco\include\ChData.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChMsgTyp.obj :  $(SOURCE)  $(DEP_CHMSGT) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChExcept.cpp
DEP_CHEXC=\
	.\headers.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChTypes.h

$(INTDIR)/ChExcept.obj :  $(SOURCE)  $(DEP_CHEXC) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSplay.cpp
DEP_CHSPL=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChSplay.h

$(INTDIR)/ChSplay.obj :  $(SOURCE)  $(DEP_CHSPL) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChVers.cpp
DEP_CHVER=\
	.\headers.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChVers.obj :  $(SOURCE)  $(DEP_CHVER) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSplit.cpp
DEP_CHSPLI=\
	.\headers.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChSplit.h\
	\chaco\include\ChPane.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChDb.h\
	\chaco\include\ChMData.h

$(INTDIR)/ChSplit.obj :  $(SOURCE)  $(DEP_CHSPLI) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRMenu.cpp
DEP_CHRME=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChMenu.h\
	\chaco\include\ChRMenu.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChMnPtrl.h\
	\chaco\include\templcls\ChMnPtrl.inl\
	\chaco\include\templcls\ChMnItem.h\
	\chaco\include\templcls\ChMnMap.h\
	\chaco\include\templcls\ChMnList.h\
	\chaco\include\templcls\ChMnList.inl\
	\chaco\include\templcls\ChMnBlk.h\
	\chaco\include\templcls\ChMnBlk.inl\
	\chaco\include\templcls\ChMItSpl.h\
	\chaco\include\templcls\ChMnSply.h\
	\chaco\include\templcls\ChMnItLs.h\
	\chaco\include\templcls\ChMnItLs.inl\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChModule.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChSplay.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h

$(INTDIR)/ChRMenu.obj :  $(SOURCE)  $(DEP_CHRME) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMenu.cpp
DEP_CHMEN=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChMenu.h\
	\chaco\include\ChRMenu.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChMnPtrl.h\
	\chaco\include\templcls\ChMnPtrl.inl\
	\chaco\include\templcls\ChMnItem.h\
	\chaco\include\templcls\ChMnMap.h\
	\chaco\include\templcls\ChMnList.h\
	\chaco\include\templcls\ChMnList.inl\
	\chaco\include\templcls\ChMnBlk.h\
	\chaco\include\templcls\ChMnBlk.inl\
	\chaco\include\templcls\ChMItSpl.h\
	\chaco\include\templcls\ChMnSply.h\
	\chaco\include\templcls\ChMnItLs.h\
	\chaco\include\templcls\ChMnItLs.inl\
	\chaco\include\templcls\ChStrLst.h\
	\chaco\include\templcls\ChStrLst.inl\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChSplay.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChData.h\
	\chaco\include\ChHook.h

$(INTDIR)/ChMenu.obj :  $(SOURCE)  $(DEP_CHMEN) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChList.cpp
DEP_CHLIS=\
	.\headers.h\
	\chaco\include\ChList.h\
	\chaco\include\ChTypes.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChList.obj :  $(SOURCE)  $(DEP_CHLIS) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHook.cpp
DEP_CHHOO=\
	.\headers.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChMData.h

$(INTDIR)/ChHook.obj :  $(SOURCE)  $(DEP_CHHOO) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTime.cpp
DEP_CHTIM=\
	.\headers.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChData.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\Values.h\
	\chaco\include\ChTypes.h

$(INTDIR)/ChTime.obj :  $(SOURCE)  $(DEP_CHTIM) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChScrWnd.cpp
DEP_CHSCR=\
	.\headers.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChList.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h\
	\chaco\include\ChMData.h

$(INTDIR)/ChScrWnd.obj :  $(SOURCE)  $(DEP_CHSCR) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSock.cpp
DEP_CHSOC=\
	.\headers.h\
	\chaco\include\ChSock.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChDb.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChSock.obj :  $(SOURCE)  $(DEP_CHSOC) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAcct.cpp
DEP_CHACC=\
	.\headers.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChAcct.obj :  $(SOURCE)  $(DEP_CHACC) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChClInfo.cpp
DEP_CHCLI=\
	.\headers.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h

$(INTDIR)/ChClInfo.obj :  $(SOURCE)  $(DEP_CHCLI) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPerFrm.cpp
DEP_CHPER=\
	.\headers.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChTypes.h

$(INTDIR)/ChPerFrm.obj :  $(SOURCE)  $(DEP_CHPER) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo32.def
# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo.cpp
DEP_PUEBL=\
	.\headers.h\
	\chaco\include\ChTypes.h

$(INTDIR)/Pueblo.obj :  $(SOURCE)  $(DEP_PUEBL) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo.rc
DEP_PUEBLO=\
	.\res\colsplit.cur\
	.\res\hotspot.cur\
	.\res\rowsplit.cur\
	.\res\book.ico\
	.\res\scroll.ico\
	.\res\map.ico\
	.\res\book_log.ico\
	.\res\Pueblo.rc2

$(INTDIR)/Pueblo.res :  $(SOURCE)  $(DEP_PUEBLO) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPage.cpp
DEP_CHPAG=\
	.\headers.h\
	\chaco\include\ChPage.h\
	\chaco\include\ChTypes.h

$(INTDIR)/ChPage.obj :  $(SOURCE)  $(DEP_CHPAG) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChUtil.cpp
DEP_CHUTI=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChUtil.obj :  $(SOURCE)  $(DEP_CHUTI) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChKeyMap.cpp
DEP_CHKEY=\
	.\headers.h\
	\chaco\include\ChKeyMap.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChList.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChKeyMap.obj :  $(SOURCE)  $(DEP_CHKEY) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDlg.cpp
DEP_CHDLG=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDlg.h

$(INTDIR)/ChDlg.obj :  $(SOURCE)  $(DEP_CHDLG) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWType.cpp
DEP_CHWTY=\
	.\headers.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChWType.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChWType.obj :  $(SOURCE)  $(DEP_CHWTY) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPane.cpp
DEP_CHPAN=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChPane.h\
	\chaco\include\ChSplit.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChMData.h

$(INTDIR)/ChPane.obj :  $(SOURCE)  $(DEP_CHPAN) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPblDoc.cpp
DEP_CHPBL=\
	.\headers.h\
	\chaco\include\ChPblDoc.h\
	\chaco\include\ChTypes.h

$(INTDIR)/ChPblDoc.obj :  $(SOURCE)  $(DEP_CHPBL) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWizard.cpp
DEP_CHWIZ=\
	.\headers.h\
	\chaco\include\ChWizard.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChMData.h

$(INTDIR)/ChWizard.obj :  $(SOURCE)  $(DEP_CHWIZ) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSocksProxy.cpp
DEP_CHSOCK=\
	.\headers.h\
	\chaco\include\ChSock.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChSplay.h

$(INTDIR)/ChSocksProxy.obj :  $(SOURCE)  $(DEP_CHSOCK) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChCore.cpp
DEP_CHCOR=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChDispat.h\
	\chaco\include\ChCore.h\
	\chaco\include\ChMsgTyp.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChPane.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChClInfo.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPerFrm.h\
	\chaco\include\ChMData.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChArch.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChAcct.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChData.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChCore.obj :  $(SOURCE)  $(DEP_CHCOR) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChArgList.cpp
DEP_CHARG=\
	.\headers.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChArgList.obj :  $(SOURCE)  $(DEP_CHARG) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPuebloScript.cpp
DEP_CHPUE=\
	.\headers.h\
	\chaco\include\ChPuebloScript.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChPuebloScript.obj :  $(SOURCE)  $(DEP_CHPUE) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
# End Group
################################################################################
# Begin Group "HTML"

################################################################################
# Begin Source File

SOURCE=.\ChHtmFrm.cpp
DEP_CHHTM=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChHtmlSettings.h\
	.\chhtmlview.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChList.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChHtmFrm.obj :  $(SOURCE)  $(DEP_CHHTM) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmMsg.cpp
DEP_CHHTMM=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChHtmWnd.h\
	.\chhtmlview.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChHtpCon.h\
	.\ChPlgInMgr.h\
	\chaco\include\ChHtmlSettings.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChHTMLStream.h\
	\chaco\include\ChList.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	.\ChPlgInAPI.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChHtmMsg.obj :  $(SOURCE)  $(DEP_CHHTMM) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmWnd.cpp
DEP_CHHTMW=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChConst.h\
	.\ChHTMLStream.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChHtmlSettings.h\
	.\chhtmlview.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChHtmlPane.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChList.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChHtmWnd.obj :  $(SOURCE)  $(DEP_CHHTMW) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTxRndr.cpp
DEP_CHTXR=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChImgUtil.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChList.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChTxRndr.obj :  $(SOURCE)  $(DEP_CHTXR) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTxtEng.cpp
DEP_CHTXT=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChTxtEng.obj :  $(SOURCE)  $(DEP_CHTXT) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTxtObj.cpp
DEP_CHTXTO=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChImgUtil.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChTxtWnd.h\
	.\ChPlgInMgr.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChList.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChSplay.h\
	.\ChPlgInAPI.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChTxtObj.obj :  $(SOURCE)  $(DEP_CHTXTO) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTxtWnd.cpp
DEP_CHTXTW=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChImgUtil.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChList.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChTxtWnd.obj :  $(SOURCE)  $(DEP_CHTXTW) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmSym.cpp
DEP_CHHTMS=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	.\chhtmlview.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChWnd.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChHtmSym.obj :  $(SOURCE)  $(DEP_CHHTMS) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPlgInMgr.cpp
DEP_CHPLG=\
	.\headers.h\
	\chaco\include\ChUtil.h\
	.\chhtmlview.h\
	\chaco\include\ChHTTP.h\
	.\ChPlgInMgr.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChList.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	.\ChPlgInAPI.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChPlgInMgr.obj :  $(SOURCE)  $(DEP_CHPLG) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPlugInAPI.cpp
DEP_CHPLU=\
	.\headers.h\
	\chaco\include\ChHtmWnd.h\
	.\chhtmlview.h\
	.\ChPlgInMgr.h\
	.\ChPlgInAPI.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChList.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChPlugInAPI.obj :  $(SOURCE)  $(DEP_CHPLU) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPlgInInst.cpp
DEP_CHPLGI=\
	.\headers.h\
	\chaco\include\ChArgList.h\
	.\chhtmlview.h\
	.\ChPlgInMgr.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChList.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	.\ChPlgInAPI.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChPlgInInst.obj :  $(SOURCE)  $(DEP_CHPLGI) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChFontElements.cpp
DEP_CHFON=\
	.\headers.h\
	\chaco\include\ChHtmlSettings.h\
	.\chhtmlview.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChFontElements.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	.\ChBodyElement.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChWnd.h\
	.\ChHtmlTag.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChFontElements.obj :  $(SOURCE)  $(DEP_CHFON) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlTag.cpp
DEP_CHHTML=\
	.\headers.h\
	.\chhtmlview.h\
	\chaco\include\ChHtmlSettings.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChHtmlTag.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChWnd.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChHtmlTag.obj :  $(SOURCE)  $(DEP_CHHTML) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPlainTag.cpp
DEP_CHPLA=\
	.\headers.h\
	.\chhtmlview.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChPlainTag.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	.\ChHtmlTag.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChWnd.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChPlainTag.obj :  $(SOURCE)  $(DEP_CHPLA) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChBodyElement.cpp
DEP_CHBOD=\
	.\headers.h\
	.\chhtmlview.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChBodyElement.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	.\ChHtmlTag.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChWnd.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChBodyElement.obj :  $(SOURCE)  $(DEP_CHBOD) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChBodyTags.cpp
DEP_CHBODY=\
	.\headers.h\
	\chaco\include\ChHtmWnd.h\
	.\chhtmlview.h\
	\chaco\include\ChHtmlSettings.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChBodyTags.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChList.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	.\ChBodyElement.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChWnd.h\
	.\ChHtmlTag.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChBodyTags.obj :  $(SOURCE)  $(DEP_CHBODY) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChFormTags.cpp
DEP_CHFOR=\
	.\headers.h\
	\chaco\include\ChHtmWnd.h\
	.\chhtmlview.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChFormTags.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChList.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	.\ChBodyElement.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChWnd.h\
	.\ChHtmlTag.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChFormTags.obj :  $(SOURCE)  $(DEP_CHFOR) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChInlineTag.cpp
DEP_CHINL=\
	.\headers.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChHtmlSettings.h\
	\chaco\include\ChArgList.h\
	\chaco\include\ChHtmWnd.h\
	.\chhtmlview.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChInlineTags.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChList.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	.\ChHtmlTag.h\
	.\ChBodyElement.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChInlineTag.obj :  $(SOURCE)  $(DEP_CHINL) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlParser.cpp
DEP_CHHTMLP=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChHtmWnd.h\
	.\chhtmlview.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChHtmlSettings.h\
	\chaco\include\ChArgList.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChHtmlTag.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChList.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	\chaco\include\ChDb.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChHtmlParser.obj :  $(SOURCE)  $(DEP_CHHTMLP) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHeadElement.cpp
DEP_CHHEA=\
	.\headers.h\
	.\chhtmlview.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChHeadElement.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	.\ChHtmlTag.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChWnd.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChHeadElement.obj :  $(SOURCE)  $(DEP_CHHEA) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlArgs.cpp
DEP_CHHTMLA=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChArgList.h\
	.\chhtmlview.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChList.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChHtmlArgs.obj :  $(SOURCE)  $(DEP_CHHTMLA) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlSettings.cpp
DEP_CHHTMLS=\
	.\headers.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChHtmlSettings.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDb.h

$(INTDIR)/ChHtmlSettings.obj :  $(SOURCE)  $(DEP_CHHTMLS) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDefnTag.cpp
DEP_CHDEF=\
	.\headers.h\
	\chaco\include\ChHtmlSettings.h\
	.\chhtmlview.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChDefnTag.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	.\ChBodyElement.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChWnd.h\
	.\ChHtmlTag.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChDefnTag.obj :  $(SOURCE)  $(DEP_CHDEF) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChCreateTag.cpp
DEP_CHCRE=\
	.\headers.h\
	.\chhtmlview.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChHeadElement.h\
	.\ChBodyElement.h\
	.\ChBodyTags.h\
	.\ChFontElements.h\
	.\ChFormTags.h\
	.\ChInlineTags.h\
	.\ChPlainTag.h\
	.\ChDefnTag.h\
	.\ChPaneTag.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	.\ChHtmlTag.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChWnd.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChCreateTag.obj :  $(SOURCE)  $(DEP_CHCRE) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHTMLStream.cpp
DEP_CHHTMLST=\
	.\headers.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChDibDecoder.h\
	\chaco\include\ChGifDecoder.h\
	\chaco\include\ChJpegDecoder.h\
	\chaco\include\ChPane.h\
	.\chhtmlview.h\
	\chaco\include\ChTxtObj.h\
	.\ChPlgInMgr.h\
	.\ChHTMLStream.h\
	.\ChHtmlPane.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChList.h\
	\chaco\include\ChImgConsumer.h\
	\chaco\include\ChImageDecoder.h\
	\chaco\include\jpeglib.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	.\ChPlgInAPI.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\jconfig.h\
	\chaco\include\jmorecfg.h\
	\chaco\include\ChSize.h

$(INTDIR)/ChHTMLStream.obj :  $(SOURCE)  $(DEP_CHHTMLST) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlView.cpp
DEP_CHHTMLV=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChHtmlSettings.h\
	.\ChHTMLStream.h\
	.\chhtmlview.h\
	.\ChPlgInMgr.h\
	.\ChHtmlPane.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChList.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	.\ChPlgInAPI.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChHtmlView.obj :  $(SOURCE)  $(DEP_CHHTMLV) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlFrameMgr.cpp
DEP_CHHTMLF=\
	.\headers.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChPane.h\
	.\chhtmlview.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChHtmlFrameMgr.obj :  $(SOURCE)  $(DEP_CHHTMLF) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlPane.cpp
DEP_CHHTMLPA=\
	.\headers.h\
	\chaco\include\ChModule.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChPane.h\
	.\chhtmlview.h\
	.\ChHTMLStream.h\
	.\ChHtmlPane.h\
	.\ChHtmSym.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChMsg.h\
	\chaco\include\ChHook.h\
	\chaco\include\ChList.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChMData.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChData.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChHtmlPane.obj :  $(SOURCE)  $(DEP_CHHTMLPA) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPaneTag.cpp
DEP_CHPANE=\
	.\headers.h\
	\chaco\include\ChHtmWnd.h\
	\chaco\include\ChHtmlSettings.h\
	.\chhtmlview.h\
	.\ChHtmSym.h\
	.\ChHtmlParser.h\
	.\ChHtmlPane.h\
	.\ChPaneTag.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChList.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChPane.h\
	.\ChHtmFrm.h\
	\chaco\include\templcls\ChPstrLs.h\
	\chaco\include\templcls\ChHtFmLs.h\
	\chaco\include\templcls\ChHtFmLs.inl\
	\chaco\include\templcls\ChFechLs.h\
	\chaco\include\templcls\ChFechLs.inl\
	\chaco\include\templcls\ChHtmspl.h\
	.\ChHtmlTag.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChWnd.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChPaneTag.obj :  $(SOURCE)  $(DEP_CHPANE) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTxtAnimation.cpp
DEP_CHTXTA=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChRect.h\
	\chaco\include\ChSize.h\
	\chaco\include\ChScrlVw.h\
	\chaco\include\ChDC.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChTxtWnd.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChImgUtil.h\
	\chaco\include\ChFont.h\
	\chaco\include\ChScrWnd.h\
	\chaco\include\ChTxtObj.h\
	\chaco\include\ChList.h\
	\chaco\include\ChDibImage.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChImgConsumer.h

$(INTDIR)/ChTxtAnimation.obj :  $(SOURCE)  $(DEP_CHTXTA) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
# End Group
################################################################################
# Begin Group "HTTP"

################################################################################
# Begin Source File

SOURCE=.\ChHTNtfy.cpp
DEP_CHHTN=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChDb.h\
	\chaco\include\SocketXX.h\
	.\ChHTPriv.h\
	.\ChHttpThreadMgr.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChList.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\templcls\ChHtpspl.h\
	\chaco\include\templcls\ChHTPLst.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\templcls\ChSockBf.h

$(INTDIR)/ChHTNtfy.obj :  $(SOURCE)  $(DEP_CHHTN) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHTPriv.cpp
DEP_CHHTP=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChDb.h\
	\chaco\include\SocketXX.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChConst.h\
	\chaco\include\ChExcept.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChUnzip.h\
	.\ChHttpCookie.h\
	.\ChHTPriv.h\
	.\ChHttpThreadMgr.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\ChList.h\
	\chaco\include\unzip.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChSplay.h\
	\chaco\include\templcls\ChHtpspl.h\
	\chaco\include\templcls\ChHTPLst.h\
	\chaco\include\templcls\ChSockBf.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChHTPriv.obj :  $(SOURCE)  $(DEP_CHHTP) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHTTP.cpp
DEP_CHHTT=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChDb.h\
	\chaco\include\ChReg.h\
	\chaco\include\ChConst.h\
	\chaco\include\SocketXX.h\
	\chaco\include\ChClInfo.h\
	.\ChHttpCookie.h\
	.\ChHttpThreadMgr.h\
	\chaco\include\ChUtil.h\
	.\ChHTPriv.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\ChData.h\
	\chaco\include\ChStrmbl.h\
	\chaco\include\ChVers.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\templcls\ChHtpspl.h\
	\chaco\include\templcls\ChHTPLst.h\
	\chaco\include\templcls\ChSockBf.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChHTTP.obj :  $(SOURCE)  $(DEP_CHHTT) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChThread.cpp
DEP_CHTHR=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChDb.h\
	\chaco\include\SocketXX.h\
	\chaco\include\ChSock.h\
	\chaco\include\ChUtil.h\
	.\ChHTPriv.h\
	.\ChHttpThreadMgr.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\templcls\ChHtpspl.h\
	\chaco\include\templcls\ChHTPLst.h\
	\chaco\include\templcls\ChSockBf.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChThread.obj :  $(SOURCE)  $(DEP_CHTHR) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChUrlMap.cpp
DEP_CHURL=\
	.\headers.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChSplay.h

$(INTDIR)/ChUrlMap.obj :  $(SOURCE)  $(DEP_CHURL) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtUtil.cpp
DEP_CHHTU=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChList.h\
	\chaco\include\ChSplay.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChHtUtil.obj :  $(SOURCE)  $(DEP_CHHTU) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHttpStream.cpp
DEP_CHHTTP=\
	.\headers.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\SocketXX.h\
	.\ChHTPriv.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSock.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\templcls\ChHtpspl.h\
	\chaco\include\templcls\ChHTPLst.h\
	\chaco\include\templcls\ChSockBf.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChHttpStream.obj :  $(SOURCE)  $(DEP_CHHTTP) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHttpCookie.cpp
DEP_CHHTTPC=\
	.\headers.h\
	\chaco\include\ChUtil.h\
	\chaco\include\ChUrlMap.h\
	.\ChHttpCookie.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChList.h\
	\chaco\include\ChTime.h\
	\chaco\include\ChSplay.h\
	\chaco\include\templcls\ChLstHlp.inl\
	\chaco\include\ChStrmbl.h

$(INTDIR)/ChHttpCookie.obj :  $(SOURCE)  $(DEP_CHHTTPC) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHttpThreadMgr.cpp
DEP_CHHTTPT=\
	.\headers.h\
	\chaco\include\ChHtpCon.h\
	\chaco\include\ChDb.h\
	\chaco\include\SocketXX.h\
	\chaco\include\ChSock.h\
	.\ChHTPriv.h\
	.\ChHttpThreadMgr.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChHTTP.h\
	\chaco\include\ChUrlMap.h\
	\chaco\include\sockstrm.h\
	\chaco\include\sockinet.h\
	\chaco\include\ChSplay.h\
	\chaco\include\ChList.h\
	\chaco\include\ChHttpStream.h\
	\chaco\include\templcls\ChHtpspl.h\
	\chaco\include\templcls\ChHTPLst.h\
	\chaco\include\templcls\ChSockBf.h\
	\chaco\include\templcls\ChLstHlp.inl

$(INTDIR)/ChHttpThreadMgr.obj :  $(SOURCE)  $(DEP_CHHTTPT) $(INTDIR)\
 $(INTDIR)/headers.obj

# End Source File
# End Group
################################################################################
# Begin Group "DataBase"

################################################################################
# Begin Source File

SOURCE=.\ChDb.cpp
DEP_CHDB_=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	\chaco\include\ChDb.h\
	.\ChNdbm.h

$(INTDIR)/ChDb.obj :  $(SOURCE)  $(DEP_CHDB_) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChNdbm.cpp
DEP_CHNDB=\
	.\headers.h\
	\chaco\include\ChTypes.h\
	.\ChNdbm.h

$(INTDIR)/ChNdbm.obj :  $(SOURCE)  $(DEP_CHNDB) $(INTDIR) $(INTDIR)/headers.obj

# End Source File
# End Group
# End Project
################################################################################
