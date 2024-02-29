/*****************************************/
/*          Author: Romani Adel          */
/*          Date: 7-2-2024               */
/*          Version: 1.0                 */
/*          Module: DIO                  */
/*****************************************/

/************** Start - for VSC **********/
//#define __AVR_ATmega32__
#include <avr/io.h>
/************** End - for VSC ************/

#include "STD_types.h"  // First file => Cause not depend in any file down ↓
#include "BIT_math.h"
#include "DIO_int.h"
#include "DIO_config.h"
#include "DIO_private.h"   

void DIO_voidInit(void)
{
    DDRA = DIO_U8_PORTA_DIR;
    DDRB = DIO_U8_PORTB_DIR;
    DDRC = DIO_U8_PORTC_DIR;
    DDRD = DIO_U8_PORTD_DIR;
}
void DIO_voidSetPinValue(u8 Copy_u8Pin,u8 Copy_u8Value)
{
    if (Copy_u8Pin<=DIO_U8_PORTA_LAST_PIN)
    {
        switch (Copy_u8Value)
        {
            case DIO_U8_HIGH: SET_BIT(PORTA,Copy_u8Pin);    break;
            case DIO_U8_LOW: CLEAR_BIT(PORTA,Copy_u8Pin);   break;
        }
    }

    else if (Copy_u8Pin<=DIO_U8_PORTB_LAST_PIN)
    {
        Copy_u8Pin = Copy_u8Pin - (DIO_U8_PORTA_LAST_PIN + DIO_U8_PORT_OFFSET);
        switch (Copy_u8Value)
        {
            case 1: SET_BIT(PORTB,Copy_u8Pin);    break;
            case 0: CLEAR_BIT(PORTB,Copy_u8Pin);  break;
        }
    }

    else if (Copy_u8Pin<=DIO_U8_PORTC_LAST_PIN)
    {
        Copy_u8Pin = Copy_u8Pin - (DIO_U8_PORTB_LAST_PIN + DIO_U8_PORT_OFFSET);
        switch (Copy_u8Value)
        {
            case 1: SET_BIT(PORTC,Copy_u8Pin);    break;
            case 0: CLEAR_BIT(PORTC,Copy_u8Pin);  break;
        }
    }

    else if (Copy_u8Pin<=DIO_U8_PORTD_LAST_PIN)
    {
        Copy_u8Pin = Copy_u8Pin - (DIO_U8_PORTC_LAST_PIN + DIO_U8_PORT_OFFSET);
        switch (Copy_u8Value)
        {
            case 1: SET_BIT(PORTD,Copy_u8Pin);    break;
            case 0: CLEAR_BIT(PORTD,Copy_u8Pin);  break;
        }
    }
    else
    {
        /* error => such as LCD OR SEVEN SEGMENT OR LIGHT RED LED and etc... */
    }
    
}

u8 DIO_voidGetPinValue(u8 Copy_u8Pin)  // return u8 value
{
    u8 Local_u8Value = DIO_U8_HIGH;
    if (Copy_u8Pin<=DIO_U8_PORTA_LAST_PIN)
    {
       Local_u8Value = GET_BIT(PINA,Copy_u8Pin);
    }
    else if (Copy_u8Pin<=DIO_U8_PORTB_LAST_PIN)
    {
       Copy_u8Pin = Copy_u8Pin - (DIO_U8_PORTA_LAST_PIN + DIO_U8_PORT_OFFSET);
       Local_u8Value = GET_BIT(PINB,Copy_u8Pin);
    }
    else if (Copy_u8Pin<=DIO_U8_PORTC_LAST_PIN)
    {
       Copy_u8Pin = Copy_u8Pin - (DIO_U8_PORTB_LAST_PIN + DIO_U8_PORT_OFFSET);
       Local_u8Value = GET_BIT(PINC,Copy_u8Pin);
    }
    else if (Copy_u8Pin<=DIO_U8_PORTD_LAST_PIN)
    {
       Copy_u8Pin = Copy_u8Pin - (DIO_U8_PORTC_LAST_PIN + DIO_U8_PORT_OFFSET);
       Local_u8Value = GET_BIT(PIND,Copy_u8Pin);
    }
    else
    {
        /* error => such as LCD OR SEVEN SEGMENT OR LIGHT RED LED and etc... */
    }
    
    return Local_u8Value;
}






