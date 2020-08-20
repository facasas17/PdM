/*=====[ resistance ]===========================================================
 * Fabiola de las Casas Escardo <fabioladelascasas@gmail.com>
 * Date: 2020/08/06
 * Version: 1.0

/*=====[Inclusion of own header]=============================================*/

#include <resistance.h>

/*=====[Inclusions of private function dependencies]=========================*/

#include <sapi.h>

/*=====[Implementations of public functions]=================================*/

void resistanceInit( void )
{
	gpioInit( RES_HIGH, GPIO_OUTPUT );
    gpioInit( RES_MID, GPIO_OUTPUT );
    gpioInit( RES_LOW, GPIO_OUTPUT );
}

void resistanceSet( resistance_t resistance, bool_t state )
{
	gpioWrite( resistance, state );
}

