/**
  ******************************************************************************
  * @file    ADC2_ContinuousConversion\main.c
  * @author  MCD Application Team
  * @version V2.0.4
  * @date    26-April-2018
  * @brief   This file contains the main function for the ADC2 Continuous Conversion example.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "iostm8s003f3.h"
#include "3461as-1.h"
/**
  * @addtogroup ADC2_ContinuousConversion
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
uint16_t ADC_Reading = 0;
uint16_t lastADC_Reading = 0;
uint16_t ppm = 0;
/* Private function prototypes -----------------------------------------------*/
static void ADC_Config(void);
static void PWM_Config(void);
/* Private functions ---------------------------------------------------------*/

/**
  * @brief ADC2_ContinuousConversion  main entry point.
  * @param  None
  * @retval None
  */
void main(void)
{
  CLK_CKDIVR = 0; // turn off clock prescaler (to have Fmaster 16 MHz)
  
  PA_DDR = 0b00111110;
  PB_DDR = 0b00110000;
  PC_DDR = 0b11111000;
  PD_DDR = 0b01110000;
  
  PA_CR1 = 0b00111110;
  PB_CR1 = 0b00000000;
  PC_CR1 = 0b10111000;
  PD_CR1 = 0b01100000;
  
  PA_ODR = 0;
  PB_ODR = 0;
  PC_ODR = 0;
  PD_ODR = 0;
  ADC_Config();
  PWM_Config();
     
  while (1) {
	if (ADC_Reading != lastADC_Reading) {
		ppm = 988 + (1023 - ADC_Reading);
		if (ppm > 2000)
			ppm = 2000;
		else if (ppm < 1000)
			ppm = 1000;
		displayNumber(ppm);
		lastADC_Reading = ADC_Reading;

		TIM1_CCR3H = (ppm >> 8);
		TIM1_CCR3L = (uint8_t)(ppm & 0xFF);
	}
	refreshDisplay();
  }
}

/**
  * @brief  Configure ADC2 Continuous Conversion with End Of Conversion interrupt 
  *         enabled .
  * @param  None
  * @retval None
  */
static void ADC_Config()
{
  /*  Init GPIO for ADC2 */
  GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_IN_FL_NO_IT);
  
  /* De-Init ADC peripheral*/
  ADC1_DeInit();

  /* Init ADC2 peripheral */
  ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS, ADC1_CHANNEL_3, ADC1_PRESSEL_FCPU_D10, \
            ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, ADC1_SCHMITTTRIG_CHANNEL3,\
            DISABLE);

  /* Enable EOC interrupt */
  ADC1_ITConfig(ADC1_IT_EOCIE, ENABLE);

  /* Enable general interrupts */  
  enableInterrupts();
  
  /*Start Conversion */
  ADC1_StartConversion();
}

static void PWM_Config(void)
{
  //clock at 16MHz

  /* TIM2 Peripheral Configuration */ 
  TIM1_DeInit();

  /* Set TIM2 Frequency to 2Mhz */ 
  TIM1_TimeBaseInit(15, TIM1_COUNTERMODE_UP, 20000, 1);

  /* Channel 1 PWM configuration */ 
  TIM1_OC3Init(TIM1_OCMODE_PWM1, 
					TIM1_OUTPUTSTATE_ENABLE,
					TIM1_OUTPUTNSTATE_DISABLE,
					ppm, 
					TIM1_OCPOLARITY_HIGH,
					TIM1_OCNPOLARITY_LOW,
					TIM1_OCIDLESTATE_RESET,
					TIM1_OCNIDLESTATE_RESET); 
  TIM1_OC3PreloadConfig(ENABLE);
  
  /* Enables TIM1 peripheral Preload register on ARR */
  TIM1_ARRPreloadConfig(ENABLE);
	
  /* Enable TIM1 */
  TIM1_Cmd(ENABLE);
  
  TIM1_CtrlPWMOutputs(ENABLE);
}
 
#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
