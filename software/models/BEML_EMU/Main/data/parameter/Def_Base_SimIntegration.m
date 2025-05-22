%% Functions for created Parameter Structures
function Def_Base_SimIntegration()

assignin('base', 'MaxVehicles', 8); %Default MaxVehicles has to be the same as Prm_Vehicle dimensions
assignin('base', 'MaxAxles', 6); %Default MaxAxles has to be the same as FreightTractionSystem_Prm_Vehicle.AxleHasMotor dimensions

end