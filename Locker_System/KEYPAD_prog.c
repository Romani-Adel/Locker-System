/*****************************************/
/*          Author: Romani Adel          */
/*          Date: 18-2-2024              */
/*          Version: 1.0                 */
/*          Module: KEYPAD               */
/*****************************************/
#include "STD_types.h"
#include "DIO_int.h"
#include "KEYPAD_int.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

void KEYPAD_voidInit(void)
{
    /*
	• To make sure that all these pins took high. 
	• It must be one row at a time to take LOW, in order to decrease the number of possibilities(pressed button).
	*/
	DIO_voidSetPinValue(KEYPAD_U8_R1,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_R2,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_R3,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_R4,DIO_U8_HIGH);

	#if KEYPAD_U8_MODE == KEYPAD_U8_INTERNAL_PULL_UP
	/* Set all buttons to HIGH to activate the internal pull-up resistor */
	DIO_voidSetPinValue(KEYPAD_U8_C1,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_C2,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_C3,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_C4,DIO_U8_HIGH);

	#elif KEYPAD_U8_MODE == KEYPAD_U8_EXTERNAL_PULL_UP
	// Connect external pull-up resistor hardware

	#endif
}
u8 KEYPAD_u8GetButton(void)
{
	/* Apply sequence 1 => 0111 */ 
	DIO_voidSetPinValue(KEYPAD_U8_R1,DIO_U8_LOW);
    DIO_voidSetPinValue(KEYPAD_U8_R2,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_R3,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_R4,DIO_U8_HIGH);

	/* Check if any button is pressed from row 1, then return its intersection with the column */
	if (DIO_voidGetPinValue(KEYPAD_U8_C1) == DIO_U8_LOW)
	{
		return R1C1;
	}
	else if (DIO_voidGetPinValue(KEYPAD_U8_C2) == DIO_U8_LOW)
	{
		return R1C2;
	}
	else if (DIO_voidGetPinValue(KEYPAD_U8_C3) == DIO_U8_LOW)
	{
		return R1C3;
	}
	else if (DIO_voidGetPinValue(KEYPAD_U8_C4) == DIO_U8_LOW)
	{
		return R1C4;
	}
	/******************************* End of sequence 1 *******************************/

	/* Apply sequence 2 => 1011 */
	DIO_voidSetPinValue(KEYPAD_U8_R1,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_R2,DIO_U8_LOW);
    DIO_voidSetPinValue(KEYPAD_U8_R3,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_R4,DIO_U8_HIGH);

	/* Check if any button is pressed from row 2, then return its intersection with the column */
	if (DIO_voidGetPinValue(KEYPAD_U8_C1) == DIO_U8_LOW)
	{
		return R2C1;
	}
	else if (DIO_voidGetPinValue(KEYPAD_U8_C2) == DIO_U8_LOW)
	{
		return R2C2;
	}
	else if (DIO_voidGetPinValue(KEYPAD_U8_C3) == DIO_U8_LOW)
	{
		return R2C3;
	}
	else if (DIO_voidGetPinValue(KEYPAD_U8_C4) == DIO_U8_LOW)
	{
		return R2C4;
	}
	/******************************* End of sequence 2 *******************************/

	/* Apply sequence 3 => 1101 */
	DIO_voidSetPinValue(KEYPAD_U8_R1,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_R2,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_R3,DIO_U8_LOW);
    DIO_voidSetPinValue(KEYPAD_U8_R4,DIO_U8_HIGH);

	/* Check if any button is pressed from row 3, then return its intersection with the column */
	if (DIO_voidGetPinValue(KEYPAD_U8_C1) == DIO_U8_LOW)
	{
		return R3C1;
	}
	else if (DIO_voidGetPinValue(KEYPAD_U8_C2) == DIO_U8_LOW)
	{
		return R3C2;
	}
	else if (DIO_voidGetPinValue(KEYPAD_U8_C3) == DIO_U8_LOW)
	{
		return R3C3;
	}
	else if (DIO_voidGetPinValue(KEYPAD_U8_C4) == DIO_U8_LOW)
	{
		return R3C4;
	}
	/******************************* End of sequence 3 *******************************/

	/* Apply sequence 4 => 1110 */
	DIO_voidSetPinValue(KEYPAD_U8_R1,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_R2,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_R3,DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_R4,DIO_U8_LOW);

	/* Check if any button is pressed from row 4, then return its intersection with the column */
	if (DIO_voidGetPinValue(KEYPAD_U8_C1) == DIO_U8_LOW)
	{
		return R4C1;
	}
	else if (DIO_voidGetPinValue(KEYPAD_U8_C2) == DIO_U8_LOW)
	{
		return R4C2;
	}
	else if (DIO_voidGetPinValue(KEYPAD_U8_C3) == DIO_U8_LOW)
	{
		return R4C3;
	}
	else if (DIO_voidGetPinValue(KEYPAD_U8_C4) == DIO_U8_LOW)
	{
		return R4C4;
	}
	/******************************* End of sequence 4 *******************************/
	return KEYPAD_U8_NULL_CHAR;
	
}

