function cellInfo = DoorSystem_Int_DoorControlIndicators(varargin) 
% DOORSYSTEM_INT_DOORCONTROLINDICATORS returns a cell array containing bus object information 
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
    'BD_DoorSystem_Int_DoorControlIndicators', ... 
    '', ... 
    '', ... 
    'Auto', ... 
    '-1', {... 
{'DoorOutsideLamp', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DoorInsideLamp', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DoorOpenPBLight', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DoorClosePBLight', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DoorsFaulty', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DCUTCMSMessages', 1, 'Bus: BD_DoorSystem_Out_Door_TCMS_Messages', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
    } ...
  } ...
}'; 

if ~suppressObject 
    % Create bus objects in the MATLAB base workspace 
    Simulink.Bus.cellToObject(cellInfo) 
end 
