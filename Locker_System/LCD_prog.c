/*****************************************/
/*          Author: Romani Adel          */
/*          Date: 15-2-2024              */
/*          Version: 1.0                 */
/*          Module: LCD                  */
/*****************************************/
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_customChar.h"

#define F_CPU 16000000UL
#include <util/delay.h>

void LCD_voidInit(void)
{
     _delay_ms(35);
     LCD_voidSendCommand(0x33);
     _delay_ms(2);
     LCD_voidSendCommand(0x32);
     _delay_ms(2);
     LCD_voidSendCommand(0x28);
     _delay_ms(2);
     LCD_voidSendCommand(0x0C);
     _delay_ms(2);
     LCD_voidSendCommand(0x06);
     _delay_ms(2);
     LCD_voidSendCommand(0x01);
     _delay_ms(2);  
}

#if LCD_U8_MODE == LCD_U8_4BIT 
void LCD_voidSendData(u8 copy_u8Data)
{
    DIO_voidSetPinValue(LCD_U8_RW , DIO_U8_LOW);
    DIO_voidSetPinValue(LCD_U8_RS , DIO_U8_HIGH);

    /* Read each bit and see if it HIGH or LOW to set the value (HIGH OR LOW) */
	/************************* High Nipple *************************/
    if (GET_BIT(copy_u8Data,DIO_U8_PIN4) == 0)
    {
        DIO_voidSetPinValue(LCD_U8_D4 , DIO_U8_LOW);
    }
    else
    {
        DIO_voidSetPinValue(LCD_U8_D4 , DIO_U8_HIGH);
    }
    /************************ End of PIN 4 ************************/
    if (GET_BIT(copy_u8Data,DIO_U8_PIN5) == 0)
    {
        DIO_voidSetPinValue(LCD_U8_D5 , DIO_U8_LOW);
    }
    else
    {
        DIO_voidSetPinValue(LCD_U8_D5 , DIO_U8_HIGH);
    }
    /************************ End of PIN 5 ************************/
    if (GET_BIT(copy_u8Data,DIO_U8_PIN6) == 0)
    {
        DIO_voidSetPinValue(LCD_U8_D6 , DIO_U8_LOW);
    }
    else
    {
        DIO_voidSetPinValue(LCD_U8_D6 , DIO_U8_HIGH);
    }
    /************************ End of PIN 6 ************************/
    if (GET_BIT(copy_u8Data,DIO_U8_PIN7) == 0)
    {
        DIO_voidSetPinValue(LCD_U8_D7 , DIO_U8_LOW);
    }
    else
    {
        DIO_voidSetPinValue(LCD_U8_D7 , DIO_U8_HIGH);
    }
    /************************ End of PIN 7 ************************/
	DIO_voidSetPinValue(LCD_U8_EN,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_EN,DIO_U8_LOW);
	_delay_ms(1);
	
	/************************* Low Nipple *************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN0) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D4 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D4 , DIO_U8_HIGH);
	}
	/************************ End of PIN LOW0 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN1) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D5 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D5 , DIO_U8_HIGH);
	}
	/************************ End of PIN LOW1 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN2) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D6 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D6 , DIO_U8_HIGH);
	}
	/************************ End of PIN LOW2 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN3) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D7 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D7 , DIO_U8_HIGH);
	}
	/************************ End of PIN LOW3 ************************/
	
	DIO_voidSetPinValue(LCD_U8_EN,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_EN,DIO_U8_LOW);
	_delay_ms(1);
	
	
}
void LCD_voidSendCommand(u8 copy_u8Data)
{
    DIO_voidSetPinValue(LCD_U8_RW , DIO_U8_LOW);
    DIO_voidSetPinValue(LCD_U8_RS , DIO_U8_LOW);

    /************************* High Nipple *************************/
    if (GET_BIT(copy_u8Data,DIO_U8_PIN4) == 0)
    {
	    DIO_voidSetPinValue(LCD_U8_D4 , DIO_U8_LOW);
    }
    else
    {
	    DIO_voidSetPinValue(LCD_U8_D4 , DIO_U8_HIGH);
    }
    /************************ End of PIN 4 ************************/
    if (GET_BIT(copy_u8Data,DIO_U8_PIN5) == 0)
    {
	    DIO_voidSetPinValue(LCD_U8_D5 , DIO_U8_LOW);
    }
    else
    {
	    DIO_voidSetPinValue(LCD_U8_D5 , DIO_U8_HIGH);
    }
    /************************ End of PIN 5 ************************/
    if (GET_BIT(copy_u8Data,DIO_U8_PIN6) == 0)
    {
	    DIO_voidSetPinValue(LCD_U8_D6 , DIO_U8_LOW);
    }
    else
    {
	    DIO_voidSetPinValue(LCD_U8_D6 , DIO_U8_HIGH);
    }
    /************************ End of PIN 6 ************************/
    if (GET_BIT(copy_u8Data,DIO_U8_PIN7) == 0)
    {
	    DIO_voidSetPinValue(LCD_U8_D7 , DIO_U8_LOW);
    }
    else
    {
	    DIO_voidSetPinValue(LCD_U8_D7 , DIO_U8_HIGH);
    }
    /************************ End of PIN 7 ************************/
    DIO_voidSetPinValue(LCD_U8_EN,DIO_U8_HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(LCD_U8_EN,DIO_U8_LOW);
    _delay_ms(1);
    
    /************************* Low Nipple *************************/
    if (GET_BIT(copy_u8Data,DIO_U8_PIN0) == 0)
    {
	    DIO_voidSetPinValue(LCD_U8_D4 , DIO_U8_LOW);
    }
    else
    {
	    DIO_voidSetPinValue(LCD_U8_D4 , DIO_U8_HIGH);
    }
    /************************ End of PIN LOW0 ************************/
    if (GET_BIT(copy_u8Data,DIO_U8_PIN1) == 0)
    {
	    DIO_voidSetPinValue(LCD_U8_D5 , DIO_U8_LOW);
    }
    else
    {
	    DIO_voidSetPinValue(LCD_U8_D5 , DIO_U8_HIGH);
    }
    /************************ End of PIN LOW1 ************************/
    if (GET_BIT(copy_u8Data,DIO_U8_PIN2) == 0)
    {
	    DIO_voidSetPinValue(LCD_U8_D6 , DIO_U8_LOW);
    }
    else
    {
	    DIO_voidSetPinValue(LCD_U8_D6 , DIO_U8_HIGH);
    }
    /************************ End of PIN LOW2 ************************/
    if (GET_BIT(copy_u8Data,DIO_U8_PIN3) == 0)
    {
	    DIO_voidSetPinValue(LCD_U8_D7 , DIO_U8_LOW);
    }
    else
    {
	    DIO_voidSetPinValue(LCD_U8_D7 , DIO_U8_HIGH);
    }
    /************************ End of PIN LOW3 ************************/
    
    DIO_voidSetPinValue(LCD_U8_EN,DIO_U8_HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(LCD_U8_EN,DIO_U8_LOW);
    _delay_ms(1);
}


#elif LCD_U8_MODE == LCD_U8_8BIT
void LCD_voidSendData(u8 copy_u8Data)
{
	DIO_voidSetPinValue(LCD_U8_RW , DIO_U8_LOW);
	DIO_voidSetPinValue(LCD_U8_RS , DIO_U8_HIGH);

	/* Read each bit and see if it HIGH or LOW to set the value (HIGH OR LOW) */
	if (GET_BIT(copy_u8Data,DIO_U8_PIN0) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D0 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D0 , DIO_U8_HIGH);
	}
	/************************ End of PIN 0 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN1) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D1 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D1 , DIO_U8_HIGH);
	}
	/************************ End of PIN 1 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN2) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D2 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D2 , DIO_U8_HIGH);
	}
	/************************ End of PIN 2 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN3) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D3 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D3 , DIO_U8_HIGH);
	}
	/************************ End of PIN 3 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN4) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D4 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D4 , DIO_U8_HIGH);
	}
	/************************ End of PIN 4 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN5) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D5 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D5 , DIO_U8_HIGH);
	}
	/************************ End of PIN 5 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN6) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D6 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D6 , DIO_U8_HIGH);
	}
	/************************ End of PIN 6 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN7) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D7 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D7 , DIO_U8_HIGH);
	}
	/************************ End of PIN 7 ************************/
	DIO_voidSetPinValue(LCD_U8_EN,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_EN,DIO_U8_LOW);
	_delay_ms(1);
}
void LCD_voidSendCommand(u8 copy_u8Data)
{
	DIO_voidSetPinValue(LCD_U8_RW , DIO_U8_LOW);
	DIO_voidSetPinValue(LCD_U8_RS , DIO_U8_LOW);

	/* Read each bit and see if it HIGH or LOW to set the value (HIGH OR LOW) */
	if (GET_BIT(copy_u8Data,DIO_U8_PIN0) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D0 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D0 , DIO_U8_HIGH);
	}
	/************************ End of PIN 0 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN1) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D1 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D1 , DIO_U8_HIGH);
	}
	/************************ End of PIN 1 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN2) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D2 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D2 , DIO_U8_HIGH);
	}
	/************************ End of PIN 2 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN3) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D3 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D3 , DIO_U8_HIGH);
	}
	/************************ End of PIN 3 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN4) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D4 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D4 , DIO_U8_HIGH);
	}
	/************************ End of PIN 4 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN5) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D5 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D5 , DIO_U8_HIGH);
	}
	/************************ End of PIN 5 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN6) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D6 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D6 , DIO_U8_HIGH);
	}
	/************************ End of PIN 6 ************************/
	if (GET_BIT(copy_u8Data,DIO_U8_PIN7) == 0)
	{
		DIO_voidSetPinValue(LCD_U8_D7 , DIO_U8_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LCD_U8_D7 , DIO_U8_HIGH);
	}
	/************************ End of PIN 7 ************************/
	
	DIO_voidSetPinValue(LCD_U8_EN,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_EN,DIO_U8_LOW);
	_delay_ms(1);
}



#endif

void LCD_voidSendString(s8 *string)
{
    u8 counter = 0;
    while (string[counter] != '\0')  // Not equal NULL
    {
        LCD_voidSendData(string[counter]);
        counter++;
    } 
}
void LCD_voidSetCursor(u8 copy_u8Line , u8 copy_u8Column)
{
	u8 Local_u8Address = copy_u8Line + copy_u8Column;
	LCD_voidSendCommand(Local_u8Address);
}

void LCD_voidSendCustomChar(u8 copy_u8Line , u8 copy_u8Column)
{
	/* 1- Go to CGRAM */
	LCD_voidSendCommand(LCD_U8_CGRAM);  // Make AC refers to the first Place/Address at CGRAM

	/* 2- Draw character in CGRAM */
	/* Hint: It will be copied to DDRAM automatically */
	for (int i = 0; i < sizeof(LCD_u8CustomChar)/sizeof(LCD_u8CustomChar[0]); i++)
	{
		LCD_voidSendData(LCD_u8CustomChar[i]);
	}

	/* 3- Back AC to DDRAM */
	LCD_voidSetCursor(copy_u8Line,copy_u8Column);

	/* 4- Send character address */
	for (int i = 0; i < 8; i++)
	{
		LCD_voidSendData(i);
	}
}
void LCD_voidClearScreen(void)
{
	LCD_voidSendCommand(lCD_Clear);
	_delay_ms(10); //wait more than 1.53 ms
}


