# Makefile for Chaco Communications server

TOP = ../..
TARGET=../libClApi$(SHARED_EXTENSION)
CXXFLAGS_EXTRA=-DCH_CLIENT -I../
include ../MakeApi.inc
OBJECTS = $(API_OBJECTS) ChTxtWnd.o ChScrlVw.o ChHtmWnd.o ChParse.o \
	ChDC.o ChFont.o ChReg.o ChHTPriv.o ChHTTP.o ChThread.o ChTxtObj.o \
	ChHtmFrm.o ChGIF.o ChHtmMsg.o ChMime.o ChJPEG.o \
	jcomapi.o jdapi.o jdatasrc.o jdcoefct.o jdcolor.o jddctmgr.o \
	jdhuff.o jdmainct.o jdmarker.o jdmaster.o jdmerge.o jdpostct.o \
	jdsample.o jerror.o jfdctint.o jidctflt.o jidctint.o jmemmgr.o \
	jquant1.o jquant2.o jutils.o ChPane.o ChSplit.o ChUrlMap.o
include $(TOP)/Make.inc

../libClApi.a: $(OBJECTS)
	ar cr $@ $^

../libClApi$(SHARED_EXTENSION): $(OBJECTS)
	$(LD_SO) -o $@ $^

depend::
	ln -s $(SOURCES_PARENT) .
	makedepend -Y $(SOURCES_LOCAL) $(CXXFLAGS)
	rm $(SOURCES_LOCAL)

# DO NOT DELETE

ChMsg.o: ../headers.h ../../include/ChTypes.h ../../include/ChMsg.h
ChMsg.o: ../../include/ChMData.h ../../include/ChData.h
ChMsg.o: ../../include/ChMsgCon.h ../../include/ChConn.h
ChMsg.o: ../../include/SocketXX.h ../../include/sockstrm.h
ChMsg.o: ../../include/sockinet.h ../../include/ChSplay.h
ChMsg.o: ../../include/protocol.h ../../include/ChVers.h
ChMsg.o: ../../include/ChStrmbl.h
ChCore.o: ../headers.h ../resource.h ../../include/ChTypes.h
ChCore.o: ../../include/ChDispat.h ../../include/ChModule.h
ChCore.o: ../../include/ChStrmbl.h ../../include/ChVers.h
ChCore.o: ../../include/ChMsg.h ../../include/ChMData.h
ChCore.o: ../../include/ChData.h ../../include/ChMsgCon.h
ChCore.o: ../../include/ChConn.h ../../include/SocketXX.h
ChCore.o: ../../include/sockstrm.h ../../include/sockinet.h
ChCore.o: ../../include/ChSplay.h ../../include/protocol.h
ChCore.o: ../../include/ChCore.h ../../include/ChModMgr.h
ChCore.o: ../../include/ChClInfo.h ../../include/ChList.h
ChCore.o: ../../include/ChWType.h ../../include/ChPerFrm.h
ChCore.o: ../../include/ChMsgTyp.h ../../include/ChArch.h
ChCore.o: ../../include/ChTime.h ../../include/ChAcct.h
ChDispat.o: ../headers.h ../../include/ChDispat.h ../../include/ChModule.h
ChDispat.o: ../../include/ChTypes.h ../../include/ChStrmbl.h
ChDispat.o: ../../include/ChVers.h ../../include/ChMsg.h
ChDispat.o: ../../include/ChMData.h ../../include/ChData.h
ChDispat.o: ../../include/ChMsgCon.h ../../include/ChConn.h
ChDispat.o: ../../include/SocketXX.h ../../include/sockstrm.h
ChDispat.o: ../../include/sockinet.h ../../include/ChSplay.h
ChDispat.o: ../../include/protocol.h ../../include/ChModMgr.h
ChDispat.o: ../../include/ChCore.h ../../include/ChClInfo.h
ChDispat.o: ../../include/ChList.h ../../include/ChWType.h
ChDispat.o: ../../include/ChPerFrm.h
ChModule.o: ../headers.h ../../include/ChCore.h ../../include/ChModule.h
ChModule.o: ../../include/ChTypes.h ../../include/ChStrmbl.h
ChModule.o: ../../include/ChVers.h ../../include/ChMsg.h
ChModule.o: ../../include/ChMData.h ../../include/ChData.h
ChModule.o: ../../include/ChMsgCon.h ../../include/ChConn.h
ChModule.o: ../../include/SocketXX.h ../../include/sockstrm.h
ChModule.o: ../../include/sockinet.h ../../include/ChSplay.h
ChModule.o: ../../include/protocol.h ../../include/ChModMgr.h
ChModule.o: ../../include/ChClInfo.h ../../include/ChList.h
ChModule.o: ../../include/ChWType.h ../../include/ChPerFrm.h
ChModule.o: ../../include/ChArch.h
ChMsgCon.o: ../headers.h ../../include/ChMsgCon.h ../../include/ChConn.h
ChMsgCon.o: ../../include/SocketXX.h ../../include/sockstrm.h
ChMsgCon.o: ../../include/ChTypes.h ../../include/sockinet.h
ChMsgCon.o: ../../include/ChSplay.h ../../include/protocol.h
ChMsgCon.o: ../../include/ChCore.h ../../include/ChModule.h
ChMsgCon.o: ../../include/ChStrmbl.h ../../include/ChVers.h
ChMsgCon.o: ../../include/ChMsg.h ../../include/ChMData.h
ChMsgCon.o: ../../include/ChData.h ../../include/ChModMgr.h
ChMsgCon.o: ../../include/ChClInfo.h ../../include/ChList.h
ChMsgCon.o: ../../include/ChWType.h ../../include/ChPerFrm.h
ChConn.o: ../headers.h ../../include/ChConn.h ../../include/SocketXX.h
ChConn.o: ../../include/sockstrm.h ../../include/ChTypes.h
ChConn.o: ../../include/sockinet.h ../../include/ChSplay.h
ChConn.o: ../../include/protocol.h ../../include/ChMsg.h
ChConn.o: ../../include/ChMData.h ../../include/ChData.h
ChConn.o: ../../include/ChMsgCon.h ../../include/ChVers.h
ChConn.o: ../../include/ChStrmbl.h
ChData.o: ../headers.h ../../include/ChData.h ../../include/ChTypes.h
ChMData.o: ../headers.h ../../include/ChMData.h ../../include/ChTypes.h
ChMData.o: ../../include/ChData.h ../../include/ChExcept.h
ChArch.o: ../headers.h ../../include/ChArch.h ../../include/ChTypes.h
ChArch.o: ../../include/ChData.h ../../include/ChStrmbl.h
ChArch.o: ../../include/ChExcept.h
ChStrmbl.o: ../headers.h ../../include/ChTypes.h ../../include/ChStrmbl.h
ChVers.o: ../headers.h ../../include/ChArch.h ../../include/ChTypes.h
ChVers.o: ../../include/ChData.h ../../include/ChStrmbl.h
ChVers.o: ../../include/ChVers.h
ChFdSet.o: ../../include/ChTypes.h ../../include/sockinet.h
ChFdSet.o: ../../include/ChSplay.h ../../include/sockstrm.h
ChFdSet.o: ../../include/ChFdSet.h
ChModMgr.o: ../headers.h ../../include/ChModMgr.h ../../include/ChTypes.h
ChModMgr.o: ../../include/ChModule.h ../../include/ChStrmbl.h
ChModMgr.o: ../../include/ChVers.h ../../include/ChMsg.h
ChModMgr.o: ../../include/ChMData.h ../../include/ChData.h
ChModMgr.o: ../../include/ChMsgCon.h ../../include/ChConn.h
ChModMgr.o: ../../include/SocketXX.h ../../include/sockstrm.h
ChModMgr.o: ../../include/sockinet.h ../../include/ChSplay.h
ChModMgr.o: ../../include/protocol.h ../../include/ChMsgTyp.h
ChModMgr.o: ../../include/ChArch.h ../../include/ChTime.h
ChModMgr.o: ../../include/ChAcct.h ../../include/ChClInfo.h
ChModMgr.o: ../../include/ChDispat.h ../../include/ChList.h
ChModMgr.o: ../../include/ChWorld.h
ChSerMod.o: ../headers.h ../../include/ChArch.h ../../include/ChTypes.h
ChSerMod.o: ../../include/ChData.h ../../include/ChStrmbl.h
ChSerMod.o: ../../include/ChCore.h ../../include/ChModule.h
ChSerMod.o: ../../include/ChVers.h ../../include/ChMsg.h
ChSerMod.o: ../../include/ChMData.h ../../include/ChMsgCon.h
ChSerMod.o: ../../include/ChConn.h ../../include/SocketXX.h
ChSerMod.o: ../../include/sockstrm.h ../../include/sockinet.h
ChSerMod.o: ../../include/ChSplay.h ../../include/protocol.h
ChSerMod.o: ../../include/ChModMgr.h ../../include/ChClInfo.h
ChSerMod.o: ../../include/ChList.h ../../include/ChWType.h
ChSerMod.o: ../../include/ChPerFrm.h ../../include/ChSerMod.h
ChSerMod.o: ../../include/ChUser.h ../../include/ChText.h
ChClMod.o: ../headers.h ../../include/ChArch.h ../../include/ChTypes.h
ChClMod.o: ../../include/ChData.h ../../include/ChStrmbl.h
ChClMod.o: ../../include/ChVers.h ../../include/ChClMod.h
ChClMod.o: ../../include/ChModule.h ../../include/ChMsg.h
ChClMod.o: ../../include/ChMData.h ../../include/ChMsgCon.h
ChClMod.o: ../../include/ChConn.h ../../include/SocketXX.h
ChClMod.o: ../../include/sockstrm.h ../../include/sockinet.h
ChClMod.o: ../../include/ChSplay.h ../../include/protocol.h
ChClMod.o: ../../include/ChUser.h ../../include/ChCore.h
ChClMod.o: ../../include/ChModMgr.h ../../include/ChClInfo.h
ChClMod.o: ../../include/ChList.h ../../include/ChWType.h
ChClMod.o: ../../include/ChPerFrm.h
ChSplay.o: ../headers.h ../../include/ChTypes.h ../../include/ChSplay.h
ChList.o: ../headers.h ../../include/ChList.h ../../include/ChTypes.h
ChUnix.o: ../../include/ChTypes.h
sockstrm.o: ../headers.h ../../include/SocketXX.h ../../include/sockstrm.h
sockstrm.o: ../../include/ChTypes.h ../../include/sockinet.h
sockstrm.o: ../../include/ChSplay.h ../../include/ChExcept.h
sockinet.o: ../headers.h ../../include/ChExcept.h ../../include/SocketXX.h
sockinet.o: ../../include/sockstrm.h ../../include/ChTypes.h
sockinet.o: ../../include/sockinet.h ../../include/ChSplay.h
ChMenu.o: ../headers.h ../../include/ChTypes.h ../../include/ChMenu.h
ChMenu.o: ../../include/ChVers.h ../../include/ChStrmbl.h
ChMenu.o: ../../include/ChMsg.h ../../include/ChMData.h
ChMenu.o: ../../include/ChData.h ../../include/ChMsgCon.h
ChMenu.o: ../../include/ChConn.h ../../include/SocketXX.h
ChMenu.o: ../../include/sockstrm.h ../../include/sockinet.h
ChMenu.o: ../../include/ChSplay.h ../../include/protocol.h
ChMenu.o: ../../include/ChDispat.h ../../include/ChModule.h
ChMenu.o: ../../include/ChExcept.h ../../include/ChList.h
ChMenu.o: ../../include/ChRMenu.h
ChRMenu.o: ../headers.h ../../include/ChTypes.h ../../include/ChMenu.h
ChRMenu.o: ../../include/ChVers.h ../../include/ChStrmbl.h
ChRMenu.o: ../../include/ChMsg.h ../../include/ChMData.h
ChRMenu.o: ../../include/ChData.h ../../include/ChMsgCon.h
ChRMenu.o: ../../include/ChConn.h ../../include/SocketXX.h
ChRMenu.o: ../../include/sockstrm.h ../../include/sockinet.h
ChRMenu.o: ../../include/ChSplay.h ../../include/protocol.h
ChRMenu.o: ../../include/ChDispat.h ../../include/ChModule.h
ChRMenu.o: ../../include/ChExcept.h ../../include/ChList.h
ChRMenu.o: ../../include/ChRMenu.h ../../include/ChModMgr.h
ChRMenu.o: ../../include/ChCore.h ../../include/ChClInfo.h
ChRMenu.o: ../../include/ChWType.h ../../include/ChPerFrm.h
ChRMenu.o: ../../include/ChMsgTyp.h ../../include/ChArch.h
ChRMenu.o: ../../include/ChTime.h ../../include/ChAcct.h
ChTime.o: ../headers.h ../../include/ChStrmbl.h ../../include/ChTypes.h
ChTime.o: ../../include/ChData.h ../../include/ChArch.h
ChTime.o: ../../include/ChTime.h
ChHook.o: ../headers.h ../../include/ChCore.h ../../include/ChModule.h
ChHook.o: ../../include/ChTypes.h ../../include/ChStrmbl.h
ChHook.o: ../../include/ChVers.h ../../include/ChMsg.h
ChHook.o: ../../include/ChMData.h ../../include/ChData.h
ChHook.o: ../../include/ChMsgCon.h ../../include/ChConn.h
ChHook.o: ../../include/SocketXX.h ../../include/sockstrm.h
ChHook.o: ../../include/sockinet.h ../../include/ChSplay.h
ChHook.o: ../../include/protocol.h ../../include/ChModMgr.h
ChHook.o: ../../include/ChClInfo.h ../../include/ChList.h
ChHook.o: ../../include/ChWType.h ../../include/ChPerFrm.h
ChHook.o: ../../include/ChHook.h
ChMsgTyp.o: ../headers.h ../../include/ChTypes.h ../../include/ChMsgTyp.h
ChMsgTyp.o: ../../include/ChMData.h ../../include/ChData.h
ChMsgTyp.o: ../../include/ChMsg.h ../../include/ChMsgCon.h
ChMsgTyp.o: ../../include/ChConn.h ../../include/SocketXX.h
ChMsgTyp.o: ../../include/sockstrm.h ../../include/sockinet.h
ChMsgTyp.o: ../../include/ChSplay.h ../../include/protocol.h
ChMsgTyp.o: ../../include/ChVers.h ../../include/ChStrmbl.h
ChMsgTyp.o: ../../include/ChArch.h ../../include/ChTime.h
ChMsgTyp.o: ../../include/ChAcct.h ../../include/ChClInfo.h
ChAcct.o: ../headers.h ../../include/ChArch.h ../../include/ChTypes.h
ChAcct.o: ../../include/ChData.h ../../include/ChStrmbl.h
ChAcct.o: ../../include/ChAcct.h
ChClInfo.o: ../headers.h ../../include/ChArch.h ../../include/ChTypes.h
ChClInfo.o: ../../include/ChData.h ../../include/ChStrmbl.h
ChClInfo.o: ../../include/ChClInfo.h ../../include/ChVers.h
ChClInfo.o: ../../include/ChConst.h
ChDb.o: ../headers.h ../../include/ChTypes.h ../../include/ChDb.h ../ChNdbm.h
ChNdbm.o: ../headers.h ../../include/ChTypes.h ../ChNdbm.h
ChPerFrm.o: ../headers.h ../../include/ChPerFrm.h ../../include/ChTypes.h
ChUtil.o: ../headers.h ../resource.h ../../include/ChUtil.h
ChUtil.o: ../../include/ChClInfo.h ../../include/ChTypes.h
ChUtil.o: ../../include/ChData.h ../../include/ChStrmbl.h
ChUtil.o: ../../include/ChVers.h
ChTxtWnd.o: ../headers.h ../../include/ChTypes.h ../../include/ChRect.h
ChTxtWnd.o: ../../include/ChSize.h ../../include/ChScrlVw.h
ChTxtWnd.o: ../../include/ChDC.h ../../include/ChFont.h
ChTxtWnd.o: ../../include/ChTxtWnd.h ../../include/ChTxtObj.h
ChTxtWnd.o: ../../include/ChDib.h
ChScrlVw.o: ../../include/ChTypes.h ../../include/ChRect.h
ChScrlVw.o: ../../include/ChSize.h ../../include/ChScrlVw.h
ChScrlVw.o: ../../include/ChDC.h ../../include/ChFont.h
ChHtmWnd.o: ../headers.h ../../include/ChTypes.h ../../include/ChRect.h
ChHtmWnd.o: ../../include/ChSize.h ../../include/ChScrlVw.h
ChHtmWnd.o: ../../include/ChDC.h ../../include/ChFont.h
ChHtmWnd.o: ../../include/ChHtmWnd.h ../../include/ChHTTP.h
ChHtmWnd.o: ../../include/sockinet.h ../../include/ChSplay.h
ChHtmWnd.o: ../../include/sockstrm.h ../../include/ChTxtWnd.h
ChHtmWnd.o: ../../include/ChTxtObj.h ../../include/ChDib.h
ChHtmWnd.o: ../../include/ChList.h ../../include/ChHtmFrm.h
ChHtmWnd.o: ../../include/ChMsgTyp.h ../../include/ChMData.h
ChHtmWnd.o: ../../include/ChData.h ../../include/ChMsg.h
ChHtmWnd.o: ../../include/ChMsgCon.h ../../include/ChConn.h
ChHtmWnd.o: ../../include/SocketXX.h ../../include/protocol.h
ChHtmWnd.o: ../../include/ChVers.h ../../include/ChStrmbl.h
ChHtmWnd.o: ../../include/ChArch.h ../../include/ChTime.h
ChHtmWnd.o: ../../include/ChAcct.h ../../include/ChClInfo.h ../ChParse.h
ChParse.o: ../headers.h ../../include/ChTypes.h ../../include/ChRect.h
ChParse.o: ../../include/ChSize.h ../../include/ChScrlVw.h
ChParse.o: ../../include/ChDC.h ../../include/ChFont.h ../../include/ChReg.h
ChParse.o: ../../include/ChDb.h ../../include/ChConst.h
ChParse.o: ../../include/ChHtmWnd.h ../../include/ChHTTP.h
ChParse.o: ../../include/sockinet.h ../../include/ChSplay.h
ChParse.o: ../../include/sockstrm.h ../../include/ChTxtWnd.h
ChParse.o: ../../include/ChTxtObj.h ../../include/ChDib.h
ChParse.o: ../../include/ChList.h ../../include/ChHtmFrm.h ../ChParse.h
ChDC.o: ../../include/ChTypes.h ../../include/ChRect.h ../../include/ChSize.h
ChDC.o: ../../include/ChScrlVw.h ../../include/ChDC.h ../../include/ChFont.h
ChFont.o: ../../include/ChTypes.h ../../include/ChSplay.h
ChFont.o: ../../include/ChFont.h
ChReg.o: ../headers.h ../../include/ChTypes.h ../../include/ChConst.h
ChReg.o: ../../include/ChReg.h ../../include/ChDb.h
ChHTPriv.o: ../headers.h ../../include/ChTypes.h ../../include/ChHTTP.h
ChHTPriv.o: ../../include/sockinet.h ../../include/ChSplay.h
ChHTPriv.o: ../../include/sockstrm.h ../../include/ChDb.h
ChHTPriv.o: ../../include/SocketXX.h ../../include/ChCore.h
ChHTPriv.o: ../../include/ChModule.h ../../include/ChStrmbl.h
ChHTPriv.o: ../../include/ChVers.h ../../include/ChMsg.h
ChHTPriv.o: ../../include/ChMData.h ../../include/ChData.h
ChHTPriv.o: ../../include/ChMsgCon.h ../../include/ChConn.h
ChHTPriv.o: ../../include/protocol.h ../../include/ChModMgr.h
ChHTPriv.o: ../../include/ChClInfo.h ../../include/ChList.h
ChHTPriv.o: ../../include/ChWType.h ../../include/ChPerFrm.h
ChHTPriv.o: ../../include/ChReg.h ../../include/ChConst.h
ChHTPriv.o: ../../include/ChExcept.h ../../include/ChMsgTyp.h
ChHTPriv.o: ../../include/ChArch.h ../../include/ChTime.h
ChHTPriv.o: ../../include/ChAcct.h ../../include/ChUtil.h ../ChHTPriv.h
ChHTTP.o: ../headers.h ../../include/ChTypes.h ../../include/ChHTTP.h
ChHTTP.o: ../../include/sockinet.h ../../include/ChSplay.h
ChHTTP.o: ../../include/sockstrm.h ../../include/ChDb.h ../../include/ChReg.h
ChHTTP.o: ../../include/ChConst.h ../../include/SocketXX.h
ChHTTP.o: ../../include/ChCore.h ../../include/ChModule.h
ChHTTP.o: ../../include/ChStrmbl.h ../../include/ChVers.h
ChHTTP.o: ../../include/ChMsg.h ../../include/ChMData.h
ChHTTP.o: ../../include/ChData.h ../../include/ChMsgCon.h
ChHTTP.o: ../../include/ChConn.h ../../include/protocol.h
ChHTTP.o: ../../include/ChModMgr.h ../../include/ChClInfo.h
ChHTTP.o: ../../include/ChList.h ../../include/ChWType.h
ChHTTP.o: ../../include/ChPerFrm.h ../../include/ChMsgTyp.h
ChHTTP.o: ../../include/ChArch.h ../../include/ChTime.h
ChHTTP.o: ../../include/ChAcct.h ../../include/ChUtil.h ../ChHTPriv.h
ChThread.o: ../headers.h ../../include/ChTypes.h ../../include/ChHTTP.h
ChThread.o: ../../include/sockinet.h ../../include/ChSplay.h
ChThread.o: ../../include/sockstrm.h ../../include/ChDb.h
ChThread.o: ../../include/SocketXX.h ../../include/ChCore.h
ChThread.o: ../../include/ChModule.h ../../include/ChStrmbl.h
ChThread.o: ../../include/ChVers.h ../../include/ChMsg.h
ChThread.o: ../../include/ChMData.h ../../include/ChData.h
ChThread.o: ../../include/ChMsgCon.h ../../include/ChConn.h
ChThread.o: ../../include/protocol.h ../../include/ChModMgr.h
ChThread.o: ../../include/ChClInfo.h ../../include/ChList.h
ChThread.o: ../../include/ChWType.h ../../include/ChPerFrm.h
ChThread.o: ../../include/ChMsgTyp.h ../../include/ChArch.h
ChThread.o: ../../include/ChTime.h ../../include/ChAcct.h
ChThread.o: ../../include/ChUtil.h ../ChHTPriv.h
ChTxtObj.o: ../headers.h ../../include/ChTypes.h ../../include/ChRect.h
ChTxtObj.o: ../../include/ChSize.h ../../include/ChScrlVw.h
ChTxtObj.o: ../../include/ChDC.h ../../include/ChFont.h
ChTxtObj.o: ../../include/ChTxtWnd.h ../../include/ChTxtObj.h
ChTxtObj.o: ../../include/ChDib.h
ChHtmFrm.o: ../headers.h ../../include/ChTypes.h ../../include/ChRect.h
ChHtmFrm.o: ../../include/ChSize.h ../../include/ChScrlVw.h
ChHtmFrm.o: ../../include/ChDC.h ../../include/ChFont.h ../../include/ChReg.h
ChHtmFrm.o: ../../include/ChDb.h ../../include/ChConst.h
ChHtmFrm.o: ../../include/ChHtmWnd.h ../../include/ChHTTP.h
ChHtmFrm.o: ../../include/sockinet.h ../../include/ChSplay.h
ChHtmFrm.o: ../../include/sockstrm.h ../../include/ChTxtWnd.h
ChHtmFrm.o: ../../include/ChTxtObj.h ../../include/ChDib.h
ChHtmFrm.o: ../../include/ChList.h ../../include/ChHtmFrm.h ../ChParse.h
ChGIF.o: ../headers.h ../../include/ChTypes.h ../../include/ChDC.h
ChGIF.o: ../../include/ChScrlVw.h ../../include/ChRect.h
ChGIF.o: ../../include/ChSize.h ../../include/ChFont.h ../../include/ChGIF.h
ChGIF.o: ../../include/ChDib.h
ChHtmMsg.o: ../headers.h ../../include/ChTypes.h ../../include/ChRect.h
ChHtmMsg.o: ../../include/ChSize.h ../../include/ChScrlVw.h
ChHtmMsg.o: ../../include/ChCore.h ../../include/ChModule.h
ChHtmMsg.o: ../../include/ChStrmbl.h ../../include/ChVers.h
ChHtmMsg.o: ../../include/ChMsg.h ../../include/ChMData.h
ChHtmMsg.o: ../../include/ChData.h ../../include/ChMsgCon.h
ChHtmMsg.o: ../../include/ChConn.h ../../include/SocketXX.h
ChHtmMsg.o: ../../include/sockstrm.h ../../include/sockinet.h
ChHtmMsg.o: ../../include/ChSplay.h ../../include/protocol.h
ChHtmMsg.o: ../../include/ChModMgr.h ../../include/ChClInfo.h
ChHtmMsg.o: ../../include/ChList.h ../../include/ChWType.h
ChHtmMsg.o: ../../include/ChPerFrm.h ../../include/ChDispat.h
ChHtmMsg.o: ../../include/ChMsgTyp.h ../../include/ChArch.h
ChHtmMsg.o: ../../include/ChTime.h ../../include/ChAcct.h
ChHtmMsg.o: ../../include/ChHtmWnd.h ../../include/ChHTTP.h
ChHtmMsg.o: ../../include/ChTxtWnd.h ../../include/ChDC.h
ChHtmMsg.o: ../../include/ChFont.h ../../include/ChTxtObj.h
ChHtmMsg.o: ../../include/ChDib.h ../../include/ChHtmFrm.h
ChHtmMsg.o: ../../include/ChGIF.h ../../include/ChJPEG.h
ChHtmMsg.o: ../../include/jpeglib.h ../../include/jconfig.h
ChHtmMsg.o: ../../include/jmorecfg.h
ChMime.o: ../headers.h ../../include/ChTypes.h ../../include/ChMsgTyp.h
ChMime.o: ../../include/ChMData.h ../../include/ChData.h
ChMime.o: ../../include/ChMsg.h ../../include/ChMsgCon.h
ChMime.o: ../../include/ChConn.h ../../include/SocketXX.h
ChMime.o: ../../include/sockstrm.h ../../include/sockinet.h
ChMime.o: ../../include/ChSplay.h ../../include/protocol.h
ChMime.o: ../../include/ChVers.h ../../include/ChStrmbl.h
ChMime.o: ../../include/ChArch.h ../../include/ChTime.h
ChMime.o: ../../include/ChAcct.h ../../include/ChClInfo.h
ChMime.o: ../../include/ChCore.h ../../include/ChModule.h
ChMime.o: ../../include/ChModMgr.h ../../include/ChList.h
ChMime.o: ../../include/ChWType.h ../../include/ChPerFrm.h
ChMime.o: ../../include/ChHTTP.h ../../include/ChDispat.h
ChMime.o: ../../include/ChMime.h ../../include/ChHtmWnd.h
ChMime.o: ../../include/ChTxtWnd.h ../../include/ChRect.h
ChMime.o: ../../include/ChScrlVw.h ../../include/ChSize.h
ChMime.o: ../../include/ChDC.h ../../include/ChFont.h
ChMime.o: ../../include/ChTxtObj.h ../../include/ChDib.h
ChMime.o: ../../include/ChHtmFrm.h
ChWType.o: ../headers.h ../../include/ChArch.h ../../include/ChTypes.h
ChWType.o: ../../include/ChData.h ../../include/ChStrmbl.h
ChWType.o: ../../include/ChWType.h
ChJPEG.o: ../headers.h ../../include/ChTypes.h ../../include/ChDC.h
ChJPEG.o: ../../include/ChScrlVw.h ../../include/ChRect.h
ChJPEG.o: ../../include/ChSize.h ../../include/ChFont.h
ChJPEG.o: ../../include/ChExcept.h ../../include/ChJPEG.h
ChJPEG.o: ../../include/ChDib.h ../../include/jpeglib.h
ChJPEG.o: ../../include/jconfig.h ../../include/jmorecfg.h
jcomapi.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jcomapi.o: ../../include/jpeglib.h ../../include/ChTypes.h
jcomapi.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jcomapi.o: ../../include/ChDib.h ../../include/ChDC.h
jcomapi.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jcomapi.o: ../../include/ChSize.h ../../include/ChFont.h
jdapi.o: ../headers.h ../resource.h ../jinclude.h ../../include/jconfig.h
jdapi.o: ../../include/jpeglib.h ../../include/ChTypes.h
jdapi.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jdapi.o: ../../include/ChDib.h ../../include/ChDC.h ../../include/ChScrlVw.h
jdapi.o: ../../include/ChRect.h ../../include/ChSize.h ../../include/ChFont.h
jdapi.o: ../../include/ChUtil.h ../../include/ChWnd.h
jdatasrc.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jdatasrc.o: ../../include/jpeglib.h ../../include/ChTypes.h
jdatasrc.o: ../../include/jmorecfg.h ../jerror.h ../../include/ChJPEG.h
jdatasrc.o: ../../include/ChDib.h ../../include/ChDC.h
jdatasrc.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jdatasrc.o: ../../include/ChSize.h ../../include/ChFont.h
jdcoefct.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jdcoefct.o: ../../include/jpeglib.h ../../include/ChTypes.h
jdcoefct.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jdcoefct.o: ../../include/ChDib.h ../../include/ChDC.h
jdcoefct.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jdcoefct.o: ../../include/ChSize.h ../../include/ChFont.h
jdcolor.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jdcolor.o: ../../include/jpeglib.h ../../include/ChTypes.h
jdcolor.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jdcolor.o: ../../include/ChDib.h ../../include/ChDC.h
jdcolor.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jdcolor.o: ../../include/ChSize.h ../../include/ChFont.h
jddctmgr.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jddctmgr.o: ../../include/jpeglib.h ../../include/ChTypes.h
jddctmgr.o: ../../include/jmorecfg.h ../jdct.h ../../include/ChJPEG.h
jddctmgr.o: ../../include/ChDib.h ../../include/ChDC.h
jddctmgr.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jddctmgr.o: ../../include/ChSize.h ../../include/ChFont.h
jdhuff.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jdhuff.o: ../../include/jpeglib.h ../../include/ChTypes.h
jdhuff.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jdhuff.o: ../../include/ChDib.h ../../include/ChDC.h ../../include/ChScrlVw.h
jdhuff.o: ../../include/ChRect.h ../../include/ChSize.h
jdhuff.o: ../../include/ChFont.h
jdmainct.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jdmainct.o: ../../include/jpeglib.h ../../include/ChTypes.h
jdmainct.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jdmainct.o: ../../include/ChDib.h ../../include/ChDC.h
jdmainct.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jdmainct.o: ../../include/ChSize.h ../../include/ChFont.h
jdmarker.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jdmarker.o: ../../include/jpeglib.h ../../include/ChTypes.h
jdmarker.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jdmarker.o: ../../include/ChDib.h ../../include/ChDC.h
jdmarker.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jdmarker.o: ../../include/ChSize.h ../../include/ChFont.h
jdmaster.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jdmaster.o: ../../include/jpeglib.h ../../include/ChTypes.h
jdmaster.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jdmaster.o: ../../include/ChDib.h ../../include/ChDC.h
jdmaster.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jdmaster.o: ../../include/ChSize.h ../../include/ChFont.h
jdmerge.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jdmerge.o: ../../include/jpeglib.h ../../include/ChTypes.h
jdmerge.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jdmerge.o: ../../include/ChDib.h ../../include/ChDC.h
jdmerge.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jdmerge.o: ../../include/ChSize.h ../../include/ChFont.h
jdpostct.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jdpostct.o: ../../include/jpeglib.h ../../include/ChTypes.h
jdpostct.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jdpostct.o: ../../include/ChDib.h ../../include/ChDC.h
jdpostct.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jdpostct.o: ../../include/ChSize.h ../../include/ChFont.h
jdsample.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jdsample.o: ../../include/jpeglib.h ../../include/ChTypes.h
jdsample.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jdsample.o: ../../include/ChDib.h ../../include/ChDC.h
jdsample.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jdsample.o: ../../include/ChSize.h ../../include/ChFont.h
jerror.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jerror.o: ../../include/jpeglib.h ../../include/ChTypes.h
jerror.o: ../../include/jmorecfg.h ../jversion.h ../jerror.h
jerror.o: ../../include/ChJPEG.h ../../include/ChDib.h ../../include/ChDC.h
jerror.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jerror.o: ../../include/ChSize.h ../../include/ChFont.h
jerror.o: ../../include/ChExcept.h
jfdctint.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jfdctint.o: ../../include/jpeglib.h ../../include/ChTypes.h
jfdctint.o: ../../include/jmorecfg.h ../jdct.h ../../include/ChJPEG.h
jfdctint.o: ../../include/ChDib.h ../../include/ChDC.h
jfdctint.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jfdctint.o: ../../include/ChSize.h ../../include/ChFont.h
jidctflt.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jidctflt.o: ../../include/jpeglib.h ../../include/ChTypes.h
jidctflt.o: ../../include/jmorecfg.h ../jdct.h ../../include/ChJPEG.h
jidctflt.o: ../../include/ChDib.h ../../include/ChDC.h
jidctflt.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jidctflt.o: ../../include/ChSize.h ../../include/ChFont.h
jidctint.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jidctint.o: ../../include/jpeglib.h ../../include/ChTypes.h
jidctint.o: ../../include/jmorecfg.h ../jdct.h ../../include/ChJPEG.h
jidctint.o: ../../include/ChDib.h ../../include/ChDC.h
jidctint.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jidctint.o: ../../include/ChSize.h ../../include/ChFont.h
jmemmgr.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jmemmgr.o: ../../include/jpeglib.h ../../include/ChTypes.h
jmemmgr.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jmemmgr.o: ../../include/ChDib.h ../../include/ChDC.h
jmemmgr.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jmemmgr.o: ../../include/ChSize.h ../../include/ChFont.h
jquant1.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jquant1.o: ../../include/jpeglib.h ../../include/ChTypes.h
jquant1.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jquant1.o: ../../include/ChDib.h ../../include/ChDC.h
jquant1.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jquant1.o: ../../include/ChSize.h ../../include/ChFont.h
jquant2.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jquant2.o: ../../include/jpeglib.h ../../include/ChTypes.h
jquant2.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jquant2.o: ../../include/ChDib.h ../../include/ChDC.h
jquant2.o: ../../include/ChScrlVw.h ../../include/ChRect.h
jquant2.o: ../../include/ChSize.h ../../include/ChFont.h
jutils.o: ../headers.h ../jinclude.h ../../include/jconfig.h
jutils.o: ../../include/jpeglib.h ../../include/ChTypes.h
jutils.o: ../../include/jmorecfg.h ../../include/ChJPEG.h
jutils.o: ../../include/ChDib.h ../../include/ChDC.h ../../include/ChScrlVw.h
jutils.o: ../../include/ChRect.h ../../include/ChSize.h
jutils.o: ../../include/ChFont.h
ChPane.o: ../headers.h ../resource.h ../../include/ChTypes.h
ChPane.o: ../../include/ChConst.h ../../include/ChCore.h
ChPane.o: ../../include/ChModule.h ../../include/ChStrmbl.h
ChPane.o: ../../include/ChVers.h ../../include/ChMsg.h
ChPane.o: ../../include/ChMData.h ../../include/ChData.h
ChPane.o: ../../include/ChMsgCon.h ../../include/ChConn.h
ChPane.o: ../../include/SocketXX.h ../../include/sockstrm.h
ChPane.o: ../../include/sockinet.h ../../include/ChSplay.h
ChPane.o: ../../include/protocol.h ../../include/ChModMgr.h
ChPane.o: ../../include/ChClInfo.h ../../include/ChList.h
ChPane.o: ../../include/ChWType.h ../../include/ChPerFrm.h
ChPane.o: ../../include/ChReg.h ../../include/ChDb.h ../../include/ChPane.h
ChPane.o: ../../include/ChWnd.h ../../include/ChSplit.h
ChPane.o: ../../include/ChRect.h ../../include/ChMsgTyp.h
ChPane.o: ../../include/ChArch.h ../../include/ChTime.h
ChPane.o: ../../include/ChAcct.h ../../include/ChHtmWnd.h
ChPane.o: ../../include/ChHTTP.h ../../include/ChTxtWnd.h
ChPane.o: ../../include/ChScrlVw.h ../../include/ChSize.h
ChPane.o: ../../include/ChDC.h ../../include/ChFont.h
ChPane.o: ../../include/ChTxtObj.h ../../include/ChDib.h
ChPane.o: ../../include/ChHtmFrm.h
ChSplit.o: ../headers.h ../resource.h ../../include/ChConst.h
ChSplit.o: ../../include/ChCore.h ../../include/ChModule.h
ChSplit.o: ../../include/ChTypes.h ../../include/ChStrmbl.h
ChSplit.o: ../../include/ChVers.h ../../include/ChMsg.h
ChSplit.o: ../../include/ChMData.h ../../include/ChData.h
ChSplit.o: ../../include/ChMsgCon.h ../../include/ChConn.h
ChSplit.o: ../../include/SocketXX.h ../../include/sockstrm.h
ChSplit.o: ../../include/sockinet.h ../../include/ChSplay.h
ChSplit.o: ../../include/protocol.h ../../include/ChModMgr.h
ChSplit.o: ../../include/ChClInfo.h ../../include/ChList.h
ChSplit.o: ../../include/ChWType.h ../../include/ChPerFrm.h
ChSplit.o: ../../include/ChWnd.h ../../include/ChSplit.h
ChSplit.o: ../../include/ChReg.h ../../include/ChDb.h ../../include/ChRect.h
