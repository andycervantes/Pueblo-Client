COMPS = ApiUtil Api WTracker ChGraphx ChWorld Pueblo ChSound ChAd
API_DIR=\chaco\api
APIUTIL_DIR=\chaco\apiutil
CLEANCOMPS = Clean_Api Clean_WTracker Clean_ChGraphx Clean_ChWorld Clean_Pueblo Clean_ChSound  Clean_ChAd
MOD_DIR=modules\client\msw
MOD_DIR_INV=..\..\..
HTML_VIEWER_DIR=viewer\html\msw\Wtracker
HTML_VIEWER_DIR_INV=..\..\..\..
PUEBLO_LIB=\chaco\lib\Pueblo32.lib
PBUTIL_LIB=\chaco\lib\PbUtil32.lib
WTRACKER_LIB=\chaco\lib\WTracker.lib

!IF "$(BLDCFG)"=="Win32 Release"
GRAPHICS_CFG="ChGraphx - Win32 Reality Release"
!ELSE
GRAPHICS_CFG="ChGraphx - Win32 Reality Debug"
!ENDIF

!IF "$(BLDCFG)"=="Win32 Release"
API_CFG="Pueblo40 - Win32 Release"
!ELSE
API_CFG="Pueblo40 - Win32 Debug"
!ENDIF

!IF "$(BLDCFG)"=="Win32 Release"
APIUTIL_CFG="PbUtil32 - Win32 Release"
!ELSE
APIUTIL_CFG="PbUtil32 - Win32 Debug"
!ENDIF

!IF "$(BLDCFG)"=="Win32 Release"
WTRACKER_CFG="WTracker - Win32 Release"
!ELSE
WTRACKER_CFG="WTracker - Win32 Debug"
!ENDIF

!IF "$(BLDCFG)" =="Win32 Release"
PUEBLO_CFG="Pueblo - Win32 Release"
!ELSE
PUEBLO_CFG="Pueblo - Win32 Debug"
!ENDIF

!IF "$(BLDCFG)"=="Win32 Release"
WORLD_CFG="ChWorld - Win32 Release"
!ELSE
WORLD_CFG="ChWorld - Win32 Debug"
!ENDIF

!IF "$(BLDCFG)"=="Win32 Release"
SOUND_CFG="ChSound - Win32 Release"
!ELSE
SOUND_CFG="ChSound - Win32 Debug"
!ENDIF




ALL: $(COMPS)

CLEAN: $(CLEANCOMPS)

APIUTIL_DEP= \
	$(APIUTIL_DIR)/PbUtil32.cpp \
	$(APIUTIL_DIR)/PbUtil32.rc \
	$(APIUTIL_DIR)/headers.cpp \
	$(APIUTIL_DIR)/jcomapi.cpp \
	$(APIUTIL_DIR)/jdapi.cpp \
	$(APIUTIL_DIR)/jdatasrc.cpp \
	$(APIUTIL_DIR)/jdcoefct.cpp \
	$(APIUTIL_DIR)/jdcolor.cpp \
	$(APIUTIL_DIR)/jddctmgr.cpp \
	$(APIUTIL_DIR)/jdhuff.cpp \
	$(APIUTIL_DIR)/jdmainct.cpp \
	$(APIUTIL_DIR)/jdmarker.cpp \
	$(APIUTIL_DIR)/jdmaster.cpp \
	$(APIUTIL_DIR)/jdmerge.cpp \
	$(APIUTIL_DIR)/jdpostct.cpp \
	$(APIUTIL_DIR)/jdsample.cpp \
	$(APIUTIL_DIR)/jerror.cpp \
	$(APIUTIL_DIR)/jfdctint.cpp \
	$(APIUTIL_DIR)/jidctflt.cpp \
	$(APIUTIL_DIR)/jidctint.cpp \
	$(APIUTIL_DIR)/jmemmgr.cpp \
	$(APIUTIL_DIR)/jquant1.cpp \
	$(APIUTIL_DIR)/jquant2.cpp \
	$(APIUTIL_DIR)/jutils.cpp \
	$(APIUTIL_DIR)/ChJPEG.cpp \
	$(APIUTIL_DIR)/ChUnzip.cpp \
	$(APIUTIL_DIR)/explode.cpp \
	$(APIUTIL_DIR)/extract.cpp \
	$(APIUTIL_DIR)/file_io.cpp \
	$(APIUTIL_DIR)/inflate.cpp \
	$(APIUTIL_DIR)/match.cpp \
	$(APIUTIL_DIR)/unreduce.cpp \
	$(APIUTIL_DIR)/unshrink.cpp \
	$(APIUTIL_DIR)/ChGIF.cpp \
	$(APIUTIL_DIR)/ChDib.cpp \
	$(APIUTIL_DIR)/ChDibPal.cpp \
	$(APIUTIL_DIR)/ChDibUtl.cpp \
	$(APIUTIL_DIR)/ChSFImg.cpp



API_DEP= \
	$(API_DIR)/ChMsg.cpp \
	$(API_DIR)/ChModule.cpp \
	$(API_DIR)/headers.cpp \
	$(API_DIR)/ChDispat.cpp \
	$(API_DIR)/ChStrmbl.cpp \
	$(API_DIR)/ChUser.cpp \
	$(API_DIR)/ChMsgCon.cpp \
	$(API_DIR)/ChConn.cpp \
	$(API_DIR)/ChReg.cpp \
	$(API_DIR)/ChMData.cpp \
	$(API_DIR)/ChData.cpp \
	$(API_DIR)/ChArch.cpp \
	$(API_DIR)/ChCore.cpp \
	$(API_DIR)/ChMsgTyp.cpp \
	$(API_DIR)/ChExcept.cpp \
	$(API_DIR)/ChSplay.cpp \
	$(API_DIR)/ChModMgr.cpp \
	$(API_DIR)/ChVers.cpp \
	$(API_DIR)/ChClMod.cpp \
	$(API_DIR)/ChSplit.cpp \
	$(API_DIR)/ChRMenu.cpp \
	$(API_DIR)/ChMenu.cpp \
	$(API_DIR)/ChList.cpp \
	$(API_DIR)/ChHook.cpp \
	$(API_DIR)/ChTime.cpp \
	$(API_DIR)/ChScrWnd.cpp \
	$(API_DIR)/ChSock.cpp \
	$(API_DIR)/ChAcct.cpp \
	$(API_DIR)/ChClInfo.cpp \
	$(API_DIR)/ChPerFrm.cpp \
	$(API_DIR)/Pueblo.cpp \
	$(API_DIR)/Pueblo.rc \
	$(API_DIR)/ChPage.cpp \
	$(API_DIR)/ChUtil.cpp \
	$(API_DIR)/ChKeyMap.cpp \
	$(API_DIR)/ChDlg.cpp \
	$(API_DIR)/ChWType.cpp \
	$(API_DIR)/ChPane.cpp \
	$(API_DIR)/ChMime.cpp \
	$(API_DIR)/ChPblDoc.cpp \
	$(API_DIR)/ChWizard.cpp \
	$(API_DIR)/ChHtmFrm.cpp \
	$(API_DIR)/ChHtmMsg.cpp \
	$(API_DIR)/ChHtmWnd.cpp \
	$(API_DIR)/ChTxRndr.cpp \
	$(API_DIR)/ChTxtEng.cpp \
	$(API_DIR)/ChTxtObj.cpp \
	$(API_DIR)/ChTxtWnd.cpp \
	$(API_DIR)/ChHTNtfy.cpp \
	$(API_DIR)/ChHTPriv.cpp \
	$(API_DIR)/ChHTTP.cpp \
	$(API_DIR)/ChThread.cpp \
	$(API_DIR)/ChUrlMap.cpp \
	$(API_DIR)/ChDb.cpp \
	$(API_DIR)/ChNdbm.cpp

ApiUtil $(PBUTIL_LIB) : $(APIUTIL_DEP)
	cd apiutil
	nmake /f PbUtil40.mak	CFG=$(APIUTIL_CFG)
	cd ..


Api $(PUEBLO_LIB) :     $(API_DEP)      $(PBUTIL_LIB)
	cd api
	nmake /f Pueblo40.mak	 CFG=$(API_CFG)
	cd ..

WTracker $(WTRACKER_LIB) : Api $(PUEBLO_LIB) 
	cd $(HTML_VIEWER_DIR)
	nmake /f WTracker40.mak CFG=$(WTRACKER_CFG)
	cd $(HTML_VIEWER_DIR_INV)


#       GRAPHICS_CFG should be something like "Reality Debug"

ChGraphx : Api $(PUEBLO_LIB)
	cd $(MOD_DIR)
	cd ChGraphx
	nmake /f ChGraphx40.mak  CFG=$(GRAPHICS_CFG)
	cd ..
	cd $(MOD_DIR_INV)

ChWorld :  Api
	cd $(MOD_DIR)
	cd ChWorld
	nmake /f ChWorld40.mak CFG=$(WORLD_CFG)
	cd ..
	cd $(MOD_DIR_INV)

ChSound :  Api
	cd $(MOD_DIR)
	cd ChSound
	nmake /f ChSound40.mak CFG=$(SOUND_CFG)
	cd ..
	cd $(MOD_DIR_INV)

ChAd :  Api
	cd $(MOD_DIR)
	cd ChAd
	nmake /f ChAd.mak
	cd ..
	cd $(MOD_DIR_INV)


Pueblo :  Api WTracker 
	cd client\msw
	nmake /f PuebloClient.mak CFG=$(PUEBLO_CFG)
	cd ..\..

Clean_Api :
	cd api
	if exist windebug rmdir /s /q WinDebug
	if exist debug rmdir /s /q Debug
	if exist winrel rmdir /s /q WinRel
	cd ..

Clean_WTracker :
	cd $(HTML_VIEWER_DIR)
	if exist windebug rmdir /s /q WinDebug
	if exist winrel rmdir /s /q WinRel
	if exist debug rmdir /s /q Debug
	cd $(HTML_VIEWER_DIR_INV)

Clean_ChGraphx :
	cd $(MOD_DIR)
	cd ChGraphx 
	if exist windebug rmdir /s /q WinDebug
	if exist winrel rmdir /s /q WinRel
	if exist debug rmdir /s /q Debug
	cd ..
	cd $(MOD_DIR_INV)

Clean_ChWorld : 
	cd $(MOD_DIR)
	cd ChWorld
	if exist debug rmdir /s /q Debug
	if exist windebug rmdir /s /q WinDebug
	if exist winrel rmdir /s /q WinRel
	cd ..
	cd $(MOD_DIR_INV)

Clean_ChSound : 
	cd $(MOD_DIR)
	cd ChSound
	if exist windebug rmdir /s /q WinDebug
	if exist winrel rmdir /s /q WinRel
	if exist debug rmdir /s /q Debug
	cd ..
	cd $(MOD_DIR_INV)

Clean_ChAd : 
	cd $(MOD_DIR)
	cd ChAd
	if exist windebug rmdir /s /q WinDebug
	if exist debug rmdir /s /q Debug
	if exist winrel rmdir /s /q WinRel
	cd ..
	cd $(MOD_DIR_INV)

Clean_Pueblo :
	cd client\msw
	if exist windebug rmdir /s /q WinDebug
	if exist winrel rmdir /s /q WinRel
	if exist debug rmdir /s /q Debug
	cd ..\..
