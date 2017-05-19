@echo off
echo ********************************************
echo * Stripping 32-bit code from Pueblo.rtf... *
echo ********************************************

sed -f HlpStrip.sed < pueblo.rtf > pueblo16.rtf

echo ********************************************
echo * Okay, now running 'hc31 pueblo16.hpj' to *
echo * build the 16-bit version of Pueblo.      *
echo ********************************************
hc31 pueblo16.hpj
echo .
echo ********************************************
echo * Finished                                 *
echo ********************************************
rename pueblo16.hlp Pueblo16.hlp
