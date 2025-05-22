call SetDatabaseProperties.bat
set TNS_ADMIN=%~dp0
ECHO Using DATABASE = %DATABASE%

set PATH=%~dp0..\cots\xerces\Bin\Win32;%~dp0..\cots\oci\Win32\bin;

mkdir Export
..\bin\import_export_scenario.exe /S saveall .\Export %DATABASE%

mkdir logs
move /Y ImportExportScenario.log logs
move /Y ImportExportScenario_xml2db.log logs

pause
