/*
 * button.c
 *
 *  Created on: 6 ago. 2020
 *      Author: fdelascasas
 */

/*=====[Inclusion of own header]=============================================*/

#include "button.h"

/*=====[Inclusions of private function dependencies]=========================*/

#include <sapi.h>

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/


bool buttonState(void){

	if ( gpioRead(TEC1) ){
		return 1;    /* Botón presionado */
	}
	else return 0;    /* Botón liberado */
}

void buttonPressed( void ){
	gpioWrite(LED1, OFF);
	gpioWrite(LED2, ON);

}

void buttonReleased( void ){
	gpioWrite(LED1, ON);
	gpioWrite(LED2, OFF);
}

