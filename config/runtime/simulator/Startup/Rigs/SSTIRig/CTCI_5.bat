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
start "Vision Comms"        /min cmd.exe /c VisionComms.bat
start "Vision"              /min cmd.exe /c Vision-64-Forward_Instructor.bat
start "Shutdown"            /min cmd.exe /c Shutdown.bat
start "VisionComms_CCTV"    /min cmd.exe /c VisionComms_CCTV.bat
REM *** EOF
