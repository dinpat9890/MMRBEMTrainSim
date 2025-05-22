robocopy /s . %2\\System /xf *.log /xd PerfLogs /xd Logs_*
robocopy /s ..\Environment\CoreRig %2\Environment\CoreRig
robocopy /s %1 %2 /xf *.log /xf *.log.* /xf OgreGraphicsDriver.ini /xd %1\Environment /xd Database /xd Track /xd Features /xd Config /xd Vision /xd System
if not exist %1\Tools\Internal\UpDown.exe copy /y %1\..\Tools\UpDown.exe %2\Tools\Internal\UpDown.exe
copy /y %1\..\CoreVersion.properties %2\System\Data\CoreVersion.properties

rem Ctrl+Alt+Num 3
bin\shortcut /f:"%USERPROFILE%\Desktop\System Install.lnk" /t:"%CD%\System_Install.bat" /w:"%CD%" /a:c /i:"%CD%\bin\simsetup.exe",1 /h:1635

rem Ctrl+Alt+Num 1
bin\shortcut /f:"%USERPROFILE%\Desktop\System Run.lnk" /t:"%~dpnx2\System\System_Run.bat" /w:"%~dpnx2\System" /a:c /i:"%CD%\bin\simsetup.exe",2 /h:1633

rem Ctrl+Alt+Num 0
bin\shortcut /f:"%USERPROFILE%\Desktop\System Kill.lnk" /t:"%~dpnx2\System\System_Kill.bat" /w:"%~dpnx2\System" /a:c /i:"%CD%\bin\simsetup.exe",3 /h:1632
