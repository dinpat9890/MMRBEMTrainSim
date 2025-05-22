PSD ============================================================
PSD ============================================================
PSD
PSD   (C) Copyright 2017 Sydac Pty Ltd., all rights reserved.
PSD   This is unpublished proprietary source code of Sydac.
PSD   The copyright notice above does not evidence any actual
PSD   or intended publication of such source code.
PSD
PSD ============================================================
PSD ============================================================


PSD ============================================================
PSD ============================================================
PSD
PSD  This File is used to define PSD application environment variables

PSD ============================================================
PSD ============================================================
PSD
PSD  The following section specifies where the Java Archive files
PSD  are located.

set FEBE_UTILS_JAR=%DEPLOY_LIB%\febeutils.jar
set PSD_FE_JAR=%DEPLOY_LIB%\psdfrontend.jar
set PSD_COMMON_JAR=%DEPLOY_LIB%\psdcommon.jar
set PSD_FE_COMMON_JAR=%DEPLOY_LIB%\fecommon.jar;
set PROTOS_SERIALISATION_JAR=%DEPLOY_LIB%\protos-serialisation.jar
set CONFIG_DATA_JAR=%DEPLOY_LIB%\projectconfigdata.jar
set SIMULATOR_CONTROLLER_JAR=%DEPLOY_LIB%\simulatorcontroller.jar
set COMMS_STRUCTURE_JAR=%DEPLOY_LIB%\ProjectCommsStructure.jar
set PSD_UNIT_CONVERSION_JAR=%DEPLOY_LIB%\unitconversions.jar
set PSD_JSCIENCE_JAR=%DEPLOY_LIB%\jscience.jar
set LOOKS_JAR=%DEPLOY_COTS%\looks\looks-1.3.2.jar
set SPLASH_SCREEN_JAR=%DEPLOY_LIB%\splashscreens.jar


PSD ============================================================
PSD ============================================================
PSD
PSD  The following section sets the Java Class Path to include the
PSD  classes contained within the deployed JAR files.

set CLASSPATH=%SIMULATOR_CONTROLLER_JAR%;%FEBE_UTILS_JAR%;%PSD_FE_JAR%;%PSD_COMMON_JAR%;%PSD_FE_COMMON_JAR%;%PROTOS_SERIALISATION_JAR%;%CONFIG_DATA_JAR%;%TRAIN_DATA_JARS%;%COMMS_STRUCTURE_JAR%;%PSD_UNIT_CONVERSION_JAR%; %PSD_JSCIENCE_JAR%;%LOOKS_JAR%;%SPLASH_SCREEN_JAR%;%CLASSPATH%

PSD ============================================================
PSD ============================================================
PSD
PSD  The following section sets the generic PSD Right Frontend properties

set PSD_RIGHT_FE_REGISTRY=%DEPLOY_ENV%\PSDRightFrontend.properties
set PSD_RIGHT_FE_HUB_REGISTRY=%DEPLOY_ENV%\PSDRightFrontendHub_Instructor.properties
set PSD_RIGHT_FE_APP_REGISTRY=%DEPLOY_ENV%\PSDRightFrontendApplicationManager.properties
set PSD_FE_APP_SIM_REGISTRY=%DEPLOY_ENV%\PSDFrontendApplicationManagerSim.properties
set SYSTEM_SHUTDOWN_REGISTRY=%DEPLOY_ENV%\SystemShutdown.properties
set PSD_HUB_REGISTRY=%DEPLOY_ENV%\Hub.properties

PSD ============================================================
PSD ============================================================

PSD *** EOF
