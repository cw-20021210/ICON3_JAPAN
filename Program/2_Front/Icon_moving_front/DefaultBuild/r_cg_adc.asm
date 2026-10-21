; 78K0R C Compiler V2.72 Assembler Source        Date: 3 Mar 2022 Time:10:48:34

; Command   : -cf100le -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile r_cg_adc.c -oDefaultBuild -_msgoff -nq -i. -
;             iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no -g2
; In-file   : r_cg_adc.c
; Asm-file  : DefaultBuild\r_cg_adc.asm
; Para-file : 

$PROCESSOR(F100LE)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		039H,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, r_cg_adc.c
$DGS	MOD_NAM, r_cg_adc,	00H,	0FFFEH,	00H,	077H,	00H,	00H
$DGS	SEC_NAM, @@BITS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@CNST,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@R_INIT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@INIT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@DATA,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@R_INIS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@INIS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@DATS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@CNSTL,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@RLINIT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@INITL,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@DATAL,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@CALT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@CODE,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@CODEL,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@BASE,	U,	U,	00H,	078H,	00H,	00H
$DGS	GLV_SYM, _R_ADC_Create,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	019H,	01H,	00H
$DGS	BEG_FUN, ??bf_R_ADC_Create,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 039H,		00H,	019H
$DGS	END_FUN, ??ef_R_ADC_Create,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0FH
$DGS	GLV_SYM, _R_ADC_Start,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	01FH,	01H,	00H
$DGS	BEG_FUN, ??bf_R_ADC_Start,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 050H,		00H,	01FH
$DGS	END_FUN, ??ef_R_ADC_Start,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	GLV_SYM, _R_ADC_Stop,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	025H,	01H,	00H
$DGS	BEG_FUN, ??bf_R_ADC_Stop,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 05BH,		00H,	025H
$DGS	END_FUN, ??ef_R_ADC_Stop,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	GLV_SYM, _R_ADC_Set_OperationOn,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	02BH,	01H,	00H
$DGS	BEG_FUN, ??bf_R_ADC_Set_OperationOn,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 066H,		00H,	02BH
$DGS	END_FUN, ??ef_R_ADC_Set_OperationOn,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	GLV_SYM, _R_ADC_Set_OperationOff,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	031H,	01H,	00H
$DGS	BEG_FUN, ??bf_R_ADC_Set_OperationOff,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 071H,		00H,	031H
$DGS	END_FUN, ??ef_R_ADC_Set_OperationOff,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	GLV_SYM, _R_ADC_Get_Result,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	039H,	01H,	00H
$DGS	BEG_FUN, ??bf_R_ADC_Get_Result,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 07DH,		02H,	039H
$DGS	FUN_ARG, _buffer,	00H,	0FFFFH,	0500DH,	09H,	01H,	01H
$DGS	AUX_STR, 00H,		00H,	02H,	00H,	00H,	00H,	00H,	01H
$DGS	END_FUN, ??ef_R_ADC_Get_Result,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H

	PUBLIC	_R_ADC_Create
	PUBLIC	_R_ADC_Start
	PUBLIC	_R_ADC_Stop
	PUBLIC	_R_ADC_Set_OperationOn
	PUBLIC	_R_ADC_Set_OperationOff
	PUBLIC	_R_ADC_Get_Result

@@BITS	BSEG

@@CNST	CSEG	MIRRORP

@@R_INIT	CSEG	UNIT64KP

@@INIT	DSEG	BASEP

@@DATA	DSEG	BASEP

@@R_INIS	CSEG	UNIT64KP

@@INIS	DSEG	SADDRP

@@DATS	DSEG	SADDRP

@@CNSTL	CSEG	PAGE64KP

@@RLINIT	CSEG	UNIT64KP

@@INITL	DSEG	UNIT64KP

@@DATAL	DSEG	UNIT64KP

@@CALT	CSEG	CALLT0

; line    72
; line    73
; line    74
; line    75
; line    76
; line    77
; line    78
; line   169
; line   175
; line    57

@@CODEL	CSEG
_R_ADC_Create:
$DGL	1,19
??bf_R_ADC_Create:
; line    58
$DGL	0,2
	set1	!PER0.5						;[INF] 4, 2
; line    59
$DGL	0,3
	clrb	!ADM0						;[INF] 3, 1
; line    60
$DGL	0,4
	set1	MK1H.0						;[INF] 3, 2
; line    61
$DGL	0,5
	clr1	IF1H.0						;[INF] 3, 2
; line    64
$DGL	0,8
	mov	a,PM2						;[INF] 2, 1
	or	a,#01H	; 1 					;[INF] 2, 1
	mov	PM2,a						;[INF] 2, 1
; line    65
$DGL	0,9
	clrb	!ADM0						;[INF] 3, 1
; line    66
$DGL	0,10
	mov	ADM1,#020H	; 32 				;[INF] 3, 1
; line    67
$DGL	0,11
	clrb	!ADM2						;[INF] 3, 1
; line    68
$DGL	0,12
	mov	!ADUL,#0FFH	; 255 				;[INF] 4, 1
; line    69
$DGL	0,13
	clrb	!ADLL						;[INF] 3, 1
; line    70
$DGL	0,14
	clrb	!ADS						;[INF] 3, 1
; line    71
$DGL	0,15
??ef_R_ADC_Create:
	ret							;[INF] 1, 6
??ee_R_ADC_Create:
; line    80
_R_ADC_Start:
$DGL	1,25
??bf_R_ADC_Start:
; line    81
$DGL	0,2
	set1	ADM0.7						;[INF] 3, 2
; line    82
$DGL	0,3
??ef_R_ADC_Start:
	ret							;[INF] 1, 6
??ee_R_ADC_Start:
; line    91
_R_ADC_Stop:
$DGL	1,31
??bf_R_ADC_Stop:
; line    92
$DGL	0,2
	clr1	ADM0.7						;[INF] 3, 2
; line    93
$DGL	0,3
??ef_R_ADC_Stop:
	ret							;[INF] 1, 6
??ee_R_ADC_Stop:
; line   102
_R_ADC_Set_OperationOn:
$DGL	1,37
??bf_R_ADC_Set_OperationOn:
; line   103
$DGL	0,2
	set1	ADM0.0						;[INF] 3, 2
; line   104
$DGL	0,3
??ef_R_ADC_Set_OperationOn:
	ret							;[INF] 1, 6
??ee_R_ADC_Set_OperationOn:
; line   113
_R_ADC_Set_OperationOff:
$DGL	1,43
??bf_R_ADC_Set_OperationOff:
; line   114
$DGL	0,2
	clr1	ADM0.0						;[INF] 3, 2
; line   115
$DGL	0,3
??ef_R_ADC_Set_OperationOff:
	ret							;[INF] 1, 6
??ee_R_ADC_Set_OperationOff:
; line   125
_R_ADC_Get_Result:
$DGL	1,49
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_R_ADC_Get_Result:
; line   126
$DGL	0,2
	movw	ax,ADCR						;[INF] 2, 1
	shrw	ax,6						;[INF] 2, 1
	movw	bc,ax						;[INF] 1, 1
	movw	ax,[hl]	; buffer 				;[INF] 1, 1
	movw	de,ax						;[INF] 1, 1
	movw	ax,bc						;[INF] 1, 1
	movw	[de],ax						;[INF] 1, 1
; line   127
$DGL	0,3
??ef_R_ADC_Get_Result:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_R_ADC_Get_Result:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE
	END


; *** Code Information ***
;
; $FILE D:\1_Project\ICON 2022\Project_Front_NEW\r_cg_adc.c
;
; $FUNC R_ADC_Create(57)
;	void=(void)
;	CODE SIZE= 39 bytes, CLOCK_SIZE= 22 clocks, STACK_SIZE= 0 bytes
;
; $FUNC R_ADC_Start(80)
;	void=(void)
;	CODE SIZE= 4 bytes, CLOCK_SIZE= 8 clocks, STACK_SIZE= 0 bytes
;
; $FUNC R_ADC_Stop(91)
;	void=(void)
;	CODE SIZE= 4 bytes, CLOCK_SIZE= 8 clocks, STACK_SIZE= 0 bytes
;
; $FUNC R_ADC_Set_OperationOn(102)
;	void=(void)
;	CODE SIZE= 4 bytes, CLOCK_SIZE= 8 clocks, STACK_SIZE= 0 bytes
;
; $FUNC R_ADC_Set_OperationOff(113)
;	void=(void)
;	CODE SIZE= 4 bytes, CLOCK_SIZE= 8 clocks, STACK_SIZE= 0 bytes
;
; $FUNC R_ADC_Get_Result(125)
;	void=(pointer buffer:ax)
;	CODE SIZE= 17 bytes, CLOCK_SIZE= 18 clocks, STACK_SIZE= 4 bytes

; Target chip : R5F100LE
; Device file : V1.14 
