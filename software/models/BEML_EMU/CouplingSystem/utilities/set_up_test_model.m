function set_up_test_model()
%set_up_project  Configure the parameters structure to assign to the reference model in test

    default_value = Default_Value_Prm_CouplingSystem('BD_CouplingSystem_Prm');

    CouplingSystemPrm = default_value;

    prm = Simulink.Parameter(CouplingSystemPrm);
    prm.DataType = 'Bus: BD_CouplingSystem_Prm';

    assignin('base', 'Z_CouplingSystemPrm', prm);

end