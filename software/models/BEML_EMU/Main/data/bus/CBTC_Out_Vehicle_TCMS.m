function cellInfo = CBTC_Out_Vehicle_TCMS(varargin) 
% CBTC_OUT_VEHICLE_TCMS returns a cell array containing bus object information 
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
    'BD_CBTC_Out_Vehicle_TCMS', ... 
    '', ... 
    '', ... 
    'Auto', ... 
    '-1', {... 
{'ATOTraction', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATOBrake', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATOTBDemand', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NoServiceBrake', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NotImmobilise', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATOState', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RollbackDetected', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LeftDoorCloseIndicator', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RightDoorCloseIndicator', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LeftDoorOpenATCReq', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RightDoorOpenATCReq', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LeftDoorCloseATCReq', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RightDoorCloseATCReq', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
    } ...
  } ...
}'; 

if ~suppressObject 
    % Create bus objects in the MATLAB base workspace 
    Simulink.Bus.cellToObject(cellInfo) 
end 
