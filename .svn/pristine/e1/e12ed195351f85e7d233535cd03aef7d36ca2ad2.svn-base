@rem Grab the latest file only, and rename to include the computer name
SET SRCDIR=\\%1\c$\PerfLogs
@FOR /F "delims=" %%I IN ('DIR %SRCDIR%\*.* /B /O:-D') DO copy "%SRCDIR%\%%I" "%LOG_DEST_DIR%\\%1_%%I" & GOTO :END
:END
