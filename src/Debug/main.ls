   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Parser V4.11.5 - 29 Dec 2015
   3                     ; Generator (Limited) V4.4.4 - 27 Jan 2016
   4                     ; Optimizer V4.4.4 - 27 Jan 2016
11379                     	bsct
11380  0000               _ADC_Reading:
11381  0000 0000          	dc.w	0
11382  0002               _Buttons_Reading:
11383  0002 0000          	dc.w	0
11384  0004               _lastADC_Reading:
11385  0004 0000          	dc.w	0
11386  0006               _ppm:
11387  0006 0000          	dc.w	0
11388  0008               _currentADCChannel:
11389  0008 03            	dc.b	3
11390  0009               _pulseMode:
11391  0009 00            	dc.b	0
11392  000a               _selectPressed:
11393  000a 00            	dc.b	0
11394  000b               _pwPressed:
11395  000b 00            	dc.b	0
11396  000c               _menuTimer:
11397  000c 0000          	dc.w	0
11398  000e               _selectReleased:
11399  000e 00            	dc.b	0
11400  000f               _pwReleased:
11401  000f 00            	dc.b	0
11457                     ; 65 void main(void)
11457                     ; 66 {
11459                     .text:	section	.text,new
11460  0000               _main:
11464                     ; 67   CLK_CKDIVR = 0; // turn off clock prescaler (to have Fmaster 16 MHz)
11466  0000 725f50c6      	clr	_CLK_CKDIVR
11467                     ; 69   PA_DDR = 0b00111110;
11469  0004 353e5002      	mov	_PA_DDR,#62
11470                     ; 70   PB_DDR = 0b00110000;
11472  0008 35305007      	mov	_PB_DDR,#48
11473                     ; 71   PC_DDR = 0b11111000;
11475  000c 35f8500c      	mov	_PC_DDR,#248
11476                     ; 72   PD_DDR = 0b01110000;
11478  0010 35705011      	mov	_PD_DDR,#112
11479                     ; 74   PA_CR1 = 0b00111110;
11481  0014 353e5003      	mov	_PA_CR1,#62
11482                     ; 75   PB_CR1 = 0b00000000;
11484  0018 725f5008      	clr	_PB_CR1
11485                     ; 76   PC_CR1 = 0b10111000;
11487  001c 35b8500d      	mov	_PC_CR1,#184
11488                     ; 77   PD_CR1 = 0b01100000;
11490  0020 35605012      	mov	_PD_CR1,#96
11491                     ; 79   PA_ODR = 0;
11493  0024 725f5000      	clr	_PA_ODR
11494                     ; 80   PB_ODR = 0;
11496  0028 725f5005      	clr	_PB_ODR
11497                     ; 81   PC_ODR = 0;
11499  002c 725f500a      	clr	_PC_ODR
11500                     ; 82   PD_ODR = 0;
11502  0030 725f500f      	clr	_PD_ODR
11503                     ; 83   ADC_Config();
11505  0034 cd0000        	call	L33601_ADC_Config
11507                     ; 84   PWM_Config();
11509  0037 cd0000        	call	L53601_PWM_Config
11511  003a               L55601:
11512                     ; 87 	if (selectPressed) {
11514  003a 3d0a          	tnz	_selectPressed
11515  003c 2737          	jreq	L16601
11516                     ; 88 		selectPressed = 0;
11518  003e 3f0a          	clr	_selectPressed
11519                     ; 89 		if (pulseMode == PulseMode_Normal) {
11521  0040 b609          	ld	a,_pulseMode
11522  0042 2614          	jrne	L36601
11523                     ; 90 			pulseMode = PulseMode_DJI;
11525  0044 35010009      	mov	_pulseMode,#1
11526                     ; 91 			displayCharacters(Character_d, Character_J, Character_i, Character_blank);
11528  0048 4b10          	push	#16
11529  004a 4b0c          	push	#12
11530  004c ae0a0b        	ldw	x,#2571
11531  004f cd0000        	call	_displayCharacters
11533  0052 85            	popw	x
11534                     ; 92 			TIM1_SetAutoreload(US_TO_ARR(DJI_PERIOD_IN_US));
11536  0053 ae1388        	ldw	x,#5000
11539  0056 2013          	jp	LC001
11540  0058               L36601:
11541                     ; 93 		} else if (pulseMode == PulseMode_DJI) {
11543  0058 4a            	dec	a
11544  0059 2613          	jrne	L56601
11545                     ; 94 			pulseMode = PulseMode_Normal;
11547  005b b709          	ld	_pulseMode,a
11548                     ; 95 			displayCharacters(Character_n, Character_o, Character_r, Character_blank);
11550  005d 4b10          	push	#16
11551  005f 4b0f          	push	#15
11552  0061 ae0d0e        	ldw	x,#3342
11553  0064 cd0000        	call	_displayCharacters
11555  0067 85            	popw	x
11556                     ; 96 			TIM1_SetAutoreload(US_TO_ARR(NORMAL_PERIOD_IN_US));
11558  0068 ae9c40        	ldw	x,#40000
11559  006b               LC001:
11560  006b cd0000        	call	_TIM1_SetAutoreload
11562  006e               L56601:
11563                     ; 98 		menuTimer = 1000;
11565  006e ae03e8        	ldw	x,#1000
11566  0071 bf0c          	ldw	_menuTimer,x
11568  0073 2048          	jra	L17601
11569  0075               L16601:
11570                     ; 100 		if (ADC_Reading != lastADC_Reading) {
11572  0075 be00          	ldw	x,_ADC_Reading
11573  0077 b304          	cpw	x,_lastADC_Reading
11574  0079 2738          	jreq	L37601
11575                     ; 101 			if (pulseMode == PulseMode_Normal) {
11577  007b 3d09          	tnz	_pulseMode
11578  007d 260d          	jrne	L57601
11579                     ; 102 				ppm = 1400 + ((((float)(1023 - ADC_Reading)) / 1023.0) * 3200);
11581  007f ad42          	call	LC003
11583  0081 ae0008        	ldw	x,#L31701
11584  0084 cd0000        	call	c_fmul
11586  0087 ae0004        	ldw	x,#L32701
11590  008a 2011          	jp	LC002
11591  008c               L57601:
11592                     ; 103 			} else if (pulseMode == PulseMode_DJI) {
11594  008c b609          	ld	a,_pulseMode
11595  008e a101          	cp	a,#1
11596  0090 2615          	jrne	L72701
11597                     ; 104 				ppm = 2000 + ((((float)(1023 - ADC_Reading)) / 1023.0) * 2000);
11599  0092 ad2f          	call	LC003
11601  0094 ae0000        	ldw	x,#L73701
11602  0097 cd0000        	call	c_fmul
11604  009a ae0000        	ldw	x,#L73701
11607  009d               LC002:
11608  009d cd0000        	call	c_fadd
11609  00a0 cd0000        	call	c_ftoi
11610  00a3 bf06          	ldw	_ppm,x
11611  00a5 be00          	ldw	x,_ADC_Reading
11612  00a7               L72701:
11613                     ; 108 			lastADC_Reading = ADC_Reading;
11615  00a7 bf04          	ldw	_lastADC_Reading,x
11616                     ; 109 			TIM1_CCR3H = (ppm >> 8);
11618  00a9 5500065269    	mov	_TIM1_CCR3H,_ppm
11619                     ; 110 			TIM1_CCR3L = (uint8_t)(ppm & 0xFF);
11621  00ae 550007526a    	mov	_TIM1_CCR3L,_ppm+1
11622  00b3               L37601:
11623                     ; 113 		if (menuTimer == 0) {
11625  00b3 be0c          	ldw	x,_menuTimer
11626  00b5 2606          	jrne	L17601
11627                     ; 114 			displayNumber(ppm / 2);
11629  00b7 be06          	ldw	x,_ppm
11630  00b9 54            	srlw	x
11631  00ba cd0000        	call	_displayNumber
11633  00bd               L17601:
11634                     ; 117 	refreshDisplay();
11636  00bd cd0000        	call	_refreshDisplay
11639  00c0 cc003a        	jra	L55601
11640  00c3               LC003:
11641  00c3 ae03ff        	ldw	x,#1023
11642  00c6 72b00000      	subw	x,_ADC_Reading
11643  00ca cd0000        	call	c_uitof
11645  00cd ae000c        	ldw	x,#L30701
11646  00d0 cc0000        	jp	c_fdiv
11675                     ; 127 static void ADC_Config()
11675                     ; 128 {
11676                     .text:	section	.text,new
11677  0000               L33601_ADC_Config:
11681                     ; 130   GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_FL_NO_IT);
11683  0000 4b00          	push	#0
11684  0002 4b08          	push	#8
11685  0004 ae500f        	ldw	x,#20495
11686  0007 cd0000        	call	_GPIO_Init
11688  000a 85            	popw	x
11689                     ; 131   GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_IN_FL_NO_IT);
11691  000b 4b00          	push	#0
11692  000d 4b04          	push	#4
11693  000f ae500f        	ldw	x,#20495
11694  0012 cd0000        	call	_GPIO_Init
11696  0015 85            	popw	x
11697                     ; 134   ADC1_DeInit();
11699  0016 cd0000        	call	_ADC1_DeInit
11701                     ; 137   ADC1_Init(ADC1_CONVERSIONMODE_SINGLE, ADC1_CHANNEL_3, ADC1_PRESSEL_FCPU_D10, 
11701                     ; 138             ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, 
11701                     ; 139 			ADC1_SCHMITTTRIG_CHANNEL3 |ADC1_SCHMITTTRIG_CHANNEL4,
11701                     ; 140             DISABLE);
11703  0019 4b00          	push	#0
11704  001b 4b07          	push	#7
11705  001d 4b08          	push	#8
11706  001f 4b00          	push	#0
11707  0021 4b00          	push	#0
11708  0023 4b50          	push	#80
11709  0025 ae0003        	ldw	x,#3
11710  0028 cd0000        	call	_ADC1_Init
11712  002b 5b06          	addw	sp,#6
11713                     ; 143   ADC1_ITConfig(ADC1_IT_EOCIE, ENABLE);
11715  002d 4b01          	push	#1
11716  002f ae0020        	ldw	x,#32
11717  0032 cd0000        	call	_ADC1_ITConfig
11719  0035 9a            	rim	
11720  0036 84            	pop	a
11721                     ; 146   enableInterrupts();
11725                     ; 149   ADC1_StartConversion();
11729                     ; 150 }
11732  0037 cc0000        	jp	_ADC1_StartConversion
11767                     ; 152 static void PWM_Config(void)
11767                     ; 153 {
11768                     .text:	section	.text,new
11769  0000               L53601_PWM_Config:
11773                     ; 157   TIM1_DeInit();
11775  0000 cd0000        	call	_TIM1_DeInit
11777                     ; 160   TIM1_TimeBaseInit(7, TIM1_COUNTERMODE_UP, US_TO_ARR(NORMAL_PERIOD_IN_US), 1);
11779  0003 4b01          	push	#1
11780  0005 ae9c40        	ldw	x,#40000
11781  0008 89            	pushw	x
11782  0009 4b00          	push	#0
11783  000b ae0007        	ldw	x,#7
11784  000e cd0000        	call	_TIM1_TimeBaseInit
11786  0011 5b04          	addw	sp,#4
11787                     ; 163   TIM1_OC3Init(TIM1_OCMODE_PWM1, 
11787                     ; 164 					TIM1_OUTPUTSTATE_ENABLE,
11787                     ; 165 					TIM1_OUTPUTNSTATE_DISABLE,
11787                     ; 166 					ppm, 
11787                     ; 167 					TIM1_OCPOLARITY_HIGH,
11787                     ; 168 					TIM1_OCNPOLARITY_LOW,
11787                     ; 169 					TIM1_OCIDLESTATE_RESET,
11787                     ; 170 					TIM1_OCNIDLESTATE_RESET); 
11789  0013 4b00          	push	#0
11790  0015 4b00          	push	#0
11791  0017 4b88          	push	#136
11792  0019 4b00          	push	#0
11793  001b be06          	ldw	x,_ppm
11794  001d 89            	pushw	x
11795  001e 4b00          	push	#0
11796  0020 ae6011        	ldw	x,#24593
11797  0023 cd0000        	call	_TIM1_OC3Init
11799  0026 5b07          	addw	sp,#7
11800                     ; 171   TIM1_OC3PreloadConfig(ENABLE);
11802  0028 a601          	ld	a,#1
11803  002a cd0000        	call	_TIM1_OC3PreloadConfig
11805                     ; 174   TIM1_ARRPreloadConfig(ENABLE);
11807  002d a601          	ld	a,#1
11808  002f cd0000        	call	_TIM1_ARRPreloadConfig
11810                     ; 177   TIM1_Cmd(ENABLE);
11812  0032 a601          	ld	a,#1
11813  0034 cd0000        	call	_TIM1_Cmd
11815                     ; 179   TIM1_CtrlPWMOutputs(ENABLE);
11817  0037 a601          	ld	a,#1
11818  0039 cd0000        	call	_TIM1_CtrlPWMOutputs
11820                     ; 183   TIM2_DeInit();
11822  003c cd0000        	call	_TIM2_DeInit
11824                     ; 185   TIM2_TimeBaseInit(4, 1000);
11826  003f ae03e8        	ldw	x,#1000
11827  0042 89            	pushw	x
11828  0043 a604          	ld	a,#4
11829  0045 cd0000        	call	_TIM2_TimeBaseInit
11831  0048 85            	popw	x
11832                     ; 186   TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE);
11834  0049 ae0101        	ldw	x,#257
11835  004c cd0000        	call	_TIM2_ITConfig
11837                     ; 188   TIM2_Cmd(ENABLE);
11839  004f a601          	ld	a,#1
11841                     ; 189 }
11844  0051 cc0000        	jp	_TIM2_Cmd
11879                     ; 200 void assert_failed(uint8_t* file, uint32_t line)
11879                     ; 201 { 
11880                     .text:	section	.text,new
11881  0000               _assert_failed:
11885  0000               L30011:
11886  0000 20fe          	jra	L30011
12042                     	xdef	_main
12043                     	xdef	_pwReleased
12044                     	xdef	_selectReleased
12045                     	xdef	_menuTimer
12046                     	xdef	_pwPressed
12047                     	xdef	_selectPressed
12048                     	xdef	_pulseMode
12049                     	xdef	_currentADCChannel
12050                     	xdef	_ppm
12051                     	xdef	_lastADC_Reading
12052                     	xdef	_Buttons_Reading
12053                     	xdef	_ADC_Reading
12054                     	xref	_ADC1_StartConversion
12055                     	xref	_ADC1_ITConfig
12056                     	xref	_ADC1_Init
12057                     	xref	_ADC1_DeInit
12058                     	xdef	_assert_failed
12059                     	xref	_TIM2_ITConfig
12060                     	xref	_TIM2_Cmd
12061                     	xref	_TIM2_TimeBaseInit
12062                     	xref	_TIM2_DeInit
12063                     	xref	_TIM1_SetAutoreload
12064                     	xref	_TIM1_OC3PreloadConfig
12065                     	xref	_TIM1_ARRPreloadConfig
12066                     	xref	_TIM1_CtrlPWMOutputs
12067                     	xref	_TIM1_Cmd
12068                     	xref	_TIM1_OC3Init
12069                     	xref	_TIM1_TimeBaseInit
12070                     	xref	_TIM1_DeInit
12071                     	xref	_GPIO_Init
12072                     	xref	_refreshDisplay
12073                     	xref	_displayCharacters
12074                     	xref	_displayNumber
12075                     .const:	section	.text
12076  0000               L73701:
12077  0000 44fa0000      	dc.w	17658,0
12078  0004               L32701:
12079  0004 44af0000      	dc.w	17583,0
12080  0008               L31701:
12081  0008 45480000      	dc.w	17736,0
12082  000c               L30701:
12083  000c 447fc000      	dc.w	17535,-16384
12084                     	xref.b	c_x
12104                     	xref	c_ftoi
12105                     	xref	c_fadd
12106                     	xref	c_fmul
12107                     	xref	c_fdiv
12108                     	xref	c_uitof
12109                     	end
