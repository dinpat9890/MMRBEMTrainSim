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

REM  This batch file will launch the Simulator Controller Console.

REM ============================================================
REM ============================================================

echo Setting up environment...
call ..\Environment\JavaEnvironment.bat
call ..\Environment\CommonEnvironment.bat
call ..\Environment\SCCEnvironment.bat

set JVM_ARGS=%COMMON_JVM_ARGS% -ms128m -mx256m
set JAVA_ARGS=%COMMON_JAVA_ARGS% %STV_REGISTRY% %ES_REGISTRY% %SCC_APP_REGISTRY% %SCC_APP_SIM_REGISTRY% %SCC_REGISTRY% %SCC_SIM_REGISTRY% %SYSTEM_SIMULATORS_REGISTRY%

REM ============================================================
REM ============================================================

title SCC
echo Starting the SCC
java %JVM_ARGS% %JAVA_ARGS%

REM ============================================================
REM ============================================================

REM *** EOF
