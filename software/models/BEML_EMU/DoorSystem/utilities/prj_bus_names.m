function [bus_names, bus_prefix, bus_dir] = prj_bus_names()

bus_names = { ...
    'DoorSystem_Cfg_Door',...
    'DoorSystem_In_Door',...
    'DoorSystem_In_Door_ElectricalSignals',...
    'DoorSystem_In_Emergency_Door',...
    'DoorSystem_In_Door_InputControlStates',...
    'DoorSystem_In_Door_Faults',...
    'DoorSystem_In_Overrides',...
	'DoorSystem_In_Vehicle',...
	'DoorSystem_In_Vehicle_TrainWires',...
    'DoorSystem_Int_DoorControlAudio'...
    'DoorSystem_Int_DoorControlIndicators'...
    'DoorSystem_Out_Door',...
    'DoorSystem_Out_Door_Audio',...
    'DoorSystem_Out_Door_ElectricalSignals',...
    'DoorSystem_Out_Emergency_Door',...
    'DoorSystem_Out_Door_OutputControlStates',...
    'DoorSystem_Out_Door_TCMS',...
    'DoorSystem_Out_Door_TCMS_Messages',...
	'DoorSystem_Out_Vehicle'...
	'DoorSystem_Out_Vehicle_ElectricalSignals'...
	'DoorSystem_Prm'...
    };
bus_prefix = 'BD_';

%find the bus_dir based on the relative
%path to this file (prj_bus_names.m)
m_dir = fileparts(mfilename('fullpath'));
bus_dir = fullfile(m_dir, '../data/bus');
%  'DoorSystem_In_DCU_Overrides',...
end