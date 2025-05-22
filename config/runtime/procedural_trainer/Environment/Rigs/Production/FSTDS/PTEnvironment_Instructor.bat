REM ============================================================
REM ============================================================
REM
REM   (C) Copyright 2006 Sydac Pty Ltd., all rights reserved.
REM   This is unpublished proprietary source code of Sydac.
REM   The copyright notice above does not evidence any actual
REM   or intended publication of such source code.
REM
REM ============================================================
REM ============================================================


REM ============================================================
REM ============================================================
REM
REM  This file is used to define PT specific environment variables

REM ============================================================
REM ============================================================
REM
REM  The following section specifies where the Java Archive files
REM  are located.

set PT_JAR=%DEPLOY_LIB%\proctrainer.jar

REM ============================================================
REM ============================================================
REM
REM  The following section sets the Java Class Path to include the
REM  classes contained within the deployed JAR files.

set CLASSPATH=%PT_JAR%;%CLASSPATH%

REM ============================================================
REM ============================================================
REM
REM  The following section sets the application manager registry files

set PT_INSTRUCTOR_APP_REGISTRY=%DEPLOY_ENV%\PTApplicationManager_Instructor.properties
set PT_INSTRUCTOR_APP_SIM_REGISTRY=%DEPLOY_ENV%\PTApplicationManagerSim_Instructor.properties
set PT_INSTRUCTOR_HUB_REGISTRY=%DEPLOY_ENV%\PTHub_Instructor.properties
set PT_REGISTRY=%DEPLOY_ENV%\PT.properties

set PT_ARGS=%PT_INSTRUCTOR_APP_REGISTRY% %PT_INSTRUCTOR_APP_SIM_REGISTRY% %PT_REGISTRY% %PT_INSTRUCTOR_HUB_REGISTRY%

REM ============================================================
REM ============================================================

REM *** EOF
