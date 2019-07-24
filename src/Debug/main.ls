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
11385  0004 ffff          	dc.w	-1
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
11441                     ; 65 void adjustLimits(void)
11441                     ; 66 {
11443                     .text:	section	.text,new
11444  0000               _adjustLimits:
11448                     ; 68 	pwPressed = 0;
11450  0000 3f0b          	clr	_pwPressed
11451                     ; 69 	displayCharacters(Character_b, Character_o, Character_t, Character_blank);
11453  0002 4b14          	push	#20
11454  0004 4b11          	push	#17
11455  0006 ae100e        	ldw	x,#4110
11456  0009 cd0000        	call	_displayCharacters
11458  000c 85            	popw	x
11460  000d 2008          	jra	L75601
11461  000f               L55601:
11462                     ; 71 		refreshDisplay();
11464  000f cd0000        	call	_refreshDisplay
11466                     ; 72 		if (selectPressed)
11468  0012 b60a          	ld	a,_selectPressed
11469  0014 2701          	jreq	L75601
11470                     ; 73 			return;
11473  0016 81            	ret	
11474  0017               L75601:
11475                     ; 70 	while (!pwPressed && !selectPressed) {
11477  0017 b60b          	ld	a,_pwPressed
11478  0019 2604          	jrne	L56601
11480  001b b60a          	ld	a,_selectPressed
11481  001d 27f0          	jreq	L55601
11482  001f               L56601:
11483                     ; 75 	pwPressed = 0;
11485  001f 3f0b          	clr	_pwPressed
11486                     ; 78 	displayNumber(servoTypes[pulseMode].min);
11488  0021 cd0122        	call	LC002
11489  0024 ee00          	ldw	x,(_servoTypes,x)
11490  0026 cd0000        	call	_displayNumber
11493  0029 2022          	jra	L17601
11494  002b               L76601:
11495                     ; 80 		refreshDisplay();
11497  002b cd0000        	call	_refreshDisplay
11499                     ; 81 		if (selectPressed)
11501  002e 3d0a          	tnz	_selectPressed
11502  0030 2701          	jreq	L57601
11503                     ; 82 			return;
11506  0032 81            	ret	
11507  0033               L57601:
11508                     ; 84 		if (ADC_Reading != lastADC_Reading) 
11510  0033 be00          	ldw	x,_ADC_Reading
11511  0035 b304          	cpw	x,_lastADC_Reading
11512  0037 2712          	jreq	L77601
11513                     ; 85 			displayNumber(500 + ((((float)(1023 - ADC_Reading)) / 1023.0) * 1000));
11515  0039 ae03ff        	ldw	x,#1023
11516  003c 72b00000      	subw	x,_ADC_Reading
11517  0040 cd0129        	call	LC003
11519  0043 cd0132        	call	LC004
11521  0046 cd0000        	call	_displayNumber
11523  0049 be00          	ldw	x,_ADC_Reading
11524  004b               L77601:
11525                     ; 87 		lastADC_Reading = ADC_Reading;
11527  004b bf04          	ldw	_lastADC_Reading,x
11528  004d               L17601:
11529                     ; 79 	while (!pwPressed && !selectPressed) {
11531  004d b60b          	ld	a,_pwPressed
11532  004f 2604          	jrne	L13701
11534  0051 b60a          	ld	a,_selectPressed
11535  0053 27d6          	jreq	L76601
11536  0055               L13701:
11537                     ; 89 	pwPressed = 0;
11539  0055 3f0b          	clr	_pwPressed
11540                     ; 91 	servoTypes[pulseMode].min = (500 + ((((float)(1023 - lastADC_Reading)) / 1023.0) * 1000));
11542  0057 cd0122        	call	LC002
11543  005a 89            	pushw	x
11544  005b ae03ff        	ldw	x,#1023
11545  005e 72b00004      	subw	x,_lastADC_Reading
11546  0062 cd0129        	call	LC003
11548  0065 cd0132        	call	LC004
11550  0068 9085          	popw	y
11551  006a 90ef00        	ldw	(_servoTypes,y),x
11552                     ; 92 	EEWriteU16((pulseMode * 4), servoTypes[pulseMode].min);
11554  006d cd0122        	call	LC002
11555  0070 ee00          	ldw	x,(_servoTypes,x)
11556  0072 89            	pushw	x
11557  0073 cd0122        	call	LC002
11558  0076 cd0000        	call	_EEWriteU16
11560  0079 85            	popw	x
11561                     ; 95 	displayCharacters(Character_t, Character_o, Character_p, Character_blank);
11563  007a 4b14          	push	#20
11564  007c 4b12          	push	#18
11565  007e ae110e        	ldw	x,#4366
11566  0081 cd0000        	call	_displayCharacters
11568  0084 85            	popw	x
11570  0085 2008          	jra	L53701
11571  0087               L33701:
11572                     ; 97 		refreshDisplay();
11574  0087 cd0000        	call	_refreshDisplay
11576                     ; 98 		if (selectPressed)
11578  008a b60a          	ld	a,_selectPressed
11579  008c 2701          	jreq	L53701
11580                     ; 99 			return;
11583  008e 81            	ret	
11584  008f               L53701:
11585                     ; 96 	while (!pwPressed && !selectPressed) {
11587  008f b60b          	ld	a,_pwPressed
11588  0091 2604          	jrne	L34701
11590  0093 b60a          	ld	a,_selectPressed
11591  0095 27f0          	jreq	L33701
11592  0097               L34701:
11593                     ; 101 	pwPressed = 0;
11595  0097 3f0b          	clr	_pwPressed
11596                     ; 104 	displayNumber(servoTypes[pulseMode].max);
11598  0099 cd0122        	call	LC002
11599  009c ee02          	ldw	x,(_servoTypes+2,x)
11600  009e cd0000        	call	_displayNumber
11603  00a1 2021          	jra	L74701
11604  00a3               L54701:
11605                     ; 106 		refreshDisplay();
11607  00a3 cd0000        	call	_refreshDisplay
11609                     ; 107 		if (selectPressed)
11611  00a6 3d0a          	tnz	_selectPressed
11612  00a8 2701          	jreq	L35701
11613                     ; 108 			return;
11616  00aa 81            	ret	
11617  00ab               L35701:
11618                     ; 110 		if (ADC_Reading != lastADC_Reading)
11620  00ab be00          	ldw	x,_ADC_Reading
11621  00ad b304          	cpw	x,_lastADC_Reading
11622  00af 2711          	jreq	L55701
11623                     ; 111 			displayNumber(1500 + ((((float)(1023 - ADC_Reading)) / 1023.0) * 2000));
11625  00b1 ae03ff        	ldw	x,#1023
11626  00b4 72b00000      	subw	x,_ADC_Reading
11627  00b8 ad6f          	call	LC003
11629  00ba cd0141        	call	LC005
11631  00bd cd0000        	call	_displayNumber
11633  00c0 be00          	ldw	x,_ADC_Reading
11634  00c2               L55701:
11635                     ; 112 		lastADC_Reading = ADC_Reading;
11637  00c2 bf04          	ldw	_lastADC_Reading,x
11638  00c4               L74701:
11639                     ; 105 	while (!pwPressed && !selectPressed) {
11641  00c4 b60b          	ld	a,_pwPressed
11642  00c6 2604          	jrne	L77701
11644  00c8 b60a          	ld	a,_selectPressed
11645  00ca 27d7          	jreq	L54701
11646  00cc               L77701:
11647                     ; 115 	servoTypes[pulseMode].max = (1500 + ((((float)(1023 - lastADC_Reading)) / 1023.0) * 2000));
11649  00cc ad54          	call	LC002
11650  00ce 89            	pushw	x
11651  00cf ae03ff        	ldw	x,#1023
11652  00d2 72b00004      	subw	x,_lastADC_Reading
11653  00d6 ad51          	call	LC003
11655  00d8 ad67          	call	LC005
11657  00da 9085          	popw	y
11658  00dc 90ef02        	ldw	(_servoTypes+2,y),x
11659                     ; 116 	EEWriteU16((pulseMode * 4) + 2, servoTypes[pulseMode].max);
11661  00df ad41          	call	LC002
11662  00e1 ee02          	ldw	x,(_servoTypes+2,x)
11663  00e3 89            	pushw	x
11664  00e4 ad3c          	call	LC002
11665  00e6 1c0002        	addw	x,#2
11666  00e9 cd0000        	call	_EEWriteU16
11668  00ec 85            	popw	x
11669                     ; 118 	menuTimer = 2000;
11671  00ed ae07d0        	ldw	x,#2000
11672  00f0 bf0c          	ldw	_menuTimer,x
11673  00f2               L10011:
11674                     ; 120 		refreshDisplay();
11676  00f2 cd0000        	call	_refreshDisplay
11678                     ; 121 		if ((menuTimer % 200) == 0) {
11680  00f5 be0c          	ldw	x,_menuTimer
11681  00f7 a6c8          	ld	a,#200
11682  00f9 62            	div	x,a
11683  00fa 5f            	clrw	x
11684  00fb 97            	ld	xl,a
11685  00fc 5d            	tnzw	x
11686  00fd 2609          	jrne	L70011
11687                     ; 122 			displayCharacters(Character_blank, Character_blank, Character_blank, Character_blank);
11689  00ff 4b14          	push	#20
11690  0101 4b14          	push	#20
11691  0103 ae1414        	ldw	x,#5140
11694  0106 2011          	jp	LC001
11695  0108               L70011:
11696                     ; 123 		} else if ((menuTimer % 100) == 0) {
11698  0108 be0c          	ldw	x,_menuTimer
11699  010a a664          	ld	a,#100
11700  010c 62            	div	x,a
11701  010d 5f            	clrw	x
11702  010e 97            	ld	xl,a
11703  010f 5d            	tnzw	x
11704  0110 260b          	jrne	L11011
11705                     ; 124 			displayCharacters(Character_d, Character_o, Character_n, Character_E);
11707  0112 4b13          	push	#19
11708  0114 4b0d          	push	#13
11709  0116 ae0a0e        	ldw	x,#2574
11711  0119               LC001:
11712  0119 cd0000        	call	_displayCharacters
11713  011c 85            	popw	x
11714  011d               L11011:
11715                     ; 119 	while (menuTimer) {
11717  011d be0c          	ldw	x,_menuTimer
11718  011f 26d1          	jrne	L10011
11719                     ; 127 }
11722  0121 81            	ret	
11723  0122               LC002:
11724  0122 b609          	ld	a,_pulseMode
11725  0124 97            	ld	xl,a
11726  0125 a604          	ld	a,#4
11727  0127 42            	mul	x,a
11728  0128 81            	ret	
11729  0129               LC003:
11730  0129 cd0000        	call	c_uitof
11732  012c ae0010        	ldw	x,#L50701
11733  012f cc0000        	jp	c_fdiv
11734  0132               LC004:
11735  0132 ae000c        	ldw	x,#L51701
11736  0135 cd0000        	call	c_fmul
11738  0138 ae0008        	ldw	x,#L52701
11739  013b cd0000        	call	c_fadd
11741  013e cc0000        	jp	c_ftoi
11742  0141               LC005:
11743  0141 ae0004        	ldw	x,#L36701
11744  0144 cd0000        	call	c_fmul
11746  0147 ae0000        	ldw	x,#L37701
11747  014a cd0000        	call	c_fadd
11749  014d cc0000        	jp	c_ftoi
11803                     ; 134 void main(void)
11803                     ; 135 {
11804                     .text:	section	.text,new
11805  0000               _main:
11807  0000 5208          	subw	sp,#8
11808       00000008      OFST:	set	8
11811                     ; 136   CLK_CKDIVR = 0; // turn off clock prescaler (to have Fmaster 16 MHz)
11813  0002 725f50c6      	clr	_CLK_CKDIVR
11814                     ; 138   PA_DDR = 0b00111110;
11816  0006 353e5002      	mov	_PA_DDR,#62
11817                     ; 139   PB_DDR = 0b00110000;
11819  000a 35305007      	mov	_PB_DDR,#48
11820                     ; 140   PC_DDR = 0b11111000;
11822  000e 35f8500c      	mov	_PC_DDR,#248
11823                     ; 141   PD_DDR = 0b01110000;
11825  0012 35705011      	mov	_PD_DDR,#112
11826                     ; 143   PA_CR1 = 0b00111110;
11828  0016 353e5003      	mov	_PA_CR1,#62
11829                     ; 144   PB_CR1 = 0b00000000;
11831  001a 725f5008      	clr	_PB_CR1
11832                     ; 145   PC_CR1 = 0b10111000;
11834  001e 35b8500d      	mov	_PC_CR1,#184
11835                     ; 146   PD_CR1 = 0b01100000;
11837  0022 35605012      	mov	_PD_CR1,#96
11838                     ; 148   PA_ODR = 0;
11840  0026 725f5000      	clr	_PA_ODR
11841                     ; 149   PB_ODR = 0;
11843  002a 725f5005      	clr	_PB_ODR
11844                     ; 150   PC_ODR = 0;
11846  002e 725f500a      	clr	_PC_ODR
11847                     ; 151   PD_ODR = 0;
11849  0032 725f500f      	clr	_PD_ODR
11850                     ; 152   ADC_Config();
11852  0036 cd0000        	call	L33601_ADC_Config
11854                     ; 153   PWM_Config();
11856  0039 cd0000        	call	L53601_PWM_Config
11858                     ; 155   servoTypes[PulseMode_Normal].min = EEReadU16WithDefValAndRange(EEAddr_Normal_Bot, 1000, 500, 1500);
11860  003c ae05dc        	ldw	x,#1500
11861  003f 89            	pushw	x
11862  0040 ae01f4        	ldw	x,#500
11863  0043 89            	pushw	x
11864  0044 58            	sllw	x
11865  0045 89            	pushw	x
11866  0046 5f            	clrw	x
11867  0047 cd0000        	call	_EEReadU16WithDefValAndRange
11869  004a 5b06          	addw	sp,#6
11870  004c bf00          	ldw	_servoTypes,x
11871                     ; 156   servoTypes[PulseMode_Normal].max = EEReadU16WithDefValAndRange(EEAddr_Normal_Top, 2000, 1500, 3500);
11873  004e ae0dac        	ldw	x,#3500
11874  0051 89            	pushw	x
11875  0052 ae05dc        	ldw	x,#1500
11876  0055 89            	pushw	x
11877  0056 ae07d0        	ldw	x,#2000
11878  0059 89            	pushw	x
11879  005a ae0002        	ldw	x,#2
11880  005d cd0000        	call	_EEReadU16WithDefValAndRange
11882  0060 5b06          	addw	sp,#6
11883  0062 bf02          	ldw	_servoTypes+2,x
11884                     ; 158   servoTypes[PulseMode_DJI].min = EEReadU16WithDefValAndRange(EEAddr_DJI_Bot, 1000, 500, 1500);
11886  0064 ae05dc        	ldw	x,#1500
11887  0067 89            	pushw	x
11888  0068 ae01f4        	ldw	x,#500
11889  006b 89            	pushw	x
11890  006c 58            	sllw	x
11891  006d 89            	pushw	x
11892  006e ae0004        	ldw	x,#4
11893  0071 cd0000        	call	_EEReadU16WithDefValAndRange
11895  0074 5b06          	addw	sp,#6
11896  0076 bf04          	ldw	_servoTypes+4,x
11897                     ; 159   servoTypes[PulseMode_DJI].max = EEReadU16WithDefValAndRange(EEAddr_DJI_Top, 2000, 1500, 3500);
11899  0078 ae0dac        	ldw	x,#3500
11900  007b 89            	pushw	x
11901  007c ae05dc        	ldw	x,#1500
11902  007f 89            	pushw	x
11903  0080 ae07d0        	ldw	x,#2000
11904  0083 89            	pushw	x
11905  0084 ae0006        	ldw	x,#6
11906  0087 cd0000        	call	_EEReadU16WithDefValAndRange
11908  008a 5b06          	addw	sp,#6
11909  008c bf06          	ldw	_servoTypes+6,x
11910  008e               L52011:
11911                     ; 162 	if (selectPressed) {
11913  008e b60a          	ld	a,_selectPressed
11914  0090 2738          	jreq	L13011
11915                     ; 163 		selectPressed = 0;
11917  0092 3f0a          	clr	_selectPressed
11918                     ; 164 		if (pulseMode == PulseMode_Normal) {
11920  0094 b609          	ld	a,_pulseMode
11921  0096 2614          	jrne	L33011
11922                     ; 165 			pulseMode = PulseMode_DJI;
11924  0098 35010009      	mov	_pulseMode,#1
11925                     ; 166 			displayCharacters(Character_d, Character_J, Character_i, Character_blank);
11927  009c 4b14          	push	#20
11928  009e 4b0c          	push	#12
11929  00a0 ae0a0b        	ldw	x,#2571
11930  00a3 cd0000        	call	_displayCharacters
11932  00a6 85            	popw	x
11933                     ; 167 			TIM1_SetAutoreload(US_TO_ARR(DJI_PERIOD_IN_US));
11935  00a7 ae09c4        	ldw	x,#2500
11938  00aa 2013          	jp	LC006
11939  00ac               L33011:
11940                     ; 168 		} else if (pulseMode == PulseMode_DJI) {
11942  00ac 4a            	dec	a
11943  00ad 2613          	jrne	L53011
11944                     ; 169 			pulseMode = PulseMode_Normal;
11946  00af b709          	ld	_pulseMode,a
11947                     ; 170 			displayCharacters(Character_n, Character_o, Character_r, Character_blank);
11949  00b1 4b14          	push	#20
11950  00b3 4b0f          	push	#15
11951  00b5 ae0d0e        	ldw	x,#3342
11952  00b8 cd0000        	call	_displayCharacters
11954  00bb 85            	popw	x
11955                     ; 171 			TIM1_SetAutoreload(US_TO_ARR(NORMAL_PERIOD_IN_US));
11957  00bc ae4e20        	ldw	x,#20000
11958  00bf               LC006:
11959  00bf cd0000        	call	_TIM1_SetAutoreload
11961  00c2               L53011:
11962                     ; 173 		menuTimer = 1000;
11964  00c2 ae03e8        	ldw	x,#1000
11965  00c5 bf0c          	ldw	_menuTimer,x
11967  00c7 cc014a        	jra	L14011
11968  00ca               L13011:
11969                     ; 174 	} else if (pwPressed) {
11971  00ca b60b          	ld	a,_pwPressed
11972  00cc 2709          	jreq	L34011
11973                     ; 175 		adjustLimits();
11975  00ce cd0000        	call	_adjustLimits
11977                     ; 176 		pwPressed = 0;
11979  00d1 3f0b          	clr	_pwPressed
11980                     ; 177 		selectPressed = 0;
11982  00d3 3f0a          	clr	_selectPressed
11984  00d5 2073          	jra	L14011
11985  00d7               L34011:
11986                     ; 179 		if (ADC_Reading != lastADC_Reading) {
11988  00d7 be00          	ldw	x,_ADC_Reading
11989  00d9 b304          	cpw	x,_lastADC_Reading
11990  00db 2764          	jreq	L74011
11991                     ; 180 			ppm = servoTypes[pulseMode].min + 
11991                     ; 181 					((((float)(1023 - ADC_Reading)) / 1023.0) * 
11991                     ; 182 					(servoTypes[pulseMode].max - servoTypes[pulseMode].min));
11993  00dd b609          	ld	a,_pulseMode
11994  00df 97            	ld	xl,a
11995  00e0 a604          	ld	a,#4
11996  00e2 42            	mul	x,a
11997  00e3 ee00          	ldw	x,(_servoTypes,x)
11998  00e5 cd0000        	call	c_uitof
12000  00e8 96            	ldw	x,sp
12001  00e9 1c0005        	addw	x,#OFST-3
12002  00ec cd0000        	call	c_rtol
12005  00ef b609          	ld	a,_pulseMode
12006  00f1 97            	ld	xl,a
12007  00f2 a604          	ld	a,#4
12008  00f4 42            	mul	x,a
12009  00f5 b609          	ld	a,_pulseMode
12010  00f7 ee02          	ldw	x,(_servoTypes+2,x)
12011  00f9 905f          	clrw	y
12012  00fb 9097          	ld	yl,a
12013  00fd 9058          	sllw	y
12014  00ff 9058          	sllw	y
12015  0101 01            	rrwa	x,a
12016  0102 90e001        	sub	a,(_servoTypes+1,y)
12017  0105 01            	rrwa	x,a
12018  0106 90e200        	sbc	a,(_servoTypes,y)
12019  0109 01            	rrwa	x,a
12020  010a cd0000        	call	c_uitof
12022  010d 96            	ldw	x,sp
12023  010e 5c            	incw	x
12024  010f cd0000        	call	c_rtol
12027  0112 ae03ff        	ldw	x,#1023
12028  0115 72b00000      	subw	x,_ADC_Reading
12029  0119 cd0000        	call	c_uitof
12031  011c ae0010        	ldw	x,#L50701
12032  011f cd0000        	call	c_fdiv
12034  0122 96            	ldw	x,sp
12035  0123 5c            	incw	x
12036  0124 cd0000        	call	c_fmul
12038  0127 96            	ldw	x,sp
12039  0128 1c0005        	addw	x,#OFST-3
12040  012b cd0000        	call	c_fadd
12042  012e cd0000        	call	c_ftoi
12044  0131 bf06          	ldw	_ppm,x
12045                     ; 184 			lastADC_Reading = ADC_Reading;
12047  0133 be00          	ldw	x,_ADC_Reading
12048  0135 bf04          	ldw	_lastADC_Reading,x
12049                     ; 185 			TIM1_CCR3H = (ppm >> 8);
12051  0137 5500065269    	mov	_TIM1_CCR3H,_ppm
12052                     ; 186 			TIM1_CCR3L = (uint8_t)(ppm & 0xFF);
12054  013c 550007526a    	mov	_TIM1_CCR3L,_ppm+1
12055  0141               L74011:
12056                     ; 189 		if (menuTimer == 0) {
12058  0141 be0c          	ldw	x,_menuTimer
12059  0143 2605          	jrne	L14011
12060                     ; 190 			displayNumber(ppm);
12062  0145 be06          	ldw	x,_ppm
12063  0147 cd0000        	call	_displayNumber
12065  014a               L14011:
12066                     ; 193 	refreshDisplay();
12068  014a cd0000        	call	_refreshDisplay
12071  014d cc008e        	jra	L52011
12100                     ; 203 static void ADC_Config()
12100                     ; 204 {
12101                     .text:	section	.text,new
12102  0000               L33601_ADC_Config:
12106                     ; 206   GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_FL_NO_IT);
12108  0000 4b00          	push	#0
12109  0002 4b08          	push	#8
12110  0004 ae500f        	ldw	x,#20495
12111  0007 cd0000        	call	_GPIO_Init
12113  000a 85            	popw	x
12114                     ; 207   GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_IN_FL_NO_IT);
12116  000b 4b00          	push	#0
12117  000d 4b04          	push	#4
12118  000f ae500f        	ldw	x,#20495
12119  0012 cd0000        	call	_GPIO_Init
12121  0015 85            	popw	x
12122                     ; 210   ADC1_DeInit();
12124  0016 cd0000        	call	_ADC1_DeInit
12126                     ; 213   ADC1_Init(ADC1_CONVERSIONMODE_SINGLE, ADC1_CHANNEL_3, ADC1_PRESSEL_FCPU_D10, 
12126                     ; 214             ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, 
12126                     ; 215 			ADC1_SCHMITTTRIG_CHANNEL3 |ADC1_SCHMITTTRIG_CHANNEL4,
12126                     ; 216             DISABLE);
12128  0019 4b00          	push	#0
12129  001b 4b07          	push	#7
12130  001d 4b08          	push	#8
12131  001f 4b00          	push	#0
12132  0021 4b00          	push	#0
12133  0023 4b50          	push	#80
12134  0025 ae0003        	ldw	x,#3
12135  0028 cd0000        	call	_ADC1_Init
12137  002b 5b06          	addw	sp,#6
12138                     ; 219   ADC1_ITConfig(ADC1_IT_EOCIE, ENABLE);
12140  002d 4b01          	push	#1
12141  002f ae0020        	ldw	x,#32
12142  0032 cd0000        	call	_ADC1_ITConfig
12144  0035 9a            	rim	
12145  0036 84            	pop	a
12146                     ; 222   enableInterrupts();
12150                     ; 225   ADC1_StartConversion();
12154                     ; 226 }
12157  0037 cc0000        	jp	_ADC1_StartConversion
12192                     ; 228 static void PWM_Config(void)
12192                     ; 229 {
12193                     .text:	section	.text,new
12194  0000               L53601_PWM_Config:
12198                     ; 233   TIM1_DeInit();
12200  0000 cd0000        	call	_TIM1_DeInit
12202                     ; 236   TIM1_TimeBaseInit(15, TIM1_COUNTERMODE_UP, US_TO_ARR(NORMAL_PERIOD_IN_US), 1);
12204  0003 4b01          	push	#1
12205  0005 ae4e20        	ldw	x,#20000
12206  0008 89            	pushw	x
12207  0009 4b00          	push	#0
12208  000b ae000f        	ldw	x,#15
12209  000e cd0000        	call	_TIM1_TimeBaseInit
12211  0011 5b04          	addw	sp,#4
12212                     ; 239   TIM1_OC3Init(TIM1_OCMODE_PWM1, 
12212                     ; 240 					TIM1_OUTPUTSTATE_ENABLE,
12212                     ; 241 					TIM1_OUTPUTNSTATE_DISABLE,
12212                     ; 242 					ppm, 
12212                     ; 243 					TIM1_OCPOLARITY_HIGH,
12212                     ; 244 					TIM1_OCNPOLARITY_LOW,
12212                     ; 245 					TIM1_OCIDLESTATE_RESET,
12212                     ; 246 					TIM1_OCNIDLESTATE_RESET); 
12214  0013 4b00          	push	#0
12215  0015 4b00          	push	#0
12216  0017 4b88          	push	#136
12217  0019 4b00          	push	#0
12218  001b be06          	ldw	x,_ppm
12219  001d 89            	pushw	x
12220  001e 4b00          	push	#0
12221  0020 ae6011        	ldw	x,#24593
12222  0023 cd0000        	call	_TIM1_OC3Init
12224  0026 5b07          	addw	sp,#7
12225                     ; 247   TIM1_OC3PreloadConfig(ENABLE);
12227  0028 a601          	ld	a,#1
12228  002a cd0000        	call	_TIM1_OC3PreloadConfig
12230                     ; 250   TIM1_ARRPreloadConfig(ENABLE);
12232  002d a601          	ld	a,#1
12233  002f cd0000        	call	_TIM1_ARRPreloadConfig
12235                     ; 253   TIM1_Cmd(ENABLE);
12237  0032 a601          	ld	a,#1
12238  0034 cd0000        	call	_TIM1_Cmd
12240                     ; 255   TIM1_CtrlPWMOutputs(ENABLE);
12242  0037 a601          	ld	a,#1
12243  0039 cd0000        	call	_TIM1_CtrlPWMOutputs
12245                     ; 259   TIM2_DeInit();
12247  003c cd0000        	call	_TIM2_DeInit
12249                     ; 261   TIM2_TimeBaseInit(4, 1000);
12251  003f ae03e8        	ldw	x,#1000
12252  0042 89            	pushw	x
12253  0043 a604          	ld	a,#4
12254  0045 cd0000        	call	_TIM2_TimeBaseInit
12256  0048 85            	popw	x
12257                     ; 262   TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE);
12259  0049 ae0101        	ldw	x,#257
12260  004c cd0000        	call	_TIM2_ITConfig
12262                     ; 264   TIM2_Cmd(ENABLE);
12264  004f a601          	ld	a,#1
12266                     ; 265 }
12269  0051 cc0000        	jp	_TIM2_Cmd
12304                     ; 276 void assert_failed(uint8_t* file, uint32_t line)
12304                     ; 277 { 
12305                     .text:	section	.text,new
12306  0000               _assert_failed:
12310  0000               L11111:
12311  0000 20fe          	jra	L11111
12500                     	xdef	_main
12501                     	xdef	_adjustLimits
12502                     	xdef	_pwReleased
12503                     	xdef	_selectReleased
12504                     	switch	.ubsct
12505  0000               _servoTypes:
12506  0000 000000000000  	ds.b	8
12507                     	xdef	_servoTypes
12508                     	xdef	_menuTimer
12509                     	xdef	_pwPressed
12510                     	xdef	_selectPressed
12511                     	xdef	_pulseMode
12512                     	xdef	_currentADCChannel
12513                     	xdef	_ppm
12514                     	xdef	_lastADC_Reading
12515                     	xdef	_Buttons_Reading
12516                     	xdef	_ADC_Reading
12517                     	xref	_ADC1_StartConversion
12518                     	xref	_ADC1_ITConfig
12519                     	xref	_ADC1_Init
12520                     	xref	_ADC1_DeInit
12521                     	xdef	_assert_failed
12522                     	xref	_TIM2_ITConfig
12523                     	xref	_TIM2_Cmd
12524                     	xref	_TIM2_TimeBaseInit
12525                     	xref	_TIM2_DeInit
12526                     	xref	_TIM1_SetAutoreload
12527                     	xref	_TIM1_OC3PreloadConfig
12528                     	xref	_TIM1_ARRPreloadConfig
12529                     	xref	_TIM1_CtrlPWMOutputs
12530                     	xref	_TIM1_Cmd
12531                     	xref	_TIM1_OC3Init
12532                     	xref	_TIM1_TimeBaseInit
12533                     	xref	_TIM1_DeInit
12534                     	xref	_GPIO_Init
12535                     	xref	_EEReadU16WithDefValAndRange
12536                     	xref	_EEWriteU16
12537                     	xref	_refreshDisplay
12538                     	xref	_displayCharacters
12539                     	xref	_displayNumber
12540                     .const:	section	.text
12541  0000               L37701:
12542  0000 44bb8000      	dc.w	17595,-32768
12543  0004               L36701:
12544  0004 44fa0000      	dc.w	17658,0
12545  0008               L52701:
12546  0008 43fa0000      	dc.w	17402,0
12547  000c               L51701:
12548  000c 447a0000      	dc.w	17530,0
12549  0010               L50701:
12550  0010 447fc000      	dc.w	17535,-16384
12551                     	xref.b	c_lreg
12552                     	xref.b	c_x
12572                     	xref	c_rtol
12573                     	xref	c_ftoi
12574                     	xref	c_fadd
12575                     	xref	c_fmul
12576                     	xref	c_fdiv
12577                     	xref	c_uitof
12578                     	end
