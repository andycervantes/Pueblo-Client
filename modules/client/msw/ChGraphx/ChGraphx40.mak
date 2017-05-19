# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=ChGraphx - Win32 Reality Debug
!MESSAGE No configuration specified.  Defaulting to ChGraphx - Win32 Reality\
 Debug.
!ENDIF 

!IF "$(CFG)" != "ChGraphx - Win32 Reality Debug" && "$(CFG)" !=\
 "ChGraphx - Win32 Reality Release" && "$(CFG)" != "ChGraphx - Win32 D3D Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "ChGraphx40.mak" CFG="ChGraphx - Win32 Reality Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ChGraphx - Win32 Reality Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ChGraphx - Win32 Reality Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ChGraphx - Win32 D3D Debug" (based on\
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
# PROP Target_Last_Scanned "ChGraphx - Win32 Reality Debug"
RSC=rc.exe
CPP=cl.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

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

ALL : "$(OUTDIR)\ChGraphx.dll"

CLEAN : 
	-@erase "$(INTDIR)\Ch3Dtrvs.obj"
	-@erase "$(INTDIR)\Ch3Rendr.obj"
	-@erase "$(INTDIR)\ChAniDep.obj"
	-@erase "$(INTDIR)\ChAnim.obj"
	-@erase "$(INTDIR)\ChAnimCh.obj"
	-@erase "$(INTDIR)\ChAniMod.obj"
	-@erase "$(INTDIR)\ChAnimy.obj"
	-@erase "$(INTDIR)\ChAniPrs.obj"
	-@erase "$(INTDIR)\ChAscTxt.obj"
	-@erase "$(INTDIR)\ChCollision.obj"
	-@erase "$(INTDIR)\ChColor.obj"
	-@erase "$(INTDIR)\ChConstruct.obj"
	-@erase "$(INTDIR)\ChGraphx.obj"
	-@erase "$(INTDIR)\ChGraphx.res"
	-@erase "$(INTDIR)\ChGraphx40.pch"
	-@erase "$(INTDIR)\ChGrDep.obj"
	-@erase "$(INTDIR)\ChGrFont.obj"
	-@erase "$(INTDIR)\ChGrMod.obj"
	-@erase "$(INTDIR)\ChGrStrm.obj"
	-@erase "$(INTDIR)\ChGrVw.obj"
	-@erase "$(INTDIR)\ChMaterialRenderData.obj"
	-@erase "$(INTDIR)\ChMazCam.obj"
	-@erase "$(INTDIR)\ChMazDep.obj"
	-@erase "$(INTDIR)\ChMaze.obj"
	-@erase "$(INTDIR)\ChMazePr.obj"
	-@erase "$(INTDIR)\ChMazMod.obj"
	-@erase "$(INTDIR)\ChNrCreate.obj"
	-@erase "$(INTDIR)\ChPanMod.obj"
	-@erase "$(INTDIR)\ChPhSprt.obj"
	-@erase "$(INTDIR)\ChQvPars.obj"
	-@erase "$(INTDIR)\ChQvStat.obj"
	-@erase "$(INTDIR)\ChRCDevice.obj"
	-@erase "$(INTDIR)\ChRenderBuffer.obj"
	-@erase "$(INTDIR)\ChRenderData.obj"
	-@erase "$(INTDIR)\ChRlabPr.obj"
	-@erase "$(INTDIR)\ChRLImg.obj"
	-@erase "$(INTDIR)\ChScriptData.obj"
	-@erase "$(INTDIR)\ChSphere.obj"
	-@erase "$(INTDIR)\ChSpline.obj"
	-@erase "$(INTDIR)\ChSpLstN.obj"
	-@erase "$(INTDIR)\ChSprite.obj"
	-@erase "$(INTDIR)\ChSprLst.obj"
	-@erase "$(INTDIR)\ChStubBrowser.obj"
	-@erase "$(INTDIR)\ChThreadMgr.obj"
	-@erase "$(INTDIR)\ChTransition.obj"
	-@erase "$(INTDIR)\ChTrConstr.obj"
	-@erase "$(INTDIR)\ChTriangle.obj"
	-@erase "$(INTDIR)\ChTrMisc.obj"
	-@erase "$(INTDIR)\ChTrMonot.obj"
	-@erase "$(INTDIR)\ChVrmlEvent.obj"
	-@erase "$(INTDIR)\ChVrmlMenu.obj"
	-@erase "$(INTDIR)\ChVrmlSettings.obj"
	-@erase "$(INTDIR)\ChVrmlTransition.obj"
	-@erase "$(INTDIR)\chvrmlwnd.obj"
	-@erase "$(INTDIR)\CvBound.obj"
	-@erase "$(INTDIR)\CvBoundsExtent.obj"
	-@erase "$(INTDIR)\CvCamera.obj"
	-@erase "$(INTDIR)\CvConvrt.obj"
	-@erase "$(INTDIR)\CvGroup.obj"
	-@erase "$(INTDIR)\CvHitTst.obj"
	-@erase "$(INTDIR)\CvInstnc.obj"
	-@erase "$(INTDIR)\CvLights.obj"
	-@erase "$(INTDIR)\CvMaterl.obj"
	-@erase "$(INTDIR)\CvNormal.obj"
	-@erase "$(INTDIR)\CvQuery.obj"
	-@erase "$(INTDIR)\CvSelectors.obj"
	-@erase "$(INTDIR)\CvShapes.obj"
	-@erase "$(INTDIR)\CvTextur.obj"
	-@erase "$(INTDIR)\CvTrnsfm.obj"
	-@erase "$(INTDIR)\CvType.obj"
	-@erase "$(INTDIR)\CvWrite.obj"
	-@erase "$(INTDIR)\Dll.obj"
	-@erase "$(INTDIR)\GxQuaternion.obj"
	-@erase "$(INTDIR)\GxSphere.obj"
	-@erase "$(INTDIR)\GxTrnsfm.obj"
	-@erase "$(INTDIR)\GxUtils.obj"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(INTDIR)\inverse.obj"
	-@erase "$(INTDIR)\QvLib.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\xlines.obj"
	-@erase "$(OUTDIR)\ChGraphx.dll"
	-@erase "$(OUTDIR)\ChGraphx.exp"
	-@erase "$(OUTDIR)\ChGraphx.ilk"
	-@erase "$(OUTDIR)\ChGraphx.lib"
	-@erase "$(OUTDIR)\ChGraphx.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D "CH_USE_3DR" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /Fr /Yu"grheader.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"grheader.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/ChGraphx40.pch" /Yu"grheader.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\RealityDebug/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo"$(INTDIR)/ChGraphx.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/ChGraphx40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 winmm.lib LZ32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /OUT:"/chaco/bin/debug/ChGraphx.dll" /PDB:"/chaco/bin/debug/ChGraphx.pdb" /IMPLIB:"/chaco/bin/debug/ChGraphx.lib"
# SUBTRACT BASE LINK32 /profile /incremental:no
# ADD LINK32 winmm.lib LZ32.lib /nologo /base:0x14000000 /subsystem:windows /dll /debug /machine:I386 /out:"\chaco\bin\debug\modules/ChGraphx.dll" /PDB:"/chaco/bin/debug/ChGraphx.pdb"
# SUBTRACT LINK32 /pdb:none /incremental:no /map
LINK32_FLAGS=winmm.lib LZ32.lib /nologo /base:0x14000000 /subsystem:windows\
 /dll /incremental:yes /pdb:"$(OUTDIR)/ChGraphx.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/ChGraphx.dll" /implib:"$(OUTDIR)/ChGraphx.lib"\
 /PDB:"/chaco/bin/debug/ChGraphx.pdb" 
LINK32_OBJS= \
	"$(INTDIR)\Ch3Dtrvs.obj" \
	"$(INTDIR)\Ch3Rendr.obj" \
	"$(INTDIR)\ChAniDep.obj" \
	"$(INTDIR)\ChAnim.obj" \
	"$(INTDIR)\ChAnimCh.obj" \
	"$(INTDIR)\ChAniMod.obj" \
	"$(INTDIR)\ChAnimy.obj" \
	"$(INTDIR)\ChAniPrs.obj" \
	"$(INTDIR)\ChAscTxt.obj" \
	"$(INTDIR)\ChCollision.obj" \
	"$(INTDIR)\ChColor.obj" \
	"$(INTDIR)\ChConstruct.obj" \
	"$(INTDIR)\ChGraphx.obj" \
	"$(INTDIR)\ChGraphx.res" \
	"$(INTDIR)\ChGrDep.obj" \
	"$(INTDIR)\ChGrFont.obj" \
	"$(INTDIR)\ChGrMod.obj" \
	"$(INTDIR)\ChGrStrm.obj" \
	"$(INTDIR)\ChGrVw.obj" \
	"$(INTDIR)\ChMaterialRenderData.obj" \
	"$(INTDIR)\ChMazCam.obj" \
	"$(INTDIR)\ChMazDep.obj" \
	"$(INTDIR)\ChMaze.obj" \
	"$(INTDIR)\ChMazePr.obj" \
	"$(INTDIR)\ChMazMod.obj" \
	"$(INTDIR)\ChNrCreate.obj" \
	"$(INTDIR)\ChPanMod.obj" \
	"$(INTDIR)\ChPhSprt.obj" \
	"$(INTDIR)\ChQvPars.obj" \
	"$(INTDIR)\ChQvStat.obj" \
	"$(INTDIR)\ChRCDevice.obj" \
	"$(INTDIR)\ChRenderBuffer.obj" \
	"$(INTDIR)\ChRenderData.obj" \
	"$(INTDIR)\ChRlabPr.obj" \
	"$(INTDIR)\ChRLImg.obj" \
	"$(INTDIR)\ChScriptData.obj" \
	"$(INTDIR)\ChSphere.obj" \
	"$(INTDIR)\ChSpline.obj" \
	"$(INTDIR)\ChSpLstN.obj" \
	"$(INTDIR)\ChSprite.obj" \
	"$(INTDIR)\ChSprLst.obj" \
	"$(INTDIR)\ChStubBrowser.obj" \
	"$(INTDIR)\ChThreadMgr.obj" \
	"$(INTDIR)\ChTransition.obj" \
	"$(INTDIR)\ChTrConstr.obj" \
	"$(INTDIR)\ChTriangle.obj" \
	"$(INTDIR)\ChTrMisc.obj" \
	"$(INTDIR)\ChTrMonot.obj" \
	"$(INTDIR)\ChVrmlEvent.obj" \
	"$(INTDIR)\ChVrmlMenu.obj" \
	"$(INTDIR)\ChVrmlSettings.obj" \
	"$(INTDIR)\ChVrmlTransition.obj" \
	"$(INTDIR)\chvrmlwnd.obj" \
	"$(INTDIR)\CvBound.obj" \
	"$(INTDIR)\CvBoundsExtent.obj" \
	"$(INTDIR)\CvCamera.obj" \
	"$(INTDIR)\CvConvrt.obj" \
	"$(INTDIR)\CvGroup.obj" \
	"$(INTDIR)\CvHitTst.obj" \
	"$(INTDIR)\CvInstnc.obj" \
	"$(INTDIR)\CvLights.obj" \
	"$(INTDIR)\CvMaterl.obj" \
	"$(INTDIR)\CvNormal.obj" \
	"$(INTDIR)\CvQuery.obj" \
	"$(INTDIR)\CvSelectors.obj" \
	"$(INTDIR)\CvShapes.obj" \
	"$(INTDIR)\CvTextur.obj" \
	"$(INTDIR)\CvTrnsfm.obj" \
	"$(INTDIR)\CvType.obj" \
	"$(INTDIR)\CvWrite.obj" \
	"$(INTDIR)\Dll.obj" \
	"$(INTDIR)\GxQuaternion.obj" \
	"$(INTDIR)\GxSphere.obj" \
	"$(INTDIR)\GxTrnsfm.obj" \
	"$(INTDIR)\GxUtils.obj" \
	"$(INTDIR)\headers.obj" \
	"$(INTDIR)\inverse.obj" \
	"$(INTDIR)\QvLib.obj" \
	"$(INTDIR)\xlines.obj" \
	"..\..\..\..\..\usr\rm\RL20\WIN32\LIB\I386\DYNAMIC\rlddf.lib" \
	"..\..\..\..\..\usr\rm\RL20\WIN32\LIB\I386\DYNAMIC\rlddfglu.lib" \
	"..\..\..\..\..\usr\rm\RL20\WIN32\LIB\I386\STATIC\rlff.lib" \
	"..\..\..\..\lib\PbUtil32.lib" \
	"..\..\..\..\lib\Pueblo32.lib"

"$(OUTDIR)\ChGraphx.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

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

ALL : "$(OUTDIR)\ChGraphx.dll"

CLEAN : 
	-@erase "$(INTDIR)\Ch3Dtrvs.obj"
	-@erase "$(INTDIR)\Ch3Rendr.obj"
	-@erase "$(INTDIR)\ChAniDep.obj"
	-@erase "$(INTDIR)\ChAnim.obj"
	-@erase "$(INTDIR)\ChAnimCh.obj"
	-@erase "$(INTDIR)\ChAniMod.obj"
	-@erase "$(INTDIR)\ChAnimy.obj"
	-@erase "$(INTDIR)\ChAniPrs.obj"
	-@erase "$(INTDIR)\ChAscTxt.obj"
	-@erase "$(INTDIR)\ChCollision.obj"
	-@erase "$(INTDIR)\ChColor.obj"
	-@erase "$(INTDIR)\ChConstruct.obj"
	-@erase "$(INTDIR)\ChGraphx.obj"
	-@erase "$(INTDIR)\ChGraphx.res"
	-@erase "$(INTDIR)\ChGraphx40.pch"
	-@erase "$(INTDIR)\ChGrDep.obj"
	-@erase "$(INTDIR)\ChGrFont.obj"
	-@erase "$(INTDIR)\ChGrMod.obj"
	-@erase "$(INTDIR)\ChGrStrm.obj"
	-@erase "$(INTDIR)\ChGrVw.obj"
	-@erase "$(INTDIR)\ChMaterialRenderData.obj"
	-@erase "$(INTDIR)\ChMazCam.obj"
	-@erase "$(INTDIR)\ChMazDep.obj"
	-@erase "$(INTDIR)\ChMaze.obj"
	-@erase "$(INTDIR)\ChMazePr.obj"
	-@erase "$(INTDIR)\ChMazMod.obj"
	-@erase "$(INTDIR)\ChNrCreate.obj"
	-@erase "$(INTDIR)\ChPanMod.obj"
	-@erase "$(INTDIR)\ChPhSprt.obj"
	-@erase "$(INTDIR)\ChQvPars.obj"
	-@erase "$(INTDIR)\ChQvStat.obj"
	-@erase "$(INTDIR)\ChRCDevice.obj"
	-@erase "$(INTDIR)\ChRenderBuffer.obj"
	-@erase "$(INTDIR)\ChRenderData.obj"
	-@erase "$(INTDIR)\ChRlabPr.obj"
	-@erase "$(INTDIR)\ChRLImg.obj"
	-@erase "$(INTDIR)\ChScriptData.obj"
	-@erase "$(INTDIR)\ChSphere.obj"
	-@erase "$(INTDIR)\ChSpline.obj"
	-@erase "$(INTDIR)\ChSpLstN.obj"
	-@erase "$(INTDIR)\ChSprite.obj"
	-@erase "$(INTDIR)\ChSprLst.obj"
	-@erase "$(INTDIR)\ChStubBrowser.obj"
	-@erase "$(INTDIR)\ChThreadMgr.obj"
	-@erase "$(INTDIR)\ChTransition.obj"
	-@erase "$(INTDIR)\ChTrConstr.obj"
	-@erase "$(INTDIR)\ChTriangle.obj"
	-@erase "$(INTDIR)\ChTrMisc.obj"
	-@erase "$(INTDIR)\ChTrMonot.obj"
	-@erase "$(INTDIR)\ChVrmlEvent.obj"
	-@erase "$(INTDIR)\ChVrmlMenu.obj"
	-@erase "$(INTDIR)\ChVrmlSettings.obj"
	-@erase "$(INTDIR)\ChVrmlTransition.obj"
	-@erase "$(INTDIR)\chvrmlwnd.obj"
	-@erase "$(INTDIR)\CvBound.obj"
	-@erase "$(INTDIR)\CvBoundsExtent.obj"
	-@erase "$(INTDIR)\CvCamera.obj"
	-@erase "$(INTDIR)\CvConvrt.obj"
	-@erase "$(INTDIR)\CvGroup.obj"
	-@erase "$(INTDIR)\CvHitTst.obj"
	-@erase "$(INTDIR)\CvInstnc.obj"
	-@erase "$(INTDIR)\CvLights.obj"
	-@erase "$(INTDIR)\CvMaterl.obj"
	-@erase "$(INTDIR)\CvNormal.obj"
	-@erase "$(INTDIR)\CvQuery.obj"
	-@erase "$(INTDIR)\CvSelectors.obj"
	-@erase "$(INTDIR)\CvShapes.obj"
	-@erase "$(INTDIR)\CvTextur.obj"
	-@erase "$(INTDIR)\CvTrnsfm.obj"
	-@erase "$(INTDIR)\CvType.obj"
	-@erase "$(INTDIR)\CvWrite.obj"
	-@erase "$(INTDIR)\Dll.obj"
	-@erase "$(INTDIR)\GxQuaternion.obj"
	-@erase "$(INTDIR)\GxSphere.obj"
	-@erase "$(INTDIR)\GxTrnsfm.obj"
	-@erase "$(INTDIR)\GxUtils.obj"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(INTDIR)\inverse.obj"
	-@erase "$(INTDIR)\QvLib.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\xlines.obj"
	-@erase "$(OUTDIR)\ChGraphx.dll"
	-@erase "$(OUTDIR)\ChGraphx.exp"
	-@erase "$(OUTDIR)\ChGraphx.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

$(OUTDIR)/ChGraphx.bsc : $(OUTDIR)  $(BSC32_SBRS)
# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_USE_RLAB" /D "CH_VRML_EVENTS" /Fr /Yu"grheader.h" /c
# ADD CPP /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"grheader.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fp"$(INTDIR)/ChGraphx40.pch" /Yu"grheader.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\RealityRelease/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/ChGraphx.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/ChGraphx40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 winmm.lib LZ32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /PDB:"/chaco/bin/debug/ChGraphx.pdb"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib Pueblo32.lib LZ32.lib /nologo /base:0x14000000 /subsystem:windows /dll /incremental:no /machine:I386 /out:"\chaco\bin\release\modules/ChGraphx.dll" /implib:"/chaco/bin/release/modules/ChGraphx.lib"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=winmm.lib Pueblo32.lib LZ32.lib /nologo /base:0x14000000\
 /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)/ChGraphx.pdb"\
 /machine:I386 /out:"$(OUTDIR)/ChGraphx.dll" /implib:"$(OUTDIR)/ChGraphx.lib"\
 /implib:"/chaco/bin/release/modules/ChGraphx.lib" 
LINK32_OBJS= \
	"$(INTDIR)\Ch3Dtrvs.obj" \
	"$(INTDIR)\Ch3Rendr.obj" \
	"$(INTDIR)\ChAniDep.obj" \
	"$(INTDIR)\ChAnim.obj" \
	"$(INTDIR)\ChAnimCh.obj" \
	"$(INTDIR)\ChAniMod.obj" \
	"$(INTDIR)\ChAnimy.obj" \
	"$(INTDIR)\ChAniPrs.obj" \
	"$(INTDIR)\ChAscTxt.obj" \
	"$(INTDIR)\ChCollision.obj" \
	"$(INTDIR)\ChColor.obj" \
	"$(INTDIR)\ChConstruct.obj" \
	"$(INTDIR)\ChGraphx.obj" \
	"$(INTDIR)\ChGraphx.res" \
	"$(INTDIR)\ChGrDep.obj" \
	"$(INTDIR)\ChGrFont.obj" \
	"$(INTDIR)\ChGrMod.obj" \
	"$(INTDIR)\ChGrStrm.obj" \
	"$(INTDIR)\ChGrVw.obj" \
	"$(INTDIR)\ChMaterialRenderData.obj" \
	"$(INTDIR)\ChMazCam.obj" \
	"$(INTDIR)\ChMazDep.obj" \
	"$(INTDIR)\ChMaze.obj" \
	"$(INTDIR)\ChMazePr.obj" \
	"$(INTDIR)\ChMazMod.obj" \
	"$(INTDIR)\ChNrCreate.obj" \
	"$(INTDIR)\ChPanMod.obj" \
	"$(INTDIR)\ChPhSprt.obj" \
	"$(INTDIR)\ChQvPars.obj" \
	"$(INTDIR)\ChQvStat.obj" \
	"$(INTDIR)\ChRCDevice.obj" \
	"$(INTDIR)\ChRenderBuffer.obj" \
	"$(INTDIR)\ChRenderData.obj" \
	"$(INTDIR)\ChRlabPr.obj" \
	"$(INTDIR)\ChRLImg.obj" \
	"$(INTDIR)\ChScriptData.obj" \
	"$(INTDIR)\ChSphere.obj" \
	"$(INTDIR)\ChSpline.obj" \
	"$(INTDIR)\ChSpLstN.obj" \
	"$(INTDIR)\ChSprite.obj" \
	"$(INTDIR)\ChSprLst.obj" \
	"$(INTDIR)\ChStubBrowser.obj" \
	"$(INTDIR)\ChThreadMgr.obj" \
	"$(INTDIR)\ChTransition.obj" \
	"$(INTDIR)\ChTrConstr.obj" \
	"$(INTDIR)\ChTriangle.obj" \
	"$(INTDIR)\ChTrMisc.obj" \
	"$(INTDIR)\ChTrMonot.obj" \
	"$(INTDIR)\ChVrmlEvent.obj" \
	"$(INTDIR)\ChVrmlMenu.obj" \
	"$(INTDIR)\ChVrmlSettings.obj" \
	"$(INTDIR)\ChVrmlTransition.obj" \
	"$(INTDIR)\chvrmlwnd.obj" \
	"$(INTDIR)\CvBound.obj" \
	"$(INTDIR)\CvBoundsExtent.obj" \
	"$(INTDIR)\CvCamera.obj" \
	"$(INTDIR)\CvConvrt.obj" \
	"$(INTDIR)\CvGroup.obj" \
	"$(INTDIR)\CvHitTst.obj" \
	"$(INTDIR)\CvInstnc.obj" \
	"$(INTDIR)\CvLights.obj" \
	"$(INTDIR)\CvMaterl.obj" \
	"$(INTDIR)\CvNormal.obj" \
	"$(INTDIR)\CvQuery.obj" \
	"$(INTDIR)\CvSelectors.obj" \
	"$(INTDIR)\CvShapes.obj" \
	"$(INTDIR)\CvTextur.obj" \
	"$(INTDIR)\CvTrnsfm.obj" \
	"$(INTDIR)\CvType.obj" \
	"$(INTDIR)\CvWrite.obj" \
	"$(INTDIR)\Dll.obj" \
	"$(INTDIR)\GxQuaternion.obj" \
	"$(INTDIR)\GxSphere.obj" \
	"$(INTDIR)\GxTrnsfm.obj" \
	"$(INTDIR)\GxUtils.obj" \
	"$(INTDIR)\headers.obj" \
	"$(INTDIR)\inverse.obj" \
	"$(INTDIR)\QvLib.obj" \
	"$(INTDIR)\xlines.obj" \
	"..\..\..\..\..\usr\rm\RL20\WIN32\LIB\I386\DYNAMIC\rlddf.lib" \
	"..\..\..\..\..\usr\rm\RL20\WIN32\LIB\I386\DYNAMIC\rlddfglu.lib" \
	"..\..\..\..\..\usr\rm\RL20\WIN32\LIB\I386\STATIC\rlff.lib" \
	"..\..\..\..\lib\PbUtil32.lib" \
	"..\..\..\..\lib\Pueblo32.lib"

"$(OUTDIR)\ChGraphx.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

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

ALL : "$(OUTDIR)\ChGraphx.dll"

CLEAN : 
	-@erase "$(INTDIR)\Ch3Dtrvs.obj"
	-@erase "$(INTDIR)\Ch3Rendr.obj"
	-@erase "$(INTDIR)\ChAniDep.obj"
	-@erase "$(INTDIR)\ChAnim.obj"
	-@erase "$(INTDIR)\ChAnimCh.obj"
	-@erase "$(INTDIR)\ChAniMod.obj"
	-@erase "$(INTDIR)\ChAnimy.obj"
	-@erase "$(INTDIR)\ChAniPrs.obj"
	-@erase "$(INTDIR)\ChAscTxt.obj"
	-@erase "$(INTDIR)\ChCollision.obj"
	-@erase "$(INTDIR)\ChColor.obj"
	-@erase "$(INTDIR)\ChConstruct.obj"
	-@erase "$(INTDIR)\ChGraphx.obj"
	-@erase "$(INTDIR)\ChGraphx.res"
	-@erase "$(INTDIR)\ChGraphx40.pch"
	-@erase "$(INTDIR)\ChGrDep.obj"
	-@erase "$(INTDIR)\ChGrFont.obj"
	-@erase "$(INTDIR)\ChGrMod.obj"
	-@erase "$(INTDIR)\ChGrStrm.obj"
	-@erase "$(INTDIR)\ChGrVw.obj"
	-@erase "$(INTDIR)\ChMaterialRenderData.obj"
	-@erase "$(INTDIR)\ChMazCam.obj"
	-@erase "$(INTDIR)\ChMazDep.obj"
	-@erase "$(INTDIR)\ChMaze.obj"
	-@erase "$(INTDIR)\ChMazePr.obj"
	-@erase "$(INTDIR)\ChMazMod.obj"
	-@erase "$(INTDIR)\ChNrCreate.obj"
	-@erase "$(INTDIR)\ChPanMod.obj"
	-@erase "$(INTDIR)\ChPhSprt.obj"
	-@erase "$(INTDIR)\ChQvPars.obj"
	-@erase "$(INTDIR)\ChQvStat.obj"
	-@erase "$(INTDIR)\ChRCDevice.obj"
	-@erase "$(INTDIR)\ChRenderBuffer.obj"
	-@erase "$(INTDIR)\ChRenderData.obj"
	-@erase "$(INTDIR)\ChRlabPr.obj"
	-@erase "$(INTDIR)\ChRLImg.obj"
	-@erase "$(INTDIR)\ChScriptData.obj"
	-@erase "$(INTDIR)\ChSphere.obj"
	-@erase "$(INTDIR)\ChSpline.obj"
	-@erase "$(INTDIR)\ChSpLstN.obj"
	-@erase "$(INTDIR)\ChSprite.obj"
	-@erase "$(INTDIR)\ChSprLst.obj"
	-@erase "$(INTDIR)\ChStubBrowser.obj"
	-@erase "$(INTDIR)\ChThreadMgr.obj"
	-@erase "$(INTDIR)\ChTransition.obj"
	-@erase "$(INTDIR)\ChTrConstr.obj"
	-@erase "$(INTDIR)\ChTriangle.obj"
	-@erase "$(INTDIR)\ChTrMisc.obj"
	-@erase "$(INTDIR)\ChTrMonot.obj"
	-@erase "$(INTDIR)\ChVrmlEvent.obj"
	-@erase "$(INTDIR)\ChVrmlMenu.obj"
	-@erase "$(INTDIR)\ChVrmlSettings.obj"
	-@erase "$(INTDIR)\ChVrmlTransition.obj"
	-@erase "$(INTDIR)\chvrmlwnd.obj"
	-@erase "$(INTDIR)\CvBound.obj"
	-@erase "$(INTDIR)\CvBoundsExtent.obj"
	-@erase "$(INTDIR)\CvCamera.obj"
	-@erase "$(INTDIR)\CvConvrt.obj"
	-@erase "$(INTDIR)\CvGroup.obj"
	-@erase "$(INTDIR)\CvHitTst.obj"
	-@erase "$(INTDIR)\CvInstnc.obj"
	-@erase "$(INTDIR)\CvLights.obj"
	-@erase "$(INTDIR)\CvMaterl.obj"
	-@erase "$(INTDIR)\CvNormal.obj"
	-@erase "$(INTDIR)\CvQuery.obj"
	-@erase "$(INTDIR)\CvSelectors.obj"
	-@erase "$(INTDIR)\CvShapes.obj"
	-@erase "$(INTDIR)\CvTextur.obj"
	-@erase "$(INTDIR)\CvTrnsfm.obj"
	-@erase "$(INTDIR)\CvType.obj"
	-@erase "$(INTDIR)\CvWrite.obj"
	-@erase "$(INTDIR)\Dll.obj"
	-@erase "$(INTDIR)\GxQuaternion.obj"
	-@erase "$(INTDIR)\GxSphere.obj"
	-@erase "$(INTDIR)\GxTrnsfm.obj"
	-@erase "$(INTDIR)\GxUtils.obj"
	-@erase "$(INTDIR)\headers.obj"
	-@erase "$(INTDIR)\inverse.obj"
	-@erase "$(INTDIR)\QvLib.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\xlines.obj"
	-@erase "$(OUTDIR)\ChGraphx.dll"
	-@erase "$(OUTDIR)\ChGraphx.exp"
	-@erase "$(OUTDIR)\ChGraphx.ilk"
	-@erase "$(OUTDIR)\ChGraphx.lib"
	-@erase "$(OUTDIR)\ChGraphx.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_USE_RLAB" /D "CH_VRML_EVENTS" /Fr /Yu"grheader.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"grheader.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fp"$(INTDIR)/ChGraphx40.pch" /Yu"grheader.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\D3D_Debu/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x0 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x0 /fo"$(INTDIR)/ChGraphx.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/ChGraphx40.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 winmm.lib LZ32.lib /nologo /base:0x14000000 /subsystem:windows /dll /debug /machine:I386 /PDB:"/chaco/bin/debug/ChGraphx.pdb"
# SUBTRACT BASE LINK32 /pdb:none /incremental:no /map
# ADD LINK32 winmm.lib LZ32.lib d3drm.lib ddraw.lib /nologo /base:0x14000000 /subsystem:windows /dll /debug /machine:I386 /out:"D3D_Debu/ChGraphx.dll" /PDB:"/chaco/bin/debug/ChGraphx.pdb"
# SUBTRACT LINK32 /pdb:none /incremental:no /map
LINK32_FLAGS=winmm.lib LZ32.lib d3drm.lib ddraw.lib /nologo /base:0x14000000\
 /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)/ChGraphx.pdb" /debug\
 /machine:I386 /out:"$(OUTDIR)/ChGraphx.dll" /implib:"$(OUTDIR)/ChGraphx.lib"\
 /PDB:"/chaco/bin/debug/ChGraphx.pdb" 
LINK32_OBJS= \
	"$(INTDIR)\Ch3Dtrvs.obj" \
	"$(INTDIR)\Ch3Rendr.obj" \
	"$(INTDIR)\ChAniDep.obj" \
	"$(INTDIR)\ChAnim.obj" \
	"$(INTDIR)\ChAnimCh.obj" \
	"$(INTDIR)\ChAniMod.obj" \
	"$(INTDIR)\ChAnimy.obj" \
	"$(INTDIR)\ChAniPrs.obj" \
	"$(INTDIR)\ChAscTxt.obj" \
	"$(INTDIR)\ChCollision.obj" \
	"$(INTDIR)\ChColor.obj" \
	"$(INTDIR)\ChConstruct.obj" \
	"$(INTDIR)\ChGraphx.obj" \
	"$(INTDIR)\ChGraphx.res" \
	"$(INTDIR)\ChGrDep.obj" \
	"$(INTDIR)\ChGrFont.obj" \
	"$(INTDIR)\ChGrMod.obj" \
	"$(INTDIR)\ChGrStrm.obj" \
	"$(INTDIR)\ChGrVw.obj" \
	"$(INTDIR)\ChMaterialRenderData.obj" \
	"$(INTDIR)\ChMazCam.obj" \
	"$(INTDIR)\ChMazDep.obj" \
	"$(INTDIR)\ChMaze.obj" \
	"$(INTDIR)\ChMazePr.obj" \
	"$(INTDIR)\ChMazMod.obj" \
	"$(INTDIR)\ChNrCreate.obj" \
	"$(INTDIR)\ChPanMod.obj" \
	"$(INTDIR)\ChPhSprt.obj" \
	"$(INTDIR)\ChQvPars.obj" \
	"$(INTDIR)\ChQvStat.obj" \
	"$(INTDIR)\ChRCDevice.obj" \
	"$(INTDIR)\ChRenderBuffer.obj" \
	"$(INTDIR)\ChRenderData.obj" \
	"$(INTDIR)\ChRlabPr.obj" \
	"$(INTDIR)\ChRLImg.obj" \
	"$(INTDIR)\ChScriptData.obj" \
	"$(INTDIR)\ChSphere.obj" \
	"$(INTDIR)\ChSpline.obj" \
	"$(INTDIR)\ChSpLstN.obj" \
	"$(INTDIR)\ChSprite.obj" \
	"$(INTDIR)\ChSprLst.obj" \
	"$(INTDIR)\ChStubBrowser.obj" \
	"$(INTDIR)\ChThreadMgr.obj" \
	"$(INTDIR)\ChTransition.obj" \
	"$(INTDIR)\ChTrConstr.obj" \
	"$(INTDIR)\ChTriangle.obj" \
	"$(INTDIR)\ChTrMisc.obj" \
	"$(INTDIR)\ChTrMonot.obj" \
	"$(INTDIR)\ChVrmlEvent.obj" \
	"$(INTDIR)\ChVrmlMenu.obj" \
	"$(INTDIR)\ChVrmlSettings.obj" \
	"$(INTDIR)\ChVrmlTransition.obj" \
	"$(INTDIR)\chvrmlwnd.obj" \
	"$(INTDIR)\CvBound.obj" \
	"$(INTDIR)\CvBoundsExtent.obj" \
	"$(INTDIR)\CvCamera.obj" \
	"$(INTDIR)\CvConvrt.obj" \
	"$(INTDIR)\CvGroup.obj" \
	"$(INTDIR)\CvHitTst.obj" \
	"$(INTDIR)\CvInstnc.obj" \
	"$(INTDIR)\CvLights.obj" \
	"$(INTDIR)\CvMaterl.obj" \
	"$(INTDIR)\CvNormal.obj" \
	"$(INTDIR)\CvQuery.obj" \
	"$(INTDIR)\CvSelectors.obj" \
	"$(INTDIR)\CvShapes.obj" \
	"$(INTDIR)\CvTextur.obj" \
	"$(INTDIR)\CvTrnsfm.obj" \
	"$(INTDIR)\CvType.obj" \
	"$(INTDIR)\CvWrite.obj" \
	"$(INTDIR)\Dll.obj" \
	"$(INTDIR)\GxQuaternion.obj" \
	"$(INTDIR)\GxSphere.obj" \
	"$(INTDIR)\GxTrnsfm.obj" \
	"$(INTDIR)\GxUtils.obj" \
	"$(INTDIR)\headers.obj" \
	"$(INTDIR)\inverse.obj" \
	"$(INTDIR)\QvLib.obj" \
	"$(INTDIR)\xlines.obj" \
	"..\..\..\..\lib\PbUtil32.lib" \
	"..\..\..\..\lib\Pueblo32.lib"

"$(OUTDIR)\ChGraphx.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

MTL_PROJ=
################################################################################
# Begin Target

# Name "ChGraphx - Win32 Reality Debug"
# Name "ChGraphx - Win32 Reality Release"
# Name "ChGraphx - Win32 D3D Debug"

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\headers.cpp
DEP_CPP_HEADE=\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\grheader.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# PROP BASE Exclude_From_Build 0
# PROP Exclude_From_Build 0
# ADD BASE CPP /W3 /Yc"grheader.h"
# SUBTRACT BASE CPP /Gf /Gy
# ADD CPP /W3 /Yc"grheader.h"
# SUBTRACT CPP /Gf /Gy

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/ChGraphx40.pch" /Yc"grheader.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\headers.obj" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\ChGraphx40.pch" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# PROP BASE Exclude_From_Build 0
# PROP Exclude_From_Build 0
# ADD BASE CPP /W3 /Yc"grheader.h"
# SUBTRACT BASE CPP /Gf /Gy
# ADD CPP /W3 /Yc"grheader.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fp"$(INTDIR)/ChGraphx40.pch" /Yc"grheader.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\headers.obj" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\ChGraphx40.pch" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# PROP BASE Exclude_From_Build 0
# PROP Exclude_From_Build 0
# ADD BASE CPP /W3 /Yc"grheader.h"
# SUBTRACT BASE CPP /Gf /Gy
# ADD CPP /W3 /Yc"grheader.h"
# SUBTRACT CPP /Gf /Gy

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fp"$(INTDIR)/ChGraphx40.pch" /Yc"grheader.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\headers.obj" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\ChGraphx40.pch" : $(SOURCE) $(DEP_CPP_HEADE) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dll.cpp
DEP_CPP_DLL_C=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrType.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\Dll.obj" : $(SOURCE) $(DEP_CPP_DLL_C) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\Dll.obj" : $(SOURCE) $(DEP_CPP_DLL_C) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\Dll.obj" : $(SOURCE) $(DEP_CPP_DLL_C) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGraphx.cpp
DEP_CPP_CHGRA=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrType.h"\
	".\ChPanMod.h"\
	".\templcls\ChGrPLst.h"\
	".\templcls\ChHtpVw.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChGraphx.obj" : $(SOURCE) $(DEP_CPP_CHGRA) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChGraphx.obj" : $(SOURCE) $(DEP_CPP_CHGRA) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChGraphx.obj" : $(SOURCE) $(DEP_CPP_CHGRA) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGraphx.rc
DEP_RSC_CHGRAP=\
	".\res\ChGraphx.rc2"\
	".\res\handmono.cur"\
	".\res\pointer.cur"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChGraphx.res" : $(SOURCE) $(DEP_RSC_CHGRAP) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChGraphx.res" : $(SOURCE) $(DEP_RSC_CHGRAP) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChGraphx.res" : $(SOURCE) $(DEP_RSC_CHGRAP) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGrMod.cpp
DEP_CPP_CHGRM=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	".\ChAniDep.h"\
	".\ChAnim.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrStrm.h"\
	".\ChGrType.h"\
	".\ChPhSprt.h"\
	".\ChSpLstN.h"\
	".\ChSprite.h"\
	".\ChSpritN.h"\
	".\ChSprLst.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibBmp.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChGrMod.obj" : $(SOURCE) $(DEP_CPP_CHGRM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChGrMod.obj" : $(SOURCE) $(DEP_CPP_CHGRM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChGrMod.obj" : $(SOURCE) $(DEP_CPP_CHGRM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGrDep.cpp
DEP_CPP_CHGRD=\
	".\ChGrDep.h"\
	".\ChGrType.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChGrDep.obj" : $(SOURCE) $(DEP_CPP_CHGRD) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChGrDep.obj" : $(SOURCE) $(DEP_CPP_CHGRD) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChGrDep.obj" : $(SOURCE) $(DEP_CPP_CHGRD) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGrVw.cpp
DEP_CPP_CHGRV=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrType.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibBmp.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChGrVw.obj" : $(SOURCE) $(DEP_CPP_CHGRV) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChGrVw.obj" : $(SOURCE) $(DEP_CPP_CHGRV) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChGrVw.obj" : $(SOURCE) $(DEP_CPP_CHGRV) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\usr\3DR\SDK\3DG32.LIB

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\usr\3DR\SDK\3DR32.LIB

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPanMod.cpp
DEP_CPP_CHPAN=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrStrm.h"\
	".\ChGrType.h"\
	".\ChPanMod.h"\
	".\templcls\ChGrPLst.h"\
	".\templcls\ChHtpVw.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChPanMod.obj" : $(SOURCE) $(DEP_CPP_CHPAN) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChPanMod.obj" : $(SOURCE) $(DEP_CPP_CHPAN) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChPanMod.obj" : $(SOURCE) $(DEP_CPP_CHPAN) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\lib\Pueblo32.lib

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\lib\PbUtil32.lib

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\usr\rm\RL20\WIN32\LIB\I386\DYNAMIC\rlddfglu.lib

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\usr\rm\RL20\WIN32\LIB\I386\DYNAMIC\rlddf.lib

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\usr\rm\RL20\WIN32\LIB\I386\STATIC\rlff.lib

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\modules\client\portable\vrml\QvLib.cpp
DEP_CPP_QVLIB=\
	"..\..\portable\ChGraphx\GxQuaternion.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvChildList.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDebugError.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFields.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvLists.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFNode.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFTime.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvReadError.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFNode.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvUnknownNode.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\vrml\QvAsciiText.cpp"\
	"..\..\portable\vrml\QvBackground.cpp"\
	"..\..\portable\vrml\QvBaseColor.cpp"\
	"..\..\portable\vrml\QvChildList.cpp"\
	"..\..\portable\vrml\QvCone.cpp"\
	"..\..\portable\vrml\QvCoordinate3.cpp"\
	"..\..\portable\vrml\QvCube.cpp"\
	"..\..\portable\vrml\QvCylinder.cpp"\
	"..\..\portable\vrml\QvDB.cpp"\
	"..\..\portable\vrml\QvDebugError.cpp"\
	"..\..\portable\vrml\QvDict.cpp"\
	"..\..\portable\vrml\QvDirectionalLight.cpp"\
	"..\..\portable\vrml\QvElement.cpp"\
	"..\..\portable\vrml\QvField.cpp"\
	"..\..\portable\vrml\QvField20.cpp"\
	"..\..\portable\vrml\QvFieldData.cpp"\
	"..\..\portable\vrml\QvFontStyle.cpp"\
	"..\..\portable\vrml\QvGroup.cpp"\
	"..\..\portable\vrml\QvIndexedFaceSet.cpp"\
	"..\..\portable\vrml\QvIndexedLineSet.cpp"\
	"..\..\portable\vrml\QvInfo.cpp"\
	"..\..\portable\vrml\QvInput.cpp"\
	"..\..\portable\vrml\QvInterpolator.cpp"\
	"..\..\portable\vrml\QvLevelOfDetail.cpp"\
	"..\..\portable\vrml\QvLists.cpp"\
	"..\..\portable\vrml\QvMaterial.cpp"\
	"..\..\portable\vrml\QvMaterialBinding.cpp"\
	"..\..\portable\vrml\QvMatrixTransform.cpp"\
	"..\..\portable\vrml\QvMFColor.cpp"\
	"..\..\portable\vrml\QvMFFloat.cpp"\
	"..\..\portable\vrml\QvMFLong.cpp"\
	"..\..\portable\vrml\QvMFRotation.cpp"\
	"..\..\portable\vrml\QvMFString.cpp"\
	"..\..\portable\vrml\QvMFTime.cpp"\
	"..\..\portable\vrml\QvMFVec2f.cpp"\
	"..\..\portable\vrml\QvMFVec3f.cpp"\
	"..\..\portable\vrml\QvName.cpp"\
	"..\..\portable\vrml\QvNavigationInfo.cpp"\
	"..\..\portable\vrml\QvNode.cpp"\
	"..\..\portable\vrml\QvNormal.cpp"\
	"..\..\portable\vrml\QvNormalBinding.cpp"\
	"..\..\portable\vrml\QvOrientationInterpolator.cpp"\
	"..\..\portable\vrml\QvOrthographicCamera.cpp"\
	"..\..\portable\vrml\QvPerspectiveCamera.cpp"\
	"..\..\portable\vrml\QvPList.cpp"\
	"..\..\portable\vrml\QvPointLight.cpp"\
	"..\..\portable\vrml\QvPointSet.cpp"\
	"..\..\portable\vrml\QvPositionInterpolator.cpp"\
	"..\..\portable\vrml\QvReadError.cpp"\
	"..\..\portable\vrml\QvRotation.cpp"\
	"..\..\portable\vrml\QvRoute.cpp"\
	"..\..\portable\vrml\QvScale.cpp"\
	"..\..\portable\vrml\QvSensor.cpp"\
	"..\..\portable\vrml\QvSeparator.cpp"\
	"..\..\portable\vrml\QvSetField.cpp"\
	"..\..\portable\vrml\QvSFBitMask.cpp"\
	"..\..\portable\vrml\QvSFBool.cpp"\
	"..\..\portable\vrml\QvSFColor.cpp"\
	"..\..\portable\vrml\QvSFEnum.cpp"\
	"..\..\portable\vrml\QvSFFloat.cpp"\
	"..\..\portable\vrml\QvSFImage.cpp"\
	"..\..\portable\vrml\QvSFLong.cpp"\
	"..\..\portable\vrml\QvSFMatrix.cpp"\
	"..\..\portable\vrml\QvSFRotation.cpp"\
	"..\..\portable\vrml\QvSFString.cpp"\
	"..\..\portable\vrml\QvSFTime.cpp"\
	"..\..\portable\vrml\QvSFVec2f.cpp"\
	"..\..\portable\vrml\QvSFVec3f.cpp"\
	"..\..\portable\vrml\QvShapeHints.cpp"\
	"..\..\portable\vrml\QvSphere.cpp"\
	"..\..\portable\vrml\QvSpin.cpp"\
	"..\..\portable\vrml\QvSpinGroup.cpp"\
	"..\..\portable\vrml\QvSpotLight.cpp"\
	"..\..\portable\vrml\QvState.cpp"\
	"..\..\portable\vrml\QvString.cpp"\
	"..\..\portable\vrml\QvSwitch.cpp"\
	"..\..\portable\vrml\QvTexture2.cpp"\
	"..\..\portable\vrml\QvTexture2Transform.cpp"\
	"..\..\portable\vrml\QvTextureCoordinate2.cpp"\
	"..\..\portable\vrml\QvTimeSensor.cpp"\
	"..\..\portable\vrml\QvTransform.cpp"\
	"..\..\portable\vrml\QvTransformSeparator.cpp"\
	"..\..\portable\vrml\QvTranslation.cpp"\
	"..\..\portable\vrml\QvUnknownNode.cpp"\
	"..\..\portable\vrml\QvWWWAnchor.cpp"\
	"..\..\portable\vrml\QvWWWInline.cpp"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# SUBTRACT CPP /Yu

"$(INTDIR)\QvLib.obj" : $(SOURCE) $(DEP_CPP_QVLIB) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\QvLib.obj" : $(SOURCE) $(DEP_CPP_QVLIB) "$(INTDIR)"
   $(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\QvLib.obj" : $(SOURCE) $(DEP_CPP_QVLIB) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAniPrs.cpp
DEP_CPP_CHANI=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	".\ChAniDep.h"\
	".\ChAnim.h"\
	".\ChAnimy.h"\
	".\ChAniPrs.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrStrm.h"\
	".\ChGrType.h"\
	".\ChPhSprt.h"\
	".\ChSpLstN.h"\
	".\ChSprite.h"\
	".\ChSpritN.h"\
	".\ChSprLst.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibBmp.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChURLMap.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChAniPrs.obj" : $(SOURCE) $(DEP_CPP_CHANI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChAniPrs.obj" : $(SOURCE) $(DEP_CPP_CHANI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChAniPrs.obj" : $(SOURCE) $(DEP_CPP_CHANI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAnimy.cpp
DEP_CPP_CHANIM=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	".\ChAnim.h"\
	".\ChAnimy.h"\
	".\ChAniPrs.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrType.h"\
	".\ChPhSprt.h"\
	".\ChSpLstN.h"\
	".\ChSprite.h"\
	".\ChSpritN.h"\
	".\ChSprLst.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibBmp.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\values.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChAnimy.obj" : $(SOURCE) $(DEP_CPP_CHANIM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChAnimy.obj" : $(SOURCE) $(DEP_CPP_CHANIM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChAnimy.obj" : $(SOURCE) $(DEP_CPP_CHANIM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAniMod.cpp
DEP_CPP_CHANIMO=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	".\ChAniDep.h"\
	".\ChAnim.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrStrm.h"\
	".\ChGrType.h"\
	".\ChPhSprt.h"\
	".\ChSpLstN.h"\
	".\ChSprite.h"\
	".\ChSpritN.h"\
	".\ChSprLst.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibBmp.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChAniMod.obj" : $(SOURCE) $(DEP_CPP_CHANIMO) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChAniMod.obj" : $(SOURCE) $(DEP_CPP_CHANIMO) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChAniMod.obj" : $(SOURCE) $(DEP_CPP_CHANIMO) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAnimCh.cpp
DEP_CPP_CHANIMC=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	".\ChAnim.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrType.h"\
	".\ChPhSprt.h"\
	".\ChSpLstN.h"\
	".\ChSprite.h"\
	".\ChSpritN.h"\
	".\ChSprLst.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibBmp.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChAnimCh.obj" : $(SOURCE) $(DEP_CPP_CHANIMC) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChAnimCh.obj" : $(SOURCE) $(DEP_CPP_CHANIMC) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChAnimCh.obj" : $(SOURCE) $(DEP_CPP_CHANIMC) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAnim.cpp
DEP_CPP_CHANIM_=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	".\ChAnim.h"\
	".\ChAnimy.h"\
	".\ChAniPrs.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrType.h"\
	".\ChPhSprt.h"\
	".\ChSpLstN.h"\
	".\ChSprite.h"\
	".\ChSpritN.h"\
	".\ChSprLst.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibBmp.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChGIFDecoder.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImageDecoder.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChImgUtil.h"\
	"\chaco\include\ChJPEGDecoder.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\jconfig.h"\
	"\chaco\include\jmorecfg.h"\
	"\chaco\include\jpeglib.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	
NODEP_CPP_CHANIM_=\
	"..\..\..\..\include\jerror.h"\
	"..\..\..\..\include\jpegint.h"\
	".\vwrres.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChAnim.obj" : $(SOURCE) $(DEP_CPP_CHANIM_) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChAnim.obj" : $(SOURCE) $(DEP_CPP_CHANIM_) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChAnim.obj" : $(SOURCE) $(DEP_CPP_CHANIM_) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAniDep.cpp
DEP_CPP_CHANID=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	".\ChAniDep.h"\
	".\ChAnim.h"\
	".\ChAnimy.h"\
	".\ChAniPrs.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrStrm.h"\
	".\ChGrType.h"\
	".\ChPhSprt.h"\
	".\ChSpLstN.h"\
	".\ChSprite.h"\
	".\ChSpritN.h"\
	".\ChSprLst.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibBmp.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChURLMap.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChAniDep.obj" : $(SOURCE) $(DEP_CPP_CHANID) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChAniDep.obj" : $(SOURCE) $(DEP_CPP_CHANID) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChAniDep.obj" : $(SOURCE) $(DEP_CPP_CHANID) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChPhSprt.cpp
DEP_CPP_CHPHS=\
	".\ChPhSprt.h"\
	".\ChSprite.h"\
	".\ChSpritN.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibBmp.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChPhSprt.obj" : $(SOURCE) $(DEP_CPP_CHPHS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChPhSprt.obj" : $(SOURCE) $(DEP_CPP_CHPHS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChPhSprt.obj" : $(SOURCE) $(DEP_CPP_CHPHS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSprLst.cpp
DEP_CPP_CHSPR=\
	".\ChSpLstN.h"\
	".\ChSprite.h"\
	".\ChSpritN.h"\
	".\ChSprLst.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibBmp.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChSprLst.obj" : $(SOURCE) $(DEP_CPP_CHSPR) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChSprLst.obj" : $(SOURCE) $(DEP_CPP_CHSPR) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChSprLst.obj" : $(SOURCE) $(DEP_CPP_CHSPR) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSprite.cpp
DEP_CPP_CHSPRI=\
	".\ChSprite.h"\
	".\ChSpritN.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibBmp.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChSprite.obj" : $(SOURCE) $(DEP_CPP_CHSPRI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChSprite.obj" : $(SOURCE) $(DEP_CPP_CHSPRI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChSprite.obj" : $(SOURCE) $(DEP_CPP_CHSPRI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSpLstN.cpp
DEP_CPP_CHSPL=\
	".\ChAnim.h"\
	".\ChPhSprt.h"\
	".\ChSpLstN.h"\
	".\ChSprite.h"\
	".\ChSpritN.h"\
	".\ChSprLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDC.h"\
	"\chaco\include\ChDibBmp.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChFont.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrlVw.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSize.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChSpLstN.obj" : $(SOURCE) $(DEP_CPP_CHSPL) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChSpLstN.obj" : $(SOURCE) $(DEP_CPP_CHSPL) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChSpLstN.obj" : $(SOURCE) $(DEP_CPP_CHSPL) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Ch3Dtrvs.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CH3DT=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvChildList.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvLists.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvUnknownNode.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChScriptData.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvMaterl.h"\
	".\CvQuery.h"\
	".\CvTextur.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CH3DT=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\Ch3Dtrvs.obj" : $(SOURCE) $(DEP_CPP_CH3DT) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CH3DT=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvChildList.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvLists.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvUnknownNode.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChScriptData.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvMaterl.h"\
	".\CvQuery.h"\
	".\CvTextur.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CH3DT=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\Ch3Dtrvs.obj" : $(SOURCE) $(DEP_CPP_CH3DT) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CH3DT=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvChildList.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvLists.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvUnknownNode.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChScriptData.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvMaterl.h"\
	".\CvQuery.h"\
	".\CvTextur.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CH3DT=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\Ch3Dtrvs.obj" : $(SOURCE) $(DEP_CPP_CH3DT) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Ch3Rendr.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CH3RE=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChCollision.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChRLImg.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvMaterl.h"\
	".\CvTextur.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSFImage.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TIMEB.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CH3RE=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\Ch3Rendr.obj" : $(SOURCE) $(DEP_CPP_CH3RE) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CH3RE=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChCollision.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChRLImg.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvMaterl.h"\
	".\CvTextur.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSFImage.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\sys\TIMEB.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CH3RE=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\Ch3Rendr.obj" : $(SOURCE) $(DEP_CPP_CH3RE) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CH3RE=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChCollision.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChRLImg.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvMaterl.h"\
	".\CvTextur.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSFImage.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TIMEB.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CH3RE=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\Ch3Rendr.obj" : $(SOURCE) $(DEP_CPP_CH3RE) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMazDep.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CHMAZ=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvChildList.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvLists.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChRLImg.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvQuery.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHMAZ=\
	".\glos.h"\
	

"$(INTDIR)\ChMazDep.obj" : $(SOURCE) $(DEP_CPP_CHMAZ) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CHMAZ=\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvChildList.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvLists.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChRLImg.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvQuery.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\ChMazDep.obj" : $(SOURCE) $(DEP_CPP_CHMAZ) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CHMAZ=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvChildList.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvLists.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChRLImg.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvQuery.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHMAZ=\
	".\glos.h"\
	

"$(INTDIR)\ChMazDep.obj" : $(SOURCE) $(DEP_CPP_CHMAZ) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMaze.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CHMAZE=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvChildList.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvLists.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvReadError.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrStrm.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChQvPars.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChStubBrowser.h"\
	".\ChTransition.h"\
	".\ChVrmlEvent.h"\
	".\ChVrmlTransition.h"\
	".\CvBound.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvQuery.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChURLMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHMAZE=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	".\vwrres.h"\
	

"$(INTDIR)\ChMaze.obj" : $(SOURCE) $(DEP_CPP_CHMAZE) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CHMAZE=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvChildList.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvLists.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvReadError.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrStrm.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChQvPars.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChStubBrowser.h"\
	".\ChTransition.h"\
	".\ChVrmlEvent.h"\
	".\ChVrmlTransition.h"\
	".\CvBound.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvQuery.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChURLMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHMAZE=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\vwrres.h"\
	

"$(INTDIR)\ChMaze.obj" : $(SOURCE) $(DEP_CPP_CHMAZE) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CHMAZE=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvChildList.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvLists.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvReadError.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrStrm.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChQvPars.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChStubBrowser.h"\
	".\ChTransition.h"\
	".\ChVrmlEvent.h"\
	".\ChVrmlTransition.h"\
	".\CvBound.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvQuery.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChURLMap.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHMAZE=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	".\vwrres.h"\
	

"$(INTDIR)\ChMaze.obj" : $(SOURCE) $(DEP_CPP_CHMAZE) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMazMod.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CHMAZM=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChMazePr.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChRlabPr.h"\
	".\ChRLImg.h"\
	".\ChStubBrowser.h"\
	".\ChVrmlEvent.h"\
	".\chvrmlwnd.h"\
	".\CvQuery.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHMAZM=\
	".\glos.h"\
	".\vwrres.h"\
	

"$(INTDIR)\ChMazMod.obj" : $(SOURCE) $(DEP_CPP_CHMAZM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CHMAZM=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChMazePr.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChRlabPr.h"\
	".\ChRLImg.h"\
	".\ChStubBrowser.h"\
	".\ChVrmlEvent.h"\
	".\chvrmlwnd.h"\
	".\CvQuery.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHMAZM=\
	".\vwrres.h"\
	

"$(INTDIR)\ChMazMod.obj" : $(SOURCE) $(DEP_CPP_CHMAZM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CHMAZM=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChMazePr.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChRlabPr.h"\
	".\ChRLImg.h"\
	".\ChStubBrowser.h"\
	".\ChVrmlEvent.h"\
	".\chvrmlwnd.h"\
	".\CvQuery.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHtmWnd.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHMAZM=\
	".\glos.h"\
	".\vwrres.h"\
	

"$(INTDIR)\ChMazMod.obj" : $(SOURCE) $(DEP_CPP_CHMAZM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChQvStat.cpp
DEP_CPP_CHQVS=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHQVS=\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChQvStat.obj" : $(SOURCE) $(DEP_CPP_CHQVS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChQvStat.obj" : $(SOURCE) $(DEP_CPP_CHQVS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChQvStat.obj" : $(SOURCE) $(DEP_CPP_CHQVS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvBound.cpp
DEP_CPP_CVBOU=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvUnknownNode.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\CvBound.h"\
	".\CvInstnc.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVBOU=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\CvBound.obj" : $(SOURCE) $(DEP_CPP_CVBOU) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\CvBound.obj" : $(SOURCE) $(DEP_CPP_CVBOU) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\CvBound.obj" : $(SOURCE) $(DEP_CPP_CVBOU) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvQuery.cpp
DEP_CPP_CVQUE=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvUnknownNode.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\CvQuery.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVQUE=\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\CvQuery.obj" : $(SOURCE) $(DEP_CPP_CVQUE) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\CvQuery.obj" : $(SOURCE) $(DEP_CPP_CVQUE) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\CvQuery.obj" : $(SOURCE) $(DEP_CPP_CVQUE) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvWrite.cpp
DEP_CPP_CVWRI=\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvUnknownNode.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\grheader.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\CvWrite.obj" : $(SOURCE) $(DEP_CPP_CVWRI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\CvWrite.obj" : $(SOURCE) $(DEP_CPP_CVWRI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\CvWrite.obj" : $(SOURCE) $(DEP_CPP_CVWRI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMazePr.cpp
DEP_CPP_CHMAZEP=\
	".\ChGrType.h"\
	".\ChMazePr.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	
NODEP_CPP_CHMAZEP=\
	".\vwrres.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChMazePr.obj" : $(SOURCE) $(DEP_CPP_CHMAZEP) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChMazePr.obj" : $(SOURCE) $(DEP_CPP_CHMAZEP) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChMazePr.obj" : $(SOURCE) $(DEP_CPP_CHMAZEP) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMazCam.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CHMAZC=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvQuery.h"\
	".\CvTrnsfm.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHMAZC=\
	".\glos.h"\
	

"$(INTDIR)\ChMazCam.obj" : $(SOURCE) $(DEP_CPP_CHMAZC) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CHMAZC=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvQuery.h"\
	".\CvTrnsfm.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\ChMazCam.obj" : $(SOURCE) $(DEP_CPP_CHMAZC) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CHMAZC=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvQuery.h"\
	".\CvTrnsfm.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHMAZC=\
	".\glos.h"\
	

"$(INTDIR)\ChMazCam.obj" : $(SOURCE) $(DEP_CPP_CHMAZC) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvTrnsfm.cpp
DEP_CPP_CVTRN=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvUnknownNode.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\CvConvrt.h"\
	".\CvTrnsfm.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVTRN=\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\CvTrnsfm.obj" : $(SOURCE) $(DEP_CPP_CVTRN) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\CvTrnsfm.obj" : $(SOURCE) $(DEP_CPP_CVTRN) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\CvTrnsfm.obj" : $(SOURCE) $(DEP_CPP_CVTRN) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvHitTst.cpp
DEP_CPP_CVHIT=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvUnknownNode.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\CvBound.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVHIT=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\CvHitTst.obj" : $(SOURCE) $(DEP_CPP_CVHIT) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\CvHitTst.obj" : $(SOURCE) $(DEP_CPP_CVHIT) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\CvHitTst.obj" : $(SOURCE) $(DEP_CPP_CVHIT) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvType.cpp
DEP_CPP_CVTYP=\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvUnknownNode.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	".\CvType.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\grheader.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\CvType.obj" : $(SOURCE) $(DEP_CPP_CVTYP) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\CvType.obj" : $(SOURCE) $(DEP_CPP_CVTYP) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\CvType.obj" : $(SOURCE) $(DEP_CPP_CVTYP) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvTextur.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CVTEX=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvInstnc.h"\
	".\CvTextur.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVTEX=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvTextur.obj" : $(SOURCE) $(DEP_CPP_CVTEX) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CVTEX=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvInstnc.h"\
	".\CvTextur.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVTEX=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\CvTextur.obj" : $(SOURCE) $(DEP_CPP_CVTEX) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CVTEX=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvInstnc.h"\
	".\CvTextur.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVTEX=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvTextur.obj" : $(SOURCE) $(DEP_CPP_CVTEX) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvMaterl.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CVMAT=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvMaterl.h"\
	".\CvTextur.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVMAT=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvMaterl.obj" : $(SOURCE) $(DEP_CPP_CVMAT) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CVMAT=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvMaterl.h"\
	".\CvTextur.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVMAT=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\CvMaterl.obj" : $(SOURCE) $(DEP_CPP_CVMAT) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CVMAT=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvMaterl.h"\
	".\CvTextur.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVMAT=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvMaterl.obj" : $(SOURCE) $(DEP_CPP_CVMAT) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvLights.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CVLIG=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVLIG=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvLights.obj" : $(SOURCE) $(DEP_CPP_CVLIG) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CVLIG=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVLIG=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\CvLights.obj" : $(SOURCE) $(DEP_CPP_CVLIG) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CVLIG=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVLIG=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvLights.obj" : $(SOURCE) $(DEP_CPP_CVLIG) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvInstnc.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CVINS=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChScriptData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVINS=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvInstnc.obj" : $(SOURCE) $(DEP_CPP_CVINS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CVINS=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChScriptData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVINS=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\CvInstnc.obj" : $(SOURCE) $(DEP_CPP_CVINS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CVINS=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChScriptData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVINS=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvInstnc.obj" : $(SOURCE) $(DEP_CPP_CVINS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvShapes.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CVSHA=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\ChTriangle.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvMaterl.h"\
	".\CvTextur.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVSHA=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvShapes.obj" : $(SOURCE) $(DEP_CPP_CVSHA) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CVSHA=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\ChTriangle.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvMaterl.h"\
	".\CvTextur.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVSHA=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\CvShapes.obj" : $(SOURCE) $(DEP_CPP_CVSHA) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CVSHA=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\ChTriangle.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvMaterl.h"\
	".\CvTextur.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVSHA=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvShapes.obj" : $(SOURCE) $(DEP_CPP_CVSHA) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChAscTxt.cpp
DEP_CPP_CHASC=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrFont.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChPoly.h"\
	".\ChRender.h"\
	".\ChSpline.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvMaterl.h"\
	".\CvTextur.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHASC=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChAscTxt.obj" : $(SOURCE) $(DEP_CPP_CHASC) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChAscTxt.obj" : $(SOURCE) $(DEP_CPP_CHASC) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChAscTxt.obj" : $(SOURCE) $(DEP_CPP_CHASC) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGrFont.cpp
DEP_CPP_CHGRF=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\TrBasic.h"\
	".\ChGrFont.h"\
	".\ChPoly.h"\
	".\ChSpline.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\grheader.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChGrFont.obj" : $(SOURCE) $(DEP_CPP_CHGRF) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChGrFont.obj" : $(SOURCE) $(DEP_CPP_CHGRF) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChGrFont.obj" : $(SOURCE) $(DEP_CPP_CHGRF) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSpline.cpp
DEP_CPP_CHSPLI=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	".\ChSpline.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\grheader.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChSpline.obj" : $(SOURCE) $(DEP_CPP_CHSPLI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChSpline.obj" : $(SOURCE) $(DEP_CPP_CHSPLI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChSpline.obj" : $(SOURCE) $(DEP_CPP_CHSPLI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChColor.cpp
DEP_CPP_CHCOL=\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	
NODEP_CPP_CHCOL=\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChColor.obj" : $(SOURCE) $(DEP_CPP_CHCOL) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChColor.obj" : $(SOURCE) $(DEP_CPP_CHCOL) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChColor.obj" : $(SOURCE) $(DEP_CPP_CHCOL) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvCamera.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CVCAM=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxQuaternion.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChTransition.h"\
	".\ChVrmlEvent.h"\
	".\ChVrmlTransition.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVCAM=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvCamera.obj" : $(SOURCE) $(DEP_CPP_CVCAM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CVCAM=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxQuaternion.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChTransition.h"\
	".\ChVrmlEvent.h"\
	".\ChVrmlTransition.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVCAM=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\CvCamera.obj" : $(SOURCE) $(DEP_CPP_CVCAM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CVCAM=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxQuaternion.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChTransition.h"\
	".\ChVrmlEvent.h"\
	".\ChVrmlTransition.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVCAM=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvCamera.obj" : $(SOURCE) $(DEP_CPP_CVCAM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvConvrt.cpp
DEP_CPP_CVCON=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\CvConvrt.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVCON=\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\CvConvrt.obj" : $(SOURCE) $(DEP_CPP_CVCON) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\CvConvrt.obj" : $(SOURCE) $(DEP_CPP_CVCON) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\CvConvrt.obj" : $(SOURCE) $(DEP_CPP_CVCON) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRLImg.cpp
DEP_CPP_CHRLI=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRLImg.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHRLI=\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChRLImg.obj" : $(SOURCE) $(DEP_CPP_CHRLI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChRLImg.obj" : $(SOURCE) $(DEP_CPP_CHRLI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChRLImg.obj" : $(SOURCE) $(DEP_CPP_CHRLI) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChGrStrm.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CHGRS=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrStrm.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChRLImg.h"\
	".\ChVrmlEvent.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibDecoder.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGIFDecoder.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChImageDecoder.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChJPEGDecoder.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUnzip.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\jconfig.h"\
	"\chaco\include\jmorecfg.h"\
	"\chaco\include\jpeglib.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	"\chaco\include\unzip.h"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	{$(INCLUDE)}"\sys\TIMEB.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHGRS=\
	"..\..\..\..\include\jerror.h"\
	"..\..\..\..\include\jpegint.h"\
	".\glos.h"\
	

"$(INTDIR)\ChGrStrm.obj" : $(SOURCE) $(DEP_CPP_CHGRS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CHGRS=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrStrm.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChRLImg.h"\
	".\ChVrmlEvent.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibDecoder.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGIFDecoder.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChImageDecoder.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChJPEGDecoder.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUnzip.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\jconfig.h"\
	"\chaco\include\jmorecfg.h"\
	"\chaco\include\jpeglib.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	"\chaco\include\unzip.h"\
	{$(INCLUDE)}"\sys\STAT.H"\
	{$(INCLUDE)}"\sys\TIMEB.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHGRS=\
	"..\..\..\..\include\jerror.h"\
	"..\..\..\..\include\jpegint.h"\
	

"$(INTDIR)\ChGrStrm.obj" : $(SOURCE) $(DEP_CPP_CHGRS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CHGRS=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrStrm.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChRLImg.h"\
	".\ChVrmlEvent.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibDecoder.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGIFDecoder.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChHttpStream.h"\
	"\chaco\include\ChImageDecoder.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChJPEGDecoder.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUnzip.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\jconfig.h"\
	"\chaco\include\jmorecfg.h"\
	"\chaco\include\jpeglib.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	"\chaco\include\unzip.h"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	{$(INCLUDE)}"\sys\TIMEB.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHGRS=\
	"..\..\..\..\include\jerror.h"\
	"..\..\..\..\include\jpegint.h"\
	".\glos.h"\
	

"$(INTDIR)\ChGrStrm.obj" : $(SOURCE) $(DEP_CPP_CHGRS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChQvPars.cpp
DEP_CPP_CHQVP=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChQvPars.h"\
	".\ChRender.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHQVP=\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChQvPars.obj" : $(SOURCE) $(DEP_CPP_CHQVP) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChQvPars.obj" : $(SOURCE) $(DEP_CPP_CHQVP) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChQvPars.obj" : $(SOURCE) $(DEP_CPP_CHQVP) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChConstruct.cpp
DEP_CPP_CHCON=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\CvInstnc.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHCON=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChConstruct.obj" : $(SOURCE) $(DEP_CPP_CHCON) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChConstruct.obj" : $(SOURCE) $(DEP_CPP_CHCON) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChConstruct.obj" : $(SOURCE) $(DEP_CPP_CHCON) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChCollision.cpp
DEP_CPP_CHCOLL=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChCollision.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMaze.h"\
	".\ChRCDevice.h"\
	".\ChRender.h"\
	".\CvBound.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvQuery.h"\
	".\CvTrnsfm.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHCOLL=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChCollision.obj" : $(SOURCE) $(DEP_CPP_CHCOLL) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChCollision.obj" : $(SOURCE) $(DEP_CPP_CHCOLL) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChCollision.obj" : $(SOURCE) $(DEP_CPP_CHCOLL) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRenderData.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CHREN=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvChildList.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvLists.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChQvPars.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChRLImg.h"\
	".\ChScriptData.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSFImage.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHREN=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\ChRenderData.obj" : $(SOURCE) $(DEP_CPP_CHREN) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CHREN=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvChildList.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvLists.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChQvPars.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChRLImg.h"\
	".\ChScriptData.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSFImage.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHREN=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\ChRenderData.obj" : $(SOURCE) $(DEP_CPP_CHREN) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CHREN=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvChildList.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvLists.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChQvPars.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChRLImg.h"\
	".\ChScriptData.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\CvType.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSFImage.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHREN=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\ChRenderData.obj" : $(SOURCE) $(DEP_CPP_CHREN) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChVrmlEvent.cpp
DEP_CPP_CHVRM=\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvString.h"\
	".\ChVrmlEvent.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\grheader.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChVrmlEvent.obj" : $(SOURCE) $(DEP_CPP_CHVRM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChVrmlEvent.obj" : $(SOURCE) $(DEP_CPP_CHVRM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChVrmlEvent.obj" : $(SOURCE) $(DEP_CPP_CHVRM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChStubBrowser.cpp
DEP_CPP_CHSTU=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChStubBrowser.h"\
	".\ChVrmlEvent.h"\
	".\CvQuery.h"\
	".\CvType.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHSTU=\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChStubBrowser.obj" : $(SOURCE) $(DEP_CPP_CHSTU) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChStubBrowser.obj" : $(SOURCE) $(DEP_CPP_CHSTU) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChStubBrowser.obj" : $(SOURCE) $(DEP_CPP_CHSTU) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChVrmlTransition.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CHVRML=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChTransition.h"\
	".\ChVrmlEvent.h"\
	".\ChVrmlTransition.h"\
	".\CvQuery.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHVRML=\
	".\glos.h"\
	

"$(INTDIR)\ChVrmlTransition.obj" : $(SOURCE) $(DEP_CPP_CHVRML) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CHVRML=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChTransition.h"\
	".\ChVrmlEvent.h"\
	".\ChVrmlTransition.h"\
	".\CvQuery.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\ChVrmlTransition.obj" : $(SOURCE) $(DEP_CPP_CHVRML) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CHVRML=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChTransition.h"\
	".\ChVrmlEvent.h"\
	".\ChVrmlTransition.h"\
	".\CvQuery.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHVRML=\
	".\glos.h"\
	

"$(INTDIR)\ChVrmlTransition.obj" : $(SOURCE) $(DEP_CPP_CHVRML) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChTransition.cpp
DEP_CPP_CHTRA=\
	".\ChTransition.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\grheader.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChTransition.obj" : $(SOURCE) $(DEP_CPP_CHTRA) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChTransition.obj" : $(SOURCE) $(DEP_CPP_CHTRA) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChTransition.obj" : $(SOURCE) $(DEP_CPP_CHTRA) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChVrmlSettings.cpp
DEP_CPP_CHVRMLS=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\CvQuery.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHVRMLS=\
	".\glos.h"\
	".\vwrres.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChVrmlSettings.obj" : $(SOURCE) $(DEP_CPP_CHVRMLS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChVrmlSettings.obj" : $(SOURCE) $(DEP_CPP_CHVRMLS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChVrmlSettings.obj" : $(SOURCE) $(DEP_CPP_CHVRMLS) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\chvrmlwnd.cpp
DEP_CPP_CHVRMLW=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\chvrmlwnd.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHVRMLW=\
	".\glos.h"\
	".\vwrres.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\chvrmlwnd.obj" : $(SOURCE) $(DEP_CPP_CHVRMLW) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\chvrmlwnd.obj" : $(SOURCE) $(DEP_CPP_CHVRMLW) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\chvrmlwnd.obj" : $(SOURCE) $(DEP_CPP_CHVRMLW) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRlabPr.cpp
DEP_CPP_CHRLA=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChMazePr.h"\
	".\ChRender.h"\
	".\ChRlabPr.h"\
	".\chvrmlwnd.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPage.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHRLA=\
	".\glos.h"\
	".\pueblo.h"\
	".\vwrres.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChRlabPr.obj" : $(SOURCE) $(DEP_CPP_CHRLA) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChRlabPr.obj" : $(SOURCE) $(DEP_CPP_CHRLA) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChRlabPr.obj" : $(SOURCE) $(DEP_CPP_CHRLA) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChThreadMgr.cpp
DEP_CPP_CHTHR=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\CvInstnc.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHTHR=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChThreadMgr.obj" : $(SOURCE) $(DEP_CPP_CHTHR) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChThreadMgr.obj" : $(SOURCE) $(DEP_CPP_CHTHR) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChThreadMgr.obj" : $(SOURCE) $(DEP_CPP_CHTHR) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvSelectors.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CVSEL=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVSEL=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvSelectors.obj" : $(SOURCE) $(DEP_CPP_CVSEL) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CVSEL=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVSEL=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\CvSelectors.obj" : $(SOURCE) $(DEP_CPP_CVSEL) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CVSEL=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVSEL=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvSelectors.obj" : $(SOURCE) $(DEP_CPP_CVSEL) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChVrmlMenu.cpp
DEP_CPP_CHVRMLM=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrMod.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazCam.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChTransition.h"\
	".\ChVrmlTransition.h"\
	".\CvQuery.h"\
	".\templcls\ChGrPLst.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDb.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChDispat.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChReg.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChUtil.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHVRMLM=\
	".\glos.h"\
	".\vwrres.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChVrmlMenu.obj" : $(SOURCE) $(DEP_CPP_CHVRMLM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChVrmlMenu.obj" : $(SOURCE) $(DEP_CPP_CHVRMLM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChVrmlMenu.obj" : $(SOURCE) $(DEP_CPP_CHVRMLM) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChScriptData.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CHSCR=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChScriptData.h"\
	".\ChVrmlEvent.h"\
	".\CvInstnc.h"\
	".\CvType.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHSCR=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\ChScriptData.obj" : $(SOURCE) $(DEP_CPP_CHSCR) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CHSCR=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChScriptData.h"\
	".\ChVrmlEvent.h"\
	".\CvInstnc.h"\
	".\CvType.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHSCR=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\ChScriptData.obj" : $(SOURCE) $(DEP_CPP_CHSCR) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CHSCR=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChScriptData.h"\
	".\ChVrmlEvent.h"\
	".\CvInstnc.h"\
	".\CvType.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHSCR=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\ChScriptData.obj" : $(SOURCE) $(DEP_CPP_CHSCR) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvGroup.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CVGRO=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVGRO=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvGroup.obj" : $(SOURCE) $(DEP_CPP_CVGRO) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CVGRO=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVGRO=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\CvGroup.obj" : $(SOURCE) $(DEP_CPP_CVGRO) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CVGRO=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVGRO=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvGroup.obj" : $(SOURCE) $(DEP_CPP_CVGRO) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CvBoundsExtent.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CVBOUN=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChScriptData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVBOUN=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvBoundsExtent.obj" : $(SOURCE) $(DEP_CPP_CVBOUN) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CVBOUN=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChScriptData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVBOUN=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\CvBoundsExtent.obj" : $(SOURCE) $(DEP_CPP_CVBOUN) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CVBOUN=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrDep.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMazDep.h"\
	".\ChMaze.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChScriptData.h"\
	".\ChVrmlEvent.h"\
	".\CvBound.h"\
	".\CvConvrt.h"\
	".\CvHitTst.h"\
	".\CvInstnc.h"\
	".\CvTrnsfm.h"\
	".\templcls\ChGrPLst.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	"\chaco\include\TemplCls\ChStrLst.h"\
	"\chaco\include\TemplCls\ChStrLst.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CVBOUN=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\CvBoundsExtent.obj" : $(SOURCE) $(DEP_CPP_CVBOUN) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChSphere.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CHSPH=\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHSPH=\
	".\glos.h"\
	

"$(INTDIR)\ChSphere.obj" : $(SOURCE) $(DEP_CPP_CHSPH) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CHSPH=\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\rl.h"\
	".\ChGrRend.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\grheader.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHSPH=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\ChSphere.obj" : $(SOURCE) $(DEP_CPP_CHSPH) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CHSPH=\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChSphere.h"\
	".\ChVrmlEvent.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHSPH=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\ChSphere.obj" : $(SOURCE) $(DEP_CPP_CHSPH) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRenderBuffer.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CHREND=\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvInstnc.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHREND=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\ChRenderBuffer.obj" : $(SOURCE) $(DEP_CPP_CHREND) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CHREND=\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvInstnc.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHREND=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	

"$(INTDIR)\ChRenderBuffer.obj" : $(SOURCE) $(DEP_CPP_CHREND) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CHREND=\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\imode.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChRender.h"\
	".\ChRenderBuffer.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\CvInstnc.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHREND=\
	"..\..\portable\include\libgpu.h"\
	"..\..\portable\include\libgte.h"\
	".\glos.h"\
	

"$(INTDIR)\ChRenderBuffer.obj" : $(SOURCE) $(DEP_CPP_CHREND) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChRCDevice.cpp
DEP_CPP_CHRCD=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvAsciiText.h"\
	"..\..\portable\include\QvBackground.h"\
	"..\..\portable\include\QvBaseColor.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvCube.h"\
	"..\..\portable\include\QvCylinder.h"\
	"..\..\portable\include\QvDB.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvDirectionalLight.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvEnvironment.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvFontStyle.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvIndexedLineSet.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvInterpolator.h"\
	"..\..\portable\include\QvLevelOfDetail.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMaterialBinding.h"\
	"..\..\portable\include\QvMatrixTransform.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFRotation.h"\
	"..\..\portable\include\QvMFString.h"\
	"..\..\portable\include\QvMFVec2f.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNavigationInfo.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNodes.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvOrientationInterpolator.h"\
	"..\..\portable\include\QvOrthographicCamera.h"\
	"..\..\portable\include\QvPerspectiveCamera.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvPointLight.h"\
	"..\..\portable\include\QvPointSet.h"\
	"..\..\portable\include\QvPositionInterpolator.h"\
	"..\..\portable\include\QvRotation.h"\
	"..\..\portable\include\QvRoute.h"\
	"..\..\portable\include\QvScale.h"\
	"..\..\portable\include\QvSensor.h"\
	"..\..\portable\include\QvSeparator.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFBool.h"\
	"..\..\portable\include\QvSFColor.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvSFImage.h"\
	"..\..\portable\include\QvSFLong.h"\
	"..\..\portable\include\QvSFMatrix.h"\
	"..\..\portable\include\QvSFRotation.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFTime.h"\
	"..\..\portable\include\QvSFVec2f.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvSphere.h"\
	"..\..\portable\include\QvSpin.h"\
	"..\..\portable\include\QvSpinGroup.h"\
	"..\..\portable\include\QvSpotLight.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvSwitch.h"\
	"..\..\portable\include\QvTexture2.h"\
	"..\..\portable\include\QvTexture2Transform.h"\
	"..\..\portable\include\QvTextureCoordinate2.h"\
	"..\..\portable\include\QvTimeSensor.h"\
	"..\..\portable\include\QvTransform.h"\
	"..\..\portable\include\QvTransformSeparator.h"\
	"..\..\portable\include\QvTranslation.h"\
	"..\..\portable\include\QvWWWAnchor.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChMaze.h"\
	".\ChRCDevice.h"\
	".\ChRender.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChDibImage.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChGrVw.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChHTTP.h"\
	"\chaco\include\ChImgConsumer.h"\
	"\chaco\include\ChKeyMap.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPane.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChScrWnd.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\ChWnd.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHRCD=\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"


"$(INTDIR)\ChRCDevice.obj" : $(SOURCE) $(DEP_CPP_CHRCD) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChRCDevice.obj" : $(SOURCE) $(DEP_CPP_CHRCD) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"


"$(INTDIR)\ChRCDevice.obj" : $(SOURCE) $(DEP_CPP_CHRCD) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChNrCreate.cpp
DEP_CPP_CHNRC=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChRender.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHNRC=\
	".\glos.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# SUBTRACT CPP /Yu

"$(INTDIR)\ChNrCreate.obj" : $(SOURCE) $(DEP_CPP_CHNRC) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"


"$(INTDIR)\ChNrCreate.obj" : $(SOURCE) $(DEP_CPP_CHNRC) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"
   $(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fp"$(INTDIR)/ChGraphx40.pch" /Yu"grheader.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\ChNrCreate.obj" : $(SOURCE) $(DEP_CPP_CHNRC) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChMaterialRenderData.cpp

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

DEP_CPP_CHMAT=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHMAT=\
	".\glos.h"\
	

"$(INTDIR)\ChMaterialRenderData.obj" : $(SOURCE) $(DEP_CPP_CHMAT) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

DEP_CPP_CHMAT=\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	".\ChGrRend.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\grheader.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

"$(INTDIR)\ChMaterialRenderData.obj" : $(SOURCE) $(DEP_CPP_CHMAT) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

DEP_CPP_CHMAT=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvGroup.h"\
	"..\..\portable\include\QvInfo.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvMaterial.h"\
	"..\..\portable\include\QvMFColor.h"\
	"..\..\portable\include\QvMFFloat.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFString.h"\
	"..\..\portable\include\QvSFVec3f.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"..\..\portable\include\QvWWWInline.h"\
	"..\..\portable\include\rl.h"\
	"..\..\portable\include\rlwin.h"\
	".\ChColor.h"\
	".\ChGrRend.h"\
	".\ChGrType.h"\
	".\ChRender.h"\
	".\ChRenderData.h"\
	".\ChVrmlEvent.h"\
	".\VrmlEvent.h"\
	"\chaco\include\ChAcct.h"\
	"\chaco\include\ChArch.h"\
	"\chaco\include\ChClInfo.h"\
	"\chaco\include\ChConst.h"\
	"\chaco\include\ChCore.h"\
	"\chaco\include\ChData.h"\
	"\chaco\include\ChExcept.h"\
	"\chaco\include\ChGraphx.h"\
	"\chaco\include\ChHook.h"\
	"\chaco\include\ChIVRMLViewer.h"\
	"\chaco\include\ChList.h"\
	"\chaco\include\ChMData.h"\
	"\chaco\include\ChModule.h"\
	"\chaco\include\ChMsg.h"\
	"\chaco\include\ChMsgTyp.h"\
	"\chaco\include\ChPerFrm.h"\
	"\chaco\include\ChRect.h"\
	"\chaco\include\ChSplay.h"\
	"\chaco\include\ChStrmbl.h"\
	"\chaco\include\ChTime.h"\
	"\chaco\include\ChTypes.h"\
	"\chaco\include\ChVers.h"\
	"\chaco\include\grheader.h"\
	"\chaco\include\TemplCls\ChLstHlp.inl"\
	{$(INCLUDE)}"\DDRAW.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CHMAT=\
	".\glos.h"\
	

"$(INTDIR)\ChMaterialRenderData.obj" : $(SOURCE) $(DEP_CPP_CHMAT) "$(INTDIR)"\
 "$(INTDIR)\ChGraphx40.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\modules\client\portable\ChGraphx\GxUtils.cpp
DEP_CPP_GXUTI=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\GxUtils.obj" : $(SOURCE) $(DEP_CPP_GXUTI) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\GxUtils.obj" : $(SOURCE) $(DEP_CPP_GXUTI) "$(INTDIR)"
   $(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\GxUtils.obj" : $(SOURCE) $(DEP_CPP_GXUTI) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\modules\client\portable\ChGraphx\GxSphere.cpp
DEP_CPP_GXSPH=\
	"..\..\portable\ChGraphx\GxSphere.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\GxSphere.obj" : $(SOURCE) $(DEP_CPP_GXSPH) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\GxSphere.obj" : $(SOURCE) $(DEP_CPP_GXSPH) "$(INTDIR)"
   $(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\GxSphere.obj" : $(SOURCE) $(DEP_CPP_GXSPH) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\modules\client\portable\ChGraphx\CvNormal.cpp
DEP_CPP_CVNOR=\
	"..\..\portable\ChGraphx\CvNormal.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\ChGraphx\GxUtils.h"\
	"..\..\portable\include\QvBasic.h"\
	"..\..\portable\include\QvCone.h"\
	"..\..\portable\include\QvCoordinate3.h"\
	"..\..\portable\include\QvDict.h"\
	"..\..\portable\include\QvElement.h"\
	"..\..\portable\include\QvField.h"\
	"..\..\portable\include\QvFieldData.h"\
	"..\..\portable\include\QvIndexedFaceSet.h"\
	"..\..\portable\include\QvInput.h"\
	"..\..\portable\include\QvMFLong.h"\
	"..\..\portable\include\QvMFVec3f.h"\
	"..\..\portable\include\QvNode.h"\
	"..\..\portable\include\QvNormal.h"\
	"..\..\portable\include\QvNormalBinding.h"\
	"..\..\portable\include\QvPList.h"\
	"..\..\portable\include\QvSFBitMask.h"\
	"..\..\portable\include\QvSFEnum.h"\
	"..\..\portable\include\QvSFFloat.h"\
	"..\..\portable\include\QvShapeHints.h"\
	"..\..\portable\include\QvState.h"\
	"..\..\portable\include\QvString.h"\
	"..\..\portable\include\QvSubField.h"\
	"..\..\portable\include\QvSubNode.h"\
	"\chaco\include\ChTypes.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\CvNormal.obj" : $(SOURCE) $(DEP_CPP_CVNOR) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\CvNormal.obj" : $(SOURCE) $(DEP_CPP_CVNOR) "$(INTDIR)"
   $(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\CvNormal.obj" : $(SOURCE) $(DEP_CPP_CVNOR) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\modules\client\portable\ChGraphx\GxTrnsfm.cpp
DEP_CPP_GXTRN=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\3dg.h"\
	"..\..\portable\include\3dr.h"\
	".\CvTrnsfm.h"\
	"\chaco\include\ChTypes.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\GxTrnsfm.obj" : $(SOURCE) $(DEP_CPP_GXTRN) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\GxTrnsfm.obj" : $(SOURCE) $(DEP_CPP_GXTRN) "$(INTDIR)"
   $(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\GxTrnsfm.obj" : $(SOURCE) $(DEP_CPP_GXTRN) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\modules\client\portable\ChGraphx\ChTrMonot.cpp
DEP_CPP_CHTRM=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\ChTriangle.h"\
	"\chaco\include\ChTypes.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# SUBTRACT CPP /Yu

"$(INTDIR)\ChTrMonot.obj" : $(SOURCE) $(DEP_CPP_CHTRM) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\ChTrMonot.obj" : $(SOURCE) $(DEP_CPP_CHTRM) "$(INTDIR)"
   $(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\ChTrMonot.obj" : $(SOURCE) $(DEP_CPP_CHTRM) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\modules\client\portable\ChGraphx\ChTrMisc.cpp
DEP_CPP_CHTRMI=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\ChTriangle.h"\
	"\chaco\include\ChTypes.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# SUBTRACT CPP /Yu

"$(INTDIR)\ChTrMisc.obj" : $(SOURCE) $(DEP_CPP_CHTRMI) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\ChTrMisc.obj" : $(SOURCE) $(DEP_CPP_CHTRMI) "$(INTDIR)"
   $(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\ChTrMisc.obj" : $(SOURCE) $(DEP_CPP_CHTRMI) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\modules\client\portable\ChGraphx\ChTriangle.cpp
DEP_CPP_CHTRI=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\ChTriangle.h"\
	"\chaco\include\ChTypes.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# SUBTRACT CPP /Yu

"$(INTDIR)\ChTriangle.obj" : $(SOURCE) $(DEP_CPP_CHTRI) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\ChTriangle.obj" : $(SOURCE) $(DEP_CPP_CHTRI) "$(INTDIR)"
   $(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\ChTriangle.obj" : $(SOURCE) $(DEP_CPP_CHTRI) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\modules\client\portable\ChGraphx\ChTrConstr.cpp
DEP_CPP_CHTRC=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\ChTriangle.h"\
	"\chaco\include\ChTypes.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# SUBTRACT CPP /Yu

"$(INTDIR)\ChTrConstr.obj" : $(SOURCE) $(DEP_CPP_CHTRC) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\ChTrConstr.obj" : $(SOURCE) $(DEP_CPP_CHTRC) "$(INTDIR)"
   $(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\ChTrConstr.obj" : $(SOURCE) $(DEP_CPP_CHTRC) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\modules\client\portable\ChGraphx\xlines.cpp
DEP_CPP_XLINE=\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"..\..\portable\include\ChTriangle.h"\
	"\chaco\include\ChTypes.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# SUBTRACT CPP /Yu

"$(INTDIR)\xlines.obj" : $(SOURCE) $(DEP_CPP_XLINE) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\xlines.obj" : $(SOURCE) $(DEP_CPP_XLINE) "$(INTDIR)"
   $(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\xlines.obj" : $(SOURCE) $(DEP_CPP_XLINE) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\modules\client\portable\ChGraphx\inverse.cpp
DEP_CPP_INVER=\
	"..\..\portable\ChGraphx\GxTrnsfm.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	"\chaco\include\ChTypes.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# SUBTRACT CPP /Yu

"$(INTDIR)\inverse.obj" : $(SOURCE) $(DEP_CPP_INVER) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\inverse.obj" : $(SOURCE) $(DEP_CPP_INVER) "$(INTDIR)"
   $(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\inverse.obj" : $(SOURCE) $(DEP_CPP_INVER) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\chaco\modules\client\portable\ChGraphx\GxQuaternion.cpp
DEP_CPP_GXQUA=\
	"..\..\portable\ChGraphx\GxQuaternion.h"\
	"..\..\portable\ChGraphx\GxTypes.h"\
	

!IF  "$(CFG)" == "ChGraphx - Win32 Reality Debug"

# SUBTRACT CPP /Yu

"$(INTDIR)\GxQuaternion.obj" : $(SOURCE) $(DEP_CPP_GXQUA) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "CH_IMMED_MODE" /D "_WINDLL"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 Reality Release"

# SUBTRACT CPP /Yu

"$(INTDIR)\GxQuaternion.obj" : $(SOURCE) $(DEP_CPP_GXQUA) "$(INTDIR)"
   $(CPP) /nologo /MD /W3 /Gm /GX /Zi /O2 /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "NDEBUG" /D\
 "CH_USE_RLAB" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ChGraphx - Win32 D3D Debug"

# SUBTRACT BASE CPP /Yu
# SUBTRACT CPP /Yu

"$(INTDIR)\GxQuaternion.obj" : $(SOURCE) $(DEP_CPP_GXQUA) "$(INTDIR)"
   $(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /I "\chaco\include" /I\
 "..\..\portable\include" /I "..\..\portable\ChGraphx" /D "_DEBUG" /D\
 "CH_USE_D3D" /D "CH_VRML_EVENTS" /D "WIN32" /D "_WINDOWS" /D "CH_MSW" /D\
 "CH_CLIENT" /D "CH_USE_2D" /D "CH_EXCEPTIONS" /D "_WINDLL" /D "_AFXDLL" /D\
 "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE)


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
