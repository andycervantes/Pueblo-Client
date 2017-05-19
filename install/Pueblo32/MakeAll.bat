@echo off
rem
rem ....Build components...
rem

goto InstRL

:Args
	echo makeall [WIN16 or WIN32S or VOXWARE] [Install shield path]
	echo   [Optional arguments]
	echo      Arg2
	echo         None    - build 32 bit version
	echo         WIN16   - build 16 bit version without win32s
	echo         WIN32S  - build 16 bit version with win32s
	echo         VOXWARE - build 32 bit Voxware version
	echo      Arg3
	echo         Install shield path

:InstRL

	if NOT Exist Setup.rl	md Setup.rl

	copy setup\setup.rul Setup.rl\
	copy MakeData.bat Setup.rl\

	rem	Compile the Reality Labs install script

	cd data\rl
	%2compile rl.rul
	cd ..\..

	rem Create Setup.rl directory tree

	cd Setup.rl
	if NOT Exist disks				md disks
	if NOT Exist Internet			md Internet
	if NOT Exist disks\disk1		md disks\disk1
	if NOT Exist disks\disk2		md disks\disk2
	if NOT Exist disks\disk3		md disks\disk3
	if NOT Exist disks\disk4		md disks\disk4
	if NOT Exist data				md data
	if NOT Exist data\program		md data\program
	if NOT Exist data\help			md data\help
	if NOT Exist data\rl			md data\rl
	if NOT Exist data\shared		md data\shared
	if NOT Exist SetupLib			md SetupLib
	
	if "%1"=="WIN32S"	goto Win16Dir
	if "%1"=="VOXWARE"	goto VoxwareDir

	goto CopyBmp

:Win16Dir

	if NOT Exist disks\disk5	md disks\disk5
	if NOT Exist data\win32s	md data\win32s
	goto CopyBmp

:VoxwareDir

	if NOT Exist disks\disk5	md disks\disk5
	if NOT Exist data\voxware	md data\voxware
	goto CopyBmp

:CopyBmp

	if Exist SetupLib\*.bmp		del SetupLib\*.bmp
	if Exist SetupLib\*.dll		del SetupLib\*.dll

	copy ..\setup\*.bmp SetupLib
	if Exist ..\disk1\uninst.exe	copy ..\disk1\uninst.exe SetupLib
	if Exist ..\disk1\uninst16.exe  copy ..\disk1\uninst16.exe SetupLib
	if Exist ..\disk1\_setup.dll  copy ..\disk1\_setup.dll SetupLib
	del SetupLib\setup.bmp

	rem Copy the data

	xcopy ..\data\program					data\program /s

	copy \chaco\Help\Pueblo32\Pueblo.hlp	data\help\Pueblo.hlp
	copy \chaco\Help\Pueblo32\Pueblo.cnt	data\help\Pueblo.cnt

	copy ..\data\ReadMe.wri					data\

	xcopy ..\data\shared					data\shared /s
	xcopy ..\data\rl						data\rl /s

	if "%1"=="VOXWARE"	xcopy ..\data\voxware	data\voxware /s

	if "%1"=="WIN32S"	xcopy \chaco\install\win32s\disks data\win32s /s

	if "%1"=="VOXWARE" 	goto CompileVoxware
	if "%1"=="WIN16" 	goto CompileWin16
	if "%1"=="WIN32S" 	goto CompileWin32s

	rem Compile for Win32

	%2compile setup.rul
	goto CompileDone

	:CompileVoxware
		%2compile /DVOXWARE=1 setup.rul
		goto CompileDone

	:CompileWin16
		%2compile /DWIN16=1 setup.rul
		goto CompileDone

	:CompileWin32s
 		%2compile /DWIN16=1 /DWIN32S setup.rul
		goto CompileDone

	:CompileDone

	copy setup.ins disks\disk1\setup.ins
	copy setup.ins Internet\setup.ins

	del data.*

	copy ..\setup\_setup.lib

	call MakeData %2

	copy ..\setup\setup.lst
	%2packlist setup.lst
	copy setup.pkg disks\disk1
	copy setup.pkg Internet
	copy ..\disk1\_setup.dll disks\disk1
	copy ..\disk1\_setup.dll Internet
	copy ..\disk1\_ISDEL.EXE disks\disk1
	copy ..\disk1\_ISDEL.EXE Internet
	copy ..\disk1\Setup.ini disks\disk1
	copy ..\disk1\Setup.ini Internet
	if Exist ..\disk1\_INST16.EX_   copy ..\disk1\_INST16.EX_ disks\disk1
	if Exist ..\disk1\_INST16.EX_   copy ..\disk1\_INST16.EX_ Internet
	if Exist ..\disk1\_INST32I.EX_  copy ..\disk1\_INST32I.EX_ disks\disk1
	if Exist ..\disk1\_INST32I.EX_  copy ..\disk1\_INST32I.EX_ Internet

	copy ..\disk1\disk1.id disks\disk1
	copy ..\disk1\disk1.id Internet
	copy ..\disk1\disk1.id disks\disk2\disk2.id
	copy ..\disk1\disk1.id disks\disk3\disk3.id

	if Exist disks\disk4	copy ..\disk1\disk1.id disks\disk4\disk4.id
	if Exist disks\disk5	copy ..\disk1\disk1.id disks\disk5\disk5.id

	copy ..\disk1\Setup.exe disks\disk1
	copy ..\disk1\Setup.exe Internet
	copy ..\setup\Setup.bmp disks\disk1
	copy ..\setup\Setup.bmp Internet

	cd ..

	goto end

:end
