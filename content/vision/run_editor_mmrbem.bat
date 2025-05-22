setlocal
REM Update the dependencies before starting the editor

call ..\..\configure_ant.bat
call ant -f ..\..\ant.prepare.xml prepare.content
call ant -f ..\build.xml combine_features

endlocal

setlocal
REM Start the editor

call set_vision_environment.bat
start /D %~dp0 %UNIGINE_SDK_PATH%/bin/editor_x64.exe ^
-engine_log %~dp0log.html ^
-engine_config %~dp0vision.cfg ^
-editor_config ../../../../../../Content/vision/unigine_editor.cfg ^
-data_path %~dp0 ^
-data_path %UNIGINE_SDK_DATA_PATH% ^
-data_path %TOOLS_ROOT%/unigine2_track_mesh_builder ^
-data_path %TOOLS_ROOT%/extruder ^
-data_path %TOOLS_ROOT%/collapse ^
-extern_plugin "../../../../../software/oksygen/sim/core/unigine_plugins/vision_manager_plugin/bin/vision_manager_plugin,../../../../../software/oksygen/sim/core/tools/vision_studio/bin/unigine2_track_mesh_builder,../../../../../../vision/utility/unigine2_extruder/unigine2_extruder,../../../../../software/oksygen/sim/core/tools/vision_studio/bin/unigine2_collapse" ^
-vision_manager_plugin_cfg vision_mmrbem.ini ^
-editor_plugin "SydacPanel.plugin,DuncanCommander.plugin,unigine2_track_mesh_builder/unigine2_track_mesh_builder.plugin,unigine2_extruder/unigine2_extruder.plugin,unigine2_collapse/unigine2_collapse.plugin" ^
-extern_define "PROJECT_CODE=project,LOG_LEVEL_VERBOSE" ^
-system_script "SystemProject.us.cpp"

endlocal