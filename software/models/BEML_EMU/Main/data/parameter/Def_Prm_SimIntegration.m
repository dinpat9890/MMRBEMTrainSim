%% Functions for created Parameter Structures
function Def_Prm_SimIntegration()
  model_name = 'BEML_EMU';
  prm_name = 'PRM_SimIntegration';
  prm_datatype = 'BD_SimIntegration_Prm';
  is_model_argument = true; %arguments are set below
  
  disp(['Defining model parameters for ', model_name]);
 
  default_value = Default_Value_Prm_SimIntegration();
  
  parameter_define(model_name, prm_name, prm_datatype, is_model_argument, default_value);
  
  m_args = 'PRM_SimIntegration';
  c_args = get_param(model_name, 'ParameterArgumentNames');
  
  if(~isequal(m_args, c_args))
    set_param(model_name, 'ParameterArgumentNames', 'PRM_SimIntegration');
  end
end