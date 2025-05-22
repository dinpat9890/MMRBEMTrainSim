function test_workspace_data_load()

% This function is called when the project is run. Modify as needed to 
% autoload multiple data files and MATLAB scripts
original_dir = pwd;
m_dir = fileparts(mfilename('fullpath'));
cd(m_dir)

p = slproject.getCurrentProject;
model_name = p.Name;

[base_data_names, model_data_names, data_dir] = test_data_names();
% base workspace data
if ~isempty(base_data_names)
    data_load(base_data_names, data_dir);
end
% model workspace data
% need to load the model first
if ~isempty(model_data_names)
    load_system(model_name);
    data_load(model_data_names, data_dir);
    save_required = bdIsDirty(model_name);
    close_system(model_name, save_required);
end

% This is a bit messy as theoretically we would want to be loading this
% from an actual data file somewhere
% assignin('base', 'MaxVehicles', 20); %Default MaxVehicles
% rs = RandStream('mt19937ar','Seed',0);
% assignin('base', 'RandomIndexArray', randperm(rs, 500)); %Default MaxVehicles


cd(original_dir)