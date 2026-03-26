/*
 *****************************************************************************
 *  CarMaker - Version 14.1.1
 *  Virtual Test Driving Tool
 *
 *  Copyright ©1998-2025 IPG Automotive GmbH. All rights reserved.
 *  www.ipg-automotive.com
 *****************************************************************************
 *
 * Simple battery controll Model
 *
 * Add the declaration of the register function to one of your header files,
 * for example to User.h and call it in User_Register()
 *
 *    BatteryCU_Register_MyModel ();
 *
 *****************************************************************************
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "CarMaker.h"
#include "Car/Vehicle_Car.h"
#include "MyModels.h"

static char const ThisModelKind[] = "MyModel";
static int const  ThisVersionId   = 1;

struct tMyModel {
    double Capacity_LV;
    double TempCool_in_LV;
};

static void
MyModel_DeclQuants_dyn(struct tMyModel *mp, int park)
{
    static struct tMyModel MyModel_Dummy = {0};
    tDDefault             *df            = DDefaultCreate("PT.BCU.");

    if (park) {
        mp = &MyModel_Dummy;
    }

    DDefDouble4(df, "LV.TempCool_in", "K", &mp->TempCool_in_LV, DVA_IO_In);

    DDefaultDelete(df);

    /* Define here dict entries for dynamically allocated variables. */
}

static void
MyModel_DeclQuants(void *MP)
{
    struct tMyModel *mp = (struct tMyModel *) MP;

    if (mp == NULL) {
        /* Define here dict entries for non-dynamically allocated (static) variables. */

    } else {
        MyModel_DeclQuants_dyn(mp, 0);
    }
}

static void
MyModel_Delete(void *MP)
{
    struct tMyModel *mp = (struct tMyModel *) MP;
    free(mp);
}

static void *
MyModel_New(struct tInfos *Inf, struct tPTBatteryCU_CfgIF *CfgIF, char const *KindKey)
{
    struct tMyModel *mp = NULL;
    char const      *ModelKind;
    int              VersionId = 0;

    if ((ModelKind = SimCore_GetKindInfo(Inf, ModelClass_PTBatteryCU, KindKey, 0, ThisVersionId, &VersionId)) == NULL) {
        return NULL;
    }

    mp                 = (struct tMyModel *) calloc(1, sizeof(*mp));
    mp->Capacity_LV    = CfgIF->BattLV.Capacity;
    mp->TempCool_in_LV = CfgIF->BattLV.TempCool_init;

    return mp;
}

static int
MyModel_Calc(void *MP, struct tPTBatteryCU_IF *IF, double dt)
{
    struct tMyModel *mp = (struct tMyModel *) MP;

    if (!IF->Ignition) {
        IF->BattLV.SOC      = 0.0;
        IF->BattLV.SOH      = 0.0;
        IF->Pwr_HV1toLV_trg = 0.0;
        return 0;
    }

    /* Set battery inlet coolant temperature */
    IF->BattLV.TempCool_in = mp->TempCool_in_LV;

    /* State of charge */
    IF->BattLV.SOC = IF->BattLV.AOC / mp->Capacity_LV * 100.0;

    /* State of health */
    IF->BattLV.SOH = 100.0;

    return 0;
}

int
BatteryCU_Register_MyModel(void)
{
    tModelClassDescr m;

    memset(&m, 0, sizeof(m));
    m.PTBatteryCU.VersionId  = ThisVersionId;
    m.PTBatteryCU.New        = MyModel_New;
    m.PTBatteryCU.Calc       = MyModel_Calc;
    m.PTBatteryCU.Delete     = MyModel_Delete;
    m.PTBatteryCU.DeclQuants = MyModel_DeclQuants;
    m.PTBatteryCU.ModelCheck = NULL;
    /* Should only be used if the model doesn't read params from extra files */
    m.PTBatteryCU.ParamsChanged = ParamsChanged_IgnoreCheck;

    return Model_Register(ModelClass_PTBatteryCU, ThisModelKind, &m);
}
