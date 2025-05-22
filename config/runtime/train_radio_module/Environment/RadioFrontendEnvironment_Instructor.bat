REM ============================================================
REM ============================================================
REM
REM   (C) Copyright 2017 Sydac Pty Ltd., all rights reserved.
REM   This is unpublished proprietary source code of Sydac.
REM   The copyright notice above does not evidence any actual
REM   or intended publication of such source code.
REM
REM ============================================================
REM ============================================================


REM ============================================================
REM ============================================================
REM
REM  This File is used to define Radio application environment variables

REM ============================================================
REM ============================================================
REM
REM  The following section specifies where the Java Archive files
REM  are located.

set FEBE_UTILS_JAR=%DEPLOY_LIB%\febeutils.jar
set RADIO_FE_JAR=%DEPLOY_LIB%\radiofrontend.jar
set RADIO_COMMON_JAR=%DEPLOY_LIB%\radiocommon.jar
set RADIO_FE_COMMON_JAR=%DEPLOY_LIB%\fecommon.jar;
set PROTOS_SERIALISATION_JAR=%DEPLOY_LIB%\protos-serialisation.jar
set CONFIG_DATA_JAR=%DEPLOY_LIB%\projectconfigdata.jar
set SIMULATOR_CONTROLLER_JAR=%DEPLOY_LIB%\simulatorcontroller.jar
set COMMS_STRUCTURE_JAR=%DEPLOY_LIB%\ProjectCommsStructure.jar
set RADIO_UNIT_CONVERSION_JAR=%DEPLOY_LIB%\unitconversions.jar
set RADIO_JSCIENCE_JAR=%DEPLOY_LIB%\jscience.jar
set LOOKS_JAR=%DEPLOY_COTS%\looks\looks-1.3.2.jar
set SPLASH_SCREEN_JAR=%DEPLOY_LIB%\splashscreens.jar


REM ============================================================
REM ============================================================
REM
REM  The following section sets the Java Class Path to include the
REM  classes contained within the deployed JAR files.

set CLASSPATH=%SIMULATOR_CONTROLLER_JAR%;%FEBE_UTILS_JAR%;%RADIO_FE_JAR%;%RADIO_COMMON_JAR%;%RADIO_FE_COMMON_JAR%;%PROTOS_SERIALISATION_JAR%;%CONFIG_DATA_JAR%;%TRAIN_DATA_JARS%;%COMMS_STRUCTURE_JAR%;%RADIO_UNIT_CONVERSION_JAR%; %RADIO_JSCIENCE_JAR%;%LOOKS_JAR%;%SPLASH_SCREEN_JAR%;%CLASSPATH%

REM ============================================================
REM ============================================================
REM
REM  The following section sets the generic Radio Frontend properties

set RADIO_INSTRUCTOR_FE_REGISTRY=%DEPLOY_ENV%\RadioFrontend.properties
set RADIO_INSTRUCTOR_FE_HUB_REGISTRY=%DEPLOY_ENV%\RadioFrontendHub_Instructor.properties
set RADIO_INSTRUCTOR_FE_APP_REGISTRY=%DEPLOY_ENV%\RadioFrontendApplicationManager_Instructor.properties
set RADIO_INSTRUCTOR_FE_APP_SIM_REGISTRY=%DEPLOY_ENV%\RadioFrontendApplicationManagerSim_Instructor.properties
set SYSTEM_SHUTDOWN_REGISTRY=%DEPLOY_ENV%\SystemShutdown.properties
set HUB_REGISTRY=%DEPLOY_ENV%\Hub.properties

REM ============================================================
REM ============================================================

REM *** EOF
