function cellInfo = TCMSSystem_In_Vehicle_CBTC(varargin) 
% TCMSSYSTEM_IN_VEHICLE_CBTC returns a cell array containing bus object information 
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
    'BD_TCMSSystem_In_Vehicle_CBTC', ... 
    '', ... 
    '', ... 
    'Auto', ... 
    '-1', {... 
{'LeftDoorOpenRequest', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RightDoorOpenRequest', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LeftDoorCloseRequest', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RightDoorCloseRequest', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATOTBDemandPct', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NoServiceBrakeOrder', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATOTraction', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATOBraking', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NotImmobilise', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DriverModeSelection', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATCBypassState', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LeftSideDoorEnable', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RightSideDoorEnable', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATCWakeup', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RollbackDetected', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LeftDoorCloseIndicator', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RightDoorCloseIndicator', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
    } ...
  } ...
}'; 

if ~suppressObject 
    % Create bus objects in the MATLAB base workspace 
    Simulink.Bus.cellToObject(cellInfo) 
end 
