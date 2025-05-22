echo off
rem ###############################################################
rem #
rem # Description:    Batch File to 
rem #
rem # Project:        
rem #
rem # Author:         Andy Cooper
rem #
rem # (C) Copyright:  SYDAC Pty Ltd, 2013
rem #
rem ###############################################################
rem
cd input

SET COTS_FOLDER=..\..\..\..\..\..\dependencies\cots\oksygen\cots
SET EXE_FOLDER=..\..\..\..\..\..\dependencies\software\oksygen\sim\core\tools\feature_placement\bin

set PATH=%PATH%;%COTS_FOLDER%\xerces\Bin\Win32;%COTS_FOLDER%\python\bin

call %EXE_FOLDER%\excel_feature_placement.exe ExcelFeaturePlacementTool.ini

