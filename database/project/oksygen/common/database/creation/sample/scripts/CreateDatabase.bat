echo off
call SetDatabaseProperties.bat
echo Using properties = %DATABASE%

cd build/common/database/creation

call BuildUserspace.bat

mkdir logs
move /Y *.lst logs
