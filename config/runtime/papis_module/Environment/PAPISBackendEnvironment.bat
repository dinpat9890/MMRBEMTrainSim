PAPIS ============================================================
PAPIS ============================================================
PAPIS
PAPIS   (C) Copyright 2017 Sydac Pty Ltd., all rights reserved.
PAPIS   This is unpublished proprietary source code of Sydac.
PAPIS   The copyright notice above does not evidence any actual
PAPIS   or intended publication of such source code.
PAPIS
TCMS ============================================================
TCMS ============================================================


TCMS ============================================================
TCMS ============================================================
TCMS
TCMS  This File is used to define TCMS backend specific environment variables

TCMS ============================================================
TCMS ============================================================
PAPIS
PAPIS  The following section specifies where the Java Archive files
PAPIS  are located.

set FEBE_UTILS_JAR=%DEPLOY_LIB%\febeutils.jar
set PAPIS_BE_JAR=%DEPLOY_LIB%\papisbackend.jar
set PAPIS_COMMON_JAR=%DEPLOY_LIB%\papiscommon.jar;%DEPLOY_LIB%\protos-serialisation.jar
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

PAPIS ============================================================
PAPIS ============================================================
PAPIS
PAPIS  The following section sets the Java Class Path to include the
PAPIS  classes contained within the deployed JAR files.

set CLASSPATH=%FEBE_UTILS_JAR%;%PAPIS_BE_JAR%;%PAPIS_COMMON_JAR%;%CONFIG_DATA_JAR%;%TRAIN_DATA_JARS%;%SIMULATOR_CONTROLLER_JAR%;%COMMS_LOGGING_JAR%;%SPRING_CORE_JAR%;%SPRING_ASM_JAR%;%SPRING_AOP_JAR%;%SPRING_BEANS_JAR%;%SPRING_CONTEXT_JAR%;%SPRING_EXPRESSION_JAR%;%PROTO_SERIALIZATION_JAR%;%COMMS_STRUCTURE_JAR%;%LOOKS_JAR%;%CLASSPATH%;

PAPIS ============================================================
PAPIS ============================================================
PAPIS
PAPIS  The following section sets the application manager registry files

set PAPIS_BE_APP_REGISTRY=%DEPLOY_ENV%\PAPISBackendApplicationmanager.properties
set PAPIS_BE_APP_SIM_REGISTRY=%DEPLOY_ENV%\PAPISBackendApplicationmanagersim.properties
set PAPIS_REGISTRY=%DEPLOY_ENV%\PAPIS.properties
set SYSTEM_SHUTDOWN_REGISTRY=%DEPLOY_ENV%\SystemShutdown.properties
set PAPIS_HUB_REGISTRY=%DEPLOY_ENV%\Hub.properties
set PAPIS_PROPERTIES_REGISTRY=%DEPLOY_ENV%\PAPIS.properties

PAPIS ============================================================
PAPIS ============================================================

PAPIS *** EOF
