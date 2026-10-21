; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:56

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile r_cg_serial_user.c -oDefaultBuild -_msgoff -
;             nq -i. -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no
;              -g2
; In-file   : r_cg_serial_user.c
; Asm-file  : DefaultBuild\r_cg_serial_user.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		056H,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, r_cg_serial_user.c
$DGS	MOD_NAM, r_cg_serial_user,	00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	SEC_NAM, @@VECT18,	U,	U,	00H,	078H,	00H,	00H
$DGS	STA_SYM, _r_uart2_interrupt_receive,	U,	U,	0E001H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	027H,	00H,	00H
$DGS	BEG_FUN, ??bf_r_uart2_interrupt_receive,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 041H,		018H,	019H
$DGS	AUT_VAR, _rx_data,	01H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_r_uart2_interrupt_receive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	01BH
$DGS	BEG_BLK, ??bb01_r_uart2_interrupt_receive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0DH,		00H,	021H
$DGS	END_BLK, ??eb01_r_uart2_interrupt_receive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0FH
$DGS	END_BLK, ??eb00_r_uart2_interrupt_receive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 010H
$DGS	BEG_BLK, ??bb02_r_uart2_interrupt_receive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 012H,		00H,	00H
$DGS	END_BLK, ??eb02_r_uart2_interrupt_receive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 014H
$DGS	END_FUN, ??ef_r_uart2_interrupt_receive,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 015H
$DGS	STA_SYM, _r_uart2_interrupt_error,	U,	U,	0E001H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	02EH,	00H,	00H
$DGS	BEG_FUN, ??bf_r_uart2_interrupt_error,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 05EH,		018H,	02EH
$DGS	AUT_VAR, _err_type,	01H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	END_FUN, ??ef_r_uart2_interrupt_error,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 08H
$DGS	STA_SYM, _r_uart2_interrupt_send,	U,	U,	0E001H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	03CH,	00H,	00H
$DGS	BEG_FUN, ??bf_r_uart2_interrupt_send,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 06EH,		016H,	032H
$DGS	BEG_BLK, ??bb00_r_uart2_interrupt_send,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	036H
$DGS	END_BLK, ??eb00_r_uart2_interrupt_send,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 07H
$DGS	BEG_BLK, ??bb01_r_uart2_interrupt_send,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	00H
$DGS	END_BLK, ??eb01_r_uart2_interrupt_send,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0BH
$DGS	END_FUN, ??ef_r_uart2_interrupt_send,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0CH
$DGS	STA_SYM, _r_uart2_callback_receiveend,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	042H,	01H,	00H
$DGS	BEG_FUN, ??bf_r_uart2_callback_receiveend,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 082H,		00H,	042H
$DGS	END_FUN, ??ef_r_uart2_callback_receiveend,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	STA_SYM, _r_uart2_callback_softwareoverrun,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	049H,	01H,	00H
$DGS	BEG_FUN, ??bf_r_uart2_callback_softwareoverrun,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 08FH,		02H,	049H
$DGS	FUN_ARG, _rx_data,	00H,	0FFFFH,	0DH,	09H,	00H,	00H
$DGS	END_FUN, ??ef_r_uart2_callback_softwareoverrun,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	STA_SYM, _r_uart2_callback_sendend,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	04FH,	01H,	00H
$DGS	BEG_FUN, ??bf_r_uart2_callback_sendend,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 09BH,		00H,	04FH
$DGS	END_FUN, ??ef_r_uart2_callback_sendend,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	STA_SYM, _r_uart2_callback_error,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	056H,	01H,	00H
$DGS	BEG_FUN, ??bf_r_uart2_callback_error,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0A8H,		02H,	056H
$DGS	FUN_ARG, _err_type,	00H,	0FFFFH,	0CH,	09H,	00H,	00H
$DGS	END_FUN, ??ef_r_uart2_callback_error,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	GLV_SYM, _@vect18,	U,	U,	00H,	026H,	00H,	00H
$DGS	GLV_SYM, _@RTARG6,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@RTARG4,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@RTARG2,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@RTARG0,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@SEGDE,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@SEGAX,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _g_uart2_rx_count,	U,	U,	0100DH,	02H,	00H,	00H
$DGS	GLV_SYM, _g_uart2_rx_length,	U,	U,	0100DH,	02H,	00H,	00H
$DGS	GLV_SYM, _gp_uart2_rx_address,	U,	U,	0CH,	02H,	01H,	01H
$DGS	AUX_STR, 00H,		00H,	02H,	00H,	00H,	00H,	00H,	01H
$DGS	GLV_SYM, _g_uart2_tx_count,	U,	U,	0100DH,	02H,	00H,	00H
$DGS	GLV_SYM, _gp_uart2_tx_address,	U,	U,	0CH,	02H,	01H,	01H
$DGS	AUX_STR, 00H,		00H,	02H,	00H,	00H,	00H,	00H,	01H

	EXTRN	_@RTARG6
	EXTRN	_@RTARG4
	EXTRN	_@RTARG2
	EXTRN	_@RTARG0
	EXTRN	_@SEGDE
	EXTRN	_@SEGAX
	EXTRN	_g_uart2_rx_count
	EXTRN	_g_uart2_rx_length
	EXTRN	_gp_uart2_rx_address
	EXTRN	_g_uart2_tx_count
	EXTRN	_gp_uart2_tx_address
	PUBLIC	_@vect18

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
; line   386
; line   387
; line   388
; line   389
; line   390
; line   391
; line   392
; line   393
; line   394
; line   395
; line    50
; line    51
; line    52
; line    53
; line    54
; line    65

@@BASE	CSEG	BASE
_r_uart2_interrupt_receive:
$DGL	1,20
	push	ax						;[INF] 1, 1
	push	bc						;[INF] 1, 1
	push	de						;[INF] 1, 1
	push	hl						;[INF] 1, 1
	movw	ax,_@RTARG6					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@RTARG4					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@RTARG2					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@RTARG0					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@SEGDE					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@SEGAX					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	mov	a,ES						;[INF] 2, 1
	mov	x,a						;[INF] 1, 1
	mov	a,CS						;[INF] 2, 1
	push	ax						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_r_uart2_interrupt_receive:
; line    68
$DGL	0,4
	mov	a,RXD2						;[INF] 2, 1
	mov	[hl+1],a	; rx_data 			;[INF] 2, 1
; line    70
$DGL	0,6
	movw	ax,!_g_uart2_rx_count				;[INF] 3, 1
	cmpw	ax,!_g_uart2_rx_length				;[INF] 3, 1
	bnc	$?L0003						;[INF] 2, 4
; line    71
??bb00_r_uart2_interrupt_receive:
; line    72
$DGL	0,8
	movw	de,!_gp_uart2_rx_address			;[INF] 3, 1
	mov	a,[hl+1]	; rx_data 			;[INF] 2, 1
	mov	[de],a						;[INF] 1, 1
; line    73
$DGL	0,9
	incw	!_gp_uart2_rx_address				;[INF] 3, 2
; line    74
$DGL	0,10
	incw	!_g_uart2_rx_count				;[INF] 3, 2
; line    76
$DGL	0,12
	movw	ax,!_g_uart2_rx_length				;[INF] 3, 1
	cmpw	ax,!_g_uart2_rx_count				;[INF] 3, 1
	sknz							;[INF] 2, 1
; line    77
??bb01_r_uart2_interrupt_receive:
; line    78
$DGL	0,14
	call	!!_r_uart2_callback_receiveend			;[INF] 4, 3
??eb01_r_uart2_interrupt_receive:
; line    79
?L0005:
?L0006:
??eb00_r_uart2_interrupt_receive:
; line    81
$DGL	0,17
	br	$?L0004						;[INF] 2, 3
?L0003:
; line    82
??bb02_r_uart2_interrupt_receive:
; line    83
$DGL	0,19
	mov	a,[hl+1]	; rx_data 			;[INF] 2, 1
	shrw	ax,8						;[INF] 2, 1
	call	!!_r_uart2_callback_softwareoverrun		;[INF] 4, 3
??eb02_r_uart2_interrupt_receive:
; line    84
?L0004:
; line    85
$DGL	0,21
??ef_r_uart2_interrupt_receive:
	pop	ax						;[INF] 1, 1
	pop	ax						;[INF] 1, 1
	mov	CS,a						;[INF] 2, 1
	mov	a,x						;[INF] 1, 1
	mov	ES,a						;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@SEGAX,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@SEGDE,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@RTARG0,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@RTARG2,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@RTARG4,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@RTARG6,ax					;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	pop	de						;[INF] 1, 1
	pop	bc						;[INF] 1, 1
	pop	ax						;[INF] 1, 1
	reti							;[INF] 2, 6
??ee_r_uart2_interrupt_receive:
; line    94
_r_uart2_interrupt_error:
$DGL	1,39
	push	ax						;[INF] 1, 1
	push	bc						;[INF] 1, 1
	push	de						;[INF] 1, 1
	push	hl						;[INF] 1, 1
	movw	ax,_@RTARG6					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@RTARG4					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@RTARG2					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@RTARG0					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@SEGDE					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@SEGAX					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	mov	a,ES						;[INF] 2, 1
	mov	x,a						;[INF] 1, 1
	mov	a,CS						;[INF] 2, 1
	push	ax						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_r_uart2_interrupt_error:
; line    97
$DGL	0,4
	movw	de,!_gp_uart2_rx_address			;[INF] 3, 1
	mov	a,RXD2						;[INF] 2, 1
	mov	[de],a						;[INF] 1, 1
; line    98
$DGL	0,5
	movw	ax,!SSR11					;[INF] 3, 1
	mov	a,x						;[INF] 1, 1
	and	a,#07H	; 7 					;[INF] 2, 1
	mov	[hl+1],a	; err_type 			;[INF] 2, 1
; line    99
$DGL	0,6
	shrw	ax,8						;[INF] 2, 1
	movw	!SIR11,ax					;[INF] 3, 1
; line   100
$DGL	0,7
	mov	a,[hl+1]	; err_type 			;[INF] 2, 1
	shrw	ax,8						;[INF] 2, 1
	call	!!_r_uart2_callback_error			;[INF] 4, 3
; line   101
$DGL	0,8
??ef_r_uart2_interrupt_error:
	pop	ax						;[INF] 1, 1
	pop	ax						;[INF] 1, 1
	mov	CS,a						;[INF] 2, 1
	mov	a,x						;[INF] 1, 1
	mov	ES,a						;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@SEGAX,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@SEGDE,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@RTARG0,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@RTARG2,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@RTARG4,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@RTARG6,ax					;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	pop	de						;[INF] 1, 1
	pop	bc						;[INF] 1, 1
	pop	ax						;[INF] 1, 1
	reti							;[INF] 2, 6
??ee_r_uart2_interrupt_error:
; line   110
_r_uart2_interrupt_send:
$DGL	1,46
	push	ax						;[INF] 1, 1
	push	bc						;[INF] 1, 1
	push	de						;[INF] 1, 1
	push	hl						;[INF] 1, 1
	movw	ax,_@RTARG6					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@RTARG4					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@RTARG2					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@RTARG0					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@SEGDE					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,_@SEGAX					;[INF] 2, 1
	push	ax						;[INF] 1, 1
	mov	a,ES						;[INF] 2, 1
	mov	x,a						;[INF] 1, 1
	mov	a,CS						;[INF] 2, 1
	push	ax						;[INF] 1, 1
??bf_r_uart2_interrupt_send:
; line   111
$DGL	0,2
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_g_uart2_tx_count				;[INF] 3, 1
	bz	$?L0011						;[INF] 2, 4
; line   112
??bb00_r_uart2_interrupt_send:
; line   113
$DGL	0,4
	movw	de,!_gp_uart2_tx_address			;[INF] 3, 1
	mov	a,[de]						;[INF] 1, 1
	mov	TXD2,a						;[INF] 2, 1
; line   114
$DGL	0,5
	incw	!_gp_uart2_tx_address				;[INF] 3, 2
; line   115
$DGL	0,6
	decw	!_g_uart2_tx_count				;[INF] 3, 2
??eb00_r_uart2_interrupt_send:
; line   117
$DGL	0,8
	br	$?L0012						;[INF] 2, 3
?L0011:
; line   118
??bb01_r_uart2_interrupt_send:
; line   119
$DGL	0,10
	call	!!_r_uart2_callback_sendend			;[INF] 4, 3
??eb01_r_uart2_interrupt_send:
; line   120
?L0012:
; line   121
$DGL	0,12
??ef_r_uart2_interrupt_send:
	pop	ax						;[INF] 1, 1
	mov	CS,a						;[INF] 2, 1
	mov	a,x						;[INF] 1, 1
	mov	ES,a						;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@SEGAX,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@SEGDE,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@RTARG0,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@RTARG2,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@RTARG4,ax					;[INF] 2, 1
	pop	ax						;[INF] 1, 1
	movw	_@RTARG6,ax					;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	pop	de						;[INF] 1, 1
	pop	bc						;[INF] 1, 1
	pop	ax						;[INF] 1, 1
	reti							;[INF] 2, 6
??ee_r_uart2_interrupt_send:
; line   130

@@CODEL	CSEG
_r_uart2_callback_receiveend:
$DGL	1,60
??bf_r_uart2_callback_receiveend:
; line   133
$DGL	0,4
??ef_r_uart2_callback_receiveend:
	ret							;[INF] 1, 6
??ee_r_uart2_callback_receiveend:
; line   143
_r_uart2_callback_softwareoverrun:
$DGL	1,66
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_r_uart2_callback_softwareoverrun:
; line   146
$DGL	0,4
??ef_r_uart2_callback_softwareoverrun:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_r_uart2_callback_softwareoverrun:
; line   155
_r_uart2_callback_sendend:
$DGL	1,73
??bf_r_uart2_callback_sendend:
; line   158
$DGL	0,4
??ef_r_uart2_callback_sendend:
	ret							;[INF] 1, 6
??ee_r_uart2_callback_sendend:
; line   168
_r_uart2_callback_error:
$DGL	1,79
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_r_uart2_callback_error:
; line   171
$DGL	0,4
??ef_r_uart2_callback_error:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_r_uart2_callback_error:

@@VECT18	CSEG	AT    0018H
_@vect18:
	DW	_r_uart2_interrupt_error

@@CODE	CSEG	BASE
	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\r_cg_serial_user.c
;
; $FUNC r_uart2_interrupt_receive(65)
;	void=(void)
;	CODE SIZE= 109 bytes, CLOCK_SIZE= 78 clocks, STACK_SIZE= 28 bytes
;
; $CALL r_uart2_callback_receiveend(78)
;	void=(void)
;
; $CALL r_uart2_callback_softwareoverrun(83)
;	void=(unsigned short:ax)
;
; $FUNC r_uart2_interrupt_error(94)
;	void=(void)
;	CODE SIZE= 90 bytes, CLOCK_SIZE= 63 clocks, STACK_SIZE= 28 bytes
;
; $CALL r_uart2_callback_error(100)
;	void=(int:ax)
;
; $FUNC r_uart2_interrupt_send(110)
;	void=(void)
;	CODE SIZE= 82 bytes, CLOCK_SIZE= 65 clocks, STACK_SIZE= 26 bytes
;
; $CALL r_uart2_callback_sendend(119)
;	void=(void)
;
; $FUNC r_uart2_callback_receiveend(130)
;	void=(void)
;	CODE SIZE= 1 bytes, CLOCK_SIZE= 6 clocks, STACK_SIZE= 0 bytes
;
; $FUNC r_uart2_callback_softwareoverrun(143)
;	void=(unsigned short rx_data:ax)
;	CODE SIZE= 8 bytes, CLOCK_SIZE= 11 clocks, STACK_SIZE= 4 bytes
;
; $FUNC r_uart2_callback_sendend(155)
;	void=(void)
;	CODE SIZE= 1 bytes, CLOCK_SIZE= 6 clocks, STACK_SIZE= 0 bytes
;
; $FUNC r_uart2_callback_error(168)
;	void=(unsigned char err_type:x)
;	CODE SIZE= 8 bytes, CLOCK_SIZE= 11 clocks, STACK_SIZE= 4 bytes

; Target chip : R5F100PG
; Device file : V1.14 
