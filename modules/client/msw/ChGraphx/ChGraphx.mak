# Microsoft Visual C++ Generated NMAKE File, Format Version 2.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Debug" && "$(CFG)" != "Win32 Release" && "$(CFG)" !=\
 "Reality Debug" && "$(CFG)" != "Reality Release" && "$(CFG)" != "D3D Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "ChGraphx.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Reality Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Reality Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "D3D Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

################################################################################
# Begin Project
# PROP Target_Last_Scanned "Reality Debug"
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
# PROP Output_Dir "\chaco\bin\debug\modules"
# PROP Intermediate_Dir "WinDebug"
OUTDIR=\chaco\bin\debug\modules
INTDIR=.\WinDebug

ALL : $(OUTDIR)/ChGraphx.dll $(OUTDIR)/ChGraphx.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr /Yu"grheader.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/\
 /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c 
CPP_OBJS=.\WinDebug/
# ADD BASE RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo$(INTDIR)/"ChGraphx.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChGraphx.bsc" 
BSC32_SBRS= \
	$(INTDIR)/HEADERS.SBR \
	$(INTDIR)/Dll.sbr \
	$(INTDIR)/ChGraphx.sbr \
	$(INTDIR)/ChGrMod.sbr \
	$(INTDIR)/ChGrDep.sbr \
	$(INTDIR)/ChGrVw.sbr \
	$(INTDIR)/ChPanMod.sbr \
	$(INTDIR)/QvLib.sbr \
	$(INTDIR)/ChAniPrs.sbr \
	$(INTDIR)/ChAnimy.sbr \
	$(INTDIR)/ChAniMod.sbr \
	$(INTDIR)/ChAnimCh.sbr \
	$(INTDIR)/ChAnim.sbr \
	$(INTDIR)/ChAniDep.sbr \
	$(INTDIR)/ChPhSprt.sbr \
	$(INTDIR)/ChSprLst.sbr \
	$(INTDIR)/ChSprite.sbr \
	$(INTDIR)/ChSpLstN.sbr \
	$(INTDIR)/Ch3Dtrvs.sbr \
	$(INTDIR)/Ch3Rendr.sbr \
	$(INTDIR)/ChMazDep.sbr \
	$(INTDIR)/ChMaze.sbr \
	$(INTDIR)/ChMazMod.sbr \
	$(INTDIR)/ChQvStat.sbr \
	$(INTDIR)/CvBound.sbr \
	$(INTDIR)/CvQuery.sbr \
	$(INTDIR)/CvWrite.sbr \
	$(INTDIR)/ChMazePr.sbr \
	$(INTDIR)/ChMazCam.sbr \
	$(INTDIR)/CvTrnsfm.sbr \
	$(INTDIR)/CvHitTst.sbr \
	$(INTDIR)/CvType.sbr \
	$(INTDIR)/CvTextur.sbr \
	$(INTDIR)/CvMaterl.sbr \
	$(INTDIR)/CvLights.sbr \
	$(INTDIR)/CvInstnc.sbr \
	$(INTDIR)/CvShapes.sbr \
	$(INTDIR)/ChAscTxt.sbr \
	$(INTDIR)/ChGrFont.sbr \
	$(INTDIR)/ChSpline.sbr \
	$(INTDIR)/ChColor.sbr \
	$(INTDIR)/CvCamera.sbr \
	$(INTDIR)/CvConvrt.sbr \
	$(INTDIR)/ChRLImg.sbr \
	$(INTDIR)/ChGrStrm.sbr \
	$(INTDIR)/ChQvPars.sbr \
	$(INTDIR)/ChRenderData.sbr \
	$(INTDIR)/ChStubBrowser.sbr \
	$(INTDIR)/ChVrmlTransition.sbr \
	$(INTDIR)/ChTransition.sbr \
	$(INTDIR)/ChVrmlSettings.sbr \
	$(INTDIR)/ChVrmlWnd.sbr \
	$(INTDIR)/ChRlabPr.sbr \
	$(INTDIR)/ChThreadMgr.sbr \
	$(INTDIR)/CvSelectors.sbr \
	$(INTDIR)/ChVrmlMenu.sbr \
	$(INTDIR)/ChScriptData.sbr \
	$(INTDIR)/CvGroup.sbr \
	$(INTDIR)/CvBoundsExtent.sbr \
	$(INTDIR)/ChSphere.sbr \
	$(INTDIR)/ChRenderBuffer.sbr \
	$(INTDIR)/ChRCDevice.sbr \
	$(INTDIR)/ChNrCreate.sbr \
	$(INTDIR)/ChMaterialRenderData.sbr \
	$(INTDIR)/GxUtils.sbr \
	$(INTDIR)/GxSphere.sbr \
	$(INTDIR)/CvNormal.sbr \
	$(INTDIR)/GxTrnsfm.sbr \
	$(INTDIR)/ChTrMonot.sbr \
	$(INTDIR)/ChTrMisc.sbr \
	$(INTDIR)/ChTriangle.sbr \
	$(INTDIR)/ChTrConstr.sbr \
	$(INTDIR)/XLINES.SBR \
	$(INTDIR)/INVERSE.SBR \
	$(INTDIR)/GxQuaternion.sbr

$(OUTDIR)/ChGraphx.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /DEF:"ChText.def" /IMPLIB:"ChText.lib"
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 winmm.lib LZ32.lib /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /OUT:"/chaco/bin/debug/ChGraphx.dll" /PDB:"/chaco/bin/debug/ChGraphx.pdb" /IMPLIB:"/chaco/bin/debug/ChGraphx.lib"
# SUBTRACT LINK32 /PROFILE /INCREMENTAL:no
LINK32_FLAGS=winmm.lib LZ32.lib /NOLOGO /SUBSYSTEM:windows /DLL\
 /INCREMENTAL:yes /PDB:$(OUTDIR)/"ChGraphx.pdb" /DEBUG /MACHINE:I386\
 /OUT:$(OUTDIR)/"ChGraphx.dll" /IMPLIB:$(OUTDIR)/"ChGraphx.lib"\
 /OUT:"/chaco/bin/debug/ChGraphx.dll" /PDB:"/chaco/bin/debug/ChGraphx.pdb"\
 /IMPLIB:"/chaco/bin/debug/ChGraphx.lib"  
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/HEADERS.OBJ \
	$(INTDIR)/Dll.obj \
	$(INTDIR)/ChGraphx.obj \
	$(INTDIR)/ChGraphx.res \
	$(INTDIR)/ChGrMod.obj \
	$(INTDIR)/ChGrDep.obj \
	$(INTDIR)/ChGrVw.obj \
	\USR\3DR\SDK\3DG32.LIB \
	\USR\3DR\SDK\3DR32.LIB \
	$(INTDIR)/ChPanMod.obj \
	\CHACO\LIB\Pueblo32.lib \
	\CHACO\LIB\PbUtil32.lib \
	$(INTDIR)/QvLib.obj \
	$(INTDIR)/ChAniPrs.obj \
	$(INTDIR)/ChAnimy.obj \
	$(INTDIR)/ChAniMod.obj \
	$(INTDIR)/ChAnimCh.obj \
	$(INTDIR)/ChAnim.obj \
	$(INTDIR)/ChAniDep.obj \
	$(INTDIR)/ChPhSprt.obj \
	$(INTDIR)/ChSprLst.obj \
	$(INTDIR)/ChSprite.obj \
	$(INTDIR)/ChSpLstN.obj \
	$(INTDIR)/Ch3Dtrvs.obj \
	$(INTDIR)/Ch3Rendr.obj \
	$(INTDIR)/ChMazDep.obj \
	$(INTDIR)/ChMaze.obj \
	$(INTDIR)/ChMazMod.obj \
	$(INTDIR)/ChQvStat.obj \
	$(INTDIR)/CvBound.obj \
	$(INTDIR)/CvQuery.obj \
	$(INTDIR)/CvWrite.obj \
	$(INTDIR)/ChMazePr.obj \
	$(INTDIR)/ChMazCam.obj \
	$(INTDIR)/CvTrnsfm.obj \
	$(INTDIR)/CvHitTst.obj \
	$(INTDIR)/CvType.obj \
	$(INTDIR)/CvTextur.obj \
	$(INTDIR)/CvMaterl.obj \
	$(INTDIR)/CvLights.obj \
	$(INTDIR)/CvInstnc.obj \
	$(INTDIR)/CvShapes.obj \
	$(INTDIR)/ChAscTxt.obj \
	$(INTDIR)/ChGrFont.obj \
	$(INTDIR)/ChSpline.obj \
	$(INTDIR)/ChColor.obj \
	$(INTDIR)/CvCamera.obj \
	$(INTDIR)/CvConvrt.obj \
	$(INTDIR)/ChRLImg.obj \
	$(INTDIR)/ChGrStrm.obj \
	$(INTDIR)/ChQvPars.obj \
	$(INTDIR)/ChRenderData.obj \
	$(INTDIR)/ChStubBrowser.obj \
	$(INTDIR)/ChVrmlTransition.obj \
	$(INTDIR)/ChTransition.obj \
	$(INTDIR)/ChVrmlSettings.obj \
	$(INTDIR)/ChVrmlWnd.obj \
	$(INTDIR)/ChRlabPr.obj \
	$(INTDIR)/ChThreadMgr.obj \
	$(INTDIR)/CvSelectors.obj \
	$(INTDIR)/ChVrmlMenu.obj \
	$(INTDIR)/ChScriptData.obj \
	$(INTDIR)/CvGroup.obj \
	$(INTDIR)/CvBoundsExtent.obj \
	$(INTDIR)/ChSphere.obj \
	$(INTDIR)/ChRenderBuffer.obj \
	$(INTDIR)/ChRCDevice.obj \
	$(INTDIR)/ChNrCreate.obj \
	$(INTDIR)/ChMaterialRenderData.obj \
	$(INTDIR)/GxUtils.obj \
	$(INTDIR)/GxSphere.obj \
	$(INTDIR)/CvNormal.obj \
	$(INTDIR)/GxTrnsfm.obj \
	$(INTDIR)/ChTrMonot.obj \
	$(INTDIR)/ChTrMisc.obj \
	$(INTDIR)/ChTriangle.obj \
	$(INTDIR)/ChTrConstr.obj \
	$(INTDIR)/XLINES.OBJ \
	$(INTDIR)/INVERSE.OBJ \
	$(INTDIR)/GxQuaternion.obj

$(OUTDIR)/ChGraphx.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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
# PROP Output_Dir "/chaco/bin/release/modules"
# PROP Intermediate_Dir "WinRel"
OUTDIR=/chaco/bin/release/modules
INTDIR=.\WinRel

ALL : $(OUTDIR)/ChGraphx.dll $(OUTDIR)/ChGraphx.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Yu"grheader.h" /c
# SUBTRACT CPP /Og /Fr
CPP_PROJ=/nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fp$(OUTDIR)/"ChGraphx.pch"\
 /Yu"grheader.h" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\WinRel/
# ADD BASE RSC /l 0x0 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"ChGraphx.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChGraphx.bsc" 
BSC32_SBRS= \
	

$(OUTDIR)/ChGraphx.bsc : $(OUTDIR)  $(BSC32_SBRS)
LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386 /DEF:"ChText.def" /IMPLIB:"ChText.lib"
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 winmm.lib Pueblo32.lib LZ32.lib /NOLOGO /SUBSYSTEM:windows /DLL /MACHINE:I386 /OUT:"/chaco/bin/release/modules/ChGraphx.dll" /PDB:"/chaco/bin/release/ChGraphx.pdb" /OUT:"/chaco/bin/release/ChGraphx.dll" /IMPLIB:"/chaco/bin/release/ChGraphx.lib"
LINK32_FLAGS=winmm.lib Pueblo32.lib LZ32.lib /NOLOGO /SUBSYSTEM:windows /DLL\
 /INCREMENTAL:no /PDB:$(OUTDIR)/"ChGraphx.pdb" /MACHINE:I386\
 /OUT:$(OUTDIR)/"ChGraphx.dll" /IMPLIB:$(OUTDIR)/"ChGraphx.lib"\
 /OUT:"/chaco/bin/release/modules/ChGraphx.dll"\
 /PDB:"/chaco/bin/release/ChGraphx.pdb" /OUT:"/chaco/bin/release/ChGraphx.dll"\
 /IMPLIB:"/chaco/bin/release/ChGraphx.lib"  
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/HEADERS.OBJ \
	$(INTDIR)/Dll.obj \
	$(INTDIR)/ChGraphx.obj \
	$(INTDIR)/ChGraphx.res \
	$(INTDIR)/ChGrMod.obj \
	$(INTDIR)/ChGrDep.obj \
	$(INTDIR)/ChGrVw.obj \
	\USR\3DR\SDK\3DG32.LIB \
	\USR\3DR\SDK\3DR32.LIB \
	$(INTDIR)/ChPanMod.obj \
	\CHACO\LIB\Pueblo32.lib \
	\CHACO\LIB\PbUtil32.lib \
	$(INTDIR)/QvLib.obj \
	$(INTDIR)/ChAniPrs.obj \
	$(INTDIR)/ChAnimy.obj \
	$(INTDIR)/ChAniMod.obj \
	$(INTDIR)/ChAnimCh.obj \
	$(INTDIR)/ChAnim.obj \
	$(INTDIR)/ChAniDep.obj \
	$(INTDIR)/ChPhSprt.obj \
	$(INTDIR)/ChSprLst.obj \
	$(INTDIR)/ChSprite.obj \
	$(INTDIR)/ChSpLstN.obj \
	$(INTDIR)/Ch3Dtrvs.obj \
	$(INTDIR)/Ch3Rendr.obj \
	$(INTDIR)/ChMazDep.obj \
	$(INTDIR)/ChMaze.obj \
	$(INTDIR)/ChMazMod.obj \
	$(INTDIR)/ChQvStat.obj \
	$(INTDIR)/CvBound.obj \
	$(INTDIR)/CvQuery.obj \
	$(INTDIR)/CvWrite.obj \
	$(INTDIR)/ChMazePr.obj \
	$(INTDIR)/ChMazCam.obj \
	$(INTDIR)/CvTrnsfm.obj \
	$(INTDIR)/CvHitTst.obj \
	$(INTDIR)/CvType.obj \
	$(INTDIR)/CvTextur.obj \
	$(INTDIR)/CvMaterl.obj \
	$(INTDIR)/CvLights.obj \
	$(INTDIR)/CvInstnc.obj \
	$(INTDIR)/CvShapes.obj \
	$(INTDIR)/ChAscTxt.obj \
	$(INTDIR)/ChGrFont.obj \
	$(INTDIR)/ChSpline.obj \
	$(INTDIR)/ChColor.obj \
	$(INTDIR)/CvCamera.obj \
	$(INTDIR)/CvConvrt.obj \
	$(INTDIR)/ChRLImg.obj \
	$(INTDIR)/ChGrStrm.obj \
	$(INTDIR)/ChQvPars.obj \
	$(INTDIR)/ChRenderData.obj \
	$(INTDIR)/ChStubBrowser.obj \
	$(INTDIR)/ChVrmlTransition.obj \
	$(INTDIR)/ChTransition.obj \
	$(INTDIR)/ChVrmlSettings.obj \
	$(INTDIR)/ChVrmlWnd.obj \
	$(INTDIR)/ChRlabPr.obj \
	$(INTDIR)/ChThreadMgr.obj \
	$(INTDIR)/CvSelectors.obj \
	$(INTDIR)/ChVrmlMenu.obj \
	$(INTDIR)/ChScriptData.obj \
	$(INTDIR)/CvGroup.obj \
	$(INTDIR)/CvBoundsExtent.obj \
	$(INTDIR)/ChSphere.obj \
	$(INTDIR)/ChRenderBuffer.obj \
	$(INTDIR)/ChRCDevice.obj \
	$(INTDIR)/ChNrCreate.obj \
	$(INTDIR)/ChMaterialRenderData.obj \
	$(INTDIR)/GxUtils.obj \
	$(INTDIR)/GxSphere.obj \
	$(INTDIR)/CvNormal.obj \
	$(INTDIR)/GxTrnsfm.obj \
	$(INTDIR)/ChTrMonot.obj \
	$(INTDIR)/ChTrMisc.obj \
	$(INTDIR)/ChTriangle.obj \
	$(INTDIR)/ChTrConstr.obj \
	$(INTDIR)/XLINES.OBJ \
	$(INTDIR)/INVERSE.OBJ \
	$(INTDIR)/GxQuaternion.obj

$(OUTDIR)/ChGraphx.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Reality Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Reality_"
# PROP BASE Intermediate_Dir "Reality_"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "\chaco\bin\debug\modules"
# PROP Intermediate_Dir "RealityDebug"
OUTDIR=\chaco\bin\debug\modules
INTDIR=.\RealityDebug

ALL : $(OUTDIR)/ChGraphx.dll $(OUTDIR)/ChGraphx.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /Fr /Yu"grheader.h" /c
# ADD CPP /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /Fr /Yu"grheader.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c 
CPP_OBJS=.\RealityDebug/
# ADD BASE RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo$(INTDIR)/"ChGraphx.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChGraphx.bsc" 
BSC32_SBRS= \
	$(INTDIR)/HEADERS.SBR \
	$(INTDIR)/Dll.sbr \
	$(INTDIR)/ChGraphx.sbr \
	$(INTDIR)/ChGrMod.sbr \
	$(INTDIR)/ChGrDep.sbr \
	$(INTDIR)/ChGrVw.sbr \
	$(INTDIR)/ChPanMod.sbr \
	$(INTDIR)/QvLib.sbr \
	$(INTDIR)/ChAniPrs.sbr \
	$(INTDIR)/ChAnimy.sbr \
	$(INTDIR)/ChAniMod.sbr \
	$(INTDIR)/ChAnimCh.sbr \
	$(INTDIR)/ChAnim.sbr \
	$(INTDIR)/ChAniDep.sbr \
	$(INTDIR)/ChPhSprt.sbr \
	$(INTDIR)/ChSprLst.sbr \
	$(INTDIR)/ChSprite.sbr \
	$(INTDIR)/ChSpLstN.sbr \
	$(INTDIR)/Ch3Dtrvs.sbr \
	$(INTDIR)/Ch3Rendr.sbr \
	$(INTDIR)/ChMazDep.sbr \
	$(INTDIR)/ChMaze.sbr \
	$(INTDIR)/ChMazMod.sbr \
	$(INTDIR)/ChQvStat.sbr \
	$(INTDIR)/CvBound.sbr \
	$(INTDIR)/CvQuery.sbr \
	$(INTDIR)/CvWrite.sbr \
	$(INTDIR)/ChMazePr.sbr \
	$(INTDIR)/ChMazCam.sbr \
	$(INTDIR)/CvTrnsfm.sbr \
	$(INTDIR)/CvHitTst.sbr \
	$(INTDIR)/CvType.sbr \
	$(INTDIR)/CvTextur.sbr \
	$(INTDIR)/CvMaterl.sbr \
	$(INTDIR)/CvLights.sbr \
	$(INTDIR)/CvInstnc.sbr \
	$(INTDIR)/CvShapes.sbr \
	$(INTDIR)/ChAscTxt.sbr \
	$(INTDIR)/ChGrFont.sbr \
	$(INTDIR)/ChSpline.sbr \
	$(INTDIR)/ChColor.sbr \
	$(INTDIR)/CvCamera.sbr \
	$(INTDIR)/CvConvrt.sbr \
	$(INTDIR)/ChRLImg.sbr \
	$(INTDIR)/ChGrStrm.sbr \
	$(INTDIR)/ChQvPars.sbr \
	$(INTDIR)/ChConstruct.sbr \
	$(INTDIR)/ChCollision.sbr \
	$(INTDIR)/ChRenderData.sbr \
	$(INTDIR)/ChVrmlEvent.sbr \
	$(INTDIR)/ChStubBrowser.sbr \
	$(INTDIR)/ChVrmlTransition.sbr \
	$(INTDIR)/ChTransition.sbr \
	$(INTDIR)/ChVrmlSettings.sbr \
	$(INTDIR)/ChVrmlWnd.sbr \
	$(INTDIR)/ChRlabPr.sbr \
	$(INTDIR)/ChThreadMgr.sbr \
	$(INTDIR)/CvSelectors.sbr \
	$(INTDIR)/ChVrmlMenu.sbr \
	$(INTDIR)/ChScriptData.sbr \
	$(INTDIR)/CvGroup.sbr \
	$(INTDIR)/CvBoundsExtent.sbr \
	$(INTDIR)/ChSphere.sbr \
	$(INTDIR)/ChRenderBuffer.sbr \
	$(INTDIR)/ChRCDevice.sbr \
	$(INTDIR)/ChNrCreate.sbr \
	$(INTDIR)/ChMaterialRenderData.sbr \
	$(INTDIR)/GxUtils.sbr \
	$(INTDIR)/GxSphere.sbr \
	$(INTDIR)/CvNormal.sbr \
	$(INTDIR)/GxTrnsfm.sbr \
	$(INTDIR)/ChTrMonot.sbr \
	$(INTDIR)/ChTrMisc.sbr \
	$(INTDIR)/ChTriangle.sbr \
	$(INTDIR)/ChTrConstr.sbr \
	$(INTDIR)/XLINES.SBR \
	$(INTDIR)/INVERSE.SBR \
	$(INTDIR)/GxQuaternion.sbr

$(OUTDIR)/ChGraphx.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 winmm.lib LZ32.lib /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /OUT:"/chaco/bin/debug/ChGraphx.dll" /PDB:"/chaco/bin/debug/ChGraphx.pdb" /IMPLIB:"/chaco/bin/debug/ChGraphx.lib"
# SUBTRACT BASE LINK32 /PROFILE /INCREMENTAL:no
# ADD LINK32 winmm.lib LZ32.lib /NOLOGO /BASE:0x14000000 /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /PDB:"/chaco/bin/debug/ChGraphx.pdb"
# SUBTRACT LINK32 /PDB:none /INCREMENTAL:no /MAP
LINK32_FLAGS=winmm.lib LZ32.lib /NOLOGO /BASE:0x14000000 /SUBSYSTEM:windows\
 /DLL /INCREMENTAL:yes /PDB:$(OUTDIR)/"ChGraphx.pdb" /DEBUG /MACHINE:I386\
 /OUT:$(OUTDIR)/"ChGraphx.dll" /IMPLIB:$(OUTDIR)/"ChGraphx.lib"\
 /PDB:"/chaco/bin/debug/ChGraphx.pdb"  
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/HEADERS.OBJ \
	$(INTDIR)/Dll.obj \
	$(INTDIR)/ChGraphx.obj \
	$(INTDIR)/ChGraphx.res \
	$(INTDIR)/ChGrMod.obj \
	$(INTDIR)/ChGrDep.obj \
	$(INTDIR)/ChGrVw.obj \
	$(INTDIR)/ChPanMod.obj \
	\CHACO\LIB\Pueblo32.lib \
	\CHACO\LIB\PbUtil32.lib \
	\USR\RM\RL20\WIN32\LIB\I386\DYNAMIC\rlddfglu.lib \
	\USR\RM\RL20\WIN32\LIB\I386\DYNAMIC\rlddf.lib \
	\USR\RM\RL20\WIN32\LIB\I386\STATIC\rlff.lib \
	$(INTDIR)/QvLib.obj \
	$(INTDIR)/ChAniPrs.obj \
	$(INTDIR)/ChAnimy.obj \
	$(INTDIR)/ChAniMod.obj \
	$(INTDIR)/ChAnimCh.obj \
	$(INTDIR)/ChAnim.obj \
	$(INTDIR)/ChAniDep.obj \
	$(INTDIR)/ChPhSprt.obj \
	$(INTDIR)/ChSprLst.obj \
	$(INTDIR)/ChSprite.obj \
	$(INTDIR)/ChSpLstN.obj \
	$(INTDIR)/Ch3Dtrvs.obj \
	$(INTDIR)/Ch3Rendr.obj \
	$(INTDIR)/ChMazDep.obj \
	$(INTDIR)/ChMaze.obj \
	$(INTDIR)/ChMazMod.obj \
	$(INTDIR)/ChQvStat.obj \
	$(INTDIR)/CvBound.obj \
	$(INTDIR)/CvQuery.obj \
	$(INTDIR)/CvWrite.obj \
	$(INTDIR)/ChMazePr.obj \
	$(INTDIR)/ChMazCam.obj \
	$(INTDIR)/CvTrnsfm.obj \
	$(INTDIR)/CvHitTst.obj \
	$(INTDIR)/CvType.obj \
	$(INTDIR)/CvTextur.obj \
	$(INTDIR)/CvMaterl.obj \
	$(INTDIR)/CvLights.obj \
	$(INTDIR)/CvInstnc.obj \
	$(INTDIR)/CvShapes.obj \
	$(INTDIR)/ChAscTxt.obj \
	$(INTDIR)/ChGrFont.obj \
	$(INTDIR)/ChSpline.obj \
	$(INTDIR)/ChColor.obj \
	$(INTDIR)/CvCamera.obj \
	$(INTDIR)/CvConvrt.obj \
	$(INTDIR)/ChRLImg.obj \
	$(INTDIR)/ChGrStrm.obj \
	$(INTDIR)/ChQvPars.obj \
	$(INTDIR)/ChConstruct.obj \
	$(INTDIR)/ChCollision.obj \
	$(INTDIR)/ChRenderData.obj \
	$(INTDIR)/ChVrmlEvent.obj \
	$(INTDIR)/ChStubBrowser.obj \
	$(INTDIR)/ChVrmlTransition.obj \
	$(INTDIR)/ChTransition.obj \
	$(INTDIR)/ChVrmlSettings.obj \
	$(INTDIR)/ChVrmlWnd.obj \
	$(INTDIR)/ChRlabPr.obj \
	$(INTDIR)/ChThreadMgr.obj \
	$(INTDIR)/CvSelectors.obj \
	$(INTDIR)/ChVrmlMenu.obj \
	$(INTDIR)/ChScriptData.obj \
	$(INTDIR)/CvGroup.obj \
	$(INTDIR)/CvBoundsExtent.obj \
	$(INTDIR)/ChSphere.obj \
	$(INTDIR)/ChRenderBuffer.obj \
	$(INTDIR)/ChRCDevice.obj \
	$(INTDIR)/ChNrCreate.obj \
	$(INTDIR)/ChMaterialRenderData.obj \
	$(INTDIR)/GxUtils.obj \
	$(INTDIR)/GxSphere.obj \
	$(INTDIR)/CvNormal.obj \
	$(INTDIR)/GxTrnsfm.obj \
	$(INTDIR)/ChTrMonot.obj \
	$(INTDIR)/ChTrMisc.obj \
	$(INTDIR)/ChTriangle.obj \
	$(INTDIR)/ChTrConstr.obj \
	$(INTDIR)/XLINES.OBJ \
	$(INTDIR)/INVERSE.OBJ \
	$(INTDIR)/GxQuaternion.obj

$(OUTDIR)/ChGraphx.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Reality Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Reality_"
# PROP BASE Intermediate_Dir "Reality_"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "/chaco/bin/release/modules"
# PROP Intermediate_Dir "RealityRelease"
OUTDIR=/chaco/bin/release/modules
INTDIR=.\RealityRelease

ALL : $(OUTDIR)/ChGraphx.dll $(OUTDIR)/ChGraphx.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

$(INTDIR) : 
    if not exist $(INTDIR)/nul mkdir $(INTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_USE_RLAB" /D "CH_VRML_EVENTS" /Fr /Yu"grheader.h" /c
# ADD CPP /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Yu"grheader.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c 
CPP_OBJS=.\RealityRelease/
# ADD BASE RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"ChGraphx.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChGraphx.bsc" 
BSC32_SBRS= \
	

$(OUTDIR)/ChGraphx.bsc : $(OUTDIR)  $(BSC32_SBRS)
LINK32=link.exe
# ADD BASE LINK32 winmm.lib LZ32.lib /NOLOGO /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /PDB:"/chaco/bin/debug/ChGraphx.pdb"
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 winmm.lib Pueblo32.lib LZ32.lib /NOLOGO /BASE:0x14000000 /SUBSYSTEM:windows /DLL /INCREMENTAL:no /MACHINE:I386 /PDB:"/chaco/bin/debug/ChGraphx.pdb"
# SUBTRACT LINK32 /PDB:none /DEBUG
LINK32_FLAGS=winmm.lib Pueblo32.lib LZ32.lib /NOLOGO /BASE:0x14000000\
 /SUBSYSTEM:windows /DLL /INCREMENTAL:no /PDB:$(OUTDIR)/"ChGraphx.pdb"\
 /MACHINE:I386 /OUT:$(OUTDIR)/"ChGraphx.dll" /IMPLIB:$(OUTDIR)/"ChGraphx.lib"\
 /PDB:"/chaco/bin/debug/ChGraphx.pdb"  
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/HEADERS.OBJ \
	$(INTDIR)/Dll.obj \
	$(INTDIR)/ChGraphx.obj \
	$(INTDIR)/ChGraphx.res \
	$(INTDIR)/ChGrMod.obj \
	$(INTDIR)/ChGrDep.obj \
	$(INTDIR)/ChGrVw.obj \
	$(INTDIR)/ChPanMod.obj \
	\CHACO\LIB\Pueblo32.lib \
	\CHACO\LIB\PbUtil32.lib \
	\USR\RM\RL20\WIN32\LIB\I386\DYNAMIC\rlddfglu.lib \
	\USR\RM\RL20\WIN32\LIB\I386\DYNAMIC\rlddf.lib \
	\USR\RM\RL20\WIN32\LIB\I386\STATIC\rlff.lib \
	$(INTDIR)/QvLib.obj \
	$(INTDIR)/ChAniPrs.obj \
	$(INTDIR)/ChAnimy.obj \
	$(INTDIR)/ChAniMod.obj \
	$(INTDIR)/ChAnimCh.obj \
	$(INTDIR)/ChAnim.obj \
	$(INTDIR)/ChAniDep.obj \
	$(INTDIR)/ChPhSprt.obj \
	$(INTDIR)/ChSprLst.obj \
	$(INTDIR)/ChSprite.obj \
	$(INTDIR)/ChSpLstN.obj \
	$(INTDIR)/Ch3Dtrvs.obj \
	$(INTDIR)/Ch3Rendr.obj \
	$(INTDIR)/ChMazDep.obj \
	$(INTDIR)/ChMaze.obj \
	$(INTDIR)/ChMazMod.obj \
	$(INTDIR)/ChQvStat.obj \
	$(INTDIR)/CvBound.obj \
	$(INTDIR)/CvQuery.obj \
	$(INTDIR)/CvWrite.obj \
	$(INTDIR)/ChMazePr.obj \
	$(INTDIR)/ChMazCam.obj \
	$(INTDIR)/CvTrnsfm.obj \
	$(INTDIR)/CvHitTst.obj \
	$(INTDIR)/CvType.obj \
	$(INTDIR)/CvTextur.obj \
	$(INTDIR)/CvMaterl.obj \
	$(INTDIR)/CvLights.obj \
	$(INTDIR)/CvInstnc.obj \
	$(INTDIR)/CvShapes.obj \
	$(INTDIR)/ChAscTxt.obj \
	$(INTDIR)/ChGrFont.obj \
	$(INTDIR)/ChSpline.obj \
	$(INTDIR)/ChColor.obj \
	$(INTDIR)/CvCamera.obj \
	$(INTDIR)/CvConvrt.obj \
	$(INTDIR)/ChRLImg.obj \
	$(INTDIR)/ChGrStrm.obj \
	$(INTDIR)/ChQvPars.obj \
	$(INTDIR)/ChConstruct.obj \
	$(INTDIR)/ChCollision.obj \
	$(INTDIR)/ChRenderData.obj \
	$(INTDIR)/ChVrmlEvent.obj \
	$(INTDIR)/ChStubBrowser.obj \
	$(INTDIR)/ChVrmlTransition.obj \
	$(INTDIR)/ChTransition.obj \
	$(INTDIR)/ChVrmlSettings.obj \
	$(INTDIR)/ChVrmlWnd.obj \
	$(INTDIR)/ChRlabPr.obj \
	$(INTDIR)/ChThreadMgr.obj \
	$(INTDIR)/CvSelectors.obj \
	$(INTDIR)/ChVrmlMenu.obj \
	$(INTDIR)/ChScriptData.obj \
	$(INTDIR)/CvGroup.obj \
	$(INTDIR)/CvBoundsExtent.obj \
	$(INTDIR)/ChSphere.obj \
	$(INTDIR)/ChRenderBuffer.obj \
	$(INTDIR)/ChRCDevice.obj \
	$(INTDIR)/ChNrCreate.obj \
	$(INTDIR)/ChMaterialRenderData.obj \
	$(INTDIR)/GxUtils.obj \
	$(INTDIR)/GxSphere.obj \
	$(INTDIR)/CvNormal.obj \
	$(INTDIR)/GxTrnsfm.obj \
	$(INTDIR)/ChTrMonot.obj \
	$(INTDIR)/ChTrMisc.obj \
	$(INTDIR)/ChTriangle.obj \
	$(INTDIR)/ChTrConstr.obj \
	$(INTDIR)/XLINES.OBJ \
	$(INTDIR)/INVERSE.OBJ \
	$(INTDIR)/GxQuaternion.obj

$(OUTDIR)/ChGraphx.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "D3D Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "D3D_Debu"
# PROP BASE Intermediate_Dir "D3D_Debu"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "D3D_Debu"
# PROP Intermediate_Dir "D3D_Debu"
OUTDIR=.\D3D_Debu
INTDIR=.\D3D_Debu

ALL : $(OUTDIR)/ChGraphx.dll $(OUTDIR)/ChGraphx.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_USE_RLAB" /D "CH_VRML_EVENTS" /Fr /Yu"grheader.h" /c
# ADD CPP /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr /Yu"grheader.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c 
CPP_OBJS=.\D3D_Debu/
# ADD BASE RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo$(INTDIR)/"ChGraphx.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"ChGraphx.bsc" 
BSC32_SBRS= \
	$(INTDIR)/HEADERS.SBR \
	$(INTDIR)/Dll.sbr \
	$(INTDIR)/ChGraphx.sbr \
	$(INTDIR)/ChGrMod.sbr \
	$(INTDIR)/ChGrDep.sbr \
	$(INTDIR)/ChGrVw.sbr \
	$(INTDIR)/ChPanMod.sbr \
	$(INTDIR)/QvLib.sbr \
	$(INTDIR)/ChAniPrs.sbr \
	$(INTDIR)/ChAnimy.sbr \
	$(INTDIR)/ChAniMod.sbr \
	$(INTDIR)/ChAnimCh.sbr \
	$(INTDIR)/ChAnim.sbr \
	$(INTDIR)/ChAniDep.sbr \
	$(INTDIR)/ChPhSprt.sbr \
	$(INTDIR)/ChSprLst.sbr \
	$(INTDIR)/ChSprite.sbr \
	$(INTDIR)/ChSpLstN.sbr \
	$(INTDIR)/Ch3Dtrvs.sbr \
	$(INTDIR)/Ch3Rendr.sbr \
	$(INTDIR)/ChMazDep.sbr \
	$(INTDIR)/ChMaze.sbr \
	$(INTDIR)/ChMazMod.sbr \
	$(INTDIR)/ChQvStat.sbr \
	$(INTDIR)/CvBound.sbr \
	$(INTDIR)/CvQuery.sbr \
	$(INTDIR)/CvWrite.sbr \
	$(INTDIR)/ChMazePr.sbr \
	$(INTDIR)/ChMazCam.sbr \
	$(INTDIR)/CvTrnsfm.sbr \
	$(INTDIR)/CvHitTst.sbr \
	$(INTDIR)/CvType.sbr \
	$(INTDIR)/CvTextur.sbr \
	$(INTDIR)/CvMaterl.sbr \
	$(INTDIR)/CvLights.sbr \
	$(INTDIR)/CvInstnc.sbr \
	$(INTDIR)/CvShapes.sbr \
	$(INTDIR)/ChAscTxt.sbr \
	$(INTDIR)/ChGrFont.sbr \
	$(INTDIR)/ChSpline.sbr \
	$(INTDIR)/ChColor.sbr \
	$(INTDIR)/CvCamera.sbr \
	$(INTDIR)/CvConvrt.sbr \
	$(INTDIR)/ChRLImg.sbr \
	$(INTDIR)/ChGrStrm.sbr \
	$(INTDIR)/ChQvPars.sbr \
	$(INTDIR)/ChConstruct.sbr \
	$(INTDIR)/ChCollision.sbr \
	$(INTDIR)/ChRenderData.sbr \
	$(INTDIR)/ChVrmlEvent.sbr \
	$(INTDIR)/ChStubBrowser.sbr \
	$(INTDIR)/ChVrmlTransition.sbr \
	$(INTDIR)/ChTransition.sbr \
	$(INTDIR)/ChVrmlSettings.sbr \
	$(INTDIR)/ChVrmlWnd.sbr \
	$(INTDIR)/ChRlabPr.sbr \
	$(INTDIR)/ChThreadMgr.sbr \
	$(INTDIR)/CvSelectors.sbr \
	$(INTDIR)/ChVrmlMenu.sbr \
	$(INTDIR)/ChScriptData.sbr \
	$(INTDIR)/CvGroup.sbr \
	$(INTDIR)/CvBoundsExtent.sbr \
	$(INTDIR)/ChSphere.sbr \
	$(INTDIR)/ChRenderBuffer.sbr \
	$(INTDIR)/ChRCDevice.sbr \
	$(INTDIR)/ChNrCreate.sbr \
	$(INTDIR)/ChMaterialRenderData.sbr \
	$(INTDIR)/GxUtils.sbr \
	$(INTDIR)/GxSphere.sbr \
	$(INTDIR)/CvNormal.sbr \
	$(INTDIR)/GxTrnsfm.sbr \
	$(INTDIR)/ChTrMonot.sbr \
	$(INTDIR)/ChTrMisc.sbr \
	$(INTDIR)/ChTriangle.sbr \
	$(INTDIR)/ChTrConstr.sbr \
	$(INTDIR)/XLINES.SBR \
	$(INTDIR)/INVERSE.SBR \
	$(INTDIR)/GxQuaternion.sbr

$(OUTDIR)/ChGraphx.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 winmm.lib LZ32.lib /NOLOGO /BASE:0x14000000 /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /PDB:"/chaco/bin/debug/ChGraphx.pdb"
# SUBTRACT BASE LINK32 /PDB:none /INCREMENTAL:no /MAP
# ADD LINK32 winmm.lib LZ32.lib d3drm.lib ddraw.lib /NOLOGO /BASE:0x14000000 /SUBSYSTEM:windows /DLL /DEBUG /MACHINE:I386 /PDB:"/chaco/bin/debug/ChGraphx.pdb"
# SUBTRACT LINK32 /PDB:none /INCREMENTAL:no /MAP
LINK32_FLAGS=winmm.lib LZ32.lib d3drm.lib ddraw.lib /NOLOGO /BASE:0x14000000\
 /SUBSYSTEM:windows /DLL /INCREMENTAL:yes /PDB:$(OUTDIR)/"ChGraphx.pdb" /DEBUG\
 /MACHINE:I386 /OUT:$(OUTDIR)/"ChGraphx.dll" /IMPLIB:$(OUTDIR)/"ChGraphx.lib"\
 /PDB:"/chaco/bin/debug/ChGraphx.pdb"  
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/HEADERS.OBJ \
	$(INTDIR)/Dll.obj \
	$(INTDIR)/ChGraphx.obj \
	$(INTDIR)/ChGraphx.res \
	$(INTDIR)/ChGrMod.obj \
	$(INTDIR)/ChGrDep.obj \
	$(INTDIR)/ChGrVw.obj \
	$(INTDIR)/ChPanMod.obj \
	\CHACO\LIB\Pueblo32.lib \
	\CHACO\LIB\PbUtil32.lib \
	$(INTDIR)/QvLib.obj \
	$(INTDIR)/ChAniPrs.obj \
	$(INTDIR)/ChAnimy.obj \
	$(INTDIR)/ChAniMod.obj \
	$(INTDIR)/ChAnimCh.obj \
	$(INTDIR)/ChAnim.obj \
	$(INTDIR)/ChAniDep.obj \
	$(INTDIR)/ChPhSprt.obj \
	$(INTDIR)/ChSprLst.obj \
	$(INTDIR)/ChSprite.obj \
	$(INTDIR)/ChSpLstN.obj \
	$(INTDIR)/Ch3Dtrvs.obj \
	$(INTDIR)/Ch3Rendr.obj \
	$(INTDIR)/ChMazDep.obj \
	$(INTDIR)/ChMaze.obj \
	$(INTDIR)/ChMazMod.obj \
	$(INTDIR)/ChQvStat.obj \
	$(INTDIR)/CvBound.obj \
	$(INTDIR)/CvQuery.obj \
	$(INTDIR)/CvWrite.obj \
	$(INTDIR)/ChMazePr.obj \
	$(INTDIR)/ChMazCam.obj \
	$(INTDIR)/CvTrnsfm.obj \
	$(INTDIR)/CvHitTst.obj \
	$(INTDIR)/CvType.obj \
	$(INTDIR)/CvTextur.obj \
	$(INTDIR)/CvMaterl.obj \
	$(INTDIR)/CvLights.obj \
	$(INTDIR)/CvInstnc.obj \
	$(INTDIR)/CvShapes.obj \
	$(INTDIR)/ChAscTxt.obj \
	$(INTDIR)/ChGrFont.obj \
	$(INTDIR)/ChSpline.obj \
	$(INTDIR)/ChColor.obj \
	$(INTDIR)/CvCamera.obj \
	$(INTDIR)/CvConvrt.obj \
	$(INTDIR)/ChRLImg.obj \
	$(INTDIR)/ChGrStrm.obj \
	$(INTDIR)/ChQvPars.obj \
	$(INTDIR)/ChConstruct.obj \
	$(INTDIR)/ChCollision.obj \
	$(INTDIR)/ChRenderData.obj \
	$(INTDIR)/ChVrmlEvent.obj \
	$(INTDIR)/ChStubBrowser.obj \
	$(INTDIR)/ChVrmlTransition.obj \
	$(INTDIR)/ChTransition.obj \
	$(INTDIR)/ChVrmlSettings.obj \
	$(INTDIR)/ChVrmlWnd.obj \
	$(INTDIR)/ChRlabPr.obj \
	$(INTDIR)/ChThreadMgr.obj \
	$(INTDIR)/CvSelectors.obj \
	$(INTDIR)/ChVrmlMenu.obj \
	$(INTDIR)/ChScriptData.obj \
	$(INTDIR)/CvGroup.obj \
	$(INTDIR)/CvBoundsExtent.obj \
	$(INTDIR)/ChSphere.obj \
	$(INTDIR)/ChRenderBuffer.obj \
	$(INTDIR)/ChRCDevice.obj \
	$(INTDIR)/ChNrCreate.obj \
	$(INTDIR)/ChMaterialRenderData.obj \
	$(INTDIR)/GxUtils.obj \
	$(INTDIR)/GxSphere.obj \
	$(INTDIR)/CvNormal.obj \
	$(INTDIR)/GxTrnsfm.obj \
	$(INTDIR)/ChTrMonot.obj \
	$(INTDIR)/ChTrMisc.obj \
	$(INTDIR)/ChTriangle.obj \
	$(INTDIR)/ChTrConstr.obj \
	$(INTDIR)/XLINES.OBJ \
	$(INTDIR)/INVERSE.OBJ \
	$(INTDIR)/GxQuaternion.obj

$(OUTDIR)/ChGraphx.dll : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
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

SOURCE=.\HEADERS.CPP
DEP_HEADE=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h

!IF  "$(CFG)" == "Win32 Debug"

# PROP Exclude_From_Build 0
# ADD CPP /W3 /Yc"grheader.h"
# SUBTRACT CPP /Gf /Gy

$(INTDIR)/HEADERS.OBJ :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/\
 /Fp$(OUTDIR)/"ChGraphx.pch" /Yc"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# ADD CPP /Yc"grheader.h"

$(INTDIR)/HEADERS.OBJ :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fp$(OUTDIR)/"ChGraphx.pch"\
 /Yc"grheader.h" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# PROP BASE Exclude_From_Build 0
# PROP Exclude_From_Build 0
# ADD BASE CPP /W3 /Yc"grheader.h"
# SUBTRACT BASE CPP /Gf /Gy
# ADD CPP /W3 /Yc"grheader.h"
# SUBTRACT CPP /Gf /Gy

$(INTDIR)/HEADERS.OBJ :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fp$(OUTDIR)/"ChGraphx.pch" /Yc"grheader.h"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

# PROP BASE Exclude_From_Build 0
# PROP Exclude_From_Build 0
# ADD BASE CPP /W3 /Yc"grheader.h"
# SUBTRACT BASE CPP /Gf /Gy
# ADD CPP /W3 /Yc"grheader.h"
# SUBTRACT CPP /Gf /Gy

$(INTDIR)/HEADERS.OBJ :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fp$(OUTDIR)/"ChGraphx.pch" /Yc"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# PROP BASE Exclude_From_Build 0
# PROP Exclude_From_Build 0
# ADD BASE CPP /W3 /Yc"grheader.h"
# SUBTRACT BASE CPP /Gf /Gy
# ADD CPP /W3 /Yc"grheader.h"
# SUBTRACT CPP /Gf /Gy

$(INTDIR)/HEADERS.OBJ :  $(SOURCE)  $(DEP_HEADE) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fp$(OUTDIR)/"ChGraphx.pch" /Yc"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dll.cpp
DEP_DLL_C=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChGrMod.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	.\ChGrType.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChData.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/Dll.obj :  $(SOURCE)  $(DEP_DLL_C) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/Dll.obj :  $(SOURCE)  $(DEP_DLL_C) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/Dll.obj :  $(SOURCE)  $(DEP_DLL_C) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/Dll.obj :  $(SOURCE)  $(DEP_DLL_C) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/Dll.obj :  $(SOURCE)  $(DEP_DLL_C) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGraphx.cpp
DEP_CHGRA=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrMod.h\
	.\ChPanMod.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChGrVw.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\TEMPLCLS\ChHtpVw.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	.\ChGrType.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChWnd.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChGraphx.obj :  $(SOURCE)  $(DEP_CHGRA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChGraphx.obj :  $(SOURCE)  $(DEP_CHGRA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChGraphx.obj :  $(SOURCE)  $(DEP_CHGRA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChGraphx.obj :  $(SOURCE)  $(DEP_CHGRA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChGraphx.obj :  $(SOURCE)  $(DEP_CHGRA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGraphx.rc
DEP_CHGRAP=\
	.\RES\POINTER.CUR\
	.\RES\HANDMONO.CUR\
	.\RES\ChGraphx.rc2

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChGraphx.res :  $(SOURCE)  $(DEP_CHGRAP) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChGraphx.res :  $(SOURCE)  $(DEP_CHGRAP) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChGraphx.res :  $(SOURCE)  $(DEP_CHGRAP) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChGraphx.res :  $(SOURCE)  $(DEP_CHGRAP) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChGraphx.res :  $(SOURCE)  $(DEP_CHGRAP) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGrMod.cpp
DEP_CHGRM=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChPane.h\
	.\ChGrMod.h\
	.\ChAniDep.h\
	.\ChGrStrm.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\ChAnim.h\
	\CHACO\INCLUDE\ChHttpStream.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	.\ChGrType.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChDb.h\
	.\ChSpritN.h\
	.\ChSprite.h\
	.\ChSpLstN.h\
	.\ChSprLst.h\
	.\ChPhSprt.h\
	\CHACO\INCLUDE\ChDibBmp.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChDC.h\
	\CHACO\INCLUDE\ChScrlVw.h\
	\CHACO\INCLUDE\ChFont.h\
	\CHACO\INCLUDE\ChSize.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChGrMod.obj :  $(SOURCE)  $(DEP_CHGRM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChGrMod.obj :  $(SOURCE)  $(DEP_CHGRM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChGrMod.obj :  $(SOURCE)  $(DEP_CHGRM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChGrMod.obj :  $(SOURCE)  $(DEP_CHGRM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChGrMod.obj :  $(SOURCE)  $(DEP_CHGRM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGrDep.cpp
DEP_CHGRD=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChList.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChMData.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChGrDep.obj :  $(SOURCE)  $(DEP_CHGRD) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChGrDep.obj :  $(SOURCE)  $(DEP_CHGRD) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChGrDep.obj :  $(SOURCE)  $(DEP_CHGRD) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChGrDep.obj :  $(SOURCE)  $(DEP_CHGRD) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChGrDep.obj :  $(SOURCE)  $(DEP_CHGRD) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGrVw.cpp
DEP_CHGRV=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChGrMod.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibBmp.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChDC.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	.\ChGrType.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChScrlVw.h\
	\CHACO\INCLUDE\ChFont.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChSize.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChGrVw.obj :  $(SOURCE)  $(DEP_CHGRV) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChGrVw.obj :  $(SOURCE)  $(DEP_CHGRV) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChGrVw.obj :  $(SOURCE)  $(DEP_CHGRV) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChGrVw.obj :  $(SOURCE)  $(DEP_CHGRV) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChGrVw.obj :  $(SOURCE)  $(DEP_CHGRV) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\USR\3DR\SDK\3DG32.LIB

!IF  "$(CFG)" == "Win32 Debug"

!ELSEIF  "$(CFG)" == "Win32 Release"

!ELSEIF  "$(CFG)" == "Reality Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Reality Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "D3D Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\USR\3DR\SDK\3DR32.LIB

!IF  "$(CFG)" == "Win32 Debug"

!ELSEIF  "$(CFG)" == "Win32 Release"

!ELSEIF  "$(CFG)" == "Reality Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Reality Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "D3D Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPanMod.cpp
DEP_CHPAN=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChCore.h\
	.\ChPanMod.h\
	\CHACO\INCLUDE\ChHtmWnd.h\
	.\ChGrStrm.h\
	\CHACO\INCLUDE\ChUtil.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrMod.h\
	.\TEMPLCLS\ChHtpVw.h\
	\CHACO\INCLUDE\ChHttpStream.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	.\ChGrType.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChPanMod.obj :  $(SOURCE)  $(DEP_CHPAN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChPanMod.obj :  $(SOURCE)  $(DEP_CHPAN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChPanMod.obj :  $(SOURCE)  $(DEP_CHPAN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChPanMod.obj :  $(SOURCE)  $(DEP_CHPAN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChPanMod.obj :  $(SOURCE)  $(DEP_CHPAN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\CHACO\LIB\Pueblo32.lib
# End Source File
################################################################################
# Begin Source File

SOURCE=\CHACO\LIB\PbUtil32.lib
# End Source File
################################################################################
# Begin Source File

SOURCE=\USR\RM\RL20\WIN32\LIB\I386\DYNAMIC\rlddfglu.lib

!IF  "$(CFG)" == "Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Reality Debug"

!ELSEIF  "$(CFG)" == "Reality Release"

!ELSEIF  "$(CFG)" == "D3D Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\USR\RM\RL20\WIN32\LIB\I386\DYNAMIC\rlddf.lib

!IF  "$(CFG)" == "Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Reality Debug"

!ELSEIF  "$(CFG)" == "Reality Release"

!ELSEIF  "$(CFG)" == "D3D Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\USR\RM\RL20\WIN32\LIB\I386\STATIC\rlff.lib

!IF  "$(CFG)" == "Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Reality Debug"

!ELSEIF  "$(CFG)" == "Reality Release"

!ELSEIF  "$(CFG)" == "D3D Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
################################################################################
# Begin Group "Qv"

################################################################################
# Begin Source File

SOURCE=\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvLib.cpp
DEP_QVLIB=\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSpin.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSpinGroup.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvNavigationInfo.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvAsciiText.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvBackground.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvBaseColor.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvDict.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvName.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvPList.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvString.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvChildList.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvCone.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvCoordinate3.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvCube.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvCylinder.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvDB.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvDebugError.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvDirectionalLight.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvElement.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvField.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvFieldData.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvFontStyle.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvGroup.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvIndexedFaceSet.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvIndexedLineSet.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvInfo.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvInput.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvLevelOfDetail.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvLists.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvMFColor.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvMFFloat.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvMFLong.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvMFString.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvMFVec2f.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvMFVec3f.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvMaterial.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvMaterialBinding.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvMatrixTransform.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvNode.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvNormal.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvNormalBinding.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvOrthographicCamera.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvPerspectiveCamera.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvPointLight.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvPointSet.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvReadError.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvRotation.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSFBitMask.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSFBool.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSFColor.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSFEnum.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSFFloat.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSFImage.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSFLong.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSFMatrix.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSFRotation.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSFString.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSFVec2f.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSFVec3f.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvScale.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSeparator.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvShapeHints.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSphere.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSpotLight.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvState.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSwitch.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvTexture2.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvTexture2Transform.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvTextureCoordinate2.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvTransform.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvTransformSeparator.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvTranslation.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvUnknownNode.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvWWWAnchor.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvWWWInline.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSensor.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvTimeSensor.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvInterpolator.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvOrientationInterpolator.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvPositionInterpolator.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSFTime.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvMFTime.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvMFRotation.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvRoute.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvField20.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\VRML\QvSetField.cpp\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvReadError.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvChildList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvUnknownNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDebugError.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFields.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLists.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxQuaternion.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\bin\msvc22\include\sys\types.h

!IF  "$(CFG)" == "Win32 Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/QvLib.obj :  $(SOURCE)  $(DEP_QVLIB) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/ /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# SUBTRACT CPP /Yu

$(INTDIR)/QvLib.obj :  $(SOURCE)  $(DEP_QVLIB) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/QvLib.obj :  $(SOURCE)  $(DEP_QVLIB) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/QvLib.obj :  $(SOURCE)  $(DEP_QVLIB) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/QvLib.obj :  $(SOURCE)  $(DEP_QVLIB) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
# End Group
################################################################################
# Begin Group "2D Animation"

################################################################################
# Begin Source File

SOURCE=.\ChAniPrs.cpp
DEP_CHANI=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChUrlMap.h\
	.\ChGrMod.h\
	.\ChAniPrs.h\
	.\ChAniDep.h\
	.\ChGrStrm.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\ChAnim.h\
	.\ChAnimy.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\INCLUDE\ChHttpStream.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	.\ChGrType.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChDb.h\
	.\ChSpritN.h\
	.\ChSprite.h\
	.\ChSpLstN.h\
	.\ChSprLst.h\
	.\ChPhSprt.h\
	\CHACO\INCLUDE\ChDibBmp.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChDC.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChScrlVw.h\
	\CHACO\INCLUDE\ChFont.h\
	\CHACO\INCLUDE\ChSize.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChAniPrs.obj :  $(SOURCE)  $(DEP_CHANI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 0

$(INTDIR)/ChAniPrs.obj :  $(SOURCE)  $(DEP_CHANI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChAniPrs.obj :  $(SOURCE)  $(DEP_CHANI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChAniPrs.obj :  $(SOURCE)  $(DEP_CHANI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChAniPrs.obj :  $(SOURCE)  $(DEP_CHANI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAnimy.cpp
DEP_CHANIM=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChAnim.h\
	.\ChGrMod.h\
	.\ChAniPrs.h\
	\CHACO\INCLUDE\Values.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChSplay.h\
	.\ChSpritN.h\
	.\ChSprite.h\
	.\ChSpLstN.h\
	.\ChSprLst.h\
	.\ChPhSprt.h\
	\CHACO\INCLUDE\ChDibBmp.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\ChAnimy.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChDC.h\
	.\ChGrType.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChScrlVw.h\
	\CHACO\INCLUDE\ChFont.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChSize.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChAnimy.obj :  $(SOURCE)  $(DEP_CHANIM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 0

$(INTDIR)/ChAnimy.obj :  $(SOURCE)  $(DEP_CHANIM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChAnimy.obj :  $(SOURCE)  $(DEP_CHANIM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChAnimy.obj :  $(SOURCE)  $(DEP_CHANIM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChAnimy.obj :  $(SOURCE)  $(DEP_CHANIM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAniMod.cpp
DEP_CHANIMO=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrMod.h\
	.\ChAniDep.h\
	.\ChGrStrm.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\ChAnim.h\
	\CHACO\INCLUDE\ChHttpStream.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	.\ChGrType.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChDb.h\
	.\ChSpritN.h\
	.\ChSprite.h\
	.\ChSpLstN.h\
	.\ChSprLst.h\
	.\ChPhSprt.h\
	\CHACO\INCLUDE\ChDibBmp.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChDC.h\
	\CHACO\INCLUDE\ChScrlVw.h\
	\CHACO\INCLUDE\ChFont.h\
	\CHACO\INCLUDE\ChSize.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChAniMod.obj :  $(SOURCE)  $(DEP_CHANIMO) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 0

$(INTDIR)/ChAniMod.obj :  $(SOURCE)  $(DEP_CHANIMO) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChAniMod.obj :  $(SOURCE)  $(DEP_CHANIMO) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChAniMod.obj :  $(SOURCE)  $(DEP_CHANIMO) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChAniMod.obj :  $(SOURCE)  $(DEP_CHANIMO) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAnimCh.cpp
DEP_CHANIMC=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChCore.h\
	.\ChGrMod.h\
	.\ChAnim.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChSplay.h\
	.\ChSpritN.h\
	.\ChSprite.h\
	.\ChSpLstN.h\
	.\ChSprLst.h\
	.\ChPhSprt.h\
	\CHACO\INCLUDE\ChDibBmp.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	.\ChGrType.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\ChDC.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChScrlVw.h\
	\CHACO\INCLUDE\ChFont.h\
	\CHACO\INCLUDE\ChSize.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChAnimCh.obj :  $(SOURCE)  $(DEP_CHANIMC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 0

$(INTDIR)/ChAnimCh.obj :  $(SOURCE)  $(DEP_CHANIMC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChAnimCh.obj :  $(SOURCE)  $(DEP_CHANIMC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChAnimCh.obj :  $(SOURCE)  $(DEP_CHANIMC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChAnimCh.obj :  $(SOURCE)  $(DEP_CHANIMC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAnim.cpp
DEP_CHANIM_=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChCore.h\
	.\ChGrMod.h\
	.\ChAniPrs.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChGifDecoder.h\
	\CHACO\INCLUDE\ChJpegDecoder.h\
	\CHACO\INCLUDE\ChUtil.h\
	\CHACO\INCLUDE\ChImgUtil.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\ChAnim.h\
	.\ChAnimy.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChImageDecoder.h\
	\CHACO\INCLUDE\JPEGLIB.H\
	\CHACO\INCLUDE\ChDC.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	.\ChGrType.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\ChSplay.h\
	.\ChSpritN.h\
	.\ChSprite.h\
	.\ChSpLstN.h\
	.\ChSprLst.h\
	.\ChPhSprt.h\
	\CHACO\INCLUDE\ChDibBmp.h\
	\CHACO\INCLUDE\JCONFIG.H\
	\CHACO\INCLUDE\JMORECFG.H\
	\CHACO\INCLUDE\ChScrlVw.h\
	\CHACO\INCLUDE\ChFont.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChSize.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChAnim.obj :  $(SOURCE)  $(DEP_CHANIM_) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 0

$(INTDIR)/ChAnim.obj :  $(SOURCE)  $(DEP_CHANIM_) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChAnim.obj :  $(SOURCE)  $(DEP_CHANIM_) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChAnim.obj :  $(SOURCE)  $(DEP_CHANIM_) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChAnim.obj :  $(SOURCE)  $(DEP_CHANIM_) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAniDep.cpp
DEP_CHANID=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChUrlMap.h\
	.\ChGrMod.h\
	.\ChAniDep.h\
	.\ChAniPrs.h\
	.\ChGrStrm.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\ChAnim.h\
	.\ChAnimy.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\INCLUDE\ChHttpStream.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	.\ChGrType.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChDb.h\
	.\ChSpritN.h\
	.\ChSprite.h\
	.\ChSpLstN.h\
	.\ChSprLst.h\
	.\ChPhSprt.h\
	\CHACO\INCLUDE\ChDibBmp.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChDC.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChScrlVw.h\
	\CHACO\INCLUDE\ChFont.h\
	\CHACO\INCLUDE\ChSize.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChAniDep.obj :  $(SOURCE)  $(DEP_CHANID) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 0

$(INTDIR)/ChAniDep.obj :  $(SOURCE)  $(DEP_CHANID) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChAniDep.obj :  $(SOURCE)  $(DEP_CHANID) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChAniDep.obj :  $(SOURCE)  $(DEP_CHANID) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChAniDep.obj :  $(SOURCE)  $(DEP_CHANID) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPhSprt.cpp
DEP_CHPHS=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChGrVw.h\
	.\ChSpritN.h\
	.\ChSprite.h\
	.\ChPhSprt.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChDibBmp.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChDC.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChScrlVw.h\
	\CHACO\INCLUDE\ChFont.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChSize.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChPhSprt.obj :  $(SOURCE)  $(DEP_CHPHS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 0

$(INTDIR)/ChPhSprt.obj :  $(SOURCE)  $(DEP_CHPHS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChPhSprt.obj :  $(SOURCE)  $(DEP_CHPHS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChPhSprt.obj :  $(SOURCE)  $(DEP_CHPHS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChPhSprt.obj :  $(SOURCE)  $(DEP_CHPHS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSprLst.cpp
DEP_CHSPR=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChGrVw.h\
	.\ChSpritN.h\
	.\ChSprite.h\
	.\ChSpLstN.h\
	.\ChSprLst.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChDibBmp.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChDC.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChScrlVw.h\
	\CHACO\INCLUDE\ChFont.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChSize.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChSprLst.obj :  $(SOURCE)  $(DEP_CHSPR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 0

$(INTDIR)/ChSprLst.obj :  $(SOURCE)  $(DEP_CHSPR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChSprLst.obj :  $(SOURCE)  $(DEP_CHSPR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChSprLst.obj :  $(SOURCE)  $(DEP_CHSPR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChSprLst.obj :  $(SOURCE)  $(DEP_CHSPR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSprite.cpp
DEP_CHSPRI=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChGrVw.h\
	.\ChSpritN.h\
	.\ChSprite.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChDibBmp.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChDC.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChScrlVw.h\
	\CHACO\INCLUDE\ChFont.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChSize.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChSprite.obj :  $(SOURCE)  $(DEP_CHSPRI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 0

$(INTDIR)/ChSprite.obj :  $(SOURCE)  $(DEP_CHSPRI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChSprite.obj :  $(SOURCE)  $(DEP_CHSPRI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChSprite.obj :  $(SOURCE)  $(DEP_CHSPRI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChSprite.obj :  $(SOURCE)  $(DEP_CHSPRI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSpLstN.cpp
DEP_CHSPL=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChAnim.h\
	.\ChSpritN.h\
	.\ChSprite.h\
	.\ChSpLstN.h\
	.\ChSprLst.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChSplay.h\
	.\ChPhSprt.h\
	\CHACO\INCLUDE\ChDibBmp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChDC.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChScrlVw.h\
	\CHACO\INCLUDE\ChFont.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChSize.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChSpLstN.obj :  $(SOURCE)  $(DEP_CHSPL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 0

$(INTDIR)/ChSpLstN.obj :  $(SOURCE)  $(DEP_CHSPL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChSpLstN.obj :  $(SOURCE)  $(DEP_CHSPL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChSpLstN.obj :  $(SOURCE)  $(DEP_CHSPL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChSpLstN.obj :  $(SOURCE)  $(DEP_CHSPL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
# End Group
################################################################################
# Begin Group "3D Vrml"

################################################################################
# Begin Source File

SOURCE=.\Ch3Dtrvs.cpp
DEP_CH3DT=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChCore.h\
	.\ChGrMod.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvUnknownNode.h\
	.\ChMaze.h\
	.\ChMazDep.h\
	.\ChRender.h\
	.\ChSphere.h\
	.\CvType.h\
	.\CvBound.h\
	.\CvConvrt.h\
	.\CvMaterl.h\
	.\CvInstnc.h\
	.\CvTextur.h\
	.\CvQuery.h\
	.\CvTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.h\
	.\ChScriptData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvChildList.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxSphere.h\
	.\ChRenderData.h\
	.\ChRenderBuffer.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLists.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\ChDb.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxUtils.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/Ch3Dtrvs.obj :  $(SOURCE)  $(DEP_CH3DT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/Ch3Dtrvs.obj :  $(SOURCE)  $(DEP_CH3DT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/Ch3Dtrvs.obj :  $(SOURCE)  $(DEP_CH3DT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/Ch3Dtrvs.obj :  $(SOURCE)  $(DEP_CH3DT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/Ch3Dtrvs.obj :  $(SOURCE)  $(DEP_CH3DT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Ch3Rendr.cpp
DEP_CH3RE=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\ChRenderData.h\
	.\ChMazDep.h\
	.\CvConvrt.h\
	.\CvTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.h\
	.\CvInstnc.h\
	.\CvTextur.h\
	.\CvType.h\
	.\CvHitTst.h\
	.\CvMaterl.h\
	.\ChSphere.h\
	.\ChRLImg.h\
	\CHACO\INCLUDE\ChSFImage.h\
	.\ChCollision.h\
	\bin\msvc22\include\sys\timeb.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChUtil.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\CvBound.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxSphere.h\
	.\ChRenderBuffer.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxUtils.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/Ch3Rendr.obj :  $(SOURCE)  $(DEP_CH3RE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/Ch3Rendr.obj :  $(SOURCE)  $(DEP_CH3RE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/Ch3Rendr.obj :  $(SOURCE)  $(DEP_CH3RE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/Ch3Rendr.obj :  $(SOURCE)  $(DEP_CH3RE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/Ch3Rendr.obj :  $(SOURCE)  $(DEP_CH3RE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMazDep.cpp
DEP_CHMAZ=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvChildList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChUtil.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChMaze.h\
	.\ChRenderData.h\
	.\ChMazDep.h\
	.\CvBound.h\
	.\CvQuery.h\
	.\ChRLImg.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLists.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChMazDep.obj :  $(SOURCE)  $(DEP_CHMAZ) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChMazDep.obj :  $(SOURCE)  $(DEP_CHMAZ) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChMazDep.obj :  $(SOURCE)  $(DEP_CHMAZ) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChMazDep.obj :  $(SOURCE)  $(DEP_CHMAZ) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChMazDep.obj :  $(SOURCE)  $(DEP_CHMAZ) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMaze.cpp
DEP_CHMAZE=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChUrlMap.h\
	\CHACO\INCLUDE\ChCore.h\
	.\ChGrMod.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\INCLUDE\ChUtil.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvReadError.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvChildList.h\
	.\ChMaze.h\
	.\ChMazCam.h\
	.\CvHitTst.h\
	.\ChQvPars.h\
	.\ChGrStrm.h\
	.\ChRenderData.h\
	.\ChMazDep.h\
	.\ChStubBrowser.h\
	.\ChVrmlTransition.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLists.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChDibImage.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	.\CvQuery.h\
	.\CvBound.h\
	.\CvInstnc.h\
	\CHACO\INCLUDE\ChHttpStream.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	.\VrmlEvent.h\
	.\ChTransition.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\chaco\include\ChIVRMLViewer.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChMaze.obj :  $(SOURCE)  $(DEP_CHMAZE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChMaze.obj :  $(SOURCE)  $(DEP_CHMAZE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChMaze.obj :  $(SOURCE)  $(DEP_CHMAZE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChMaze.obj :  $(SOURCE)  $(DEP_CHMAZE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChMaze.obj :  $(SOURCE)  $(DEP_CHMAZE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMazMod.cpp
DEP_CHMAZM=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChHtmWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChUtil.h\
	.\ChGrMod.h\
	.\ChVrmlWnd.h\
	.\ChMazDep.h\
	.\ChMazePr.h\
	.\ChRlabPr.h\
	.\ChRenderData.h\
	.\ChStubBrowser.h\
	.\ChVrmlEvent.h\
	.\ChMazCam.h\
	.\ChRLImg.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\ChMaze.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\INCLUDE\ChPage.h\
	.\ChGrType.h\
	.\ChRender.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	.\VrmlEvent.h\
	\chaco\include\ChIVRMLViewer.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	.\CvQuery.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChMazMod.obj :  $(SOURCE)  $(DEP_CHMAZM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChMazMod.obj :  $(SOURCE)  $(DEP_CHMAZM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChMazMod.obj :  $(SOURCE)  $(DEP_CHMAZM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChMazMod.obj :  $(SOURCE)  $(DEP_CHMAZM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChMazMod.obj :  $(SOURCE)  $(DEP_CHMAZM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChQvStat.cpp
DEP_CHQVS=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChQvStat.obj :  $(SOURCE)  $(DEP_CHQVS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChQvStat.obj :  $(SOURCE)  $(DEP_CHQVS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChQvStat.obj :  $(SOURCE)  $(DEP_CHQVS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChQvStat.obj :  $(SOURCE)  $(DEP_CHQVS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChQvStat.obj :  $(SOURCE)  $(DEP_CHQVS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvBound.cpp
DEP_CVBOU=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvUnknownNode.h\
	.\ChMaze.h\
	.\CvBound.h\
	.\CvInstnc.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	.\ChRender.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvBound.obj :  $(SOURCE)  $(DEP_CVBOU) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvBound.obj :  $(SOURCE)  $(DEP_CVBOU) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvBound.obj :  $(SOURCE)  $(DEP_CVBOU) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvBound.obj :  $(SOURCE)  $(DEP_CVBOU) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvBound.obj :  $(SOURCE)  $(DEP_CVBOU) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvQuery.cpp
DEP_CVQUE=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvUnknownNode.h\
	.\ChMaze.h\
	.\CvQuery.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	.\ChRender.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvQuery.obj :  $(SOURCE)  $(DEP_CVQUE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvQuery.obj :  $(SOURCE)  $(DEP_CVQUE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvQuery.obj :  $(SOURCE)  $(DEP_CVQUE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvQuery.obj :  $(SOURCE)  $(DEP_CVQUE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvQuery.obj :  $(SOURCE)  $(DEP_CVQUE) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvWrite.cpp
DEP_CVWRI=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvUnknownNode.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvWrite.obj :  $(SOURCE)  $(DEP_CVWRI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvWrite.obj :  $(SOURCE)  $(DEP_CVWRI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvWrite.obj :  $(SOURCE)  $(DEP_CVWRI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvWrite.obj :  $(SOURCE)  $(DEP_CVWRI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvWrite.obj :  $(SOURCE)  $(DEP_CVWRI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMazePr.cpp
DEP_CHMAZEP=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChMazePr.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChPage.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\ChData.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChMazePr.obj :  $(SOURCE)  $(DEP_CHMAZEP) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChMazePr.obj :  $(SOURCE)  $(DEP_CHMAZEP) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChMazePr.obj :  $(SOURCE)  $(DEP_CHMAZEP) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChMazePr.obj :  $(SOURCE)  $(DEP_CHMAZEP) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChMazePr.obj :  $(SOURCE)  $(DEP_CHMAZEP) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMazCam.cpp
DEP_CHMAZC=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\ChRenderData.h\
	.\ChMazCam.h\
	.\CvTrnsfm.h\
	.\CvBound.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	.\CvQuery.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChMazCam.obj :  $(SOURCE)  $(DEP_CHMAZC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChMazCam.obj :  $(SOURCE)  $(DEP_CHMAZC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChMazCam.obj :  $(SOURCE)  $(DEP_CHMAZC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChMazCam.obj :  $(SOURCE)  $(DEP_CHMAZC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChMazCam.obj :  $(SOURCE)  $(DEP_CHMAZC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvTrnsfm.cpp
DEP_CVTRN=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvUnknownNode.h\
	.\ChMaze.h\
	.\CvTrnsfm.h\
	.\CvConvrt.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	.\ChRender.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvTrnsfm.obj :  $(SOURCE)  $(DEP_CVTRN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvTrnsfm.obj :  $(SOURCE)  $(DEP_CVTRN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvTrnsfm.obj :  $(SOURCE)  $(DEP_CVTRN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvTrnsfm.obj :  $(SOURCE)  $(DEP_CVTRN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvTrnsfm.obj :  $(SOURCE)  $(DEP_CVTRN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvHitTst.cpp
DEP_CVHIT=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvUnknownNode.h\
	.\ChMaze.h\
	.\CvBound.h\
	.\CvHitTst.h\
	.\CvTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	.\CvInstnc.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvHitTst.obj :  $(SOURCE)  $(DEP_CVHIT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvHitTst.obj :  $(SOURCE)  $(DEP_CVHIT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvHitTst.obj :  $(SOURCE)  $(DEP_CVHIT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvHitTst.obj :  $(SOURCE)  $(DEP_CVHIT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvHitTst.obj :  $(SOURCE)  $(DEP_CVHIT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvType.cpp
DEP_CVTYP=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\CvType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvUnknownNode.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvType.obj :  $(SOURCE)  $(DEP_CVTYP) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvType.obj :  $(SOURCE)  $(DEP_CVTYP) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvType.obj :  $(SOURCE)  $(DEP_CVTYP) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvType.obj :  $(SOURCE)  $(DEP_CVTYP) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvType.obj :  $(SOURCE)  $(DEP_CVTYP) $(INTDIR) $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvTextur.cpp
DEP_CVTEX=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\CvInstnc.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\CvBound.h\
	.\CvTextur.h\
	.\ChRenderData.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	.\ChRender.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	.\ChColor.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChWnd.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvTextur.obj :  $(SOURCE)  $(DEP_CVTEX) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvTextur.obj :  $(SOURCE)  $(DEP_CVTEX) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvTextur.obj :  $(SOURCE)  $(DEP_CVTEX) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvTextur.obj :  $(SOURCE)  $(DEP_CVTEX) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvTextur.obj :  $(SOURCE)  $(DEP_CVTEX) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvMaterl.cpp
DEP_CVMAT=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\CvInstnc.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\ChMazDep.h\
	.\CvTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.h\
	.\CvBound.h\
	.\CvMaterl.h\
	.\CvTextur.h\
	.\ChRenderData.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	.\ChRender.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\CvConvrt.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	.\ChColor.h\
	.\TemplCls\ChGrPLst.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChWnd.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvMaterl.obj :  $(SOURCE)  $(DEP_CVMAT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvMaterl.obj :  $(SOURCE)  $(DEP_CVMAT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvMaterl.obj :  $(SOURCE)  $(DEP_CVMAT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvMaterl.obj :  $(SOURCE)  $(DEP_CVMAT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvMaterl.obj :  $(SOURCE)  $(DEP_CVMAT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvLights.cpp
DEP_CVLIG=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\ChMazDep.h\
	.\CvTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.h\
	.\CvConvrt.h\
	.\CvInstnc.h\
	.\CvType.h\
	.\ChRenderData.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	.\TemplCls\ChGrPLst.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvLights.obj :  $(SOURCE)  $(DEP_CVLIG) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvLights.obj :  $(SOURCE)  $(DEP_CVLIG) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvLights.obj :  $(SOURCE)  $(DEP_CVLIG) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvLights.obj :  $(SOURCE)  $(DEP_CVLIG) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvLights.obj :  $(SOURCE)  $(DEP_CVLIG) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvInstnc.cpp
DEP_CVINS=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\CvInstnc.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\ChRenderData.h\
	.\ChScriptData.h\
	.\ChMazDep.h\
	.\CvTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.h\
	.\CvBound.h\
	.\CvConvrt.h\
	.\CvHitTst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	.\ChRender.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChWnd.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvInstnc.obj :  $(SOURCE)  $(DEP_CVINS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvInstnc.obj :  $(SOURCE)  $(DEP_CVINS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvInstnc.obj :  $(SOURCE)  $(DEP_CVINS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvInstnc.obj :  $(SOURCE)  $(DEP_CVINS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvInstnc.obj :  $(SOURCE)  $(DEP_CVINS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvShapes.cpp
DEP_CVSHA=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\CvInstnc.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\ChRenderData.h\
	.\ChMazDep.h\
	.\CvTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.h\
	.\CvBound.h\
	.\CvMaterl.h\
	.\CvTextur.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxSphere.h\
	.\ChSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\ChTriangle.h\
	.\ChRenderBuffer.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	.\ChRender.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\CvConvrt.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxUtils.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	.\ChColor.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChWnd.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvShapes.obj :  $(SOURCE)  $(DEP_CVSHA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvShapes.obj :  $(SOURCE)  $(DEP_CVSHA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvShapes.obj :  $(SOURCE)  $(DEP_CVSHA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvShapes.obj :  $(SOURCE)  $(DEP_CVSHA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvShapes.obj :  $(SOURCE)  $(DEP_CVSHA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAscTxt.cpp
DEP_CHASC=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\CvInstnc.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\ChMazDep.h\
	.\CvTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.h\
	.\CvBound.h\
	.\CvMaterl.h\
	.\CvTextur.h\
	.\ChGrFont.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	.\ChRender.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\CvConvrt.h\
	.\ChSpline.h\
	.\ChPoly.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	.\ChColor.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChWnd.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChAscTxt.obj :  $(SOURCE)  $(DEP_CHASC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChAscTxt.obj :  $(SOURCE)  $(DEP_CHASC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChAscTxt.obj :  $(SOURCE)  $(DEP_CHASC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChAscTxt.obj :  $(SOURCE)  $(DEP_CHASC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChAscTxt.obj :  $(SOURCE)  $(DEP_CHASC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGrFont.cpp
DEP_CHGRF=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChGrFont.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\TrBasic.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChSpline.h\
	.\ChPoly.h\
	\bin\msvc22\include\sys\types.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChGrFont.obj :  $(SOURCE)  $(DEP_CHGRF) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChGrFont.obj :  $(SOURCE)  $(DEP_CHGRF) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChGrFont.obj :  $(SOURCE)  $(DEP_CHGRF) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChGrFont.obj :  $(SOURCE)  $(DEP_CHGRF) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChGrFont.obj :  $(SOURCE)  $(DEP_CHGRF) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSpline.cpp
DEP_CHSPLI=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChSpline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChSpline.obj :  $(SOURCE)  $(DEP_CHSPLI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChSpline.obj :  $(SOURCE)  $(DEP_CHSPLI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChSpline.obj :  $(SOURCE)  $(DEP_CHSPLI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChSpline.obj :  $(SOURCE)  $(DEP_CHSPLI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChSpline.obj :  $(SOURCE)  $(DEP_CHSPLI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChColor.cpp
DEP_CHCOL=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChColor.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChData.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChColor.obj :  $(SOURCE)  $(DEP_CHCOL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChColor.obj :  $(SOURCE)  $(DEP_CHCOL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChColor.obj :  $(SOURCE)  $(DEP_CHCOL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChColor.obj :  $(SOURCE)  $(DEP_CHCOL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChColor.obj :  $(SOURCE)  $(DEP_CHCOL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvCamera.cpp
DEP_CVCAM=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\CvConvrt.h\
	.\CvTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.h\
	.\CvInstnc.h\
	.\CvType.h\
	.\CvBound.h\
	.\ChRenderData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxQuaternion.h\
	.\ChVrmlTransition.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	.\ChTransition.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvCamera.obj :  $(SOURCE)  $(DEP_CVCAM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvCamera.obj :  $(SOURCE)  $(DEP_CVCAM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvCamera.obj :  $(SOURCE)  $(DEP_CVCAM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvCamera.obj :  $(SOURCE)  $(DEP_CVCAM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvCamera.obj :  $(SOURCE)  $(DEP_CVCAM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvConvrt.cpp
DEP_CVCON=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\CvConvrt.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvConvrt.obj :  $(SOURCE)  $(DEP_CVCON) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvConvrt.obj :  $(SOURCE)  $(DEP_CVCON) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvConvrt.obj :  $(SOURCE)  $(DEP_CVCON) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvConvrt.obj :  $(SOURCE)  $(DEP_CVCON) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvConvrt.obj :  $(SOURCE)  $(DEP_CVCON) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRLImg.cpp
DEP_CHRLI=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChMazDep.h\
	.\ChRLImg.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChGrDep.h\
	.\ChMaze.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChList.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChRLImg.obj :  $(SOURCE)  $(DEP_CHRLI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChRLImg.obj :  $(SOURCE)  $(DEP_CHRLI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChRLImg.obj :  $(SOURCE)  $(DEP_CHRLI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChRLImg.obj :  $(SOURCE)  $(DEP_CHRLI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChRLImg.obj :  $(SOURCE)  $(DEP_CHRLI) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGrStrm.cpp
DEP_CHGRS=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\INCLUDE\ChUtil.h\
	\CHACO\INCLUDE\ChUnzip.h\
	\CHACO\INCLUDE\ChDibDecoder.h\
	\CHACO\INCLUDE\ChGifDecoder.h\
	\CHACO\INCLUDE\ChJpegDecoder.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChModule.h\
	.\ChGrMod.h\
	.\ChMaze.h\
	.\ChMazDep.h\
	.\ChRLImg.h\
	.\ChGrStrm.h\
	.\ChRenderData.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\UNZIP.H\
	\CHACO\INCLUDE\ChImageDecoder.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\JPEGLIB.H\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChDibImage.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\INCLUDE\ChHttpStream.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\bin\msvc22\include\sys\types.h\
	\bin\msvc22\include\sys\stat.h\
	\bin\msvc22\include\sys\timeb.h\
	\CHACO\INCLUDE\JCONFIG.H\
	\CHACO\INCLUDE\JMORECFG.H\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChRect.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChGrStrm.obj :  $(SOURCE)  $(DEP_CHGRS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChGrStrm.obj :  $(SOURCE)  $(DEP_CHGRS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChGrStrm.obj :  $(SOURCE)  $(DEP_CHGRS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChGrStrm.obj :  $(SOURCE)  $(DEP_CHGRS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChGrStrm.obj :  $(SOURCE)  $(DEP_CHGRS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChQvPars.cpp
DEP_CHQVP=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChMaze.h\
	.\ChQvPars.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChQvPars.obj :  $(SOURCE)  $(DEP_CHQVP) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChQvPars.obj :  $(SOURCE)  $(DEP_CHQVP) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChQvPars.obj :  $(SOURCE)  $(DEP_CHQVP) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChQvPars.obj :  $(SOURCE)  $(DEP_CHQVP) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChQvPars.obj :  $(SOURCE)  $(DEP_CHQVP) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChConstruct.cpp
DEP_CHCON=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\CvInstnc.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h

!IF  "$(CFG)" == "Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChConstruct.obj :  $(SOURCE)  $(DEP_CHCON) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChConstruct.obj :  $(SOURCE)  $(DEP_CHCON) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChConstruct.obj :  $(SOURCE)  $(DEP_CHCON) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChCollision.cpp
DEP_CHCOLL=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChMaze.h\
	.\CvBound.h\
	.\CvHitTst.h\
	.\CvTrnsfm.h\
	.\ChCollision.h\
	.\ChMazCam.h\
	.\ChRCDevice.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	.\CvInstnc.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\CvQuery.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h

!IF  "$(CFG)" == "Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChCollision.obj :  $(SOURCE)  $(DEP_CHCOLL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChCollision.obj :  $(SOURCE)  $(DEP_CHCOLL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChCollision.obj :  $(SOURCE)  $(DEP_CHCOLL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRenderData.cpp
DEP_CHREN=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\ChRenderData.h\
	.\ChScriptData.h\
	.\ChMazDep.h\
	.\CvConvrt.h\
	.\CvTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.h\
	.\CvInstnc.h\
	.\CvType.h\
	.\CvHitTst.h\
	.\ChSphere.h\
	.\ChRLImg.h\
	\CHACO\INCLUDE\ChSFImage.h\
	.\ChQvPars.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChUtil.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvChildList.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	.\CvBound.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxSphere.h\
	.\ChRenderBuffer.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLists.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxUtils.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChRenderData.obj :  $(SOURCE)  $(DEP_CHREN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChRenderData.obj :  $(SOURCE)  $(DEP_CHREN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChRenderData.obj :  $(SOURCE)  $(DEP_CHREN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChRenderData.obj :  $(SOURCE)  $(DEP_CHREN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChRenderData.obj :  $(SOURCE)  $(DEP_CHREN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChVrmlEvent.cpp
DEP_CHVRM=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\bin\msvc22\include\sys\types.h

!IF  "$(CFG)" == "Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChVrmlEvent.obj :  $(SOURCE)  $(DEP_CHVRM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChVrmlEvent.obj :  $(SOURCE)  $(DEP_CHVRM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChVrmlEvent.obj :  $(SOURCE)  $(DEP_CHVRM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChStubBrowser.cpp
DEP_CHSTU=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChStubBrowser.h\
	.\ChMaze.h\
	.\CvQuery.h\
	.\CvType.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\VrmlEvent.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChRender.h\
	\chaco\include\ChIVRMLViewer.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChStubBrowser.obj :  $(SOURCE)  $(DEP_CHSTU) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChStubBrowser.obj :  $(SOURCE)  $(DEP_CHSTU) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChStubBrowser.obj :  $(SOURCE)  $(DEP_CHSTU) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChStubBrowser.obj :  $(SOURCE)  $(DEP_CHSTU) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChStubBrowser.obj :  $(SOURCE)  $(DEP_CHSTU) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChVrmlTransition.cpp
DEP_CHVRML=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChVrmlTransition.h\
	.\ChMaze.h\
	.\ChMazCam.h\
	.\ChRenderData.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChTransition.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChHook.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	.\CvQuery.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChVrmlTransition.obj :  $(SOURCE)  $(DEP_CHVRML) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChVrmlTransition.obj :  $(SOURCE)  $(DEP_CHVRML) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChVrmlTransition.obj :  $(SOURCE)  $(DEP_CHVRML) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChVrmlTransition.obj :  $(SOURCE)  $(DEP_CHVRML) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChVrmlTransition.obj :  $(SOURCE)  $(DEP_CHVRML) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTransition.cpp
DEP_CHTRA=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChTransition.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChTransition.obj :  $(SOURCE)  $(DEP_CHTRA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChTransition.obj :  $(SOURCE)  $(DEP_CHTRA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChTransition.obj :  $(SOURCE)  $(DEP_CHTRA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChTransition.obj :  $(SOURCE)  $(DEP_CHTRA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChTransition.obj :  $(SOURCE)  $(DEP_CHTRA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChVrmlSettings.cpp
DEP_CHVRMLS=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChCore.h\
	.\ChGrMod.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\INCLUDE\ChUtil.h\
	.\ChMaze.h\
	.\ChMazCam.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChDibImage.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	.\CvQuery.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChVrmlSettings.obj :  $(SOURCE)  $(DEP_CHVRMLS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChVrmlSettings.obj :  $(SOURCE)  $(DEP_CHVRMLS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChVrmlSettings.obj :  $(SOURCE)  $(DEP_CHVRMLS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChVrmlSettings.obj :  $(SOURCE)  $(DEP_CHVRMLS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChVrmlSettings.obj :  $(SOURCE)  $(DEP_CHVRMLS) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChVrmlWnd.cpp
DEP_CHVRMLW=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChVrmlWnd.h\
	.\ChGrMod.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChMaze.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChData.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChVrmlWnd.obj :  $(SOURCE)  $(DEP_CHVRMLW) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChVrmlWnd.obj :  $(SOURCE)  $(DEP_CHVRMLW) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChVrmlWnd.obj :  $(SOURCE)  $(DEP_CHVRMLW) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChVrmlWnd.obj :  $(SOURCE)  $(DEP_CHVRMLW) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChVrmlWnd.obj :  $(SOURCE)  $(DEP_CHVRMLW) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRlabPr.cpp
DEP_CHRLA=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChRlabPr.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChMazePr.h\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChPage.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChDb.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChRlabPr.obj :  $(SOURCE)  $(DEP_CHRLA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChRlabPr.obj :  $(SOURCE)  $(DEP_CHRLA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChRlabPr.obj :  $(SOURCE)  $(DEP_CHRLA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChRlabPr.obj :  $(SOURCE)  $(DEP_CHRLA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChRlabPr.obj :  $(SOURCE)  $(DEP_CHRLA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChThreadMgr.cpp
DEP_CHTHR=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\CvInstnc.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChThreadMgr.obj :  $(SOURCE)  $(DEP_CHTHR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChThreadMgr.obj :  $(SOURCE)  $(DEP_CHTHR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChThreadMgr.obj :  $(SOURCE)  $(DEP_CHTHR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChThreadMgr.obj :  $(SOURCE)  $(DEP_CHTHR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChThreadMgr.obj :  $(SOURCE)  $(DEP_CHTHR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvSelectors.cpp
DEP_CVSEL=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\CvInstnc.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\ChRenderData.h\
	.\ChMazDep.h\
	.\CvTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.h\
	.\CvBound.h\
	.\CvConvrt.h\
	.\CvHitTst.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	.\ChRender.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChWnd.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvSelectors.obj :  $(SOURCE)  $(DEP_CVSEL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvSelectors.obj :  $(SOURCE)  $(DEP_CVSEL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvSelectors.obj :  $(SOURCE)  $(DEP_CVSEL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvSelectors.obj :  $(SOURCE)  $(DEP_CVSEL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvSelectors.obj :  $(SOURCE)  $(DEP_CVSEL) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChVrmlMenu.cpp
DEP_CHVRMLM=\
	\CHACO\INCLUDE\GRHEADER.H\
	\CHACO\INCLUDE\ChReg.h\
	\CHACO\INCLUDE\ChCore.h\
	.\ChGrMod.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\INCLUDE\ChUtil.h\
	.\ChMaze.h\
	.\ChMazCam.h\
	.\ChVrmlTransition.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChDb.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChDispat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChDibImage.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	.\CvQuery.h\
	.\ChTransition.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChWnd.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChVrmlMenu.obj :  $(SOURCE)  $(DEP_CHVRMLM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChVrmlMenu.obj :  $(SOURCE)  $(DEP_CHVRMLM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChVrmlMenu.obj :  $(SOURCE)  $(DEP_CHVRMLM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChVrmlMenu.obj :  $(SOURCE)  $(DEP_CHVRMLM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChVrmlMenu.obj :  $(SOURCE)  $(DEP_CHVRMLM) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChScriptData.cpp
DEP_CHSCR=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChMaze.h\
	.\ChScriptData.h\
	.\CvInstnc.h\
	.\CvType.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	.\ChRenderData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	.\ChColor.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChScriptData.obj :  $(SOURCE)  $(DEP_CHSCR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChScriptData.obj :  $(SOURCE)  $(DEP_CHSCR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChScriptData.obj :  $(SOURCE)  $(DEP_CHSCR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChScriptData.obj :  $(SOURCE)  $(DEP_CHSCR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChScriptData.obj :  $(SOURCE)  $(DEP_CHSCR) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvGroup.cpp
DEP_CVGRO=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\CvInstnc.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\ChRenderData.h\
	.\ChMazDep.h\
	.\CvTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.h\
	.\CvBound.h\
	.\CvConvrt.h\
	.\CvHitTst.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	.\ChRender.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChWnd.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvGroup.obj :  $(SOURCE)  $(DEP_CVGRO) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvGroup.obj :  $(SOURCE)  $(DEP_CVGRO) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvGroup.obj :  $(SOURCE)  $(DEP_CVGRO) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvGroup.obj :  $(SOURCE)  $(DEP_CVGRO) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvGroup.obj :  $(SOURCE)  $(DEP_CVGRO) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvBoundsExtent.cpp
DEP_CVBOUN=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\CvInstnc.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	.\ChMaze.h\
	.\ChRenderData.h\
	.\ChScriptData.h\
	.\ChMazDep.h\
	.\CvTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.h\
	.\CvBound.h\
	.\CvConvrt.h\
	.\CvHitTst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	.\ChRender.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	.\ChGrDep.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.h\
	\CHACO\INCLUDE\TEMPLCLS\ChStrLst.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	.\TemplCls\ChGrPLst.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChWnd.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/CvBoundsExtent.obj :  $(SOURCE)  $(DEP_CVBOUN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/CvBoundsExtent.obj :  $(SOURCE)  $(DEP_CVBOUN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/CvBoundsExtent.obj :  $(SOURCE)  $(DEP_CVBOUN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/CvBoundsExtent.obj :  $(SOURCE)  $(DEP_CVBOUN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/CvBoundsExtent.obj :  $(SOURCE)  $(DEP_CVBOUN) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSphere.cpp
DEP_CHSPH=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChSphere.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxSphere.h\
	.\ChRender.h\
	.\ChRenderData.h\
	.\ChRenderBuffer.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxUtils.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChSphere.obj :  $(SOURCE)  $(DEP_CHSPH) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChSphere.obj :  $(SOURCE)  $(DEP_CHSPH) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChSphere.obj :  $(SOURCE)  $(DEP_CHSPH) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChSphere.obj :  $(SOURCE)  $(DEP_CHSPH) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChSphere.obj :  $(SOURCE)  $(DEP_CHSPH) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRenderBuffer.cpp
DEP_CHREND=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\CvInstnc.h\
	.\ChRenderData.h\
	.\ChRenderBuffer.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\IMODE.H\
	.\ChRender.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\INCLUDE\ChSplay.h\
	.\ChColor.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxUtils.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\INCLUDE\ChData.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChRenderBuffer.obj :  $(SOURCE)  $(DEP_CHREND) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChRenderBuffer.obj :  $(SOURCE)  $(DEP_CHREND) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChRenderBuffer.obj :  $(SOURCE)  $(DEP_CHREND) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChRenderBuffer.obj :  $(SOURCE)  $(DEP_CHREND) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChRenderBuffer.obj :  $(SOURCE)  $(DEP_CHREND) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRCDevice.cpp
DEP_CHRCD=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChMaze.h\
	.\ChRCDevice.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChKeyMap.h\
	.\ChGrType.h\
	\CHACO\INCLUDE\ChGraphx.h\
	\CHACO\INCLUDE\ChGrVw.h\
	\CHACO\INCLUDE\ChDibImage.h\
	\CHACO\INCLUDE\ChHTTP.h\
	.\ChGrRend.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDB.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNodes.h\
	.\ChRender.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChScrWnd.h\
	\CHACO\INCLUDE\ChPane.h\
	\CHACO\INCLUDE\ChImgConsumer.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvAsciiText.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBackground.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBaseColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCube.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCylinder.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDirectionalLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFontStyle.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedLineSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvLevelOfDetail.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterialBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMatrixTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrthographicCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPerspectiveCamera.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPointSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvScale.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpotLight.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSwitch.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTexture2Transform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTextureCoordinate2.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransform.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTransformSeparator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTranslation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWAnchor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpin.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSpinGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvOrientationInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPositionInterpolator.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvTimeSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvRoute.h\
	\CHACO\MODULES\CLIENT\portable\include\QvNavigationInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvEnvironment.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\ChWnd.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBool.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFMatrix.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFImage.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec2f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFRotation.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFTime.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSensor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChRCDevice.obj :  $(SOURCE)  $(DEP_CHRCD) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChRCDevice.obj :  $(SOURCE)  $(DEP_CHRCD) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChRCDevice.obj :  $(SOURCE)  $(DEP_CHRCD) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChRCDevice.obj :  $(SOURCE)  $(DEP_CHRCD) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChRCDevice.obj :  $(SOURCE)  $(DEP_CHRCD) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChNrCreate.cpp
DEP_CHNRC=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChRender.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\INCLUDE\ChData.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChNrCreate.obj :  $(SOURCE)  $(DEP_CHNRC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/\
 /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChNrCreate.obj :  $(SOURCE)  $(DEP_CHNRC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fp$(OUTDIR)/"ChGraphx.pch"\
 /Yu"grheader.h" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/ChNrCreate.obj :  $(SOURCE)  $(DEP_CHNRC) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChNrCreate.obj :  $(SOURCE)  $(DEP_CHNRC) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/ChNrCreate.obj :  $(SOURCE)  $(DEP_CHNRC) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMaterialRenderData.cpp
DEP_CHMAT=\
	\CHACO\INCLUDE\GRHEADER.H\
	.\ChRenderData.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\INCLUDE\ChExcept.h\
	\CHACO\INCLUDE\ChConst.h\
	.\ChRender.h\
	.\ChVrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMaterial.h\
	.\ChGrRend.h\
	\CHACO\INCLUDE\ChSplay.h\
	\CHACO\INCLUDE\ChGraphx.h\
	.\ChGrType.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	.\ChColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInfo.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvWWWInline.h\
	\chaco\include\ChIVRMLViewer.h\
	.\VrmlEvent.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFColor.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RL.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\RLWIN.H\
	\CHACO\INCLUDE\ChRect.h\
	\CHACO\INCLUDE\ChModule.h\
	\CHACO\INCLUDE\ChCore.h\
	\CHACO\INCLUDE\ChMsg.h\
	\CHACO\INCLUDE\ChMsgTyp.h\
	\CHACO\INCLUDE\ChList.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFString.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvGroup.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\INCLUDE\ChStrmbl.h\
	\CHACO\INCLUDE\ChVers.h\
	\CHACO\INCLUDE\ChHook.h\
	\CHACO\INCLUDE\ChClInfo.h\
	\CHACO\INCLUDE\ChPerFrm.h\
	\CHACO\INCLUDE\ChMData.h\
	\CHACO\INCLUDE\ChArch.h\
	\CHACO\INCLUDE\ChTime.h\
	\CHACO\INCLUDE\ChAcct.h\
	\CHACO\INCLUDE\TEMPLCLS\ChLstHlp.inl\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\INCLUDE\ChData.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/ChMaterialRenderData.obj :  $(SOURCE)  $(DEP_CHMAT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/ChMaterialRenderData.obj :  $(SOURCE)  $(DEP_CHMAT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Debug"

$(INTDIR)/ChMaterialRenderData.obj :  $(SOURCE)  $(DEP_CHMAT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "Reality Release"

$(INTDIR)/ChMaterialRenderData.obj :  $(SOURCE)  $(DEP_CHMAT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ELSEIF  "$(CFG)" == "D3D Debug"

$(INTDIR)/ChMaterialRenderData.obj :  $(SOURCE)  $(DEP_CHMAT) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ

!ENDIF 

# End Source File
# End Group
################################################################################
# Begin Group "Portable"

################################################################################
# Begin Source File

SOURCE=\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxUtils.cpp
DEP_GXUTI=\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxUtils.h

!IF  "$(CFG)" == "Win32 Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/GxUtils.obj :  $(SOURCE)  $(DEP_GXUTI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/ /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# SUBTRACT CPP /Yu

$(INTDIR)/GxUtils.obj :  $(SOURCE)  $(DEP_GXUTI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/GxUtils.obj :  $(SOURCE)  $(DEP_GXUTI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/GxUtils.obj :  $(SOURCE)  $(DEP_GXUTI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/GxUtils.obj :  $(SOURCE)  $(DEP_GXUTI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxSphere.cpp
DEP_GXSPH=\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxSphere.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxUtils.h

!IF  "$(CFG)" == "Win32 Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/GxSphere.obj :  $(SOURCE)  $(DEP_GXSPH) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/ /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# SUBTRACT CPP /Yu

$(INTDIR)/GxSphere.obj :  $(SOURCE)  $(DEP_GXSPH) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/GxSphere.obj :  $(SOURCE)  $(DEP_GXSPH) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/GxSphere.obj :  $(SOURCE)  $(DEP_GXSPH) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/GxSphere.obj :  $(SOURCE)  $(DEP_GXSPH) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.cpp
DEP_CVNOR=\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvState.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCoordinate3.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvShapeHints.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNormalBinding.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvCone.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvIndexedFaceSet.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxUtils.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\CvNormal.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvElement.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFVec3f.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFEnum.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFFloat.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSFBitMask.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvMFLong.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvBasic.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvSubField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvFieldData.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvNode.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvString.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvField.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvInput.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvPList.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\QvDict.h

!IF  "$(CFG)" == "Win32 Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/CvNormal.obj :  $(SOURCE)  $(DEP_CVNOR) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/ /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# SUBTRACT CPP /Yu

$(INTDIR)/CvNormal.obj :  $(SOURCE)  $(DEP_CVNOR) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/CvNormal.obj :  $(SOURCE)  $(DEP_CVNOR) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/CvNormal.obj :  $(SOURCE)  $(DEP_CVNOR) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/CvNormal.obj :  $(SOURCE)  $(DEP_CVNOR) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.cpp
DEP_GXTRN=\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DR.H\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\3DG.H\
	.\CvTrnsfm.h

!IF  "$(CFG)" == "Win32 Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/GxTrnsfm.obj :  $(SOURCE)  $(DEP_GXTRN) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/ /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# SUBTRACT CPP /Yu

$(INTDIR)/GxTrnsfm.obj :  $(SOURCE)  $(DEP_GXTRN) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/GxTrnsfm.obj :  $(SOURCE)  $(DEP_GXTRN) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/GxTrnsfm.obj :  $(SOURCE)  $(DEP_GXTRN) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/GxTrnsfm.obj :  $(SOURCE)  $(DEP_GXTRN) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\ChTrMonot.cpp
DEP_CHTRM=\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\ChTriangle.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h

!IF  "$(CFG)" == "Win32 Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/ChTrMonot.obj :  $(SOURCE)  $(DEP_CHTRM) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/ /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# SUBTRACT CPP /Yu

$(INTDIR)/ChTrMonot.obj :  $(SOURCE)  $(DEP_CHTRM) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/ChTrMonot.obj :  $(SOURCE)  $(DEP_CHTRM) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/ChTrMonot.obj :  $(SOURCE)  $(DEP_CHTRM) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/ChTrMonot.obj :  $(SOURCE)  $(DEP_CHTRM) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\ChTrMisc.cpp
DEP_CHTRMI=\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\ChTriangle.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h

!IF  "$(CFG)" == "Win32 Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/ChTrMisc.obj :  $(SOURCE)  $(DEP_CHTRMI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/ /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# SUBTRACT CPP /Yu

$(INTDIR)/ChTrMisc.obj :  $(SOURCE)  $(DEP_CHTRMI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/ChTrMisc.obj :  $(SOURCE)  $(DEP_CHTRMI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/ChTrMisc.obj :  $(SOURCE)  $(DEP_CHTRMI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/ChTrMisc.obj :  $(SOURCE)  $(DEP_CHTRMI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\ChTriangle.cpp
DEP_CHTRI=\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\ChTriangle.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h

!IF  "$(CFG)" == "Win32 Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/ChTriangle.obj :  $(SOURCE)  $(DEP_CHTRI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/ /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# SUBTRACT CPP /Yu

$(INTDIR)/ChTriangle.obj :  $(SOURCE)  $(DEP_CHTRI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/ChTriangle.obj :  $(SOURCE)  $(DEP_CHTRI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/ChTriangle.obj :  $(SOURCE)  $(DEP_CHTRI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/ChTriangle.obj :  $(SOURCE)  $(DEP_CHTRI) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\ChTrConstr.cpp
DEP_CHTRC=\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\ChTriangle.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h

!IF  "$(CFG)" == "Win32 Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/ChTrConstr.obj :  $(SOURCE)  $(DEP_CHTRC) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/ /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# SUBTRACT CPP /Yu

$(INTDIR)/ChTrConstr.obj :  $(SOURCE)  $(DEP_CHTRC) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/ChTrConstr.obj :  $(SOURCE)  $(DEP_CHTRC) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/ChTrConstr.obj :  $(SOURCE)  $(DEP_CHTRC) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/ChTrConstr.obj :  $(SOURCE)  $(DEP_CHTRC) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\XLINES.CPP
DEP_XLINE=\
	\CHACO\MODULES\CLIENT\PORTABLE\INCLUDE\ChTriangle.h\
	\bin\msvc22\include\sys\types.h\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h

!IF  "$(CFG)" == "Win32 Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/XLINES.OBJ :  $(SOURCE)  $(DEP_XLINE) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/ /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# SUBTRACT CPP /Yu

$(INTDIR)/XLINES.OBJ :  $(SOURCE)  $(DEP_XLINE) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/XLINES.OBJ :  $(SOURCE)  $(DEP_XLINE) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/XLINES.OBJ :  $(SOURCE)  $(DEP_XLINE) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/XLINES.OBJ :  $(SOURCE)  $(DEP_XLINE) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\INVERSE.CPP
DEP_INVER=\
	\CHACO\INCLUDE\ChTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTrnsfm.h

!IF  "$(CFG)" == "Win32 Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/INVERSE.OBJ :  $(SOURCE)  $(DEP_INVER) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/ /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# SUBTRACT CPP /Yu

$(INTDIR)/INVERSE.OBJ :  $(SOURCE)  $(DEP_INVER) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/INVERSE.OBJ :  $(SOURCE)  $(DEP_INVER) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/INVERSE.OBJ :  $(SOURCE)  $(DEP_INVER) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/INVERSE.OBJ :  $(SOURCE)  $(DEP_INVER) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxQuaternion.cpp
DEP_GXQUA=\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxQuaternion.h\
	\CHACO\MODULES\CLIENT\PORTABLE\ChGraphx\GxTypes.h

!IF  "$(CFG)" == "Win32 Debug"

$(INTDIR)/GxQuaternion.obj :  $(SOURCE)  $(DEP_GXQUA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fr$(INTDIR)/\
 /Fp$(OUTDIR)/"ChGraphx.pch" /Yu"grheader.h" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

$(INTDIR)/GxQuaternion.obj :  $(SOURCE)  $(DEP_GXQUA) $(INTDIR)\
 $(INTDIR)/HEADERS.OBJ
   $(CPP) /nologo /MD /W3 /GX /Ow /Oi /Os /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /Fp$(OUTDIR)/"ChGraphx.pch"\
 /Yu"grheader.h" /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Debug"

# SUBTRACT CPP /Yu

$(INTDIR)/GxQuaternion.obj :  $(SOURCE)  $(DEP_GXQUA) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D\
 "CH_IMMED_MODE" /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Reality Release"

# SUBTRACT CPP /Yu

$(INTDIR)/GxQuaternion.obj :  $(SOURCE)  $(DEP_GXQUA) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

$(INTDIR)/GxQuaternion.obj :  $(SOURCE)  $(DEP_GXQUA) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS"\
 /Fr$(INTDIR)/ /Fo$(INTDIR)/ /Fd$(OUTDIR)/"ChGraphx.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
# End Group
# End Project
################################################################################
