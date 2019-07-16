   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Parser V4.11.5 - 29 Dec 2015
   3                     ; Generator (Limited) V4.4.4 - 27 Jan 2016
   4                     ; Optimizer V4.4.4 - 27 Jan 2016
11378                     	bsct
11379  0000               _ADC_Reading:
11380  0000 0000          	dc.w	0
11381  0002               _lastADC_Reading:
11382  0002 0000          	dc.w	0
11383  0004               _ppm:
11384  0004 0000          	dc.w	0
11435                     ; 52 void main(void)
11435                     ; 53 {
11437                     	switch	.text
11438  0000               _main:
11442                     ; 54   CLK_CKDIVR = 0; // turn off clock prescaler (to have Fmaster 16 MHz)
11444  0000 725f50c6      	clr	_CLK_CKDIVR
11445                     ; 56   PA_DDR = 0b00111110;
11447  0004 353e5002      	mov	_PA_DDR,#62
11448                     ; 57   PB_DDR = 0b00110000;
11450  0008 35305007      	mov	_PB_DDR,#48
11451                     ; 58   PC_DDR = 0b11111000;
11453  000c 35f8500c      	mov	_PC_DDR,#248
11454                     ; 59   PD_DDR = 0b01110000;
11456  0010 35705011      	mov	_PD_DDR,#112
11457                     ; 61   PA_CR1 = 0b00111110;
11459  0014 353e5003      	mov	_PA_CR1,#62
11460                     ; 62   PB_CR1 = 0b00000000;
11462  0018 725f5008      	clr	_PB_CR1
11463                     ; 63   PC_CR1 = 0b10111000;
11465  001c 35b8500d      	mov	_PC_CR1,#184
11466                     ; 64   PD_CR1 = 0b01100000;
11468  0020 35605012      	mov	_PD_CR1,#96
11469                     ; 66   PA_ODR = 0;
11471  0024 725f5000      	clr	_PA_ODR
11472                     ; 67   PB_ODR = 0;
11474  0028 725f5005      	clr	_PB_ODR
11475                     ; 68   PC_ODR = 0;
11477  002c 725f500a      	clr	_PC_ODR
11478                     ; 69   PD_ODR = 0;
11480  0030 725f500f      	clr	_PD_ODR
11481                     ; 70   ADC_Config();
11483  0034 ad3b          	call	L33601_ADC_Config
11485                     ; 71   PWM_Config();
11487  0036 ad73          	call	L53601_PWM_Config
11489  0038               L55601:
11490                     ; 74 	if (ADC_Reading != lastADC_Reading) {
11492  0038 be00          	ldw	x,_ADC_Reading
11493  003a b302          	cpw	x,_lastADC_Reading
11494  003c 272e          	jreq	L16601
11495                     ; 75 		ppm = 988 + (1023 - ADC_Reading);
11497  003e ae07db        	ldw	x,#2011
11498  0041 72b00000      	subw	x,_ADC_Reading
11499  0045 bf04          	ldw	_ppm,x
11500                     ; 76 		if (ppm > 2000)
11502  0047 a307d1        	cpw	x,#2001
11503  004a 2505          	jrult	L36601
11504                     ; 77 			ppm = 2000;
11506  004c ae07d0        	ldw	x,#2000
11508  004f 2008          	jp	LC001
11509  0051               L36601:
11510                     ; 78 		else if (ppm < 1000)
11512  0051 a303e8        	cpw	x,#1000
11513  0054 2405          	jruge	L56601
11514                     ; 79 			ppm = 1000;
11516  0056 ae03e8        	ldw	x,#1000
11517  0059               LC001:
11518  0059 bf04          	ldw	_ppm,x
11519  005b               L56601:
11520                     ; 80 		displayNumber(ppm);
11522  005b cd0000        	call	_displayNumber
11524                     ; 81 		lastADC_Reading = ADC_Reading;
11526  005e be00          	ldw	x,_ADC_Reading
11527  0060 bf02          	ldw	_lastADC_Reading,x
11528                     ; 83 		TIM1_CCR3H = (ppm >> 8);
11530  0062 5500045269    	mov	_TIM1_CCR3H,_ppm
11531                     ; 84 		TIM1_CCR3L = (uint8_t)(ppm & 0xFF);
11533  0067 550005526a    	mov	_TIM1_CCR3L,_ppm+1
11534  006c               L16601:
11535                     ; 86 	refreshDisplay();
11537  006c cd0000        	call	_refreshDisplay
11540  006f 20c7          	jra	L55601
11569                     ; 96 static void ADC_Config()
11569                     ; 97 {
11570                     	switch	.text
11571  0071               L33601_ADC_Config:
11575                     ; 99   GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_FL_NO_IT);
11577  0071 4b00          	push	#0
11578  0073 4b08          	push	#8
11579  0075 ae500f        	ldw	x,#20495
11580  0078 cd0000        	call	_GPIO_Init
11582  007b 85            	popw	x
11583                     ; 100   GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_IN_FL_NO_IT);
11585  007c 4b00          	push	#0
11586  007e 4b04          	push	#4
11587  0080 ae500f        	ldw	x,#20495
11588  0083 cd0000        	call	_GPIO_Init
11590  0086 85            	popw	x
11591                     ; 103   ADC1_DeInit();
11593  0087 cd0000        	call	_ADC1_DeInit
11595                     ; 106   ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS, ADC1_CHANNEL_3, ADC1_PRESSEL_FCPU_D10, \
11595                     ; 107             ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, ADC1_SCHMITTTRIG_CHANNEL3,\
11595                     ; 108             DISABLE);
11597  008a 4b00          	push	#0
11598  008c 4b03          	push	#3
11599  008e 4b08          	push	#8
11600  0090 4b00          	push	#0
11601  0092 4b00          	push	#0
11602  0094 4b50          	push	#80
11603  0096 ae0103        	ldw	x,#259
11604  0099 cd0000        	call	_ADC1_Init
11606  009c 5b06          	addw	sp,#6
11607                     ; 111   ADC1_ITConfig(ADC1_IT_EOCIE, ENABLE);
11609  009e 4b01          	push	#1
11610  00a0 ae0020        	ldw	x,#32
11611  00a3 cd0000        	call	_ADC1_ITConfig
11613  00a6 9a            	rim	
11614  00a7 84            	pop	a
11615                     ; 114   enableInterrupts();
11619                     ; 117   ADC1_StartConversion();
11623                     ; 118 }
11626  00a8 cc0000        	jp	_ADC1_StartConversion
11657                     ; 120 static void PWM_Config(void)
11657                     ; 121 {
11658                     	switch	.text
11659  00ab               L53601_PWM_Config:
11663                     ; 125   TIM1_DeInit();
11665  00ab cd0000        	call	_TIM1_DeInit
11667                     ; 128   TIM1_TimeBaseInit(15, TIM1_COUNTERMODE_UP, 20000, 1);
11669  00ae 4b01          	push	#1
11670  00b0 ae4e20        	ldw	x,#20000
11671  00b3 89            	pushw	x
11672  00b4 4b00          	push	#0
11673  00b6 ae000f        	ldw	x,#15
11674  00b9 cd0000        	call	_TIM1_TimeBaseInit
11676  00bc 5b04          	addw	sp,#4
11677                     ; 131   TIM1_OC3Init(TIM1_OCMODE_PWM1, 
11677                     ; 132 					TIM1_OUTPUTSTATE_ENABLE,
11677                     ; 133 					TIM1_OUTPUTNSTATE_DISABLE,
11677                     ; 134 					ppm, 
11677                     ; 135 					TIM1_OCPOLARITY_HIGH,
11677                     ; 136 					TIM1_OCNPOLARITY_LOW,
11677                     ; 137 					TIM1_OCIDLESTATE_RESET,
11677                     ; 138 					TIM1_OCNIDLESTATE_RESET); 
11679  00be 4b00          	push	#0
11680  00c0 4b00          	push	#0
11681  00c2 4b88          	push	#136
11682  00c4 4b00          	push	#0
11683  00c6 be04          	ldw	x,_ppm
11684  00c8 89            	pushw	x
11685  00c9 4b00          	push	#0
11686  00cb ae6011        	ldw	x,#24593
11687  00ce cd0000        	call	_TIM1_OC3Init
11689  00d1 5b07          	addw	sp,#7
11690                     ; 139   TIM1_OC3PreloadConfig(ENABLE);
11692  00d3 a601          	ld	a,#1
11693  00d5 cd0000        	call	_TIM1_OC3PreloadConfig
11695                     ; 142   TIM1_ARRPreloadConfig(ENABLE);
11697  00d8 a601          	ld	a,#1
11698  00da cd0000        	call	_TIM1_ARRPreloadConfig
11700                     ; 145   TIM1_Cmd(ENABLE);
11702  00dd a601          	ld	a,#1
11703  00df cd0000        	call	_TIM1_Cmd
11705                     ; 147   TIM1_CtrlPWMOutputs(ENABLE);
11707  00e2 a601          	ld	a,#1
11709                     ; 148 }
11712  00e4 cc0000        	jp	_TIM1_CtrlPWMOutputs
11747                     ; 159 void assert_failed(uint8_t* file, uint32_t line)
11747                     ; 160 { 
11748                     	switch	.text
11749  00e7               _assert_failed:
11753  00e7               L72701:
11754  00e7 20fe          	jra	L72701
11796                     	xdef	_main
11797                     	xdef	_ppm
11798                     	xdef	_lastADC_Reading
11799                     	xdef	_ADC_Reading
11800                     	xref	_refreshDisplay
11801                     	xref	_displayNumber
11802                     	xdef	_assert_failed
11803                     	xref	_TIM1_OC3PreloadConfig
11804                     	xref	_TIM1_ARRPreloadConfig
11805                     	xref	_TIM1_CtrlPWMOutputs
11806                     	xref	_TIM1_Cmd
11807                     	xref	_TIM1_OC3Init
11808                     	xref	_TIM1_TimeBaseInit
11809                     	xref	_TIM1_DeInit
11810                     	xref	_GPIO_Init
11811                     	xref	_ADC1_StartConversion
11812                     	xref	_ADC1_ITConfig
11813                     	xref	_ADC1_Init
11814                     	xref	_ADC1_DeInit
11833                     	end
