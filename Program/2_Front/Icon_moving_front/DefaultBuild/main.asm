; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:57

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile Source\main.c -oDefaultBuild -_msgoff -nq -i
;             . -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no -g2
; In-file   : Source\main.c
; Asm-file  : DefaultBuild\main.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		05AH,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, main.c
$DGS	MOD_NAM, main,		00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	GLV_SYM, _MainLoop,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	054H,	01H,	00H
$DGS	BEG_FUN, ??bf_MainLoop,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0EH,		00H,	04AH
$DGS	BEG_BLK, ??bb00_MainLoop,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 010H,		00H,	04EH
$DGS	END_BLK, ??eb00_MainLoop,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 016H
$DGS	BEG_BLK, ??bb01_MainLoop,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 019H,		00H,	00H
$DGS	END_BLK, ??eb01_MainLoop,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02FH
$DGS	END_FUN, ??ef_MainLoop,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 030H
$DGS	GLV_SYM, _RamClear,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	05AH,	01H,	00H
$DGS	BEG_FUN, ??bf_RamClear,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 043H,		00H,	05AH
$DGS	END_FUN, ??ef_RamClear,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0BH
$DGS	GLV_SYM, _gu8_PWM_Count,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_OperationStep,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _F_CommunicationCMD,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerHWWait,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerBootDisplay,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerVersionDisplay,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _R_WDT_Restart,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _R_SAU1_Create,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _R_TAU0_Create,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _R_TAU0_Channel0_Start,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _R_UART2_Start,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _Timer_Process,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _InputControl,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _gu8_DigitalInput,	U,	U,	08H,	02H,	01H,	00H
$DGS	AUX_STR, 039H,		00H,	06H,	00H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _KeyDecide,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _Operation,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _CommunicationControl,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _ProcessVoice,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _Communication_Initialize,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _Display_Initialize,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _Input_Initialize,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _KeyControl_Initialize,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _Operation_Initialize,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _Safety_Initialize,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _Timer_Initialize,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _Output_Initialize,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _Initial_Voice,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H

	EXTRN	_R_WDT_Restart
	EXTRN	_R_SAU1_Create
	EXTRN	_R_TAU0_Create
	EXTRN	_R_TAU0_Channel0_Start
	EXTRN	_R_UART2_Start
	EXTRN	_Timer_Process
	EXTRN	_InputControl
	EXTRN	_gu8_DigitalInput
	EXTRN	_KeyDecide
	EXTRN	_Operation
	EXTRN	_CommunicationControl
	EXTRN	_ProcessVoice
	EXTRN	_Communication_Initialize
	EXTRN	_Display_Initialize
	EXTRN	_Input_Initialize
	EXTRN	_KeyControl_Initialize
	EXTRN	_Operation_Initialize
	EXTRN	_Safety_Initialize
	EXTRN	_Timer_Initialize
	EXTRN	_Output_Initialize
	EXTRN	_Initial_Voice
	PUBLIC	_gu8_PWM_Count
	PUBLIC	_gu8_OperationStep
	PUBLIC	_F_CommunicationCMD
	PUBLIC	_gu8_TimerHWWait
	PUBLIC	_gu8_TimerBootDisplay
	PUBLIC	_gu8_TimerVersionDisplay
	PUBLIC	_MainLoop
	PUBLIC	_RamClear

@@BITS	BSEG

@@CNST	CSEG	MIRRORP

@@R_INIT	CSEG	UNIT64KP

@@INIT	DSEG	BASEP

@@FIX	DSEG	BASEP
_gu8_PWM_Count:	DS	(1)
_gu8_OperationStep:	DS	(1)
_F_CommunicationCMD:	DS	(1)
	DS	(1)

@@DATA	DSEG	BASEP
_gu8_TimerHWWait:	DS	(1)
_gu8_TimerBootDisplay:	DS	(1)
_gu8_TimerVersionDisplay:	DS	(1)
	DS	(1)

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
; line    14

@@CODEL	CSEG
_MainLoop:
$DGL	1,70
??bf_MainLoop:
; line    15
$DGL	0,2
	call	!!_RamClear					;[INF] 4, 3
; line    17
$DGL	0,4
	call	!!_R_WDT_Restart				;[INF] 4, 3
; line    19
$DGL	0,6
	call	!!_R_SAU1_Create				;[INF] 4, 3
; line    20
$DGL	0,7
	call	!!_R_TAU0_Create				;[INF] 4, 3
; line    22
$DGL	0,9
	call	!!_R_TAU0_Channel0_Start			;[INF] 4, 3
; line    23
$DGL	0,10
	call	!!_R_UART2_Start				;[INF] 4, 3
; line    24
$DGL	0,11
	call	!!_R_WDT_Restart				;[INF] 4, 3
; line    26
$DGL	0,13
	mov	!_gu8_TimerHWWait,#032H	; 50 			;[INF] 4, 1
; line    28
$DGL	0,15
?L0003:
	cmp0	!_gu8_TimerHWWait				;[INF] 3, 1
	bz	$?L0004						;[INF] 2, 4
; line    29
??bb00_MainLoop:
; line    30
$DGL	0,17
	call	!!_R_WDT_Restart				;[INF] 4, 3
; line    32
$DGL	0,19
	call	!!_Timer_Process				;[INF] 4, 3
; line    34
$DGL	0,21
	call	!!_InputControl					;[INF] 4, 3
??eb00_MainLoop:
; line    35
$DGL	0,22
	br	$?L0003						;[INF] 2, 3
?L0004:
; line    37
?L0005:
; line    38
??bb01_MainLoop:
; line    39
$DGL	0,26
	call	!!_R_WDT_Restart				;[INF] 4, 3
; line    41
$DGL	0,28
	call	!!_Timer_Process				;[INF] 4, 3
; line    44
$DGL	0,31
	call	!!_InputControl					;[INF] 4, 3
; line    46
$DGL	0,33
	movw	ax,#loww (_gu8_DigitalInput)			;[INF] 3, 1
	call	!!_KeyDecide					;[INF] 4, 3
; line    49
$DGL	0,36
	call	!!_Operation					;[INF] 4, 3
; line    55
$DGL	0,42
	call	!!_CommunicationControl				;[INF] 4, 3
; line    59
$DGL	0,46
	call	!!_ProcessVoice					;[INF] 4, 3
??eb01_MainLoop:
; line    60
$DGL	0,47
	br	$?L0005						;[INF] 2, 3
?L0006:
; line    61
$DGL	0,48
??ef_MainLoop:
	ret							;[INF] 1, 6
??ee_MainLoop:
; line    67
_RamClear:
$DGL	1,84
??bf_RamClear:
; line    68
$DGL	0,2
	call	!!_Communication_Initialize			;[INF] 4, 3
; line    69
$DGL	0,3
	call	!!_Display_Initialize				;[INF] 4, 3
; line    70
$DGL	0,4
	call	!!_Input_Initialize				;[INF] 4, 3
; line    71
$DGL	0,5
	call	!!_KeyControl_Initialize			;[INF] 4, 3
; line    72
$DGL	0,6
	call	!!_Operation_Initialize				;[INF] 4, 3
; line    73
$DGL	0,7
	call	!!_Safety_Initialize				;[INF] 4, 3
; line    74
$DGL	0,8
	call	!!_Timer_Initialize				;[INF] 4, 3
; line    75
$DGL	0,9
	call	!!_Output_Initialize				;[INF] 4, 3
; line    76
$DGL	0,10
	call	!!_Initial_Voice				;[INF] 4, 3
; line    77
$DGL	0,11
??ef_RamClear:
	ret							;[INF] 1, 6
??ee_RamClear:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE
	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\Source\main.c
;
; $FUNC MainLoop(14)
;	void=(void)
;	CODE SIZE= 85 bytes, CLOCK_SIZE= 70 clocks, STACK_SIZE= 4 bytes
;
; $CALL RamClear(15)
;	void=(void)
;
; $CALL R_WDT_Restart(17)
;	void=(void)
;
; $CALL R_SAU1_Create(19)
;	void=(void)
;
; $CALL R_TAU0_Create(20)
;	void=(void)
;
; $CALL R_TAU0_Channel0_Start(22)
;	void=(void)
;
; $CALL R_UART2_Start(23)
;	void=(void)
;
; $CALL R_WDT_Restart(24)
;	void=(void)
;
; $CALL R_WDT_Restart(30)
;	void=(void)
;
; $CALL Timer_Process(32)
;	void=(void)
;
; $CALL InputControl(34)
;	void=(void)
;
; $CALL R_WDT_Restart(39)
;	void=(void)
;
; $CALL Timer_Process(41)
;	void=(void)
;
; $CALL InputControl(44)
;	void=(void)
;
; $CALL KeyDecide(46)
;	void=(pointer:ax)
;
; $CALL Operation(49)
;	void=(void)
;
; $CALL CommunicationControl(55)
;	void=(void)
;
; $CALL ProcessVoice(59)
;	void=(void)
;
; $FUNC RamClear(67)
;	void=(void)
;	CODE SIZE= 37 bytes, CLOCK_SIZE= 33 clocks, STACK_SIZE= 4 bytes
;
; $CALL Communication_Initialize(68)
;	void=(void)
;
; $CALL Display_Initialize(69)
;	void=(void)
;
; $CALL Input_Initialize(70)
;	void=(void)
;
; $CALL KeyControl_Initialize(71)
;	void=(void)
;
; $CALL Operation_Initialize(72)
;	void=(void)
;
; $CALL Safety_Initialize(73)
;	void=(void)
;
; $CALL Timer_Initialize(74)
;	void=(void)
;
; $CALL Output_Initialize(75)
;	void=(void)
;
; $CALL Initial_Voice(76)
;	void=(void)

; Target chip : R5F100PG
; Device file : V1.14 
