%% Functions for created Parameter Structures
function [default_value] =  Default_Value_Prm_PantographSystem(prm_datatype)

  if(~exist('prm_datatype', 'var'))
      prm_datatype = 'BD_PantographSystem_Prm';
  end

default_value = Simulink.Bus.createMATLABStruct(prm_datatype);

%% Common values
  default_value.PantoRaiseTime = 5;
  default_value.PantoLowerTime = 5;
  default_value.PantoEmergencyLowerTime = 2;

end