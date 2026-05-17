//================================================================================================//
//                                                                                                //
// PROJET       : DBM620                                                                          //
// MODULE       : Board                                                                           //
// DESCRIPTION  :                                                                                 //
// CREATION     : 18/12/2017                                                                      //
// HISTORIQUE   :                                                                                 //
//                                                                                                //
//================================================================================================//

#ifndef _LL_BOARD_
#define _LL_BOARD_

//================================================================================================//
//                                        FICHIERS INCLUS                                         //
//================================================================================================//
#include <Arduino.h>
#include <_YauS_.h>
#include "TypeDefs.h"

//================================================================================================//
//                                            DEFINES                                             //
//================================================================================================//

#define GPIO_PIN_BUILTIN_LED    2
#define GPIO_BUILTIN_LED_ON() digitalWrite(GPIO_PIN_BUILTIN_LED, HIGH)
#define GPIO_BUILTIN_LED_OFF() digitalWrite(GPIO_PIN_BUILTIN_LED, LOW)
#define GPIO_BUILTIN_LED(X) digitalWrite(GPIO_PIN_BUILTIN_LED, X)
#define GPIO_BUILTIN_LED_MODE(X)  pinMode(GPIO_PIN_BUILTIN_LED , X)

#define GPIO_PIN_EN_BTS7960_L_WHEEL   23
#define GPIO_EN_BTS7960_L_WHEEL_ON() digitalWrite(GPIO_PIN_EN_BTS7960_L_WHEEL, HIGH)
#define GPIO_EN_BTS7960_L_WHEEL_OFF() digitalWrite(GPIO_PIN_EN_BTS7960_L_WHEEL, LOW)
#define GPIO_EN_BTS7960_L_WHEEL(X) digitalWrite(GPIO_PIN_EN_BTS7960_L_WHEEL, X)
#define GPIO_EN_BTS7960_L_WHEEL_MODE(X)  pinMode(GPIO_PIN_EN_BTS7960_L_WHEEL , X)

#define GPIO_PIN_LPWM_BTS7960_L_WHEEL   22
#define GPIO_LPWM_BTS7960_L_WHEEL_VALUE(X) analogWrite(GPIO_PIN_LPWM_BTS7960_L_WHEEL, X)
#define GPIO_LPWM_BTS7960_L_WHEEL_MODE(X)  pinMode(GPIO_PIN_LPWM_BTS7960_L_WHEEL , X)

#define GPIO_PIN_RPWM_BTS7960_L_WHEEL   1
#define GPIO_RPWM_BTS7960_L_WHEEL_VALUE(X) analogWrite(GPIO_PIN_RPWM_BTS7960_L_WHEEL, X)
#define GPIO_RPWM_BTS7960_L_WHEEL_MODE(X)  pinMode(GPIO_PIN_RPWM_BTS7960_L_WHEEL , X)

#define GPIO_PIN_EN_BTS7960_R_WHEEL   3
#define GPIO_EN_BTS7960_R_WHEEL_ON() digitalWrite(GPIO_PIN_EN_BTS7960_R_WHEEL, HIGH)
#define GPIO_EN_BTS7960_R_WHEEL_OFF() digitalWrite(GPIO_PIN_EN_BTS7960_R_WHEEL, LOW)
#define GPIO_EN_BTS7960_R_WHEEL(X) digitalWrite(GPIO_PIN_EN_BTS7960_R_WHEEL, X)
#define GPIO_EN_BTS7960_R_WHEEL_MODE(X)  pinMode(GPIO_PIN_EN_BTS7960_R_WHEEL , X)

#define GPIO_PIN_LPWM_BTS7960_R_WHEEL   22
#define GPIO_LPWM_BTS7960_R_WHEEL_VALUE(X) analogWrite(GPIO_PIN_LPWM_BTS7960_R_WHEEL, X)
#define GPIO_LPWM_BTS7960_R_WHEEL_MODE(X)  pinMode(GPIO_PIN_LPWM_BTS7960_R_WHEEL , X)

#define GPIO_PIN_RPWM_BTS7960_R_WHEEL   19
#define GPIO_RPWM_BTS7960_R_WHEEL_VALUE(X) analogWrite(GPIO_PIN_RPWM_BTS7960_R_WHEEL, X)
#define GPIO_RPWM_BTS7960_R_WHEEL_MODE(X)  pinMode(GPIO_PIN_RPWM_BTS7960_R_WHEEL , X)


//#define GPIO_PIN_EN_BTS7960_R    
#define GPIO_WRITE(X, Y) digitalWrite(X, Y)

//================================================================================================//
//                                          ENUMERATIONS                                          //
//================================================================================================//

//================================================================================================//
//                                      STRUCTURES ET UNIONS                                      //
//================================================================================================//

//================================================================================================//
//                                VARIABLES ET FONCTION PARTAGEES                                 //
//================================================================================================//

//------------------------------------------------------------------------------------------------//
//---                                        Variables                                         ---//
//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//
//---                                        Fonctions                                         ---//
//------------------------------------------------------------------------------------------------//
void BOARD_Init(void);
uint32_t BOARD_GetTick(void);
void BOARD_Delayms(uint32_t value);
void BOARD_Delayus(uint32_t value);
#endif //--- _BOARD_
