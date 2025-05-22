echo off
call SetDatabaseProperties.bat
echo Using properties = %DATABASE%

set PATH=%~dp0..\cots\xerces\Bin\Win32;%PATH%

..\bin\import_export_features.exe -iao ./population/features %DATABASE%

mkdir logs
move /Y ImportExportFeatures.log logs

pause;

