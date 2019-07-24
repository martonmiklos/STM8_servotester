#ifndef DISPLAY_3461AS_1
#define DISPLAY_3461AS_1

#include "stdint.h"


#define DIG1 PC_ODR_bits.ODR6
#define DIG2 PB_ODR_bits.ODR5
#define DIG3 PB_ODR_bits.ODR4
#define DIG4 PD_ODR_bits.ODR4

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

typedef enum Characters {
	Character_0 = 0,
	Character_1,
	Character_2,
	Character_3,
	Character_4,
	Character_5,
	Character_6,
	Character_7,
	Character_8,
	Character_9,
	Character_d,
	Character_J,
	Character_i,
	Character_n,
	Character_o,
	Character_r,
	Character_b,
	Character_t,
	Character_p,
	Character_E,
	Character_blank
} Characters_t;


void displayNumber(uint16_t number);
void displayCharacters(Characters_t digit1, Characters_t digit2, Characters_t digit3, Characters_t digit4);
void refreshDisplay(void);
#endif