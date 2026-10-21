; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:56

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile Source\input.c -oDefaultBuild -_msgoff -nq -
;             i. -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no -g2
; In-file   : Source\input.c
; Asm-file  : DefaultBuild\input.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		065H,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, input.c
$DGS	MOD_NAM, input,		00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	STR_STR, .2fake,	00H,	0FFFEH,	08H,	0AH,	01H,	00H
$DGS	AUX_TAG, 01H,		028H
$DGS	BIT_FLD, _b0,		00H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b1,		01H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b2,		02H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b3,		03H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b4,		04H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b5,		05H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b6,		06H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b7,		07H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	END_STR, .eos,		01H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 014H,		01H
$DGS	STR_STR, .4fake,	00H,	0FFFEH,	08H,	0AH,	01H,	00H
$DGS	AUX_TAG, 01H,		030H
$DGS	BIT_FLD, _lo,		00H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		04H
$DGS	BIT_FLD, _hi,		04H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		04H
$DGS	END_STR, .eos,		01H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 028H,		01H
$DGS	UNI_TAG, .5fake,	00H,	0FFFEH,	09H,	0CH,	01H,	00H
$DGS	AUX_TAG, 01H,		039H
$DGS	MEB_UNI, _byte,		00H,	0FFFFH,	0CH,	0BH,	00H,	00H
$DGS	MEB_UNI, _Bit,		00H,	0FFFFH,	08H,	0BH,	01H,	00H
$DGS	AUX_STR, 014H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	MEB_UNI, _nibble,	00H,	0FFFFH,	08H,	0BH,	01H,	00H
$DGS	AUX_STR, 028H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	END_STR, .eos,		01H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 030H,		01H
$DGS	STR_STR, .13fake,	00H,	0FFFEH,	08H,	0AH,	01H,	00H
$DGS	AUX_TAG, 06H,		046H
$DGS	MEB_STR, _First,	00H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Second,	01H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Third,	02H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Level,	03H,	0FFFFH,	09H,	08H,	01H,	00H
$DGS	AUX_STR, 030H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	MEB_STR, _OnEdge,	04H,	0FFFFH,	09H,	08H,	01H,	00H
$DGS	AUX_STR, 030H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	MEB_STR, _OffEdge,	05H,	0FFFFH,	09H,	08H,	01H,	00H
$DGS	AUX_STR, 030H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	END_STR, .eos,		06H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 039H,		06H
$DGS	GLV_SYM, _Input_Initialize,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	04CH,	01H,	00H
$DGS	BEG_FUN, ??bf_Input_Initialize,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0DH,		00H,	04CH
$DGS	END_FUN, ??ef_Input_Initialize,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	GLV_SYM, _InputControl,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	05CH,	01H,	00H
$DGS	BEG_FUN, ??bf_InputControl,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 015H,		04H,	056H
$DGS	AUT_VAR, _mu8_inputdata,	03H,	0FFFFH,	09H,	01H,	01H,	00H
$DGS	AUX_STR, 030H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	AUT_VAR, _mu8_inputdata2,	02H,	0FFFFH,	09H,	01H,	01H,	00H
$DGS	AUX_STR, 030H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	AUT_VAR, _mu8_inputdata3,	01H,	0FFFFH,	09H,	01H,	01H,	00H
$DGS	AUX_STR, 030H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	BEG_BLK, ??bb00_InputControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0BH,		00H,	00H
$DGS	END_BLK, ??eb00_InputControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 022H
$DGS	END_FUN, ??ef_InputControl,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 023H
$DGS	GLV_SYM, _ThreeMatchModule,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	065H,	01H,	00H
$DGS	BEG_FUN, ??bf_ThreeMatchModule,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 03DH,		02H,	065H
$DGS	FUN_ARG, _p,		00H,	0FFFFH,	08H,	09H,	01H,	01H
$DGS	AUX_STR, 039H,		00H,	02H,	00H,	00H,	00H,	00H,	01H
$DGS	FUN_ARG, _data,		08H,	0FFFFH,	0CH,	09H,	00H,	00H
$DGS	END_FUN, ??ef_ThreeMatchModule,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 09H
$DGS	GLV_SYM, _gu8_DigitalInput,	U,	U,	08H,	026H,	01H,	00H
$DGS	AUX_STR, 039H,		00H,	06H,	00H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_DigitalInput2,	U,	U,	08H,	026H,	01H,	00H
$DGS	AUX_STR, 039H,		00H,	06H,	00H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_DigitalInput3,	U,	U,	08H,	026H,	01H,	00H
$DGS	AUX_STR, 039H,		00H,	06H,	00H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_Timer_LongSW,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Timer_ShortSW,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Timer_ProhibitSW,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_KeyOnBreak,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _F_10ms_for_InputDigital,	U,	U,	0100CH,	02H,	00H,	00H

	EXTRN	_F_10ms_for_InputDigital
	PUBLIC	_gu8_DigitalInput
	PUBLIC	_gu8_DigitalInput2
	PUBLIC	_gu8_DigitalInput3
	PUBLIC	_gu8_Timer_LongSW
	PUBLIC	_gu8_Timer_ShortSW
	PUBLIC	_gu8_Timer_ProhibitSW
	PUBLIC	_gu8_KeyOnBreak
	PUBLIC	_Input_Initialize
	PUBLIC	_InputControl
	PUBLIC	_ThreeMatchModule

@@BITS	BSEG

@@CNST	CSEG	MIRRORP

@@R_INIT	CSEG	UNIT64KP

@@INIT	DSEG	BASEP

@@DATA	DSEG	BASEP
_gu8_DigitalInput:	DS	(6)
_gu8_DigitalInput2:	DS	(6)
_gu8_DigitalInput3:	DS	(6)
_gu8_Timer_LongSW:	DS	(1)
_gu8_Timer_ShortSW:	DS	(1)
_gu8_Timer_ProhibitSW:	DS	(1)
_gu8_KeyOnBreak:	DS	(1)

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
; line    13

@@CODEL	CSEG
_Input_Initialize:
$DGL	1,70
??bf_Input_Initialize:
; line    15
$DGL	0,3
??ef_Input_Initialize:
	ret							;[INF] 1, 6
??ee_Input_Initialize:
; line    21
_InputControl:
$DGL	1,76
	push	hl						;[INF] 1, 1
	subw	sp,#04H						;[INF] 2, 1
	movw	hl,sp						;[INF] 3, 1
??bf_InputControl:
; line    26
$DGL	0,6
	mov	[hl+3],#00H	; mu8_inputdata,0 		;[INF] 3, 1
; line    27
$DGL	0,7
	mov	[hl+2],#00H	; mu8_inputdata2,0 		;[INF] 3, 1
; line    28
$DGL	0,8
	mov	[hl+1],#00H	; mu8_inputdata3,0 		;[INF] 3, 1
; line    30
$DGL	0,10
	cmp	!_F_10ms_for_InputDigital,#01H	; 1 		;[INF] 4, 1
	bnz	$?L0005						;[INF] 2, 4
; line    31
??bb00_InputControl:
; line    32
$DGL	0,12
	clrb	!_F_10ms_for_InputDigital			;[INF] 3, 1
; line    35
$DGL	0,15
	mov1	CY,P12.1					;[INF] 3, 1
	onew	ax						;[INF] 1, 1
	subc	x,a						;[INF] 2, 1
	mov	a,x						;[INF] 1, 1
	mov1	CY,a.0						;[INF] 2, 1
	mov	a,[hl+3]	; mu8_inputdata 		;[INF] 2, 1
	mov1	a.0,CY						;[INF] 2, 1
	mov	[hl+3],a	; mu8_inputdata 		;[INF] 2, 1
; line    36
$DGL	0,16
	mov1	CY,P13.7					;[INF] 3, 1
	onew	ax						;[INF] 1, 1
	subc	x,a						;[INF] 2, 1
	mov	a,x						;[INF] 1, 1
	mov1	CY,a.0						;[INF] 2, 1
	mov	a,[hl+3]	; mu8_inputdata 		;[INF] 2, 1
	mov1	a.1,CY						;[INF] 2, 1
	mov	[hl+3],a	; mu8_inputdata 		;[INF] 2, 1
; line    37
$DGL	0,17
	mov1	CY,P12.2					;[INF] 3, 1
	onew	ax						;[INF] 1, 1
	subc	x,a						;[INF] 2, 1
	mov	a,x						;[INF] 1, 1
	mov1	CY,a.0						;[INF] 2, 1
	mov	a,[hl+3]	; mu8_inputdata 		;[INF] 2, 1
	mov1	a.2,CY						;[INF] 2, 1
	mov	[hl+3],a	; mu8_inputdata 		;[INF] 2, 1
; line    38
$DGL	0,18
	mov1	CY,P12.4					;[INF] 3, 1
	onew	ax						;[INF] 1, 1
	subc	x,a						;[INF] 2, 1
	mov	a,x						;[INF] 1, 1
	mov1	CY,a.0						;[INF] 2, 1
	mov	a,[hl+3]	; mu8_inputdata 		;[INF] 2, 1
	mov1	a.3,CY						;[INF] 2, 1
	mov	[hl+3],a	; mu8_inputdata 		;[INF] 2, 1
; line    41
$DGL	0,21
	shrw	ax,8						;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,#loww (_gu8_DigitalInput)			;[INF] 3, 1
	call	!!_ThreeMatchModule				;[INF] 4, 3
	pop	ax						;[INF] 1, 1
; line    44
$DGL	0,24
	mov1	CY,P2.1						;[INF] 3, 1
	mov	a,[hl+2]	; mu8_inputdata2 		;[INF] 2, 1
	mov1	a.0,CY						;[INF] 2, 1
	mov	[hl+2],a	; mu8_inputdata2 		;[INF] 2, 1
; line    46
$DGL	0,26
	shrw	ax,8						;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,#loww (_gu8_DigitalInput2)			;[INF] 3, 1
	call	!!_ThreeMatchModule				;[INF] 4, 3
	pop	ax						;[INF] 1, 1
; line    48
$DGL	0,28
	mov	[hl+3],#00H	; mu8_inputdata,0 		;[INF] 3, 1
; line    51
$DGL	0,31
	mov1	CY,P3.1						;[INF] 3, 1
	onew	ax						;[INF] 1, 1
	subc	x,a						;[INF] 2, 1
	mov	a,x						;[INF] 1, 1
	mov1	CY,a.0						;[INF] 2, 1
	incw	hl						;[INF] 1, 1
	mov1	[hl].0,CY					;[INF] 2, 2
	decw	hl						;[INF] 1, 1
; line    53
$DGL	0,33
	mov	a,[hl+1]	; mu8_inputdata3 		;[INF] 2, 1
	shrw	ax,8						;[INF] 2, 1
	push	ax						;[INF] 1, 1
	movw	ax,#loww (_gu8_DigitalInput3)			;[INF] 3, 1
	call	!!_ThreeMatchModule				;[INF] 4, 3
	pop	ax						;[INF] 1, 1
??eb00_InputControl:
; line    54
?L0005:
?L0006:
; line    55
$DGL	0,35
??ef_InputControl:
	addw	sp,#04H						;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_InputControl:
; line    61
_ThreeMatchModule:
$DGL	1,92
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_ThreeMatchModule:
; line    62
$DGL	0,2
	movw	ax,[hl]	; p 					;[INF] 1, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de+1]					;[INF] 2, 1
	mov	[de+2],a					;[INF] 2, 1
; line    63
$DGL	0,3
	movw	ax,[hl]	; p 					;[INF] 1, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de]						;[INF] 1, 1
	mov	[de+1],a					;[INF] 2, 1
; line    64
$DGL	0,4
	movw	ax,[hl]	; p 					;[INF] 1, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[hl+8]	; data 				;[INF] 2, 1
	mov	[de],a						;[INF] 1, 1
; line    66
$DGL	0,6
	movw	ax,[hl]	; p 					;[INF] 1, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de+3]					;[INF] 2, 1
	xor	a,#0FFH	; 255 					;[INF] 2, 1
	mov	x,#0FFH	; 255 					;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,[de]						;[INF] 1, 1
	and	c,a						;[INF] 2, 1
	mov	a,[de+1]					;[INF] 2, 1
	and	c,a						;[INF] 2, 1
	mov	a,[de+2]					;[INF] 2, 1
	and	c,a						;[INF] 2, 1
	mov	a,c						;[INF] 1, 1
	mov	[de+4],a					;[INF] 2, 1
; line    67
$DGL	0,7
	movw	ax,[hl]	; p 					;[INF] 1, 1
	movw	de,ax						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,0[bc]						;[INF] 3, 1
	xor	a,#0FFH	; 255 					;[INF] 2, 1
	mov	x,#0FFH	; 255 					;[INF] 2, 1
	mov	x,a						;[INF] 1, 1
	mov	a,[de+3]					;[INF] 2, 1
	and	a,x						;[INF] 2, 1
	mov	c,a						;[INF] 1, 1
	mov	a,[de+1]					;[INF] 2, 1
	xor	a,#0FFH	; 255 					;[INF] 2, 1
	mov	x,#0FFH	; 255 					;[INF] 2, 1
	and	c,a						;[INF] 2, 1
	mov	a,[de+2]					;[INF] 2, 1
	xor	a,#0FFH	; 255 					;[INF] 2, 1
	and	c,a						;[INF] 2, 1
	mov	a,c						;[INF] 1, 1
	mov	[de+5],a					;[INF] 2, 1
; line    68
$DGL	0,8
	movw	ax,[hl]	; p 					;[INF] 1, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de]						;[INF] 1, 1
	mov	c,a						;[INF] 1, 1
	mov	a,[de+1]					;[INF] 2, 1
	or	c,a						;[INF] 2, 1
	mov	a,[de+2]					;[INF] 2, 1
	or	c,a						;[INF] 2, 1
	mov	a,[de+3]					;[INF] 2, 1
	and	c,a						;[INF] 2, 1
	mov	a,[de+4]					;[INF] 2, 1
	or	c,a						;[INF] 2, 1
	mov	a,c						;[INF] 1, 1
	mov	[de+3],a					;[INF] 2, 1
; line    69
$DGL	0,9
??ef_ThreeMatchModule:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_ThreeMatchModule:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE

@@FIX	DSEG	BASEP

	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\Source\input.c
;
; $FUNC Input_Initialize(13)
;	void=(void)
;	CODE SIZE= 1 bytes, CLOCK_SIZE= 6 clocks, STACK_SIZE= 0 bytes
;
; $FUNC InputControl(21)
;	void=(void)
;	CODE SIZE= 148 bytes, CLOCK_SIZE= 88 clocks, STACK_SIZE= 12 bytes
;
; $CALL ThreeMatchModule(41)
;	void=(pointer:ax, int:[sp+4])
;
; $CALL ThreeMatchModule(46)
;	void=(pointer:ax, int:[sp+4])
;
; $CALL ThreeMatchModule(53)
;	void=(pointer:ax, int:[sp+4])
;
; $FUNC ThreeMatchModule(61)
;	void=(pointer p:ax, unsigned char data:[sp+4])
;	CODE SIZE= 104 bytes, CLOCK_SIZE= 71 clocks, STACK_SIZE= 4 bytes

; Target chip : R5F100PG
; Device file : V1.14 
