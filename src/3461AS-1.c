#include "3461AS-1.h"

#include "iostm8s003f3.h"

static uint16_t displayedNumber = 0;
static DisplayColumn_t currentDigit = Digit_1;

const unsigned char digitMap[10] = 
{	
	(Segment_A | 
	 Segment_B |
	 Segment_C |
	 Segment_D |
	 Segment_E |
	 Segment_F),// 0
	(Segment_B | 
	 Segment_C),// 1
	(Segment_A | 
	 Segment_B |
	 Segment_G |
	 Segment_E |
	 Segment_D),// 2
	(Segment_A | 
	 Segment_B |
	 Segment_G |
	 Segment_C |
	 Segment_D),// 3
	(Segment_F | 
	 Segment_G |
	 Segment_B |
	 Segment_C),// 4
	(Segment_A | 
	 Segment_F |
	 Segment_G |
	 Segment_C |
	 Segment_D),// 5
	(Segment_A | 
	 Segment_F |
	 Segment_G |
	 Segment_C |
	 Segment_D |
	 Segment_E),// 6
	(Segment_A | 
	 Segment_B |
	 Segment_C),// 7
	(Segment_A | 
	 Segment_F |
	 Segment_G |
	 Segment_B |
	 Segment_C |
	 Segment_D |
	 Segment_E),// 8
	(Segment_A | 
	 Segment_B |
	 Segment_C |
	 Segment_D |
	 Segment_F |
	 Segment_G)// 9
};

void writeDisplayPort(uint8_t digit)
{
	PA_ODR = ((PA_ODR & 0b11110001) |  (digit & 0b00001110));
	PC_ODR = ((PC_ODR & 0b11001111) |  (digit & 0b00110000));
	PD_ODR = ((PD_ODR & 0b10011111) | ((digit >> 1) & 0b01100000));
}

void displayNumber(uint16_t number)
{
	displayedNumber = number;
}

void refreshDisplay(void)
{
	uint8_t n;
	writeDisplayPort(0);
	switch (currentDigit) {
	case Digit_1:
		DIG4 = 1;
		DIG1 = 0;
		n = (displayedNumber / 1000);
	    writeDisplayPort(digitMap[n]);
		break;
	case Digit_2:
		DIG1 = 1;
		DIG2 = 0;
		n = ((displayedNumber / 100) % 10);
	    writeDisplayPort(digitMap[n]);
		break;
	case Digit_3:
		DIG2 = 1;
		DIG3 = 0;
		n = ((displayedNumber / 10) % 10);
	    writeDisplayPort(digitMap[n]);
		break;
	case Digit_4:
		DIG3 = 1;
		DIG4 = 0;
		n = (displayedNumber % 10);
	    writeDisplayPort(digitMap[n]);
		break;
	}
	currentDigit++;
	if (currentDigit > Digit_4)
		currentDigit = Digit_1;
}