/*****************************************/
/*          Author : Romani Adel         */
/*          Date   : 29-2-2024           */
/*          Version: 1.0                 */
/*          Project: Locker_System       */
/*****************************************/

#define F_CPU 16000000UL
#include <util/delay.h>
#include "STD_types.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"

#define MAX_ATTEMPTS		 3					// Attempts allowed before blocking access
#define BLOCK_MODE_TIME		 20000				// Duration (20 seconds) for blocking access after exceeding the maximum number of attempts (3)
#define MAX_PASSWORD_LENGTH	 16					// Limited by the LCD display width (16 characters)

u8 kp_value = KEYPAD_U8_NULL_CHAR;				// Variable to store the pressed button for Keypad
u8 number_of_digits = 0;						// Variable to track the number of digits entered during password setting
u8 counter = 0;									// Variable to track the number of digits entered during password checking
u8 attempts = 0;								// Variable to track the number of password authentication attempts
u8 set_password[MAX_PASSWORD_LENGTH] = {0};		// Array to store the password when set
u8 check_password[MAX_PASSWORD_LENGTH] = {0};	// Array to store the password when check


/*******************************************************************************
*                      	Function prototypes                                	   *
*******************************************************************************/
u8	 password_compareProcess(u8 a[], u8 b[], u8 set_password_length, u8 check_password_length);
void password_authenticationProcess(void);

int main(void)
{
    /* Initialize DIO, LCD, and Keypad */
	DIO_voidInit();
	LCD_voidInit();
	KEYPAD_voidInit();
	
	LCD_voidSendString("Set Password");
	
	while(1)
	{
		/* Wait for the user to press a button on the keypad */
		do 
		{
			kp_value = KEYPAD_u8GetButton();
		} while (kp_value == KEYPAD_U8_NULL_CHAR);
		
		/* If the pressed button is '?', exit the loop */
		if (kp_value == '?') break; 
		
		/* Store the pressed button in the set_password array and increment the number of digits */
		set_password[number_of_digits] = kp_value;
		number_of_digits++;
		
		/* Display the pressed button on the LCD and replace it with '*' */
		LCD_voidSetCursor( LCD_U8_LINE2 , number_of_digits-1);
		LCD_voidSendData(kp_value);
		_delay_ms(200);			
		LCD_voidSetCursor( LCD_U8_LINE2 ,number_of_digits - 1);
		LCD_voidSendData('*');
	}
	
	password_authenticationProcess();
}


/*********************************************************************************************************
* Prototype	  : u8 password_compareProcess(u8 a[], u8 b[], u8 set_password_length, u8 check_password_length)
* Description : Compares two passwords to check if they match.
* Parameters  : � a					    => array containing the set password
*				� b						=> array containing the entered password
*				� set_password_length	=> length of the set password array
*				� check_password_length => length of the entered password array
* return	  : 1 if passwords match, 0 otherwise
*********************************************************************************************************/
u8 password_compareProcess(u8 a[], u8 b[], u8 set_password_length, u8 check_password_length)
{	

	// Check if the lengths of the entered and set passwords are equal
	if (set_password_length != check_password_length) {
		return 0;		// Return false if the lengths are not equal
	}

	// Compare each character of the entered and set passwords
	for (u8 i = 0; i < set_password_length; i++)
	{
		if (a[i] != b[i])
		{
			return 0;	// Return false if any character does not match
		}
	}
	
	// If the loop completes without finding any mismatches, return true
	return 1;			
}


/*********************************************************************************************************
* Prototype	  : void password_authenticationProcess(void)
* Description : � This function prompts the user to enter a password and compares it with the set password.
*               � It hides the entered digits with '*', 
*				� displays feedback messages.
*				� and blocks access after a certain number of failed attempts.
* Parameters  : None
* return	  : None
*********************************************************************************************************/
void password_authenticationProcess(void)
{
	do
	{
		LCD_voidClearScreen();
		_delay_ms(200);
		LCD_voidSetCursor( LCD_U8_LINE1 , LCD_U8_DIGIT1);
		LCD_voidSendString("Check Password");
		kp_value = KEYPAD_U8_NULL_CHAR;
		counter = 0;
		
		while(kp_value != '?')
		{
			do
			{
				kp_value = KEYPAD_u8GetButton();
			} while (kp_value == KEYPAD_U8_NULL_CHAR);
			
			if (kp_value == '?') break;
			check_password[counter] = kp_value;
			counter++;
			
			LCD_voidSetCursor( LCD_U8_LINE2 , counter - 1);
			LCD_voidSendData(kp_value);
			_delay_ms(200);			// Wait until I remove my hand from the button.
			LCD_voidSetCursor( LCD_U8_LINE2 , counter - 1);
			LCD_voidSendData('*');
			
			
		}
		
		if (password_compareProcess(set_password,check_password,number_of_digits,counter))
		{
			LCD_voidClearScreen();
			LCD_voidSendString("Loading...");
			
			for(u8 i=0; i<4; i++)
			{
				LCD_voidSendData('.');
				_delay_ms(300);
			}
			LCD_voidClearScreen();
			LCD_voidSendString("Welcome !! ");
			break;
			
		}
		else
		{
			LCD_voidClearScreen();
			LCD_voidSendString("Wrong Password");
			_delay_ms(500);
			
			attempts++;
			
			if (attempts >= MAX_ATTEMPTS)
			{
				LCD_voidClearScreen();
				LCD_voidSendString("Maximum attempts!!");
				LCD_voidSetCursor( LCD_U8_LINE2 , LCD_U8_DIGIT1);
				LCD_voidSendString("Wait 20 seconds");
				_delay_ms(BLOCK_MODE_TIME);
				attempts=0;	
			}
			LCD_voidClearScreen();
			LCD_voidSendString("Tries left ");
			LCD_voidSendData((MAX_ATTEMPTS - attempts)+'0');
			_delay_ms(500);
		}
		
	}while (attempts < MAX_ATTEMPTS);
}


