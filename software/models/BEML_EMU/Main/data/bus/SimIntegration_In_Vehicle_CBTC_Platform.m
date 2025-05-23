function cellInfo = SimIntegration_In_Vehicle_CBTC_Platform(varargin) 
% SIMINTEGRATION_IN_VEHICLE_CBTC_PLATFORM returns a cell array containing bus object information 
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
    'BD_SimIntegration_In_Vehicle_CBTC_Platform', ... 
    '', ... 
    '', ... 
    'Auto', ... 
    '-1', {... 
{'LeftSideDoorEnable', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RightSideDoorEnable', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'OpenLeftTrainDoors', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'OpenRightTrainDoors', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'CloseLeftTrainDoors', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'CloseRightTrainDoors', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LeftDoorOpenIndicator', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RightDoorOpenIndicator', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LeftDoorReleaseIndicator', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RightDoorReleaseIndicator', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'UndergroundSection', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LeftDoorCloseIndicator', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RightDoorCloseIndicator', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
    } ...
  } ...
}'; 

if ~suppressObject 
    % Create bus objects in the MATLAB base workspace 
    Simulink.Bus.cellToObject(cellInfo) 
end 
