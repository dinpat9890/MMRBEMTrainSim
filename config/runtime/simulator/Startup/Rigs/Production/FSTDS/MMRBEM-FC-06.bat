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
start "TCMSBackend"          /min cmd.exe /c TCMSBackend.bat
start "TCMSFrontend"         /min cmd.exe /c TCMSFrontend.bat
start "SerialDevices"        /min cmd.exe /c SerialDevices.bat
start "VisionTCMS"           /min cmd.exe /c VisionTCMS.bat
start "Shutdown"             /min cmd.exe /c Shutdown.bat

REM *** EOF