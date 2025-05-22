function set_up_test_modelCB_6Car(TrainConfiguration)

    %% Set defaults
    if(~exist('TrainConfiguration', 'var'))
        TrainConfiguration = table;
        TrainConfiguration.Class = ["DM", "T", "M","M", "T", "DM"]';
        TrainConfiguration.Orientation = [1 1 1 2 2 2]';
        TrainConfiguration.Index = [0 1 2 3 4 5]';
        
    end
    assignin('base', 'MaxVehicles', 6); %Default MaxVehicles
    MaxVehicles = evalin('base', 'MaxVehicles');
    
    fprintf('Creating Common Config Bus\n');
    createCommonConfigBus(MaxVehicles, TrainConfiguration);
    
    fprintf('Creating a train of size %i With the first %i vehicles enabled\n', MaxVehicles, height(TrainConfiguration));
    createVehicleInputsBus(MaxVehicles);
    
    %assignin('base', 'Z_TestFromScript', 0);
    %% Disp settings
end

%% Functions
function createVehicleInputsBus(MaxVehicles)
%createVehicleInputsBus(MaxVehicles) creates the VehicleInputsBusInit which is the
% init for the data store. 
% Also creases VehicleInputsBus, which can be
% edited at any time and can change the value of any input that is not being
% assigned indidually in a data store write.
    IOControlsBus = createIOControlsBus();
    VehicleInputsBus = Simulink.Bus.createMATLABStruct('BD_SimIntegration_In_Vehicle');
%     VehicleInputsBus.IOControls = IOControlsBus;
    VehicleInputsBus.Environment = Simulink.Bus.createMATLABStruct('BD_SimIntegration_In_Vehicle_Environment');
    
    % Needs to be size of vehicle since VehicleInputsBus being used in
    % constant block
    VehicleInputsBus(1:MaxVehicles,1) = VehicleInputsBus;
    
    assignin('base', 'Z_VehicleInputsBusInit', VehicleInputsBus);
    assignin('base', 'Z_VehicleInputsBus', VehicleInputsBus);
    assignin('base', 'Z_IOControlsBusInit', IOControlsBus);
end


function IOControlsBus = createIOControlsBus()
%createIOControlsBus for init, and set mode to 1 for all controls. 
    IOControlsBus = Simulink.Bus.createMATLABStruct('BD_IOControls_In_Vehicle');
    busFieldnames = fieldnames(IOControlsBus(1));
    for i = 1:length(busFieldnames)
        IOControlsBus(1).(busFieldnames{i}).Mode = 1;
    end
end

function createCommonConfigBus(MaxVehicles, TrainConfiguration)
    %% Check for errors   
    if height(TrainConfiguration) > MaxVehicles
       error('Length of TrainConfiguration greater than MaxVehicles')
    end

    %% Get Common Config Bus
    SimIntegration_CfgVehBus = Simulink.Bus.createMATLABStruct('BD_SimIntegration_Cfg_Vehicle');
    CommonCfgVehBus = SimIntegration_CfgVehBus.Common;
	DynamicsCfgVehBus = SimIntegration_CfgVehBus.Dynamics;
    BrakesCfgVehBus = SimIntegration_CfgVehBus.Brakes;

    fprintf('Overall train configuration is...\n%s\n', TrainConfiguration.Class')

    %% Create Vehicle Types
    % Put things that are common across vehicles here
    CommonCfgVehBus.Height = 4.08;
    CommonCfgVehBus.Width = 3.2;
    CommonCfgVehBus.WheelDiameter = 0.84;
    CommonCfgVehBus.LoadingMass = 0;
    CommonCfgVehBus.Enabled = false;
    
    
    AW0 = [42000 42000 42000 42000 42000 42000 42000 42000];
    AW1 = [44900 45640 45640 45640 45640 45640 45640 44900];
    AW2 = [61500 61500 61500 61500 61500 61500 61500 61500];
    AW3 = [66700 66700 66700 66700 66700 66700 66700 66700];
    
    Mass = AW0;
    
    %%
    CfgBus.DM = SimIntegration_CfgVehBus;
    CfgBus.DM.Common.Length = 22;
    CfgBus.DM.Common.Type = VehicleType.Motor;
    CfgBus.DM.Common.Class = 101;
    CfgBus.DM.Common.TareMass = AW0(1);
    CfgBus.DM.Common.GrossMass = AW3(1);
    CfgBus.DM.Common.LoadingMass = Mass(1) - AW0(1);
    CfgBus.DM.Common.NumberOfAxles = 4;
    CfgBus.DM.Common.NumberOfDrivenAxles = 4;
    CfgBus.DM.Common.NumberOfBrakedAxles = 4;
	CfgBus.DM.Brakes.BrakeShoeFrictionCoeff = 0.35;
    
    CfgBus.T = SimIntegration_CfgVehBus;
    CfgBus.T.Common.Length = 22;
    CfgBus.T.Common.Type = VehicleType.Trailer;
    CfgBus.T.Common.Class = 102;
    CfgBus.T.Common.TareMass = AW0(2);
    CfgBus.T.Common.GrossMass = AW3(2);
    CfgBus.T.Common.LoadingMass = Mass(2) - AW0(2);
    CfgBus.T.Common.NumberOfAxles = 4;
    CfgBus.T.Common.NumberOfDrivenAxles = 0;
    CfgBus.T.Common.NumberOfBrakedAxles = 4;
    CfgBus.T.Brakes.BrakeShoeFrictionCoeff = 0.35;
	
    CfgBus.M = SimIntegration_CfgVehBus;
    CfgBus.M.Common.Length = 22;
    CfgBus.M.Common.Type = VehicleType.Motor;
    CfgBus.M.Common.Class = 103;
    CfgBus.M.Common.TareMass = AW0(3);
    CfgBus.M.Common.GrossMass = AW3(3);
    CfgBus.M.Common.LoadingMass = Mass(3) - AW0(3);
    CfgBus.M.Common.NumberOfAxles = 4;
    CfgBus.M.Common.NumberOfDrivenAxles = 4;
    CfgBus.M.Common.NumberOfBrakedAxles = 4;
    CfgBus.M.Brakes.BrakeShoeFrictionCoeff = 0.35;
	
	
	%BrakesCfgVehBus.BrakeShoeCoefficientCalculationMethod = BrakeShoeCoefficientCalculationMethod.CustomBSC;
    BrakesCfgVehBus.BrakeShoeFrictionCoeff = 0.35;
    BrakesCfgVehBus.BrakeFadeEnable = 1;
    BrakesCfgVehBus.BrakeTemperatureEnable = 1;
    
    DynamicsCfgVehBus.EnableDampingAdjustmentByMass = true;
    DynamicsCfgVehBus.DampingAdjustmentDesignMass = 158000;
	
	
	SimIntegration_CfgVehBus.Common = CommonCfgVehBus;
	SimIntegration_CfgVehBus.Dynamics = DynamicsCfgVehBus;
    SimIntegration_CfgVehBus.Brakes = BrakesCfgVehBus;

	
    %% Create Train Common Config Bus

    % Prepopulate for preformance
    % If there are more vehicles in MaxVehicles then TrainConfigurationByClass
    % those extra vehicles will not be enabled via logic earlier on
    CfgVehBus = repmat(SimIntegration_CfgVehBus,MaxVehicles,1);

    for i = 1:height(TrainConfiguration)
        class = TrainConfiguration.Class(i);
        if not(isfield(CfgBus, class))
            error(sprintf('Vehicle Class %s is not in CfgBus', class))
        end
        
        CfgVehBus(i) = CfgBus.(class);
        CfgVehBus(i).Common.Orientation = TrainConfiguration.Orientation(i);
        CfgVehBus(i).Common.Enabled = true;
    end

    assignin('base', 'Z_CfgVehBus', CfgVehBus);
    
    test_workspace_data_load();
end
