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
start "Audio Engine"    /min cmd.exe /c     AudioEngine.bat
start "Sound Model"     /min cmd.exe /c     SoundModel.bat
start "PIS Unit"        /min cmd.exe /c     PISUnit.bat
start "DVA Unit"        /min cmd.exe /c     DVAUnit.bat
start "Shutdown"                   /min cmd.exe /c Shutdown.bat

REM *** EOF
