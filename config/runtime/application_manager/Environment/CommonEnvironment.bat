REM ============================================================
REM ============================================================
REM
REM   (C) Copyright 2019 Sydac Pty Ltd., all rights reserved.
REM   This is unpublished proprietary source code of Sydac.
REM   The copyright notice above does not evidence any actual
REM   or intended publication of such source code.
REM
REM ============================================================
REM ============================================================


REM ============================================================
REM ============================================================
REM
REM  This file defines common environment variables
REM  for Java applications.

REM ============================================================
REM ============================================================
REM
REM  Set the following constants to match the deploy's 
REM  directory structure.
REM
REM  DEPLOY_HOME         : The Base Path of the Deployment
REM  DEPLOY_LIB          : JAR files
REM  DEPLOY_BIN          : Binaries
REM  DEPLOY_COTS         : COTS
REM  DEPLOY_ENV          : Environment files and configuration files

set DEPLOY_HOME=..
set DEPLOY_BIN=%DEPLOY_HOME%\Bin
set DEPLOY_LIB=%DEPLOY_HOME%\Jar
set DEPLOY_COTS=%DEPLOY_HOME%\COTS
set DEPLOY_ENV=%DEPLOY_HOME%\Environment

REM ============================================================
REM ============================================================
REM
REM  The following section specifies where libraries are located.

REM Okatl Sydac libraries that are typically used by simulator applications:

set APPLICATION_MANAGER_JAR=%DEPLOY_LIB%\applicationmanager.jar
set COMMS_JAR=%DEPLOY_LIB%\comms.jar
set CONTENT_JAR=%DEPLOY_LIB%\content.jar
set CONTENT_UTILS_JAR=%DEPLOY_LIB%\contentutils.jar
set DATABASE_JAR=%DEPLOY_LIB%\database.jar
set DATAOBJECTS_JAR=%DEPLOY_LIB%\dataobjects.jar
set EVENT_SCRIPT_JAR=%DEPLOY_LIB%\eventscript.jar
set FEATURE_DATA_JAR=%DEPLOY_LIB%\featuredata.jar
set FOUNDATION_JAR=%DEPLOY_LIB%\foundation.jar
set GUI_JAR=%DEPLOY_LIB%\gui.jar
set GEOM_JAR=%DEPLOY_LIB%\geometry.jar
set I18N_JAR=%DEPLOY_LIB%\i18n.jar
set NETWORK_JAR=%DEPLOY_LIB%\network.jar
set LOGGING_JAR=%DEPLOY_LIB%\logging.jar
set PEER_APPLICATION_JAR=%DEPLOY_LIB%\peermodule.jar
set REGISTRY_JAR=%DEPLOY_LIB%\registry.jar
set RUNTIME_DATA_JAR=%DEPLOY_LIB%\runtimedata.jar
set SESSION_DATA_JAR=%DEPLOY_LIB%\sessiondata.jar
set SPLASH_SCREENS_JAR=%DEPLOY_LIB%\splashscreens.jar
set UNIT_CONVERSIONS_JAR=%DEPLOY_LIB%\unitconversions.jar
set SERIALISATION_JAR=%DEPLOY_LIB%\core_serialisation.jar;%DEPLOY_LIB%\train_serialisation.jar
set SIGNAL_TRACK_VIEWER_JAR=%DEPLOY_LIB%\signaltrackviewer.jar
set TRACK_DATA_UTILS_JAR=%DEPLOY_LIB%\trackdatautils.jar

REM COTS libraries that are typically used by simulator applications:

set AOPALLIANCE_JAR=%DEPLOY_COTS%\google-guice\aopalliance.jar
set BORLAND_JAR=%DEPLOY_LIB%\jbcl3.0.jar
set GSON_JAR=%DEPLOY_COTS%\gson\gson-2.6.2.jar
set GUAVA_JAR=%DEPLOY_COTS%\google-guava\guava-26.0-jre.jar
set GUICE_JAR=%DEPLOY_COTS%\google-guice\guice-3.0.jar
set JAVAXCOMMS_JAR=%DEPLOY_COTS%\javax.comm\comm.jar
set JAVAX_INJECT_JAR=%DEPLOY_COTS%\google-guice\javax.inject.jar
set JCOMMUNIQUE_JAR=%DEPLOY_COTS%\jcommunique\JCommunique-2.0.0.jar
set JDBC_JAR=%DEPLOY_COTS%\oraclejdbc\ojdbc14.jar
set JGOODIES_JAR=%DEPLOY_COTS%\looks\looks-1.3.2.jar
set JSCIENCE_JAR=%DEPLOY_COTS%\jscience\jscience.jar
set LOG4J_JAR=%DEPLOY_COTS%\apache-log4j\log4j-1.2.15.jar
set MICROBA_JAR=%DEPLOY_COTS%\microba\microba-0.4.4.3.jar
set MIGLAYOUT_JAR=%DEPLOY_COTS%\miglayout\miglayout-3.7.1-swing.jar
set PROTOBUF_JAR=%DEPLOY_COTS%\protobuf\lib\protobuf.jar
set SHIRO_CORE_JAR=%DEPLOY_COTS%\apache-shiro-core\shiro-core-1.3.2.jar
set SLF4J_LOG4J_JAR=%DEPLOY_COTS%\slf4j-log4j\slf4j-log4j12-1.7.25.jar
set SLF4J_API=%DEPLOY_COTS%\slf4j-api\slf4j-api-1.7.25.jar

REM ============================================================
REM ============================================================
REM
REM  The following section sets the Java Class Path to include the
REM  libraries defined above.

set CLASSPATH=.;%APPLICATION_MANAGER_JAR%;%CONTENT_JAR%;%CONTENT_UTILS_JAR%;%DATABASE_JAR%
set CLASSPATH=%CLASSPATH%;%DATAOBJECTS_JAR%;%EVENT_SCRIPT_JAR%
set CLASSPATH=%CLASSPATH%;%FEATURE_DATA_JAR%;%FOUNDATION_JAR%;%GUI_JAR%
set CLASSPATH=%CLASSPATH%;%LOGGING_JAR%;%PEER_APPLICATION_JAR%
set CLASSPATH=%CLASSPATH%;%REGISTRY_JAR%;%RUNTIME_DATA_JAR%
set CLASSPATH=%CLASSPATH%;%SESSION_DATA_JAR%;%SPLASH_SCREENS_JAR%
set CLASSPATH=%CLASSPATH%;%UNIT_CONVERSIONS_JAR%
set CLASSPATH=%CLASSPATH%;%SERIALISATION_JAR%
set CLASSPATH=%CLASSPATH%;%SIGNAL_TRACK_VIEWER_JAR%;%TRACK_DATA_UTILS_JAR%
set CLASSPATH=%CLASSPATH%;%GEOM_JAR%
set CLASSPATH=%CLASSPATH%;%BORLAND_JAR%
set CLASSPATH=%CLASSPATH%;%COMMS_JAR%
set CLASSPATH=%CLASSPATH%;%I18N_JAR%
set CLASSPATH=%CLASSPATH%;%JAVAXCOMMS_JAR%
set CLASSPATH=%CLASSPATH%;%JCOMMUNIQUE_JAR%
set CLASSPATH=%CLASSPATH%;%JDBC_JAR%
set CLASSPATH=%CLASSPATH%;%JGOODIES_JAR%
set CLASSPATH=%CLASSPATH%;%JSCIENCE_JAR%
set CLASSPATH=%CLASSPATH%;%LOG4J_JAR%
set CLASSPATH=%CLASSPATH%;%MIGLAYOUT_JAR%
set CLASSPATH=%CLASSPATH%;%MICROBA_JAR%
set CLASSPATH=%CLASSPATH%;%PROTOBUF_JAR%
set CLASSPATH=%CLASSPATH%;%GSON_JAR%
set CLASSPATH=%CLASSPATH%;%GUAVA_JAR%
set CLASSPATH=%CLASSPATH%;%GUICE_JAR%
set CLASSPATH=%CLASSPATH%;%AOPALLIANCE_JAR%
set CLASSPATH=%CLASSPATH%;%JAVAX_INJECT_JAR%
set CLASSPATH=%CLASSPATH%;%SHIRO_CORE_JAR%
set CLASSPATH=%CLASSPATH%;%SLF4J_LOG4J_JAR%
set CLASSPATH=%CLASSPATH%;%SLF4J_API%

REM ============================================================
REM ============================================================
REM
REM  The following section defines common configuration files

set APP_MANAGER_REGISTRY=%DEPLOY_ENV%\ApplicationManager.properties
set DATABASE_REGISTRY=%DEPLOY_ENV%\Database.ini
set SYSTEM_SIMULATORS_REGISTRY=%DEPLOY_ENV%\SystemSimulators.properties

set STV_REGISTRY=%DEPLOY_ENV%\SignalTrackViewer.properties
set ES_REGISTRY=%DEPLOY_ENV%\EventScript.properties

set L10N_REGISTRY=%DEPLOY_ENV%\Localisation.ini
set UNITS_REGISTRY=%DEPLOY_ENV%\Units.properties

REM ============================================================
REM ============================================================
REM
REM  The following section sets the Comms DLL path

set COMMS_DLL_PATH=%DEPLOY_BIN%

REM ============================================================
REM ============================================================
REM
REM  The following section sets the simulator data JARs

set CORE_COMMS_STRUCT_JAR=%DEPLOY_LIB%\CoreCommsStructure.jar
set TRAIN_COMMS_STRUCT_JAR=%DEPLOY_LIB%\TrainCommsStructure.jar

set CORE_SERIALISATION_JAR=%DEPLOY_LIB%\CoreSerialisation.jar
set TRAIN_SERIALISATION_JAR=%DEPLOY_LIB%\TrainSerialisation.jar

set TRAIN_FEATURES_JAR=%DEPLOY_LIB%\TrainFeatures.jar

REM These collect the jars defined above, for brevity
set TRAIN_COMMS_JARS=%CORE_COMMS_STRUCT_JAR%;%TRAIN_COMMS_STRUCT_JAR%
set TRAIN_SERIALISATION_JARS=%CORE_SERIALISATION_JAR%;%CORE_SERIALISATION_JAR%
set TRAIN_DATA_JARS=%TRAIN_COMMS_JARS%;%TRAIN_SERIALISATION_JARS%;%TRAIN_FEATURES_JAR%

REM ============================================================
REM ============================================================
REM
REM  The following section sets the common JVM args

set COMMON_JVM_ARGS=-Djava.library.path=%COMMS_DLL_PATH% -XX:+HeapDumpOnOutOfMemoryError

REM ============================================================
REM ============================================================
REM
REM  The following section sets the common Java args for launching 
REM  applications that extend PeerApplication

set COMMON_JAVA_ARGS=com.sydac.peer.application.PeerApplicationManager %DATABASE_REGISTRY% %APP_MANAGER_REGISTRY% %L10N_REGISTRY% %UNITS_REGISTRY%

REM ============================================================
REM ============================================================

REM *** EOF
