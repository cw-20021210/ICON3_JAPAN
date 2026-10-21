; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:55

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile r_cg_timer.c -oDefaultBuild -_msgoff -nq -i.
;              -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no -g2
; In-file   : r_cg_timer.c
; Asm-file  : DefaultBuild\r_cg_timer.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		025H,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, r_cg_timer.c
$DGS	MOD_NAM, r_cg_timer,	00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	GLV_SYM, _R_TAU0_Create,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	019H,	01H,	00H
$DGS	BEG_FUN, ??bf_R_TAU0_Create,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 039H,		00H,	019H
$DGS	END_FUN, ??ef_R_TAU0_Create,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 030H
$DGS	GLV_SYM, _R_TAU0_Channel0_Start,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	01FH,	01H,	00H
$DGS	BEG_FUN, ??bf_R_TAU0_Channel0_Start,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 071H,		00H,	01FH
$DGS	END_FUN, ??ef_R_TAU0_Channel0_Start,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	GLV_SYM, _R_TAU0_Channel0_Stop,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	025H,	01H,	00H
$DGS	BEG_FUN, ??bf_R_TAU0_Channel0_Stop,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 07EH,		00H,	025H
$DGS	END_FUN, ??ef_R_TAU0_Channel0_Stop,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 06H

	PUBLIC	_R_TAU0_Create
	PUBLIC	_R_TAU0_Channel0_Start
	PUBLIC	_R_TAU0_Channel0_Stop

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
; line    57

@@CODEL	CSEG
_R_TAU0_Create:
$DGL	1,19
??bf_R_TAU0_Create:
; line    58
$DGL	0,2
	set1	!PER0.0						;[INF] 4, 2
; line    59
$DGL	0,3
	clrw	ax						;[INF] 1, 1
	movw	!TPS0,ax					;[INF] 3, 1
; line    64
$DGL	0,8
	movw	ax,#0AFFH	; 2815 				;[INF] 3, 1
	movw	!TT0,ax						;[INF] 3, 1
; line    66
$DGL	0,10
	set1	MK1L.4						;[INF] 3, 2
; line    67
$DGL	0,11
	clr1	IF1L.4						;[INF] 3, 2
; line    69
$DGL	0,13
	set1	MK1L.5						;[INF] 3, 2
; line    70
$DGL	0,14
	clr1	IF1L.5						;[INF] 3, 2
; line    72
$DGL	0,16
	set1	MK0H.7						;[INF] 3, 2
; line    73
$DGL	0,17
	clr1	IF0H.7						;[INF] 3, 2
; line    75
$DGL	0,19
	set1	MK1L.6						;[INF] 3, 2
; line    76
$DGL	0,20
	clr1	IF1L.6						;[INF] 3, 2
; line    78
$DGL	0,22
	set1	MK1L.7						;[INF] 3, 2
; line    79
$DGL	0,23
	clr1	IF1L.7						;[INF] 3, 2
; line    81
$DGL	0,25
	set1	MK1L.2						;[INF] 3, 2
; line    82
$DGL	0,26
	clr1	IF1L.2						;[INF] 3, 2
; line    84
$DGL	0,28
	set1	MK1H.7						;[INF] 3, 2
; line    85
$DGL	0,29
	clr1	IF1H.7						;[INF] 3, 2
; line    87
$DGL	0,31
	set1	MK2L.0						;[INF] 3, 2
; line    88
$DGL	0,32
	clr1	IF2L.0						;[INF] 3, 2
; line    90
$DGL	0,34
	set1	MK2L.1						;[INF] 3, 2
; line    91
$DGL	0,35
	clr1	IF2L.1						;[INF] 3, 2
; line    93
$DGL	0,37
	set1	MK2L.2						;[INF] 3, 2
; line    94
$DGL	0,38
	clr1	IF2L.2						;[INF] 3, 2
; line    96
$DGL	0,40
	clr1	PR11L.4						;[INF] 3, 2
; line    97
$DGL	0,41
	clr1	PR01L.4						;[INF] 3, 2
; line   100
$DGL	0,44
	clrw	ax						;[INF] 1, 1
	movw	!TMR00,ax					;[INF] 3, 1
; line   101
$DGL	0,45
	movw	TDR00,#018FFH	; 6399 				;[INF] 4, 1
; line   102
$DGL	0,46
	movw	ax,!TO0						;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	and	a,#0FEH	; 254 					;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	movw	!TO0,ax						;[INF] 3, 1
; line   103
$DGL	0,47
	movw	ax,!TOE0					;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	and	a,#0FEH	; 254 					;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	movw	!TOE0,ax					;[INF] 3, 1
; line   104
$DGL	0,48
??ef_R_TAU0_Create:
	ret							;[INF] 1, 6
??ee_R_TAU0_Create:
; line   113
_R_TAU0_Channel0_Start:
$DGL	1,25
??bf_R_TAU0_Channel0_Start:
; line   114
$DGL	0,2
	clr1	IF1L.4						;[INF] 3, 2
; line   115
$DGL	0,3
	clr1	MK1L.4						;[INF] 3, 2
; line   116
$DGL	0,4
	movw	ax,!TS0						;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	or	a,#01H	; 1 					;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	movw	!TS0,ax						;[INF] 3, 1
; line   117
$DGL	0,5
??ef_R_TAU0_Channel0_Start:
	ret							;[INF] 1, 6
??ee_R_TAU0_Channel0_Start:
; line   126
_R_TAU0_Channel0_Stop:
$DGL	1,31
??bf_R_TAU0_Channel0_Stop:
; line   127
$DGL	0,2
	movw	ax,!TT0						;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	or	a,#01H	; 1 					;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	movw	!TT0,ax						;[INF] 3, 1
; line   129
$DGL	0,4
	set1	MK1L.4						;[INF] 3, 2
; line   130
$DGL	0,5
	clr1	IF1L.4						;[INF] 3, 2
; line   131
$DGL	0,6
??ef_R_TAU0_Channel0_Stop:
	ret							;[INF] 1, 6
??ee_R_TAU0_Channel0_Stop:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE
	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\r_cg_timer.c
;
; $FUNC R_TAU0_Create(57)
;	void=(void)
;	CODE SIZE= 109 bytes, CLOCK_SIZE= 69 clocks, STACK_SIZE= 0 bytes
;
; $FUNC R_TAU0_Channel0_Start(113)
;	void=(void)
;	CODE SIZE= 17 bytes, CLOCK_SIZE= 15 clocks, STACK_SIZE= 0 bytes
;
; $FUNC R_TAU0_Channel0_Stop(126)
;	void=(void)
;	CODE SIZE= 17 bytes, CLOCK_SIZE= 15 clocks, STACK_SIZE= 0 bytes

; Target chip : R5F100PG
; Device file : V1.14 
