#include <ll_board.h>
#include "heartbeat.h"

uint32_t _tick;

void setup()
{
  BOARD_Init();

  //-- init _YauS_
  YAUS_Init();

  HEARTBEAT_Init();

  _tick = YAUS_TickCount();
}

void loop()
{
  if (YAUS_TickNbCountSince(_tick) >= 1)
  {
    _tick = YAUS_TickCount();
    YAUS_Update();
  }

  YAUS_Run(false);
}
