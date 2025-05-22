function [base_data_names, model_data_names, data_dir] = prj_data_names(model_name)
 
base_data_names = { ...
    'Def_Base_DoorSystem'...
};
     
model_data_names = { ...
    'Def_Prm_DoorSystem'...
};
     
 
%find the bus_dir based on the relative
%path to this file (prj_bus_names.m)
m_dir = fileparts(mfilename('fullpath'));
data_dir = fullfile(m_dir, '../data/parameter');
 
end