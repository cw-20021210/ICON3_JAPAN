; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:54

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile r_cg_port.c -oDefaultBuild -_msgoff -nq -i. 
;             -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no -g2
; In-file   : r_cg_port.c
; Asm-file  : DefaultBuild\r_cg_port.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		019H,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, r_cg_port.c
$DGS	MOD_NAM, r_cg_port,	00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	GLV_SYM, _R_PORT_Create,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	019H,	01H,	00H
$DGS	BEG_FUN, ??bf_R_PORT_Create,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 039H,		00H,	019H
$DGS	END_FUN, ??ef_R_PORT_Create,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 02BH

	PUBLIC	_R_PORT_Create

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
_R_PORT_Create:
$DGL	1,19
??bf_R_PORT_Create:
; line    59
$DGL	0,3
	clrb	P0						;[INF] 2, 1
; line    61
$DGL	0,5
	clrb	P1						;[INF] 2, 1
; line    62
$DGL	0,6
	clrb	P3						;[INF] 2, 1
; line    64
$DGL	0,8
	clrb	P4						;[INF] 2, 1
; line    65
$DGL	0,9
	clrb	P5						;[INF] 2, 1
; line    66
$DGL	0,10
	clrb	P6						;[INF] 2, 1
; line    67
$DGL	0,11
	clrb	P7						;[INF] 2, 1
; line    69
$DGL	0,13
	clrb	P8						;[INF] 2, 1
; line    70
$DGL	0,14
	clrb	P10						;[INF] 2, 1
; line    71
$DGL	0,15
	clrb	P11						;[INF] 2, 1
; line    72
$DGL	0,16
	clrb	P13						;[INF] 2, 1
; line    74
$DGL	0,18
	clrb	P14						;[INF] 2, 1
; line    75
$DGL	0,19
	oneb	!PU4						;[INF] 3, 1
; line    76
$DGL	0,20
	mov	!PMC0,#0F3H	; 243 				;[INF] 4, 1
; line    77
$DGL	0,21
	mov	!ADPC,#06H	; 6 				;[INF] 4, 1
; line    79
$DGL	0,23
	mov	PM0,#080H	; 128 				;[INF] 3, 1
; line    81
$DGL	0,25
	mov	PM1,#018H	; 24 				;[INF] 3, 1
; line    83
$DGL	0,27
	mov	PM2,#0FFH	; 255 				;[INF] 3, 1
; line    84
$DGL	0,28
	mov	PM3,#0FEH	; 254 				;[INF] 3, 1
; line    86
$DGL	0,30
	oneb	!PM4						;[INF] 3, 1
; line    88
$DGL	0,32
	mov	PM5,#01FH	; 31 				;[INF] 3, 1
; line    90
$DGL	0,34
	mov	PM6,#0FH	; 15 				;[INF] 3, 1
; line    92
$DGL	0,36
	mov	PM7,#03FH	; 63 				;[INF] 3, 1
; line    94
$DGL	0,38
	clrb	!PM8						;[INF] 3, 1
; line    95
$DGL	0,39
	mov	PM10,#0F9H	; 249 				;[INF] 3, 1
; line    96
$DGL	0,40
	mov	PM11,#0FCH	; 252 				;[INF] 3, 1
; line    98
$DGL	0,42
	mov	PM14,#080H	; 128 				;[INF] 3, 1
; line    99
$DGL	0,43
??ef_R_PORT_Create:
	ret							;[INF] 1, 6
??ee_R_PORT_Create:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE
	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\r_cg_port.c
;
; $FUNC R_PORT_Create(57)
;	void=(void)
;	CODE SIZE= 72 bytes, CLOCK_SIZE= 33 clocks, STACK_SIZE= 0 bytes

; Target chip : R5F100PG
; Device file : V1.14 
