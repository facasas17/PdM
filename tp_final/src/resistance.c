/*=====[ resistance ]===========================================================
 * Fabiola de las Casas Escardo <fabioladelascasas@gmail.com>
 * Date: 2020/08/06
 * Version: 1.0

/*=====[Inclusion of own header]=============================================*/

#include <resistance.h>

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

void resistanceInit( void )
{
	gpioInit(RES_HIGH, GPIO_OUTPUT);
    gpioInit(RES_MID, GPIO_OUTPUT);
    gpioInit(RES_LOW, GPIO_OUTPUT);
}

void resistanceSet(resistance_t resistance, bool_t state)
{
	gpioWrite( resistance, state );
}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/
