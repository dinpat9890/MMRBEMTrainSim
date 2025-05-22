@echo off

setlocal ENABLEDELAYEDEXPANSION

tasklist /FI "IMAGENAME eq MATLAB.exe" | find "No tasks" > nul
if "%ERRORLEVEL%"=="0" GOTO check_lock

choice /M "A Matlab.exe process is already running, continue with build?"
IF NOT "%ERRORLEVEL%"=="1" GOTO end

:check_lock

::Check for a lock on the build zip file

SET ZIP_FILE=BEML_EMU.zip
SET SVN_EXE=svn.exe

where /Q %SVN_EXE%
IF NOT "%ERRORLEVEL%"=="0" (
  choice /T 10 /D Y /M "Unable to perform lock status check as %SVN_EXE% is not found on the path, continue with build?"
  IF NOT "!ERRORLEVEL!"=="1" GOTO end
  GOTO generate_code
)

FOR /F "tokens=* delims=" %%A IN ('%SVN_EXE% status --show-updates --verbose ^| findstr "%ZIP_FILE%"') do set ZIP_STATUS=%%A
rem echo ZIP_STATUS=%ZIP_STATUS%
IF "%ZIP_STATUS:~8,1%"=="*" (
  echo:
  choice /T 10 /D Y /M "%ZIP_FILE% appears to be out of date, continue with build?"
  IF NOT "!ERRORLEVEL!"=="1" GOTO end
) ELSE IF "%ZIP_STATUS:~5,1%"=="O" (
  echo:
  choice /T 10 /D Y /M "%ZIP_FILE% appears to be locked by someone else, or in another working copy, continue with build?"
  IF NOT "!ERRORLEVEL!"=="1" GOTO end
) ELSE IF NOT "%ZIP_STATUS:~5,1%"=="K" (
  echo:
  echo You don't have the lock on %ZIP_FILE% - consider cancelling and getting the lock if you are intending to check in this build
  timeout 5
) ELSE (
  echo You have the lock on %ZIP_FILE% - full steam ahead! Choo Choooooo!
)

:generate_code

:: Generate the model code

call ..\..\configure_ant.bat

:: Deploy the model code
call ant clean.all build.all 

:: Deploy constants
REM cd ..\..\Config
REM call ant deploy.model.constants

pause

:end