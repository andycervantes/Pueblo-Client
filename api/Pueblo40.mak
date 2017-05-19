# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=Pueblo40 - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Pueblo40 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Pueblo40 - Win32 Release" && "$(CFG)" !=\
 "Pueblo40 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Pueblo40.mak" CFG="Pueblo40 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Pueblo40 - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Pueblo40 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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
# PROP Target_Last_Scanned "Pueblo40 - Win32 Release"
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "Pueblo40 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\bin\release\Pueblo32.dll"

CLEAN : 
	-@erase "$(INTDIR)\ChAcct.obj"
	-@erase "$(INTDIR)\ChArch.obj"
	-@erase "$(INTDIR)\ChArgList.obj"
	-@erase "$(INTDIR)\ChBodyElement.obj"
	-@erase "$(INTDIR)\ChBodyTags.obj"
	-@erase "$(INTDIR)\ChClInfo.obj"
	-@erase "$(INTDIR)\ChConn.obj"
	-@erase "$(INTDIR)\ChCore.obj"
	-@erase "$(INTDIR)\ChCreateTag.obj"
	-@erase "$(INTDIR)\ChData.obj"
	-@erase "$(INTDIR)\ChDb.obj"
	-@erase "$(INTDIR)\ChDefnTag.obj"
	-@erase "$(INTDIR)\ChDispat.obj"
	-@erase "$(INTDIR)\ChDlg.obj"
	-@erase "$(INTDIR)\ChExcept.obj"
	-@erase "$(INTDIR)\ChFontElements.obj"
	-@erase "$(INTDIR)\ChFormTags.obj"
	-@erase "$(INTDIR)\ChHeadElement.obj"
	-@erase "$(INTDIR)\ChHook.obj"
	-@erase "$(INTDIR)\ChHtmFrm.obj"
	-@erase "$(INTDIR)\ChHtmlArgs.obj"
	-@erase "$(INTDIR)\ChHtmlFrameMgr.obj"
	-@erase "$(INTDIR)\ChHtmlPane.obj"
	-@erase "$(INTDIR)\ChHtmlParser.obj"
	-@erase "$(INTDIR)\ChHtmlSettings.obj"
	-@erase "$(INTDIR)\ChHTMLStream.obj"
	-@erase "$(INTDIR)\ChHtmlTag.obj"
	-@erase "$(INTDIR)\ChHtmlView.obj"
	-@erase "$(INTDIR)\ChHtmMsg.obj"
	-@erase "$(INTDIR)\ChHtmSym.obj"
	-@erase "$(INTDIR)\ChHtmWnd.obj"
	-@erase "$(INTDIR)\ChHTNtfy.obj"
	-@erase "$(INTDIR)\ChHTPriv.obj"
	-@erase "$(INTDIR)\ChHTTP.obj"
	-@erase "$(INTDIR)\ChHttpCookie.obj"
	-@erase "$(INTDIR)\ChHttpStream.obj"
	-@erase "$(INTDIR)\ChHttpThreadMgr.obj"
	-@erase "$(INTDIR)\ChHtUtil.obj"
	-@erase "$(INTDIR)\ChInlineTag.obj"
	-@erase "$(INTDIR)\ChKeyMap.obj"
	-@erase "$(INTDIR)\ChList.obj"
	-@erase "$(INTDIR)\ChMData.obj"
	-@erase "$(INTDIR)\ChMenu.obj"
	-@erase "$(INTDIR)\ChModule.obj"
	-@erase "$(INTDIR)\ChMsg.obj"
	-@erase "$(INTDIR)\ChMsgTyp.obj"
	-@erase "$(INTDIR)\ChNdbm.obj"
	-@erase "$(INTDIR)\ChPage.obj"
	-@erase "$(INTDIR)\ChPane.obj"
	-@erase "$(INTDIR)\ChPaneTag.obj"
	-@erase "$(INTDIR)\ChPblDoc.obj"
	-@erase "$(INTDIR)\ChPerFrm.obj"
	-@erase "$(INTDIR)\ChPlainTag.obj"
	-@erase "$(INTDIR)\ChPlgInInst.obj"
	-@erase "$(INTDIR)\ChPlgInMgr.obj"
	-@erase "$(INTDIR)\ChPlugInAPI.obj"
	-@erase "$(INTDIR)\ChPuebloScript.obj"
	-@erase "$(INTDIR)\ChReg.obj"
	-@erase "$(INTDIR)\ChRMenu.obj"
	-@erase "$(INTDIR)\ChScrWnd.obj"
	-@erase "$(INTDIR)\ChSock.obj"
	-@erase "$(INTDIR)\ChSocksProxy.obj"
	-@erase "$(INTDIR)\ChSplay.obj"
	-@erase "$(INTDIR)\ChSplit.obj"
	-@erase "$(INTDIR)\ChStrmbl.obj"
	-@erase "$(INTDIR)\ChThread.obj"
	-@erase "$(INTDIR)\ChTime.obj"
	-@erase "$(INTDIR)\ChTxRndr.obj"
	-@erase "$(INTDIR)\ChTxtAnimation.obj"
	-@erase "$(INTDIR)\ChTxtEng.obj"
	-@erase "$(INTDIR)\ChTxtObj.obj"
	-@erase "$(INTDIR)\ChTxtWnd.obj"
	-@erase "$(INTDIR)\ChUrlMap.obj"
	-@erase "$(INTDIR)\ChUtil.obj"
	-@erase "$(INTDIR)\ChVers.obj"
	-@erase "$(INTDIR)\ChWizard.obj"
	-@erase "$(INTDIR)\ChWType.obj"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(INTDIR)\Pueblo.obj"
	-@erase "$(INTDIR)\Pueblo.res"
	-@erase "$(INTDIR)\Pueblo40.pch"
	-@erase "..\bin\release\Pueblo32.dll"
	-@erase "..\lib\Pueblo32.exp"
	-@erase "..\lib\Pueblo32.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /Yu"headers.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D\
 "CH_EXCEPTIONS" /Fp"$(INTDIR)/Pueblo40.pch" /Yu"headers.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Pueblo.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Pueblo40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 wsock32.lib lz32.lib winmm.lib version.lib \chaco\lib\PbUtil32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"\chaco\bin\release/Pueblo32.dll" /implib:"\chaco\lib/Pueblo32.lib"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=wsock32.lib lz32.lib winmm.lib version.lib \chaco\lib\PbUtil32.lib\
 /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)/Pueblo32.pdb"\
 /machine:I386 /def:".\Pueblo32.def" /out:"\chaco\bin\release/Pueblo32.dll"\
 /implib:"\chaco\lib/Pueblo32.lib" 
DEF_FILE= \
	".\Pueblo32.def"
LINK32_OBJS= \
	"$(INTDIR)\ChAcct.obj" \
	"$(INTDIR)\ChArch.obj" \
	"$(INTDIR)\ChArgList.obj" \
	"$(INTDIR)\ChBodyElement.obj" \
	"$(INTDIR)\ChBodyTags.obj" \
	"$(INTDIR)\ChClInfo.obj" \
	"$(INTDIR)\ChConn.obj" \
	"$(INTDIR)\ChCore.obj" \
	"$(INTDIR)\ChCreateTag.obj" \
	"$(INTDIR)\ChData.obj" \
	"$(INTDIR)\ChDb.obj" \
	"$(INTDIR)\ChDefnTag.obj" \
	"$(INTDIR)\ChDispat.obj" \
	"$(INTDIR)\ChDlg.obj" \
	"$(INTDIR)\ChExcept.obj" \
	"$(INTDIR)\ChFontElements.obj" \
	"$(INTDIR)\ChFormTags.obj" \
	"$(INTDIR)\ChHeadElement.obj" \
	"$(INTDIR)\ChHook.obj" \
	"$(INTDIR)\ChHtmFrm.obj" \
	"$(INTDIR)\ChHtmlArgs.obj" \
	"$(INTDIR)\ChHtmlFrameMgr.obj" \
	"$(INTDIR)\ChHtmlPane.obj" \
	"$(INTDIR)\ChHtmlParser.obj" \
	"$(INTDIR)\ChHtmlSettings.obj" \
	"$(INTDIR)\ChHTMLStream.obj" \
	"$(INTDIR)\ChHtmlTag.obj" \
	"$(INTDIR)\ChHtmlView.obj" \
	"$(INTDIR)\ChHtmMsg.obj" \
	"$(INTDIR)\ChHtmSym.obj" \
	"$(INTDIR)\ChHtmWnd.obj" \
	"$(INTDIR)\ChHTNtfy.obj" \
	"$(INTDIR)\ChHTPriv.obj" \
	"$(INTDIR)\ChHTTP.obj" \
	"$(INTDIR)\ChHttpCookie.obj" \
	"$(INTDIR)\ChHttpStream.obj" \
	"$(INTDIR)\ChHttpThreadMgr.obj" \
	"$(INTDIR)\ChHtUtil.obj" \
	"$(INTDIR)\ChInlineTag.obj" \
	"$(INTDIR)\ChKeyMap.obj" \
	"$(INTDIR)\ChList.obj" \
	"$(INTDIR)\ChMData.obj" \
	"$(INTDIR)\ChMenu.obj" \
	"$(INTDIR)\ChModule.obj" \
	"$(INTDIR)\ChMsg.obj" \
	"$(INTDIR)\ChMsgTyp.obj" \
	"$(INTDIR)\ChNdbm.obj" \
	"$(INTDIR)\ChPage.obj" \
	"$(INTDIR)\ChPane.obj" \
	"$(INTDIR)\ChPaneTag.obj" \
	"$(INTDIR)\ChPblDoc.obj" \
	"$(INTDIR)\ChPerFrm.obj" \
	"$(INTDIR)\ChPlainTag.obj" \
	"$(INTDIR)\ChPlgInInst.obj" \
	"$(INTDIR)\ChPlgInMgr.obj" \
	"$(INTDIR)\ChPlugInAPI.obj" \
	"$(INTDIR)\ChPuebloScript.obj" \
	"$(INTDIR)\ChReg.obj" \
	"$(INTDIR)\ChRMenu.obj" \
	"$(INTDIR)\ChScrWnd.obj" \
	"$(INTDIR)\ChSock.obj" \
	"$(INTDIR)\ChSocksProxy.obj" \
	"$(INTDIR)\ChSplay.obj" \
	"$(INTDIR)\ChSplit.obj" \
	"$(INTDIR)\ChStrmbl.obj" \
	"$(INTDIR)\ChThread.obj" \
	"$(INTDIR)\ChTime.obj" \
	"$(INTDIR)\ChTxRndr.obj" \
	"$(INTDIR)\ChTxtAnimation.obj" \
	"$(INTDIR)\ChTxtEng.obj" \
	"$(INTDIR)\ChTxtObj.obj" \
	"$(INTDIR)\ChTxtWnd.obj" \
	"$(INTDIR)\ChUrlMap.obj" \
	"$(INTDIR)\ChUtil.obj" \
	"$(INTDIR)\ChVers.obj" \
	"$(INTDIR)\ChWizard.obj" \
	"$(INTDIR)\ChWType.obj" \
	"$(INTDIR)\headers.obj" \
	"$(INTDIR)\Pueblo.obj" \
	"$(INTDIR)\Pueblo.res"

"..\bin\release\Pueblo32.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Pueblo40 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\bin\Debug\Pueblo32.dll"

CLEAN : 
	-@erase "$(INTDIR)\ChAcct.obj"
	-@erase "$(INTDIR)\ChArch.obj"
	-@erase "$(INTDIR)\ChArgList.obj"
	-@erase "$(INTDIR)\ChBodyElement.obj"
	-@erase "$(INTDIR)\ChBodyTags.obj"
	-@erase "$(INTDIR)\ChClInfo.obj"
	-@erase "$(INTDIR)\ChConn.obj"
	-@erase "$(INTDIR)\ChCore.obj"
	-@erase "$(INTDIR)\ChCreateTag.obj"
	-@erase "$(INTDIR)\ChData.obj"
	-@erase "$(INTDIR)\ChDb.obj"
	-@erase "$(INTDIR)\ChDefnTag.obj"
	-@erase "$(INTDIR)\ChDispat.obj"
	-@erase "$(INTDIR)\ChDlg.obj"
	-@erase "$(INTDIR)\ChExcept.obj"
	-@erase "$(INTDIR)\ChFontElements.obj"
	-@erase "$(INTDIR)\ChFormTags.obj"
	-@erase "$(INTDIR)\ChHeadElement.obj"
	-@erase "$(INTDIR)\ChHook.obj"
	-@erase "$(INTDIR)\ChHtmFrm.obj"
	-@erase "$(INTDIR)\ChHtmlArgs.obj"
	-@erase "$(INTDIR)\ChHtmlFrameMgr.obj"
	-@erase "$(INTDIR)\ChHtmlPane.obj"
	-@erase "$(INTDIR)\ChHtmlParser.obj"
	-@erase "$(INTDIR)\ChHtmlSettings.obj"
	-@erase "$(INTDIR)\ChHTMLStream.obj"
	-@erase "$(INTDIR)\ChHtmlTag.obj"
	-@erase "$(INTDIR)\ChHtmlView.obj"
	-@erase "$(INTDIR)\ChHtmMsg.obj"
	-@erase "$(INTDIR)\ChHtmSym.obj"
	-@erase "$(INTDIR)\ChHtmWnd.obj"
	-@erase "$(INTDIR)\ChHTNtfy.obj"
	-@erase "$(INTDIR)\ChHTPriv.obj"
	-@erase "$(INTDIR)\ChHTTP.obj"
	-@erase "$(INTDIR)\ChHttpCookie.obj"
	-@erase "$(INTDIR)\ChHttpStream.obj"
	-@erase "$(INTDIR)\ChHttpThreadMgr.obj"
	-@erase "$(INTDIR)\ChHtUtil.obj"
	-@erase "$(INTDIR)\ChInlineTag.obj"
	-@erase "$(INTDIR)\ChKeyMap.obj"
	-@erase "$(INTDIR)\ChList.obj"
	-@erase "$(INTDIR)\ChMData.obj"
	-@erase "$(INTDIR)\ChMenu.obj"
	-@erase "$(INTDIR)\ChModule.obj"
	-@erase "$(INTDIR)\ChMsg.obj"
	-@erase "$(INTDIR)\ChMsgTyp.obj"
	-@erase "$(INTDIR)\ChNdbm.obj"
	-@erase "$(INTDIR)\ChPage.obj"
	-@erase "$(INTDIR)\ChPane.obj"
	-@erase "$(INTDIR)\ChPaneTag.obj"
	-@erase "$(INTDIR)\ChPblDoc.obj"
	-@erase "$(INTDIR)\ChPerFrm.obj"
	-@erase "$(INTDIR)\ChPlainTag.obj"
	-@erase "$(INTDIR)\ChPlgInInst.obj"
	-@erase "$(INTDIR)\ChPlgInMgr.obj"
	-@erase "$(INTDIR)\ChPlugInAPI.obj"
	-@erase "$(INTDIR)\ChPuebloScript.obj"
	-@erase "$(INTDIR)\ChReg.obj"
	-@erase "$(INTDIR)\ChRMenu.obj"
	-@erase "$(INTDIR)\ChScrWnd.obj"
	-@erase "$(INTDIR)\ChSock.obj"
	-@erase "$(INTDIR)\ChSocksProxy.obj"
	-@erase "$(INTDIR)\ChSplay.obj"
	-@erase "$(INTDIR)\ChSplit.obj"
	-@erase "$(INTDIR)\ChStrmbl.obj"
	-@erase "$(INTDIR)\ChThread.obj"
	-@erase "$(INTDIR)\ChTime.obj"
	-@erase "$(INTDIR)\ChTxRndr.obj"
	-@erase "$(INTDIR)\ChTxtAnimation.obj"
	-@erase "$(INTDIR)\ChTxtEng.obj"
	-@erase "$(INTDIR)\ChTxtObj.obj"
	-@erase "$(INTDIR)\ChTxtWnd.obj"
	-@erase "$(INTDIR)\ChUrlMap.obj"
	-@erase "$(INTDIR)\ChUtil.obj"
	-@erase "$(INTDIR)\ChVers.obj"
	-@erase "$(INTDIR)\ChWizard.obj"
	-@erase "$(INTDIR)\ChWType.obj"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(INTDIR)\Pueblo.obj"
	-@erase "$(INTDIR)\Pueblo.res"
	-@erase "$(INTDIR)\Pueblo40.pch"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Pueblo32.pdb"
	-@erase "..\bin\Debug\Pueblo32.dll"
	-@erase "..\bin\Debug\Pueblo32.ilk"
	-@erase "..\lib\Pueblo32.exp"
	-@erase "..\lib\Pueblo32.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D "CH_EXCEPTIONS" /Yu"headers.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D\
 "CH_EXCEPTIONS" /Fp"$(INTDIR)/Pueblo40.pch" /Yu"headers.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Pueblo.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Pueblo40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 wsock32.lib lz32.lib winmm.lib version.lib \chaco\lib\PbUtil32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"\chaco\bin\Debug/Pueblo32.dll" /implib:"\chaco\lib/Pueblo32.lib"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=wsock32.lib lz32.lib winmm.lib version.lib \chaco\lib\PbUtil32.lib\
 /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)/Pueblo32.pdb"\
 /debug /machine:I386 /def:".\Pueblo32.def" /out:"\chaco\bin\Debug/Pueblo32.dll"\
 /implib:"\chaco\lib/Pueblo32.lib" 
DEF_FILE= \
	".\Pueblo32.def"
LINK32_OBJS= \
	"$(INTDIR)\ChAcct.obj" \
	"$(INTDIR)\ChArch.obj" \
	"$(INTDIR)\ChArgList.obj" \
	"$(INTDIR)\ChBodyElement.obj" \
	"$(INTDIR)\ChBodyTags.obj" \
	"$(INTDIR)\ChClInfo.obj" \
	"$(INTDIR)\ChConn.obj" \
	"$(INTDIR)\ChCore.obj" \
	"$(INTDIR)\ChCreateTag.obj" \
	"$(INTDIR)\ChData.obj" \
	"$(INTDIR)\ChDb.obj" \
	"$(INTDIR)\ChDefnTag.obj" \
	"$(INTDIR)\ChDispat.obj" \
	"$(INTDIR)\ChDlg.obj" \
	"$(INTDIR)\ChExcept.obj" \
	"$(INTDIR)\ChFontElements.obj" \
	"$(INTDIR)\ChFormTags.obj" \
	"$(INTDIR)\ChHeadElement.obj" \
	"$(INTDIR)\ChHook.obj" \
	"$(INTDIR)\ChHtmFrm.obj" \
	"$(INTDIR)\ChHtmlArgs.obj" \
	"$(INTDIR)\ChHtmlFrameMgr.obj" \
	"$(INTDIR)\ChHtmlPane.obj" \
	"$(INTDIR)\ChHtmlParser.obj" \
	"$(INTDIR)\ChHtmlSettings.obj" \
	"$(INTDIR)\ChHTMLStream.obj" \
	"$(INTDIR)\ChHtmlTag.obj" \
	"$(INTDIR)\ChHtmlView.obj" \
	"$(INTDIR)\ChHtmMsg.obj" \
	"$(INTDIR)\ChHtmSym.obj" \
	"$(INTDIR)\ChHtmWnd.obj" \
	"$(INTDIR)\ChHTNtfy.obj" \
	"$(INTDIR)\ChHTPriv.obj" \
	"$(INTDIR)\ChHTTP.obj" \
	"$(INTDIR)\ChHttpCookie.obj" \
	"$(INTDIR)\ChHttpStream.obj" \
	"$(INTDIR)\ChHttpThreadMgr.obj" \
	"$(INTDIR)\ChHtUtil.obj" \
	"$(INTDIR)\ChInlineTag.obj" \
	"$(INTDIR)\ChKeyMap.obj" \
	"$(INTDIR)\ChList.obj" \
	"$(INTDIR)\ChMData.obj" \
	"$(INTDIR)\ChMenu.obj" \
	"$(INTDIR)\ChModule.obj" \
	"$(INTDIR)\ChMsg.obj" \
	"$(INTDIR)\ChMsgTyp.obj" \
	"$(INTDIR)\ChNdbm.obj" \
	"$(INTDIR)\ChPage.obj" \
	"$(INTDIR)\ChPane.obj" \
	"$(INTDIR)\ChPaneTag.obj" \
	"$(INTDIR)\ChPblDoc.obj" \
	"$(INTDIR)\ChPerFrm.obj" \
	"$(INTDIR)\ChPlainTag.obj" \
	"$(INTDIR)\ChPlgInInst.obj" \
	"$(INTDIR)\ChPlgInMgr.obj" \
	"$(INTDIR)\ChPlugInAPI.obj" \
	"$(INTDIR)\ChPuebloScript.obj" \
	"$(INTDIR)\ChReg.obj" \
	"$(INTDIR)\ChRMenu.obj" \
	"$(INTDIR)\ChScrWnd.obj" \
	"$(INTDIR)\ChSock.obj" \
	"$(INTDIR)\ChSocksProxy.obj" \
	"$(INTDIR)\ChSplay.obj" \
	"$(INTDIR)\ChSplit.obj" \
	"$(INTDIR)\ChStrmbl.obj" \
	"$(INTDIR)\ChThread.obj" \
	"$(INTDIR)\ChTime.obj" \
	"$(INTDIR)\ChTxRndr.obj" \
	"$(INTDIR)\ChTxtAnimation.obj" \
	"$(INTDIR)\ChTxtEng.obj" \
	"$(INTDIR)\ChTxtObj.obj" \
	"$(INTDIR)\ChTxtWnd.obj" \
	"$(INTDIR)\ChUrlMap.obj" \
	"$(INTDIR)\ChUtil.obj" \
	"$(INTDIR)\ChVers.obj" \
	"$(INTDIR)\ChWizard.obj" \
	"$(INTDIR)\ChWType.obj" \
	"$(INTDIR)\headers.obj" \
	"$(INTDIR)\Pueblo.obj" \
	"$(INTDIR)\Pueblo.res"

"..\bin\Debug\Pueblo32.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "Pueblo40 - Win32 Release"
# Name "Pueblo40 - Win32 Debug"

!IF  "$(CFG)" == "Pueblo40 - Win32 Release"

!ELSEIF  "$(CFG)" == "Pueblo40 - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "Pueblo40 - Win32 Release"

!ELSEIF  "$(CFG)" == "Pueblo40 - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo.cpp
DEP_CPP_PUEBL=\
	".\headers.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\Pueblo.obj" : $(SOURCE) $(DEP_CPP_PUEBL) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChArch.cpp
DEP_CPP_CHARC=\
	".\headers.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChArch.obj" : $(SOURCE) $(DEP_CPP_CHARC) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChArgList.cpp
DEP_CPP_CHARG=\
	".\headers.h"\
	{$(INCLUDE)}"\ChArgList.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChArgList.obj" : $(SOURCE) $(DEP_CPP_CHARG) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChBodyElement.cpp
DEP_CPP_CHBOD=\
	".\ChBodyElement.h"\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlTag.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChBodyElement.obj" : $(SOURCE) $(DEP_CPP_CHBOD) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChBodyTags.cpp
DEP_CPP_CHBODY=\
	".\ChBodyElement.h"\
	".\ChBodyTags.h"\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlTag.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChBodyTags.obj" : $(SOURCE) $(DEP_CPP_CHBODY) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChClInfo.cpp
DEP_CPP_CHCLI=\
	".\headers.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	

"$(INTDIR)\ChClInfo.obj" : $(SOURCE) $(DEP_CPP_CHCLI) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChConn.cpp
DEP_CPP_CHCON=\
	".\headers.h"\
	{$(INCLUDE)}"\ChConn.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\protocol.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\TemplCls\ChSockBf.h"\
	

"$(INTDIR)\ChConn.obj" : $(SOURCE) $(DEP_CPP_CHCON) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChCore.cpp
DEP_CPP_CHCOR=\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	
NODEP_CPP_CHCOR=\
	".\vwrres.h"\
	

"$(INTDIR)\ChCore.obj" : $(SOURCE) $(DEP_CPP_CHCOR) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChCreateTag.cpp
DEP_CPP_CHCRE=\
	".\ChBodyElement.h"\
	".\ChBodyTags.h"\
	".\ChDefnTag.h"\
	".\ChFontElements.h"\
	".\ChFormTags.h"\
	".\ChHeadElement.h"\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlTag.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\ChInlineTags.h"\
	".\ChPaneTag.h"\
	".\ChPlainTag.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChCreateTag.obj" : $(SOURCE) $(DEP_CPP_CHCRE) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChData.cpp
DEP_CPP_CHDAT=\
	".\headers.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChData.obj" : $(SOURCE) $(DEP_CPP_CHDAT) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDb.cpp
DEP_CPP_CHDB_=\
	".\ChNdbm.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\ChDb.obj" : $(SOURCE) $(DEP_CPP_CHDB_) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDefnTag.cpp
DEP_CPP_CHDEF=\
	".\ChBodyElement.h"\
	".\ChDefnTag.h"\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlTag.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChDefnTag.obj" : $(SOURCE) $(DEP_CPP_CHDEF) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDispat.cpp
DEP_CPP_CHDIS=\
	".\headers.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChDispat.obj" : $(SOURCE) $(DEP_CPP_CHDIS) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChDlg.cpp
DEP_CPP_CHDLG=\
	".\headers.h"\
	{$(INCLUDE)}"\ChDlg.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChDlg.obj" : $(SOURCE) $(DEP_CPP_CHDLG) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChExcept.cpp
DEP_CPP_CHEXC=\
	".\headers.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChExcept.obj" : $(SOURCE) $(DEP_CPP_CHEXC) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChFontElements.cpp
DEP_CPP_CHFON=\
	".\ChBodyElement.h"\
	".\ChFontElements.h"\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlTag.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChFontElements.obj" : $(SOURCE) $(DEP_CPP_CHFON) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmFrm.cpp
DEP_CPP_CHHTM=\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChHtmFrm.obj" : $(SOURCE) $(DEP_CPP_CHHTM) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHeadElement.cpp
DEP_CPP_CHHEA=\
	".\ChHeadElement.h"\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlTag.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChHeadElement.obj" : $(SOURCE) $(DEP_CPP_CHHEA) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHook.cpp
DEP_CPP_CHHOO=\
	".\headers.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChHook.obj" : $(SOURCE) $(DEP_CPP_CHHOO) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChFormTags.cpp
DEP_CPP_CHFOR=\
	".\ChBodyElement.h"\
	".\ChFormTags.h"\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlTag.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChFormTags.obj" : $(SOURCE) $(DEP_CPP_CHFOR) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlArgs.cpp
DEP_CPP_CHHTML=\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChArgList.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	
NODEP_CPP_CHHTML=\
	".\vwrres.h"\
	

"$(INTDIR)\ChHtmlArgs.obj" : $(SOURCE) $(DEP_CPP_CHHTML) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlFrameMgr.cpp
DEP_CPP_CHHTMLF=\
	".\ChHtmFrm.h"\
	".\ChHtmlView.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChHtmlFrameMgr.obj" : $(SOURCE) $(DEP_CPP_CHHTMLF) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlPane.cpp
DEP_CPP_CHHTMLP=\
	".\ChHtmFrm.h"\
	".\ChHtmlPane.h"\
	".\ChHtmlStream.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChHtmlPane.obj" : $(SOURCE) $(DEP_CPP_CHHTMLP) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlParser.cpp
DEP_CPP_CHHTMLPA=\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlTag.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChArgList.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	
NODEP_CPP_CHHTMLPA=\
	".\vwrres.h"\
	

"$(INTDIR)\ChHtmlParser.obj" : $(SOURCE) $(DEP_CPP_CHHTMLPA) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlSettings.cpp
DEP_CPP_CHHTMLS=\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChHtmlSettings.obj" : $(SOURCE) $(DEP_CPP_CHHTMLS) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHTMLStream.cpp

!IF  "$(CFG)" == "Pueblo40 - Win32 Release"

DEP_CPP_CHHTMLST=\
	".\ChHtmlPane.h"\
	".\ChHtmlStream.h"\
	".\ChHtmlView.h"\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibDecoder.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChGifDecoder.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	
NODEP_CPP_CHHTMLST=\
	"..\include\jerror.h"\
	"..\include\jpegint.h"\
	

"$(INTDIR)\ChHTMLStream.obj" : $(SOURCE) $(DEP_CPP_CHHTMLST) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ELSEIF  "$(CFG)" == "Pueblo40 - Win32 Debug"

DEP_CPP_CHHTMLST=\
	".\ChHtmFrm.h"\
	".\ChHtmlPane.h"\
	".\ChHtmlStream.h"\
	".\ChHtmlView.h"\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibDecoder.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChGifDecoder.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChImageDecoder.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChJpegDecoder.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\jconfig.h"\
	{$(INCLUDE)}"\jmorecfg.h"\
	{$(INCLUDE)}"\jpeglib.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	
NODEP_CPP_CHHTMLST=\
	"..\include\jerror.h"\
	"..\include\jpegint.h"\
	

"$(INTDIR)\ChHTMLStream.obj" : $(SOURCE) $(DEP_CPP_CHHTMLST) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlTag.cpp
DEP_CPP_CHHTMLT=\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlTag.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChHtmlTag.obj" : $(SOURCE) $(DEP_CPP_CHHTMLT) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\headers.cpp
DEP_CPP_HEADE=\
	".\headers.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

!IF  "$(CFG)" == "Pueblo40 - Win32 Release"

# ADD CPP /Yc"headers.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D\
 "CH_EXCEPTIONS" /Fp"$(INTDIR)/Pueblo40.pch" /Yc"headers.h" /Fo"$(INTDIR)/" /c\
 $(SOURCE) \
	

"$(INTDIR)\headers.obj" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Pueblo40.pch" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Pueblo40 - Win32 Debug"

# ADD CPP /Yc"headers.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "CH_MSW" /D "CH_CLIENT" /D\
 "CH_EXCEPTIONS" /Fp"$(INTDIR)/Pueblo40.pch" /Yc"headers.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\headers.obj" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Pueblo40.pch" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTxtWnd.cpp
DEP_CPP_CHTXT=\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChImgUtil.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChTxtWnd.obj" : $(SOURCE) $(DEP_CPP_CHTXT) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmMsg.cpp

!IF  "$(CFG)" == "Pueblo40 - Win32 Release"

DEP_CPP_CHHTMM=\
	".\ChHtmlParser.h"\
	".\ChHtmlStream.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	
NODEP_CPP_CHHTMM=\
	".\vwrres.h"\
	

"$(INTDIR)\ChHtmMsg.obj" : $(SOURCE) $(DEP_CPP_CHHTMM) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ELSEIF  "$(CFG)" == "Pueblo40 - Win32 Debug"

DEP_CPP_CHHTMM=\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlStream.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	
NODEP_CPP_CHHTMM=\
	".\vwrres.h"\
	

"$(INTDIR)\ChHtmMsg.obj" : $(SOURCE) $(DEP_CPP_CHHTMM) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmSym.cpp
DEP_CPP_CHHTMS=\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChHtmSym.obj" : $(SOURCE) $(DEP_CPP_CHHTMS) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmWnd.cpp
DEP_CPP_CHHTMW=\
	".\ChHtmFrm.h"\
	".\ChHtmlPane.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlStream.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	
NODEP_CPP_CHHTMW=\
	".\vwrres.h"\
	

"$(INTDIR)\ChHtmWnd.obj" : $(SOURCE) $(DEP_CPP_CHHTMW) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChInlineTag.cpp
DEP_CPP_CHINL=\
	".\ChBodyElement.h"\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlTag.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\ChInlineTags.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChArgList.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChInlineTag.obj" : $(SOURCE) $(DEP_CPP_CHINL) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChNdbm.cpp
DEP_CPP_CHNDB=\
	".\ChNdbm.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\types.h"\
	

"$(INTDIR)\ChNdbm.obj" : $(SOURCE) $(DEP_CPP_CHNDB) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPaneTag.cpp
DEP_CPP_CHPAN=\
	".\ChHtmFrm.h"\
	".\ChHtmlPane.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlTag.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\ChPaneTag.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChPaneTag.obj" : $(SOURCE) $(DEP_CPP_CHPAN) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPlainTag.cpp
DEP_CPP_CHPLA=\
	".\ChHtmFrm.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlTag.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\ChPlainTag.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChPlainTag.obj" : $(SOURCE) $(DEP_CPP_CHPLA) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPlgInInst.cpp

!IF  "$(CFG)" == "Pueblo40 - Win32 Release"

DEP_CPP_CHPLG=\
	".\ChHtmFrm.h"\
	".\ChHtmlView.h"\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	".\jri\jri.h"\
	".\jri\jri_md.h"\
	".\jri\jritypes.h"\
	{$(INCLUDE)}"\ChArgList.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChPlgInInst.obj" : $(SOURCE) $(DEP_CPP_CHPLG) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ELSEIF  "$(CFG)" == "Pueblo40 - Win32 Debug"

DEP_CPP_CHPLG=\
	".\ChHtmFrm.h"\
	".\ChHtmlView.h"\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	".\jri\jri.h"\
	".\jri\jri_md.h"\
	".\jri\jritypes.h"\
	{$(INCLUDE)}"\ChArgList.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChPlgInInst.obj" : $(SOURCE) $(DEP_CPP_CHPLG) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPlgInMgr.cpp

!IF  "$(CFG)" == "Pueblo40 - Win32 Release"

DEP_CPP_CHPLGI=\
	".\ChHtmFrm.h"\
	".\ChHtmlView.h"\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	".\jri\jri.h"\
	".\jri\jri_md.h"\
	".\jri\jritypes.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChPlgInMgr.obj" : $(SOURCE) $(DEP_CPP_CHPLGI) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ELSEIF  "$(CFG)" == "Pueblo40 - Win32 Debug"

DEP_CPP_CHPLGI=\
	".\ChHtmFrm.h"\
	".\ChHtmlView.h"\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	".\jri\jri.h"\
	".\jri\jri_md.h"\
	".\jri\jritypes.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChPlgInMgr.obj" : $(SOURCE) $(DEP_CPP_CHPLGI) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPlugInAPI.cpp

!IF  "$(CFG)" == "Pueblo40 - Win32 Release"

DEP_CPP_CHPLU=\
	".\ChHtmFrm.h"\
	".\ChHtmlView.h"\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	".\jri\jri.h"\
	".\jri\jri_md.h"\
	".\jri\jritypes.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChPlugInAPI.obj" : $(SOURCE) $(DEP_CPP_CHPLU) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ELSEIF  "$(CFG)" == "Pueblo40 - Win32 Debug"

DEP_CPP_CHPLU=\
	".\ChHtmFrm.h"\
	".\ChHtmlView.h"\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	".\jri\jri.h"\
	".\jri\jri_md.h"\
	".\jri\jritypes.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	

"$(INTDIR)\ChPlugInAPI.obj" : $(SOURCE) $(DEP_CPP_CHPLU) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTxRndr.cpp
DEP_CPP_CHTXR=\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChImgUtil.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChTxRndr.obj" : $(SOURCE) $(DEP_CPP_CHTXR) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTxtAnimation.cpp
DEP_CPP_CHTXTA=\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChImgUtil.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChTxtAnimation.obj" : $(SOURCE) $(DEP_CPP_CHTXTA) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTxtEng.cpp
DEP_CPP_CHTXTE=\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChTxtEng.obj" : $(SOURCE) $(DEP_CPP_CHTXTE) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTxtObj.cpp

!IF  "$(CFG)" == "Pueblo40 - Win32 Release"

DEP_CPP_CHTXTO=\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChArgList.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgUtil.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChTxtObj.obj" : $(SOURCE) $(DEP_CPP_CHTXTO) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ELSEIF  "$(CFG)" == "Pueblo40 - Win32 Debug"

DEP_CPP_CHTXTO=\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChArgList.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChImgUtil.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChTxtObj.obj" : $(SOURCE) $(DEP_CPP_CHTXTO) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtmlView.cpp

!IF  "$(CFG)" == "Pueblo40 - Win32 Release"

DEP_CPP_CHHTMLV=\
	".\ChHtmlPane.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlStream.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	
NODEP_CPP_CHHTMLV=\
	".\vwrres.h"\
	

"$(INTDIR)\ChHtmlView.obj" : $(SOURCE) $(DEP_CPP_CHHTMLV) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ELSEIF  "$(CFG)" == "Pueblo40 - Win32 Debug"

DEP_CPP_CHHTMLV=\
	".\ChHtmFrm.h"\
	".\ChHtmlPane.h"\
	".\ChHtmlParser.h"\
	".\ChHtmlStream.h"\
	".\ChHtmlView.h"\
	".\ChHtmSym.h"\
	".\ChPlgInAPI.h"\
	".\ChPlgInMgr.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDC.h"\
	{$(INCLUDE)}"\ChDibImage.h"\
	{$(INCLUDE)}"\ChFont.h"\
	{$(INCLUDE)}"\ChHtmlSettings.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChImgConsumer.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChScrlVw.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChSize.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTxtObj.h"\
	{$(INCLUDE)}"\ChTxtWnd.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.h"\
	{$(INCLUDE)}"\TemplCls\ChFechLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.h"\
	{$(INCLUDE)}"\TemplCls\ChHtFmLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChHtmSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChPstrLs.h"\
	
NODEP_CPP_CHHTMLV=\
	".\vwrres.h"\
	

"$(INTDIR)\ChHtmlView.obj" : $(SOURCE) $(DEP_CPP_CHHTMLV) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChUrlMap.cpp
DEP_CPP_CHURL=\
	".\headers.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	

"$(INTDIR)\ChUrlMap.obj" : $(SOURCE) $(DEP_CPP_CHURL) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHTPriv.cpp
DEP_CPP_CHHTP=\
	".\ChHTPriv.h"\
	".\ChHttpCookie.h"\
	".\ChHttpThreadMgr.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUnzip.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\TemplCls\ChHTPLst.h"\
	{$(INCLUDE)}"\TemplCls\ChHtpSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChSockBf.h"\
	{$(INCLUDE)}"\unzip.h"\
	
NODEP_CPP_CHHTP=\
	".\ChGrType.h"\
	

"$(INTDIR)\ChHTPriv.obj" : $(SOURCE) $(DEP_CPP_CHHTP) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHTTP.cpp
DEP_CPP_CHHTT=\
	".\ChHTPriv.h"\
	".\ChHttpCookie.h"\
	".\ChHttpThreadMgr.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\TemplCls\ChHTPLst.h"\
	{$(INCLUDE)}"\TemplCls\ChHtpSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChSockBf.h"\
	
NODEP_CPP_CHHTT=\
	".\ChGrType.h"\
	

"$(INTDIR)\ChHTTP.obj" : $(SOURCE) $(DEP_CPP_CHHTT) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHttpCookie.cpp
DEP_CPP_CHHTTP=\
	".\ChHttpCookie.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	
NODEP_CPP_CHHTTP=\
	".\vwrres.h"\
	

"$(INTDIR)\ChHttpCookie.obj" : $(SOURCE) $(DEP_CPP_CHHTTP) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHttpStream.cpp
DEP_CPP_CHHTTPS=\
	".\ChHTPriv.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\TemplCls\ChHTPLst.h"\
	{$(INCLUDE)}"\TemplCls\ChHtpSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChSockBf.h"\
	

"$(INTDIR)\ChHttpStream.obj" : $(SOURCE) $(DEP_CPP_CHHTTPS) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHttpThreadMgr.cpp
DEP_CPP_CHHTTPT=\
	".\ChHTPriv.h"\
	".\ChHttpThreadMgr.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\TemplCls\ChHTPLst.h"\
	{$(INCLUDE)}"\TemplCls\ChHtpSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChSockBf.h"\
	

"$(INTDIR)\ChHttpThreadMgr.obj" : $(SOURCE) $(DEP_CPP_CHHTTPT) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHtUtil.cpp
DEP_CPP_CHHTU=\
	".\headers.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChHtUtil.obj" : $(SOURCE) $(DEP_CPP_CHHTU) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChThread.cpp
DEP_CPP_CHTHR=\
	".\ChHTPriv.h"\
	".\ChHttpThreadMgr.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\TemplCls\ChHTPLst.h"\
	{$(INCLUDE)}"\TemplCls\ChHtpSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChSockBf.h"\
	

"$(INTDIR)\ChThread.obj" : $(SOURCE) $(DEP_CPP_CHTHR) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChHTNtfy.cpp
DEP_CPP_CHHTN=\
	".\ChHTPriv.h"\
	".\ChHttpThreadMgr.h"\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChHtpCon.h"\
	{$(INCLUDE)}"\ChHTTP.h"\
	{$(INCLUDE)}"\ChHTTPStream.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUrlMap.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\SocketXX.h"\
	{$(INCLUDE)}"\sockinet.h"\
	{$(INCLUDE)}"\sockstrm.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\TemplCls\ChHTPLst.h"\
	{$(INCLUDE)}"\TemplCls\ChHtpSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChSockBf.h"\
	
NODEP_CPP_CHHTN=\
	".\vwrres.h"\
	

"$(INTDIR)\ChHTNtfy.obj" : $(SOURCE) $(DEP_CPP_CHHTN) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWType.cpp
DEP_CPP_CHWTY=\
	".\headers.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChWType.h"\
	

"$(INTDIR)\ChWType.obj" : $(SOURCE) $(DEP_CPP_CHWTY) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChList.cpp
DEP_CPP_CHLIS=\
	".\headers.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChList.obj" : $(SOURCE) $(DEP_CPP_CHLIS) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMData.cpp
DEP_CPP_CHMDA=\
	".\headers.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChMData.obj" : $(SOURCE) $(DEP_CPP_CHMDA) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMenu.cpp
DEP_CPP_CHMEN=\
	".\headers.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChMenu.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChRMenu.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChMItSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChMnBlk.h"\
	{$(INCLUDE)}"\TemplCls\ChMnBlk.inl"\
	{$(INCLUDE)}"\TemplCls\ChMnItem.h"\
	{$(INCLUDE)}"\TemplCls\ChMnItLs.h"\
	{$(INCLUDE)}"\TemplCls\ChMnItLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChMnList.h"\
	{$(INCLUDE)}"\TemplCls\ChMnList.inl"\
	{$(INCLUDE)}"\TemplCls\ChMnMap.h"\
	{$(INCLUDE)}"\TemplCls\ChMnPtrL.h"\
	{$(INCLUDE)}"\TemplCls\ChMnPtrL.inl"\
	{$(INCLUDE)}"\TemplCls\ChMnSply.h"\
	{$(INCLUDE)}"\TemplCls\ChStrLst.h"\
	{$(INCLUDE)}"\TemplCls\ChStrLst.inl"\
	

"$(INTDIR)\ChMenu.obj" : $(SOURCE) $(DEP_CPP_CHMEN) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChModule.cpp
DEP_CPP_CHMOD=\
	".\headers.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChModule.obj" : $(SOURCE) $(DEP_CPP_CHMOD) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMsg.cpp
DEP_CPP_CHMSG=\
	".\headers.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	

"$(INTDIR)\ChMsg.obj" : $(SOURCE) $(DEP_CPP_CHMSG) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMsgTyp.cpp
DEP_CPP_CHMSGT=\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChGraphx.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChMsgTyp.obj" : $(SOURCE) $(DEP_CPP_CHMSGT) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPage.cpp
DEP_CPP_CHPAG=\
	".\headers.h"\
	{$(INCLUDE)}"\ChPage.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChPage.obj" : $(SOURCE) $(DEP_CPP_CHPAG) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPane.cpp
DEP_CPP_CHPANE=\
	".\headers.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChHtmWnd.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplit.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	
NODEP_CPP_CHPANE=\
	".\vwrres.h"\
	

"$(INTDIR)\ChPane.obj" : $(SOURCE) $(DEP_CPP_CHPANE) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPblDoc.cpp
DEP_CPP_CHPBL=\
	".\headers.h"\
	{$(INCLUDE)}"\ChPblDoc.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChPblDoc.obj" : $(SOURCE) $(DEP_CPP_CHPBL) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPerFrm.cpp
DEP_CPP_CHPER=\
	".\headers.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChPerFrm.obj" : $(SOURCE) $(DEP_CPP_CHPER) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPuebloScript.cpp
DEP_CPP_CHPUE=\
	".\headers.h"\
	{$(INCLUDE)}"\ChArgList.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChPuebloScript.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChPuebloScript.obj" : $(SOURCE) $(DEP_CPP_CHPUE) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChReg.cpp
DEP_CPP_CHREG=\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChReg.obj" : $(SOURCE) $(DEP_CPP_CHREG) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRMenu.cpp
DEP_CPP_CHRME=\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDispat.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChMenu.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChMsgTyp.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChRMenu.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\TemplCls\ChMItSpl.h"\
	{$(INCLUDE)}"\TemplCls\ChMnBlk.h"\
	{$(INCLUDE)}"\TemplCls\ChMnBlk.inl"\
	{$(INCLUDE)}"\TemplCls\ChMnItem.h"\
	{$(INCLUDE)}"\TemplCls\ChMnItLs.h"\
	{$(INCLUDE)}"\TemplCls\ChMnItLs.inl"\
	{$(INCLUDE)}"\TemplCls\ChMnList.h"\
	{$(INCLUDE)}"\TemplCls\ChMnList.inl"\
	{$(INCLUDE)}"\TemplCls\ChMnMap.h"\
	{$(INCLUDE)}"\TemplCls\ChMnPtrL.h"\
	{$(INCLUDE)}"\TemplCls\ChMnPtrL.inl"\
	{$(INCLUDE)}"\TemplCls\ChMnSply.h"\
	{$(INCLUDE)}"\TemplCls\ChStrLst.h"\
	{$(INCLUDE)}"\TemplCls\ChStrLst.inl"\
	

"$(INTDIR)\ChRMenu.obj" : $(SOURCE) $(DEP_CPP_CHRME) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChScrWnd.cpp
DEP_CPP_CHSCR=\
	".\headers.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChScrWnd.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChScrWnd.obj" : $(SOURCE) $(DEP_CPP_CHSCR) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSock.cpp
DEP_CPP_CHSOC=\
	".\headers.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	
NODEP_CPP_CHSOC=\
	".\ChGrType.h"\
	

"$(INTDIR)\ChSock.obj" : $(SOURCE) $(DEP_CPP_CHSOC) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSocksProxy.cpp
DEP_CPP_CHSOCK=\
	".\headers.h"\
	{$(INCLUDE)}"\ChExcept.h"\
	{$(INCLUDE)}"\ChSock.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChSocksProxy.obj" : $(SOURCE) $(DEP_CPP_CHSOCK) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSplay.cpp
DEP_CPP_CHSPL=\
	".\headers.h"\
	{$(INCLUDE)}"\ChSplay.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChSplay.obj" : $(SOURCE) $(DEP_CPP_CHSPL) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChStrmbl.cpp
DEP_CPP_CHSTR=\
	".\headers.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChStrmbl.obj" : $(SOURCE) $(DEP_CPP_CHSTR) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChUtil.cpp
DEP_CPP_CHUTI=\
	".\headers.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\sys\stat.h"\
	{$(INCLUDE)}"\sys\types.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	
NODEP_CPP_CHUTI=\
	".\vwrres.h"\
	

"$(INTDIR)\ChUtil.obj" : $(SOURCE) $(DEP_CPP_CHUTI) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChVers.cpp
DEP_CPP_CHVER=\
	".\headers.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	

"$(INTDIR)\ChVers.obj" : $(SOURCE) $(DEP_CPP_CHVER) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTime.cpp
DEP_CPP_CHTIM=\
	".\headers.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTime.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\values.h"\
	

"$(INTDIR)\ChTime.obj" : $(SOURCE) $(DEP_CPP_CHTIM) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSplit.cpp
DEP_CPP_CHSPLI=\
	".\headers.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChConst.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChDb.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChPane.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChRect.h"\
	{$(INCLUDE)}"\ChReg.h"\
	{$(INCLUDE)}"\ChSplit.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWnd.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	
NODEP_CPP_CHSPLI=\
	".\vwrres.h"\
	

"$(INTDIR)\ChSplit.obj" : $(SOURCE) $(DEP_CPP_CHSPLI) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAcct.cpp
DEP_CPP_CHACC=\
	".\headers.h"\
	{$(INCLUDE)}"\ChAcct.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	

"$(INTDIR)\ChAcct.obj" : $(SOURCE) $(DEP_CPP_CHACC) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChWizard.cpp
DEP_CPP_CHWIZ=\
	".\headers.h"\
	{$(INCLUDE)}"\ChClInfo.h"\
	{$(INCLUDE)}"\ChCore.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChHook.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChMData.h"\
	{$(INCLUDE)}"\ChModule.h"\
	{$(INCLUDE)}"\ChMsg.h"\
	{$(INCLUDE)}"\ChPerFrm.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\ChUtil.h"\
	{$(INCLUDE)}"\ChVers.h"\
	{$(INCLUDE)}"\ChWizard.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	
NODEP_CPP_CHWIZ=\
	".\vwrres.h"\
	

"$(INTDIR)\ChWizard.obj" : $(SOURCE) $(DEP_CPP_CHWIZ) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChKeyMap.cpp
DEP_CPP_CHKEY=\
	".\headers.h"\
	{$(INCLUDE)}"\ChArch.h"\
	{$(INCLUDE)}"\ChData.h"\
	{$(INCLUDE)}"\ChKeyMap.h"\
	{$(INCLUDE)}"\ChList.h"\
	{$(INCLUDE)}"\ChStrmbl.h"\
	{$(INCLUDE)}"\ChTypes.h"\
	{$(INCLUDE)}"\TemplCls\ChLstHlp.inl"\
	

"$(INTDIR)\ChKeyMap.obj" : $(SOURCE) $(DEP_CPP_CHKEY) "$(INTDIR)"\
 "$(INTDIR)\Pueblo40.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo32.def

!IF  "$(CFG)" == "Pueblo40 - Win32 Release"

!ELSEIF  "$(CFG)" == "Pueblo40 - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Pueblo.rc
DEP_RSC_PUEBLO=\
	".\res\book.ico"\
	".\res\book_log.ico"\
	".\RES\COLSPLIT.CUR"\
	".\RES\HOTSPOT.CUR"\
	".\res\map.ico"\
	".\res\Pueblo.rc2"\
	".\res\rowsplit.cur"\
	".\res\scroll.ico"\
	

"$(INTDIR)\Pueblo.res" : $(SOURCE) $(DEP_RSC_PUEBLO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
# End Target
# End Project
################################################################################
