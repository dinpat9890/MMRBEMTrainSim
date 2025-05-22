function set_up_test_model()
%set_up_project  Configure the parameters structure to assign to the reference model in test

    default_value = Default_Value_Prm_PneumaticsSystem('BD_PneumaticsSystem_Prm');

    PneumaticsSystemPrm = default_value;

    prm = Simulink.Parameter(PneumaticsSystemPrm);
    prm.DataType = 'Bus: BD_PneumaticsSystem_Prm';

    assignin('base', 'Z_PneumaticsSystemPrm', prm);

end