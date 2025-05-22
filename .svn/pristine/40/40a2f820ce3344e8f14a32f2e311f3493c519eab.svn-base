@echo off

REM============================================================
REM============================================================
REM
REM   (C) Copyright 2022 Sydac Pty Ltd., all rights reserved.
REM   This is unpublished proprietary source code of Sydac.
REM   The copyright notice above does not evidence any actual
REM   or intended publication of such source code.
REM
REM============================================================
REM============================================================

REM  This batch file will execute the GCP Application Manager
REM  which will show the Central Panel Application.

REM============================================================
REM============================================================

echo Setting up environment...
call ..\Environment\JavaEnvironment.bat
echo Setting up common environment...
call ..\Environment\CommonEnvironment.bat
echo Setting up gmi environment...
call ..\Environment\GMIEnvironment.bat
echo Setting up gcp environment...
call ..\Environment\GCPDriverControlPanelEnvironment.bat

set JVM_ARGS=-ms256m -mx256m %COMMON_JVM_ARGS%
set JAVA_ARGS=%COMMON_JAVA_ARGS% %COMMON_GMI_ARGS% %GCP_ARGS% %HUB_REGISTRY% 

REM============================================================
REM============================================================

@title Driver Control Panel
echo Starting GCP Driver Control Panel
echo java %JVM_ARGS% %JAVA_ARGS%
echo CLASSPATH=%CLASSPATH%
java %JVM_ARGS% %JAVA_ARGS%

REM============================================================
REM============================================================

REM *** EOF
