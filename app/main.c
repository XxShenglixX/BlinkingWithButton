#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "configuration.h"
#include "Timer.h"
#include "LED.h"
#include "LedSM.h"
#include "ButtonSM.h"
#include "State.h"
#include "Message.h"

#define _100ms 100
#define _120ms 120
#define _200ms 200
#define _500ms 500
#define _1000ms 1000
#define _2000ms 2000


int main(void)
{
	LedData ledData ; ButtonData buttonData ;

	ledInitData(&ledData);
	buttonInitData(&buttonData);

	initLED();
	configButton();

	while(1)
	{
		buttonSM(&buttonData);
		ledSM(&ledData);
		updateCurrentTime();
	}


}




