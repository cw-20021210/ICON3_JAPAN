; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:55

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile r_cg_timer_user.c -oDefaultBuild -_msgoff -n
;             q -i. -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no 
;             -g2
; In-file   : r_cg_timer_user.c
; Asm-file  : DefaultBuild\r_cg_timer_user.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		01BH,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, r_cg_timer_user.c
$DGS	MOD_NAM, r_cg_timer_user,	00H,	0FFFEH,	00H,	077H,	00H,	00H
$DGS	SEC_NAM, @@BITS,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@CNST,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@R_INIT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@INIT,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@DATA,	U,	U,	00H,	078H,	00H,	00H
$DGS	SEC_NAM, @@FIX,		U,	U,	00H,	078H,	00H,	00H
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
$DGS	SEC_NAM, @@VECT2C,	U,	U,	00H,	078H,	00H,	00H
$DGS	STA_SYM, _r_tau0_channel0_interrupt,	U,	U,	0E001H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	01BH,	00H,	00H
$DGS	BEG_FUN, ??bf_r_tau0_channel0_interrupt,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 03BH,		016H,	01BH
$DGS	END_FUN, ??ef_r_tau0_channel0_interrupt,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	GLV_SYM, _@vect2c,	U,	U,	00H,	026H,	00H,	00H
$DGS	GLV_SYM, _@RTARG6,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@RTARG4,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@RTARG2,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@RTARG0,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@SEGDE,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@SEGAX,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _Timer_Base_Timer,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H

	EXTRN	_@RTARG6
	EXTRN	_@RTARG4
	EXTRN	_@RTARG2
	EXTRN	_@RTARG0
	EXTRN	_@SEGDE
	EXTRN	_@SEGAX
	EXTRN	_Timer_Base_Timer
	PUBLIC	_@vect2c

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
; line   411
; line   412
; line   413
; line    47
; line    48
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
; line     7
; line     8
; line     9
; line    10
; line    11
; line    12
; line    13
; line    14
; line    15
; line    16
; line    17
; line    28
; line    40
; line    60
; line    66
; line    73
; line   112
; line   160
; line   176
; line   186
; line   192
; line   199
; line   206
; line   218
; line   230
; line   236
; line   256
; line   266
; line   273
; line   279
; line   287
; line   296
; line   304
; line    18
; line    42
; line    46
; line   129
; line   220
; line   247
; line   274
; line   301
; line   302
; line   304
; line   305
; line   307
; line   309
; line   310
; line   311
; line   313
; line   315
; line   316
; line   317
; line   318
; line   320
; line   321
; line   323
; line   364
; line   365
; line   370
; line   375
; line   376
; line   377
; line   378
; line   379
; line   380
; line   382
; line    60
; line    62
; line    63
; line    68
; line    69
; line    47
; line    64
; line    67
; line    72
; line    73
; line    74
; line    79
; line    84
; line    85
; line    86
; line    47
; line    49
; line   115
; line   116
; line   118
; line   119
; line   120
; line   121
; line   126
; line   127
; line   128
; line   129
; line   130
; line   131
; line   132
; line   133
; line    71
; line    73
; line    78
; line    79
; line    48
; line    49
; line    50
; line    51
; line    42
; line    43
; line    44
; line    45
; line    47
; line    48
; line    50
; line    51
; line    57
; line    58
; line    59
; line    60
; line    61
; line    62
; line    63
; line    64
; line    65
; line    66
; line    67
; line    65
; line    66
; line    72
; line    73
; line    74
; line    75
; line    79
; line    80
; line    81
; line    83
; line    84
; line    86
; line    87
; line    89
; line    91
; line    92
; line    94
; line    95
; line    96
; line    98
; line   100
; line   101
; line   102
; line   103
; line   104
; line   105
; line   106
; line   107
; line   108
; line   109
; line   110
; line   111
; line   112
; line   113
; line   114
; line   115
; line   116
; line   117
; line   118
; line   119
; line   120
; line   121
; line   122
; line   123
; line   124
; line   125
; line   126
; line   127
; line   128
; line   129
; line   130
; line   131
; line   132
; line   133
; line   134
; line   135
; line   136
; line   139
; line   141
; line   142
; line   145
; line   149
; line   150
; line   151
; line   152
; line   153
; line   154
; line   155
; line   156
; line   157
; line   158
; line   159
; line   160
; line   162
; line   166
; line   208
; line   209
; line   211
; line   212
; line   213
; line   214
; line   215
; line   216
; line   217
; line   218
; line   219
; line   220
; line   221
; line   222
; line    42
; line    47
; line    48
; line   306
; line   308
; line   310
; line   311
; line   312
; line   314
; line   315
; line   319
; line   320
; line   321
; line   325
; line   326
; line   327
; line   330
; line   331
; line   335
; line   337
; line   338
; line   339
; line   340
; line   341
; line   343
; line   345
; line   347
; line   348
; line   349
; line   350
; line   351
; line    13
; line    14
; line    13
; line    14
; line    15
; line    17
; line    18
; line    19
; line    20
; line    21
; line    22
; line    23
; line    24
; line    25
; line    26
; line    27
; line    29
; line    30
; line    31
; line    32
; line    33
; line    34
; line    35
; line    36
; line    37
; line    39
; line    40
; line    41
; line    42
; line    43
; line    44
; line    45
; line    46
; line    47
; line    20
; line    25
; line    29
; line    30
; line    31
; line    32
; line    33
; line    34
; line    35
; line    36
; line    37
; line    38
; line    39
; line    40
; line    41
; line    42
; line    43
; line    45
; line    46
; line    51
; line    52
; line    54
; line    59
; line    60
; line    65
; line    66
; line    67
; line    68
; line    70
; line    71
; line    72
; line    73
; line    74
; line    75
; line    76
; line    78
; line    83
; line    84
; line    89
; line    90
; line    92
; line    93
; line    94
; line    95
; line    96
; line    97
; line    98
; line   100
; line   105
; line   106
; line   111
; line   112
; line    16
; line    18
; line    19
; line    20
; line    21
; line    22
; line    23
; line    24
; line    25
; line    26
; line    27
; line    28
; line    29
; line    30
; line    31
; line    32
; line    33
; line    35
; line    37
; line    38
; line    39
; line    40
; line    43
; line    45
; line    46
; line    47
; line    48
; line    49
; line    50
; line    51
; line    52
; line    53
; line    54
; line    55
; line    56
; line    57
; line    58
; line    59
; line    60
; line    62
; line    64
; line    65
; line    66
; line    69
; line    71
; line    72
; line    73
; line    74
; line    75
; line    76
; line    77
; line    78
; line    79
; line    80
; line    81
; line    82
; line    83
; line    84
; line    85
; line    86
; line    88
; line    90
; line    91
; line    92
; line    13
; line    21
; line    22
; line    23
; line    24
; line    25
; line    26
; line    27
; line    28
; line    29
; line    30
; line    31
; line    32
; line    33
; line    34
; line    35
; line    36
; line    37
; line    38
; line    39
; line    40
; line    41
; line    42
; line    43
; line    44
; line    45
; line    46
; line    47
; line    48
; line    49
; line    50
; line    51
; line    52
; line    53
; line    54
; line    55
; line    56
; line    57
; line    58
; line    59
; line    60
; line    61
; line    62
; line    63
; line    64
; line    65
; line    67
; line    68
; line    69
; line    70
; line    72
; line    73
; line    74
; line    75
; line    59

@@BASE	CSEG	BASE
_r_tau0_channel0_interrupt:
$DGL	1,21
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
??bf_r_tau0_channel0_interrupt:
; line    61
$DGL	0,3
	call	!!_Timer_Base_Timer				;[INF] 4, 3
; line    63
$DGL	0,5
??ef_r_tau0_channel0_interrupt:
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
??ee_r_tau0_channel0_interrupt:

@@VECT2C	CSEG	AT    002CH
_@vect2c:
	DW	_r_tau0_channel0_interrupt

@@CODE	CSEG	BASE

@@CODEL	CSEG

@@FIX	DSEG	BASEP

@@DATA	DSEG	BASEP

	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\r_cg_timer_user.c
;
; $FUNC r_tau0_channel0_interrupt(59)
;	void=(void)
;	CODE SIZE= 62 bytes, CLOCK_SIZE= 49 clocks, STACK_SIZE= 26 bytes
;
; $CALL Timer_Base_Timer(61)
;	void=(void)

; Target chip : R5F100PG
; Device file : V1.14 
