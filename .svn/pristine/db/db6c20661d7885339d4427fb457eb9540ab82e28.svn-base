@ECHO OFF

SET COTS_FOLDER=..\..\..\..\..\software\cots
SET EXE_FOLDER=..\..\..\..\..\software\tools\bin\

set PATH=%PATH%;%COTS_FOLDER%\xerces\Bin\Win32;%COTS_FOLDER%\python\bin

REM NB! The Spreadsheet must be supplied with a FULL path for this to work.

REM options are:
REM -s=Full Spreadsheet Filename -o=Output XML filename
REM or
REM -sl=textfilename with list of Spreadsheet paths to process -o=Output XML filename

REM Single Spreadsheet RunString
REM .\bin\ControlTableEncoder.exe  -s=F:\KBData\SvnRepository\FGWIEPTrainSim\Software\ControlTableEncoder\ControlTable.xlsm  -o=ControlTable.xml

REM del /Q ControlTableEncoder.log

set ControlTableLogFile="ControlTableEncoder_ENCODE_%DATE:~4,2%-%DATE:~7,2%-%DATE:~10,4% %TIME:~0,2%.%TIME:~3,2%.%TIME:~6,2%.log"

REM Multiple Spreadsheets - Listed in text file in order - RunString
call %EXE_FOLDER%\ControlTableEncoder.exe  -sl=ControlTables\Input\ControlTableList.txt -o=ControlTables\Output\MMRBEM-ControlTable.xml -log_detail

rem copy /Y ControlTableEncoder.log %ControlTableLogFile%
rem del /Q ControlTableEncoder.log

pause