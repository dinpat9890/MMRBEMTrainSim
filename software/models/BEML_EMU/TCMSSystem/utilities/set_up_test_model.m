function set_up_test_model()
%set_up_project  Configure the parameters structure to assign to the reference model in test

    default_value = Default_Value_Prm_TCMSSystem('BD_TCMSSystem_Prm');

    TCMSSystemPrm = default_value;

    prm = Simulink.Parameter(TCMSSystemPrm);
    prm.DataType = 'Bus: BD_TCMSSystem_Prm';

    assignin('base', 'Z_TCMSSystemPrm', prm);

end