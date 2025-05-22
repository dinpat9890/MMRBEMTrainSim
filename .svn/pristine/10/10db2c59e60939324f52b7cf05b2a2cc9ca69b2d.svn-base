function set_up_test_model()
disp('Creating Bus Initial Conditions')
IOControls = Simulink.Bus.createMATLABStruct('BD_IOControls_In_Vehicle');
elements = fieldnames(IOControls(1));

for i = 1:length(elements)
    IOControls(1).(elements{i}).Mode = 1;
end

assignin('base', 'IOControlsBus', IOControls);

default_value = Default_Value_Prm_SimIntegration('BD_SimIntegration_Prm');

SimIntegrationPrm = default_value;

prm = Simulink.Parameter(SimIntegrationPrm);
prm.DataType = 'Bus: BD_SimIntegration_Prm';

assignin('base', 'Z_SimIntegrationPrm', prm);

end