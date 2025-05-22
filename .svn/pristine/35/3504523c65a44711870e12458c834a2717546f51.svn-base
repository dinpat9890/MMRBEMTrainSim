@rem We run all queries locally. Otherwise one would need to enable the RPC server
@rem Use wmic, then type the commands in, to investigate, or it will wrap uncomfortably <NUL
@echo off
echo WMIC:"MAC Address"
wmic nicconfig where IPEnabled=true get MACAddress <NUL
echo WMIC:OS
wmic os get Caption <NUL
echo WMIC:CPU NumberOfLogicalProcessors
wmic cpu get Name, NumberOfLogicalProcessors <NUL
echo WMIC:"RAM"
wmic memphysical get MaxCapacity <NUL
echo WMIC:"Video RAM" "Video Card" "Video Mode"
wmic path win32_videocontroller get AdapterRAM, Caption, VideoModeDescription <NUL
