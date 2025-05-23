function cellInfo = TCMSSystem_Out_Vehicle_Display_ElectricalSystem(varargin) 
% TCMSSYSTEM_OUT_VEHICLE_DISPLAY_ELECTRICALSYSTEM returns a cell array containing bus object information 
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
    'BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem', ... 
    '', ... 
    '', ... 
    'Auto', ... 
    '-1', {... 
{'HMIPower', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'CabActive', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TBCPosition', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'UTOMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATOMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATPMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ROSMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RMRMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATBMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RMFMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS1Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS2Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS1Active', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS2Active', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS1Fault', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS2Fault', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS1Isolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS2Isolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS1OutputVoltage', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APS2OutputVoltage', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'AK1Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'K1Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'AK2Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'K2Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG1Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG2Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG1Fault', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG2Fault', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCGOutputVoltage', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BatteryVoltage', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TotalOutputCurrent', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'OutputCurrent', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BatteryCurrent', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BatteryTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG1OutputCurrent', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG2OutputCurrent', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATCBypassMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BrakeTrainLineStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MotorTrainLineStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'FSB1LineStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'FSB2LineStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EB1LineStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EB2LineStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBFault', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBIsolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBState', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'LineVoltage', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'Odometer', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TotalWeight', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'OperationalMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RescueMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'JogMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EnableToRun', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ShoreSupply', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'Coupled', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBTripCommandStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'StandbyMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'SaloonLightGroupStatus1', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'SaloonLightGroupStatus2', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'FlasherLightStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'WFLStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'WFLFault', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'WFLOilLevelStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'WFLPump1Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'WFLPump2Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TrainControlContactor', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BatteryIsolationContactor', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DUMMY_HVAC_SCREEN_SIGNALS_BELOW', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC2Status', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1ReducedMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC2ReducedMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1Fault', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC2Fault', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1Isolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC2Isolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1SetPointTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC2SetPointTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1InternalTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC2InternalTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1ExternalTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC2ExternalTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DUMMY_MV_SCREEN_SIGNALS_BELOW', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MainCompressor', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PowerExtensionContactor', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'AuxCompressor', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DUMMY_TCMS_ECN_SCREEN_SIGNALS_BELOW', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ComponentSwitchStatusA', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ComponentSwitchStatusB', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ComponentSwitchStatusC', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TrainEthernetRepeaterStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TrainBackboneNodeStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ECNALGStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DUMMY_FIRE_DETECTION_SCREEN_SIGNALS_BELOW', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'UnderframeFireAlarmStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'SaloonFireAlarmStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'SensorFireAlarmStatus', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'FireDetectionUnit', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ExternalSmoke', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'InternalFire', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DUMMY_EB_INTERLOCK_SCREEN_SIGNALS_BELOW', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBForNonCabEnabled', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBDueToATCZeroSpeed', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBByCC', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBForNonDirectionSelected', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBDueToPushButton', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBByMC', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBByBrakeLoop', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EBDueToDeadman', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DUMMY_PANTO_INTERLOCK_SCREEN_SIGNALS_BELOW', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EGSOperatedACPM', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EGSOperatedOSPM', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DUMMY_VCB_INTERLOCK_SCREEN_SIGNALS_BELOW', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TransformerOilTemperature', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBOpenedByACOverCurrent', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBOpenedByMTrProtection', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBOpenedByICM', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBOpenedByICDM', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'VCBOpenedByAPS', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'NoLineVoltage', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'APSKAKContactor', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'RCCBTripped', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'SupplyFanTripped', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ExtSmokeDetectedinHVAC', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EmergencyInverterTripped', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVACFireMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVACReducedMode', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVACGroupMCBTripped', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVACMajorFault', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'SmokeAlarmCABArea', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HeatAlarmEDB', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'FDUFault', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'SFARFault', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG1Isolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG2Isolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BCG1IsolationFailed', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'PowerOffPressed', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ObstructionDetectedLeft', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ObstructionDetectedRight', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DerailmentDetectedLeft', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DerailmentDetectedRight', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HighVoltageMissing', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'CabNotEnabled', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DrivingModeNotOK', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TrainDirectionMissing', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ATCStatusNotOK', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TrainReadyNotOK', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TooManyRPressureCutout', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TooManyEPICCutout', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'TooManyBogieIsolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ZVRDNotActive', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'MotoringTLDeenergized', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BrakeLoopOpenTL', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ParkingBrakeActiveTL', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'DoorLoopOpenTL', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'ADDIntervention', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'BrakeLoopCBTripped', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'WFLIsolated', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'HVAC1FireSmokeActive', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'EDBHeatAlarmActive', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
{'CABSmokeAlarmActive', 1, 'double', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
    } ...
  } ...
}'; 

if ~suppressObject 
    % Create bus objects in the MATLAB base workspace 
    Simulink.Bus.cellToObject(cellInfo) 
end 
