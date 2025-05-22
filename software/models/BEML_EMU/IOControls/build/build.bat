@echo off
echo.
echo Generating IO Controls Model ...

:: Locate the correct version of matlab

for /f "delims=" %%i IN ('where matlab ^| find "2019b" ^| find "matlab.exe"') DO SET MATLAB_PATH=%%i
echo using matlab.exe @ %MATLAB_PATH%

:: Execute the build script

echo Generating C++ code for MatlabTrain ...
"%MATLAB_PATH%" /wait -r build(true)
echo Finished generating IO Controls Model.
echo.

