/*=============================================================================
 * Copyright (c) 2020, Fabiola de las Casas Escardo <fabioladelascasas@gmail.com>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE.txt)
 * Date: 2020/07/16
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "sapi.h"

/*=====[Definitions of public functions]=====================================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
	/* Inicializar la placa */
    boardInit();

    /* Variable de Retardo no bloqueante */
    delay_t delay1;
    delay_t delay2;
    delay_t delay3;

    /* Contador de tiempo de LEDS */
    int32_t contLED[3] = {0, 0, 0};

    while(true){

    	if ( !gpioRead(TEC1) ){
        	++contLED[1];
    	}
    	else {
    		if ( contLED[1] > 0 ){
    			gpioWrite(LED1, ON);
    			--contLED[1];
    		}
    		else{
    			gpioWrite(LED1, OFF);
    			contLED[1] = 0;
    		}
    	}

        if ( !gpioRead(TEC2) ){
            ++contLED[2];
        }
        else {
        	if ( contLED[2] > 0 ){
        		gpioWrite(LED2, ON);
        		--contLED[2];
        	}
        	else{
        		gpioWrite(LED2, OFF);
        		contLED[2] = 0;
        	}
    	}
        if ( !gpioRead(TEC3) ){
            ++contLED[3];
        }
        else {
        	if ( contLED[3] > 0 ){
        		gpioWrite(LED3, ON);
        		--contLED[3];
        	}
        	else{
        		gpioWrite(LED3, OFF);
        		contLED[3] = 0;
        	}
    	}

    	/* Delay bloqueante para estandarizar los tiempos en 1 ms */
    	delay(1);
    }
}

