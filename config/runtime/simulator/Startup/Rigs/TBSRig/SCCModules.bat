start "Logging and Replay"  /min cmd.exe /c LoggingAndReplay.bat
start "Scripting Engine"    /min cmd.exe /c ScriptingEngine.bat
start "Soft PLC"            /min cmd.exe /c SoftPLC.bat
start "PT"          		/min cmd.exe /c ProceduralTrainer.bat
start "Train Display"    /min cmd.exe /c TrainDisplay.bat
start "SCC"                 /min /wait cmd.exe /c SimulatorControllerConsole.bat
REM start "Comms Show"    /min cmd.exe /c CommsShow.bat

