function set_up_test_model()
%set_up_project  Configure the parameters structure to assign to the reference model in test

    default_value = Default_Value_Prm_PantographSystem('BD_PantographSystem_Prm');

    PantographSystemPrm = default_value;

    prm = Simulink.Parameter(PantographSystemPrm);
    prm.DataType = 'Bus: BD_PantographSystem_Prm';

    assignin('base', 'Z_PantographSystemPrm', prm);

end