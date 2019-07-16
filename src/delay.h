/* 
 * delay utilite for STM8 family
 * COSMIC and SDCC
 * Terentiev Oleg
 * t.oleg@ymail.com
 */

#ifndef _UTIL_DELAY_H_
#define _UTIL_DELAY_H_

#include "stdint.h"

#ifndef F_CPU
#error F_CPU is not defined!
#endif

#define T_COUNT(x) ((( F_CPU * x / 1000000UL )-3)/3)

void __delay_cycl(const uint16_t ticks);
void __delay_us(const uint16_t us);

#endif // _UTIL_DELAY_H_

