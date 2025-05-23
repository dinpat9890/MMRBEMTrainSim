function cellInfo = ElectricalSystem_Out_Vehicle(varargin) 
% ELECTRICALSYSTEM_OUT_VEHICLE returns a cell array containing bus object information 
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
    'BD_ElectricalSystem_Out_Vehicle', ... 
    '', ... 
    '', ... 
    'Auto', ... 
    '-1', {... 
{'OutputControlStates', 1, 'Bus: BD_ElectricalSystem_Out_Vehicle_OutputControlStates', -1, 'real', 'Sample', 'Fixed', [], [], '', sprintf('Electrical System to IO Controls Ouputs')}; ...
{'Traction', 1, 'Bus: BD_ElectricalSystem_Out_Vehicle_Traction', -1, 'real', 'Sample', 'Fixed', [], [], '', sprintf('Electrical System to TCU')}; ...
{'Braking', 1, 'Bus: BD_ElectricalSystem_Out_Vehicle_Braking', -1, 'real', 'Sample', 'Fixed', [], [], '', sprintf('Electrical System to TCU')}; ...
{'TCMS', 1, 'Bus: BD_ElectricalSystem_Out_Vehicle_TCMS', -1, 'real', 'Sample', 'Fixed', [], [], '', sprintf('Electrical System to TCMS Outputs')}; ...
{'Pneumatics', 1, 'Bus: BD_ElectricalSystem_Out_Vehicle_Pneumatics', -1, 'real', 'Sample', 'Fixed', [], [], '', sprintf('Electrical System to Pneumatics Outputs')}; ...
{'Doors', 1, 'Bus: BD_ElectricalSystem_Out_Vehicle_Doors', -1, 'real', 'Sample', 'Fixed', [], [], '', sprintf('Electrical System to Door System')}; ...
{'Pantograph', 1, 'BD_ElectricalSystem_Out_Vehicle_Pantograph', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'SignalSys', 1, 'Bus: BD_ElectricalSystem_Out_Vehicle_SignalSys', -1, 'real', 'Sample', 'Fixed', [], [], '', sprintf('Electrical System to Signal Ouputs')}; ...
{'CouplingSystem', 1, 'Bus: BD_ElectricalSystem_Out_Vehicle_Coupling', -1, 'real', 'Sample', 'Fixed', [], [], '', sprintf('Electrical System to CouplerSystem')}; ...
{'Audio', 1, 'Bus: BD_ElectricalSystem_Out_Vehicle_Audio', -1, 'real', 'Sample', 'Fixed', [], [], '', sprintf('AudioBus')}; ...
{'Scoring', 1, 'Bus: BD_ElectricalSystem_Out_Vehicle_Scoring', -1, 'real', 'Sample', 'Fixed', [], [], '', sprintf('ScoringBus')}; ...
{'MiscOutputs', 1, 'Bus: BD_ElectricalSystem_Out_Vehicle_MiscOutputs', -1, 'real', 'Sample', 'Fixed', [], [], '', sprintf('Power to PAPIS and CCTV module')}; ...
    } ...
  } ...
}'; 

if ~suppressObject 
    % Create bus objects in the MATLAB base workspace 
    Simulink.Bus.cellToObject(cellInfo) 
end 
