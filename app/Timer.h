#ifndef Timer_H
#define Timer_H

#ifndef TEST
#include "stm32f4xx_hal.h"
#endif
#include "stm32f4xx_hal_gpio.h"

void updateCurrentTime();
int checkTime(int Time_LED,int LED_no);

#endif // Timer_H
