robocopy /s . %2\\System /xf *.log /xd PerfLogs /xd Logs_*
robocopy /s ..\Environment\CoreRig %2\Environment\CoreRig
robocopy /s %1 %2 /xf *.log /xf *.log.* /xd %1\Environment /xd System
if not exist %1\Tools\Internal\UpDown.exe copy /y %1\..\Tools\UpDown.exe %2\Tools\Internal\UpDown.exe
