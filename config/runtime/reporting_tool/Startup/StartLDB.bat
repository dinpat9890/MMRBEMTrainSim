REM Ensure the 32 bit version is always used
set PROG_FILES=%ProgramFiles%
if exist "%ProgramFiles(x86)%" set PROG_FILES=%ProgramFiles(x86)%

REM Find a version of office
set OFFICE=%PROG_FILES%\Microsoft Office\Office14\MSACCESS.EXE
set OFFICE16=C:\Program Files\Microsoft Office\Office16\MSACCESS.EXE
set OFFICE16ROOT=C:\Program Files\Microsoft Office\root\Office16\MSACCESS.EXE

for /D %%d in ("%OFFICE16%" "%OFFICE%" "%OFFICE16ROOT%","MSACCESS.EXE") do set ACCESS_PATH=%%d&& if exist %%d goto found

:found
%ACCESS_PATH% %~dp3\DR%1_%2.ldr
