@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h

echo // MAKEHELP.BAT generated Help Map file.  Used by Pueblo.HPJ. > hlp\Pueblo.hm
echo. >> hlp\Pueblo.hm

echo // Commands (ID_* and IDM_*) >> hlp\Pueblo.hm
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >> hlp\Pueblo.hm

echo. >> hlp\Pueblo.hm

echo // Prompts (IDP_*) >> hlp\Pueblo.hm
makehm IDP_,HIDP_,0x30000 resource.h >> hlp\Pueblo.hm

echo. >> hlp\Pueblo.hm

echo // Resources (IDR_*) >> hlp\Pueblo.hm
makehm IDR_,HIDR_,0x20000 resource.h >> hlp\Pueblo.hm

echo. >> hlp\Pueblo.hm

echo // Dialogs (IDD_*) >> hlp\Pueblo.hm
makehm IDD_,HIDD_,0x20000 resource.h >> hlp\Pueblo.hm

echo. >> hlp\Pueblo.hm

echo // Frame Controls (IDW_*) >> hlp\Pueblo.hm

makehm IDW_,HIDW_,0x50000 resource.h >> hlp\Pueblo.hm

REM -- Make help for Project PUEBLO

echo Building Win32 Help files

REM call hc31 Pueblo.hpj
echo.

REM if exist \chaco\bin\Debug copy Pueblo.hlp \chaco\bin\Debug
REM if exist \chaco\bin\Release copy Pueblo.hlp \chaco\bin\Release

EndLocal
