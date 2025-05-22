%% Functions for created Parameter Structures
function PRM_TractionConverter()
  model_name = 'TractionSystem';
  prm_name = 'PRM_TractionConverter';
  prm_type = 'BD_TractionSystem_Prm';

  modelWorkspace = get_param(model_name,'ModelWorkspace');

  %% Setup the struct parameter with correct data type.
  new_prm = Simulink.Parameter;
  new_prm.CoderInfo.StorageClass = 'Auto';
  new_prm.Description = '';
  new_prm.DataType = 'auto';
  new_prm.Min = [];
  new_prm.Max = [];
  new_prm.DocUnits = '';
  new_prm.DataType = ['Bus: ' prm_type];
  new_prm.Value = Simulink.Bus.createMATLABStruct(prm_type);

  %% Check if a parameter matching this already exists in the model workspace.
  require_assignnment = true;
  prm_exists = modelWorkspace.hasVariable(prm_name);
  if (prm_exists)
    current_prm = modelWorkspace.getVariable(prm_name);
    if(isequal(current_prm, new_prm))
      disp("Model Paramaters have not changed");
      require_assignnment = false;
    end
  end

  %% assign our value and make it an argument if we did not match
  if(require_assignnment)
    disp("Assigning Model Workspace Data");
    assignin(modelWorkspace, prm_name,new_prm);
    set_param(model_name, ...
              'ParameterArgumentNames', prm_name);
  end
end

