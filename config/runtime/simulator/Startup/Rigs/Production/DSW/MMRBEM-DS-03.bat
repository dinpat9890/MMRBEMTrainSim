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

start "DMIBackend"                  /min cmd.exe /c DMIBackend.bat
start "DMIFrontend"                 /min cmd.exe /c DMIFrontend.bat
start "CBTCOnBoard"                 /min cmd.exe /c CBTCOnBoard.bat
start "CBTCUnits"                   /min cmd.exe /c CBTCUnits.bat
start "Shutdown"                    /min cmd.exe /c Shutdown.bat


REM *** EOF
