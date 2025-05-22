call SetDatabaseProperties.bat
set TNS_ADMIN=%~dp0
ECHO Using DATABASE = %DATABASE%

set PATH=%~dp0..\cots\xerces\Bin\Win32;%~dp0..\cots\oci\Win32\bin;

if exist ..\Temp (
	del ..\Temp\*.xml	
  ) else (
	mkdir ..\Temp
  )
)

REM export_db_mapping is a merged mapping of all files except for the db_mapping_esm.xml file.  
REM This is because xml2db gets a memory issue if it tries to export esm data.

..\bin\xml2db /e  /c %DATABASE% /m population/db_mapping.xml /d ../Temp