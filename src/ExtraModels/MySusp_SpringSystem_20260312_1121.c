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
** Simple suspension Model for SpringSystem
**
** Add the declaration of the register function to one of your header files,
** for example to User.h and call it in User_Register()
**
**    int Susp_SpringSystem_Register_MyModel (void);
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

static const char ThisModelClass[] = "Susp_SpringSystem";
static const char ThisModelKind[]  = "MyModel";
static const int  ThisVersionId    = 1;

#define N_SUSPENSIONS 4

/* model parameters */
struct tMyModel {
    struct tMyFrcSpring {
	double len0;
	double Frc0;
	double dFrc_dl;
    } Spring[N_SUSPENSIONS];
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
MyModel_New (struct tInfos *Inf, struct tSusp_SpringSystemCfgIF *CfgIF, const char *KindKey)
{
    struct tMyModel *mp = NULL;
    int iS, n, VersionId = 0;
    char MsgPre[64];
    const char *ModelKind;
    double *Param[4] = {NULL, NULL, NULL, NULL};

    if ((ModelKind = SimCore_GetKindInfo(Inf, ModelClass_Susp_SpringSystem, KindKey,
	 				 0, ThisVersionId, &VersionId)) == NULL)
	return NULL;

    sprintf (MsgPre, "%s %s", ThisModelClass, ThisModelKind);

    mp = (struct tMyModel*)calloc(1, sizeof(*mp));

    for (iS=0; iS < N_SUSPENSIONS; iS++) {
	char Key[32];
	const char *s = Vehicle_TireNo_Str(iS);
	double	*dv = NULL;

	/* key = <len0> <Frc0> <dFrc/dl> */
	sprintf(Key, "SFH.Spring%s", s);
	dv = iGetTable2(Inf, Key, 3, &n);
	if (dv != NULL) {
	    mp->Spring[iS].len0 =	dv[0];
	    mp->Spring[iS].Frc0 =	dv[1];
	    mp->Spring[iS].dFrc_dl =	dv[2];
	    free(dv);
	} else {
	    LogErrF (EC_Init, "%s: Unsupported argument for '%s'", MsgPre, Key);
	    goto ErrorReturn;
	}
    }
    /* The following lines can be used if the parameters len0 are to be calculated to fit the static equilibrium */
//    for (iS=0; iS < N_SUSPENSIONS; iS++)
//	 Param[iS] = &mp->Spring[iS].len0;
    Susp_SpringSystem_GetCfgOutIF (Inf, CfgIF, ModelKind, Param);

    return mp;

    ErrorReturn:
	if (mp != NULL)
	    free(mp);
    	return NULL;
}


static int
MyModel_Calc (void *MP, tSusp_SpringSystemIF *IF, double dt)
{
    struct tMyModel *mp = (struct tMyModel*)MP;
    int	iS;

    for (iS=0; iS < N_SUSPENSIONS; iS++) {
	IF->Force[iS]
		= mp->Spring[iS].dFrc_dl * (mp->Spring[iS].len0 - IF->length[iS])
		  + mp->Spring[iS].Frc0;
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
Susp_SpringSystem_Register_MyModel (void)
{
    tModelClassDescr m;

    memset (&m, 0, sizeof(m));
    m.Susp_SpringSystem.VersionId =	ThisVersionId;
    m.Susp_SpringSystem.New =		MyModel_New;
    m.Susp_SpringSystem.Calc =		MyModel_Calc;
    m.Susp_SpringSystem.Delete =	MyModel_Delete;
    m.Susp_SpringSystem.DeclQuants =	MyModel_DeclQuants;
    /* Should only be used if the model doesn't read params from extra files */
    m.Susp_SpringSystem.ParamsChanged =	ParamsChanged_IgnoreCheck;

    return Model_Register(ModelClass_Susp_SpringSystem, ThisModelKind, &m);
}
