REM Build the solution, update the database and deploy

REM The BaseX server must be launched
REM Svn must be updated
REM Customized CreateAndPopulateDatabase.bat is used if it exists in the trunk directory
REM Customized SetDatabaseProperties.bat is used if it exists in the trunk directory


REM Save current directory
set cur_dir=%~dp0

REM Save start time
time /T > %cur_dir%UpdateAllTimer.log
set STARTTIME=%TIME%

REM Setup
REM call setup.bat NoPause

REM Remove the old install directory
del /F /S /Q %cur_dir%install\*

REM Remove the old deploy directory
del /F /S /Q %cur_dir%deploy\*

REM Call ant prepare.all build.all generate.world_types install.all
Call ant_all.bat
IF %ERRORLEVEL% NEQ 0 GOTO eof

REM Save end time
time /T >> %cur_dir%UpdateAllTimer.log
set ENDTIME=%TIME%

echo   STARTTIME: %STARTTIME%
echo   ENDTIME:   %ENDTIME%

:eof

@if not defined ENDTIME set ENDTIME=%TIME%
echo Total time (except CreateAndPopulate):
echo   STARTTIME: %STARTTIME%
echo   ENDTIME:   %ENDTIME%



pause

exit
