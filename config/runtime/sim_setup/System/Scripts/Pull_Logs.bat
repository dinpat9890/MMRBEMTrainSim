rem This collapses the directory structure and does not grab old logs
set LOG_DEST_DIR=Logs_%CURRENT_DATE: =%_%CURRENT_TIME: =%
set DEST_DIR=%LOG_DEST_DIR%\\%1
set GET_OLD=%LOG_DEST_DIR%\\%1

mkdir %LOG_DEST_DIR%
mkdir %DEST_DIR%
erase %DEST_DIR%\\*.* /q
robocopy %INSTALL_PATH%\\Environment %DEST_DIR% %LOG_FLAGS%
robocopy %INSTALL_PATH%\\Logs %DEST_DIR% %LOG_FLAGS%

rem Also pulls network and host settings in case these are causing grief
copy \\%1\c$\XEClient\network\admin\tnsnames.ora %DEST_DIR%\tnsnames.ora /y
copy \\%1\c$\windows\system32\drivers\etc\hosts %DEST_DIR%\hosts /y
