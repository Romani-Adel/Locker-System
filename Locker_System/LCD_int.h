/*****************************************/
/*          Author: Romani Adel          */
/*          Date: 15-2-2024              */
/*          Version: 1.0                 */
/*          Module: LCD                  */
/*****************************************/
#ifndef LCD_int_H
#define LCD_int_H

/*** Hint: Line + Digit = Address ***/
/***************** Line addresses for (SetCursor) *****************/
#define LCD_U8_LINE1    0X80
#define LCD_U8_LINE2    0XC0

/***************** Column addresses for (SetCursor) *****************/
#define LCD_U8_DIGIT1       0
#define LCD_U8_DIGIT2       1
#define LCD_U8_DIGIT3       2
#define LCD_U8_DIGIT4       3
#define LCD_U8_DIGIT5       4
#define LCD_U8_DIGIT6       5
#define LCD_U8_DIGIT7       6
#define LCD_U8_DIGIT8       7
#define LCD_U8_DIGIT9       8
#define LCD_U8_DIGIT10      9
#define LCD_U8_DIGIT11      10
#define LCD_U8_DIGIT12      11
#define LCD_U8_DIGIT13      12
#define LCD_U8_DIGIT14      13
#define LCD_U8_DIGIT15      14
#define LCD_U8_DIGIT16      15

/***************** The first Place/Address at CGRAM for (CustomChar)  *****************/
#define LCD_U8_CGRAM    0X40

/***************** all characters with ASCII 'space' *****************/
#define lCD_Clear		0x01          

void LCD_voidInit(void);
void LCD_voidSendData(u8 copy_u8Data);
void LCD_voidSendCommand(u8 copy_u8Data);
void LCD_voidSetCursor(u8 copy_u8Line , u8 copy_u8Column);
void LCD_voidSendCustomChar(u8 copy_u8Line , u8 copy_u8Column);
void LCD_voidSendString(s8 *string);

void LCD_Send_Number(u32 num);


// =========================================================================================
/*
* Prototype	  : void LCD_voidClearScreen(void);
* Description : This Function clear LCD
* Parameters  : nothing
* return	  : nothing
*/
void LCD_voidClearScreen(void);
// =========================================================================================



#endif /* LCD_int_H */
