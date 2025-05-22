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

start "VisionComms"             /min cmd.exe /c     VisionComms.bat
start "VisionComms CCTV"        /min cmd.exe /c     VisionComms_CCTV.bat
start "VisionComms_TCMS_CCTV"   /min cmd.exe /c     VisionComms_TCMS_CCTV.bat
start "Vision FWD Right"        /min cmd.exe /c     Vision-64-Forward-Right.bat
start "Shutdown"                /min cmd.exe /c     Shutdown.bat

REM *** EOF
