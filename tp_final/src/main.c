/*=============================================================================
 * Copyright (c) 2020, Fabiola de las Casas Escardo <fabioladelascasas@gmail.com>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE.txt)
 * Date: 2020/08/13
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../inc/main.h"

#include "sapi.h"

#include "fsm_selectR.h"

/*=====[Definition macros of private constants]==============================*/

#define FSM_SELECT_PERIODICITY  1   /* Periodicidad de ejecucion de la FSM */

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------

   delay_t fsm_select;		/* Defino delay no bloqueante para la actualización de la MEF */
   delayInit( &fsm_select, FSM_SELECT_PERIODICITY );

   fsmSelectInit();

   // ----- Repeat for ever -------------------------
   while( true ) {
       if( delayRead(&fsm_select) ){
           fsmSelectUpdate();
       }
   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
