@echo off

set PATH=..\..\cots\opencv\x64\vc15\bin\;..\..\cots\IntelRealSenseSDK2.0\bin\x64\;..\..\cots\DirectX9\x86\;%PATH%

cd ..\data\Live3D
start ..\..\bin\Live3DServer.exe ..\..\Environment\Live3DServerSettings.xml