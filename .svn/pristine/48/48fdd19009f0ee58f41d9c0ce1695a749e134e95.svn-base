@rem We run all queries locally. Otherwise one would need to enable the RPC server
@rem Use wmic, then type the commands in, to investigate, or it will wrap uncomfortably
@echo off
echo WMIC:"MAC Address"
wmic nicconfig where IPEnabled=true get MACAddress
echo WMIC:OS
wmic os get Caption
echo WMIC:CPU NumberOfLogicalProcessors
wmic cpu get Name, NumberOfLogicalProcessors
echo WMIC:"RAM"
wmic memphysical get MaxCapacity
echo WMIC:"Video RAM" "Video Card" "Video Mode"
wmic path win32_videocontroller get AdapterRAM, Caption, VideoModeDescription
