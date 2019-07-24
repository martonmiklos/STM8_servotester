#ifndef MAIN_H
#define MAIN_H

#include "stm8s_adc1.h"

#define NORMAL_PERIOD_IN_US 20000
#define DJI_PERIOD_IN_US 2500

#define US_TO_ARR(us) (us)

typedef enum ADC_Channel {
	ADC_CH_Poti = ADC1_CHANNEL_3,
	ADC_CH_Buttons = ADC1_CHANNEL_4
} ADC_Channel_t;

typedef enum PulseMode {
	PulseMode_Normal,
	PulseMode_DJI
} PulseMode_t;

typedef struct ServoType {
	uint16_t min;
	uint16_t max;
} ServoType_t;

#define BTN_PULSE_W_THRESHOLD 480
#define BTN_SELECT_THRESHOLD 600
#define BTN_BOTH_THRESHOLD 700


#endif