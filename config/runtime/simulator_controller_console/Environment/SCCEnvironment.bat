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
REM  This file is used to define SCC specific environment variables

REM ============================================================
REM ============================================================
REM
REM  The following section specifies where the Java Archive files
REM  are located.

set SCC_JAR=%DEPLOY_LIB%\simulatorcontroller.jar;%DEPLOY_LIB%\sccplugin.jar
set CONFIG_DATA_JAR=%DEPLOY_LIB%\projectobjects.jar;%DEPLOY_LIB%\projectcommsstructure.jar

REM ============================================================
REM ============================================================
REM
REM  The following section sets the Java Class Path to include the
REM  classes contained within the deployed JAR files.

set CLASSPATH=%SCC_JAR%;%TRAIN_DATA_JARS%;%CONFIG_DATA_JAR%;%CLASSPATH%

REM ============================================================
REM ============================================================
REM
REM  The following section sets the application manager registry files

set SCC_REGISTRY=%DEPLOY_ENV%\SCC.properties
set SCC_SIM_REGISTRY=%DEPLOY_ENV%\SCCSim.properties
set SCC_APP_REGISTRY=%DEPLOY_ENV%\SCCApplicationManager.properties
set SCC_APP_SIM_REGISTRY=%DEPLOY_ENV%\SCCApplicationManagerSim.properties

REM ============================================================
REM ============================================================

REM *** EOF
