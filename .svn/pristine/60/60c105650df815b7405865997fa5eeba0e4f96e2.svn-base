@echo off

SET DATETIME=%DATE:~10,4%%DATE:~7,2%%DATE:~4,2%_%TIME:~0,2%%TIME:~3,2%%TIME:~6,2%
SET DATETIME=%DATETIME: =0%

:: Locate the correct version of matlab

for /f "delims=" %%i IN ('where matlab.exe ^| find "2019b"') DO SET MATLAB_PATH=%%i
echo using matlab.exe @ %MATLAB_PATH%

:: Execute the build script

echo Generating C++ code for MatlabTrain ...
"%MATLAB_PATH%" /wait -r build(true) -logfile build_%DATETIME%.log -nosplash
echo Finished generating C++ code for MatlabTrain.
