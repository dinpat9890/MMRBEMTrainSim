function clean_up_project()
%clean_up_project   Clean up local customizations of the environment
% 
%   Clean up the environment for the current project. This function undoes
%   the settings applied in "set_up_project". It is set to Run at Shutdown.

%   Copyright 2011-2012 The MathWorks, Inc.

% Use Simulink Project API to get the current project:
p = slproject.getCurrentProject;

% Get the project root folder:
projectRoot = p.RootFolder;

% Clean up our configurations we loaded.
prj_configurations_clear;
% Save out each bus to file, and remove it from the workspace
prj_buses_save;
prj_buses_clear;

% Now we should hopefully have an empty workspace, if not, we are not cleaning somthing up properly.

% Reset the location where generated code and other temporary files are
% created (slprj) to the default:
Simulink.fileGenControl('reset');
