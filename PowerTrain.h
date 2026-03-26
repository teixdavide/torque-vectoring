/*
 *****************************************************************************
 *  CarMaker - Version 14.1.1
 *  Virtual Test Driving Tool
 *
 *  Copyright ©1998-2025 IPG Automotive GmbH. All rights reserved.
 *  www.ipg-automotive.com
 *****************************************************************************
 *
 * PowerTrain
 *
 *
 *****************************************************************************
 */

#ifndef _POWERTRAIN_H__
#define _POWERTRAIN_H__

#include "DrivMan.h"
#include "Vehicle.h"

#define NOTSET -99999
#ifndef N_DRIVESOURCE
# define N_DRIVESOURCE VEHICLE_NWHLS /* defined in Vehicle.h */
#endif
#ifndef N_MOTOR
# define N_MOTOR VEHICLE_NWHLS /* defined in Vehicle.h */
#endif
#ifndef N_ISG
# define N_ISG 1
#endif
#ifndef N_CLUTCH
# define N_CLUTCH 12
#endif
#ifndef N_PLANETGEAR
# define N_PLANETGEAR 1
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct tInfos;
struct tMData;
struct tLM;

typedef struct tPTBdy {
    tBdy            Bdy;            /* Bdy in Fr1                                   */
    tMountFrameVhcl Frame;          /* mounting Frame                               */
    double          Orientation[3]; /* Orientation between Fr1 and body-fixed frame */
} tPTBdy;

/** Universal MC*******************************************************************/

#define N_UNIVERSALMC        128
#define N_UNIVERSALMC_TABLES 10

typedef struct tUniversalMC_CfgIF {
    double Input[N_UNIVERSALMC];
    double Output[N_UNIVERSALMC];

    struct tLM   *tLM_Input[N_UNIVERSALMC_TABLES];
    struct tLM   *tLM_Output[N_UNIVERSALMC_TABLES];
    struct tLM2D *tLM2D_Input[N_UNIVERSALMC_TABLES];
    struct tLM2D *tLM2D_Output[N_UNIVERSALMC_TABLES];
} tUniversalMC_CfgIF;

typedef struct tUniversalMC_IF {
    tUniversalMC_CfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    double Input[N_UNIVERSALMC];

    /* Outputs */
    double Output[N_UNIVERSALMC];
} tUniversalMC_IF;

/** Free End *****************************************************************/

typedef struct tPTFreeEndIF {
    double Trq_ext;

    // Inputs
    double Trq_in;
    double Inert_in;

    // Outputs
    double rotv;
    double rot;
} tPTFreeEndIF;

/** Engine *******************************************************************/

typedef struct tPTEngineCU_CfgIF {
    /* Inputs */
    double      rotv_off;  /* Engine off speed [rad/s]                     */
    double      rotv_max;  /* Engine maximum speed [rad/s]                 */
    double      rotv_idle; /* Engine idle speed [rad/s]                    */
    double      rotv_opt;  /* Engine optimum speed with minimum be [rad/s] */
    struct tLM *TrqFull;   /* 1D-Lookup table for max. engine full torque  */
    struct tLM *TrqDrag;   /* 1D-Lookup table for max. engine drag torque  */
    struct tLM *TrqOpt;    /* 1D-Lookup table for engine torque with
                              optimal consumption (minimal specific fuel
                              consumption as function of engine speed)     */
} tPTEngineCU_CfgIF;

typedef struct tPTEngineCU_IF {
    tPTEngineCU_CfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    int    Ignition; /* Ignition                                  */
    int    set_ISC;  /* Flag for idle speed controller activation */
    double Trq_trg;  /* Target engine torque [Nm]                 */
    double Trq;      /* Current engine torque [Nm]                */
    double rotv_trg; /* Target engine speed [rad/s]               */
    double rotv;     /* Current Engine speed [rad/s]              */
    double rot;      /* Engine rotational angle [rad]             */
    double FuelFlow; /* Current fuel flow [l/s]                   */

    /* Outputs */
    int    Status;     /* Engine CU status                             */
    int    FuelCutOff; /* Flag if fuel is cut-off (gets also as Input) */
    char   Engine_on;  /* Flag if engine is over the engine off speed  */
    double Load;       /* Engine throttle (gets also as Input) []      */
    double TrqDrag;    /* Engine drag torque [Nm]                      */
    double TrqFull;    /* Engine full load torque [Nm]                 */
    double TrqOpt;     /* Engine torque with optimal consumption [Nm]  */
} tPTEngineCU_IF;

typedef struct tPTEngineCfgIF {
    /* Inputs */
    double          FuelDensity;        /* Fuel density [kg/m^3]                        */
    tMountFrameVhcl Frame;              /* mounting Frame                               */
    double          Orientation[3];     /* Orientation between Fr1 and body-fixed frame */
    tMountFrameVhcl FrameTank;          /* mounting Frame                               */
    double          OrientationTank[3]; /* Orientation between Fr1 and body-fixed frame */

    /* In/Outputs */
    tBdy Bdy;     /* Bdy in Fr1 - in: pos, out: mass, I */
    tBdy BdyTank; /* Bdy in Fr1 - in: pos, out: mass, I */

    /* Outputs */
    double      rotv_off;                 /* Engine off speed [rad/s]                     */
    double      rotv_max;                 /* Engine maximum speed [rad/s]                 */
    double      rotv_idle;                /* Engine idle speed [rad/s]                    */
    double      rotv_opt;                 /* Engine optimum speed with minimum be [rad/s] */
    struct tLM *TrqFull;                  /* 1D-Lookup table for max. engine full torque  */
    struct tLM *TrqDrag;                  /* 1D-Lookup table for max. engine drag torque  */
    struct tLM *TrqOpt;                   /* 1D-Lookup table for engine torque with
                                             optimal consumption (minimal specific fuel
                                             consumption as function of engine speed)     */
    double      CrankshaftOrientation[3]; /* Crankshaft Orientation in Fr1                */
} tPTEngineCfgIF;

typedef struct tPTEngineIF {
    tPTEngineCfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    int    Ignition;   /* Ignition                      */
    int    FuelCutOff; /* Flag if fuel is cut-off       */
    double Load;       /* Engine throttle []            */
    double FuelLevel;  /* Current fuel level [%]        */
    double rot;        /* Engine rotation [rad]         */
    double rotv;       /* Engine rotation speed [rad/s] */

    /* Outputs */
    double Trq;      /* Engine torque [Nm]      */
    double Inert;    /* Engine inertia [kgm^2]  */
    double FuelFlow; /* Current fuel flow [l/s] */
} tPTEngineIF;

/** Motor / ISG **************************************************************/

typedef enum {
    PowerSupply_LV = 0,
    PowerSupply_HV1,
    PowerSupply_HV2
} tPTPowerSupply_Level;

typedef enum {
    MotorCtrlMode_Mapping = 0,
    MotorCtrlMode_PMSM,
    MotorCtrlMode_Plugin
} tPTMotor_CtrlMode;

typedef struct tPTMotorCU_CfgIF {
    /* Inputs */
    int nMotor; /* Number of motors (not ISG included) */

    struct tPTMotorCU_CfgIF_Motor {
        tPTMotor_CtrlMode CtrlMode; /* Mode determines control strategy           */

        double      Ratio;          /* Ratio between motor shaft and driven shaft */
        struct tLM *TrqMot_max;     /* 1D-Lookup table for max. motor torque      */
        double      rotv_Mot_max;   /* Maximum motor rotation [rad/s]             */
        struct tLM *TrqGen_max;     /* 1D-Lookup table for max. generator torque  */
        double      rotv_Gen_max;   /* Maximum generator rotation [rad/s]         */
        int         nPolePairs;     /* Number of pole pairs []                    */
        double      L_d;            /* Inductance in d coordinate [H]             */
        double      L_q;            /* Inductance in q coordinate [H]             */
        double      Psi_PM;         /* Magnetic flux of the permanent magnet [Wb] */
    } ISG, Motor[N_MOTOR];
} tPTMotorCU_CfgIF;

typedef struct tPTMotorCU_IF {
    tPTMotorCU_CfgIF const *CfgIF;

    /* Inputs */
    int Ignition; /* Ignition   */

    struct tPTMotorCU_IF_MotorIn {
        double Trq_trg;        /* Target motor torque on driven shaft [Nm]                */
        double Trq;            /* Current motor torque on driven shaft [Nm]               */
        double rotv_trg;       /* Target motor rotation of driven shaft [rad/s]           */
        double rotv;           /* Current motor rotation of driven shaft [rad/s]          */
        double rot;            /* Rotation of driven shaft [rad]                          */
        double PwrElec;        /* Electrical power (generator, motor) [W]                 */
        double VoltBatt;       /* Accessible battery voltage of connected power level [V] */
        double Current_dq[2];  /* Electric current in rotor fixed dq coordinates [A]      */
        double Current_uvw[3]; /* Electric phase currents [A]                             */
    } ISGIn, MotorIn[N_MOTOR];

    /* Outputs */
    int Status; /* Motor CU status */

    struct tPTMotorCU_IF_MotorOut {
        double Load;           /* Control signal (gets also as Input) []                */
        double TrqMot_max;     /* Current maximum motor torque on driven shaft [Nm]     */
        double TrqGen_max;     /* Current maximum generator torque on driven shaft [Nm] */
        double Voltage_dq[2];  /* Electric voltage in rotor fixed dq coordinates [V]    */
        double Voltage_uvw[3]; /* Electric phase voltages [V]                           */
    } ISGOut, MotorOut[N_MOTOR];

} tPTMotorCU_IF;

typedef struct tPTMotorCfgIF {
    /* Inputs */
    tMountFrameVhcl Frame;          /* mounting Frame                               */
    double          Orientation[3]; /* Orientation between Fr1 and body-fixed frame */

    /* In/Outputs */
    tBdy Bdy; /* Bdy in Fr1 - in: pos, out: mass, I */

    /* Outputs */
    tPTMotor_CtrlMode CtrlMode; /* Motor Mode to determine parameter configuration */

    struct {
        int    nPolePairs; /* Number of pole pairs []                    */
        double L_d;        /* Inductance in d coordinate [H]             */
        double L_q;        /* Inductance in q coordinate [H]             */
        double Psi_PM;     /* Magnetic flux of the permanent magnet [Wb] */
    } PMSM;

    tPTPowerSupply_Level Level;        /* PowerSupply voltage level                  */
    double               Ratio;        /* Ratio between motor shaft and driven shaft */
    struct tLM          *TrqMot_max;   /* 1D-Lookup table for max. motor torque      */
    double               rotv_Mot_max; /* Maximum motor rotation [rad/s]             */
    struct tLM          *TrqGen_max;   /* 1D-Lookup table for max. generator torque  */
    double               rotv_Gen_max; /* Maximum generator rotation [rad/s]         */
} tPTMotorCfgIF;

typedef struct tPTMotorIF {
    tPTMotorCfgIF const *CfgIF; /* Pointer to CfgIF struct                      */

    /* Inputs */
    double rot;            /* Rotation of driven shaft [rad]                   */
    double rotv;           /* Rotation speed of driven shaft [rad/s]           */
    double VoltBatt;       /* Accessible battery voltage [V]                   */
    double Load;           /* Control signal []                                */
    double Voltage_dq[2];  /* Voltage vector in rotor fixed dq coordinates [V] */
    double Voltage_uvw[3]; /* Electric phase voltages [V]                      */

    /* Outputs */
    double Trq;            /* Motor torque on driven shaft [Nm]                */
    double Inert;          /* Motor inertia on driven shaft [kgm^2]            */
    double PwrElec;        /* Electrical power (generator, motor) [W]          */
    double Current_dq[2];  /* Current vector in rotor fixed dq coordinates [A] */
    double Current_uvw[3]; /* Electric phase currents [A]                      */
} tPTMotorIF;

/** Transmission *************************************************************/

typedef struct tPTTransmCU_CfgIF {
    /* Inputs */
    tClutchKind ClKind;   /* Clutch kind (friction, converter) */
    int         nGearbox; /* Number of Gearboxes               */
    int         nClutch;  /* Number of Clutches                */

    struct tPTTransmCU_CfgIF_GB {
        tGearBoxKind GBKind;  /* Gearbox kind (manual, automatic)        */
        tClutchKind  ClKind;  /* Clutch kind (friction, converter)       */
        int          nFGears; /* Number of forward gears and the ratios  */
        double       iFGear[VEHICLE_NGEARS + 1];
        int          nBGears; /* Number of backward gears and the ratios */
        double       iBGear[VEHICLE_NGEARS + 1];
    } GearBox[N_MOTOR];

    /* Outputs */
    int AutoWithMan; /* Automated gearbox with manual gear selection */
} tPTTransmCU_CfgIF;

typedef struct tPTTransmCU_IF {
    tPTTransmCU_CfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    int    Ignition;     /* Ignition []                 */
    int    SelectorCtrl; /* Gearbox selector control [] */
    double Load;         /* Engine throttle []          */
    double Velocity;     /* Vehicle velocity [m/s]      */

    struct tPTTransmCU_IF_ClutchIn {
        double rotv_in;      /* Clutch input rotation speed [rad/s]         */
        double rotv_out;     /* Clutch output rotation speed [rad/s]        */
        double rotv_out_trg; /* Target clutch output rotation speed [rad/s] */
        double Trq_in;       /* Clutch input torque [Nm]                    */
        double Trq_out;      /* Clutch output torque [Nm]                   */
        double Trq_out_trg;  /* Target clutch output torque [Nm]            */
        double i_TrqIn2Out;  /* Clutch ratio input to output torque []      */
    } ClutchIn[N_CLUTCH];

    struct tPTTransmCU_IF_GearBoxIn {
        int    GearNo;      /* Gearbox current gear []                     */
        int    GearNo_dis;  /* Gearbox current gear disengaged shaft []    */
        double i;           /* Gearbox gear ratio []                       */
        double rotv_in;     /* Gearbox input rotation speed [rad/s]        */
        double rotv_in_trg; /* Target Gearbox input rotation speed [rad/s] */
        double rotv_out;    /* Gearbox output rotation speed [rad/s]       */
        double Trq_in;      /* Gearbox input torque [Nm]                   */
        double Trq_out;     /* Gearbox output torque [Nm]                  */
        double Trq_out_trg; /* Target Gearbox output torque [Nm]           */

                            /* Clutch integrated in Gearbox model */
        struct tPTTransmCU_IF_GearBoxIn_Clutch {
            double rotv_in;      /* Clutch input rotation speed [rad/s]         */
            double rotv_out;     /* Clutch output rotation speed [rad/s]        */
            double rotv_out_trg; /* Target clutch output rotation speed [rad/s] */
            double Trq_in;       /* Clutch input torque [Nm]                    */
            double Trq_out;      /* Clutch output torque [Nm]                   */
            double Trq_out_trg;  /* Target clutch output torque [Nm]            */
            double i_TrqIn2Out;  /* Clutch ratio input to output torque []      */
        } Clutch, Clutch_dis;
    } GearBoxIn[N_MOTOR];

    /* Outputs */
    int Status; /* Transmission CU status */

    struct tPTTransmCU_IF_ClutchOut {
        double Pos; /* Clutch position 0=closed 1=open */
    } ClutchOut[N_CLUTCH];

    struct tPTTransmCU_IF_GearBoxOut {
        int    GearNoTrg;        /* Gearbox target gear (gets also as Input)  */
        int    GearNoTrg_dis;    /* Gearbox target gear for disengaged shaft
                                    (gets also as Input)                      */
        int    set_ParkBrake;    /* Flag if park brake is set []              */
        double Trq_DriveSrc_trg; /* Set optionally drive source target torque
                                    (e.g. while shifting)                     */
        double i_trg;            /* Gearbox target ratio []                   */

                                 /* Clutch integrated in Gearbox model */
        struct tPTTransmCU_IF_GearBoxOut_Clutch {
            double Pos; /* Clutch position 0=closed 1=open */
        } Clutch, Clutch_dis;
    } GearBoxOut[N_MOTOR];

} tPTTransmCU_IF;

typedef struct tPTTransmCU_PreSimIF {
    struct {
        int GearNoTrg;
    } GearBox[N_MOTOR];
} tPTTransmCU_PreSimIF;

typedef struct tPTClutchCfgIF {
    /* Outputs */
    tClutchKind ClKind; /* Clutch kind (friction, converter) */
} tPTClutchCfgIF;

typedef struct tPTClutchIF {
    tPTClutchCfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    double Pos;      /* Clutch position (0=closed 1=open)    */
    double Inert_in; /* Clutch input inertia [kgm^2]         */
    double rot_out;  /* Clutch output rotation [rad]         */
    double rotv_out; /* Clutch output rotation speed [rad/s] */
    double Trq_in;   /* Clutch input torque [Nm]             */

    /* Outputs */
    double rot_in;        /* Clutch input rotation [rad]            */
    double rotv_in;       /* Clutch input rotation speed [rad/s]    */
    double Trq_out;       /* Clutch output torque [Nm]              */
    double Inert_out;     /* Clutch output inertia [kgm^2]          */
    double i_TrqIn2Out;   /* Clutch ratio input to output torque [] */
    double Trq_SuppInert; /* Support torque of inertia [Nm]         */
} tPTClutchIF;

typedef struct tPTClutchPreSimIF {
    double Pos;
    double rotv_in;
} tPTClutchPreSimIF;

typedef struct tPTGearBoxCfgIF {
    /* Inputs */
    tMountFrameVhcl Frame;          /* mounting Frame                               */
    double          Orientation[3]; /* Orientation between Fr1 and body-fixed frame */

    /* In/Outputs */
    tBdy Bdy; /* Bdy in Fr1 - in: pos, out: mass, I */

    /* Outputs */
    tGearBoxKind GBKind;  /* Gearbox kind (manual, automatic)           */
    tClutchKind  ClKind;  /* Clutch kind (friction, converter)          */
    int          nFGears; /* Number of forward gears and the ratios     */
    double       iFGear[VEHICLE_NGEARS + 1];
    int          nBGears; /* Number of backward gears and the ratios    */
    double       iBGear[VEHICLE_NGEARS + 1];
} tPTGearBoxCfgIF;

typedef struct tPTGearBoxIF {
    tPTGearBoxCfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    int    GearNoTrg;     /* Gearbox target gear []                      */
    int    GearNoTrg_dis; /* Gearbox target gear for disengaged shaft
                             (gets also as Input)                        */
    int    set_ParkBrake; /* Flag if park brake is set []                */
    double i_trg;         /* Gearbox target ratio []                     */
    double Inert_in;      /* Gearbox input inertia [kgm^2]               */
    double rot_out;       /* Gearbox output rotation [rad]               */
    double rotv_out;      /* Gearbox output rotation speed [rad/s]       */
    double Trq_in;        /* Gearbox input torque [Nm]                   */

    struct tPTGearBoxIF_ClutchIn {
        double Pos; /* Clutch position (0=closed 1=open) */
    } ClutchIn, Clutch_dis_In;

    /* Outputs */
    int    GearNo;        /* Gearbox current gear []                     */
    int    GearNo_dis;    /* Gearbox target gear for disengaged shaft
                             (gets also as Input)                        */
    double i;             /* Gearbox gear ratio []                       */
    double i_TrqIn2Out;   /* Gearbox gear ratio [] (considering loss)    */
    double rot_in;        /* Gearbox input rotation [rad]                */
    double rotv_in;       /* Gearbox input rotation speed [rad/s]        */
    double Trq_out;       /* Gearbox output torque [Nm]                  */
    double Inert_out;     /* Gearbox output inertia [kgm^2]              */
    double Trq_SuppInert; /* Support torque of inertia [Nm]              */

    struct tPTGearBoxIF_ClutchOut {
        double rot_in;      /* Clutch input rotation [rad]            */
        double rotv_in;     /* Clutch input rotation speed [rad/s]    */
        double rot_out;     /* Clutch output rotation [rad]           */
        double rotv_out;    /* Clutch output rotation speed [rad/s]   */
        double Trq_in;      /* Clutch input torque [Nm]               */
        double Trq_out;     /* Clutch output torque [Nm]              */
        double i_TrqIn2Out; /* Clutch ratio input to output torque [] */
    } ClutchOut, Clutch_dis_Out;
} tPTGearBoxIF;

typedef struct tPTGearBoxPreSimIF {
    int    GearNo;
    double rotv_out;
    double Clutch_Pos;
    double Clutch_rotv_in;
} tPTGearBoxPreSimIF;

/* Function pointer for calculation of shift avoidance during cornering */
typedef int (*tShiftAvoidFunc)(void);
void Set_UserShiftAvoidFunc(tShiftAvoidFunc ShiftAvoidFunc);

typedef void (*tShiftAvoidFunc_New)(void);
void Set_UserShiftAvoidFunc_New(tShiftAvoidFunc_New ShiftAvoid_New);

/** DriveLine ****************************************************************/

typedef enum {
    NoPosition = 0,
    Diff_Center,
    Diff_Front,
    Diff_Rear,
    Diff_Rear2,
    Diff_Front2,
    Diff_Rear3,
    Diff_Rear4,
    Diff_CenterFront,
    Diff_CenterRear,
    Wheel_FL,
    Wheel_FR,
    Wheel_RL,
    Wheel_RR,
    Wheel_RL2,
    Wheel_RR2,
    Wheel_FL2,
    Wheel_FR2,
    Wheel_RL3,
    Wheel_RR3,
    Wheel_RL4,
    Wheel_RR4
} tDriveSourcePos;

typedef struct tPTDriveLineCfgIF {
    /* Inputs */
    int             nWheels;                  /* Number of vehicle wheels  */
    double          Wheel_Iyy[VEHICLE_NWHLS]; /* Wheel inertia Iyy [kgm^2] */
    /* Outputs */
    double          iDiff_mean;                    /* Driveline mean differential ratio     */
    tDriveSourcePos DriveSourcePos[N_DRIVESOURCE]; /* Specifies on which position the drive
                                                      source i is applied                   */
} tPTDriveLineCfgIF;

typedef struct tPTDriveLineIF {
    tPTDriveLineCfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    struct tPTDriveLineIF_WheelIn {
        double Trq_Brake;      /* Total brake torque to the wheel [Nm]     */
        double Trq_T2W;        /* Tire torque, around wheel spin axis [Nm] */
        double Trq_WhlBearing; /* Wheel bearing torque [Nm]                */
    } WheelIn[VEHICLE_NWHLS];

    struct tPTDriveLineIF_DriveIn {
        double Inert_in; /* Drive source input inertia [kgm^2] */
        double Trq_in;   /* Drive source input torque [Nm]     */
    } DriveIn[N_DRIVESOURCE];

    /* Outputs */
    double Trq_Supp2Bdy1[3];   /* Drive torque support on vehicle body Fr1A [Nm]       */
    double Trq_Supp2Bdy1B[3];  /* Drive torque support on vehicle body Fr1B [Nm]       */
    double Trq_Supp2BdyEng[2]; /* Drive torque support on engine body FrEng [Nm]       */

    double iDiff_mean;         /* Driveline mean differential ratio (overrides
                                  the value from the configuration struct if non zero) */

    struct tPTDriveLineIF_WheelOut {
        double rot, rotv;   /* Wheel rotation [radm rad/s]                */
        double Trq_B2W;     /* Reduced brake torque [Nm]                  */
        double Trq_Drive;   /* Drive torque [Nm]                          */
        double Trq_Supp2WC; /* Drive torque support on wheel carrier [Nm] */
    } WheelOut[VEHICLE_NWHLS];

    struct tPTDriveLineIF_DriveOut {
        double rot_in, rotv_in;      /* Drive source input rotation [rad, rad/s] */
        double i_D2W[VEHICLE_NWHLS]; /* Ratio drive source to wheel []           */
    } DriveOut[N_DRIVESOURCE];

} tPTDriveLineIF;

typedef struct tPTDriveLinePreSimIF {
    double Whl_rotv[VEHICLE_NWHLS];
} tPTDriveLinePreSimIF;

/* PTGenCoupling */

typedef enum {
    PTGen_Pos_Unknown = 0,
    PTGen_Pos_Front,
    PTGen_Pos_Rear,
    PTGen_Pos_Center,
    PTGen_Pos_Rear2,
    PTGen_Pos_Front2,
    PTGen_Pos_Rear3,
    PTGen_Pos_Rear4,
    PTGen_Pos_HangOn,
    PTGen_Pos_CenterFront,
    PTGen_Pos_CenterRear,
} tPTGen_CplDiffPos;

typedef enum {
    PTGen_CplType_Unknown     = 0,
    PTGen_CplType_NotLockable = 1,
    PTGen_CplType_Lockable    = 2,
    PTGen_CplType_FullyActive = 3
} tPTGen_CouplingType;

typedef struct tPTGenCouplingCfgIF {
    /* Inputs */
    tPTGen_CplDiffPos CplPos; /* Coupling position */

    /* Outputs */
    tPTGen_CouplingType CplType; /* Coupling type */
} tPTGenCouplingCfgIF;

typedef struct tPTGenCouplingIF {
    tPTGenCouplingCfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    double              Trq_Ext2Cage; /* Input torque to differential cage [Nm]          */
    double              drotv_A2B;    /* Rotation speed difference A to B:
                                         means depending on central or axle differential
                                         'left to right' or 'front to rear' [rad/s]      */
    /* Outputs */
    double              Trq_A2B; /* Coupling torque A to B:
                                    means depending on central or axle differential
                                    'left to right' or 'front to rear'              */
    tPTGen_CouplingType CplType; /* NOT USED                                        */
} tPTGenCouplingIF;

/** Battery & PowerSupply ****************************************************/

typedef struct tPTBatteryCU_CfgIF {
    /* Inputs */
    struct tPTBatteryCU_CfgIF_Battery {
        double SOC_min;       /* State of charge minimum [%]      */
        double SOC_max;       /* State of charge maximum [%]      */
        double Capacity;      /* Capacity [Ah]                    */
        double Voltage;       /* Open circuit battary voltage [V] */

        double Temp_init;     /* Initial battery temperature [K]  */
        double TempCool_init; /* Initial coolant temperature [K]  */
    } BattLV, BattHV;
} tPTBatteryCU_CfgIF;

typedef struct tPTBatteryCU_IF {
    tPTBatteryCU_CfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    int    Ignition;
    double Pwr_LV;           /* Total power (generator, consumer) for LV [W]  */
    double Pwr_HV1;          /* Total power (generator, consumer) for HV1 [W] */
    double Pwr_HV2;          /* Total power (generator, consumer) for HV2 [W] */
    double Voltage_LV;       /* Voltage of level LV [V]                       */
    double Voltage_HV1;      /* Voltage of level HV1 [V]                      */
    double Voltage_HV2;      /* Voltage of level HV2 [V]                      */
    double Pwr_HV1toLV_trg;  /* Target transformed power from HV1 to LV [W]   */
    double Pwr_HV1toLV;      /* Current transformed power from HV1 to LV [W]  */
    double Pwr_HV1toHV2;     /* Current transformed power from HV1 to HV2 [W] */
    double Pwr_HV1toLV_max;  /* Maximum possible power from HV1 to LV [W]     */
    double Pwr_HV1toHV2_max; /* Maximum possible power from HV1 to HV2 [W]    */
    double Eta_HV1toLV;      /* DC/DC efficiency from HV1 to LV []            */
    double Eta_HV1toHV2;     /* DC/DC efficiency from HV1 to HV2 []           */

    /* Outputs */
    int Status; /* Battery CU status */

    /* Inputs / Outputs (signal transmit from battery to PTControl) */
    struct tPTBatteryCU_IF_Battery {
        double SOC;     /* Current state of charge [%]        */
        double SOH;     /* Current state of health [%]        */
        double Current; /* Battery current [A]                */
        double AOC;     /* Amount of charge [Ah]              */
        double Energy;  /* Energy capacity [kWh]              */
        double Pwr_max; /* Maximum charge/discharge power [W] */

        /* Heat transfer */
        double Temp;             /* Battery temperature [K]        */
        double TempCool_in;      /* Inlet coolant temperature [K]  */
        double TempCool_out;     /* Outlet coolant temperature [K] */
        double MassFlowCool;     /* Mass flow rate [kg/s]          */

        double Temp_trg;         /* Battery target temperature [K]               */
        double MassFlowCool_trg; /* Battery coolant target mass flow rate [kg/s] */
    } BattLV, BattHV;

} tPTBatteryCU_IF;

typedef struct tPTBatteryCfgIF {
    /* In/Outputs */
    tPTBdy BdyPart[2]; /* Battery can be splitted into two parts to work with
                          multiple mounting frames:
                          in: pos, Orientation, Frame
                          out: mass, I */

    /* Outputs */
    double SOC_init; /* Initial State of charge [%]      */
    double SOC_min;  /* State of charge minimum [%]      */
    double SOC_max;  /* State of charge maximum [%]      */
    double Capacity; /* Capacity [Ah]                    */
    double Voltage;  /* Open circuit battary voltage [V] */

    /* Heat transfer */
    double Temp_init;     /* Initial battery temperature [K] */
    double TempCool_init; /* Initial coolant temperature [K] */
} tPTBatteryCfgIF;

typedef struct tPTBatteryIF {
    tPTBatteryCfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    double Current; /* Battery current [A] */

    /* Outputs */
    double Voltage; /* Battery voltage [V]                */
    double AOC;     /* Amount of charge [Ah]              */
    double Energy;  /* Energy capacity [kWh]              */
    double Pwr_max; /* Maximum charge/discharge power [W] */

    /* Heat transfer */
    double Temp;         /* Battery temperature [K]        */
    double TempCool_in;  /* Inlet coolant temperature [K]  */
    double TempCool_out; /* Outlet coolant temperature [K] */
    double MassFlowCool; /* Mass flow rate [kg/s]          */
} tPTBatteryIF;

typedef struct tPTPowerSupplyCfgIF {
    /* Outputs */
    struct tPTPowerSupplyCfgIF_Battery {
        tPTBdy BdyPart[2]; /* Battery can be splitted into two parts to
                              work with multiple mounting frames
                              in: pos, Orientation, Frame
                              out: mass, I                              */
        double SOC_min;    /* State of charge minimum [%]               */
        double SOC_max;    /* State of charge maximum [%]               */
        double Capacity;   /* Capacity [Ah]                             */
        double Voltage;    /* Open circuit battary voltage [V]          */

        /* Heat transfer */
        double Temp_init;     /* Initial battery temperature [K] */
        double TempCool_init; /* Initial coolant temperature [K] */
    } BattLV, BattHV;
} tPTPowerSupplyCfgIF;

typedef struct tPTPowerSupplyIF {
    tPTPowerSupplyCfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    double Pwr_HV1toLV_trg; /* Target transformed power from HV1 to LV [W]   */
    double Pwr_LV;          /* Total power (generator, consumer) for LV [W]  */
    double Pwr_HV1;         /* Total power (generator, consumer) for HV1 [W] */
    double Pwr_HV2;         /* Total power (generator, consumer) for HV2 [W] */

    /* Outputs */
    double Pwr_HV1toLV;      /* Current transformed power from HV1 to LV [W]  */
    double Pwr_HV1toHV2;     /* Current transformed power from HV1 to HV2 [W] */
    double Pwr_HV1toLV_max;  /* Maximum possible power from HV1 to LV [W]     */
    double Pwr_HV1toHV2_max; /* Maximum possible power from HV1 to HV2 [W]    */
    double Eta_HV1toLV;      /* DC/DC efficiency from HV1 to LV []            */
    double Eta_HV1toHV2;     /* DC/DC efficiency from HV1 to HV2 []           */
    double Voltage_LV;       /* Voltage of level LV [V]                       */
    double Voltage_HV1;      /* Voltage of level HV1 [V]                      */
    double Voltage_HV2;      /* Voltage of level HV2 [V]                      */

    struct tPTPowerSupplyIF_Battery {
        double Current; /* Battery current [A]                */
        double AOC;     /* Amount of charge [Ah]              */
        double Energy;  /* Energy capacity [kWh]              */
        double Pwr_max; /* Maximum charge/discharge power [W] */

        /* Heat transfer */
        double Temp;         /* Battery temperature [K]        */
        double TempCool_in;  /* Inlet coolant temperature [K]  */
        double TempCool_out; /* Outlet coolant temperature [K] */
        double MassFlowCool; /* Mass flow rate [kg/s]          */
    } BattLV, BattHV;
} tPTPowerSupplyIF;

typedef struct tPTInverterCfgIF {
    /* Inputs */
    tPTPowerSupply_Level Level;      /* PowerSupply voltage level                 */
    int                  nPolePairs; /* Number of pole pairs for a physical model */
    int                  MotorType;  /* Motor Type, used for plausibility checks  */
} tPTInverterCfgIF;

typedef struct tPTInverterIF {
    tPTInverterCfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    double Load_in;        /* Load input from MCU []                  */
    double GateSignal[3];  /* GateSignal for three phase inverter     */
    double PwrElec;        /* Electric power from electric motor [W]  */
    double Motor_Trq;      /* Torque of electric motor,
                              used for power loss calculation [Nm]    */
    double Motor_rotv;     /* Rotation speed of electric motor,
                              used for power loss calculation [rad/s] */
    double Motor_rot;      /* Rotation angle of electric motor [rad]  */
    double Current_uvw[3]; /* Current in stator coordinate system [A] */
    double Current_dq[2];  /* Currrent in rotor coordinate system [A] */
    double Volt_Batt;      /* Battery voltage [V]                     */

    /* Outputs */
    double Load_out;       /* Load output for look up table electric motor model [] */
    double PwrLoss;        /* Power loss in inverter [W]                            */
    double Voltage_uvw[3]; /* Voltage in stator coordinate system [V]               */
    double Voltage_dq[2];  /* Voltage in rotor coordinate system [V]                */
    double Current_Batt;   /* Battery current [A]                                   */
} tPTInverterIF;

/** PT Control ***************************************************************/

typedef enum {
    Mode_StartStop   = 0,
    Mode_RegBrake    = 1,
    Mode_RegDrag     = 2,
    Mode_Coasting    = 3,
    Mode_ElecDrive   = 4,
    Mode_LoadShift   = 5,
    Mode_Assist      = 6,
    Mode_Boost       = 7,
    Mode_EngineDrive = 8,

    Mode_EngineStart = 9,
    Mode_EngineSync  = 10,
    Mode_EngineStop  = 11,
    Mode_NumModes    = 12
} tStrategyMode;

typedef struct tPTControlCfgIF {
    /* Inputs */
    tPowerTrainKind PTKind;                        /* PowerTrain kind                       */
    tClutchKind     ClKind;                        /* Clutch kind (friction, converter)     */
    int             nMotor;                        /* Number of motors (not ISG included)   */
    int             nGearbox;                      /* Number of Gearboxes                   */
    int             nClutch;                       /* Number of Clutches                    */
    int             nPlanetGear;                   /* Number of planet gear                 */
    int             nWheels;                       /* Number of vehicle wheels              */
    double          WheelRadius;                   /* Mean wheel radius [m]                 */
    double          Aero_Frcx;                     /* Static aero force along x-axis
                                                      (with angle zero)                     */
    double          DL_iDiff_mean;                 /* Driveline mean differential ratio     */
    tDriveSourcePos DriveSourcePos[N_DRIVESOURCE]; /* Specifies on which position the drive
                                                      source i is applied                   */

    struct tPTControlCfgIF_Battery {
        double SOC_min;  /* State of charge minimum [%]      */
        double SOC_max;  /* State of charge maximum [%]      */
        double Capacity; /* Capacity [Ah]                    */
        double Voltage;  /* Open circuit battary voltage [V] */

        /* Heat transfer */
        double Temp_init;     /* Initial battery temperature [K] */
        double TempCool_init; /* Initial coolant temperature [K] */
    } BattLV, BattHV;

    struct tPTControlCfgIF_Engine {
        double      Fuel_l2kWh; /* Factor for Fuel: l -> kWh                    */
        double      rotv_max;   /* Engine maximum speed [rad/s]                 */
        double      rotv_idle;  /* Engine idle speed [rad/s]                    */
        double      rotv_opt;   /* Engine optimum speed with minimum be [rad/s] */
        struct tLM *TrqFull;    /* 1D-Lookup table for max. engine full torque  */
        struct tLM *TrqDrag;    /* 1D-Lookup table for max. engine drag torque  */
        struct tLM *TrqOpt;     /* 1D-Lookup table for engine torque with
                                   optimal consumption (minimal specific fuel
                                   consumption as function of engine speed)     */
    } Engine;

    struct tPTControlCfgIF_Motor {
        tPTMotor_CtrlMode    CtrlMode;     /* Mode determines control strategy           */
        tPTPowerSupply_Level Level;        /* PowerSupply voltage level                  */
        double               Ratio;        /* Ratio between motor shaft and driven shaft */
        struct tLM          *TrqMot_max;   /* 1D-Lookup table for max. motor torque      */
        double               rotv_Mot_max; /* Maximum motor rotation [rad/s]             */
        struct tLM          *TrqGen_max;   /* 1D-Lookup table for max. generator torque  */
        double               rotv_Gen_max; /* Maximum generator rotation [rad/s]         */
        int                  nPolePairs;   /* Number of pole pairs []                    */
        double               L_d;          /* Inductance in d coordinate [H]             */
        double               L_q;          /* Inductance in q coordinate [H]             */
        double               Psi_PM;       /* Magnetic flux of the permanent magnet [Wb] */
    } ISG, Motor[N_MOTOR];

    struct tPTControlCfgIF_GB {
        tGearBoxKind GBKind;  /* Gearbox kind (manual, automatic)        */
        tClutchKind  ClKind;  /* Clutch kind (friction, converter)       */
        int          nFGears; /* Number of forward gears and the ratios  */
        double       iFGear[VEHICLE_NGEARS + 1];
        int          nBGears; /* Number of backward gears and the ratios */
        double       iBGear[VEHICLE_NGEARS + 1];
    } GearBox[N_MOTOR];

    struct tPTControlCfgIF_PG {
        double Ratio; /* Planet gear ratio (ring/sun radius) */
    } PlanetGear[N_PLANETGEAR];

    /* Outputs */
    int    StartEngineWithSST; /* 1: Engine starter is activated with SST */
    double Velocity_max;       /* Vehicle maximum possible velocity [m/s] */

} tPTControlCfgIF;

typedef struct tPTControlIF {
    tPTControlCfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    tKeyPosition Key;              /* Vehicle key                 */
    int          SST;              /* Start-Stop key              */
    int          SelectorCtrl;     /* Gearbox selector control [] */
    int          GearNoTrg;        /* Gearbox target gear []      */
    double       Clutch;           /* Driver clutch pedal 0-1 []  */
    double       Gas;              /* Driver gas pedal 0-1 []     */
    double       Brake;            /* Driver brake pedal 0-1 []   */
    double       Velocity;         /* Vehicle velocity [m/s]      */

    int UserSignal[N_USERSIGNALS]; /* Optional user defined signals */

    int ECU_Status;                /* Engine CU status */

    struct tPTControlIF_EngineIn {
        int    Engine_on; /* Flag if engine is over the engine off speed */
        double rotv;      /* Engine speed [rad/s]                        */
        double Trq;       /* Engine torque [Nm]                          */
        double TrqDrag;   /* Engine drag torque [Nm]                     */
        double TrqFull;   /* Engine full load torque [Nm]                */
        double TrqOpt;    /* Engine torque with optimal consumption [Nm] */
        double FuelFlow;  /* Current fuel flow [l/s]                     */
    } EngineIn;

    int MCU_Status; /* Motor CU status */

    struct tPTControlIF_MotorIn {
        double rotv;                 /* Motor rotation of driven shaft [rad/s]        */
        double Trq;                  /* Motor torque on driven shaft [Nm]             */
        double TrqMot_max;           /* Maximum motor torque on driven shaft [Nm]     */
        double TrqGen_max;           /* Maximum generator torque on driven shaft [Nm] */
        double PwrElec;              /* Electrical power (generator, motor) [W]       */
        double i_M2W[VEHICLE_NWHLS]; /* Theoretical ratio motor to wheel []
                                        (without considering friction clutches)       */
    } ISGIn, MotorIn[N_MOTOR];

    int TCU_Status; /* Transmission CU status */

    struct tPTControlIF_ClutchIn {
        double Pos;         /* Clutch position from TCU               */
        double rotv_in;     /* Clutch input rotation speed [rad/s]    */
        double rotv_out;    /* Clutch output rotation speed [rad/s]   */
        double Trq_in;      /* Clutch input torque [Nm]               */
        double Trq_out;     /* Clutch output torque [Nm]              */
        double i_TrqIn2Out; /* Clutch ratio input to output torque [] */
    } ClutchIn[N_CLUTCH];

    struct tPTControlIF_GearBoxIn {
        int    GearNo;           /* Gearbox current gear []                   */
        int    GearNo_dis;       /* Gearbox current gear disengaged shaft []  */
        double Trq_DriveSrc_trg; /* Set optionally drive source target torque
                                    (e.g. while shifting)                     */
        double i;                /* Gearbox gear ratio []                     */
        double rotv_in;          /* Gearbox input rotation speed [rad/s]      */
        double rotv_out;         /* Gearbox output rotation speed [rad/s]     */
        double Trq_in;           /* Gearbox input torque [Nm]                 */
        double Trq_out;          /* Gearbox output torque [Nm]                */

        struct tPTControlIF_GearBoxIn_Clutch {
            double Pos;         /* Clutch position from TCU               */
            double rotv_in;     /* Clutch input rotation speed [rad/s]    */
            double rotv_out;    /* Clutch output rotation speed [rad/s]   */
            double Trq_in;      /* Clutch input torque [Nm]               */
            double Trq_out;     /* Clutch output torque [Nm]              */
            double i_TrqIn2Out; /* Clutch ratio input to output torque [] */
        } Clutch, Clutch_dis;
    } GearBoxIn[N_MOTOR];

    int BCU_Status; /* Battery CU status */

    struct tPTControlIF_BattIn {
        double SOC;          /* Current state of charge [%]        */
        double SOH;          /* Current state of health [%]        */
        double Current;      /* Battery current [A]                */
        double AOC;          /* Amount of charge [Ah]              */
        double Energy;       /* Energy capacity [kWh]              */
        double Pwr_max;      /* Maximum charge/discharge power [W] */

        double Temp;         /* Battery temperature [K]                */
        double TempCool_out; /* Battery outlet coolant temperature [K] */
    } BattLVIn, BattHVIn;

    struct tPTControlIF_PwrSupplyIn {
        double Pwr_LV;           /* Total power (generator, consumer) for LV [W]  */
        double Pwr_HV1;          /* Total power (generator, consumer) for HV1 [W] */
        double Pwr_HV2;          /* Total power (generator, consumer) for HV2 [W] */
        double Voltage_LV;       /* Voltage of level LV [V]                       */
        double Voltage_HV1;      /* Voltage of level HV1 [V]                      */
        double Voltage_HV2;      /* Voltage of level HV2 [V]                      */
        double Pwr_HV1toLV;      /* Current transformed power from HV1 to LV [W]  */
        double Pwr_HV1toHV2;     /* Current transformed power from HV1 to HV2 [W] */
        double Pwr_HV1toLV_max;  /* Maximum possible power from HV1 to LV [W]     */
        double Pwr_HV1toHV2_max; /* Maximum possible power from HV1 to HV2 [W]    */
        double Eta_HV1toLV;      /* DC/DC efficiency from HV1 to LV []            */
        double Eta_HV1toHV2;     /* DC/DC efficiency from HV1 to HV2 []           */
    } PwrSupplyIn;

    struct tPTControlIF_WheelIn {
        double Trq_BrakeReg_trg; /* Target regenerative braking torque [Nm] */
    } WheelIn[VEHICLE_NWHLS];

    struct tPTControlIF_DriveSrcIn {
        double Trq_trg; /* Target torque for drivesource [Nm]
                           (Intervention by brake control unit in the
                           drive torque for example by ESP controller) */
    } DriveSrcIn[N_DRIVESOURCE];

    /* Outputs */
    tOperationState OperationState; /* Vehicle operation state          */
    tOperationError OperationError; /* Vehicle operation error, warning */
    tStrategyMode   StrategyMode;   /* Strategy mode                    */
    int             Ignition;       /* Vehicle ignition                 */

    struct tPTControlIF_EngineOut {
        int    set_ISC;    /* Flag for idle speed controller activation */
        int    FuelCutOff; /* Flag if fuel is cut-off                   */
        double Load;       /* Engine throttle (gets also as Input) []   */
        double Trq_trg;    /* Target engine torque [Nm]                 */
        double rotv_trg;   /* Target engine speed [rad/s]               */
    } EngineOut;

    struct tPTControlIF_MotorOut {
        double Load;     /* Control signal (gets also as Input) []        */
        double Trq_trg;  /* Target motor torque on driven shaft [Nm]      */
        double rotv_trg; /* Target motor rotation of driven shaft [rad/s] */
    } ISGOut, MotorOut[N_MOTOR];

    struct tPTControlIF_ClutchOut {
        double Pos;          /* Clutch position 0=closed 1=open             */
        double rotv_out_trg; /* Target clutch output rotation speed [rad/s] */
        double Trq_out_trg;  /* Target clutch output torque [Nm]            */
    } ClutchOut[N_CLUTCH];

    struct tPTControlIF_GearBoxOut {
        int    GearNoTrg;     /* Gearbox target gear (gets also as Input)    */
        int    GearNoTrg_dis; /* Gearbox target gear for disengaged shaft [] */
        int    set_ParkBrake; /* Flag if park brake is set []                */
        double i_trg;         /* Gearbox target ratio []                     */
        double rotv_in_trg;   /* Target Gearbox input rotation speed [rad/s] */
        double Trq_out_trg;   /* Target Gearbox output torque [Nm]           */

        struct tPTControlIF_GearBoxOut_Clutch {
            double Pos;          /* Clutch position 0=closed 1=open             */
            double rotv_out_trg; /* Target clutch output rotation speed [rad/s] */
            double Trq_out_trg;  /* Target clutch output torque [Nm]            */
        } Clutch, Clutch_dis;
    } GearBoxOut[N_MOTOR];

    struct tPTControlIF_BattOut {
        double Temp_trg;         /* Battery target temperature [K]               */
        double MassFlowCool_trg; /* Battery coolant target mass flow rate [kg/s] */
    } BattLVOut, BattHVOut;

    struct tPTControlIF_PwrSupplyOut {
        double Pwr_HV1toLV_trg; /* Target transformed power from HV1 to LV [W] */
    } PwrSupplyOut;

    struct tPTControlIF_WheelOut {
        double Trq_BrakeReg;     /* Current regenerative braking torque [Nm] */
        double Trq_BrakeReg_max; /* Maximum regenerative braking torque [Nm] */
    } WheelOut[VEHICLE_NWHLS];

} tPTControlIF;

/* PTControl Operation State Machine (OSM) */
typedef enum {
    OSMFunc_None = 0,
    OSMFunc_Absent,
    OSMFunc_PowerOff,
    OSMFunc_PowerAcc,
    OSMFunc_PowerOn,
    OSMFunc_Start,
    OSMFunc_SkipStart,
    OSMFunc_Drive,
    OSMFunc_MaxNumber
} tPTControlOSMFunc;

typedef struct tPTControlOSM_CfgIF {
    /* Inputs */
    int          StartEngineWithSST;           /* 1: Engine starter is activated with SST */
    tGearBoxKind GBKind;                       /* Gearbox kind (manual, automatic)        */
    int          Func_used[OSMFunc_MaxNumber]; /* Flag if the OSM function i is used      */
} tPTControlOSM_CfgIF;

typedef struct tPTControlOSM_IF {
    tPTControlOSM_CfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    tKeyPosition Key;                       /* Vehicle key                   */
    int          SST;                       /* Start-Stop key                */
    int          SelectorCtrl;              /* Gearbox selector control []   */
    int          GearNoTrg;                 /* Gearbox target gear []        */
    double       Clutch;                    /* Driver clutch pedal 0-1 []    */
    double       Gas;                       /* Driver gas pedal 0-1 []       */
    double       Brake;                     /* Driver brake pedal 0-1 []     */
    double       Velocity;                  /* Vehicle velocity [m/s]        */
    int          UserSignal[N_USERSIGNALS]; /* Optional user defined signals */

    int FuncReturn;                         /* Return value from current OSM function
                                              -1: error
                                               0: normal calculation, not finished
                                               1: normal calculation, finished        */

    /* Outputs */
    tOperationState   OperationState; /* Vehicle operation state           */
    tOperationError   OperationError; /* Vehicle operation error, warning  */
    tPTControlOSMFunc OSMFunc;        /* OSM function to used by PTControl */

} tPTControlOSM_IF;

/** PowerTrain ***************************************************************/

typedef struct tPowerTrainCfgIF {
    /* Inputs */
    int    nWheels;                  /* Number of vehicle wheels                         */
    double Wheel_Iyy[VEHICLE_NWHLS]; /* Wheel inertia Iyy [kgm^2]                        */
    double WheelRadius;              /* Mean wheel radius [m]                            */
    double Aero_Frcx;                /* Static aero force along x-axis (with angle zero) */

    /* Outputs */
    int             StartEngineWithSST; /* 1: Engine starter is activated with SST */
    tPowerTrainKind PTKind;             /* PowerTrain kind                         */
    tGearBoxKind    GBKind;             /* Gearbox kind (manual, automatic)        */
    int             nFGears;            /* Number of forward gears and the ratios  */
    double          iFGear[VEHICLE_NGEARS + 1];
    int             nBGears;            /* Number of backward gears and the ratios */
    double          iBGear[VEHICLE_NGEARS + 1];
    double          DL_iDiff_mean;      /* Driveline mean differential ratio       */
    double          Engine_rotv_max;    /* Engine maximum speed [rad/s]            */
    double          Engine_rotv_idle;   /* Engine idle speed [rad/s]               */
    double          Velocity_max;       /* Vehicle maximum possible velocity [m/s] */
    tBdy            BdyFr1A;
    tBdy            BdyFr1B;
    tBdy            BdyFrEng; /* FrEng only for Car not used with Truck   */
    tBdy            BdyFrPlf; /* FrPlf only for Truck not used with Car   */
    tBdy            BdyFrCab; /* FrCab only for Truck not used with Car   */

    struct tPowerTrainCfgIF_WC {
        tBdy Bdy;
    } WheelCarrier[VEHICLE_NWHLS];
} tPowerTrainCfgIF;

typedef struct tPowerTrainIF {
    tPowerTrainCfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    tKeyPosition Key;              /* Vehicle key                 */
    int          SST;              /* Start-Stop key              */
    int          SelectorCtrl;     /* Gearbox selector control [] */
    int          GearNoTrg;        /* Gearbox target gear []      */
    double       Clutch;           /* Driver clutch pedal 0-1 []  */
    double       Gas;              /* Driver gas pedal 0-1 []     */
    double       Brake;            /* Driver brake pedal 0-1 []   */
    double       Velocity;         /* Vehicle velocity [m/s]      */

    int UserSignal[N_USERSIGNALS]; /* Optional user defined signals */

    struct tPowerTrainIF_WheelIn {
        double Trq_Brake;        /* Total brake torque to the wheel [Nm]     */
        double Trq_BrakeReg_trg; /* Target regenerative braking torque [Nm]  */
        double Trq_T2W;          /* Tire torque, around wheel spin axis [Nm] */
        double Trq_WhlBearing;   /* Wheel bearing torque [Nm]                */
    } WheelIn[VEHICLE_NWHLS];

    struct tPowerTrainIF_DriveSrcIn {
        double Trq_trg; /* Target torque for drivesource [Nm]
                           (Intervention by brake control unit in the
                           drive torque for example by ESP controller) */
    } DriveSrcIn[N_DRIVESOURCE];

    /* Outputs */
    int             Ignition;           /* Vehicle ignition                               */
    tOperationState OperationState;     /* Vehicle operation state                        */
    tOperationError OperationError;     /* Vehicle operation error, warning               */
    int             GearNo;             /* Gearbox current gear []                        */
    double          Engine_rotv;        /* Engine rotation speed for Driver [rad/s]       */
    double          Trq_Supp2Bdy1[3];   /* Drive torque support on vehicle body Fr1A [Nm] */
    double          Trq_Supp2Bdy1B[3];  /* Drive torque support on vehicle body Fr1B [Nm] */
    double          Trq_Supp2BdyEng[3]; /* Drive torque support on engine body FrEng [Nm] */

    double DL_iDiff_mean;               /* Driveline mean differential ratio (overrides
                                         the value from the configuration struct if non zero) */

    struct tPowerTrainIF_WheelOut {
        double rot, rotv;        /* Wheel rotation [rad, rad/s]                */
        double Trq_B2W;          /* Reduced brake torque [Nm]                  */
        double Trq_Drive;        /* Drive torque [Nm]                          */
        double Trq_Supp2WC;      /* Drive torque support on wheel carrier [Nm] */
        double Trq_BrakeReg;     /* Current regenerative braking torque [Nm]   */
        double Trq_BrakeReg_max; /* Maximum regenerative braking torque [Nm]   */
    } WheelOut[VEHICLE_NWHLS];

} tPowerTrainIF;

typedef struct tPowerTrainPreSimIF {
    int    GearNo;
    double Whl_rotv[VEHICLE_NWHLS];
    double Engine_rotv;
    double GearBox_rotv_out;
    double Clutch;
} tPowerTrainPreSimIF;

/** PowerTrain OpenXWD *******************************************************/

/* OpenXWD DriveLine */

typedef struct tPTDriveLineXWD_CfgIF {
    /* Inputs */
    int             nWheels; /* Number of vehicle wheels */
    /* Outputs */
    double          iDiff_mean;        /* Driveline mean differential ratio     */
    tDriveSourcePos DriveSourcePos[1]; /* Specifies on which position the drive
                                          source is applied                     */
} tPTDriveLineXWD_CfgIF;

typedef struct tPTDriveLineXWD_IF {
    tPTDriveLineXWD_CfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    struct tPTDriveLineXWD_IF_DriveIn {
        double Inert_in; /* Drive source input inertia [kgm^2] */
        double Trq_in;   /* Drive source input torque [Nm]     */
    } DriveIn;

    struct tPTDriveLineXWD_IF_WheelIn {
        double rot, rotv; /* Wheel rotation [rad, rad/s] */
    } WheelIn[VEHICLE_NWHLS];

    /* Outputs */
    double Trq_Supp2Bdy1[3];   /* Drive torque support on vehicle body Fr1A [Nm] */
    double Trq_Supp2Bdy1B[3];  /* Drive torque support on vehicle body Fr1B [Nm] */
    double Trq_Supp2BdyEng[2]; /* Drive torque support on engine body FrEng [Nm] */

    double iDiff_mean;         /* Driveline mean differential ratio (overrides
                                  the value from the configuration struct if non zero) */

    struct tPTDriveLineXWD_IF_DriveOut {
        double rot_in;  /* Drive source input rotation [rad]         */
        double rotv_in; /* Drive source input rotation speed [rad/s] */
    } DriveOut;

    struct tPTDriveLineXWD_IF_WheelOut {
        double Inert_in;    /* Wheel input inertia [kgm^2]                */
        double Trq_Drive;   /* Drive torque [Nm]                          */
        double Trq_Supp2WC; /* Drive torque support on wheel carrier [Nm] */
    } WheelOut[VEHICLE_NWHLS];

    struct tPTDriveLineXWD_IF_PowerDelta {
        double PlanetGear; /* PlanetGear.PwrI - PlanetGear.PwrO [W]               */
        double Diffs;      /* Sum(Diff.PwrI - Diff.PwrO) of all differentials [W] */
        double Shafts;     /* Spring-damper power of all shafts [W]               */
        double Spring_DL;  /* Sum(Shaft_SpringFrc * Spring_drotv) [W]             */
        double Inert_DL;   /* Inertia power of driveline parts
                             (Gearbox output, differential) [W]                   */
    } PowerDelta;

} tPTDriveLineXWD_IF;

/* OpenXWD PowerTrain */

typedef struct tPowerTrainXWD_CfgIF {
    /* Inputs */
    int nWheels; /* Number of vehicle wheels */

    /* Outputs */
    tPowerTrainKind PTKind;      /* PowerTrain kind                     */
    tClutchKind     ClKind;      /* Clutch kind (friction, converter)   */
    int             nMotor;      /* Number of motors (not ISG included) */
    int             nGearbox;    /* Number of Gearbox                   */
    int             nPlanetGear; /* Number of planet gear               */

    struct tPowerTrainXWD_CfgIF_DL {
        double          iDiff_mean;                    /* Driveline mean differential ratio */
        tDriveSourcePos DriveSourcePos[N_DRIVESOURCE]; /* Specifies on which position the
                                                          drive source i is applied         */
    } DriveLine;

    struct tPowerTrainXWD_CfgIF_GB {
        tBdy            Bdy;            /* Bdy in Fr1 - in: pos, out: mass, I           */
        double          Orientation[3]; /* Orientation between Fr1 and body-fixed frame */
        tMountFrameVhcl Frame;          /* mounting Frame                               */

        tGearBoxKind GBKind;            /* Gearbox kind (manual, automatic)             */
        tClutchKind  ClKind;            /* Clutch kind (friction, converter)            */
        int          nFGears;           /* Number of forward gears and the ratios       */
        double       iFGear[VEHICLE_NGEARS + 1];
        int          nBGears;           /* Number of backward gears and the ratios      */
        double       iBGear[VEHICLE_NGEARS + 1];
    } GearBox[N_MOTOR];

    struct tPowerTrainXWD_CfgIF_PG {
        double Ratio; /* Planet gear ratio (ring/sun radius) */
    } PlanetGear[N_PLANETGEAR];

    struct tPowerTrainXWD_CfgIF_Battery {
        double SOC_min;       /* State of charge minimum [%]      */
        double SOC_max;       /* State of charge maximum [%]      */
        double Capacity;      /* Capacity [Ah]                    */
        double Voltage;       /* Open circuit battary voltage [V] */

        double Temp_init;     /* Initial battery temperature [K]  */
        double TempCool_init; /* Initial coolant temperature [K]  */
    } BattLV, BattHV;

    struct tPowerTrainXWD_CfgIF_Engine {
        tBdy            Bdy;                /* Bdy in Fr1 - in: pos, out: mass, I               */
        tBdy            BdyTank;            /* Bdy in Fr1 - in: pos, out: mass, I               */
        double          Orientation[3];     /* Orientation between Fr1 and body-fixed frame     */
        tMountFrameVhcl Frame;              /* mounting Frame                                   */
        tMountFrameVhcl FrameTank;          /* mounting Frame                                   */
        double          OrientationTank[3]; /* Orientation between Fr1 and body-fixed frame     */

        double      Fuel_l2kWh;             /* Factor for Fuel: l -> kWh                    */
        double      rotv_off;               /* Engine off speed [rad/s]                     */
        double      rotv_max;               /* Engine maximum speed [rad/s]                 */
        double      rotv_idle;              /* Engine idle speed [rad/s]                    */
        double      rotv_opt;               /* Engine optimum speed with minimum be [rad/s] */
        struct tLM *TrqFull;                /* 1D-Lookup table for max. engine full torque  */
        struct tLM *TrqDrag;                /* 1D-Lookup table for max. engine drag torque  */
        struct tLM *TrqOpt;                 /* 1D-Lookup table for engine torque with
                                               optimal consumption (minimal specific fuel
                                               consumption as function of engine speed)     */
    } Engine;

    struct tPowerTrainXWD_CfgIF_Motor {
        tBdy            Bdy;               /* Bdy in Fr1 - in: pos, out: mass, I           */
        double          Orientation[3];    /* Orientation between Fr1 and body-fixed frame */
        tMountFrameVhcl Frame;             /* mounting Frame                               */

        tPTPowerSupply_Level Level;        /* PowerSupply voltage level                  */
        double               Ratio;        /* Ratio between motor shaft and driven shaft */
        struct tLM          *TrqMot_max;   /* 1D-Lookup table for max. motor torque      */
        double               rotv_Mot_max; /* Maximum motor rotation [rad/s]             */
        struct tLM          *TrqGen_max;   /* 1D-Lookup table for max. generator torque  */
        double               rotv_Gen_max; /* Maximum generator rotation [rad/s]         */
    } ISG, Motor[N_MOTOR];

} tPowerTrainXWD_CfgIF;

typedef struct tPowerTrainXWD_IF {
    tPowerTrainXWD_CfgIF const *CfgIF; /* Pointer to CfgIF struct */

    /* Inputs */
    int    Ignition;     /* Vehicle ignition            */
    double Gas;          /* Driver gas pedal 0-1 []     */
    int    SelectorCtrl; /* Gearbox selector control [] */
    double Velocity;     /* Vehicle velocity [m/s]      */

    struct tPowerTrainXWD_IF_EngineIn {
        int    set_ISC;    /* Flag for idle speed controller activation */
        int    FuelCutOff; /* Flag if fuel is cut-off                   */
        double Load;       /* Engine throttle []                        */
        double Trq_trg;    /* Target engine torque [Nm]                 */
        double rotv_trg;   /* Target engine speed [rad/s]               */
    } EngineIn;

    struct tPowerTrainXWD_IF_MotorIn {
        double Load;     /* Control signal []                             */
        double Trq_trg;  /* Target motor torque on driven shaft [Nm]      */
        double rotv_trg; /* Target motor rotation of driven shaft [rad/s] */
    } ISGIn, MotorIn[N_MOTOR];

    struct tPowerTrainXWD_IF_ClutchIn {
        double Pos;          /* Clutch position (0=closed 1=open)           */
        double rotv_out_trg; /* Target clutch output rotation speed [rad/s] */
        double Trq_out_trg;  /* Target clutch output torque [Nm]            */
    } ClutchIn;

    struct tPowerTrainXWD_IF_GearBoxIn {
        int    GearNoTrg;     /* Gearbox target gear                            */
        int    GearNoTrg_dis; /* Gearbox target gear for disengaged shaft []    */
        int    set_ParkBrake; /* Flag if park brake is set []                   */
        double i_trg;         /* Gearbox target ratio []                        */
        double rotv_in_trg;   /* Target Gearbox input rotation speed [rad/s]    */
        double Trq_out_trg;   /* Target Gearbox output torque [Nm]              */

        struct tPowerTrainXWD_IF_GearBoxIn_Clutch {
            double Pos;          /* Clutch position 0=closed 1=open             */
            double rotv_out_trg; /* Target clutch output rotation speed [rad/s] */
            double Trq_out_trg;  /* Target clutch output torque [Nm]            */
        } Clutch, Clutch_dis;
    } GearBoxIn[N_MOTOR];

    struct tPowerTrainXWD_IF_BattIn {
        double Temp_trg;         /* Battery inlet coolant target temperature [K] */
        double MassFlowCool_trg; /* Battery coolant target mass flow rate [kg/s] */
    } BattLVIn, BattHVIn;

    struct tPowerTrainXWD_IF_PwrSupplyIn {
        double Pwr_HV1toLV_trg; /* Target transformed power from HV1 to LV [W] */
    } PwrSupplyIn;

    struct tPowerTrainXWD_IF_WheelIn {
        double rot, rotv; /* Wheel rotation [rad, rad/s] */
    } WheelIn[VEHICLE_NWHLS];

    /* Outputs */
    int ECU_Status; /* Engine CU status */

    struct tPowerTrainXWD_IF_EngineOut {
        char   Engine_on; /* Flag if engine is over the engine off speed */
        char   dummy[3];
        double rotv;      /* Current Engine speed [rad/s]                */
        double Trq;       /* Current engine torque [Nm]                  */
        double TrqDrag;   /* Engine drag torque [Nm]                     */
        double TrqFull;   /* Engine full load torque [Nm]                */
        double TrqOpt;    /* Engine torque with optimal consumption [Nm] */
        double FuelFlow;  /* Current fuel flow [l/s]                     */
    } EngineOut;

    int MCU_Status; /* Motor CU status */

    struct tPowerTrainXWD_IF_MotorOut {
        double rotv;                 /* Current motor rotation of driven shaft [rad/s]        */
        double Trq;                  /* Current motor torque on driven shaft [Nm]             */
        double TrqMot_max;           /* Current maximum motor torque on driven shaft [Nm]     */
        double TrqGen_max;           /* Current maximum generator torque on driven shaft [Nm] */
        double PwrElec;              /* Electrical power (generator, motor) [W]               */
        double i_M2W[VEHICLE_NWHLS]; /* Theoretical ratio motor to wheel []
                                        (without considering friction clutches)               */
    } ISGOut, MotorOut[N_MOTOR];

    int TCU_Status; /* Transmission CU status */

    struct tPowerTrainXWD_IF_ClutchOut {
        double Pos;         /* Clutch position from TCU               */
        double rotv_in;     /* Clutch input rotation speed [rad/s]    */
        double rotv_out;    /* Clutch output rotation speed [rad/s]   */
        double Trq_in;      /* Clutch input torque [Nm]               */
        double Trq_out;     /* Clutch output torque [Nm]              */
        double i_TrqIn2Out; /* Clutch ratio input to output torque [] */
    } ClutchOut;

    struct tPowerTrainXWD_IF_GearBoxOut {
        int    GearNo;           /* Gearbox current gear []                     */
        int    GearNo_dis;       /* Gearbox target gear for disengaged shaft [] */
        double Trq_DriveSrc_trg; /* Set optionally drive source target torque
                                    (e.g. while shifting)                       */
        double i;                /* Gearbox gear ratio []                       */
        double rotv_in;          /* Gearbox input rotation speed [rad/s]        */
        double rotv_out;         /* Gearbox output rotation speed [rad/s]       */
        double Trq_in;           /* Gearbox input torque [Nm]                   */
        double Trq_out;          /* Gearbox output torque [Nm]                  */

        struct tPowerTrainXWD_IF_GearBoxOut_Clutch {
            double Pos;         /* Clutch position from TCU               */
            double rotv_in;     /* Clutch input rotation speed [rad/s]    */
            double rotv_out;    /* Clutch output rotation speed [rad/s]   */
            double Trq_in;      /* Clutch input torque [Nm]               */
            double Trq_out;     /* Clutch output torque [Nm]              */
            double i_TrqIn2Out; /* Clutch ratio input to output torque [] */
        } Clutch, Clutch_dis;
    } GearBoxOut[N_MOTOR];

    int BCU_Status; /* Battery CU status */

    struct tPowerTrainXWD_IF_BattOut {
        double SOC;          /* Current state of charge [%]           */
        double SOH;          /* Current state of health [%]           */
        double Current;      /* Battery current [A]                   */
        double AOC;          /* Amount of charge [Ah]                 */
        double Energy;       /* Energy capacity [kWh]                 */
        double Pwr_max;      /* Maximum charge/discharge power [W]    */

        double Temp;         /* Battery temperature [K]               */
        double TempCool_out; /* Battery inlet coolant temperature [K] */
    } BattLVOut, BattHVOut;

    struct tPowerTrainXWD_IF_PwrSupplyOut {
        double Pwr_LV;           /* Total power (generator, consumer) for LV [W]  */
        double Pwr_HV1;          /* Total power (generator, consumer) for HV1 [W] */
        double Pwr_HV2;          /* Total power (generator, consumer) for HV2 [W] */
        double Voltage_LV;       /* Voltage of level LV [V]                       */
        double Voltage_HV1;      /* Voltage of level HV1 [V]                      */
        double Voltage_HV2;      /* Voltage of level HV2 [V]                      */
        double Pwr_HV1toLV;      /* Current transformed power from HV1 to LV [W]  */
        double Pwr_HV1toHV2;     /* Current transformed power from HV1 to HV2 [W] */
        double Pwr_HV1toLV_max;  /* Maximum possible power from HV1 to LV [W]     */
        double Pwr_HV1toHV2_max; /* Maximum possible power from HV1 to HV2 [W]    */
        double Eta_HV1toLV;      /* DC/DC efficiency from HV1 to LV []            */
        double Eta_HV1toHV2;     /* DC/DC efficiency from HV1 to HV2 []           */
    } PwrSupplyOut;

    double Trq_Supp2Bdy1[3];   /* Drive torque support on vehicle body Fr1A [Nm] */
    double Trq_Supp2Bdy1B[3];  /* Drive torque support on vehicle body Fr1B [Nm] */
    double Trq_Supp2BdyEng[2]; /* Drive torque support on engine body FrEng [Nm] */

    double DL_iDiff_mean;      /* Driveline mean differential ratio (overrides
                                  the value from the configuration struct if non zero) */

    struct tPowerTrainXWD_IF_WheelOut {
        double Inert_in;    /* Wheel input inertia [kgm^2]                */
        double Trq_Drive;   /* Drive torque [Nm]                          */
        double Trq_Supp2WC; /* Drive torque support on wheel carrier [Nm] */
    } WheelOut[VEHICLE_NWHLS];

    struct tPowerTrainXWD_IF_PowerDelta {
        double PlanetGear;  /* PlanetGear.PwrI - PlanetGear.PwrO [W]               */
        double Diffs;       /* Sum(Diff.PwrI - Diff.PwrO) of all differentials [W] */
        double Shafts;      /* Spring-damper power of all shafts [W]               */
        double Spring_DL;   /* Sum(Shaft_SpringFrc * Spring_drotv) [W]             */
        double Inert_DL;    /* Inertia power of driveline parts
                               (Gearbox output, differential) [W]                  */
        double Inert;       /* Internal inertia power of powertrain components
                               (Engine, Clutch) not passed to the driveline [W]    */
        double PowerSupply; /* PowerSupply power (DC/DC, aux. power) [W]           */
    } PowerDelta;

} tPowerTrainXWD_IF;

/** Global Struct ************************************************************/

typedef struct tPowerTrain {
    tPTEngineCU_IF EngineCU_IF;
    tPTEngineIF    EngineIF;

    struct tPTEngine {
        double Trq_Ext2E; /* external torque to engine
                             (must not be handled by current engine model) */

        struct tFuel {
            double Flow_ext; /* external fuel flow [l/s] */
            double Level;    /* Fuel level in tank [%]   */
        } Fuel;
    } Engine;

    tPTMotorCU_IF MotorCU_IF;
    tPTMotorIF    ISG_IF;
    tPTMotorIF    MotorIF[N_MOTOR];

    tPTTransmCU_IF TransmCU_IF;
    tPTClutchIF    ClutchIF[N_CLUTCH];

    tPTGearBoxIF GearBoxIF[N_MOTOR];

    struct tPTGearBox {
        double Trq_Ext2GB_In;  /* external torque to gear box in
                                  (must not be handled by current gearbox model) [Nm] */
        double Trq_Ext2GB_Out; /* external torque to gear box out
                                  (must not be handled by current gearbox model) [Nm] */
        double Inert_ExtIn;    /* additional inertia for gearbox input shaft [kgm^2]  */
        double Inert_ExtOut;   /* additional inertia for gearbox output shaft [kgm^2] */
        double i_Ext;          /* additional transmission ratio for gearbox           */
    } GearBox[N_MOTOR];

    struct tPTRetarder {
        /* inputs  */
        int Stage; /* retarder stage (0= inactive) */

        /* outputs  */
        double Trq_R2GB_In;  /* torque retarder to gearbox input  [Nm] */
        double Trq_R2GB_Out; /* torque retarder to gearbox output [Nm] */
    } Retarder;

    tPTDriveLineIF DriveLineIF;

    struct tPTDriveLine {
        double Trq_Ext2DriveSrc[N_DRIVESOURCE]; /* External torque to drivesource [Nm] */
    } DriveLine;

    tPTBatteryCU_IF  BatteryCU_IF;
    tPTPowerSupplyIF PowerSupplyIF;
    tPTInverterIF    InverterISG_IF;   // Inverter at the ISG
    tPTInverterIF    InverterIF[N_MOTOR];

    struct tPTPowerSupply {
        double Pwr_LV_aux;  /* Additional auxiliary power consumption for LV [W]  */
        double Pwr_HV1_aux; /* Additional auxiliary power consumption for HV1 [W] */
        double Pwr_HV2_aux; /* Additional auxiliary power consumption for HV2 [W] */
    } PowerSupply;

    int OSRate; /* Integration Substeps in one simulation cycle */

    tUniversalMC_IF UniversalMC_IF[N_MOTOR];
    tPTFreeEndIF    FreeEnd_IF[N_MOTOR];

    tPTControlIF  ControlIF;
    tPowerTrainIF IF;
} tPowerTrain;

typedef struct tPwrElm {
    /* Input */
    double PwrElec; /* Power Element power [W] */
    /* Output */
    double Voltage; /* Voltage of Level where the element is mounted [V] */
} tPwrElm;

/* global powertrain interface structure */
extern tPowerTrain PowerTrain;

void PowerTrain_Init(void);
void PowerTrain_DeclQuants(void);
int  PowerTrain_ModelCheck_BeforePre(struct tInfos *Inf);
void PowerTrain_Cleanup(void);

int PTControl_New(struct tInfos *Inf, int Id);
int PTControl_Delete(int Id);
int PTControl_Calc(double dt, int Id);
int PTControl_Calc_ModularPT(double dt, int Id);

int PowerTrain_New(struct tInfos *Inf);
int PowerTrain_Reduced_New(struct tInfos *Inf);
int PowerTrain_Calc(double dt);
int PowerTrain_CalcPost(double dt);
int PowerTrain_Delete(void);

int  EngineCU_New(struct tInfos *Inf, int Id);
int  EngineCU_Delete(int Id);
int  EngineCU_Calc(double dt, int Id);
void EngineCU_DeclQuants(int Id);
int  EngineCU_Calc_ModularPT(double dt, int Id);

int  Engine_New(struct tInfos *Inf, int Id);
int  Engine_Calc(double dt, int Id);
int  Engine_Delete(int Id);
void Engine_InitDefault(void);
void Engine_DeclQuants(int Id);
void Engine_TransferToPTCfgIF_AddBdy(tPowerTrainCfgIF *PTCfgIF, void *CfgIF);

int MotorCU_New(struct tInfos *Inf, int Id);
int MotorCU_Delete(int Id);
int MotorCU_Calc(double dt, int Id);
int MotorCU_Calc_ModularPT(double dt, int Id);

int Motor_New(struct tInfos *Inf, int Id);
int Motor_Calc(double dt, int Id);
int Motor_Delete(int Id);

int  TransmCU_New(struct tInfos *Inf, int Id);
int  TransmCU_Delete(int Id);
int  TransmCU_Calc(double dt, int Id);
void TransmCU_TransferToPTCfgIF(tPowerTrainCfgIF *PTCfgIF, void *CfgIF);
int  TransmCU_Calc_ModularPT(double dt, int Id);
int  TransmCU_PreSimSetup(struct tPowerTrainPreSimIF *PreSimIF, int Id);

int  Clutch_New(struct tInfos *Inf, int Id);
int  Clutch_Calc(double dt, int Id);
int  Clutch_Delete(int Id);
void Clutch_InitDefault(int Id);
void Clutch_DeclQuants(int Id);
int  Clutch_PreSimSetup_ModularPT(struct tPowerTrainPreSimIF *PreSimIF, int Id);
int  Clutch_PreSimSetup(struct tPowerTrainPreSimIF *PreSimIF);

int  GearBox_New(struct tInfos *Inf, int Id);
int  GearBox_Calc(double dt, int Id);
int  GearBox_Delete(int Id);
void GearBox_InitDefault(int Id);
void GearBox_DeclQuants(int Id);
void GearBox_TransferToPTCfgIFAddBdy(tPowerTrainCfgIF *PTCfgIF, void *CfgIF);
int  GearBox_PreSimSetup_ModularPT(struct tPowerTrainPreSimIF *PreSimIF, int Id);
int  GearBox_PreSimSetup(struct tPowerTrainPreSimIF *IF, int nGearbox, int EngineIndex, int EngineGearNo,
     int MotorGearNo);
int  DriveLine_New(struct tInfos *Inf, int Id);
int  DriveLine_Calc(double dt, int Id);
int  DriveLine_Delete(int Id);
void DriveLine_InitDefault(void);
void DriveLine_DeclQuants(int Id);
void DriveLine_TransferToPTCfgIF(tPowerTrainCfgIF *PTCfgIF, void *CfgIF);
int  DriveLine_PreSimSetup(struct tPowerTrainPreSimIF *PreSimIF, int nWheels);

int BatteryCU_New(struct tInfos *Inf, int Id);
int BatteryCU_Calc(double dt, int Id);
int BatteryCU_Delete(int Id);
int BatteryCU_Calc_ModularPT(double dt, int Id);

int  PowerSupply_New(struct tInfos *Inf, int Id);
int  PowerSupply_Calc(double dt, int Id);
int  PowerSupply_Delete(int Id);
int  PowerSupply_Calc_ModularPT(double dt, int Id);
void PowerSupply_TransferToPTCfgIF_AddBdy(tPowerTrainCfgIF *PTCfgIF, void *CfgIF);

int  Inverter_New(struct tInfos *Inf, int Id);
int  Inverter_Calc(double dt, int Id);
int  Inverter_Delete(int Id);
void Inverter_DeclQuants(int Id);

int  UniversalMC_New(struct tInfos *Inf, int Id);
int  UniversalMC_Calc(double dt, int Id);
int  UniversalMC_Delete(int Id);
void UniversalMC_InitDefault(void);
void UniversalMC_DeclQuants(int Id);

int  FreeEnd_New(struct tInfos *Inf, int Id);
int  FreeEnd_Calc(double dt, int Id);
int  FreeEnd_Delete(int Id);
void FreeEnd_DeclQuants(int Id);

tPwrElm *PowerSupply_AddPwrElm(tPTPowerSupply_Level Level);

/*** Model registration functions */

void PowerTrain_Register(void);

void PT_Wheels_UpdateTrq(double dt, double *Irot, double *Irot_act, double *Trq_Ext2Whl);

tOperationState PowerTrain_TargetOperationState(void);

/*** PT Generic *******************************************************/

int PTGenCpl_Register_Visco(void);
int PTGenCpl_Register_Locked(void);
int PTGenCpl_Register_DVA_Locked(void);
int PTGenCpl_Register_TrqSensing(void);
int PTGenCpl_Register_TrqVec(void);

struct tPTGenCpl_TrqVec {
    struct TrqVec {
        tPTGen_CplDiffPos CplPos;
        double            TrqRatio; /* torque distribution to the front [0...1] */
        double            Trqlast;  /* last coupling torque [Nm]                */
    } Front, Front2, Center, Rear, Rear2, Rear3, Rear4, CenterFront, CenterRear;
};

extern struct tPTGenCpl_TrqVec PTGenCpl_TrqVec;

/*** functions to read CfgIF parameter from Info File **************************/

int PowerTrain_GetCfgOutIF(struct tInfos *Inf, struct tPowerTrainCfgIF *CfgIF, char const *modelname);
int PowerTrainXWD_GetCfgOutIF(struct tInfos *Inf, struct tPowerTrainXWD_CfgIF *CfgIF, char const *modelname);
int DriveLineXWD_GetCfgOutIF(struct tInfos *Inf, struct tPTDriveLineXWD_CfgIF *CfgIF, char const *modelname);
int Coupling_GetCfgOutIF(struct tInfos *Inf, struct tPTGenCouplingCfgIF *CfgIF, char const *modelname,
    char const *PreKey);
int DriveLine_GetCfgOutIF(struct tInfos *Inf, struct tPTDriveLineCfgIF *CfgIF, char const *modelname);
int Battery_GetCfgOutIF(struct tInfos *Inf, struct tPTBatteryCfgIF *CfgIF, char const *modelname, char const *Ident);
int PowerSupply_GetCfgOutIF(struct tInfos *Inf, struct tPTPowerSupplyCfgIF *CfgIF, char const *modelname);
int Engine_GetCfgOutIF(struct tInfos *Inf, struct tPTEngineCfgIF *CfgIF, char const *modelname);
int Clutch_GetCfgOutIF(struct tInfos *Inf, struct tPTClutchCfgIF *CfgIF, char const *modelname, char const *Ident);
int GearBox_GetCfgOutIF(struct tInfos *Inf, struct tPTGearBoxCfgIF *CfgIF, char const *modelname, char const *Ident);
int Motor_GetCfgOutIF(struct tInfos *Inf, struct tPTMotorCfgIF *CfgIF, char const *modelname, char const *Ident);
int PTControl_GetCfgOutIF(struct tInfos *Inf, struct tPTControlCfgIF *CfgIF, char const *modelname);
int TransmCU_GetCfgOutIF(struct tInfos *Inf, struct tPTTransmCU_CfgIF *CfgIF, char const *modelname);
int UniversalMC_GetCfgIF(struct tInfos *Inf, struct tUniversalMC_CfgIF *CfgIF, char const *modelname,
    char const *ModelClassWithIdent);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _POWERTRAIN_H__ */
