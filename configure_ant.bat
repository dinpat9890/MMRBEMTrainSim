@echo off

@rem if we have already defined this environment, we can avoid adding this stuff to the path again
if defined IVY_ENV_SET (
  @echo ivy environment already set for this terminal instance
  @goto end
)

rem Change this if you need to
set JAVAVER=jdk1.8.0_51

set BC_DIR=%~dp0
set COTS_DIR=

if exist "%BC_DIR%COTS"    set COTS_DIR=%BC_DIR%COTS

if "%COTS_DIR%" == "" (
    echo Can't find "COTS" directory.
    goto end
)

set PROGx86=%ProgramFiles(x86)%
if "%PROGx86%" == "" set PROGx86=%ProgramFiles%
if "%PROGx86%" == "" (
    echo Can't find either "Program Files" or "Program Files (x86)" directory.
    goto end
)

set JAVADIR=%PROGx86%\Java\%JAVAVER%
set ANTDIR=%COTS_DIR%\apache-ant

if not exist "%JAVADIR%\bin\javac.exe" (
    echo ERROR: javac.exe not found in "%JAVADIR%\bin"
    goto end
)
if not exist "%ANTDIR%\bin\ant.bat"    (
    echo ERROR: ant.bat not found in "%ANTDIR%\bin"
    goto end
)

@rem Allow this file to quickly configure JAVA_HOME for AutoTest
@if "%1"=="JAVA_HOME" goto set_java_home

set ANT_HOME=%ANTDIR%
set ANT_OPTS=-Xmx512m
echo ANT_HOME set to %ANT_HOME%
echo ANT_OPTS set to %ANT_OPTS%
echo.

:set_java_home
set JAVA_HOME=%JAVADIR%
@set JRE_HOME=%JAVA_HOME%\jre
echo JAVA_HOME set to %JAVA_HOME%
echo.

@if "%1"=="JAVA_HOME" goto end

set PATH=%DEVENV%;%JAVA_HOME%\bin;%COTS_DIR%\site\bin;%ANT_HOME%\bin;%COTS_DIR%\7-zip\bin;%PATH%
set ANT_ARGS=-lib "%COTS_DIR%\site\plugins;%COTS_DIR%\jython;%COTS_DIR%\apache-ivy;%COTS_DIR%\apache-ivy\lib;%COTS_DIR%\ant-contrib"
echo Set up java ant args and the following items have been prepended to PATH
echo   %JAVA_HOME%\bin
echo   %COTS_DIR%\site\bin
echo   %ANT_HOME%\bin

@rem This is where Jython will look for .py files:
set JYTHONPATH=%~dp0;%JYTHONPATH%

set IVY_ENV_SET=1

@rem This should be used, but this makes it optional
@if not exist "%~dp0release.xml" goto end
echo Setting user.properties for build information
ant -f "%~dp0release.xml" buildconfigure

:end
