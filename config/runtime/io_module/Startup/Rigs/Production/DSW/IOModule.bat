call ..\Environment\SetPath_TNS.bat
call ..\Environment\SetPath_PYTHON.bat
call ..\Environment\SetPath_Xerces.bat
call ..\Environment\SetPath_MSVCRT.bat
call ..\Environment\SetPath_OCI.bat
set PATH=%~dp0..\COTS\wago\bin;%PATH%
cd ..\Data
..\bin\io_module.exe ..\Environment\IOModule.ini