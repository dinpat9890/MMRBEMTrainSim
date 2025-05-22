@echo off
setlocal
set PATH=
cd ..\Data
call ..\Environment\SetPath_TNS.bat
call ..\Environment\SetPath_Xerces.bat
call ..\Environment\SetPath_MSVCRT.bat
call ..\Environment\SetPath_OCI.bat
echo PATH is %PATH%
echo.
..\Bin\MotionBase.exe ..\Environment\MotionBaseController.ini
endlocal