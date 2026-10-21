; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:55

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile r_cg_wdt.c -oDefaultBuild -_msgoff -nq -i. -
;             iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no -g2
; In-file   : r_cg_wdt.c
; Asm-file  : DefaultBuild\r_cg_wdt.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		01FH,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, r_cg_wdt.c
$DGS	MOD_NAM, r_cg_wdt,	00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	GLV_SYM, _R_WDT_Create,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	019H,	01H,	00H
$DGS	BEG_FUN, ??bf_R_WDT_Create,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 039H,		00H,	019H
$DGS	END_FUN, ??ef_R_WDT_Create,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 08H
$DGS	GLV_SYM, _R_WDT_Restart,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	01FH,	01H,	00H
$DGS	BEG_FUN, ??bf_R_WDT_Restart,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 049H,		00H,	01FH
$DGS	END_FUN, ??ef_R_WDT_Restart,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H

	PUBLIC	_R_WDT_Create
	PUBLIC	_R_WDT_Restart

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
_R_WDT_Create:
$DGL	1,19
??bf_R_WDT_Create:
; line    58
$DGL	0,2
	set1	MK0L.0						;[INF] 3, 2
; line    59
$DGL	0,3
	clr1	IF0L.0						;[INF] 3, 2
; line    61
$DGL	0,5
	set1	PR10L.0						;[INF] 3, 2
; line    62
$DGL	0,6
	set1	PR00L.0						;[INF] 3, 2
; line    63
$DGL	0,7
	clr1	MK0L.0						;[INF] 3, 2
; line    64
$DGL	0,8
??ef_R_WDT_Create:
	ret							;[INF] 1, 6
??ee_R_WDT_Create:
; line    73
_R_WDT_Restart:
$DGL	1,25
??bf_R_WDT_Restart:
; line    74
$DGL	0,2
	mov	WDTE,#0ACH	; 172 				;[INF] 3, 1
; line    75
$DGL	0,3
??ef_R_WDT_Restart:
	ret							;[INF] 1, 6
??ee_R_WDT_Restart:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE
	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\r_cg_wdt.c
;
; $FUNC R_WDT_Create(57)
;	void=(void)
;	CODE SIZE= 16 bytes, CLOCK_SIZE= 16 clocks, STACK_SIZE= 0 bytes
;
; $FUNC R_WDT_Restart(73)
;	void=(void)
;	CODE SIZE= 4 bytes, CLOCK_SIZE= 7 clocks, STACK_SIZE= 0 bytes

; Target chip : R5F100PG
; Device file : V1.14 
