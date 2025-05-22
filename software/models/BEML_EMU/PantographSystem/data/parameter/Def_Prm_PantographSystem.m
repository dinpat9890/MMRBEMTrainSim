%% Functions for created Parameter Structures
function Def_Prm_PantographSystem()
  model_name = 'PantographSystem';
  prm_name = 'Prm_PantographSystem';
  prm_datatype = 'BD_PantographSystem_Prm';
  is_model_argument = true;
  default_value = Default_Value_Prm_PantographSystem(prm_datatype);
 
  parameter_define(model_name, prm_name, prm_datatype, is_model_argument, default_value)
    
end