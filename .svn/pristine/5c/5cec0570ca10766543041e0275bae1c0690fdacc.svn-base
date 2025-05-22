%% Functions for created Parameter Structures
function [default_value] =  Default_Value_Brakes_Prm()

  prm_datatype = 'BD_TrainBrakes_Prm_Vehicle';

  default_value = Simulink.Bus.createMATLABStruct(prm_datatype);
  
  default_value.Equipment.AxleBrakeConfig = [1; 1; 2; 2; 0; 0;];
  default_value.Equipment.AxleParkBrakeConfig = [1; 2; 3; 4; 0; 0;];
  default_value.Equipment.NumberOfBrakeCylindersPerAxle = 2;
  default_value.Equipment.BrakeShoeType = BrakeShoeType.Composition;
  
  default_value.ThermalModel.BrakeInitialTemperature = 298;
  default_value.ThermalModel.BrakeSpecificHeat = 500;
  default_value.ThermalModel.BrakeEmissivity = 0.30;
  default_value.ThermalModel.BrakeThermalMass = 300;
  
  default_value.BrakeFade.BrakeTemperatures = [273; 323; 373; 423; 473; 523; 573; 623; 673; 723];
  default_value.BrakeFade.BrakeEfficiencies = [1; 1; 1; 1; 1; 1; 1; 1; 1; 1];
  
  default_value.BrakeCylinder.BrakeCylinderPreload = 5000.0;
  default_value.BrakeCylinder.BrakeCylinderArea = 0.024;
  default_value.BrakeCylinder.BrakeBeamFactor = 4.35;
  default_value.BrakeCylinder.BrakeEfficiency = 95;
  
  default_value.BrakeDisc.DiscBrakeRatio = 0;
  
  default_value.ParkBrakes.ParkBrakePressures = [3.8e5, 4.8e5];
  default_value.ParkBrakes.AxleParkBrakePistonForces = [31500, 0];

end