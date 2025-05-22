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
REM  This file is used to define GCP specific environment variables

REM ============================================================
REM ============================================================
REM
REM  The following section specifies where the Java Archive files
REM  are located.

set GCP_JAR=%DEPLOY_LIB%\gcp.jar

REM ============================================================
REM ============================================================
REM
REM  The following section sets the Java Class Path to include the
REM  classes contained within the deployed JAR files.

set CLASSPATH=%GCP_JAR%;%CLASSPATH%

REM ============================================================
REM ============================================================
REM
REM  The following section sets the application manager registry files

set GCP_APP_REGISTRY=%DEPLOY_ENV%\GCPApplicationManager.properties

set GCP_ARGS=%GCP_APP_REGISTRY%

REM ============================================================
REM ============================================================

REM *** EOF
