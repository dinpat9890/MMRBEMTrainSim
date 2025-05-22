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
REM  This file is used to define GMI specific environment variables

REM ============================================================
REM ============================================================
REM
REM  The following section specifies where the Java Archive files
REM  are located.

set GMI_JAR=%DEPLOY_LIB%\gmi.jar
set CONFIG_DATA_JARS=%DEPLOY_LIB%\projectconfigdata.jar;%DEPLOY_LIB%\gmiconfig.jar;%DEPLOY_LIB%\gmiplugin.jar;%DEPLOY_LIB%\projectobjects.jar;%DEPLOY_LIB%\ProjectCommsStructure.jar;

REM ============================================================
REM ============================================================
REM
REM  The following section sets the Java Class Path to include the
REM  classes contained within the deployed JAR files.

set CLASSPATH=%GMI_JAR%;%TRAIN_DATA_JARS%;%CONFIG_DATA_JARS%;%CLASSPATH%

REM ============================================================
REM ============================================================
REM
REM  The following section sets the application manager registry files

set GMI_REGISTRY=%DEPLOY_ENV%\GMI.properties

set COMMON_GMI_ARGS=%GMI_REGISTRY%

REM ============================================================
REM ============================================================

REM *** EOF
