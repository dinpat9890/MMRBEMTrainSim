function cellInfo = CouplingSystem_Out_Vehicle_Debug(varargin) 
% COUPLINGSYSTEM_OUT_VEHICLE_DEBUG returns a cell array containing bus object information 
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
    'BD_CouplingSystem_Out_Vehicle_Debug', ... 
    '', ... 
    '', ... 
    'Auto', ... 
    '-1', {... 
{'EPVState', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ElectricalHeadCommand', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MainResPressureOk', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PneuUncouplingCommand', 2, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MechUncouplingCommand', 2, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ElectUncouplingCommand', 2, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ElectCouplingCommand', 2, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VehicleOnAnEnd', 2, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'CouplerTypesAcrossUnit', 2, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DebugPerCoupler', 2, 'Bus: BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
    } ...
  } ...
}'; 

if ~suppressObject 
    % Create bus objects in the MATLAB base workspace 
    Simulink.Bus.cellToObject(cellInfo) 
end 
