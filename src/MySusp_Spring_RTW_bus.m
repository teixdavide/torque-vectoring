Simulink.Bus.cellToObject({
{
    'cm24CtrlIn', {
	{'CtrlInOpt_0',	1,'double', -1, 'real', 'Sample'};
	{'CtrlInOpt_1',	1,'double', -1, 'real', 'Sample'};
	{'CtrlInOpt_2',	1,'double', -1, 'real', 'Sample'};
	{'CtrlInOpt_3',	1,'double', -1, 'real', 'Sample'};
    }
}

{
    'cm24CtrlOut', {
	{'CtrlOutOpt_0', 1,'double', -1, 'real', 'Sample'};
	{'CtrlOutOpt_1', 1,'double', -1, 'real', 'Sample'};
	{'CtrlOutOpt_2', 1,'double', -1, 'real', 'Sample'};
	{'CtrlOutOpt_3', 1,'double', -1, 'real', 'Sample'};
    }
}
});

Simulink.Bus.cellToObject({
{
    'cmSusp_SpringIn', {
	{'length', 	1, 'double', 	-1, 'real', 'Sample'};
	{'vel',  	1, 'double', 	-1, 'real', 'Sample'};
	{'CtrlIn',  	1, 'double', 	-1, 'real', 'Sample'};
	{'CtrlInOpt', 	1, 'cm24CtrlIn',-1, 'real', 'Sample'};
    }
}
{
    'cmSusp_SpringOut', {
	{'Force', 	1, 'double', 	  -1, 'real', 'Sample'};
	{'CtrlOutOpt', 	1, 'cm24CtrlOut', -1, 'real', 'Sample'};
    }
}
% CfgInput Bus
{
    'cmSusp_SpringCfgIn' , {
	{'SuspModID', 1, 'double', -1, 'real', 'Sample'};
    }
}
});
