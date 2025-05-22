setlocal

rem Not sure on why this is fixed as such, but at least it will still work either way
set TNS_ADMIN=..\Environment\

cd ..\Data
set PATH=%~dp0..\COTS\xerces\Bin\x64;%PATH%
set PATH=%~dp0..\COTS\vc_redist\x64\crt;%PATH%
set PATH=%~dp0..\COTS\oci\x64\bin;%PATH%

set UNIGINE_SDK_PATH=%~dp0..\COTS\Unigine
set PATH=%UNIGINE_SDK_PATH%\bin;%PATH%
set UNIGINE_SDK_DATA_PATH=%UNIGINE_SDK_PATH%\data

set VISION_INI_FILE=..\Environment\VisionForwardInstructor.ini
..\Bin\Vision64.exe %VISION_INI_FILE% -extern_plugin "vision_manager_plugin,Interface" -vision_manager_plugin_cfg %VISION_INI_FILE% -data_path %UNIGINE_SDK_DATA_PATH%

endlocal
