/*****************************************/
/*          Author: Romani Adel          */
/*          Date: 18-2-2024              */
/*          Version: 1.0                 */
/*          Module: KEYPAD               */
/*****************************************/
#ifndef KEYPAD_int_H
#define KEYPAD_int_H

// If no button is pressed, return NULL
#define KEYPAD_U8_NULL_CHAR '\0'

void KEYPAD_voidInit(void);
u8 KEYPAD_u8GetButton(void);


#endif /* KEYPAD_int_H */
