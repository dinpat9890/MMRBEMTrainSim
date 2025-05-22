@echo off

if not exist "C:\Program Files (x86)\Microsoft Visual Studio\InstallerRenamed" (
    call %~dp0vs_copy_installer.bat
)

echo Stopping any vs_instalershell.exe s
taskkill /fi "imagename eq vs_installershell.exe"

if exist %~dp0.vsconfig (
    del /q %~dp0.vsconfig
)

start /b "Visual Studio Installer" "C:\Program Files (x86)\Microsoft Visual Studio\InstallerRenamed\vs_installershell.exe" --channelId "VisualStudio.15.Release" --productId "Microsoft.VisualStudio.Product.Professional" export --quiet --config %~dp0.vsconfig

:loop
    if exist %~dp0.vsconfig (
        echo Stopping any vs_installershell.exe s after generating the .vsconfig
        taskkill /fi "imagename eq vs_installershell.exe" /f
        goto end
    )

    timeout /t 1 > nul
    goto loop

:end

