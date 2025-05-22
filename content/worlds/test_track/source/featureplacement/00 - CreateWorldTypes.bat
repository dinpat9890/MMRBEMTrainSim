@echo off

cd ..\..\..\..\

call ..\configure_ant.bat

call ant generate.world_types

pause
