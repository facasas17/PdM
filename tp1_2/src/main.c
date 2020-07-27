/*=============================================================================
 * Copyright (c) 2020, Fabiola de las Casas Escardo <fabioladelascasas@gmail.com>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE.txt)
 * Date: 2020/07/27
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../inc/main.h"

#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();

   gpioMap_t secuencia1[] = {LED1, LED2, LED3, LEDB};
   gpioMap_t secuencia2[] = {LED3, LED2, LED1, LEDB};
   gpioMap_t *secuencias[] = {secuencia1, secuencia2};
   gpioMap_t **ptr_secuencia = secuencias;

   uint32_t tiempoEncendido[] = {150, 750};
   uint32_t *ptr_tiempo = tiempoEncendido;

   int8_t i = 3;
   uint8_t sequence = 0;

   delay_t delay;
   /* Inicializar Retardo no bloqueante con tiempo en milisegundos */
   delayConfig( &delay, 500 );

   // ----- Repeat for ever -------------------------
   while(1) {

      if ( !gpioRead( TEC1 ) ){
         sequence = 0;
         *ptr_secuencia = *secuencias;
      }
      if ( !gpioRead( TEC2 ) ){
         /* Velocidad Rapida */
         delayWrite( &delay, *ptr_tiempo );
      }
      if ( !gpioRead( TEC3 ) ){
         /* Velocidad Lenta */
         delayWrite( &delay, *(ptr_tiempo+1) );
      }
      if ( !gpioRead( TEC4 ) ){
         sequence = 1;
         *ptr_secuencia = *(secuencias + 1);
      }

      /* delayRead retorna TRUE cuando se cumple el tiempo de retardo */
      if ( delayRead( &delay ) ){
         if ( !sequence ){
            i--;
         }
         else{
            i++;
         }
      }

      if ( i == 0 ){
         gpioWrite( LEDB, ON );
         gpioWrite( LED1, OFF );
         gpioWrite( LED2, OFF );
         gpioWrite( LED3, OFF );
      }
      if ( i == 1 ){
         gpioWrite( LEDB, OFF );
         gpioWrite( LED1, ON );
         gpioWrite( LED2, OFF );
         gpioWrite( LED3, OFF );
      }
      if ( i == 2 ){
         gpioWrite( LEDB, OFF );
         gpioWrite( LED1, OFF );
         gpioWrite( LED2, ON );
         gpioWrite( LED3, OFF );
      }
      if ( i == 3 ){
         gpioWrite( LEDB, OFF );
         gpioWrite( LED1, OFF );
         gpioWrite( LED2, OFF );
         gpioWrite( LED3, ON );
      }

      if ( i < 0 ){
         i = 3;
      }
      if ( i > 3 ){
         i = 0;
      }

   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
