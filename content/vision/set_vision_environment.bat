@echo off
set COTS_ROOT=%~dp0..\..\software\cots
set DEPENDENCIES_COTS_ROOT=%~dp0..\dependencies\cots\oksygen\cots
set CORE_UNIGINE_PLUGINS_ROOT=%~dp0..\dependencies\software\oksygen\sim\core\unigine_plugins
set TOOLS_ROOT=%~dp0..\..\Tools
set XERCES_PATH=%DEPENDENCIES_COTS_ROOT%\xerces
set OCI_PATH=%DEPENDENCIES_COTS_ROOT%\oci
set UNIGINE_SDK_PATH=%DEPENDENCIES_COTS_ROOT%\unigine
set UNIGINE_SDK_DATA_PATH=%UNIGINE_SDK_PATH%\data

REM FIXME: For now just point the user in the direction of the retrieve all
REM        batch file when dependencies are missing. In the future we should
REM        probably pull our dependencies into a local folder.
REM See https:\\support.microsoft.com\en-hk\help\65994\testing-if-a-drive-or-directory-exists-from-a-batch-file
REM for an explanation of the NUL thing below...
if not exist %DEPENDENCIES_COTS_ROOT%\NUL (
  echo ERROR! Failed to find %DEPENDENCIES_COTS_ROOT%.
  echo        Try running ..\..\retrieveall.bat to retrieve dependencies.
  echo.
)

set PATH=%~dp0\bin;%UNIGINE_SDK_PATH%\Bin;%XERCES_PATH%\Bin\x64;%OCI_PATH%\x64\bin;%PATH%
echo PATH has been set to %PATH%
