sET PATH=%~dp0..\COTS\vc_redist\x86\crt;%PATH%
SET CURRENT_DATE=%date:~10,4%-%date:~7,2%-%date:~4,2%
SET CURRENT_TIME=%time:~0,2%-%time:~3,2%

rem Don't get old logs
SET LOG_FLAGS=/if *.log /xf *old*

rem Use this switch to get all logs, not just old
rem SET LOG_FLAGS=/if *.log*

call bin\simsetup.bat /m /call "Scripts\Pull_Logs.bat"
pause
