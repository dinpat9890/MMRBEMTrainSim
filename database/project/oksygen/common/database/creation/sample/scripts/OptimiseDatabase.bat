echo off
call SetDatabaseProperties.bat
echo Using properties; User: %USER%, Database: %DATABASE_NAME%, At %SERVER_HOST% : %SERVER_PORT%

set CREATION_SCRIPT=./build/common/database/creation/optimize.ps1

powershell.exe  -executionpolicy remotesigned ^
                -File %CREATION_SCRIPT% ^
                -server_host %SERVER_HOST% ^
                -server_http_port %SERVER_HTTP_PORT% ^
                -basex_user %USER% ^
                -database_name %DATABASE_NAME%

pause;