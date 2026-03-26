if strcmp(vehicle, 'Car')
    Simulink.Bus.cellToObject({
    {
	'cm5Wheels', {
	    {'FL',	1,'double', -1, 'real', 'Sample'};
	    {'FR',	1,'double', -1, 'real', 'Sample'};
	    {'RL',	1,'double', -1, 'real', 'Sample'};
	    {'RR',	1,'double', -1, 'real', 'Sample'};
	}
    }
    {
	'cm5WheelsTrq_stat', {
	    {'FL',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'FR',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'RL',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'RR',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	}
    }
    {
	'cm5DriveSrcs', {
	    {'d0',	1,'double', -1, 'real', 'Sample'};
	    {'d1',	1,'double', -1, 'real', 'Sample'};
	    {'d2',	1,'double', -1, 'real', 'Sample'};
	    {'d3',	1,'double', -1, 'real', 'Sample'};
	}
    }
    {
	'cm5CtrlInArray', {
	    {'CtrlIn_0', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_1', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_2', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_3', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_4', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_5', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_6', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_7', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_8', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_9', 1,'double', -1, 'real', 'Sample'};
	}
    }
    });
elseif strcmp(vehicle, 'Truck')
    Simulink.Bus.cellToObject({
    {
	'cm5Wheels', {
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
	'cm5WheelsTrq_stat', {
	    {'FL',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'FR',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'RL',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'RR',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'RL2',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'RR2',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'FL2',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'FR2',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'RL3',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'RR3',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'RL4',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	    {'RR4',	1,'cm5Trq_statMap', -1, 'real', 'Sample'};
	}
    }
    {
	'cm5DriveSrcs', {
	    {'d0',	1,'double', -1, 'real', 'Sample'};
	    {'d1',	1,'double', -1, 'real', 'Sample'};
	    {'d2',	1,'double', -1, 'real', 'Sample'};
	    {'d3',	1,'double', -1, 'real', 'Sample'};
	    {'d4',	1,'double', -1, 'real', 'Sample'};
	    {'d5',	1,'double', -1, 'real', 'Sample'};
	    {'d6',	1,'double', -1, 'real', 'Sample'};
	    {'d7',	1,'double', -1, 'real', 'Sample'};
	    {'d8',	1,'double', -1, 'real', 'Sample'};
	    {'d9',	1,'double', -1, 'real', 'Sample'};
	    {'d10',	1,'double', -1, 'real', 'Sample'};
	    {'d11',	1,'double', -1, 'real', 'Sample'};
	}
    }
    {
	'cm5CtrlInArray', {
	    {'CtrlIn_0', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_1', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_2', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_3', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_4', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_5', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_6', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_7', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_8', 1,'double', -1, 'real', 'Sample'};
	    {'CtrlIn_9', 1,'double', -1, 'real', 'Sample'};
	}
    }
    });
end
Simulink.Bus.cellToObject({
% Input Bus
{
    'cmHydBrakeControlIn', {
	{'Pedal',		1, 'double', 		-1, 'real', 'Sample'};
	{'Park', 		1, 'double', 		-1, 'real', 'Sample'};
	{'Trq_BrakeReg_max', 	1, 'cm5Wheels', 	-1, 'real', 'Sample'};
	{'Trq_BrakeReg', 	1, 'cm5Wheels', 	-1, 'real', 'Sample'};
	{'T_env', 		1, 'double', 		-1, 'real', 'Sample'};
	{'Trq_WB', 		1, 'cm5Wheels', 	-1, 'real', 'Sample'};
	{'Trq_PB', 		1, 'cm5Wheels', 	-1, 'real', 'Sample'};
	{'Rel_SW', 		1, 'double', 		-1, 'real', 'Sample'};
	{'pMC', 		1, 'double', 		-1, 'real', 'Sample'};
	{'pMC_2nd', 		1, 'double', 		-1, 'real', 'Sample'};
	{'pWB', 		1, 'cm5Wheels', 	-1, 'real', 'Sample'};
	{'PuRetVolt', 		1, 'double', 		-1, 'real', 'Sample'};
	{'PedFrc', 		1, 'double', 		-1, 'real', 'Sample'};
	{'PedTravel', 		1, 'double', 		-1, 'real', 'Sample'};
	{'PistTravel', 		1, 'double', 		-1, 'real', 'Sample'};
	{'DiaphTravel', 	1, 'double', 		-1, 'real', 'Sample'};
	{'rot',		  	1,'double',  		-1, 'real', 'Sample'};
	{'rotv',	  	1,'double',   		-1, 'real', 'Sample'};
	{'Trq',		  	1,'double',   		-1, 'real', 'Sample'};
	{'p_PresBooster', 	1,'double',           	-1, 'real', 'Sample'};
	{'CtrlIn', 		1,'cm5CtrlInArray',	-1, 'real', 'Sample'};
    }
}
% Output Bus
{
    'cm5ValveOutArray', {
       	{'V_0',	1,'double', -1, 'real', 'Sample'};
       	{'V_1',	1,'double', -1, 'real', 'Sample'};
       	{'V_2',	1,'double', -1, 'real', 'Sample'};
       	{'V_3',	1,'double', -1, 'real', 'Sample'};
       	{'V_4',	1,'double', -1, 'real', 'Sample'};
	{'V_5',	1,'double', -1, 'real', 'Sample'};
       	{'V_6',	1,'double', -1, 'real', 'Sample'};
	{'V_7',	1,'double', -1, 'real', 'Sample'};
       	{'V_8',	1,'double', -1, 'real', 'Sample'};
	{'V_9',	1,'double', -1, 'real', 'Sample'};
       	{'V_10',1,'double', -1, 'real', 'Sample'};
	{'V_11',1,'double', -1, 'real', 'Sample'};
       	{'V_12',1,'double', -1, 'real', 'Sample'};
	{'V_13',1,'double', -1, 'real', 'Sample'};
       	{'V_14',1,'double', -1, 'real', 'Sample'};
	{'V_15',1,'double', -1, 'real', 'Sample'};
    }
}
{
    'cm5CtrlOutArray', {
	{'CtrlOut_0',	1,'double', -1, 'real', 'Sample'};
	{'CtrlOut_1',	1,'double', -1, 'real', 'Sample'};
	{'CtrlOut_2',	1,'double', -1, 'real', 'Sample'};
	{'CtrlOut_3',	1,'double', -1, 'real', 'Sample'};
	{'CtrlOut_4',	1,'double', -1, 'real', 'Sample'};
	{'CtrlOut_5',	1,'double', -1, 'real', 'Sample'};
	{'CtrlOut_6',	1,'double', -1, 'real', 'Sample'};
	{'CtrlOut_7',	1,'double', -1, 'real', 'Sample'};
	{'CtrlOut_8',	1,'double', -1, 'real', 'Sample'};
	{'CtrlOut_9',	1,'double', -1, 'real', 'Sample'};
    }
}
{
    'cmHydBrakeControlOut', {
    	{'Pedal',		1, 'double', 		-1, 'real', 'Sample'};
	{'Park', 		1, 'double', 		-1, 'real', 'Sample'};
    	{'Trq_BrakeReg_trg',	1,'cm5Wheels', 		-1, 'real', 'Sample'};
    	{'Trq_DriveSrc_trg',	1,'cm5DriveSrcs', 	-1, 'real', 'Sample'};
    	{'Valve',		1,'cm5ValveOutArray', 	-1, 'real', 'Sample'};
    	{'PumpCtrl',		1,'double', 		-1, 'real', 'Sample'};
    	{'BooSignal',		1,'double', 		-1, 'real', 'Sample'};
	{'p_trg', 		1, 'double',          	-1, 'real', 'Sample'};
	{'Trq_trg', 		1, 'double',          	-1, 'real', 'Sample'};
	{'CtrlOut', 		1, 'cm5CtrlOutArray', 	-1, 'real', 'Sample'};
    }
}
% CfgInput Bus
{
    'cm5Trq_statMap', {
	{'x',	100,'double', -1, 'real', 'Sample'};
	{'z',	100,'double', -1, 'real', 'Sample'};
    }
}
{
    'cm5Map', {
	    {'x',100,'double', -1, 'real', 'Sample'};
	    {'z',100,'double', -1, 'real', 'Sample'};
    }
}
{
    'cmHydBrakeControlCfgIn' , {
	{'VehicleClassId', 	1, 'double', 		-1, 'real', 'Sample'};
	{'nWheels', 		1, 'double', 		-1, 'real', 'Sample'};
	{'BrakeKind', 		1, 'double', 		-1, 'real', 'Sample'};
	{'Trq_stat', 		1, 'cm5WheelsTrq_stat', -1, 'real', 'Sample'};
	{'Ped2pMC', 		1, 'cm5Map', 		-1, 'real', 'Sample'};
    }
}
});
