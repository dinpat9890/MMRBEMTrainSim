@echo off

setlocal ENABLEDELAYEDEXPANSION

call %~dp0vs_copy_installer.bat
call %~dp0vs_versions.bat

REM Compare the Visual Studio version numbers and update if required

set vswhere_exe="C:\Program Files (x86)\Microsoft Visual Studio\InstallerRenamed\vswhere.exe"
set vs_installer_cmd="C:\Program Files (x86)\Microsoft Visual Studio\InstallerRenamed\vs_installer.exe" --channelId "VisualStudio.15.Release" --productId "Microsoft.VisualStudio.Product.Professional"

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
    echo Updating Visual Studio to version %vs_min_version%...
	%vs_installer_cmd% update --passive
)

REM Export the visual studio config so that we can check whether we have required modules installed

call %~dp0vs_config.bat > nul

REM Make sure the required toolchain is installed

set vc_toolchain_line_number=0
for /f "tokens=1 delims=:" %%n in ('findstr /n "microsoft.visualstudio.component.vc.%vs_vc_toolchain%" %~dp0.vsconfig') do (
    set /a vc_toolchain_line_number=%%n
)

if %vc_toolchain_line_number% equ 0 (
    echo Updating Visual Studio toolchain to version %vs_vc_toolchain%...
    %vs_installer_cmd% install --passive --add "microsoft.visualstudio.component.vc.%vs_vc_toolchain%"
)

REM Make sure the required windows sdk is installed

set win_sdk_line_number=0
for /f "tokens=1 delims=:" %%n in ('findstr /n "microsoft.visualstudio.component.%vs_win_sdk%" %~dp0.vsconfig') do (
    set /a win_sdk_line_number=%%n
)

if %win_sdk_line_number% equ 0 (
    echo Updating Windows SDK to version %vs_win_sdk%...
    %vs_installer_cmd% install --passive --add "microsoft.visualstudio.component.%vs_win_sdk%"
)

REM reload the .vsconfig after the modifications

call %~dp0vs_config.bat > nul

endlocal

