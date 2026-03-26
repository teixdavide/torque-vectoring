/*
*****************************************************************************
*  CarMaker - Version 14.1.1
*  Virtual Test Driving Tool
*
*  Copyright ©1998-2025 IPG Automotive GmbH. All rights reserved.
*  www.ipg-automotive.com
*****************************************************************************
*
* Simple SelectorCtrlMapping Model to demonstrate the mapping from SelectorCtrl
* to the digital gear selector
*
* Add the declaration of the register function to one of your header files,
* for example to User.h and call it in User_Register()
*
*    SelecCtrlMapping_Register_MySelectorCtrlMapping ();
*
*****************************************************************************
*/

#include <string.h>
#include <stdlib.h>

#include "MyModels.h"
#include "ModelManager.h"
#include "SimCore.h"
#include "Log.h"
#include "Vehicle.h"
#include "DrivMan.h"

static char const ThisModelClass[] = "SelectorCtrlMapping";
static char const ThisModelKind[]  = "MyModel";
static int const  ThisVersionId    = 1;

struct SelecCtrlMap_DGS0 {
    char const   *name;
    tSelectorCtrl Front1;
    tSelectorCtrl Front2;
    tSelectorCtrl Back1;
    tSelectorCtrl Back2;
} SelecCtrlMap_DGS0[] = {
    {"SelectorCtrl_P", SelectorCtrl_N, SelectorCtrl_R, SelectorCtrl_D, SelectorCtrl_D},
    {"SelectorCtrl_N", SelectorCtrl_R, SelectorCtrl_R, SelectorCtrl_D, SelectorCtrl_D},
    {"SelectorCtrl_D", SelectorCtrl_N, SelectorCtrl_R, SelectorCtrl_S, SelectorCtrl_S},
    {"SelectorCtrl_S", SelectorCtrl_N, SelectorCtrl_R, SelectorCtrl_D, SelectorCtrl_D},
    {"SelectorCtrl_R", SelectorCtrl_R, SelectorCtrl_R, SelectorCtrl_N, SelectorCtrl_D},
    {"SelectorCtrl_M", SelectorCtrl_N, SelectorCtrl_R, SelectorCtrl_D, SelectorCtrl_S},
    {NULL}
};

#define UNSET (tSelectorCtrl) - 999

struct SelecCtrlMap_DGS0 SelecCtrlMap_DGS1[] = {
    {"SelectorCtrl_P", SelectorCtrl_P, UNSET, UNSET, UNSET},
    {"SelectorCtrl_N", SelectorCtrl_P, UNSET, UNSET, UNSET},
    {"SelectorCtrl_D", SelectorCtrl_P, UNSET, UNSET, UNSET},
    {"SelectorCtrl_S", SelectorCtrl_P, UNSET, UNSET, UNSET},
    {"SelectorCtrl_R", SelectorCtrl_P, UNSET, UNSET, UNSET},
    {"SelectorCtrl_M", SelectorCtrl_P, UNSET, UNSET, UNSET},
    {NULL}
};

enum {
    Back2  = -2,
    Back1  = -1,
    N      = 0,
    Front1 = 1,
    Front2 = 2
};

struct MyModel {
    tSelectorCtrl SelectorCtrlCurr;
    tSelectorCtrl SelectorCtrl_trg;
    tSelectorCtrl DM_SelectorCtrl_last;
};

static void
MyModel_Delete(void *MP)
{
    struct MyModel *mp = (struct MyModel *) MP;

    free(mp);
}

static void *
MyModel_New(struct tInfos *Inf, char const *KindKey)
{
    struct MyModel *mp = NULL;
    char const     *ModelKind;
    char            MsgPre[64];
    int             VersionId = 0;

    if ((ModelKind = SimCore_GetKindInfo(Inf, ModelClass_SelectorCtrlMapping, KindKey, 0, ThisVersionId, &VersionId))
        == NULL) {
        return NULL;
    }
    mp = (struct MyModel *) calloc(1, sizeof(*mp));
    if (mp == NULL) {
        LogErrF(EC_Init, "%s: Memory allocation failed.", KindKey);
        goto ErrorReturn;
    }

    sprintf(MsgPre, "%s %s", ThisModelClass, ThisModelKind);

    return mp;

ErrorReturn:
    if (mp != NULL) {
        MyModel_Delete(mp);
    }
    return NULL;
}

static tSelectorCtrl
SelecCtrlAction2SelecCtrl(tSelectorCtrlAction SelecCtrlAction)
{
    switch (SelecCtrlAction) {
        case SelCtrlAction_Park:
            return SelectorCtrl_P;
        case SelCtrlAction_Neutral:
            return SelectorCtrl_N;
        case SelCtrlAction_Drive:
            return SelectorCtrl_D;
        case SelCtrlAction_Reverse:
            return SelectorCtrl_R;
        case SelCtrlAction_Sport:
            return SelectorCtrl_S;
        case SelCtrlAction_Manumatic:
            return SelectorCtrl_M;
        default:
            return SelectorCtrl_N;
    }
}

static int
DetectChange(struct tSelectorCtrlMappingIF *IF, int SelectorCtrl_last)
{
    return (SelecCtrlAction2SelecCtrl(IF->SelectorCtrlAction) != SelectorCtrl_last);
}

static tSelectorCtrl
GetSelecCtrl(char const *name)
{
    if (strcmp(name, "SelectorCtrl_P") == 0) {
        return SelectorCtrl_P;
    } else if (strcmp(name, "SelectorCtrl_N") == 0) {
        return SelectorCtrl_N;
    } else if (strcmp(name, "SelectorCtrl_D") == 0) {
        return SelectorCtrl_D;
    } else if (strcmp(name, "SelectorCtrl_S") == 0) {
        return SelectorCtrl_S;
    } else if (strcmp(name, "SelectorCtrl_R") == 0) {
        return SelectorCtrl_R;
    } else if (strcmp(name, "SelectorCtrl_M") == 0) {
        return SelectorCtrl_M;
    }

    return SelectorCtrl_N;
}

static int
CheckForTarget(int *DGS_Out, struct SelecCtrlMap_DGS0 *Map, tSelectorCtrl SelectorCtrl_trg)
{
    int rv = 0;

    if (Map->Front1 == SelectorCtrl_trg) {
        *DGS_Out = 1;
        rv       = 1;
    } else if (Map->Front2 == SelectorCtrl_trg) {
        *DGS_Out = 2;
        rv       = 1;
    } else if (Map->Back1 == SelectorCtrl_trg) {
        *DGS_Out = -1;
        rv       = 1;
    } else if (Map->Back2 == SelectorCtrl_trg) {
        *DGS_Out = -2;
        rv       = 1;
    }

    return rv;
}

static void
SetDigitalGearSelectorValue(tSelectorCtrlMappingIF *IF, tSelectorCtrl SelecCtrlCurr, tSelectorCtrl SelectorCtrl_trg)
{
    int           i;
    tSelectorCtrl SelecCtrl;

    for (i = 0; SelecCtrlMap_DGS0[i].name != NULL; i++) {
        SelecCtrl = GetSelecCtrl(SelecCtrlMap_DGS0[i].name);
        if (SelecCtrl == SelecCtrlCurr) {
            if (CheckForTarget(&IF->DigitalSelectorCtrl_out[0], &SelecCtrlMap_DGS0[i], SelectorCtrl_trg)) {
                return;
            }
        }
    }

    for (i = 0; SelecCtrlMap_DGS1[i].name != NULL; i++) {
        SelecCtrl = GetSelecCtrl(SelecCtrlMap_DGS1[i].name);
        if (SelecCtrl == SelecCtrlCurr) {
            if (CheckForTarget(&IF->DigitalSelectorCtrl_out[1], &SelecCtrlMap_DGS1[i], SelectorCtrl_trg)) {
                return;
            }
        }
    }
}

static void
ResetDigitalGearSelector(tSelectorCtrlMappingIF *IF)
{
    int i;
    for (i = 0; i < N_SELCTRLSIGNALS; i++) {
        IF->DigitalSelectorCtrl_out[i] = 0;
    }
}

static int
MyModel_Calc(void *MP, tSelectorCtrlMappingIF *IF, double dt)
{
    struct MyModel *mp = (struct MyModel *) MP;

    mp->SelectorCtrlCurr = IF->VC_SelectorCtrl_in;
    mp->SelectorCtrl_trg = SelecCtrlAction2SelecCtrl(IF->SelectorCtrlAction);

    if (DetectChange(IF, mp->DM_SelectorCtrl_last)) {
        SetDigitalGearSelectorValue(IF, mp->SelectorCtrlCurr, mp->SelectorCtrl_trg);
    } else {
        ResetDigitalGearSelector(IF);
    }

    mp->DM_SelectorCtrl_last = SelecCtrlAction2SelecCtrl(IF->SelectorCtrlAction);
    IF->DM_SelectorCtrl_out  = mp->SelectorCtrl_trg;

    return 0;
}

int
SelectorCtrlMapping_Register_MySelectorCtrlMapping(void)
{
    tModelClassDescr m;

    memset(&m, 0, sizeof(m));
    m.SelectorCtrlMapping.VersionId  = ThisVersionId;
    m.SelectorCtrlMapping.New        = MyModel_New;
    m.SelectorCtrlMapping.Calc       = MyModel_Calc;
    m.SelectorCtrlMapping.DeclQuants = NULL;
    m.SelectorCtrlMapping.Delete     = MyModel_Delete;
    /* Should only be used if the model doesn't read params from extra files */
    m.VehicleControl.ParamsChanged = ParamsChanged_IgnoreCheck;

    return Model_Register(ModelClass_SelectorCtrlMapping, ThisModelKind, &m);
}
