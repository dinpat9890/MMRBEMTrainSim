function traction_system_lib_callback(block,action)
    % traction_system_lib_callback contains callbacks for braking torque block
    
    switch action
        case 'init'
            curve_type = get_param(block, 'CurveInput');
            traction_init_callback(block, curve_type);
        case 'tractioncurveinput_param'
            curve_type = get_param(block, 'CurveInput');
            tractioncurveinput_param_callback(block, curve_type, 0);
        case 'brakecurveinput_param'
            curve_type = get_param(block, 'CurveInput');
            brakecurveinput_param_callback(block, curve_type, 0);
        case 'converter_tractioncurveinputstate_param'
            curve_type = get_param(block, 'TractionCurveInput');
            tractioncurveinput_param_callback(block, curve_type, 0);
        case 'converter_tractioncurveinputstate1_param'
            curve_type = get_param(block, 'TractionCurveInput1');
            tractioncurveinput_param_callback(block, curve_type, 6);
        case 'converter_tractioncurveinputstate2_param'
            curve_type = get_param(block, 'TractionCurveInput2');
            tractioncurveinput_param_callback(block, curve_type, 12);
        case 'converter_brakingcurveinput_param'
            curve_type = get_param(block, 'BrakingCurveInput');
            brakecurveinput_param_callback(block, curve_type, 18);
        otherwise
            disp(['traction_callback: ' action ' callback not implemented'])
    end
end

%% curve type callback
function tractioncurveinput_param_callback(block, curve_type, param_offset)
    CURVE_PARAM = param_offset + 1;
    CURVE_EQ_PARAM_1 = param_offset + 2;
    CURVE_EQ_PARAM_2 = param_offset + 3;
    CURVE_DT_PARAM_1 = param_offset + 4;
    CURVE_DT_PARAM_2 = param_offset + 5;
    CURVE_DT_PARAM_3 = param_offset + 6;
    
    vis = get_param(block,'MaskVisibilities');
    
    switch curve_type
        case 'Curve Data'
            vis{CURVE_PARAM} = 'on';
            vis{CURVE_EQ_PARAM_1} = 'off';
            vis{CURVE_EQ_PARAM_1} = 'off';
            vis{CURVE_EQ_PARAM_2} = 'off';
            vis{CURVE_DT_PARAM_1} = 'on';
            vis{CURVE_DT_PARAM_2} = 'on';
            vis{CURVE_DT_PARAM_3} = 'on';
        case 'Curve Equations'
            vis{CURVE_PARAM} = 'on';
            vis{CURVE_EQ_PARAM_1} = 'on';
            vis{CURVE_EQ_PARAM_2} = 'on';
            vis{CURVE_DT_PARAM_1} = 'off';
            vis{CURVE_DT_PARAM_2} = 'off';
            vis{CURVE_DT_PARAM_3} = 'off';
        otherwise
            disp('Should never get here')
    end
    set_param(block,'MaskVisibilities',vis);
end

%% Curve Type callback
function brakecurveinput_param_callback(block, curve_type, param_offset)
    CURVE_PARAM = param_offset + 1;
    CURVE_EQ_PARAM_1 = param_offset + 2;
    CURVE_EQ_PARAM_2 = param_offset + 3;
    CURVE_EQ_PARAM_3 = param_offset + 4;
    CURVE_DT_PARAM_1 = param_offset + 5;
    CURVE_DT_PARAM_2 = param_offset + 6;
    CURVE_DT_PARAM_3 = param_offset + 7;
    
    vis = get_param(block,'MaskVisibilities');
    
    switch curve_type
        case 'Curve Data'
            vis{CURVE_PARAM} = 'on';
            vis{CURVE_EQ_PARAM_1} = 'off';
            vis{CURVE_EQ_PARAM_2} = 'off';
            vis{CURVE_EQ_PARAM_3} = 'off';
            vis{CURVE_DT_PARAM_1} = 'on';
            vis{CURVE_DT_PARAM_2} = 'on';
            vis{CURVE_DT_PARAM_3} = 'on';
        case 'Curve Equations'
            vis{CURVE_PARAM} = 'on';
            vis{CURVE_EQ_PARAM_1} = 'on';
            vis{CURVE_EQ_PARAM_2} = 'on';
            vis{CURVE_EQ_PARAM_3} = 'on';
            vis{CURVE_DT_PARAM_1} = 'off';
            vis{CURVE_DT_PARAM_2} = 'off';
            vis{CURVE_DT_PARAM_3} = 'off';
        otherwise
            disp('Should never get here')
    end
    set_param(block,'MaskVisibilities',vis);
end

%% init callback
function traction_init_callback(block, curve_type)
    switch curve_type
        case 'Curve Data'
            set_param([block '/CurveInputType'],  'value', '1')
%             if strcmp(get_param([block '/CurveData'],  'commented'), 'on')
%                 delete_line(block, 'CurveEquations/1', 'TorqueScaling/1');
%                 add_line(block, 'CurveData/1', 'TorqueScaling/1', 'autorouting', 'on');
%                 set_param([block '/CurveData'],  'commented', 'off')
%                 set_param([block '/CurveEquations'],  'commented', 'on')
%             end
        case 'Curve Equations'
            set_param([block '/CurveInputType'],  'value', '0')
%             if strcmp(get_param([block '/CurveEquations'],  'commented'), 'on')
%                 delete_line(block, 'CurveData/1', 'TorqueScaling/1');
%                 add_line(block, 'CurveEquations/1', 'TorqueScaling/1', 'autorouting', 'on');
%                 set_param([block '/CurveEquations'],  'commented', 'off' )
%                 set_param([block '/CurveData'],  'commented', 'on' )
%             end
        otherwise
            disp('Should never get here')
    end
end
