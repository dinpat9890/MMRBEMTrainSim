function set_up_test_model()
%set_up_project  Configure the parameters structure to assign to the reference model in test

    default_value = Default_Value_Prm_TractionSystem('BD_TractionSystem_Prm');

    TractionSystemPrm = default_value;

    prm = Simulink.Parameter(TractionSystemPrm);
    prm.DataType = 'Bus: BD_TractionSystem_Prm';

    assignin('base', 'Z_TractionSystemPrm', prm);

end