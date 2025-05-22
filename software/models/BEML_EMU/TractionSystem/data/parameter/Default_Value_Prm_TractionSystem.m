%% Functions for created Parameter Structures
function [default_value] =  Default_Value_Prm_TractionSystem(prm_datatype)

  if(~exist('prm_datatype', 'var'))
      prm_datatype = 'BD_TractionSystem_Prm';
  end

default_value = Simulink.Bus.createMATLABStruct(prm_datatype);

%% Common values
  default_value.DesignMaxTractionTorque = 1091; % Ref. MMRBEM Technical Specification and Drawing of Traction Motor
  default_value.DesignMaxTractionPower = 210.12e3; % Continuous Rating Ref. MMRBEM Technical Specification and Drawing of Traction Motor
  default_value.DesignTimeToMaxTraction = 1.75;
  default_value.DesignMaxBrakingTorque = 1570; % Ref. MMRBEM Technical Specification and Drawing of Traction Motor
  default_value.DesignMaxBrakingPower = 430e3;
  default_value.BrakeFadeRampDownSpeeds = [12, 32];
  default_value.DesignGearingRatio = 6.79;    % Ref. MMRBEM Technical Specification and Drawing of Traction Motor
  default_value.DesignGearingEfficiency = 0.97;
  default_value.DesignWheelDiameter = 0.820;  % Half Worn Wheel Ref. MMRBEM Technical Specification and Drawing of Traction Motor
  default_value.DesignBogieMotorCount = 2;
  default_value.AxleHasMotor = [1 1];
  default_value.EmergencyBrakeDeactivatesDynamicBrake = 1;
  default_value.WheelSlipProtectionEnable = 1;
  default_value.WheelSlideProtectionEnable = 1;
  default_value.JerkLimit = 0.75;
  default_value.MaxContinuousSlipBeforeTractionCutout = 10;
  default_value.MaxContinuousSlideBeforeBrakeCutout = 10;
  
end

%   %% Traction Values
%   default_value.TractiveEffortData.ContourCount = 9;
%   Traction_0 = ...
%     [  0         0;
%      329.906     0 ];
% 
%   Traction_1 = ...
%     [  0        93.2965;
%        5.63255  85.4277;
%        7.24185  73.2307;
%        8.85115  61.6876;
%       10.4604   52.1818;
%       12.0697   46.7372;
%       12.8744   43.7747;
%       14.4837   38.4903;
%       16.093    34.2956;
%       24.1395   22.0364;
%       32.186    16.058;
%       48.279    10.3376;
%       64.372     7.5486;
%      329.906     2.00169 ];
% 
%   Traction_2 = ...
%     [  0       185.979;
%        5.87394 185.979;
%        8.97989 142.342;
%       12.9871  109.159;
%       16.093    86.9178;
%       22.5302   60.6734;
%       28.9674   48.4854;
%       38.6232   36.3863;
%       48.279    28.2906;
%       64.372    20.2393;
%       80.465    18.1931;
%       96.558    14.1453;
%      112.651    12.0991;
%      329.906     4.22579 ];
%   
%   Traction_3 = ...
%     [  0       278.991;
%        8.0465  278.991;
%       11.7479  213.514;
%       14.8538  177.928;
%       18.5713  142.342;
%       22.5946  117.255;
%       28.9674   90.9657;
%       38.6232   68.7247;
%       48.279    56.6256;
%       64.372    40.4341;
%       80.465    32.3384;
%       96.558    28.2906;
%      112.651    24.2427;
%      329.906     8.00676 ];
% 
%   Traction_4 = ...
%     [  0       372.047;
%        8.0465  372.047;
%       11.1354  311.374;
%       14.5159  246.653;
%       16.7045  214.314;
%       20.422   177.928;
%       25.3787  145.585;
%       32.186   113.207;
%       42.0832   84.9161;
%       52.608    68.7247;
%       64.372    56.6256;
%       80.465    46.4837;
%       96.558    38.1656;
%      112.651    32.3384;
%      329.906    10.6757  ];
% 
%   Traction_5 = ...
%     [  0       465.015;
%        9.26957 465.015;
%       12.6813  363.907;
%       17.6379  266.892;
%       22.2727  210.266;
%       30.9468  155.687;
%       39.621   121.302;
%       48.279    97.0152;
%       64.372    74.8187;
%       80.465    60.6734;
%       96.558    52.5777;
%      112.651    44.482;
%      329.906    14.9015  ];
% 
%   Traction_6 = ...
%     [  0       606.557;
%       10.5248  606.574;
%       12.0537  572.212;
%       14.2423  485.299;
%       18.2656  382.145;
%       21.0336  335.617;
%       24.751   287.131;
%       28.4685  248.699;
%       33.4252  214.314;
%       39.621   177.928;
%       48.279   147.591;
%       64.372   109.203;
%       80.465    88.964;
%       96.558    72.7726;
%      112.651    64.7213;
%      329.906    21.3514  ];
% 
%   Traction_7 = ...
%     [  0       746.052;
%       11.1364  746.052;
%       14.2423  598.505;
%       18.5552  473.111;
%       24.4453  351.853;
%       29.0801  295.183;
%       35.2759  242.649;
%       42.4051  202.171;
%       48.279   179.93;
%       64.372   135.448;
%       80.465   108.18;
%       96.558    90.9657;
%      112.651    78.8221;
%      329.906    26.6892  ];
% 
%   Traction_8 = ...
%     [  0       837.062;
%       12.8583  837.062;
%       16.7045  622.748;
%       22.3371  460.967;
%       29.0801  355.856;
%       37.1266  279.036;
%       48.279   214.314;
%       59.0935  177.928;
%       80.465   131.4;
%      112.651    93.0119;
%      329.906    31.1374  ];
% 
%   % The bock expects percentage as the input so we convert form notch to %.
%   default_value.TractiveEffortData.ContourDemand(1:default_value.TractiveEffortData.ContourCount) = 0:100/8:100;
%   default_value.TractiveEffortData.ContourSize(1:default_value.TractiveEffortData.ContourCount) = ...
%     [length(Traction_0);
%      length(Traction_1);
%      length(Traction_2);
%      length(Traction_3);
%      length(Traction_4);
%      length(Traction_5);
%      length(Traction_6);
%      length(Traction_7);
%      length(Traction_8)];
% 
%   default_value.TractiveEffortData.ContourValues(1, :, 1:length(Traction_0)) = convert_contour_units(Traction_0, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.TractiveEffortData.ContourValues(2, :, 1:length(Traction_1)) = convert_contour_units(Traction_1, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.TractiveEffortData.ContourValues(3, :, 1:length(Traction_2)) = convert_contour_units(Traction_2, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.TractiveEffortData.ContourValues(4, :, 1:length(Traction_3)) = convert_contour_units(Traction_3, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.TractiveEffortData.ContourValues(5, :, 1:length(Traction_4)) = convert_contour_units(Traction_4, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.TractiveEffortData.ContourValues(6, :, 1:length(Traction_5)) = convert_contour_units(Traction_5, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.TractiveEffortData.ContourValues(7, :, 1:length(Traction_6)) = convert_contour_units(Traction_6, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.TractiveEffortData.ContourValues(8, :, 1:length(Traction_7)) = convert_contour_units(Traction_7, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.TractiveEffortData.ContourValues(9, :, 1:length(Traction_8)) = convert_contour_units(Traction_8, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%      
%   for i_tcurve = 1:9
%     torque = default_value.TractiveEffortData.ContourValues(i_tcurve, 2, :);
%     power = torque.*(default_value.TractiveEffortData.ContourValues(i_tcurve, 1, :));
%     default_value.TractiveEffortData.ContourMaximumTorque(i_tcurve) = max(torque);
%     default_value.TractiveEffortData.ContourMaximumPower(i_tcurve) = max(power);
%   end
%   
%   %% Dynamic Braking Values
%   default_value.DynamicBrakingEffortData.ContourCount = 8;
%   Braking_0 = ...
%     [  0         0;
%      329.906     2.00169 ];
% 
%   Braking_1 = ...
%     [  0         0;
%        0.901208 15.3908;
%       32.7975   15.3908;
%       36.0483   13.3001;
%       40.2325   11.8322;
%       48.279     9.47467;
%       64.372     7.07264;
%       80.456     5.91611;
%       96.558     4.71509;
%      112.651     3.51408;
%      329.906     0.88964 ];
% 
%   Braking_2 = ...
%     [  0         0;
%        0.917301 71.1712;
%       32.7975   71.1712;
%       40.2325   56.937;
%       48.279    48.6188;
%       56.937    41.5017;
%       64.372    36.7866;
%       72.4185   32.027;
%       80.465    28.4685;
%       96.558    23.7089;
%      112.651    20.1503;
%      329.906     6.80575 ];
% 
% 
%   Braking_3 = ...
%     [  0          0;
%        0.917301 145.901;
%       32.7975   145.901;
%       40.844    117.432;
%       51.6746    90.076;
%       68.0895    68.8137;
%       86.0332    55.7359;
%      112.651     41.5017;
%      329.906     14.2342 ];
% 
%   Braking_4 = ...
%     [  0          0;
%        0.917301 218.006;
%       32.7975   218.006;
%       36.8208   196.877;
%       43.95     163.694;
%       56.0197   126.907;
%       66.8503   106.712;
%       83.5549    85.4054;
%       99.3421    72.3722;
%      112.651     64.0541;
%      329.906     21.7962 ];
% 
%   Braking_5 = ...
%     [  0          0;
%        0.917301 297.718;
%       32.7975   297.718;
%       41.1498   238.424;
%       48.279    202.838;
%       59.4154   163.694;
%       69.9402   138.784;
%       82.6376   118.589;
%       94.997    103.198;
%      112.651     87.763;
%      329.906     29.5805 ];
% 
%   Braking_6 = ...
%     [  0          0;
%        0.917301 395;
%       32.9795   395;
%       40.844    319.069;
%       48.5848   266.892;
%       58.1762   222.988;
%       70.7836   182.688;
%       84.4722   151.817;
%       99.6479   129.309;
%      112.651    116.231;
%      329.906     38.6993 ];
% 
%   Braking_7 = ...
%     [  0         0;
%        1.22307 466.171;
%       32.7975  466.171;
%       39.621   400.027;
%       48.279   320.27;
%       57.2428  266.892;
%       69.0068  221.818;
%       81.7042  187.403;
%       99.0363  154.175;
%      112.651   137.583;
%      329.906    44.0372 ];
%      
%   % The curve for notch 7 and 8 are the same so we only specicy the curve for notch 7.
%   % The bock expects percentage as the input so we convert form notch to %.
%   % So now our max value is 7/8ths of 100%
%   default_value.DynamicBrakingEffortData.ContourDemand(1:default_value.DynamicBrakingEffortData.ContourCount) = 0:100/8:7/8*100;
%   default_value.DynamicBrakingEffortData.ContourSize(1:default_value.DynamicBrakingEffortData.ContourCount) = ...
%     [length(Braking_0);
%      length(Braking_1);
%      length(Braking_2);
%      length(Braking_3);
%      length(Braking_4);
%      length(Braking_5);
%      length(Braking_6);
%      length(Braking_7)];
%   
%   default_value.DynamicBrakingEffortData.ContourValues(1, :, 1:length(Braking_0)) = convert_contour_units(Braking_0, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.DynamicBrakingEffortData.ContourValues(2, :, 1:length(Braking_1)) = convert_contour_units(Braking_1, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.DynamicBrakingEffortData.ContourValues(3, :, 1:length(Braking_2)) = convert_contour_units(Braking_2, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.DynamicBrakingEffortData.ContourValues(4, :, 1:length(Braking_3)) = convert_contour_units(Braking_3, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.DynamicBrakingEffortData.ContourValues(5, :, 1:length(Braking_4)) = convert_contour_units(Braking_4, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.DynamicBrakingEffortData.ContourValues(6, :, 1:length(Braking_5)) = convert_contour_units(Braking_5, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.DynamicBrakingEffortData.ContourValues(7, :, 1:length(Braking_6)) = convert_contour_units(Braking_6, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
%   default_value.DynamicBrakingEffortData.ContourValues(8, :, 1:length(Braking_7)) = convert_contour_units(Braking_7, default_value.DesignMotorCount, default_value.DesignWheelDiameter, default_value.DesignGearingRatio)';
% 
%   for i_dbcurve = 1:8 
%     torque = default_value.DynamicBrakingEffortData.ContourValues(i_dbcurve, 2, :);
%     power = torque.*(default_value.DynamicBrakingEffortData.ContourValues(i_dbcurve, 1, :));
%     default_value.DynamicBrakingEffortData.ContourMaximumTorque(i_dbcurve) = max(torque);
%     default_value.DynamicBrakingEffortData.ContourMaximumPower(i_dbcurve) = max(power);
%   end
% end
% 
% function converted_data = convert_contour_units(contour_data, DesignMotorCount, DesignWheelDiameter, DesignGearingRatio)
%   % conversion array is [km/h(wheel)→rad/s(motor), kN(wheel)→Nm(motor)]
%   speed_conversion = 1/(3.6*(DesignWheelDiameter/2))*DesignGearingRatio;
%   torque_conversion = 1000/DesignMotorCount*(DesignWheelDiameter/2)/DesignGearingRatio;
%   conversion = [speed_conversion, torque_conversion];
%   converted_data = contour_data.*conversion;
% end  
  
