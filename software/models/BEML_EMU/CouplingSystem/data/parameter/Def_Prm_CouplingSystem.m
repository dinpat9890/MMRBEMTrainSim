%% Functions for created Parameter Structures
function Def_Prm_CouplingSystem()
  model_name = 'CouplingSystem';
  prm_name = 'PRM_CouplingSystem';
  prm_datatype = 'BD_CouplingSystem_Prm';
  is_model_argument = true;
  default_value = Default_Value_Prm_CouplingSystem(prm_datatype);
 
  parameter_define(model_name, prm_name, prm_datatype, is_model_argument, default_value)
 
end