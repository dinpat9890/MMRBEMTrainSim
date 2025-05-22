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
start "HubModule"           /min cmd.exe /c HubModule.bat
start "WorldModel"          /min cmd.exe /c WorldModel.bat
start "TrainModel"          /min cmd.exe /c TrainModel.bat
start "ScriptingEngine"     /min cmd.exe /c ScriptingEngine.bat
start "VisionComms"         /min cmd.exe /c VisionComms.bat
start "VisionComms CCTV"    /min cmd.exe /c VisionComms_CCTV.bat
start "SoundModel"          /min cmd.exe /c SoundModel.bat
start "AudioEngine"         /min cmd.exe /c AudioEngine.bat
start "PISUnit"             /min cmd.exe /c PISUnit.bat
start "DVAUnit"             /min cmd.exe /c DVAUnit.bat
start "Shutdown"            /min cmd.exe /c Shutdown.bat

REM *** EOF
