#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#include <stdint.h>
#include <string.h>
#include <math.h>

#define assert_param(expr) ((void)0)

#define INFO_SOFT_SIZE 19
#define MAX_LEN_NAME 19

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

typedef uint8_t (*COM_CHECK_PTR_FUNC)(uint8_t const *const, const uint16_t, uint8_t);
typedef void (*COM_REPLY_PTR_FUNC)(uint8_t const *const, uint8_t *const, uint8_t);
typedef void (*COM_PROCESS_PTR_FUNC)(uint8_t const *const, const uint16_t);

typedef struct
{
    uint8_t cmde;
    COM_CHECK_PTR_FUNC check;
    COM_REPLY_PTR_FUNC reply;
    COM_PROCESS_PTR_FUNC process;
} s_COM_FUNC;

#define DEFINE_CHECK_CMD(X) uint8_t _Check##X(uint8_t const *const in, const uint16_t len, uint8_t dest)
#define DEFINE_REPLY_CMD(X) void _Reply##X(uint8_t const *const in, uint8_t *const out , uint8_t dest)

#define DECLARE_CMD(X)   \
    DEFINE_CHECK_CMD(X); \
    DEFINE_REPLY_CMD(X)

#define SET_CMD(MODULE, FCT) {CMD_##FCT, MODULE##_Check##FCT, MODULE##_Reply##FCT}

typedef void (*const MEDIUM_INIT)(void);
typedef void (*const MEDIUM_SEND_TAB)(uint8_t const *const, uint16_t);
typedef void (*const MEDIUM_RST_IDX)(void);
typedef uint16_t (*const MEDIUM_GET_IDX)(void);
typedef bool (*const MEDIUM_IS_FRAME_SENT)(void);

typedef struct //--- s_COM_DESC
{
    uint8_t const *const in;
    const uint16_t inBuffSize;
    uint8_t *const out;
    const uint16_t outBuffSize;
    MEDIUM_INIT init;
    MEDIUM_SEND_TAB sendTab;
    MEDIUM_RST_IDX resetIndex;
    MEDIUM_GET_IDX getIndex;
    MEDIUM_IS_FRAME_SENT isFrameSent;
} s_COM_DESC;

typedef struct //--- s_SERIAL_NUM
{
    //--- Attention, si changement dans cette structure -> verifier la gestion des numero de serie dans le mapping memoire
    uint8_t classe;
    uint8_t gamme;
    uint16_t year;
    uint8_t week;
    uint32_t num;
} s_SERIAL_NUM;

typedef struct //--- s_VERSION
{
    float num;
    uint8_t stage;
    uint16_t build;
} s_VERSION;

typedef struct //--- s_PRODUCT_IDENT
{
    //--- Identification
    uint32_t code;
    char name[MAX_LEN_NAME];

    //--- Numero de serie
    s_SERIAL_NUM serial;

    //--- Version de Soft
    s_VERSION vers;
} s_PRODUCT_IDENT;

typedef struct
{
    uint8_t second;
    uint8_t minute;
    uint8_t hour;

    uint8_t day;
    uint8_t month;
    uint8_t dow;
    uint16_t year;
} DateTime;

typedef struct //--- s_CERTIF
{
    uint8_t type;
    DateTime date;
    uint8_t period;
} s_CERTIF;

typedef struct //--- s_DEVICE
{
    //--- Identite
    s_PRODUCT_IDENT ident;

    //--- Certificat
    s_CERTIF certif;

} s_DEVICE;


#define MAX_DEVICE_NAME 10
typedef struct
{
    uint32_t dec;               //-- Code
    uint8_t dev[MAX_DEVICE_NAME]; //-- Name
    uint32_t cen;               //-- Rom Code Size
    uint32_t den;               //-- Rom Data Size
    uint32_t ver;               //-- Version
} s_CHIP;

typedef enum
{
    NO_DIRECTION = -1,
    FORWARD_DIRECTION,
    BACKWARD_DIRECTION
} e_MOWER_DIRECTION;

#endif