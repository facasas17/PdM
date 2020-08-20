/*=====[ Resistance ]===========================================================
 * Fabiola de las Casas Escardo <fabioladelascasas@gmail.com>
 * Date: 2020/08/06
 * Version: 1.0


/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef PDM_TP_FINAL_INC_RESISTANCE_H_
#define PDM_TP_FINAL_INC_RESISTANCE_H_

/*=====[Inclusions of public function dependencies]==========================*/

#include <sapi.h>

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

typedef enum{
    RES_HIGH = LED2,
    RES_MID = LED1,
    RES_LOW = LED3,
} resistance_t;

/*=====[Prototypes (declarations) of public functions]=======================*/

void resistanceInit( void );
void resistanceSet( resistance_t resistance, bool_t state );

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

#endif /* PDM_TP_FINAL_INC_RESISTANCE_H_ */
