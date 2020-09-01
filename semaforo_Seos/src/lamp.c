/*
 * lamp.c
 *
 *  Created on: 27 ago. 2020
 *      Author: fdelascasas
 */

/*=====[Inclusion of own header]=============================================*/

#include <lamp.h>

/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

void lampsInit( void )
{
    gpioInit(RED_LAMP, GPIO_OUTPUT);
    gpioInit(YELLOW_LAMP, GPIO_OUTPUT);
    gpioInit(GREEN_LAMP, GPIO_OUTPUT);
}

void lampSet( lamp_t lamp, bool_t state )
{
    gpioWrite( lamp, state );
}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/
