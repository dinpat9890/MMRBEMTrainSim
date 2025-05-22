@echo off

REM============================================================
REM============================================================
REM
REM   (C) Copyright 2010 Sydac Pty Ltd., all rights reserved.
REM   This is unpublished proprietary source code of Sydac.
REM   The copyright notice above does not evidence any actual
REM   or intended publication of such source code.
REM
REM============================================================
REM============================================================

REM============================================================
REM Configuring Custom Video Resolution
REM============================================================

start "PSDDSW_LeftFrontend"             /min cmd.exe /c PSDDSW_LeftFrontend_Instructor.bat
start "PSDDSW_RightFrontend"            /min cmd.exe /c PSDDSW_RightFrontend_instructor.bat
start "GCP Instructor"          /min cmd.exe /c GCPDriverControlPanel.bat
start "Vision-64-Instructor"            /min cmd.exe /c Vision-64-Forward_Instructor.bat
start "Shutdown"                        /min cmd.exe /c Shutdown.bat

REM *** EOF
