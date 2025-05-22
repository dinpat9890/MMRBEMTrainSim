echo off
call SetDatabaseProperties.bat
echo Using properties = %DATABASE%

set PATH=%~dp0..\cots\xerces\Bin\Win32;%PATH%

..\bin\import_export_scenario --db-mapping .\population\db_mapping.xml loadall .\population\scenarios %DATABASE% 

mkdir logs
move /Y ImportExportScenario.log logs
move /Y ImportExportScenario_xml2db.log logs

pause;

