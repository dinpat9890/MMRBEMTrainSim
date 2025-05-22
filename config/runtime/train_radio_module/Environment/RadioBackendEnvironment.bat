REM  ============================================================
REM  ============================================================
REM 
REM    (C) Copyright 2017 Sydac Pty Ltd., all rights reserved.
REM    This is unpublished proprietary source code of Sydac.
REM    The copyright notice above does not evidence any actual
REM    or intended publication of such source code.

REM  ============================================================
REM  ============================================================


REM  ============================================================
REM  ============================================================

REM  This File is used to define TCMS backend specific environment variables

REM  ============================================================
REM  ============================================================

REM   The following section specifies where the Java Archive files
REM  are located.

set FEBE_UTILS_JAR=%DEPLOY_LIB%\febeutils.jar
set RADIO_BE_JAR=%DEPLOY_LIB%\radiobackend.jar
set RADIO_COMMON_JAR=%DEPLOY_LIB%\radiocommon.jar;%DEPLOY_LIB%\protos-serialisation.jar
set CONFIG_DATA_JAR=%DEPLOY_LIB%\projectconfigdata.jar
set SIMULATOR_CONTROLLER_JAR=%DEPLOY_LIB%\simulatorcontroller.jar
set SPRING_AOP_JAR=%DEPLOY_LIB%\spring-aop.jar
set SPRING_ASM_JAR=%DEPLOY_LIB%\spring-asm.jar
set SPRING_BEANS_JAR=%DEPLOY_LIB%\spring-beans.jar
set SPRING_CONTEXT_JAR=%DEPLOY_LIB%\spring-context-5.2.0.RELEASE.jar
set SPRING_CORE_JAR=%DEPLOY_LIB%\spring-core.jar
set SPRING_EXPRESSION_JAR=%DEPLOY_LIB%\spring-expression.jar
set COMMS_LOGGING_JAR=%DEPLOY_LIB%\commons-logging.jar
set COMMS_STRUCTURE_JAR=%DEPLOY_LIB%\ProjectCommsStructure.jar
set PROTO_SERIALIZATION_JAR=%DEPLOY_LIB%\protos-serialisation.jar
set LOOKS_JAR=%DEPLOY_COTS%\looks\looks-1.3.2.jar

REM  ============================================================
REM  ============================================================

REM   The following section sets the Java Class Path to include the
REM   classes contained within the deployed JAR files.

set CLASSPATH=%FEBE_UTILS_JAR%;%RADIO_BE_JAR%;%RADIO_COMMON_JAR%;%CONFIG_DATA_JAR%;%TRAIN_DATA_JARS%;%SIMULATOR_CONTROLLER_JAR%;%COMMS_LOGGING_JAR%;%SPRING_CORE_JAR%;%SPRING_ASM_JAR%;%SPRING_AOP_JAR%;%SPRING_BEANS_JAR%;%SPRING_CONTEXT_JAR%;%SPRING_EXPRESSION_JAR%;%PROTO_SERIALIZATION_JAR%;%COMMS_STRUCTURE_JAR%;%LOOKS_JAR%;%CLASSPATH%;

REM  ============================================================
REM  ============================================================

REM The following section sets the application manager registry files

set RADIO_BE_APP_REGISTRY=%DEPLOY_ENV%\RadioBackendApplicationmanager.properties
set RADIO_BE_APP_SIM_REGISTRY=%DEPLOY_ENV%\RadioBackendApplicationmanagersim.properties
set RADIO_REGISTRY=%DEPLOY_ENV%\Radio.properties
set SYSTEM_SHUTDOWN_REGISTRY=%DEPLOY_ENV%\SystemShutdown.properties
set RADIO_HUB_REGISTRY=%DEPLOY_ENV%\Hub.properties
set RADIO_PROPERTIES_REGISTRY=%DEPLOY_ENV%\Radio.properties

REM  ============================================================
REM  ============================================================

REM  *** EOF
