/*============================================================================
 * License: BSD-3-Clause
 * Copyright 2018, Eric Pernia <ericpernia@gmail.com>
 * All rights reserved.
 * Date: 2018/10/04
 *===========================================================================*/

/*==================[inclusions]=============================================*/

#include "../../semaforo_Seos/inc/task1.h"  // <= own header
#include "lamp.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

// Posibles estados
typedef enum{
    RED_STATE,
    RED_YELLOW_STATE,
    GREEN_STATE,
    YELLOW_STATE,
} state_t;

/*==================[internal functions declaration]=========================*/

static void fsmSemaphoreError(void);

/*==================[internal data definition]===============================*/

static state_t currentState;

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

static void fsmSemaphoreError(void)
{
	task1_Init();
}

/*==================[external functions definition]==========================*/

// Funcion que inicializa la tarea
void task1_Init( void ){

   gpioInit(RED_LAMP, GPIO_OUTPUT);
   gpioInit(YELLOW_LAMP, GPIO_OUTPUT);
   gpioInit(GREEN_LAMP, GPIO_OUTPUT);
   currentState = RED;
}

// Funcion que se ejecuta periodicamente
void task1_Update( void* taskParam ){

    static uint32_t counter = 0;

    switch( currentState ){
        case RED_STATE:
            // Actualizar salidas
            lampSet(RED_LAMP, ON);
            lampSet(YELLOW_LAMP, OFF);
            lampSet(GREEN_LAMP, OFF);
            // Chequear condiciones de transicion de estados
            if ( counter >= TIME_RED ){
            	currentState = RED_YELLOW_STATE;
                counter = 0;
            }

        break;

        case RED_YELLOW_STATE:
            // Actualizar salidas
            lampSet(RED_LAMP, ON);
            lampSet(YELLOW_LAMP, ON);
            lampSet(GREEN_LAMP, OFF);
            // Chequear condiciones de transicion de estados
            if ( counter >= TIME_RED_YELLOW ){
            	currentState = GREEN_STATE;
                counter = 0;
            }
        break;

        case GREEN_STATE:
            // Actualizar salidas
            lampSet(RED_LAMP, OFF);
            lampSet(YELLOW_LAMP, OFF);
            lampSet(GREEN_LAMP, ON);
            // Chequear condiciones de transicion de estados
            if ( counter >= TIME_GREEN ){
            	currentState = YELLOW_STATE;
                counter = 0;
            }
        break;

        case YELLOW_STATE:
            // Actualizar salidas
            lampSet(RED_LAMP, OFF);
            lampSet(YELLOW_LAMP, ON);
            lampSet(GREEN_LAMP, OFF);
            // Chequear condiciones de transicion de estados
            if ( counter >= TIME_YELLOW ){
            	currentState = RED_STATE;
                counter = 0;
            }
        break;

        default:
            fsmSemaphoreError();
        break;
    }
    counter++;
}

/*==================[end of file]============================================*/
