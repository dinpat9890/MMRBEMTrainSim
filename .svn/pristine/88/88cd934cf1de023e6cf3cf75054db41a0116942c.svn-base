echo off
call SetDatabaseProperties.bat
echo Using properties = %DATABASE%

set PATH=%~dp0..\cots\xerces\Bin\Win32;%PATH%

..\bin\xml2db -2 log.sql /i /c %DATABASE% /m ./population/db_mapping.xml /d ./population/data

mkdir logs
move /Y xml2db.log logs
type log.sql > logs/log.sql
del log.sql

pause;