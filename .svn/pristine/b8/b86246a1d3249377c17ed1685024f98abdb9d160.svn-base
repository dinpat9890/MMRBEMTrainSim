if not exist %2 mkdir %2
robocopy /s %1 %2 /xf *.log /xf *.log.* /xd %1\Environment /xd Database /xd Track /xd Features /xd Config /xd Data\Vision /xd System
robocopy /s ..\Environment\CoreRig %2\Environment\CoreRig
robocopy /s . %2\\System /xf *.log /xd PerfLogs /xd Logs_*
if not exist %1\Tools\Internal\UpDown.exe copy /y %1\..\Tools\UpDown.exe %2\Tools\Internal\UpDown.exe
if not exist %2\..\Archive\Core\Replays mkdir %2\..\Archive\Core\Replays
