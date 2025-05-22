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
REM  This file is used to define SMC specific environment variables

REM ============================================================
REM ============================================================
REM
REM  The following section specifies where the Java Archive files
REM  are located.

set SMC_JAR=%DEPLOY_LIB%\simulatormanager.jar;%DEPLOY_LIB%\smctimetableplugin.jar
set MARSHALLING_JAR=%DEPLOY_LIB%\projecttrainmarshalling.jar

REM ============================================================
REM ============================================================
REM
REM  The following section sets the Java Class Path to include the
REM  classes contained within the deployed JAR files.

set CLASSPATH=%SMC_JAR%;%MARSHALLING_JAR%;%CLASSPATH%

REM ============================================================
REM ============================================================
REM
REM  The following section sets the application manager registry file

set SMC_REGISTRY=%DEPLOY_ENV%\SMC.properties
set SMC_APP_REGISTRY=%DEPLOY_ENV%\SMCApplicationManager.properties

REM ============================================================
REM ============================================================

REM *** EOF
