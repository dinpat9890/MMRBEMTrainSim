rem Adding Core, Project to the path for the train model DLLs
call ..\Environment\SetPath_Xerces.bat
call ..\Environment\SetPath_TNS.bat
cd ..\data
..\bin\plugin_module.exe ..\environment\TrainModel.ini