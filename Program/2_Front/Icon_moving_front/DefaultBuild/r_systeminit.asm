; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:54

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile r_systeminit.c -oDefaultBuild -_msgoff -nq -
;             i. -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no -g2
; In-file   : r_systeminit.c
; Asm-file  : DefaultBuild\r_systeminit.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		01FH,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, r_systeminit.c
$DGS	MOD_NAM, r_systeminit,	00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	GLV_SYM, _R_Systeminit,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	019H,	01H,	00H
$DGS	BEG_FUN, ??bf_R_Systeminit,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 03DH,		00H,	019H
$DGS	END_FUN, ??ef_R_Systeminit,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0BH
$DGS	GLV_SYM, _hdwinit,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	01FH,	01H,	00H
$DGS	BEG_FUN, ??bf_hdwinit,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 051H,		00H,	01FH
$DGS	END_FUN, ??ef_hdwinit,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	GLV_SYM, _R_CGC_Get_ResetSource,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _R_CGC_Create,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _R_PORT_Create,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _R_SAU1_Create,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _R_TAU0_Create,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _R_WDT_Create,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H

	EXTRN	_R_CGC_Get_ResetSource
	EXTRN	_R_CGC_Create
	EXTRN	_R_PORT_Create
	EXTRN	_R_SAU1_Create
	EXTRN	_R_TAU0_Create
	EXTRN	_R_WDT_Create
	PUBLIC	_R_Systeminit
	PUBLIC	_hdwinit

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
; line   161
; line   166
; line   167
; line   211
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
; line   411
; line   412
; line   413
; line    47
; line    48
; line    61

@@CODEL	CSEG
_R_Systeminit:
$DGL	1,19
??bf_R_Systeminit:
; line    62
$DGL	0,2
	clrb	!PIOR						;[INF] 3, 1
; line    63
$DGL	0,3
	call	!!_R_CGC_Get_ResetSource			;[INF] 4, 3
; line    64
$DGL	0,4
	call	!!_R_CGC_Create					;[INF] 4, 3
; line    65
$DGL	0,5
	call	!!_R_PORT_Create				;[INF] 4, 3
; line    66
$DGL	0,6
	call	!!_R_SAU1_Create				;[INF] 4, 3
; line    67
$DGL	0,7
	call	!!_R_TAU0_Create				;[INF] 4, 3
; line    68
$DGL	0,8
	call	!!_R_WDT_Create					;[INF] 4, 3
; line    70
$DGL	0,10
	clrb	!IAWCTL						;[INF] 3, 1
; line    71
$DGL	0,11
??ef_R_Systeminit:
	ret							;[INF] 1, 6
??ee_R_Systeminit:
; line    81
_hdwinit:
$DGL	1,25
	di							;[INF] 3, 4
??bf_hdwinit:
; line    83
$DGL	0,3
	call	!!_R_Systeminit					;[INF] 4, 3
; line    84
$DGL	0,4
??ef_hdwinit:
	ret							;[INF] 1, 6
??ee_hdwinit:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE
	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\r_systeminit.c
;
; $FUNC R_Systeminit(61)
;	void=(void)
;	CODE SIZE= 31 bytes, CLOCK_SIZE= 26 clocks, STACK_SIZE= 4 bytes
;
; $CALL R_CGC_Get_ResetSource(63)
;	void=(void)
;
; $CALL R_CGC_Create(64)
;	void=(void)
;
; $CALL R_PORT_Create(65)
;	void=(void)
;
; $CALL R_SAU1_Create(66)
;	void=(void)
;
; $CALL R_TAU0_Create(67)
;	void=(void)
;
; $CALL R_WDT_Create(68)
;	void=(void)
;
; $FUNC hdwinit(81)
;	void=(void)
;	CODE SIZE= 8 bytes, CLOCK_SIZE= 13 clocks, STACK_SIZE= 4 bytes
;
; $CALL R_Systeminit(83)
;	void=(void)

; Target chip : R5F100PG
; Device file : V1.14 
