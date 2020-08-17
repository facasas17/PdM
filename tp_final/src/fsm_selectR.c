/*=====[ fsm_selectR ]===========================================================
 * Fabiola de las Casas Escardo <fabioladelascasas@gmail.com>
 * Date: 2020/08/06
 * Version: 1.0

/*=====[Inclusion of own header]=============================================*/

#include <fsm_selectR.h>

/*=====[Inclusions of private function dependencies]=========================*/

#include <sapi.h>
#include <resistance.h>

/*=====[Definition macros of private constants]==============================*/

#define ADC_BITS 1024
#define VCC_MICRO 3.3

// Rango de valor leido
const uint16_t MAX_VALUE = ADC_BITS - 1;
const uint16_t MID_MAX_VALUE = (MAX_VALUE * 2)/VCC_MICRO;
const uint16_t MID_MIN_VALUE = (MAX_VALUE * 1)/VCC_MICRO;
const uint16_t MIN_VALUE = 0;
const uint16_t HISTERESIS = 10;

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

// Posibles estados de la MEF
typedef enum{
	MAX,
	MID,
	MIN,
} selectState_t;

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

static selectState_t fsmSelectState;
static uint16_t value;

/*=====[Prototypes (declarations) of private functions]======================*/

static void fsmSelectError(void);

/*=====[Implementations of public functions]=================================*/

void fsmSelectInit( void ){

	boardInit();
	adcConfig( ADC_ENABLE ); /* ADC */
	fsmSelectState = MAX;
	resistanceInit();
}

void fsmSelectUpdate( void ){

	switch(fsmSelectState){
		case MAX:
			// Actualizar salidas
            resistanceSet(RES_HIGH, ON);
            resistanceSet(RES_MID, OFF);
            resistanceSet(RES_LOW, OFF);

            // Chequear condiciones de transicion de estados
            if ( (value > (MID_MIN_VALUE + HISTERESIS)) && (value <= MID_MAX_VALUE) ){
            	fsmSelectState = MID;
            }
            else if ( (value >= MIN_VALUE) && (value <= MID_MIN_VALUE) ){
            		fsmSelectState = MIN;
            	 }

			break;

		case MID:
			// Actualizar salidas
            resistanceSet(RES_HIGH, OFF);
            resistanceSet(RES_MID, ON);
            resistanceSet(RES_LOW, OFF);

            // Chequear condiciones de transicion de estados
            if ( (value > (MID_MAX_VALUE + HISTERESIS)) && (value <= MAX_VALUE) ){
            	fsmSelectState = MAX;
            }
            else if ( (value >= MIN_VALUE) && (value <= MID_MIN_VALUE) ){
            		fsmSelectState = MIN;
            	 }
			break;

		case MIN:
			// Actualizar salidas
            resistanceSet(RES_HIGH, OFF);
            resistanceSet(RES_MID, OFF);
            resistanceSet(RES_LOW, ON);

            // Chequear condiciones de transicion de estados
            if ( (value > (MID_MAX_VALUE + HISTERESIS)) && (value <= MAX_VALUE) ){
            	fsmSelectState = MAX;
            }
            else if ( (value > (MID_MIN_VALUE + HISTERESIS)) && (value <= MID_MAX_VALUE) ){
            		fsmSelectState = MID;
            	 }
			break;

		default:
			fsmSelectError();
			break;
	}
	value = adcRead( CH1 );
}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/

static void fsmSelectError(void)
{
	fsmSelectInit();
}
