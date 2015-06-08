#include "LedSM.h"
#include <stdio.h>


void ledSM(LedData *data)
{
	switch (data->state)
	{
	
	
		default : 
					printf("Error : unknown state encountered in ledSM : %d\n",data->state);
					break ;
	}
}