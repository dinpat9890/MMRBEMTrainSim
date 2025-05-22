@echo off
rem add xerces-c_3_1.dll to the path
set PATH=%PATH%;%~dp0..\COTS\xerces\x86
rem add dll to path
set PATH=%PATH%;%~dp0..\Bin

call ..\Environment\SetPath_Xerces.bat
call ..\Environment\SetPath_PYTHON.bat
call ..\Environment\SetPath_OCI.bat
call ..\Environment\SetPath_TNS.bat

cd ..\Data
..\Bin\StudentMarkerSystemReplyPlus.exe ..\Environment\StudentMarkerSystemReplyPlus.ini
