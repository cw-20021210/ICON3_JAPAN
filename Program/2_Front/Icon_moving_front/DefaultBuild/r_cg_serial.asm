; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:55

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile r_cg_serial.c -oDefaultBuild -_msgoff -nq -i
;             . -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no -g2
; In-file   : r_cg_serial.c
; Asm-file  : DefaultBuild\r_cg_serial.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		04FH,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, r_cg_serial.c
$DGS	MOD_NAM, r_cg_serial,	00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	GLV_SYM, _R_SAU1_Create,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	019H,	01H,	00H
$DGS	BEG_FUN, ??bf_R_SAU1_Create,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 03EH,		00H,	019H
$DGS	END_FUN, ??ef_R_SAU1_Create,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 09H
$DGS	GLV_SYM, _R_UART2_Create,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	01FH,	01H,	00H
$DGS	BEG_FUN, ??bf_R_UART2_Create,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 04FH,		00H,	01FH
$DGS	END_FUN, ??ef_R_UART2_Create,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 026H
$DGS	GLV_SYM, _R_UART2_Start,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	025H,	01H,	00H
$DGS	BEG_FUN, ??bf_R_UART2_Start,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 07DH,		00H,	025H
$DGS	END_FUN, ??ef_R_UART2_Start,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0BH
$DGS	GLV_SYM, _R_UART2_Stop,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	02BH,	01H,	00H
$DGS	BEG_FUN, ??bf_R_UART2_Stop,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 090H,		00H,	02BH
$DGS	END_FUN, ??ef_R_UART2_Stop,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0BH
$DGS	GLV_SYM, _R_UART2_Receive,	U,	U,	0DH,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	03DH,	01H,	00H
$DGS	BEG_FUN, ??bf_R_UART2_Receive,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0A7H,		04H,	033H
$DGS	FUN_ARG, _rx_buf,	02H,	0FFFFH,	0500CH,	09H,	01H,	01H
$DGS	AUX_STR, 00H,		00H,	02H,	00H,	00H,	00H,	00H,	01H
$DGS	FUN_ARG, _rx_num,	0AH,	0FFFFH,	0DH,	09H,	00H,	00H
$DGS	AUT_VAR, _status,	00H,	0FFFFH,	0DH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_R_UART2_Receive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 05H,		00H,	037H
$DGS	END_BLK, ??eb00_R_UART2_Receive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 07H
$DGS	BEG_BLK, ??bb01_R_UART2_Receive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	00H
$DGS	END_BLK, ??eb01_R_UART2_Receive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0DH
$DGS	END_FUN, ??ef_R_UART2_Receive,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 010H
$DGS	GLV_SYM, _R_UART2_Send,	U,	U,	0DH,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	04FH,	01H,	00H
$DGS	BEG_FUN, ??bf_R_UART2_Send,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0C3H,		04H,	045H
$DGS	FUN_ARG, _tx_buf,	02H,	0FFFFH,	0500CH,	09H,	01H,	01H
$DGS	AUX_STR, 00H,		00H,	02H,	00H,	00H,	00H,	00H,	01H
$DGS	FUN_ARG, _tx_num,	0AH,	0FFFFH,	0DH,	09H,	00H,	00H
$DGS	AUT_VAR, _status,	00H,	0FFFFH,	0DH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_R_UART2_Send,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 05H,		00H,	049H
$DGS	END_BLK, ??eb00_R_UART2_Send,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 07H
$DGS	BEG_BLK, ??bb01_R_UART2_Send,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	00H
$DGS	END_BLK, ??eb01_R_UART2_Send,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 011H
$DGS	END_FUN, ??ef_R_UART2_Send,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 014H
$DGS	GLV_SYM, _gp_uart2_tx_address,	U,	U,	0CH,	026H,	01H,	01H
$DGS	AUX_STR, 00H,		00H,	02H,	00H,	00H,	00H,	00H,	01H
$DGS	GLV_SYM, _g_uart2_tx_count,	U,	U,	0100DH,	026H,	00H,	00H
$DGS	GLV_SYM, _gp_uart2_rx_address,	U,	U,	0CH,	026H,	01H,	01H
$DGS	AUX_STR, 00H,		00H,	02H,	00H,	00H,	00H,	00H,	01H
$DGS	GLV_SYM, _g_uart2_rx_count,	U,	U,	0100DH,	026H,	00H,	00H
$DGS	GLV_SYM, _g_uart2_rx_length,	U,	U,	0100DH,	026H,	00H,	00H

	PUBLIC	_gp_uart2_tx_address
	PUBLIC	_g_uart2_tx_count
	PUBLIC	_gp_uart2_rx_address
	PUBLIC	_g_uart2_rx_count
	PUBLIC	_g_uart2_rx_length
	PUBLIC	_R_SAU1_Create
	PUBLIC	_R_UART2_Create
	PUBLIC	_R_UART2_Start
	PUBLIC	_R_UART2_Stop
	PUBLIC	_R_UART2_Receive
	PUBLIC	_R_UART2_Send

@@BITS	BSEG

@@CNST	CSEG	MIRRORP

@@R_INIT	CSEG	UNIT64KP

@@INIT	DSEG	BASEP

@@DATA	DSEG	BASEP
_gp_uart2_tx_address:	DS	(2)
_g_uart2_tx_count:	DS	(2)
_gp_uart2_rx_address:	DS	(2)
_g_uart2_rx_count:	DS	(2)
_g_uart2_rx_length:	DS	(2)

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
; line   392
; line   393
; line   394
; line   395
; line    47
; line    48
; line    49
; line    50
; line    51
; line    62

@@CODEL	CSEG
_R_SAU1_Create:
$DGL	1,19
??bf_R_SAU1_Create:
; line    63
$DGL	0,2
	set1	!PER0.3						;[INF] 4, 2
; line    64
$DGL	0,3
	nop							;[INF] 1, 1
; line    65
$DGL	0,4
	nop							;[INF] 1, 1
; line    66
$DGL	0,5
	nop							;[INF] 1, 1
; line    67
$DGL	0,6
	nop							;[INF] 1, 1
; line    68
$DGL	0,7
	movw	ax,#011H	; 17 				;[INF] 3, 1
	movw	!SPS1,ax					;[INF] 3, 1
; line    69
$DGL	0,8
	call	!!_R_UART2_Create				;[INF] 4, 3
; line    70
$DGL	0,9
??ef_R_SAU1_Create:
	ret							;[INF] 1, 6
??ee_R_SAU1_Create:
; line    79
_R_UART2_Create:
$DGL	1,25
??bf_R_UART2_Create:
; line    80
$DGL	0,2
	movw	ax,!ST1						;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	or	a,#03H	; 3 					;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	movw	!ST1,ax						;[INF] 3, 1
; line    81
$DGL	0,3
	set1	MK0H.0						;[INF] 3, 2
; line    82
$DGL	0,4
	clr1	IF0H.0						;[INF] 3, 2
; line    83
$DGL	0,5
	set1	MK0H.1						;[INF] 3, 2
; line    84
$DGL	0,6
	clr1	IF0H.1						;[INF] 3, 2
; line    85
$DGL	0,7
	set1	MK0H.2						;[INF] 3, 2
; line    86
$DGL	0,8
	clr1	IF0H.2						;[INF] 3, 2
; line    88
$DGL	0,10
	clr1	PR10H.0						;[INF] 3, 2
; line    89
$DGL	0,11
	clr1	PR00H.0						;[INF] 3, 2
; line    91
$DGL	0,13
	clr1	PR10H.1						;[INF] 3, 2
; line    92
$DGL	0,14
	clr1	PR00H.1						;[INF] 3, 2
; line    94
$DGL	0,16
	set1	PR10H.2						;[INF] 3, 2
; line    95
$DGL	0,17
	set1	PR00H.2						;[INF] 3, 2
; line    97
$DGL	0,19
	movw	ax,#022H	; 34 				;[INF] 3, 1
	movw	!SMR10,ax					;[INF] 3, 1
; line    99
$DGL	0,21
	movw	ax,#08097H	; -32617 			;[INF] 3, 1
	movw	!SCR10,ax					;[INF] 3, 1
; line   100
$DGL	0,22
	movw	SDR10,#0CE00H	; -12800 			;[INF] 4, 1
; line   101
$DGL	0,23
	mov	a,!NFEN0					;[INF] 3, 1
	or	a,#010H	; 16 					;[INF] 2, 1
	mov	!NFEN0,a					;[INF] 3, 1
; line   102
$DGL	0,24
	movw	ax,#07H	; 7 					;[INF] 3, 1
	movw	!SIR11,ax					;[INF] 3, 1
; line   104
$DGL	0,26
	movw	ax,#0122H	; 290 				;[INF] 3, 1
	movw	!SMR11,ax					;[INF] 3, 1
; line   106
$DGL	0,28
	movw	ax,#04497H	; 17559 			;[INF] 3, 1
	movw	!SCR11,ax					;[INF] 3, 1
; line   107
$DGL	0,29
	movw	SDR11,#0CE00H	; -12800 			;[INF] 4, 1
; line   108
$DGL	0,30
	movw	ax,!SO1						;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	or	a,#01H	; 1 					;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	movw	!SO1,ax						;[INF] 3, 1
; line   109
$DGL	0,31
	movw	ax,!SOL1					;[INF] 3, 1
	movw	!SOL1,ax					;[INF] 3, 1
; line   110
$DGL	0,32
	movw	ax,!SOE1					;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	or	a,#01H	; 1 					;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	movw	!SOE1,ax					;[INF] 3, 1
; line   112
$DGL	0,34
	mov	a,PM1						;[INF] 2, 1
	or	a,#010H	; 16 					;[INF] 2, 1
	mov	PM1,a						;[INF] 2, 1
; line   114
$DGL	0,36
	or	P1,#08H	; 8 					;[INF] 3, 2
; line   115
$DGL	0,37
	mov	a,PM1						;[INF] 2, 1
	and	a,#0F7H	; 247 					;[INF] 2, 1
	mov	PM1,a						;[INF] 2, 1
; line   116
$DGL	0,38
??ef_R_UART2_Create:
	ret							;[INF] 1, 6
??ee_R_UART2_Create:
; line   125
_R_UART2_Start:
$DGL	1,31
??bf_R_UART2_Start:
; line   126
$DGL	0,2
	movw	ax,!SO1						;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	or	a,#01H	; 1 					;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	movw	!SO1,ax						;[INF] 3, 1
; line   127
$DGL	0,3
	movw	ax,!SOE1					;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	or	a,#01H	; 1 					;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	movw	!SOE1,ax					;[INF] 3, 1
; line   128
$DGL	0,4
	movw	ax,!SS1						;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	or	a,#03H	; 3 					;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	movw	!SS1,ax						;[INF] 3, 1
; line   129
$DGL	0,5
	clr1	IF0H.0						;[INF] 3, 2
; line   130
$DGL	0,6
	clr1	IF0H.1						;[INF] 3, 2
; line   131
$DGL	0,7
	clr1	IF0H.2						;[INF] 3, 2
; line   132
$DGL	0,8
	clr1	MK0H.0						;[INF] 3, 2
; line   133
$DGL	0,9
	clr1	MK0H.1						;[INF] 3, 2
; line   134
$DGL	0,10
	clr1	MK0H.2						;[INF] 3, 2
; line   135
$DGL	0,11
??ef_R_UART2_Start:
	ret							;[INF] 1, 6
??ee_R_UART2_Start:
; line   144
_R_UART2_Stop:
$DGL	1,37
??bf_R_UART2_Stop:
; line   145
$DGL	0,2
	set1	MK0H.0						;[INF] 3, 2
; line   146
$DGL	0,3
	set1	MK0H.1						;[INF] 3, 2
; line   147
$DGL	0,4
	set1	MK0H.2						;[INF] 3, 2
; line   148
$DGL	0,5
	movw	ax,!ST1						;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	or	a,#03H	; 3 					;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	movw	!ST1,ax						;[INF] 3, 1
; line   149
$DGL	0,6
	movw	ax,!SOE1					;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	and	a,#0FEH	; 254 					;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	movw	!SOE1,ax					;[INF] 3, 1
; line   150
$DGL	0,7
	clr1	IF0H.0						;[INF] 3, 2
; line   151
$DGL	0,8
	clr1	IF0H.1						;[INF] 3, 2
; line   152
$DGL	0,9
	clr1	IF0H.2						;[INF] 3, 2
; line   154
$DGL	0,11
??ef_R_UART2_Stop:
	ret							;[INF] 1, 6
??ee_R_UART2_Stop:
; line   167
_R_UART2_Receive:
$DGL	1,43
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_R_UART2_Receive:
; line   168
$DGL	0,2
	clrw	ax						;[INF] 1, 1
	movw	[hl],ax	; status 				;[INF] 1, 1
; line   170
$DGL	0,4
	cmpw	ax,[hl+10]	; rx_num 			;[INF] 3, 1
	bnz	$?L0011						;[INF] 2, 4
; line   171
??bb00_R_UART2_Receive:
; line   172
$DGL	0,6
	mov	x,#081H	; 129 					;[INF] 2, 1
	movw	[hl],ax	; status 				;[INF] 1, 1
??eb00_R_UART2_Receive:
; line   174
$DGL	0,8
	br	$?L0012						;[INF] 2, 3
?L0011:
; line   175
??bb01_R_UART2_Receive:
; line   176
$DGL	0,10
	clrw	ax						;[INF] 1, 1
	movw	!_g_uart2_rx_count,ax				;[INF] 3, 1
; line   177
$DGL	0,11
	movw	ax,[hl+10]	; rx_num 			;[INF] 2, 1
	movw	!_g_uart2_rx_length,ax				;[INF] 3, 1
; line   178
$DGL	0,12
	movw	ax,[hl+2]	; rx_buf 			;[INF] 2, 1
	movw	!_gp_uart2_rx_address,ax			;[INF] 3, 1
??eb01_R_UART2_Receive:
; line   179
?L0012:
; line   181
$DGL	0,15
	movw	ax,[hl]	; status 				;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
; line   182
?L0010:
; line   182
$DGL	0,16
??ef_R_UART2_Receive:
	addw	sp,#04H						;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_R_UART2_Receive:
; line   195
_R_UART2_Send:
$DGL	1,61
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_R_UART2_Send:
; line   196
$DGL	0,2
	clrw	ax						;[INF] 1, 1
	movw	[hl],ax	; status 				;[INF] 1, 1
; line   198
$DGL	0,4
	cmpw	ax,[hl+10]	; tx_num 			;[INF] 3, 1
	bnz	$?L0015						;[INF] 2, 4
; line   199
??bb00_R_UART2_Send:
; line   200
$DGL	0,6
	mov	x,#081H	; 129 					;[INF] 2, 1
	movw	[hl],ax	; status 				;[INF] 1, 1
??eb00_R_UART2_Send:
; line   202
$DGL	0,8
	br	$?L0016						;[INF] 2, 3
?L0015:
; line   203
??bb01_R_UART2_Send:
; line   204
$DGL	0,10
	movw	ax,[hl+2]	; tx_buf 			;[INF] 2, 1
	movw	!_gp_uart2_tx_address,ax			;[INF] 3, 1
; line   205
$DGL	0,11
	movw	ax,[hl+10]	; tx_num 			;[INF] 2, 1
	movw	!_g_uart2_tx_count,ax				;[INF] 3, 1
; line   206
$DGL	0,12
	set1	MK0H.0						;[INF] 3, 2
; line   207
$DGL	0,13
	movw	de,!_gp_uart2_tx_address			;[INF] 3, 1
	mov	a,[de]						;[INF] 1, 1
	mov	TXD2,a						;[INF] 2, 1
; line   208
$DGL	0,14
	incw	!_gp_uart2_tx_address				;[INF] 3, 2
; line   209
$DGL	0,15
	decw	!_g_uart2_tx_count				;[INF] 3, 2
; line   210
$DGL	0,16
	clr1	MK0H.0						;[INF] 3, 2
??eb01_R_UART2_Send:
; line   211
?L0016:
; line   213
$DGL	0,19
	movw	ax,[hl]	; status 				;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
; line   214
?L0014:
; line   214
$DGL	0,20
??ef_R_UART2_Send:
	addw	sp,#04H						;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_R_UART2_Send:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE
	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\r_cg_serial.c
;
; $FUNC R_SAU1_Create(62)
;	void=(void)
;	CODE SIZE= 19 bytes, CLOCK_SIZE= 17 clocks, STACK_SIZE= 4 bytes
;
; $CALL R_UART2_Create(69)
;	void=(void)
;
; $FUNC R_UART2_Create(79)
;	void=(void)
;	CODE SIZE= 134 bytes, CLOCK_SIZE= 70 clocks, STACK_SIZE= 0 bytes
;
; $FUNC R_UART2_Start(125)
;	void=(void)
;	CODE SIZE= 49 bytes, CLOCK_SIZE= 33 clocks, STACK_SIZE= 0 bytes
;
; $FUNC R_UART2_Stop(144)
;	void=(void)
;	CODE SIZE= 39 bytes, CLOCK_SIZE= 28 clocks, STACK_SIZE= 0 bytes
;
; $FUNC R_UART2_Receive(167)
;	bc=(pointer rx_buf:ax, unsigned short rx_num:[sp+4])
;	CODE SIZE= 38 bytes, CLOCK_SIZE= 32 clocks, STACK_SIZE= 6 bytes
;
; $FUNC R_UART2_Send(195)
;	bc=(pointer tx_buf:ax, unsigned short tx_num:[sp+4])
;	CODE SIZE= 52 bytes, CLOCK_SIZE= 41 clocks, STACK_SIZE= 6 bytes

; Target chip : R5F100PG
; Device file : V1.14 
