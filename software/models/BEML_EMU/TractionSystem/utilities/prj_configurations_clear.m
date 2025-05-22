function prj_configurations_clear()

% This function is called when the project is closed. 
% Should clean up any configuration data from the workspace

evalin('base', 'clear ConfigSet_TractionSystem');
evalin('base', 'clear ConfigSet_TractionSystem_Reference')
end