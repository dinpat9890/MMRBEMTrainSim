@echo off

REM Run the script with administrator rights
if not "%1"=="am_admin" (
    powershell start -verb runas '%0' am_admin
    goto wait_for_installer_copy_completion
)

if exist "C:\Program Files (x86)\Microsoft Visual Studio\InstallerRenamed" (
    echo Deleting the older installer...
    del /f /q /s "C:\Program Files (x86)\Microsoft Visual Studio\InstallerRenamed"
)

echo Copying the installer...
xcopy /O /X /E /H /K "C:\Program Files (x86)\Microsoft Visual Studio\Installer" "C:\Program Files (x86)\Microsoft Visual Studio\InstallerRenamed\"

REM Mark the end of the elevated process
type nul > %~dp0installer_copy_completed
exit /b

:wait_for_installer_copy_completion
    if exist %~dp0installer_copy_completed (
        del %~dp0installer_copy_completed
        goto end
    )

    timeout /t 1 /nobreak > nul
    goto wait_for_installer_copy_completion

:end
