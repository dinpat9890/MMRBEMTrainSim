function set_up_project()
%set_up_project  Configure the environment for this project
%
%   Set up the environment for the current project. This function is set to
%   Run at Startup.

%   Copyright 2011-2012 The MathWorks, Inc.

% Use Simulink Project API to get the current project:
p = slproject.getCurrentProject;

projectRoot = p.RootFolder;
% Set the location of slprj to be the "work" folder of the current project:
myCacheFolder = fullfile(projectRoot, 'work');
if ~exist(myCacheFolder, 'dir')
    mkdir(myCacheFolder)
end
Simulink.fileGenControl('set', 'CacheFolder', myCacheFolder, ...
   'CodeGenFolder', myCacheFolder);

% Assume set_up_project is in same location as all files run below
m_files_dir = fileparts(mfilename('fullpath'));
model_name = 'TCMSSystem';

[base_data_names, model_data_names, data_dir] = prj_data_names(model_name);

prj_buses_load
prj_configurations_load
base_workspace_data_load(projectRoot, m_files_dir, base_data_names, data_dir)
model_workspace_data_load(projectRoot, m_files_dir, model_name, model_data_names, data_dir)

cd(projectRoot);
