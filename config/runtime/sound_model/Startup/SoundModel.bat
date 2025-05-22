@echo off
setlocal
set PATH=
cd ..\data

call ..\Environment\SetPath_TNS.bat
call ..\Environment\SetPath_Xerces.bat
call ..\Environment\SetPath_MSVCRT.bat
call ..\Environment\SetPath_OCI.bat
call ..\Environment\SetPath_Python.bat

echo PATH is %PATH%
echo.

..\Bin\plugin_module.exe ..\Environment\SoundModel.ini

endlocal
