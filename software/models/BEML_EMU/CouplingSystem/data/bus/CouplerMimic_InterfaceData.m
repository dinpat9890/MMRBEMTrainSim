function cellInfo = CouplerMimic_InterfaceData(varargin) 
% COUPLERMIMIC_INTERFACEDATA returns a cell array containing bus object information 
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
    'BD_CouplerMimic_InterfaceData', ... 
    '', ... 
    '', ... 
    'Auto', ... 
    '-1', {... 
{'Mass', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'Time', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'Position', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'Velocity', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'Acceleration', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'Gradient', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'Radius', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TractiveForce', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BrakingForce', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'OtherCouplerForce', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'OtherCouplerForceRate', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
    } ...
  } ...
}'; 

if ~suppressObject 
    % Create bus objects in the MATLAB base workspace 
    Simulink.Bus.cellToObject(cellInfo) 
end 
