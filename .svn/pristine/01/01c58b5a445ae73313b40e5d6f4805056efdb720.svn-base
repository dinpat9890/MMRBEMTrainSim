%% Functions for created Parameter Structures
function [default_value] =  Default_Value_Prm_TCMSSystem(prm_datatype)

  if(~exist('prm_datatype', 'var'))
      prm_datatype = 'BD_TCMSSystem_Prm';
  end

default_value = Simulink.Bus.createMATLABStruct(prm_datatype);

%% Common values
  default_value.LoadCompensationMasses = [42000, 66700]/2;
  default_value.LoadCompensationPressures = [165000, 440000];
  default_value.TractionAccelerationTargets = [0, 1.36];
  default_value.BrakingDecelerationTargets = [0, 1.1];  % Must be positive
  default_value.TractionBrakingDemands = [0, 100];      % Between 0 and 100
  default_value.AW3TractionAccelerationTargets = [0, 1.08];
  default_value.AW3BrakingDecelerationTargets = [0, 0.8];  % Must be positive
  
end