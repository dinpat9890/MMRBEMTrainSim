rem net time \\RIG-01-SCC /set /yes
bin\bginfo Data\SetupSystem.bgi /timer:0 /nolicprompt
@for /D %%d in ("..\Archive" "..\Archive\Records","..\Archive\Replay","..\Archive\CCTV","..\Archive\Voice","..\Temp","..\Temp\IdealRuns") do @if not exist %%d mkdir %%d
