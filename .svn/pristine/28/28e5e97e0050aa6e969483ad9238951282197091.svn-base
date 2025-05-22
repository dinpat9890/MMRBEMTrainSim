rem This is a demo file of using relog to merge the recorded logs

SET START_TIME=2/9/2012 14:38:48
SET END_TIME=2/9/2012 14:38:50

rem Although relog can work across the network, the IO Read Bytes are tremendous and the files are quick to copy

rem If trimming is needed as the file is large, relog will take a long time. It is probably best in this situation to
rem cull each file using the flags below, rather than doing this on the output, and then merge them
rem There is a -a flag, but that requires the file to already exist
rem -b %START_TIME% -e %END_TIME%

@SETLOCAL ENABLEDELAYEDEXPANSION
@set ALL_FILES=
@for /f %%a IN ('dir PerfLogs /b') do set ALL_FILES=!ALL_FILES! "PerfLogs\%%a"
relog %ALL_FILES% -o AllComputers.blg

pause
