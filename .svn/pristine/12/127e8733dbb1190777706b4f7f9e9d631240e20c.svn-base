@echo off
title Radio Instructor Frontend

REM============================================================
REM============================================================
REM
REM   (C) Copyright 2017 Sydac Pty Ltd., all rights reserved.
REM   This is unpublished proprietary source code of Sydac.
REM   The copyright notice above does not evidence any actual
REM   or intended publication of such source code.
REM
REM============================================================
REM============================================================

REM  This batch file will execute the TMS

REM============================================================
REM============================================================

echo Setting up environment...
call ..\Environment\JavaEnvironment.bat
call ..\Environment\CommonEnvironment.bat
call ..\Environment\RadioFrontendEnvironment_Instructor.bat

set JVM_ARGS=%COMMON_JVM_ARGS% -ms128m -mx512m
set JAVA_ARGS=%COMMON_JAVA_ARGS% %HUB_REGISTRY% %RADIO_INSTRUCTOR_FE_REGISTRY% %RADIO_INSTRUCTOR_FE_HUB_REGISTRY% %RADIO_INSTRUCTOR_FE_APP_REGISTRY% %RADIO_INSTRUCTOR_FE_APP_SIM_REGISTRY% %HUB_REGISTRY%

REM============================================================
REM============================================================

@title Radio Instructor Frontend
echo %CLASSPATH%
echo java %JVM_ARGS% %JAVA_ARGS%
java %JVM_ARGS% %JAVA_ARGS%

REM============================================================
REM============================================================

REM *** EOF
