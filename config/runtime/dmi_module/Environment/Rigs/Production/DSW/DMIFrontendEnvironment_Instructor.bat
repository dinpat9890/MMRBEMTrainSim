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
REM  This File is used to define TMS application environment variables

REM ============================================================
REM ============================================================
REM
REM  The following section specifies where the Java Archive files
REM  are located.

set FEBE_UTILS_JAR=%DEPLOY_LIB%\febeutils.jar
set DMI_FE_JAR=%DEPLOY_LIB%\dmifrontend.jar
set DMI_COMMON_JAR=%DEPLOY_LIB%\dmicommon.jar
set DMI_FE_COMMON_JAR=%DEPLOY_LIB%\fecommon.jar;
set PROTOS_SERIALISATION_JAR=%DEPLOY_LIB%\protos-serialisation.jar
set CONFIG_DATA_JAR=%DEPLOY_LIB%\projectconfigdata.jar
set SIMULATOR_CONTROLLER_JAR=%DEPLOY_LIB%\simulatorcontroller.jar
set COMMS_STRUCTURE_JAR=%DEPLOY_LIB%\ProjectCommsStructure.jar
set DMI_UNIT_CONVERSION_JAR=%DEPLOY_LIB%\unitconversions.jar
set DMI_JSCIENCE_JAR=%DEPLOY_LIB%\jscience.jar
set LOOKS_JAR=%DEPLOY_COTS%\looks\looks-1.3.2.jar
set SPLASH_SCREEN_JAR=%DEPLOY_LIB%\splashscreens.jar


REM ============================================================
REM ============================================================
REM
REM  The following section sets the Java Class Path to include the
REM  classes contained within the deployed JAR files.

set CLASSPATH=%SIMULATOR_CONTROLLER_JAR%;%FEBE_UTILS_JAR%;%DMI_FE_JAR%;%DMI_COMMON_JAR%;%DMI_FE_COMMON_JAR%;%PROTOS_SERIALISATION_JAR%;%CONFIG_DATA_JAR%;%TRAIN_DATA_JARS%;%COMMS_STRUCTURE_JAR%;%DMI_UNIT_CONVERSION_JAR%; %DMI_JSCIENCE_JAR%;%LOOKS_JAR%;%SPLASH_SCREEN_JAR%;%CLASSPATH%

REM ============================================================
REM ============================================================
REM
REM  The following section sets the generic DMI IDU Frontend properties

set DMI_FE_REGISTRY=%DEPLOY_ENV%\DMIFrontend.properties
set DMI_FE_HUB_REGISTRY=%DEPLOY_ENV%\DMIFrontendHub_Instructor.properties
set DMI_FE_INSTRUCTOR_APP_REGISTRY=%DEPLOY_ENV%\DMIFrontendApplicationManager_Instructor.properties
set DMI_FE_APP_SIM_REGISTRY=%DEPLOY_ENV%\DMIFrontendApplicationManagerSim_Instructor.properties
set SYSTEM_SHUTDOWN_REGISTRY=%DEPLOY_ENV%\SystemShutdown.properties
set DMI_HUB_REGISTRY=%DEPLOY_ENV%\Hub.properties

REM ============================================================
REM ============================================================

REM *** EOF
