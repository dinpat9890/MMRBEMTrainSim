function set_up_test_model()
%set_up_project  Configure the parameters structure to assign to the reference model in test

    default_value = Default_Value_Prm_DoorSystem('BD_DoorSystem_Prm');

    DoorSystemPrm = default_value;

    prm = Simulink.Parameter(DoorSystemPrm);
    prm.DataType = 'Bus: BD_DoorSystem_Prm';

    assignin('base', 'Z_DoorSystemPrm', prm);

end