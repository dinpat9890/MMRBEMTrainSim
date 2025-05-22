@echo off

rem if we have already defined this environment, we can avoid adding this stuff to the path again
if defined BUILD_ENV_SET (
  @echo build environment already set for this terminal instance
  @goto end
)

call %~dp0/configure_ant.bat

pushd .

rem We are going to assume the installation location of VS2017 for now, since we don't
REM automatically get an environment variable that points to it
if not exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat" (
    echo Can't find an installation of VS 2017!
    goto end
)

goto end_vs_versions_check
if not defined no_vs_versions_check ( goto begin_vs_versions_check  )
if %no_vs_versions_check%==1        ( goto end_vs_versions_check    )

:begin_vs_versions_check
goto end_vs_versions_check 

REM populate the version of the visual studio and it's components.

call %~dp0vs_versions.bat

REM Compare the Visual Studio version and update if required

set vswhere_exe="C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe"

set /a vs_newer=1
for /f "tokens=1-4 delims=." %%m in (%vs_min_version%) do ( 
    for /f "tokens=2-5 delims=. " %%v in ('%vswhere_exe% ^| findstr installationVersion') do ( 
        if %%v lss %%m ( set /a vs_newer=0 )
        if %vs_newer% equ 1 if %%w lss %%n ( set /a vs_newer=0 )
        if %vs_newer% equ 1 if %%x lss %%o ( set /a vs_newer=0 )
        if %vs_newer% equ 1 if %%y lss %%p ( set /a vs_newer=0 )
    )
)

if %vs_newer% neq 1 (
    echo Visual Studio version %vs_min_version% is required. Please update Visual Studio to build the project ^(vs_update.bat^).
    goto end
)

REM Export the visual studio config so that we can check whether we have required modules installed

if not exist %~dp0.vsconfig (
    call %~dp0vs_config.bat > nul
)

REM Make sure the required toolchain is installed

set vc_toolchain_line_number=0
for /f "tokens=1 delims=:" %%n in ('findstr /n "microsoft.visualstudio.component.vc.%vs_vc_toolchain%" %~dp0.vsconfig') do (
    set /a vc_toolchain_line_number=%%n
)

if %vc_toolchain_line_number% equ 0 (
    echo Visual Studio toolchain version %vs_vc_toolchain% required. Please update Visual Studio to build the project ^(vs_update.bat^).
    goto end
)

REM Make sure the required windows sdk is installed

set win_sdk_line_number=0
for /f "tokens=1 delims=:" %%n in ('findstr /n "microsoft.visualstudio.component.%vs_win_sdk%" %~dp0.vsconfig') do (
    set /a win_sdk_line_number=%%n
)

if %win_sdk_line_number% equ 0 (
    echo Windows SDK version %vs_win_sdk% required. Please update Visual Studio to build the project ^(vs_update.bat^).
    goto end
)

:end_vs_versions_check

@rem devenv.com is in a location like C:\Windows\Microsoft.NET\Framework\v4.0.30319
@rem So using the standard bat file
@call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat"

popd

set PROGx86=%ProgramFiles(x86)%
if "%PROGx86%" == "" set PROGx86=%ProgramFiles%
if "%PROGx86%" == "" (
    echo Can't find either "Program Files" or "Program Files (x86)" directory.
    goto end
)

set HHCDIR=%PROGx86%\HTML Help Workshop
set DOXYGENDIR=%COTS_DIR%\doxygen

@if "%VS110COMNTOOLS%"=="" (
    echo ERROR: VS110COMNTOOLSDIR not found in environment
    goto end
)
if not exist "%HHCDIR%\hhc.exe"        (
    echo ERROR: hhc.exe not found in "%HHCDIR%"
    goto end
)
if not exist "%DOXYGENDIR%\doxygen.exe"    (
    echo ERROR: doxygen.exe not found in "%DOXYGENDIR%"
    goto end
)

set PATH=%DEVENV%;%VCBUILD%;%HHCDIR%;%DOXYGENDIR%;%PATH%
echo Set up MSBuild and the following items have been prepended to PATH
@echo   DEVENV
@echo   VCBUILD
@echo   %HHCDIR%
@echo   %DOXYGENDIR%

set BUILD_ENV_SET=1

@rem This should be used, but this makes it optional
@if not exist "%~dp0release.xml" goto end
echo Setting user.properties for build information
ant -f "%~dp0release.xml" buildconfigure

:end
