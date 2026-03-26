Simulink.Bus.cellToObject({
{
    'cm22PTInverterCurrentuvwArray', {
	{'I_u',	1,'double', -1, 'real', 'Sample'};
	{'I_v',	1,'double', -1, 'real', 'Sample'};
	{'I_w',	1,'double', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTInverterCurrentdqArray', {
	{'I_d',	1,'double', -1, 'real', 'Sample'};
	{'I_q',	1,'double', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTInverterVoltageuvwArray', {
	{'V_u',	1,'double', -1, 'real', 'Sample'};
	{'V_v',	1,'double', -1, 'real', 'Sample'};
	{'V_w',	1,'double', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTInverterVoltagedqArray', {
	{'V_d',	1,'double', -1, 'real', 'Sample'};
	{'V_q',	1,'double', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTInverterGateSignalArray', {
	{'GS0',	1,'double', -1, 'real', 'Sample'};
	{'GS1',	1,'double', -1, 'real', 'Sample'};
	{'GS2',	1,'double', -1, 'real', 'Sample'};
    }
}
% Input Bus
{
    'cmPTInverterIn', {
	{'Load_in',		1,'double',                      -1, 'real', 'Sample'};
	{'GateSignal',	        1,'cm22PTInverterGateSignalArray', -1, 'real', 'Sample'};
	{'PwrElec',		1,'double',                      -1, 'real', 'Sample'};
	{'Motor_Trq',		1,'double',                      -1, 'real', 'Sample'};
	{'Motor_rotv',		1,'double',                      -1, 'real', 'Sample'};
	{'Motor_rot',		1,'double',                      -1, 'real', 'Sample'};
	{'Current_uvw',		1,'cm22PTInverterCurrentuvwArray', -1, 'real', 'Sample'};
	{'Current_dq',		1,'cm22PTInverterCurrentdqArray',  -1, 'real', 'Sample'};
	{'Volt_Batt',		1,'double',                      -1, 'real', 'Sample'};
    }
}
% Output Bus
{
    'cmPTInverterOut', {
	{'Load',		1,'double',		          -1, 'real', 'Sample'};
	{'Voltage_uvw',		1,'cm22PTInverterVoltageuvwArray',  -1, 'real', 'Sample'};
	{'Voltage_dq',		1,'cm22PTInverterVoltagedqArray',	  -1, 'real', 'Sample'};
	{'Current_Batt',	1,'double',	                  -1, 'real', 'Sample'};
	{'PwrLoss',	        1,'double',	                  -1, 'real', 'Sample'};
    }
}
% Cfg Input Bus
{
    'cmPTInverterCfgIn', {
	{'Level',	1,'double',		-1, 'real', 'Sample'};
	{'nPolePairs',	1,'double',		-1, 'real', 'Sample'};
	{'MotorType',	1,'double',		-1, 'real', 'Sample'};
    }
}
});
