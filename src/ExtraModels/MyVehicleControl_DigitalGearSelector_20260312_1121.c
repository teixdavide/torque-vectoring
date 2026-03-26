/*
******************************************************************************
**  CarMaker - Version 13.1.1
**  Vehicle Dynamics Simulation Toolkit
**
**  Copyright (C)   IPG Automotive GmbH
**                  Bannwaldallee 60             Phone  +49.721.98520.0
**                  76185 Karlsruhe              Fax    +49.721.98520.99
**                  Germany                      WWW    www.ipg-automotive.com
******************************************************************************
**
** Simple VehicleControl Model to demonstrate the manipulation of Driver Gas
**
** Add the declaration of the register function to one of your header files,
** for example to User.h and call it in User_Register()
**
**    VehicleControl_Register_MyDigitalGearSelector ()
**
******************************************************************************
*/

#include <string.h>
#include <stdlib.h>

#include "MyModels.h"
#include "Car/Vehicle_Car.h"
#include "Vehicle.h"
#include "VehicleControl.h"
#include "Log.h"

static const char ThisModelClass[] = "VehicleControl";
static const char ThisModelKind[] = "MyDigitalGearSelector";
static const int ThisVersionId = 1;


struct SelectorCtrlMap{
    const char *Name;
    tSelectorCtrl Front1;
    tSelectorCtrl Front2;
    tSelectorCtrl Back1;
    tSelectorCtrl Back2;
} SelectorCtrlMap[] = {
    {"SelectorCtrl_P", SelectorCtrl_N, SelectorCtrl_R, SelectorCtrl_D, SelectorCtrl_D},
    {"SelectorCtrl_N", SelectorCtrl_R, SelectorCtrl_R, SelectorCtrl_D, SelectorCtrl_D},
    {"SelectorCtrl_D", SelectorCtrl_N, SelectorCtrl_R, SelectorCtrl_S, SelectorCtrl_S},
    {"SelectorCtrl_S", SelectorCtrl_N, SelectorCtrl_R, SelectorCtrl_D, SelectorCtrl_D},
    {"SelectorCtrl_R", SelectorCtrl_R, SelectorCtrl_R, SelectorCtrl_N, SelectorCtrl_D},
    {NULL}
};


enum {
    Back2   = -2,
    Back1   = -1,
    Neutral =  0,
    Front1  =  1,
    Front2  =  2
};


struct tMyModel {
    tSelectorCtrl SelectorCtrlCurr;
    tSelectorCtrl SelectorCtrlTrg;
    int SwitchRegistered;
};


static void
MyDigitalGearSelector_DeclQuants(void *MP)
{
}


static void
SelectorCtrl2String (tSelectorCtrl SelectorCtrl, char *buffer, int buffersize)
{
    switch(SelectorCtrl) {
	case SelectorCtrl_P:
	    snprintf(buffer, buffersize, "%s", "SelectorCtrl_P");
	    break;
	case SelectorCtrl_R:
	    snprintf(buffer, buffersize, "%s", "SelectorCtrl_R");
	    break;
	case SelectorCtrl_N:
	    snprintf(buffer, buffersize, "%s", "SelectorCtrl_N");
	    break;
	case SelectorCtrl_M:
	    snprintf(buffer, buffersize, "%s", "SelectorCtrl_M");
	    break;
	case SelectorCtrl_D:
	    snprintf(buffer, buffersize, "%s", "SelectorCtrl_D");
	    break;
	case SelectorCtrl_S:
	    snprintf(buffer, buffersize, "%s", "SelectorCtrl_S");
	    break;
    }
}


static int
GearSelectorInNeutral(int DigitalSelectorPos[])
{
    if ((DigitalSelectorPos[0] == Neutral || DigitalSelectorPos[0] == NOTSET) &&
	(DigitalSelectorPos[1] == Neutral || DigitalSelectorPos[1] == NOTSET)) {
	return 1;
    }
    return 0;
}


static int
PlausibilityCheck(tSelectorCtrl CurrentState, tSelectorCtrl Target)
{
    switch (CurrentState) {
	case SelectorCtrl_D:
	case SelectorCtrl_S:
	case SelectorCtrl_M:
	    switch (Target) {
		case SelectorCtrl_D:
		case SelectorCtrl_S:
		case SelectorCtrl_M:
		    return 1;
		case SelectorCtrl_R:
		case SelectorCtrl_P:
		case SelectorCtrl_N:
		    if (Vehicle.v < 0.1) {
			return 1;
		    } else {
			return 0;
		    }
	    }
	    break;
	case SelectorCtrl_N:
	case SelectorCtrl_P:
	    switch (Target) {
		case SelectorCtrl_D:
		case SelectorCtrl_S:
		case SelectorCtrl_R:
		case SelectorCtrl_N:
		case SelectorCtrl_P:
		case SelectorCtrl_M:
		    if (Vehicle.v < 0.1) {
			return 1;
		    } else {
			return 0;
		    }
		    break;
	    }
	    break;
	case SelectorCtrl_R:
	    switch (Target) {
		case SelectorCtrl_D:
		case SelectorCtrl_S:
		case SelectorCtrl_M:
		case SelectorCtrl_P:
		case SelectorCtrl_N:
		    if (Vehicle.v < 0.1) {
			return 1;
		    } else {
			return 0;
		    }
		    break;
		case SelectorCtrl_R:
		    return 1;
		    break;
	    }
	    break;
    }

    return 0;
}


static tSelectorCtrl
HandleGearSelectorEntry0(int DigitalSelectorPos, tSelectorCtrl CurrentState,
			 int *SwitchRegistered, struct SelectorCtrlMap *SelecCtrlMap)
{
    switch(DigitalSelectorPos) {
	case Back2:
	    if (PlausibilityCheck(CurrentState, SelecCtrlMap->Back2)) {
		*SwitchRegistered = 1;
		return SelecCtrlMap->Back2;
	    } else {
		*SwitchRegistered = 0;
	    }
	    break;
	case Back1:
	    if (PlausibilityCheck(CurrentState, SelecCtrlMap->Back1)) {
		*SwitchRegistered = 1;
		return SelecCtrlMap->Back1;
	    } else {
		*SwitchRegistered = 0;
	    }
	    break;
	case Neutral:
	    *SwitchRegistered = 0;
	    break;
	case Front1:
	    if (PlausibilityCheck(CurrentState, SelecCtrlMap->Front1)) {
		*SwitchRegistered = 1;
		return SelecCtrlMap->Front1;
	    } else {
		*SwitchRegistered = 0;
	    }
	    break;
	case Front2:
	    if (PlausibilityCheck(CurrentState, SelecCtrlMap->Front2)) {
		*SwitchRegistered = 1;
		return SelecCtrlMap->Front2;
	    } else {
		*SwitchRegistered = 0;
	    }
	    break;
	default:
	    LogErrF(EC_Sim, "%s: %d is not a valid Digital Selector Control 0 position", ThisModelKind, DigitalSelectorPos);
	    break;
    }
    return CurrentState;
}


static tSelectorCtrl
HandleGearSelectorEntry1 (int DigitalSelectorPos, tSelectorCtrl CurrentState, 
			  int *SwitchRegistered)
{
    switch (DigitalSelectorPos) {
	case 0:
	    *SwitchRegistered = 0;
	    break;
	case 1:
	    if (PlausibilityCheck(CurrentState, SelectorCtrl_P)) {
		*SwitchRegistered = 1;
		return SelectorCtrl_P;
	    } else {
		*SwitchRegistered = 0;
	    }
	    break;
	default:
	    LogErrF(EC_Sim, "%s: %d is not a valid Digital Selector Control 1 position", ThisModelKind, DigitalSelectorPos);
	    break;
    }
    return CurrentState;
}


#define NOTSET -99999
static tSelectorCtrl
GetSelectorCtrlTrg (struct SelectorCtrlMap *SelecCtrlMap, int DigitalGearSelectorPos[],
		    tSelectorCtrl CurrentState, int *SwitchRegistered)
{
    if (DigitalGearSelectorPos[0] != Neutral && DigitalGearSelectorPos[0] != NOTSET &&
	*SwitchRegistered == 0) {
	return HandleGearSelectorEntry0(DigitalGearSelectorPos[0], CurrentState, 
					SwitchRegistered, SelecCtrlMap);
    } else if (DigitalGearSelectorPos[1] != Neutral && DigitalGearSelectorPos[1] != NOTSET &&
	       *SwitchRegistered == 0) {
	return HandleGearSelectorEntry1(DigitalGearSelectorPos[1], CurrentState, 
					SwitchRegistered);
    } else if (GearSelectorInNeutral(DigitalGearSelectorPos) &&
	       *SwitchRegistered == 1) {
	*SwitchRegistered = 0;
	return CurrentState;
    } else { // Switch registered but DigitalGearSelectorPos still != Neutral
	return CurrentState;
    }

    return CurrentState;
}


static int
MyDigitalGearSelector_Calc (void *MP, double dt)
{
    tVehicleControl *VC = &VehicleControl;
    struct tMyModel *mp = (struct tMyModel*)MP;
    char SelectorCtrlStr[24];
    int i;
    int bufflen = sizeof(SelectorCtrlStr);

    if (Vehicle.OperationState != OperState_Driving ||
	(VC->DigitalSelectorCtrl[0] == NOTSET &&
	 VC->DigitalSelectorCtrl[1] == NOTSET &&
	 VC->DigitalSelectorCtrl[2] == NOTSET)) {
	mp->SelectorCtrlCurr = (tSelectorCtrl)DrivMan.SelectorCtrl;
	return 0;
    }

    SelectorCtrl2String(mp->SelectorCtrlCurr, SelectorCtrlStr, bufflen);
    for (i = 0; SelectorCtrlMap[i].Name != NULL; ++i) {
	if (strcmp(SelectorCtrlStr, SelectorCtrlMap[i].Name) == 0) {
	    mp->SelectorCtrlTrg = GetSelectorCtrlTrg(&SelectorCtrlMap[i], VC->DigitalSelectorCtrl,
						     mp->SelectorCtrlCurr, &mp->SwitchRegistered);
	    break;
	}
    }

    VC->SelectorCtrl     = mp->SelectorCtrlTrg;
    mp->SelectorCtrlCurr = mp->SelectorCtrlTrg;

    return 0;
}


static void
MyDigitalGearSelector_Delete (void *MP)
{
    struct tMyModel *mp = (struct tMyModel*)MP;

    free(mp);
}


static void*
MyDigitalGearSelector_New (struct tInfos *Inf, const char *KindKey)
{
    struct tMyModel *mp = NULL;
    const char *ModelKind;
    char MsgPre[64];
    int VersionId = 0;

    if ((ModelKind = SimCore_GetKindInfo(Inf, ModelClass_VehicleControl, KindKey,
	 				 0, ThisVersionId, &VersionId)) == NULL)
	return NULL;

    mp = (struct tMyModel *)calloc(1, sizeof(*mp));
    if (mp == NULL) {
	LogErrF(EC_Init, "%s: Memory allocation failed.", KindKey);
	goto ErrorReturn;
    }

    sprintf(MsgPre, "%s %s", ThisModelClass, ThisModelKind);

    mp->SelectorCtrlCurr = (tSelectorCtrl)VehicleControl.SelectorCtrl;

    return mp;

ErrorReturn:
    if (mp != NULL) {
	MyDigitalGearSelector_Delete(mp);
    }
    return NULL;
}


int
VehicleControl_Register_MyDigitalGearSelector (void)
{
    tModelClassDescr m;

    memset(&m, 0, sizeof(m));
    m.VehicleControl.VersionId	   =	ThisVersionId;
    m.VehicleControl.New	   = 	MyDigitalGearSelector_New;
    m.VehicleControl.Calc   	   = 	MyDigitalGearSelector_Calc;
    m.VehicleControl.DeclQuants    = 	MyDigitalGearSelector_DeclQuants;
    m.VehicleControl.Delete        =  	MyDigitalGearSelector_Delete;
    /* Should only be used if the model doesn't read params from extra files */
    m.VehicleControl.ParamsChanged = 	ParamsChanged_IgnoreCheck;

    return Model_Register(ModelClass_VehicleControl, ThisModelKind, &m);
}
