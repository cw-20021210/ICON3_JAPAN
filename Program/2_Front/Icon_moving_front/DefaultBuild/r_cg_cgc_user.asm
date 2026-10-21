; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:54

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile r_cg_cgc_user.c -oDefaultBuild -_msgoff -nq 
;             -i. -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no -g
;             2
; In-file   : r_cg_cgc_user.c
; Asm-file  : DefaultBuild\r_cg_cgc_user.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		01AH,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, r_cg_cgc_user.c
$DGS	MOD_NAM, r_cg_cgc_user,	00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	GLV_SYM, _R_CGC_Get_ResetSource,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	01AH,	01H,	00H
$DGS	BEG_FUN, ??bf_R_CGC_Get_ResetSource,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 039H,		02H,	01AH
$DGS	AUT_VAR, _reset_flag,	01H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	END_FUN, ??ef_R_CGC_Get_ResetSource,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 05H

	PUBLIC	_R_CGC_Get_ResetSource

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
; line    57

@@CODEL	CSEG
_R_CGC_Get_ResetSource:
$DGL	1,19
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_R_CGC_Get_ResetSource:
; line    58
$DGL	0,2
	mov	a,RESF						;[INF] 2, 1
	mov	[hl+1],a	; reset_flag 			;[INF] 2, 1
; line    61
$DGL	0,5
??ef_R_CGC_Get_ResetSource:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_R_CGC_Get_ResetSource:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE
	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\r_cg_cgc_user.c
;
; $FUNC R_CGC_Get_ResetSource(57)
;	void=(void)
;	CODE SIZE= 12 bytes, CLOCK_SIZE= 13 clocks, STACK_SIZE= 4 bytes

; Target chip : R5F100PG
; Device file : V1.14 
