%% Functions for created Parameter Structures
function Def_Prm_TCMSSystem()
  model_name = 'TCMSSystem';
  prm_name = 'Prm_TCMSSystem';
  prm_datatype = 'BD_TCMSSystem_Prm';
  is_model_argument = true;
  default_value = Default_Value_Prm_TCMSSystem(prm_datatype);
 
  parameter_define(model_name, prm_name, prm_datatype, is_model_argument, default_value)
    
end