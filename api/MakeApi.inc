# MakeApi.inc

# This file defines things we need for both the client and server api Makefiles

API_OBJECTS = ChMsg.o ChCore.o ChDispat.o ChModule.o ChMsgCon.o ChConn.o \
	ChData.o ChMData.o ChArch.o ChStrmbl.o ChVers.o ChFdSet.o \
	ChModMgr.o ChSerMod.o ChClMod.o ChSplay.o ChList.o \
	ChUnix.o sockstrm.o sockinet.o ChMenu.o ChRMenu.o \
	ChTime.o ChHook.o ChMsgTyp.o ChAcct.o ChClInfo.o ChDb.o ChNdbm.o \
	ChPerFrm.o ChUtil.o ChWType.o

SOURCES_LOCAL = $(patsubst %.o,%.cpp,$(OBJECTS))
SOURCES_PARENT = $(patsubst %,../%,$(SOURCES_LOCAL))
SOURCES = /dev/null

%.o : ../%.cpp
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) $<

