function cellInfo = CBTC_Out_Vehicle_Onboard(varargin) 
% CBTC_OUT_VEHICLE_ONBOARD returns a cell array containing bus object information 
% 
% Optional Input: 'false' will suppress a call to Simulink.Bus.cellToObject 
%                 when the MATLAB file is executed. 
% The order of bus element attributes is as follows:
%   ElementName, Dimensions, DataType, SampleTime, Complexity, SamplingMode, DimensionsMode, Min, Max, DocUnits, Description 

suppressObject = false; 
if nargin == 1 && islogical(varargin{1}) && varargin{1} == false 
    suppressObject = true; 
elseif nargin > 1 
    error('Invalid input argument(s) encountered'); 
end 

cellInfo = { ... 
  { ... 
    'BD_CBTC_Out_Vehicle_Onboard', ... 
    '', ... 
    '', ... 
    'Auto', ... 
    '-1', {... 
{'PowerSupply', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'CabinActivation', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DriverModeSelection', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ModeSelectorPosition', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATCBypassState', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TBCPosition', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATOStartButton', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'UTOStartButton', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATCSBResetButton', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NoEmergencyBrake', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NoDoorEnableBypass', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TrainDoorClosedAndLocked', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EmergencyDoorNotOpen', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'WakeUpStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PassengerEmergencyAlarm', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'FireSmokeInd', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MechanicalCoupling', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ROSPB', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'UTBPB', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TrainIntegrity', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TCMSSpeedLimit', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TCMSSpeedLimitCause', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
    } ...
  } ...
}'; 

if ~suppressObject 
    % Create bus objects in the MATLAB base workspace 
    Simulink.Bus.cellToObject(cellInfo) 
end 
