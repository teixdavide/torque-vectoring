/*
 *****************************************************************************
 *  CarMaker - Version 14.1.1
 *  Virtual Test Driving
 *
 *  Copyright ©1998-2026 IPG Automotive GmbH. All rights reserved.
 *  www.ipg-automotive.com
 *****************************************************************************
 */

#include <Global.h>

#if defined(WIN32)
#  include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_DSRTLX) || defined(_DSRT64)
#  include <DsApplicationInterface.h>
#endif

#include <infoc.h>
#include <CarMaker.h>
#include <ipgdriver.h>
#include <CMDefs.h>
#include <Road.h>

extern const char *SetConnectedIO (const char *io);

static const char *CompileLibs[] = {
    /* C:/IPG/carmaker/win64-14.1.1/lib/libcarmaker.a */
    /* C:/IPG/carmaker/win64-14.1.1/lib/libcar.a */
    /* C:/IPG/carmaker/win64-14.1.1/lib/libipgdriver.a */
    /* C:/IPG/carmaker/win64-14.1.1/lib/libipgroad.a */
    /* C:/IPG/carmaker/win64-14.1.1/lib/libipgtire.a */
    /* C:/IPG/carmaker/win64-14.1.1/Matlab/R2021a/libmatsupp-win64.a */
    "libcarmaker.a	CarMaker win64 14.1.1 2025-07-07",
    "libcar.a	CarMaker-Car win64 14.1.1 2025-07-07",
    "libipgdriver.a	IPGDriver win64 14.1.1 2025-07-04",
    "libipgroad.a	IPGRoad win64 14.1.1 2025-07-03",
    "libipgtire.a	IPGTire win64 9.1.1 2024-10-08",
    "libmatsupp-win64.a	MATSUPP win64 14.1 (R2021a) 2025-05-14",
    NULL
};


static const char *CompileFlags[] = {
    "",
    "Used compiler options are not available for MS Visual Studio builds.",
    NULL
};


tAppStartInfo   AppStartInfo = {
    "Car_Generic <insert.your.version.no>",          /* App_Version         */
    "18",          /* App_BuildVersion    */
    "Simulations",     /* App_CompileUser     */
    "fsfeup-simulati",         /* App_CompileSystem   */
    "2026-03-26 17:05:18",  /* App_CompileTime */

    CompileFlags,                /* App_CompileFlags  */
    CompileLibs,                 /* App_Libs          */

    "14.1.1",          /* SetVersion        */

    NULL,           /* TestRunName       */
    NULL,           /* TestRunFName      */
    NULL,           /* TestRunVariation  */
    NULL,           /* LogFName          */

    0,              /* SaveMode          */
    0,              /* OnErrSaveHist     */

    0,              /* Verbose           */
    0,              /* Comments          */
    0,              /* ModelCheck        */
    0,              /* Snapshot          */
    0,              /* DriverAdaption    */
    0,              /* Log2Screen        */
    0,              /* ShowDataDict      */
    0,              /* DontHandleSignals */
    {0, 0, NULL},   /* Suffixes          */
    {0, 0, NULL}    /* Keys              */
};



void
App_InfoPrint (void)
{
    int i;
    Log ("Application.Version       = %s #%s (%s)\n",
            AppStartInfo.App_Version,
            AppStartInfo.App_BuildVersion,
            SimCoreInfo.Version);
    Log ("Application.Compiled      = %s@%s %s\n",
            AppStartInfo.App_CompileUser,
            AppStartInfo.App_CompileSystem,
            AppStartInfo.App_CompileTime);
    Log ("Application.BuildVersion  = %s\n", AppStartInfo.App_BuildVersion);
    Log ("Application.CompileTime   = %s\n", AppStartInfo.App_CompileTime);
    Log ("Application.CompileUser   = %s\n", AppStartInfo.App_CompileUser);
    Log ("Application.CompileSystem = %s\n", AppStartInfo.App_CompileSystem);

    i = 0;
    Log ("Application.CompileFlags:\n");
    while (AppStartInfo.App_CompileFlags != NULL
        && AppStartInfo.App_CompileFlags[i] != NULL) {
        Log ("			%s\n", AppStartInfo.App_CompileFlags[i++]);
    }

    i = 0;
    Log ("Application.Libs:\n");
    while (AppStartInfo.App_Libs != NULL && AppStartInfo.App_Libs[i] != NULL)
        Log ("			%s\n", AppStartInfo.App_Libs[i++]);

#if 0
    /* Security */
    i = 0;
    Log ("Application.Suffixes:\n");
    while (AppStartInfo.Suffix.List != NULL && AppStartInfo.Suffix.List[i] != NULL)
        Log ("			%s\n", AppStartInfo.Suffix.List[i++]);

    i = 0;
    Log ("Application.Keys:\n");
    while (AppStartInfo.Key.List != NULL && AppStartInfo.Key.List[i] != NULL)
        Log ("			%s\n", AppStartInfo.Key.List[i++]);


    /*** Linked libraries */
    Log ("Application.Version.Driver =\t%s\n",  IPGDrv_LibVersion);
    Log ("Application.Version.Road =\t%s\n",    RoadLibVersion);
#endif
}




int
App_ExportConfig (void)
{
    int        i, n;
    char       *txt[42], sbuf[512];
    char const *item;
    tInfos *inf = SimCore.Config.Inf;

    InfoSetStr (inf, "Application.Version",       AppStartInfo.App_Version);
    InfoSetStr (inf, "Application.BuildVersion",  AppStartInfo.App_BuildVersion);
    InfoSetStr (inf, "Application.CompileTime",   AppStartInfo.App_CompileTime);
    InfoSetStr (inf, "Application.CompileUser",   AppStartInfo.App_CompileUser);
    InfoSetStr (inf, "Application.CompileSystem", AppStartInfo.App_CompileSystem);
    if (AppStartInfo.App_CompileFlags != NULL)
        InfoSetTxt (inf, "Application.CompileFlags",
                    (char**)AppStartInfo.App_CompileFlags);
    InfoAddLineBehind (inf, NULL, "");
    if (AppStartInfo.App_Libs != NULL)
        InfoSetTxt (inf, "Application.Libs",
                    (char**)AppStartInfo.App_Libs);
    InfoAddLineBehind (inf, NULL, "");

    /*** Linked libraries */
    InfoSetStr (inf, "Application.Version.Driver",  IPGDrv_LibVersion);
    InfoSetStr (inf, "Application.Version.Road",    RoadLibVersion);
    InfoAddLineBehind (inf, NULL, "");

    /*** I/O configuration */
    IO_ListNames(sbuf, -1);

    n = 0;
    txt[n] = NULL;
    while (1) {
	item = strtok((n==0 ? sbuf : NULL), " \t");
	if (item == NULL || n >= 42-1)
	    break;

	txt[n++] = strdup(item);
	txt[n] =   NULL;
    }

    InfoSetTxt (inf, "IO.Configs", txt);
    InfoAddLineBehind (inf, NULL, "");

    for (i=0; i < n; i++)
	free (txt[i]);

    return 0;
}


