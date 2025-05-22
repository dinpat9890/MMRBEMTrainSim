setlocal

set TNS_ADMIN=..\Environment\

cd ..\Data
set PATH=%~dp0..\COTS\xerces\Bin\x64;%PATH%
set PATH=%~dp0..\COTS\vc_redist\x64\crt;%PATH%
set PATH=%~dp0..\COTS\oci\x64\bin;%PATH%

set UNIGINE_SDK_PATH=%~dp0..\COTS\Unigine
set PATH=%UNIGINE_SDK_PATH%\bin;%PATH%
set UNIGINE_SDK_DATA_PATH=%UNIGINE_SDK_PATH%\data

set VISION_INI_FILE=..\Environment\VisionForwardRight.ini
set LIVE3D_INI_FILE=..\Environment\Live3D.ini
..\Bin\Vision64.exe %VISION_INI_FILE% -extern_plugin "vision_manager_plugin,Interface,Live3DClient" -vision_manager_plugin_cfg %VISION_INI_FILE% --live3d_config_file %LIVE3D_INI_FILE% -extern_define "ENABLE_LIVE3D" -data_path %UNIGINE_SDK_DATA_PATH%

endlocal
