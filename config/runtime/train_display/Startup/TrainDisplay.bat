set PATH=%~dp0..\Bin;%PATH%
call ..\Environment\SetPath_Xerces.bat
call ..\Environment\SetPath_PYTHON.bat
call ..\Environment\SetPath_OCI.bat
call ..\Environment\SetPath_TNS.bat
call ..\Environment\SetPath_MSVCRT.bat
cd ..\Data
start ..\Bin\train_display.exe ..\Environment\TrainDisplay.ini
