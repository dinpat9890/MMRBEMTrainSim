@echo off

REM ============================================================
REM ============================================================
REM
REM   (C) Copyright 2000 Sydac Pty Ltd., all rights reserved.
REM   This is unpublished proprietary source code of Sydac.
REM   The copyright notice above does not evidence any actual
REM   or intended publication of such source code.
REM
REM ============================================================
REM ============================================================

REM  This batch file will launch the Procedural Trainer.

REM ============================================================
REM ============================================================

echo Setting up environment...
call ..\Environment\JavaEnvironment.bat
echo Setting up common environment...
call ..\Environment\CommonEnvironment.bat
echo Setting up gmi environment...
call ..\Environment\GMIEnvironment.bat
echo Setting up pt environment...
call ..\Environment\PTEnvironment_Instructor.bat

set JVM_ARGS=-ms256m -mx256m %COMMON_JVM_ARGS%
set JAVA_ARGS=%COMMON_JAVA_ARGS% %COMMON_GMI_ARGS% %PT_ARGS%

REM ============================================================
REM ============================================================

title Instructor PT
echo Starting the Instructor PT
echo java %JVM_ARGS% %JAVA_ARGS%
echo CLASSPATH=%CLASSPATH%
java %JVM_ARGS% %JAVA_ARGS%

REM ============================================================
REM ============================================================

REM *** EOF
