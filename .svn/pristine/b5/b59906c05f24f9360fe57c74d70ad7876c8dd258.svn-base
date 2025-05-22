set PATH=%~dp0..\..\COTS\xerces\x86;%PATH%
set DBCONFIG=%1
set CONTENT=..\..\Content
set TRACK=%CONTENT%\Track
set TOOLS=..\..\Built\Tools\Deploy
set BUILDCONFIG=..\BuildConfig

@echo Inserting Configuration

if exist %BUILDCONFIG% rmdir %BUILDCONFIG%
mkdir %BUILDCONFIG%
xcopy /y ..\Simulator\*.* %BUILDCONFIG%
xcopy /y ..\..\Sample\Config\Simulator\*.* %BUILDCONFIG%
xcopy /y ..\..\Sample\Config\Train\*.* %BUILDCONFIG%
%TOOLS%\xml2db -2 log.sql /i /c %DBCONFIG% /m ..\Database\db_mapping.xml /d %BUILDCONFIG%

@echo Importing Features

%TOOLS%\ImportExportFeatures.exe -iao %CONTENT%\Features %DBCONFIG%

@echo Importing Track

%TOOLS%\ImportTrack.exe -s %TRACK%\FastTrack_skins.xml %TRACK%\FastTrack.xml %TRACK% %DBCONFIG% -t "FastTrack"
%TOOLS%\ImportTrack.exe -s %TRACK%\Dense_skins.xml %TRACK%\Dense.xml %TRACK% %DBCONFIG%
%TOOLS%\ImportTrack.exe -s %TRACK%\Complex_skins.xml %TRACK%\Complex.xml %TRACK% %DBCONFIG%

@echo Importing Scenarios

%TOOLS%\ImportExportScenario.exe loadall %CONTENT%\Scenarios %DBCONFIG%
