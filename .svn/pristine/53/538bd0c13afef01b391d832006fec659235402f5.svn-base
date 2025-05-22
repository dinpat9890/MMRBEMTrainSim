@echo off
setlocal
set PATH=
cd ..\Data
call ..\Environment\SetPath_TNS.bat
call ..\Environment\SetPath_Xerces.bat
call ..\Environment\SetPath_MSVCRT.bat
call ..\Environment\SetPath_OCI.bat
call ..\Environment\SetPath_VADAAR.bat
echo PATH is %PATH%
echo.
..\Bin\student_monitoring.exe ..\Environment\StudentMonitoring_OBS.ini
endlocal