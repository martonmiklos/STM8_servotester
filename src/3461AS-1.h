#ifndef DISPLAY_3461AS_1
#define DISPLAY_3461AS_1

#include "stdint.h"


#define DIG1 PC_ODR_bits.ODR6
#define DIG2 PB_ODR_bits.ODR5
#define DIG3 PB_ODR_bits.ODR4
#define DIG4 PD_ODR_bits.ODR4

void displayNumber(uint16_t number);
void refreshDisplay(void);

typedef enum DisplayColumn {
	Digit_1,
	Digit_2,
	Digit_3,
	Digit_4
}  DisplayColumn_t;

typedef enum DisplaySegment {
	Segment_D = 0b10,
	Segment_E = 0b100,
	Segment_B = 0b1000,
	Segment_F = 0b10000,
	Segment_A = 0b100000,
	Segment_G = 0b1000000,
	Segment_C = 0b10000000
} DisplaySegment_t;

#endif