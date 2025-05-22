%% Functions for created Parameter Structures
function [default_value] =  Default_Value_Prm_PneumaticsSystem(prm_datatype)

  if(~exist('prm_datatype', 'var'))
      prm_datatype = 'BD_PneumaticsSystem_Prm';
  end
  
  default_value = Simulink.Bus.createMATLABStruct(prm_datatype);
  
%% 	Common values all in SI units
%	All pressures relative to atmosphere
  
  %% Brake Control
  default_value.BrakeControl.LoadCompensationGains = [0.66, 1];
  default_value.BrakeControl.MaxPressure = 4.43e5;
  
  %% Main Reservoir
  default_value.MainReservoir.ResetPressure = 10e5;
  default_value.MainReservoir.MaxPressure = 12e5;
  default_value.MainReservoir.Volume = 200e-3;
  default_value.MainReservoir.SwitchONPressure = 10e5;
  default_value.MainReservoir.SwitchOFFPressure = 7.5e5;
  default_value.MainReservoir.CompressorMassFlowRate = 0.022;
  default_value.MainReservoir.BlowOffONPressure = 10.5e5;
  default_value.MainReservoir.BlowOffOFFPressure = 10e5;
  
  %% Main Reservoir Pipe
  default_value.MainReservoirPipe.ResetPressure = 10e5;
  default_value.MainReservoirPipe.SwitchONPressure = 10e5;
  default_value.MainReservoirPipe.SwitchOFFPressure = 7.5e5;
  
  %% Sanding
  default_value.Sanding.SwitchONPressure = 3.8e5;
  default_value.Sanding.SwitchOFFPressure = 3.6e5;
  
  %% Air Suspension
  default_value.AirSuspension.LoadCompensationMasses = [42000, 66700]/2;
  default_value.AirSuspension.LoadCompensationPressures = [165000, 440000];
  default_value.AirSuspension.MaxPressure = 5.1e5;
  default_value.AirSuspension.Volume = 70e-3;
  default_value.AirSuspension.SwitchONPressure = 2.2e5;
  default_value.AirSuspension.SwitchOFFPressure = 1.8e5;
  
  %% Horn
  default_value.Horn.SwitchONPressure = 1.4e5;
  
  %% Auxiliary Reservoir
  default_value.AuxiliaryReservoir.ResetPressure = 10e5;
  default_value.AuxiliaryReservoir.MaxPressure = 10e5;
  default_value.AuxiliaryReservoir.Volume = 25e-3;
  default_value.AuxiliaryReservoir.SwitchONPressure = 7e5;
  default_value.AuxiliaryReservoir.SwitchOFFPressure = 6e5;
  default_value.AuxiliaryReservoir.CompressorMassFlowRate = 0.0014;
  default_value.AuxiliaryReservoir.BlowOffONPressure = 10.2e5;
  default_value.AuxiliaryReservoir.BlowOffOFFPressure = 10e5;
  
  %% Pantograph Cylinder
  default_value.Pantograph.ResetPressure = 0;
  default_value.Pantograph.MaxPressure = 10e5;
  default_value.Pantograph.Volume = 3e-3;
  default_value.Pantograph.SwitchONPressure = 3.8e5;
  default_value.Pantograph.SwitchOFFPressure = 2.8e5;
  default_value.Pantograph.ORDSwitchONPressure = 3e5;
  default_value.Pantograph.ORDSwitchOFFPressure = 2.4e5;
  
  %% VCB Cylinder
  default_value.VCB.ResetPressure = 0;
  default_value.VCB.MaxPressure = 10e5;
  default_value.VCB.Volume = 0.5e-3;
  default_value.VCB.SwitchONPressure = 4.35e5;
  default_value.VCB.SwitchOFFPressure = 3.85e5;
  
  %% Brake Supply Reservoir
  default_value.BrakeReservoir.ResetPressure = 10e5;
  default_value.BrakeReservoir.MaxPressure = 12e5;
  default_value.BrakeReservoir.Volume = 100e-3;
  default_value.BrakeReservoir.SwitchONPressure = 6.5e5;
  default_value.BrakeReservoir.SwitchOFFPressure = 5.5e5;
  
  %% Brake Cylinder
  default_value.BrakeCylinder.BrakeCylindersPerBogieAxle = [2, 2];
  default_value.BrakeCylinder.ResetPressure = 0;
  default_value.BrakeCylinder.MaxPressure = 6e5;
  default_value.BrakeCylinder.Volume = 12.5e-3;
  default_value.BrakeCylinder.SwitchONPressure = 0.6e5;
  default_value.BrakeCylinder.SwitchOFFPressure = 0.3e5;
  
  %% Park Brakes
  default_value.ParkBrakes.ParkBrakesPerBogieAxle = [1, 1];
  default_value.ParkBrakes.ParkBrakePressures = [3e5, 4.8e5];
  default_value.ParkBrakes.ParkBrakeForces = [31500, 0];
  default_value.ParkBrakes.SwitchONPressure = 4.8e5;
  default_value.ParkBrakes.SwitchOFFPressure = 3.8e5;

end