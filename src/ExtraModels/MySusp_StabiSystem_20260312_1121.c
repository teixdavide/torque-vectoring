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
** Simple suspension Model for Stabi
**
** Add the declaration of the register function to one of your header files,
** for example to User.h and call it in User_Register()
**
**    int Susp_StabiSystem_Register_MyModel (void);
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

static const char ThisModelClass[] = "Susp_StabiSystem";
static const char ThisModelKind[]  = "MyModel";
static const int  ThisVersionId    = 1;

#define N_SUSPENSIONS 4

/* model parameters */
struct tMyModel {
    struct tMyFrcStabi {
	double dFrc_dl;
    } Stabi[N_SUSPENSIONS];
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
MyModel_DeclQuants (void *MP)
{
    struct tMyModel *mp = (struct tMyModel *)MP;

    if (mp == NULL) {
	/* Define here dict entries for non-dynamically allocated (static) variables. */

    } else {
	MyModel_DeclQuants_dyn (mp, 0);
    }
}


static void *
MyModel_New (struct tInfos *Inf, struct tSusp_StabiSystemCfgIF *CfgIF, const char *KindKey)
{
    struct tMyModel *mp = NULL;
    int iS, VersionId = 0;
    char MsgPre[64];
    const char *ModelKind;

    if ((ModelKind = SimCore_GetKindInfo(Inf, ModelClass_Susp_StabiSystem, KindKey,
	 				 0, ThisVersionId, &VersionId)) == NULL)
	return NULL;

    sprintf (MsgPre, "%s %s", ThisModelClass, ThisModelKind);

    mp = (struct tMyModel*)calloc(1, sizeof(*mp));

    for (iS=0; iS < N_SUSPENSIONS; iS++) {
	char Key[32];
	const char *s = Vehicle_TireNo_Str(iS);

	/* key = <dF/dl> */
	sprintf(Key, "SFH.Stabi%s", s);
	mp->Stabi[iS].dFrc_dl = iGetDbl(Inf, Key);
    }

    Susp_StabiSystem_GetCfgOutIF (Inf, CfgIF, ModelKind);

    return mp;
}


static int
MyModel_Calc (void *MP, tSusp_StabiSystemIF *IF, double dt)
{
    struct tMyModel *mp = (struct tMyModel*)MP;
    int	iS;

    for (iS=0; iS < N_SUSPENSIONS; iS += 2) {
	/* Frc = c * (right - left) */
	IF->Force[iS]   = mp->Stabi[iS].dFrc_dl * (IF->length[iS+1] - IF->length[iS]);
	IF->Force[iS+1] = -IF->Force[iS];
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
Susp_StabiSystem_Register_MyModel (void)
{
    tModelClassDescr m;

    memset (&m, 0, sizeof(m));
    m.Susp_StabiSystem.VersionId =	ThisVersionId;
    m.Susp_StabiSystem.New =		MyModel_New;
    m.Susp_StabiSystem.Calc =		MyModel_Calc;
    m.Susp_StabiSystem.Delete =	MyModel_Delete;
    m.Susp_StabiSystem.DeclQuants =	MyModel_DeclQuants;
    /* Should only be used if the model doesn't read params from extra files */
    m.Susp_StabiSystem.ParamsChanged =	ParamsChanged_IgnoreCheck;

    return Model_Register(ModelClass_Susp_StabiSystem, ThisModelKind, &m);
}
