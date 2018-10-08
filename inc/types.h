#ifndef HEADER_BIT
#define HEADER_BIT


#include <limits.h>


/* Inspired from SFML code. */
#if UCHAR_MAX == 0xFF
    typedef char int_8_t;
    typedef unsigned char u_int_8_t;
#else
    #error No 8 bits integer type for this platform
#endif
#if USHRT_MAX == 0xFFFF
    typedef short int_16_t;
    typedef unsigned short u_int_16_t;
#elif UINT_MAX == 0xFFFF
    typedef int int_16_t;
    typedef unsigned int u_int_16_t;
#elif ULONG_MAX == 0xFFFF
    typedef long int_16_t;
    typedef unsigned long u_int_16_t;
#else
    #error No 16 bits integer type for this platform
#endif
#if USHRT_MAX == 0xFFFFFFFF
    typedef short int_32_t;
    typedef unsigned short u_int_32_t;
#elif UINT_MAX == 0xFFFFFFFF
    typedef int int_32_t;
    typedef unsigned int u_int_32_t;
#elif ULONG_MAX == 0xFFFFFFFF
    typedef long int_32_t;
    typedef unsigned long u_int_32_t;
#else
    #error No 32 bits integer type for this platform
#endif 


typedef enum bit_t
{
    ZERO,
    ONE,
    UNTOUCHED
} bit_t;


typedef u_int_8_t register_8_t;
typedef u_int_16_t register_16_t;


#endif