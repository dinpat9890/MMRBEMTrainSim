@echo off
setlocal
set PATH=
cd ..\Data
call ..\Environment\SetPath_TNS.bat
call ..\Environment\SetPath_PYTHON.bat
call ..\Environment\SetPath_Xerces.bat
call ..\Environment\SetPath_MSVCRT.bat
call ..\Environment\SetPath_OCI.bat
call ..\Environment\SetPath_OLEDB.bat
echo PATH is %PATH%
echo.
..\Bin\session_analyser.exe ..\Environment\SessionAnalyser.ini
endlocal