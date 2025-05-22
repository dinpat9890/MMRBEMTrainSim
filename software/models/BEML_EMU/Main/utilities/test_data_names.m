function [base_data_names, model_data_names, data_dir] = test_data_names()

base_data_names = { ...
};
    
model_data_names = { ...
    'Prm_SimIntegration'...
};
    

%find the bus_dir based on the relative
%path to this file (prj_bus_names.m)
m_dir = fileparts(mfilename('fullpath'));
data_dir = fullfile(m_dir, '../data/parameter');

end