echo off

SET COTS_FOLDER=..\..\..\..\dependencies\cots\oksygen\cots
SET EXE_FOLDER=..\..\..\..\..\dependencies\software\oksygen\sim\core\tools\feature_automation_encoder\bin

SET SCHEMA_DIR=..\..\..\..\dependencies\software\oksygen\common\libraries\network_definition

set PATH=%PATH%;%COTS_FOLDER%\xerces\Bin\Win32;%COTS_FOLDER%\python\bin

del /Q feature_automation_encoder.log

REM Runtime Parameters
REM
REM -i    Source XML
REM -il   Source XML List
REM -el   Exclusion List
REM -d    Definition - Implies ds and dw are specified, this is the input network definition.
REM -ds   Schema Directory
REM -dw   World Types
REM -od   Output Network Definition with Automation Scripts appended
REM -os   Output Script
REM -rf   Report File - reports to this as a csv file

%EXE_FOLDER%\feature_automation_encoder.exe    -il=.\FeatureAutomationScripts\Input\AutomationScriptInputFiles_Cutout_Mode.txt ^
                                               -os=.\FeatureAutomationScripts\Output\MMRBEM_ControlTable_Cutout_Mode.script ^
                                               -od=..\..\definition\Mumbai_Metro_L2_L7_Track_Cutout_Mode.xml ^
                                               -rf=MMRBEM_Report.csv ^
                                               -el=.\ControlTables\Output\excluded_signals.txt ^
                                               -d=..\..\definition\MMRBEM_Features_Track.xml ^
                                               -ds=%SCHEMA_DIR% ^
                                               -dw=..\..\..\..\features\world_types.xml

pause