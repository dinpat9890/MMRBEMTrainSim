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

start "Train Model"      /min cmd.exe /c TrainModel.bat
start "Sound Model"      /min cmd.exe /c SoundModel.bat
start "World Model"      /min cmd.exe /c WorldModel.bat
start "Hub Module"       /min cmd.exe /c HubModule.bat
start "Audio Engine"     /min cmd.exe /c AudioEngine.bat
start "Shutdown"         /min cmd.exe /c Shutdown.bat
start "PAPISBackend"     /min cmd.exe /c PAPISBackend.bat
start "PAPISFrontend"    /min cmd.exe /c PAPISFrontend.bat
start "PISUnit"         /min cmd.exe /c PISUnit.bat
start "RadioBackend"    /min cmd.exe /c RadioBackend.bat
start "RadioFrontend"   /min cmd.exe /c RadioFrontend.bat
start "RadioUnit"        /min cmd.exe /c RadioUnit.bat
start "DVAUnit"        /min cmd.exe /c DVAUnit.bat

REM *** EOF
