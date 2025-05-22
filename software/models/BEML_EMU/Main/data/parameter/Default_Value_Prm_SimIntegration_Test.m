%% Functions for created Parameter Structures
function [default_value] = Default_Value_Prm_SimIntegration_Test(prm_datatype)
  
  if(~exist('prm_datatype', 'var'))
      prm_datatype = 'BD_SimIntegration_Prm';
  end
  
  default_value = Simulink.Bus.createMATLABStruct(prm_datatype);
  
  default_value.Dynamics	= Default_Value_Prm_TrainDynamics('BD_TrainDynamics_Prm');
  default_value.Brakes		= Default_Value_Prm_TrainBrakes_Vehicle();
  default_value.Pneumatics	= Default_Value_Prm_PneumaticsSystem();
  default_value.Traction	= Default_Value_Prm_TractionSystem();
  default_value.Pantograph	= Default_Value_Prm_PantographSystem();
  default_value.Doors       = Default_Value_Prm_DoorSystem();
  default_value.Electrical  = Default_Value_Prm_ElectricalSystem();
  default_value.TCMS        = Default_Value_Prm_TCMSSystem();
    
end