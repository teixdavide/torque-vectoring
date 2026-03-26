if strcmp(vehicle, 'Motorcycle')
Simulink.Bus.cellToObject({
{
    'cm22PTTransmCUClutchInArray', {
	{'m0',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'m1',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUClutchOutArray', {
	{'CL0',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL1',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGBInArray', {
	{'GB0',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB1',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGBOutInArray', {
	{'GB0',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB1',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGearBoxOutArray', {
	{'GB0', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB1', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGearBoxCfgArray', {
	{'GB0', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB1', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
    }
}
});
elseif strcmp(vehicle, 'Car')
Simulink.Bus.cellToObject({
{
    'cm22PTTransmCUClutchInArray', {
	{'CL0',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL1',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL2',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL3',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL4',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL5',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL6',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL7',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL8',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL9',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL10',	1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL11',	1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUClutchOutArray', {
	{'CL0',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL1',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL2',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL3',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL4',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL5',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL6',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL7',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL8',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL9',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL10',	1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL11',	1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGBInArray', {
	{'GB0',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB1',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB2',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB3',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB4',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB5',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB6',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB7',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB8',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB9',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB10',	1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB11',	1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGBOutInArray', {
	{'GB0',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB1',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB2',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB3',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB4',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB5',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB6',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB7',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB8',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB9',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB10',	1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB11',	1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGearBoxOutArray', {
	{'GB0', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB1', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB2', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB3', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB4', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB5', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB6', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB7', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB8', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB9', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB10', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB11', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGearBoxCfgArray', {
	{'GB0', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB1', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB2', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB3', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB4', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB5', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB6', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB7', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB8', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB9', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB10', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB11', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
    }
}
});
elseif strcmp(vehicle, 'Truck')
Simulink.Bus.cellToObject({
{
    'cm22PTTransmCUClutchInArray', {
	{'CL0',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL1',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL2',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL3',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL4',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL5',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL6',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL7',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL8',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL9',		1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL10',	1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'CL11',	1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUClutchOutArray', {
	{'CL0',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL1',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL2',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL3',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL4',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL5',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL6',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL7',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL8',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL9',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL10',	1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'CL11',	1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGBInArray', {
	{'GB0',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB1',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB2',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB3',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB4',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB5',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB6',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB7',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB8',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB9',		1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB10',	1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
	{'GB11',	1,'cm22PTTransmCUGBIn', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGBOutInArray', {
	{'GB0',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB1',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB2',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB3',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB4',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB5',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB6',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB7',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB8',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB9',		1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB10',	1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
	{'GB11',	1,'cm22PTTransmCUGBOutIn', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGearBoxOutArray', {
	{'GB0', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB1', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB2', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB3', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB4', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB5', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB6', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB7', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB8', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB9', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB10', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
	{'GB11', 1,'cm22PTTransmCUGearBoxOut', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGearBoxCfgArray', {
	{'GB0', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB1', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB2', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB3', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB4', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB5', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB6', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB7', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB8', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB9', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB10', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
	{'GB11', 1,'cm22PTTransmCUGearBoxCfg', -1, 'real', 'Sample'};
    }
}
});
end
Simulink.Bus.cellToObject({
{
    'cm22PTTransmCUClutchOut', {
	{'Pos',	1,'double', -1, 'real', 'Sample'};
    }
}
% Input Bus
{
    'cm22PTTransmCUClutchIn', {
	{'rotv_in',	1,'double', -1, 'real', 'Sample'};
	{'rotv_out',	1,'double', -1, 'real', 'Sample'};
	{'rotv_out_trg',1,'double', -1, 'real', 'Sample'};
	{'Trq_in',	1,'double', -1, 'real', 'Sample'};
	{'Trq_out',	1,'double', -1, 'real', 'Sample'};
	{'Trq_out_trg',	1,'double', -1, 'real', 'Sample'};
	{'i_TrqIn2Out',	1,'double', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGBIn', {
	{'GearNo',	1,'double', -1, 'real', 'Sample'};
	{'GearNo_dis',	1,'double', -1, 'real', 'Sample'};
	{'i',		1,'double', -1, 'real', 'Sample'};
	{'rotv_in',	1,'double', -1, 'real', 'Sample'};
	{'rotv_in_trg',	1,'double', -1, 'real', 'Sample'};
	{'rotv_out',	1,'double', -1, 'real', 'Sample'};
	{'Trq_in',	1,'double', -1, 'real', 'Sample'};
	{'Trq_out',	1,'double', -1, 'real', 'Sample'};
	{'Trq_out_trg',	1,'double', -1, 'real', 'Sample'};
	{'Clutch',	1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
	{'Clutch_dis',	1,'cm22PTTransmCUClutchIn', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGBOutIn', {
	{'GearNoTrg',		1,'double', -1, 'real', 'Sample'};
	{'GearNoTrg_dis',	1,'double', -1, 'real', 'Sample'};
	{'set_ParkBrake',	1,'double', -1, 'real', 'Sample'};
	{'i_trg',		1,'double', -1, 'real', 'Sample'};
	{'Clutch',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'Clutch_dis',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
    }
}
{
    'cmPTTransmCUIn', {
	{'Ignition',		1,'double', -1, 'real', 'Sample'};
	{'Load',		1,'double', -1, 'real', 'Sample'};
	{'SelectorCtrl',	1,'double', -1, 'real', 'Sample'};
	{'Velocity',		1,'double', -1, 'real', 'Sample'};
	{'ClutchIn',		1,'cm22PTTransmCUClutchInArray',  -1, 'real', 'Sample'};
	{'ClutchOut',		1,'cm22PTTransmCUClutchOutArray', -1, 'real', 'Sample'};
	{'GearboxIn',		1,'cm22PTTransmCUGBInArray',      -1, 'real', 'Sample'};
	{'GearboxOut',		1,'cm22PTTransmCUGBOutInArray',   -1, 'real', 'Sample'};
    }
}
% Output Bus
{
    'cm22PTTransmCUGearBoxOut', {
	{'GearNoTrg',		1,'double', -1, 'real', 'Sample'};
	{'GearNoTrg_dis',	1,'double', -1, 'real', 'Sample'};
	{'set_ParkBrake',	1,'double', -1, 'real', 'Sample'};
	{'Trq_DriveSrc_trg',	1,'double', -1, 'real', 'Sample'};
	{'i_trg',		1,'double', -1, 'real', 'Sample'};
	{'Clutch',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
	{'Clutch_dis',		1,'cm22PTTransmCUClutchOut', -1, 'real', 'Sample'};
    }
}
{
    'cmPTTransmCUOut', {
	{'Status',		1,'double',		-1, 'real', 'Sample'};
	{'ClutchOut',		1,'cm22PTTransmCUClutchOutArray',	-1, 'real', 'Sample'};
	{'GearboxOut',		1,'cm22PTTransmCUGearBoxOutArray',	-1, 'real', 'Sample'};
    }
}
% Cfg Input Bus
{
    'cm22PTTransmCUGBFGears', {
	{'Gear1',		1,'double', -1, 'real', 'Sample'};
	{'Gear2',		1,'double', -1, 'real', 'Sample'};
	{'Gear3',		1,'double', -1, 'real', 'Sample'};
	{'Gear4',		1,'double', -1, 'real', 'Sample'};
	{'Gear5',		1,'double', -1, 'real', 'Sample'};
	{'Gear6',		1,'double', -1, 'real', 'Sample'};
	{'Gear7',		1,'double', -1, 'real', 'Sample'};
	{'Gear8',		1,'double', -1, 'real', 'Sample'};
	{'Gear9',		1,'double', -1, 'real', 'Sample'};
	{'Gear10',		1,'double', -1, 'real', 'Sample'};
	{'Gear11',		1,'double', -1, 'real', 'Sample'};
	{'Gear12',		1,'double', -1, 'real', 'Sample'};
	{'Gear13',		1,'double', -1, 'real', 'Sample'};
	{'Gear14',		1,'double', -1, 'real', 'Sample'};
	{'Gear15',		1,'double', -1, 'real', 'Sample'};
	{'Gear16',		1,'double', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGBBGears', {
	{'Gear1',		1,'double', -1, 'real', 'Sample'};
	{'Gear2',		1,'double', -1, 'real', 'Sample'};
	{'Gear3',		1,'double', -1, 'real', 'Sample'};
	{'Gear4',		1,'double', -1, 'real', 'Sample'};
    }
}
{
    'cm22PTTransmCUGearBoxCfg', {
	{'GBKind',		1,'double', -1, 'real', 'Sample'};
	{'ClKind',		1,'double', -1, 'real', 'Sample'};
	{'nFGears',		1,'double', -1, 'real', 'Sample'};
	{'iFGear',		1,'cm22PTTransmCUGBFGears', -1, 'real', 'Sample'};
	{'nBGears',		1,'double',                 -1, 'real', 'Sample'};
	{'iBGear',		1,'cm22PTTransmCUGBBGears', -1, 'real', 'Sample'};
    }
}
{
    'cmPTTransmCUCfgIn', {
	{'ClKind',	1,'double',		-1, 'real', 'Sample'};
	{'nGearbox',	1,'double',		-1, 'real', 'Sample'};
	{'nClutch',	1,'double',		-1, 'real', 'Sample'};
	{'Gearbox',	1,'cm22PTTransmCUGearBoxCfgArray',	-1, 'real', 'Sample'};
    }
}
% Cfg Output Bus
{
    'cmPTTransmCUCfgOut', {
	{'AutoWithMan',	1,'double',		-1, 'real', 'Sample'};
    }
}
});
