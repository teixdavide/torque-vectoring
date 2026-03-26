/*
 *****************************************************************************
 *  CarMaker - Version 14.1.1
 *  Virtual Test Driving Tool
 *
 *  Copyright ©1998-2025 IPG Automotive GmbH. All rights reserved.
 *  www.ipg-automotive.com
 *****************************************************************************
 *
 * Simple inverter model
 *
 * Add the declaration of the register function to one of your header files,
 * for example to User.h and call it in User_Register()
 *
 *    Inverter_Register_MyModel ();
 *
 *****************************************************************************
 */

#include <stdlib.h>
#include <string.h>

#include "CarMaker.h"
#include "Car/Vehicle_Car.h"
#include "MyModels.h"
#include "MapUtils.h"

static char const ThisModelKind[]  = "MyModel";
static char const ThisModelPre[]   = "MyModel.Inverter";
static char const ThisModelClass[] = "PowerTrain.Inverter";
static int const  ThisVersionId    = 1;

struct tMyModel {
    int    MotorType;    /* Differentiate between mapping model and PMSM      */
    tLM2D *PwrLossMap;   /* Power loss map [W]                                */
    double PwrLoss_theo; /* Theoretical power loss [W]                        */
    int    nPolePairs;   /* Number of pole pairs []                           */
};

static void
MyModel_DeclQuants_dyn(struct tMyModel *mp, int park)
{
    static struct tMyModel MyModel_Dummy;
    memset(&MyModel_Dummy, 0, sizeof(struct tMyModel));
    if (park) {
        mp = &MyModel_Dummy;
    }

    /* Define here dict entries for dynamically allocated variables. */
}

static void
MyModel_DeclQuants(void *MP, char const *Ident)
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

static void
Unset_Unused_Outputs_Mapping(double *Voltage_dq, double *Voltage_uvw)
{
    int i;
    for (i = 0; i < 2; i++) {
        Voltage_dq[i] = NOTSET;
    }
    for (i = 0; i < 3; i++) {
        Voltage_uvw[i] = NOTSET;
    }
}

static double
Get_Pwr_Loss(struct tMyModel *mp, double rotv, double torque)
{
    double Loss = 0.0;

    if (mp->PwrLossMap != NULL) {
        Loss = LM2DEval(mp->PwrLossMap, rotv, torque);
    } else {
        Loss = 0.0;
    }

    return Loss;
}

static void
Calc_PwrLoss(double *PwrElec, double *PwrLoss, double PwrLoss_theo)
{
    if (*PwrElec < 0.0 && PwrLoss_theo + *PwrElec > 0.0) {
        *PwrLoss = -*PwrElec;
    } else {
        *PwrLoss = PwrLoss_theo;
    }
}

static void
Calc_Inverter4MappingMotor(struct tMyModel *mp, struct tPTInverterIF *IF, double dt)
{
    double Pwr_Total = 0;

    mp->PwrLoss_theo = Get_Pwr_Loss(mp, IF->Motor_rotv, IF->Motor_Trq);

    Calc_PwrLoss(&IF->PwrElec, &IF->PwrLoss, mp->PwrLoss_theo);

    Pwr_Total = IF->PwrElec + IF->PwrLoss;

    IF->Current_Batt = Pwr_Total / IF->Volt_Batt;
    IF->Load_out     = IF->Load_in;
    Unset_Unused_Outputs_Mapping(IF->Voltage_dq, IF->Voltage_uvw);
}

static void
Unset_Unused_Outputs_PMSM(double *Load)
{
    *Load = NOTSET;
}

static void
Calc_Voltage_dq(struct tPTInverterIF *IF)
{
    double rot        = IF->Motor_rot * IF->CfgIF->nPolePairs;
    IF->Voltage_dq[0] = 0.667
                      * (IF->Voltage_uvw[0] * cos(rot) + IF->Voltage_uvw[1] * cos(rot - 0.667 * 3.14)
                          + IF->Voltage_uvw[2] * cos(rot + 0.667 * 3.14));
    IF->Voltage_dq[1] = 0.667
                      * (-IF->Voltage_uvw[0] * sin(rot) - IF->Voltage_uvw[1] * sin(rot - 0.667 * 3.14)
                          - IF->Voltage_uvw[2] * sin(rot + 0.667 * 3.14));
}

static void
Calc_Inverter4PMSMMotor(struct tMyModel *mp, struct tPTInverterIF *IF, double dt)
{
    int    i;
    double Pwr_Total = 0;

    Unset_Unused_Outputs_PMSM(&IF->Load_out);

    for (i = 0; i < 3; i++) {
        IF->Voltage_uvw[i] = IF->GateSignal[i];
    }

    Calc_Voltage_dq(IF);

    mp->PwrLoss_theo = Get_Pwr_Loss(mp, IF->Motor_rotv, IF->Motor_Trq);

    Pwr_Total = IF->PwrElec + IF->PwrLoss;

    IF->Current_Batt = Pwr_Total / IF->Volt_Batt;
}

static int
MyModel_Calc(void *MP, struct tPTInverterIF *IF, double dt)
{
    struct tMyModel *mp = (struct tMyModel *) MP;
    if (mp->MotorType == MotorCtrlMode_Mapping) {
        Calc_Inverter4MappingMotor(mp, IF, dt);
    } else if (mp->MotorType == MotorCtrlMode_PMSM) {
        Calc_Inverter4PMSMMotor(mp, IF, dt);
    }

    return 0;
}

static struct tLM2D *
Get_InverterPwrLossMap(struct tInfos *Inf, char const *PreKey, char const *MsgPre)
{
    char         **txt = NULL;
    char           key[96];
    tLM2D         *LossMap = NULL;
    struct tMData *md      = NULL;

    sprintf(key, "%s%s", PreKey, "LossMap");

    txt = iGetTxtOpt(Inf, key);
    if (txt == NULL || txt[0] == NULL) {
        goto ErrorReturn;
    }

    if ((md = GetAquiMap2D_f(txt, (char *) MsgPre, "rotation", "torque", "PwrLoss", 1.0, 1.0, 1.0, 0.001)) == NULL) {
        goto ErrorReturn;
    }

    LossMap = LM2DInitMD(md, ArrayAequi, ArrayAequi);
    MDataDelete(md);
    md = NULL;

    if (LossMap == NULL) {
        goto ErrorReturn;
    }

    free(txt);

    return LossMap;

ErrorReturn:
    if (md != NULL) {
        MDataDelete(md);
    }
    if (txt != NULL) {
        free(txt);
    }
    return NULL;
}

static void *
MyModel_New(struct tInfos *Inf, struct tPTInverterCfgIF *CfgIF, char const *KindKey, char const *Ident)
{
    struct tMyModel *mp = NULL;
    char const      *ModelKind;
    char             MsgPre[64];
    char             PreKey[64];
    int              VersionId = 0;

    sprintf(PreKey, "%s.%s.", ThisModelPre, Ident);
    sprintf(MsgPre, "%s %s", ThisModelClass, ThisModelKind);

    if ((ModelKind = SimCore_GetKindInfo(Inf, ModelClass_PTInverter, KindKey, 0, ThisVersionId, &VersionId)) == NULL) {
        return NULL;
    }

    mp = (struct tMyModel *) calloc(1, sizeof(*mp));
    if (mp == NULL) {
        LogErrF(EC_Init, "%s: Out of memory.", MsgPre);
        return NULL;
    }

    mp->MotorType  = CfgIF->MotorType;
    mp->nPolePairs = CfgIF->nPolePairs;
    mp->PwrLossMap = Get_InverterPwrLossMap(Inf, PreKey, MsgPre);

    return mp;
}

int
Inverter_Register_MyModel(void)
{
    tModelClassDescr m;

    memset(&m, 0, sizeof(m));
    m.PTInverter.VersionId  = ThisVersionId;
    m.PTInverter.New        = MyModel_New;
    m.PTInverter.Calc       = MyModel_Calc;
    m.PTInverter.Delete     = MyModel_Delete;
    m.PTInverter.DeclQuants = MyModel_DeclQuants;
    /*PT Should only be used if the model doesn't read params from extra files */
    m.PTInverter.ParamsChanged = ParamsChanged_IgnoreCheck;

    return Model_Register(ModelClass_PTInverter, ThisModelKind, &m);
}
