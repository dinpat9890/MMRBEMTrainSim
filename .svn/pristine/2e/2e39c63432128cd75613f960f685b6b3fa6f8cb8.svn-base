%% Functions for created Parameter Structures
function [default_value] =  Default_Value_Prm_DoorSystem(prm_datatype)

  if(~exist('prm_datatype', 'var'))
      prm_datatype = 'BD_DoorSystem_Prm';
  end

default_value = Simulink.Bus.createMATLABStruct(prm_datatype);

%% Common values
  default_value.DoorOpenTime = 2.1;
  default_value.DoorCloseTime = 3;
  default_value.DoorOpenAlarmTime = 5;
  default_value.DoorCloseAlarmTime = 5;
  default_value.DoorOpenDelay = 0.1;
  default_value.DoorCloseDelay = 3;

end

