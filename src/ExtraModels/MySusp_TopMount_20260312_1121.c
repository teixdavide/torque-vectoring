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
** Simple suspension Model for TopMount
**
** Add the declaration of the register function to one of your header files,
** for example to User.h and call it in User_Register()
**
**    int Susp_TopMount_Register_MyModel (void);
**
******************************************************************************
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "CarMaker.h"
#include "Car/Car.h"
#include "Car/Vehicle_Car.h"
#include "MyModels.h"
#include "Log.h"

static const char ThisModelClass[] = "Susp_TopMount";
static const char ThisModelKind[]  = "MyModel";
static const int  ThisVersionId    = 1;

/* model parameters */
struct tMyModel {
    double mass;	/* mass between TopMount and Damper */
    double cTM;		/* stiffness */
    double dTM; 	/* damping rate */
    double x, dx, ddx;	/* length, velocity and acceleration */
};


static void
MyModel_DeclQuants_dyn (struct tMyModel *mp, int park)
{
    static struct tMyModel MyModel_Dummy;
    memset (&MyModel_Dummy, 0, sizeof(struct tMyModel));
    if (park)
	mp = &MyModel_Dummy;

    /* Define here dict entries for dynamically allocated variables. */
}


static void
MyModel_DeclQuants (void *MP, int SuspModID)
{
    struct tMyModel *mp = (struct tMyModel *)MP;

    if (mp == NULL) {
	/* Define here dict entries for non-dynamically allocated (static) variables. */

    } else {
	MyModel_DeclQuants_dyn (mp, 0);
    }
}


static void *
MyModel_New (struct tInfos *Inf, struct tSusp_TopMountCfgIF *CfgIF, const char *KindKey)
{
    struct tMyModel *mp = NULL;
    int VersionId = 0;
    char MsgPre[64];
    const char *ModelKind;

    if ((ModelKind = SimCore_GetKindInfo(Inf, ModelClass_Susp_TopMount, KindKey,
	 				 0, ThisVersionId, &VersionId)) == NULL)
	return NULL;

    sprintf (MsgPre, "%s %s", ThisModelClass, ThisModelKind);

    mp = (struct tMyModel*)calloc(1, sizeof(*mp));

    char Key[32];
    const char *s = SuspMod_SuspPre(CfgIF->SuspModID);

    /* initialize model state */
    mp->x   = 0.0;
    mp->dx  = 0.0;

    /* This is a very simple model which will only be numerically stable with
     * - a "soft" damper model,
     * - a big TopMount mass and
     * - suitable TopMount spring and damper rates. */

    sprintf(Key, "SFH.%s.cTM", s);
    mp->cTM = iGetDbl(Inf, Key);

    sprintf(Key, "SFH.%s.dTM", s);
    mp->dTM = iGetDbl(Inf, Key);

    sprintf(Key, "SFH.%s.mass", s);
    mp->mass = iGetDbl(Inf, Key);

    Susp_TopMount_GetCfgOutIF(Inf, CfgIF, ModelKind);

    return mp;
}


static int
MyModel_Calc (void *MP, tSusp_TopMountIF *IF, double dt)
{
    struct tMyModel *mp = (struct tMyModel*)MP;
    int i;
    const int OSRate = 10;

    if (dt != 0) {
	dt = dt/OSRate;		/* Oversampling */
	for (i = 0; i < OSRate; i++) {
	    mp->ddx  = (IF->damper.Force - mp->x * mp->cTM - mp->dx * mp->dTM) / mp->mass;
	    mp->x   += mp->dx * dt;
	    mp->dx  += mp->ddx * dt;
	}

	IF->Force  = mp->cTM * mp->x + mp->dTM * mp->dx;
	IF->length = mp->x;
	IF->vel    = mp->dx;
    } else {
	/* Behaviour in preparation phase and for model check: fixed TopMount */
	IF->Force  = IF->damper.Force; /* Actio = Reactio */
	IF->length = 0.0; 	/* Fixed spring of TopMount */
	IF->vel    = 0.0; 	/* Fixed damper of TopMount */
    }

    return 0;
}


static void
MyModel_Delete (void *MP)
{
    struct tMyModel *mp = (struct tMyModel*)MP;

    if (mp != NULL)
	free (mp);
    mp = NULL;
}


int
Susp_TopMount_Register_MyModel (void)
{
    tModelClassDescr m;

    memset (&m, 0, sizeof(m));
    m.Susp_TopMount.VersionId =	  ThisVersionId;
    m.Susp_TopMount.New =	  MyModel_New;
    m.Susp_TopMount.Calc =	  MyModel_Calc;
    m.Susp_TopMount.Delete =	  MyModel_Delete;
    m.Susp_TopMount.DeclQuants =  MyModel_DeclQuants;
    /* Should only be used if the model doesn't read params from extra files */
    m.Susp_TopMount.ParamsChanged = ParamsChanged_IgnoreCheck;

    return Model_Register(ModelClass_Susp_TopMount, ThisModelKind, &m);
}
