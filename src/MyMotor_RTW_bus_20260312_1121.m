Simulink.Bus.cellToObject({
{
    'cmPTMotorIn', {
	{'rot',		1,'double', -1, 'real', 'Sample'};
	{'rotv',	1,'double', -1, 'real', 'Sample'};
	{'VoltBatt',	1,'double', -1, 'real', 'Sample'};
	{'Load',	1,'double', -1, 'real', 'Sample'};
	{'Voltage_d',	1,'double', -1, 'real', 'Sample'};
	{'Voltage_q',	1,'double', -1, 'real', 'Sample'};
	{'Voltage_u',	1,'double', -1, 'real', 'Sample'};
	{'Voltage_v',	1,'double', -1, 'real', 'Sample'};
	{'Voltage_w',	1,'double', -1, 'real', 'Sample'};

    }
}
{
    'cmPTMotorOut', {
	{'Trq',		1,'double', -1, 'real', 'Sample'};
	{'Inert',	1,'double', -1, 'real', 'Sample'};
	{'PwrElec',	1,'double', -1, 'real', 'Sample'};
	{'Current_d',	1,'double', -1, 'real', 'Sample'};
	{'Current_q',	1,'double', -1, 'real', 'Sample'};
	{'Current_u',	1,'double', -1, 'real', 'Sample'};
	{'Current_v',	1,'double', -1, 'real', 'Sample'};
	{'Current_w',	1,'double', -1, 'real', 'Sample'};
    }
}
% Cfg Output Bus
{
    'cm19PTMotorMap', {
	{'x',	100,'double', -1, 'real', 'Sample'};
	{'z',	100,'double', -1, 'real', 'Sample'};
    }
}
{
    'cmPTMotorCfgOut', {
	{'CtrlMode',		1,'double', -1, 'real', 'Sample'};
	{'Level',		1,'double', -1, 'real', 'Sample'};
	{'Ratio',		1,'double', -1, 'real', 'Sample'};
	{'TrqMot_max',		1,'cm19PTMotorMap', -1, 'real', 'Sample'};
	{'rotv_Mot_max',	1,'double', -1, 'real', 'Sample'};
	{'TrqGen_max',		1,'cm19PTMotorMap', -1, 'real', 'Sample'};
	{'rotv_Gen_max',	1,'double', -1, 'real', 'Sample'};
    }
}
});
