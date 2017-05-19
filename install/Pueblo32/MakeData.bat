%1icomp data\*.* data.z -i
%1icomp program\cvs\*.* data.z -r

copy data.z Internet\data.1

%1split data.z -F1370 -d1@550

copy data.1 disks\disk1
copy data.2 disks\disk2
copy data.3 disks\disk3
if Exist data.4 copy data.4 disks\disk4
if Exist data.5 copy data.5 disks\disk5

%1icomp SetupLib\*.* _setup.lib
copy _setup.lib disks\disk1
copy _setup.lib Internet
