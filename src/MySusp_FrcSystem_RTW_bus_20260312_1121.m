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
	    {'CtrlInOpt_0', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_1', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_2', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_3', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_4', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_5', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_6', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_7', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_8', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_9', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_10',1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_11',1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_12',1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_13',1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_14',1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_15',1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_16',1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_17',1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_18',1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_19',1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_20',1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_21',1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_22',1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_23',1,'double', -1, 'real', 'Sample'};
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
	    {'CtrlInOpt_0',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_1',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_2',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_3',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_4',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_5',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_6',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_7',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_8',    	1,'double', -1, 'real', 'Sample'};
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
	    {'CtrlInOpt_48',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_49',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_50',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_51',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_52',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_53',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_54',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_55',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_56',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_57',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_58',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_59',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_60',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_61',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_62',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_63',	1,'double', -1, 'real', 'Sample'};
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
	    {'CtrlOutOpt_48',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_49',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_50',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_51',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_52',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_53',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_54',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_55',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_56',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_57',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_58',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_59',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_60',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_61',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_62',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_63',	1,'double', -1, 'real', 'Sample'};
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
	    {'CtrlInOpt_0',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_1',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_2',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_3',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_4',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_5',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_6',    	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_7',    	1,'double', -1, 'real', 'Sample'};
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
	    {'CtrlInOpt_48',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_49',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_50',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_51',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_52',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_53',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_54',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_55',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_56',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_57',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_58',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_59',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_60',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_61',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_62',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_63',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_64',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_65',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_66',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_67',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_68',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_69',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_70',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_71',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_72',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_73',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_74',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_75',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_76',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_77',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_78',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_79',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_80',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_81',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_82',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_83',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_84',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_85',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_86',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_87',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_88',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_89',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_90',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_91',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_92',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_93',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_94',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_95',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_96',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_97',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_98',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_99',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_100',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_101',   1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_102',   1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_103',   1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_104',  	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_105',   1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_106',   1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_107',   1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_108',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_109',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_110',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_111',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_112',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_113',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_114',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_115',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_116',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_117',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_118',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_119',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_120',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_121',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_122',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_123',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_124',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_125',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_126',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_127',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_128',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_129',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_130',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_131',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_132',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_133',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_134',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_135',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_136',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_137',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_138',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_139',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_140',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_141',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_142',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_143',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_144',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_145',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_146',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_147',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_148',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_149',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_150',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_151',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_152',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_153',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_154',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_155',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_156',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_157',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_158',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlInOpt_159',	1,'double', -1, 'real', 'Sample'};
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
	    {'CtrlOutOpt_48',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_49',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_50',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_51',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_52',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_53',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_54',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_55',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_56',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_57',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_58',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_59',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_60',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_61',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_62',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_63',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_64',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_65',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_66',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_67',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_68',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_69',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_70',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_71',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_72',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_73',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_74',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_75',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_76',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_77',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_78',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_79',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_80',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_81',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_82',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_83',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_84',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_85',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_86',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_87',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_88',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_89',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_90',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_91',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_92',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_93',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_94',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_95',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_96',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_97',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_98',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_99',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_100',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_101',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_102',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_103',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_104',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_105',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_106',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_107',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_108',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_109',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_110',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_111',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_112',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_113',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_114',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_115',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_116',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_117',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_118',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_119',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_120',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_121',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_122',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_123',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_124',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_125',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_126',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_127',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_128',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_129',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_130',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_131',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_132',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_133',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_134',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_135',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_136',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_137',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_138',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_139',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_140',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_141',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_142',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_143',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_144',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_145',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_146',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_147',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_148',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_149',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_150',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_151',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_152',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_153',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_154',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_155',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_156',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_157',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_158',	1,'double', -1, 'real', 'Sample'};
	    {'CtrlOutOpt_159',	1,'double', -1, 'real', 'Sample'};
	}
    }
    });
end
Simulink.Bus.cellToObject({
{
    'cmSusp_FrcSystemIn', {
	{'Vhcl_Fr1',		1,'cm25Vhcl_Fr1In', -1, 'real', 'Sample'};
	{'tWheelCarrier_z',     1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'vWheelCarrier_z',     1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'lSpring',             1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'vSpring', 	    	1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'lDamper', 	    	1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'vDamper', 	    	1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'lBuffer', 	    	1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'vBuffer', 	    	1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'lStabi',  	   	1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'vStabi', 	        1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'CtrlInSpring',        1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'CtrlInDamper',        1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'CtrlInBuffer',        1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'CtrlInStabi',         1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'CtrlInOpt', 	    	1, 'cm24CtrlIn', -1, 'real', 'Sample'};
    }
}
{
    'cmSusp_FrcSystemOut', {
	{'FrcParasiticStiff', 	1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'FrcParasiticFric', 	1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'FrcSpring',          	1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'FrcDamper',       	1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'FrcBuffer',       	1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'FrcStabi', 	        1, 'cm24Wheels', -1, 'real', 'Sample'};
	{'CtrlOutOpt',         	1, 'cm24CtrlOut', -1,'real', 'Sample'};
    }
}
% CfgInput Bus
{
    'cmSusp_FrcSystemCfgIn' , {
	{'VehicleClassId', 	1, 'double', -1, 'real', 'Sample'};
	{'nWheels', 	1, 'double', -1, 'real', 'Sample'};
    }
}
});
