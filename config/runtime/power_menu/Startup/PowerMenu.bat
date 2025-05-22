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

REM  This batch file will launch the Power Menu.

REM ============================================================
REM ============================================================

echo Setting up environment...
call ..\Environment\JavaEnvironment.bat
call ..\Environment\CommonEnvironment.bat
call ..\Environment\PowerMenuEnvironment.bat

set JVM_ARGS=%COMMON_JVM_ARGS% -mx64m
set JAVA_ARGS=com.sydac.common.applicationmanager.ApplicationManager %DATABASE_REGISTRY% %APP_MANAGER_REGISTRY% %L10N_REGISTRY%
set JAVA_ARGS=%JAVA_ARGS% %POWER_MENU_APP_REGISTRY% %POWER_MENU_SIM_REGISTRY% %POWER_MENU_APP_SIM_REGISTRY%

REM ============================================================
REM ============================================================

title Power Menu
echo Starting the Power Menu Application Manager
java %JVM_ARGS% %JAVA_ARGS%

REM ============================================================
REM ============================================================

REM *** EOF
