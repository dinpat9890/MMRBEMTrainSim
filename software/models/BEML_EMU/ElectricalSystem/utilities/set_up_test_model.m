function set_up_test_model()
%set_up_project  Configure the parameters structure to assign to the reference model in test

    default_value = Default_Value_Prm_ElectricalSystem('BD_ElectricalSystem_Prm');

    ElectricalSystemPrm = default_value;

    prm = Simulink.Parameter(ElectricalSystemPrm);
    prm.DataType = 'Bus: BD_ElectricalSystem_Prm';

    assignin('base', 'Z_ElectricalSystemPrm', prm);

end