/*=============================================================================
 * Copyright (c) 2020, Fabiola de las Casas Escardo <fabioladelascasas@gmail.com>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE.txt)
 * Date: 2020/08/06
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../../antirrebote_mef/inc/main.h"

#include "../../antirrebote_mef/inc/debounce.h"
#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/

// Periodicidad de ejecucion de la FSM
#define FSM_PERIODICITY  1

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------

   delay_t fsm;

   delayInit( &fsm, FSM_PERIODICITY );

   fsmInit();

   // ----- Repeat for ever -------------------------
   while( true ) {
       if( delayRead(&fsm) ){
    	   fsmSelectUpdate();
       }
   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
