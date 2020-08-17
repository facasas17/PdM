/*
 * debounce.c
 *
 *  Created on: 6 ago. 2020
 *      Author: fdelascasas
 */

/*=====[Inclusion of own header]=============================================*/

#include "../../antirrebote_mef/inc/debounce.h"

#include <sapi.h>
#include "../../antirrebote_mef/inc/button.h"

/*=====[Definition macros of private constants]==============================*/

// Tiempo en ms de espera para verificación
#define TIME_WAITING 40

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

// FSM state names
typedef enum{
	button_up,
	button_falling,
	button_rising,
	button_down,
} debounce_t;

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

static debounce_t fsmState;

/*=====[Prototypes (declarations) of private functions]======================*/

static void fsmError(void);

/*=====[Implementations of public functions]=================================*/



void fsmInit( void ){

	boardInit();
	fsmState = button_down;
	gpioWrite(LED1, ON);
}

void fsmUpdate( void ){

	static uint32_t counter = 0;

	switch( fsmState ){

		case button_up:
			if( buttonState() ){
				fsmState = button_falling;
			}
		break;

		case button_falling:
			if( counter == TIME_WAITING ){
				counter = 0;
				if( buttonState() ){
					fsmState = button_down;
					buttonPressed();
				}
				else {
					fsmState = button_up;
				}
			}
			else counter++ ;
		break;

		case button_down:
			if ( !buttonState() ){
				fsmState = button_rising;
			}
		break;

		case button_rising:
			if( counter == TIME_WAITING ){
				counter = 0;
				if( !buttonState() ){
					fsmState = button_up;
					buttonReleased();
				}
				else {
					fsmState = button_down;
				}
			}
			else counter++ ;
		break;

		default:
			fsmError();
			counter = 0;
		break;
	}
}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/

static void fsmError(void)
{
	fsmInit();
}
