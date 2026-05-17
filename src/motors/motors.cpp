//=============================================================================
//
// PROJET       : POSTE FIXE 2013
// MODULE       : Mem_24C512.c
// DESCRIPTION  : Acces a la memoire
//
//=============================================================================

//=============================================================================
//--- DECLARATIONS
//=============================================================================

//-----------------------------------------------------------------------------
// Fichiers Inclus
//-----------------------------------------------------------------------------
#include "motors.h"

//-----------------------------------------------------------------------------
// Constantes : defines et enums
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Types : definitions de structures
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Variables et Fonctions Externes
//-----------------------------------------------------------------------------
//---------- Variables ----------

//---------- Fonctions ----------

//-----------------------------------------------------------------------------
// Variables et Fonctions Privees
//-----------------------------------------------------------------------------
//---------- Variables ----------
static uint32_t _taskId = NULL;
static s_MOWER sMower;

//---------- Fonctions ----------

//=============================================================================
//--- DEFINITIONS
//=============================================================================
static void _init_L_Motor(void){
    GPIO_EN_BTS7960_L_WHEEL_OFF();
    GPIO_LPWM_BTS7960_L_WHEEL_VALUE(0);
    GPIO_RPWM_BTS7960_L_WHEEL_VALUE(0);
}

static void _init_R_Motor(void){
    GPIO_EN_BTS7960_R_WHEEL_OFF();
    GPIO_LPWM_BTS7960_R_WHEEL_VALUE(0);
    GPIO_RPWM_BTS7960_R_WHEEL_VALUE(0);
}

//-----------------------------------------------------------------------------
// FONCTION    : _Init
//
// DESCRIPTION : Init de la tache
//-----------------------------------------------------------------------------
static bool _Init(void)
{
    EVENT_None(_taskId);
    sMower.direction = NO_DIRECTION;
    _init_L_Motor();
    _init_R_Motor();
    return true;
}

//-----------------------------------------------------------------------------
// FONCTION    :  _Run
//
// DESCRIPTION :  Appel periodique
//-----------------------------------------------------------------------------
static void _Run(void)
{
    s_EVENT *event = NULL;

    if (EVENT_HasEvent(_taskId))
    {
        event = EVENT_GetEvent(_taskId);
        if (EVENT_HAS(event, MOTORS_EVENT))
        {
            EVENT_Clear(_taskId, MOTORS_EVENT);
        }
    }
}

uint32_t MOTORS_GetTaskId(void)
{
    return _taskId;
}
//-----------------------------------------------------------------------------
// FONCTION    :  HEARTBEAT_Init
//
// DESCRIPTION :  Chargement des parametres
//-----------------------------------------------------------------------------
void MOTORS_Init(void)
{
    _taskId = YAUS_TaskCreate((char *)"APP_Motors", (void *)_Init, (void *)_Run, 10, 0);
}