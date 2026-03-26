/*
 *****************************************************************************
 *  CarMaker - Version 14.1.1
 *  Virtual Test Driving Tool
 *
 *  Copyright ©1998-2025 IPG Automotive GmbH. All rights reserved.
 *  www.ipg-automotive.com
 *****************************************************************************
 *
 * Simple motor controll Model
 *
 * Add the declaration of the register function to one of your header files,
 * for example to User.h and call it in User_Register()
 *
 *    MotorCU_Register_MyModel ();
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
    double limrotv;
};

static void *
MyModel_New(struct tInfos *Inf, struct tPTMotorCU_CfgIF *CfgIF, char const *KindKey)
{
    struct tMyModel *mp = NULL;
    char const      *ModelKind;
    int              VersionId = 0;

    if ((ModelKind = SimCore_GetKindInfo(Inf, ModelClass_PTMotorCU, KindKey, 0, ThisVersionId, &VersionId)) == NULL) {
        return NULL;
    }

    mp          = (struct tMyModel *) calloc(1, sizeof(*mp));
    mp->limrotv = 0.5;

    return mp;
}

static int
MyModel_Calc(void *MP, struct tPTMotorCU_IF *IF, double dt)
{
    struct tMyModel        *mp    = (struct tMyModel *) MP;
    tPTMotorCU_CfgIF const *CfgIF = IF->CfgIF;

    if (!IF->Ignition) {
        IF->ISGOut.Load       = 0.0;
        IF->ISGOut.TrqMot_max = 0.0;
        IF->ISGOut.TrqGen_max = 0.0;
        return 0;
    }

#ifdef __cplusplus
    struct tPTMotorCU_IF::tPTMotorCU_IF_MotorIn  *IFIn  = &IF->ISGIn;
    struct tPTMotorCU_IF::tPTMotorCU_IF_MotorOut *IFOut = &IF->ISGOut;
#else
    struct tPTMotorCU_IF_MotorIn  *IFIn  = &IF->ISGIn;
    struct tPTMotorCU_IF_MotorOut *IFOut = &IF->ISGOut;
#endif
    double rotv, lim_rotv;
    int    MotMode = (IFIn->Trq_trg >= 0.0 && IFIn->rotv >= -mp->limrotv)
               || (IFIn->Trq_trg < 0.0 && IFIn->rotv < mp->limrotv);

    /* max motor/generator torque */
    rotv = fabs(IFIn->rotv) * CfgIF->ISG.Ratio;
    if (CfgIF->ISG.TrqMot_max != NULL) {
        IFOut->TrqMot_max = LMEval(CfgIF->ISG.TrqMot_max, rotv) * CfgIF->ISG.Ratio;
    }
    if (CfgIF->ISG.TrqGen_max != NULL) {
        IFOut->TrqGen_max = -LMEval(CfgIF->ISG.TrqGen_max, rotv) * CfgIF->ISG.Ratio;
    }

    if (MotMode) {
        lim_rotv = fabs(CfgIF->ISG.rotv_Mot_max);
    } else {
        lim_rotv = fabs(CfgIF->ISG.rotv_Gen_max);
    }

    if (IFOut->Load == NOTSET) {
        IFOut->Load = 0.0;
    }
    IFOut->Load = M_BOUND(-1.0, 1.0, IFOut->Load);

    if (fabs(IFIn->rotv) > lim_rotv && IFIn->rotv_trg == NOTSET) {
        IFOut->Load = 0.0;
    }

    return 0;
}

static void
MyModel_Delete(void *MP)
{
    struct tMyModel *mp = (struct tMyModel *) MP;

    free(mp);
}

int
MotorCU_Register_MyModel(void)
{
    tModelClassDescr m;

    memset(&m, 0, sizeof(m));
    m.PTMotorCU.VersionId  = ThisVersionId;
    m.PTMotorCU.New        = MyModel_New;
    m.PTMotorCU.Calc       = MyModel_Calc;
    m.PTMotorCU.Delete     = MyModel_Delete;
    m.PTMotorCU.DeclQuants = NULL;
    /* Should only be used if the model doesn't read params from extra files */
    m.PTMotorCU.ParamsChanged = ParamsChanged_IgnoreCheck;

    return Model_Register(ModelClass_PTMotorCU, ThisModelKind, &m);
}
