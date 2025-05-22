@echo off
title DMIBackend

REM============================================================
REM============================================================
REM
REM   (C) Copyright 2018 Sydac Pty Ltd., all rights reserved.
REM   This is unpublished proprietary source code of Sydac.
REM   The copyright notice above does not evidence any actual
REM   or intended publication of such source code.
REM
REM============================================================
REM============================================================

REM  This batch file will execute the DMI Backend

REM============================================================
REM============================================================

echo Setting up environment...
call ..\Environment\JavaEnvironment.bat
call ..\Environment\CommonEnvironment.bat
call ..\Environment\DMIBackendEnvironment.bat

set JVM_ARGS=%COMMON_JVM_ARGS% -ms128m -mx512m
set JAVA_ARGS=%COMMON_JAVA_ARGS% %HUB_REGISTRY% %DMI_BE_APP_REGISTRY% %DMI_BE_APP_SIM_REGISTRY% %DMI_USER_CREDENTIALS_INI% %DMI_PROPERTIES_REGISTRY% %DMI_HUB_REGISTRY% %DMI_TEXT_MESSAGE_REGISTRY%

REM============================================================
REM============================================================

@title DMI Backend
echo %CLASSPATH%
echo java %JVM_ARGS% %JAVA_ARGS%
java %JVM_ARGS% %JAVA_ARGS%

REM============================================================
REM============================================================

REM *** EOF
