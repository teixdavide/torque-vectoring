Simulink.Bus.cellToObject({
{
    'cm32DigitalSelectorCtrl', {
	{'d0',		1, 'double', -1, 'real', 'Sample'};
	{'d1',		1, 'double', -1, 'real', 'Sample'};
	{'d2',		1, 'double', -1, 'real', 'Sample'};
    }
}
{
    'cmSelectorCtrlMappingIn', {
	{'SelectorCtrlAction', 	1, 'double', -1, 'real', 'Sample'};
	{'VC_SelectorCtrl_in',	1, 'double', -1, 'real', 'Sample'};
	{'DigitalSelectorCtrl', 	1, 'cm32DigitalSelectorCtrl', -1, 'real', 'Sample'};
    }
}
{
    'cmSelectorCtrlMappingOut', { ...
	{'DM_SelectorCtrl_out',	1, 'double', -1, 'real', 'Sample'};
	{'DigitalSelectorCtrl', 		1, 'cm32DigitalSelectorCtrl', -1, 'real', 'Sample'};
    }
}
});

