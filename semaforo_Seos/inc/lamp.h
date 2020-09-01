/*
 * lamp.h
 *
 *  Created on: 27 ago. 2020
 *      Author: fdelascasas
 */


/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef _LAMP_H_
#define _LAMP_H_

/*=====[Inclusions of public function dependencies]==========================*/

#include <sapi.h>

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

// Tiempo en segundos en cada estado
#define TIME_RED          3
#define TIME_RED_YELLOW   1
#define TIME_GREEN        2
#define TIME_YELLOW       1

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

typedef enum{
    RED_LAMP = LED2,
    YELLOW_LAMP = LED1,
    GREEN_LAMP = LEDG,
} lamp_t;

/*=====[Prototypes (declarations) of public functions]=======================*/

void lampsInit( void );
void lampSet( lamp_t lamp, bool_t state );

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _LAMP_H_ */
