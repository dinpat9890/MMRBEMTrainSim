function cellInfo = ElectricalSystem_Out_Vehicle_TCMS(varargin) 
% ELECTRICALSYSTEM_OUT_VEHICLE_TCMS returns a cell array containing bus object information 
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
    'BD_ElectricalSystem_Out_Vehicle_TCMS', ... 
    '', ... 
    '', ... 
    'Auto', ... 
    '-1', {... 
{'TCMSPowerAvailable', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HMIPower', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'CabActive', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ForwardDirection', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ReverseDirection', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TractionOn', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BrakeOn', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TractionSafe', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'AllRightDoorsClosed', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'AllLeftDoorsClosed', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ServiceBrakesReleased', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ParkBrakesReleased', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', sprintf('Relay powered by pressure switch')}; ...
{'ParkBrakeApplication', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ServiceBrakeApplication', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PantoLowered', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PantoRaised', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PantoPowerDetected', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ZeroSpeed', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'Speedometer', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBState', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APSKContactorState', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APSAKContactorState', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'FilterVoltage', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS1Status', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS2Status', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG1Status', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG2Status', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCGOutputVoltage', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BatteryVoltage', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BatteryCurrent', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BatteryTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG1OutputCurrent', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG2OutputCurrent', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NoBrakeTrainLine', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MotorTrainLine', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NoFSB1Line', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NoFSB2Line', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NoEB1Line', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NoEB2Line', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LineVoltage', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NoEB', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS1OutputVoltage', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS2OutputVoltage', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HLSwitchStatus', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MarkerAndTailLight', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TCMS_FL_Status', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TCMS_CallOn_Status', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'UTOOrRMLight', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PADPBStatus', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PADRStatus', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TPOR_ON', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TSDR_ON', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PowerONPBPressed', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PowerOFFPBPressed', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LeftDoorEnable', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RightDoorEnable', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LeftHoldDoorClose', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RightHoldDoorClose', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LimpHomeMode', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'FwdRevTrainLineMismatchMessage', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LowMRPressureFaultMessage', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCUPower', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS1Fault', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS2Fault', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS1Isolated', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS2Isolated', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'SaloonLightGroupStatus1', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'SaloonLightGroupStatus2', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'WFLStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'WFLOilLevelStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'WFLPump1Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'WFLPump2Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'WFLFailure', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BatteryIsolationContactor', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TrainControlContactor', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MainCompressor', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'AuxCompressor', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1SetPointTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1IntTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1ExtTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1Faulty', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1Isolated', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC2Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC2SetPointTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC2IntTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC2ExtTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC2Faulty', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC2Isolated', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PECStatus', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBbyNonCabEnabled', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBbyMC', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBbyBrakeLoop', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBbyDeadMan', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NoLineVoltage', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'D1Power', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBbyCC', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBdueToATCZeroSpeed', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVACFaults', 7, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ADDCOSStatus', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ORDCOSStatus', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MRIsolation', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MCBPAGroup', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MCB110VDCGroup', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MCBLightGroup', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MCBLightSaloonGroup', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MCBDoorGroup', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MCBBrakeGroup', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MCBAPSGroup', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MCBTCMSGroup', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MCBSignallingGroup', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBTripCommand', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'CECBTripped', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'UCCBTripped', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PANCBTripped', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ELCB1Tripped', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ELCB2Tripped', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ILCB1Tripped', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ILCB2Tripped', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APSCBTripped', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'FDUFailure', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'InternalFireAlarmTLActive', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'SmokeAlarmCABArea', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HeatAlarmEDB', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'FDUStatus', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'SFARStatus', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'UFARStatus', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BUVDR_Active', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'CMCActivationFault', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'CMCDeactivationFault', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'UW_VCB', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PantoIsolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBIsolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PantoDownPBCmd', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBTripByCI', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'CIIsolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG1Fault', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG2Fault', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG1Isolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG2Isolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG1IsolationFailed', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBbyPB', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBTripByAPS', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MCDR', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', sprintf('Mechanical Coupler Detection Relay')}; ...
{'MCDRFaulty', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ObstacleDetected', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ODDFailure', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MCBHVACGroupTripped', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PANPSR', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'Key_Switch_Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBI_ACOvercurrent', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBI_KAKContactorCI', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EmergencyDoorNotOpenStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DoorProvenLoopOK', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BrakeLoopCBTripped', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DeadmanBypassStatus', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BLCOSwitchStatus', 1, 'boolean', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'WFLIsolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
    } ...
  } ...
}'; 

if ~suppressObject 
    % Create bus objects in the MATLAB base workspace 
    Simulink.Bus.cellToObject(cellInfo) 
end 
