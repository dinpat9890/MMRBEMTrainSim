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
REM start "TrainDisplay"                     /min cmd.exe /c TrainDisplay.bat
start "TCMSFrontend-Instructor"          /min cmd.exe /c TCMSFrontend-Instructor.bat
start "DMIFrontend-Instructor"           /min cmd.exe /c DMIFrontendInstructor.bat
start "PAPIS-Instructor"          		 /min cmd.exe /c PAPISFrontend_Instructor.bat
start "RADIO-Instructor"           		 /min cmd.exe /c RadioFrontend_Instructor.bat
start "Saloon-CCTV-FE-Instructor"        /min cmd.exe /c CCTVFrontend_Instructor.bat
start "StudentMonitoring_OBS"        	 /min cmd.exe /c StudentMonitoring_OBS.bat
start "Vision Instructor CCTV"        	 /min cmd.exe /c VisionInstructorCCTV.bat
start "Shutdown"                         /min cmd.exe /c Shutdown.bat

REM *** EOF
