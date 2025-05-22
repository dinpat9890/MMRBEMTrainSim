function prj_configurations_load()

% This function is called when the project is run. Modify as needed to 
% autoload multiple data files and MATLAB scripts

% Find where data file is located
original_dir = pwd;
m_dir = fileparts(mfilename('fullpath'));
data_dir = fullfile(m_dir, '../data/config');
cd(data_dir)

% prj = slproject.getCurrentProject
% data_dir = fullfile(prj.RootFolder, 'data\config');
% addpath( data_dir );

display('Loading configurations');
ConfigSet_PantographSystem();
ConfigSet_PantographSystem_Reference();

cd(original_dir)