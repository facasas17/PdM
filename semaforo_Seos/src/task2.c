/*============================================================================
 * License: BSD-3-Clause
 * Copyright 2018, Eric Pernia <ericpernia@gmail.com>
 * All rights reserved.
 * Date: 2018/10/04
 *===========================================================================*/

/*==================[inclusions]=============================================*/

#include "task2.h"  // <= own header
#include "button.h"

/*==================[macros and definitions]=================================*/

// Tiempo en ms de espera para verificación
#define TIME_WAITING 40

/*==================[internal data declaration]==============================*/

// FSM state names
typedef enum{
	button_up,
	button_falling,
	button_rising,
	button_down,
} debounce_t;

/*==================[internal functions declaration]=========================*/

static void fsmError(void);

/*==================[internal data definition]===============================*/

static debounce_t fsmState;

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

static void fsmError(void)
{
	task2_Init();
}

/*==================[external functions definition]==========================*/

// Funcion que inicializa la tarea
void task2_Init( void ){
	fsmState = button_down;
}

// Funcion que se ejecuta periodicamente
void task2_Update( void* taskParam ){

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

/*==================[end of file]============================================*/
