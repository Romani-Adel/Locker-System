/* 
* ======= File guard =======
Include guards ensures that compiler will process this file only once, 
no matter how many times it is included.
*/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

// These sizes based on Gcc tool chain 

typedef unsigned char       u8;    // unsigned character 8 bit size 
typedef unsigned short int  u16;
typedef unsigned int        u32;
typedef unsigned long int   u64; 

typedef char       s8;
typedef short int s16;
typedef int       s32;
typedef long int  s64;

typedef float     f32;
typedef double    f64;


#endif