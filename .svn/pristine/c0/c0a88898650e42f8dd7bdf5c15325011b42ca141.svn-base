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

REM  This batch file will launch the Simulator Manager Console.

REM ============================================================
REM ============================================================

echo Setting up environment...
call ..\Environment\JavaEnvironment.bat
call ..\Environment\CommonEnvironment.bat
call ..\Environment\SMCEnvironment.bat

set JVM_ARGS=%COMMON_JVM_ARGS% -ms256m -mx256m
set JAVA_ARGS=com.sydac.common.applicationmanager.ApplicationManager %APP_MANAGER_REGISTRY% %DATABASE_REGISTRY% %L10N_REGISTRY%  %UNITS_REGISTRY% %STV_REGISTRY% %ES_REGISTRY% %SMC_APP_REGISTRY% %SMC_REGISTRY%

REM ============================================================
REM The SMC has a special exit code of 99,
REM which represents a logoff action.
REM Since we can't switch users within the SMC,
REM we restart it here instead.
REM Any other exit code will not trigger a restart.
REM ============================================================

title SMC
echo Starting the SMC
:logon
echo %CLASSPATH%
echo java %JVM_ARGS% %JAVA_ARGS%
java %JVM_ARGS% %JAVA_ARGS%
if ERRORLEVEL 99 GOTO logon 

REM ============================================================
REM ============================================================

REM *** EOF
