if strcmp(vehicle, 'Motorcycle')
    Simulink.Bus.cellToObject({
    {
	'cm24Wheels', {
	    {'F',	1,'double', -1, 'real', 'Sample'};
	    {'R',	1,'double', -1, 'real', 'Sample'};
	}
    }

    {
	'cm24CtrlIn', {
	    {'CtrlInOpt_0',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_1',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_2',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_3',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_4',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_5',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_6',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_7',	1,'double', -1, 'real', 'Sample'};
	}
    }

    {
	'cm24CtrlOut', {
	    {'CtrlOutOpt_0',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_1',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_2',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_3',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_4',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_5',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_6',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_7',	1,'double', -1, 'real', 'Sample'};
	}
    }
    });
elseif strcmp(vehicle, 'Car')
    Simulink.Bus.cellToObject({
    {
	'cm253D', {
	    {'x',	1,'double', -1, 'real', 'Sample'};
	    {'y',	1,'double', -1, 'real', 'Sample'};
	    {'z',	1,'double', -1, 'real', 'Sample'};
	}
    }

    {
	'cm253DRot', {
	    {'rx',	1,'double', -1, 'real', 'Sample'};
	    {'ry',	1,'double', -1, 'real', 'Sample'};
	    {'rz',	1,'double', -1, 'real', 'Sample'};
	}
    }

    {
	'cm253x3Mat', {
	    {'r0c0',	1,'double', -1, 'real', 'Sample'};
	    {'r0c1',	1,'double', -1, 'real', 'Sample'};
	    {'r0c2',	1,'double', -1, 'real', 'Sample'};
	    {'r1c0',	1,'double', -1, 'real', 'Sample'};
	    {'r1c1',	1,'double', -1, 'real', 'Sample'};
	    {'r1c2',	1,'double', -1, 'real', 'Sample'};
	    {'r2c0',	1,'double', -1, 'real', 'Sample'};
	    {'r2c1',	1,'double', -1, 'real', 'Sample'};
	    {'r2c2',	1,'double', -1, 'real', 'Sample'};
	}
    }

    {
	'cm25Vhcl_Fr1In', {
	    {'t_0',	1,'cm253D', -1, 'real', 'Sample'};
	    {'v_0',	1,'cm253D', -1, 'real', 'Sample'};
	    {'a_0',	1,'cm253D', -1, 'real', 'Sample'};
	    {'Tr2Fr0',	1,'cm253x3Mat', -1, 'real', 'Sample'};
	    {'r_zyx',	1,'cm253DRot', -1, 'real', 'Sample'};
	    {'rv_zyx',	1,'cm253DRot', -1, 'real', 'Sample'};
	    {'ra_zyx',	1,'cm253DRot', -1, 'real', 'Sample'};
	}
    }
    {
	'cm24Wheels', {
	    {'FL',	1,'double', -1, 'real', 'Sample'};
	    {'FR',	1,'double', -1, 'real', 'Sample'};
	    {'RL',	1,'double', -1, 'real', 'Sample'};
	    {'RR',	1,'double', -1, 'real', 'Sample'};
	}
    }

    {
	'cm24CtrlIn', {
	    {'CtrlInOpt_0',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_1',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_2',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_3',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_4',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_5',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_6',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_7',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_8',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_9',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_10',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_11',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_12',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_13',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_14',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_15',	1,'double', -1, 'real', 'Sample'};
	}
    }

    {
	'cm24CtrlOut', {
	    {'CtrlOutOpt_0',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_1',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_2',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_3',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_4',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_5',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_6',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_7',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_8',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_9',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_10',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_11',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_12',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_13',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_14',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_15',	1,'double', -1, 'real', 'Sample'};
	}
    }
    });
elseif strcmp(vehicle, 'Truck')
    Simulink.Bus.cellToObject({
    {
	'cm253D', {
	    {'x',	1,'double', -1, 'real', 'Sample'};
	    {'y',	1,'double', -1, 'real', 'Sample'};
	    {'z',	1,'double', -1, 'real', 'Sample'};
	}
    }

    {
	'cm253DRot', {
	    {'rx',	1,'double', -1, 'real', 'Sample'};
	    {'ry',	1,'double', -1, 'real', 'Sample'};
	    {'rz',	1,'double', -1, 'real', 'Sample'};
	}
    }

    {
	'cm253x3Mat', {
	    {'r0c0',	1,'double', -1, 'real', 'Sample'};
	    {'r0c1',	1,'double', -1, 'real', 'Sample'};
	    {'r0c2',	1,'double', -1, 'real', 'Sample'};
	    {'r1c0',	1,'double', -1, 'real', 'Sample'};
	    {'r1c1',	1,'double', -1, 'real', 'Sample'};
	    {'r1c2',	1,'double', -1, 'real', 'Sample'};
	    {'r2c0',	1,'double', -1, 'real', 'Sample'};
	    {'r2c1',	1,'double', -1, 'real', 'Sample'};
	    {'r2c2',	1,'double', -1, 'real', 'Sample'};
	}
    }

    {
	'cm25Vhcl_Fr1In', {
	    {'t_0',	1,'cm253D', -1, 'real', 'Sample'};
	    {'v_0',	1,'cm253D', -1, 'real', 'Sample'};
	    {'a_0',	1,'cm253D', -1, 'real', 'Sample'};
	    {'Tr2Fr0',	1,'cm253x3Mat', -1, 'real', 'Sample'};
	    {'r_zyx',	1,'cm253DRot', -1, 'real', 'Sample'};
	    {'rv_zyx',	1,'cm253DRot', -1, 'real', 'Sample'};
	    {'ra_zyx',	1,'cm253DRot', -1, 'real', 'Sample'};
	}
    }
    
    {
	'cm24Wheels', {
	    {'FL',	1,'double', -1, 'real', 'Sample'};
	    {'FR',	1,'double', -1, 'real', 'Sample'};
	    {'RL',	1,'double', -1, 'real', 'Sample'};
	    {'RR',	1,'double', -1, 'real', 'Sample'};
	    {'RL2',	1,'double', -1, 'real', 'Sample'};
	    {'RR2',	1,'double', -1, 'real', 'Sample'};
	    {'FL2',	1,'double', -1, 'real', 'Sample'};
	    {'FR2',	1,'double', -1, 'real', 'Sample'};
	    {'RL3',	1,'double', -1, 'real', 'Sample'};
	    {'RR3',	1,'double', -1, 'real', 'Sample'};
	    {'RL4',	1,'double', -1, 'real', 'Sample'};
	    {'RR4',	1,'double', -1, 'real', 'Sample'};
	}
    }

    {
	'cm24CtrlIn', {
	    {'CtrlInOpt_0',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_1',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_2',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_3',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_4',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_5',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_6',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_7',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_8',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_9',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_10',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_11',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_12',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_13',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_14',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_15',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_16',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_17',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_18',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_19',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_20',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_21',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_22',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_23',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_24',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_25',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_26',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_27',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_28',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_29',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_30',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_31',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_32',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_33',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_34',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_35',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_36',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_37',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_38',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_39',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_40',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_41',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_42',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_43',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_44',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_45',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_46',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_47',	1,'double', -1, 'real', 'Sample'};
	}
    }

    {
	'cm24CtrlOut', {
	    {'CtrlOutOpt_0',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_1',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_2',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_3',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_4',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_5',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_6',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_7',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_8',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_9',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_10',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_11',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_12',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_13',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_14',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_15',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_16',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_17',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_18',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_19',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_20',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_21',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_22',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_23',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_24',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_25',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_26',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_27',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_28',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_29',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_30',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_31',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_32',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_33',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_34',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_35',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_36',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_37',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_38',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_39',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_40',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_41',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_42',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_43',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_44',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_45',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_46',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_47',	1,'double', -1, 'real', 'Sample'};
	}
    }
    });
end
Simulink.Bus.cellToObject({
{
    'cmSusp_BufferSystemIn', {
        {'Vhcl_Fr1',	1,'cm25Vhcl_Fr1In', -1, 'real', 'Sample'};
        {'length', 	1, 'cm24Wheels', -1, 'real', 'Sample'};
        {'vel', 	1, 'cm24Wheels', -1, 'real', 'Sample'};
        {'CtrlIn', 	1, 'cm24Wheels', -1, 'real', 'Sample'};
        {'CtrlInOpt', 	1, 'cm24CtrlIn', -1, 'real', 'Sample'};
    }
}
{
    'cmSusp_BufferSystemOut', {
        {'Force', 	1, 'cm24Wheels', -1, 'real', 'Sample'};
        {'CtrlOutOpt', 	1, 'cm24CtrlOut', -1, 'real', 'Sample'};
    }
}
% CfgInput Bus
{
    'cmSusp_BufferSystemCfgIn' , {
        {'VehicleClassId', 	1, 'double', -1, 'real', 'Sample'};
        {'nWheels', 	1, 'double', -1, 'real', 'Sample'};
    }
}
});
