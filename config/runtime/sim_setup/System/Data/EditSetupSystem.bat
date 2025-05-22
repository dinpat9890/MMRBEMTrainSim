@if not "%1" == "" goto :run
cd ..
start bin\simsetup.bat /call "%0"
goto :end

:run
bin\bginfo Data\SetupSystem.bgi
rem This will close in 10 seconds, but >300 seconds crashes it
:end
