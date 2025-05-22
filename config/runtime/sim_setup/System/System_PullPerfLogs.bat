SET PATH=%~dp0..\COTS\vc_redist\x86\crt;%PATH%
rem Although relog can work across the network, the IO Read Bytes are tremendous and the files are quick to copy

set LOG_DEST_DIR=PerfLogs
set DEST_DIR=%LOG_DEST_DIR%

mkdir %DEST_DIR%
erase %DEST_DIR%\\*.* /q

call bin\simsetup.bat /m /call "Scripts\Pull_PerfLogs.bat"
pause
