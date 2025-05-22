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

REM============================================================
REM============================================================
REM
REM  This File is used to define GCP specific environment variables

echo Setting up GCP environment...

REM============================================================
REM============================================================
REM
REM  The following section specifies where the Java Archive files
REM  are located.

set GCP_JAR=%DEPLOY_LIB%\gcp.jar;%DEPLOY_LIB%\febeutils.jar;

REM============================================================
REM============================================================
REM
REM  The following section sets the Java Class Path to include the
REM  classes contained within the deployed JAR files.

set CLASSPATH=%GCP_JAR%;%CLASSPATH%%DEPLOY_LIB%\legacyclasses.jar;%DEPLOY_LIB%\graphics.jar;%TRAIN_DATA_JARS%;

REM============================================================
REM============================================================
REM
REM  The following section sets the application manager registry files

set GCP_APP_REGISTRY=%DEPLOY_ENV%\GCPDriverControlPanelApplicationManager_Observer.properties
set GCP_APP_SIM_REGISTRY=%DEPLOY_ENV%\GCPDriverControlPanelApplicationManagerSim.properties

set GCP_ARGS=%GCP_APP_REGISTRY% %GCP_APP_SIM_REGISTRY% 

REM============================================================
REM============================================================

REM *** EOF
