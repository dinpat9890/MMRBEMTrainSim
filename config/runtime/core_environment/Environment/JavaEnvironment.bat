REM ============================================================
REM ============================================================
REM
REM   (C) Copyright 2012 Sydac Pty Ltd., all rights reserved.
REM   This is unpublished proprietary source code of Sydac.
REM   The copyright notice above does not evidence any actual
REM   or intended publication of such source code.
REM
REM ============================================================
REM ============================================================

REM ============================================================
REM ============================================================
REM
REM  This file is used to define the Java Runtime Environment
REM  that the Java Applications will be executed with.

REM ============================================================
REM ============================================================
REM
REM  The following section sets the System Path to include the java
REM  bin directory where the JVM is executed from.

REM This is the version we are looking for.
set JAVA_VER="1.8.0_51"

REM These are the target JDK/JRE versions we are looking for
set TARGET_JDK=jdk%JAVA_VER%
set TARGET_JRE=jre%JAVA_VER%

REM Ensure the 32 bit version is always used
set PROG_FILES=%ProgramFiles%
if exist "%ProgramFiles(x86)%" set PROG_FILES=%ProgramFiles(x86)%

REM Check for either a standalone JRE or one bundled with the JDK.
REM Prefer the JDK version as it has more debugging info built in.
set JAVA_INSTALLS=%PROG_FILES%\Java
set JDK=%JAVA_INSTALLS%\%TARGET_JDK%
set JRE=%JAVA_INSTALLS%\%TARGET_JRE%

for /D %%d in ("%JDK%" "%JRE%") do set JRE_PATH=%%d&& if exist %%d goto found

REM Could not find the JRE/JDK in any place where it was expected, so notify the user.
echo.
echo ERROR: Could not find installation of Java version %JAVA_VER%!
echo Program execution will be aborted.
echo.
echo Please ensure that you have installed this version of Java in the  %JAVA_INSTALLS%  directory.
echo The JRE must be used on rigs. Development machines may use the JDK.
echo Note that you must use the 32 bit version of Java.
echo.

REM Make sure the user sees the error message, then prevent the program from launching.
REM If we allow the program to launch, it will attempt to use whatever version of Java
REM happens to be on the path, which is highly undesirable.
pause
exit

:found
set PATH=%JRE_PATH%\bin;%PATH%

for /f "tokens=3" %%g in ('java -version 2^>^&1 ^| findstr /i "version"') do (
    set JAVA_FOUND=%%g
)

if "%JAVA_FOUND%" == "%JAVA_VER%" goto setPathDone

echo WARNING: Found java version %JAVA_FOUND%, expecting version %JAVA_VER%

:setPathDone

REM ============================================================
REM ============================================================

REM *** EOF
