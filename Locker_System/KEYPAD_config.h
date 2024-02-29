/*****************************************/
/*          Author: Romani Adel          */
/*          Date: 18-2-2024              */
/*          Version: 1.0                 */
/*          Module: KEYPAD               */
/*****************************************/
#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

/* This is known as Pre-build configuration
Options:
• KEYPAD_U8_INTERNAL_PULL_UP
• KEYPAD_U8_EXTERNAL_PULL_UP
*/
#define KEYPAD_U8_MODE  KEYPAD_U8_INTERNAL_PULL_UP


/* Rows Pins of KEYPAD */
#define KEYPAD_U8_R1    DIO_U8_PIN12 //B4
#define KEYPAD_U8_R2    DIO_U8_PIN13
#define KEYPAD_U8_R3    DIO_U8_PIN14
#define KEYPAD_U8_R4    DIO_U8_PIN15 //CB7

/* Columns Pins of KEYPAD */
#define KEYPAD_U8_C1    DIO_U8_PIN19 //C3
#define KEYPAD_U8_C2    DIO_U8_PIN20
#define KEYPAD_U8_C3    DIO_U8_PIN21
#define KEYPAD_U8_C4    DIO_U8_PIN22 //C6

/* Macros for RxCy to make them portable across any keypad.*/
#define R1C1    '7'
#define R1C2    '8'
#define R1C3    '9'
#define R1C4    '/'

#define R2C1    '4'
#define R2C2    '5'
#define R2C3    '6'
#define R2C4    '*'

#define R3C1    '1'
#define R3C2    '2'
#define R3C3    '3'
#define R3C4    '-'

#define R4C1    '?'
#define R4C2    '0'
#define R4C3    '='
#define R4C4    '+'

#endif /* KEYPAD_CONFIG_H */
