/*****************************************/
/*          Author: Romani Adel          */
/*          Date: 7-2-2024               */
/*          Version: 1.0                 */
/*          Module: BIT_math             */
/*****************************************/

// To be able to handle the bit (since C language good at bit manipulation)
#ifndef BIT_MATH
#define BIT_MATH

//  Function-Like Macros ↓↓ 
/*
Register =>   1|1|0|1|0|1|1|0|
And I want to put in third bit the value of 1 
*/
#define SET_BIT(var,bitNo) (var  = var | (1 << bitNo)) // Set the bit (to 1 or nothing can change)

/* 
• ~ => "bitwise NOT" and "one's complement" are often used interchangeably.
• Bitwise NOT (~): Performs a bitwise complement or one's complement operation on each bit of the operand.
• It's important to note that bitwise NOT is different from logical NOT (!). 
    The logical NOT operates on a boolean value, whereas bitwise NOT operates on each individual bit of an integer value.
*/
#define CLEAR_BIT(var,bitNo) (var = var & ~(1 << bitNo))    // Clear the bit (to 0)

#define TOGGLE_BIT(var,bitNo) (var = var ^ (1 << bitNo))    // Toggle the bit (1 to 0 or 0 to 1)

#define GET_BIT(var,bitNo) (var >> bitNo & 1) // Get the bit (to know by if condition, if the bit is 1 or 0) 

// For set and clear high and low nibble (nibbles are 4 bits aka half byte)
#define SET_HIGH_NIBBLE(var) (var = var | 0xF0)   
#define CLEAR_HIGH_NIBBLE(var) (var = var & 0x0F)
#define SET_LOW_NIBBLE(var) (var = var | 0x0F)
#define CLEAR_LOW_NIBBLE(var) (var = var & 0xF0)

// For concatenation 
// Make it in two stages (see the example below)
// Because the preprocessor doesn't make two operations(text replacement) at the same time 
#define CONC_BIT(A7,A6,A5,A4,A3,A2,A1,A0)   CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)  
#define CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)  0b##A7##A6##A5##A4##A3##A2##A1##A0



#endif  /* BIT_MATH_H */