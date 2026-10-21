; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:58

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile Source\Voice_NXD1005.c -oDefaultBuild -_msgo
;             ff -nq -i. -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild
;              -no -g2
; In-file   : Source\Voice_NXD1005.c
; Asm-file  : DefaultBuild\Voice_NXD1005.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		094H,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, Voice_NXD1005.c
$DGS	MOD_NAM, Voice_NXD1005,	00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	GLV_SYM, _Initial_Voice,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	01AH,	01H,	00H
$DGS	BEG_FUN, ??bf_Initial_Voice,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 022H,		00H,	01AH
$DGS	END_FUN, ??ef_Initial_Voice,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 010H
$DGS	GLV_SYM, _SetVoiceLevel,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	025H,	01H,	00H
$DGS	BEG_FUN, ??bf_SetVoiceLevel,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 036H,		02H,	01FH
$DGS	FUN_ARG, _mu8Val,	00H,	0FFFFH,	0CH,	09H,	00H,	00H
$DGS	BEG_BLK, ??bb00_SetVoiceLevel,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 04H,		00H,	00H
$DGS	END_BLK, ??eb00_SetVoiceLevel,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	END_FUN, ??ef_SetVoiceLevel,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 07H
$DGS	GLV_SYM, _Get_Sound_Type,	U,	U,	0CH,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	02BH,	01H,	00H
$DGS	BEG_FUN, ??bf_Get_Sound_Type,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 041H,		00H,	02BH
$DGS	END_FUN, ??ef_Get_Sound_Type,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	GLV_SYM, _VoiceStop,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	031H,	01H,	00H
$DGS	BEG_FUN, ??bf_VoiceStop,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 049H,		00H,	031H
$DGS	END_FUN, ??ef_VoiceStop,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	GLV_SYM, _Play_Voice,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	038H,	01H,	00H
$DGS	BEG_FUN, ??bf_Play_Voice,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 052H,		02H,	038H
$DGS	FUN_ARG, _mu16MemoryAddress,	00H,	0FFFFH,	0EH,	09H,	00H,	00H
$DGS	END_FUN, ??ef_Play_Voice,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	GLV_SYM, _ProcessVoice,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	06EH,	01H,	00H
$DGS	BEG_FUN, ??bf_ProcessVoice,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 05CH,		00H,	03CH
$DGS	BEG_BLK, ??bb00_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	040H
$DGS	END_BLK, ??eb00_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0BH
$DGS	BEG_BLK, ??bb01_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 010H,		00H,	042H
$DGS	BEG_BLK, ??bb02_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 057H,		00H,	046H
$DGS	END_BLK, ??eb02_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05EH
$DGS	BEG_BLK, ??bb03_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 061H,		00H,	04AH
$DGS	END_BLK, ??eb03_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 068H
$DGS	BEG_BLK, ??bb04_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 06DH,		00H,	04EH
$DGS	END_BLK, ??eb04_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 074H
$DGS	BEG_BLK, ??bb05_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 077H,		00H,	052H
$DGS	END_BLK, ??eb05_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 07EH
$DGS	BEG_BLK, ??bb06_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 081H,		00H,	056H
$DGS	END_BLK, ??eb06_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 088H
$DGS	BEG_BLK, ??bb07_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 08BH,		00H,	05AH
$DGS	END_BLK, ??eb07_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 092H
$DGS	BEG_BLK, ??bb08_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 095H,		00H,	05EH
$DGS	END_BLK, ??eb08_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 09CH
$DGS	BEG_BLK, ??bb09_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09FH,		00H,	062H
$DGS	END_BLK, ??eb09_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0A6H
$DGS	BEG_BLK, ??bb0A_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0A8H,		00H,	068H
$DGS	END_BLK, ??eb0A_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0AAH
$DGS	END_BLK, ??eb01_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0ACH
$DGS	BEG_BLK, ??bb0B_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0B0H,		00H,	00H
$DGS	END_BLK, ??eb0B_ProcessVoice,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0B3H
$DGS	END_FUN, ??ef_ProcessVoice,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0B9H
$DGS	GLV_SYM, _SEND_SPI_COMMAND,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	089H,	01H,	00H
$DGS	BEG_FUN, ??bf_SEND_SPI_COMMAND,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 011AH,		02H,	073H
$DGS	AUT_VAR, _i,		00H,	0FFFFH,	04H,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_SEND_SPI_COMMAND,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 011H,		00H,	075H
$DGS	BEG_BLK, ??bb01_SEND_SPI_COMMAND,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 017H,		00H,	079H
$DGS	END_BLK, ??eb01_SEND_SPI_COMMAND,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 019H
$DGS	BEG_BLK, ??bb02_SEND_SPI_COMMAND,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01BH,		00H,	07DH
$DGS	END_BLK, ??eb02_SEND_SPI_COMMAND,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 01DH
$DGS	BEG_BLK, ??bb03_SEND_SPI_COMMAND,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 027H,		00H,	081H
$DGS	END_BLK, ??eb03_SEND_SPI_COMMAND,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 029H
$DGS	BEG_BLK, ??bb04_SEND_SPI_COMMAND,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 02BH,		00H,	00H
$DGS	END_BLK, ??eb04_SEND_SPI_COMMAND,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02DH
$DGS	END_BLK, ??eb00_SEND_SPI_COMMAND,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02EH
$DGS	END_FUN, ??ef_SEND_SPI_COMMAND,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 036H
$DGS	GLV_SYM, _Delay,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	094H,	01H,	00H
$DGS	BEG_FUN, ??bf_Delay,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0155H,		02H,	08EH
$DGS	FUN_ARG, _mu8Time,	00H,	0FFFFH,	0EH,	09H,	00H,	00H
$DGS	BEG_BLK, ??bb00_Delay,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	00H
$DGS	END_BLK, ??eb00_Delay,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02DH
$DGS	END_FUN, ??ef_Delay,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 02EH
$DGS	GLV_SYM, _COMMAND,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Sound_Type,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8PlayVoice_Count,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_VoiceVolumeLevel,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8Voice_Actor,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_Voice_Address,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16VoiceDelay,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _F_OneMoreSound,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _F_Beep_Sound,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _F_PlayVoice,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_F_Voice_Play_ForCommu,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_Voice_Address_ForCommu,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Voice_VolumeLevel_ForCommu,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_VoiceTestttt,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu32_Count_VoiceTest,	U,	U,	0FH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16VoiceVolumeRegList,	U,	U,	0EH,	026H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	0AH,	05H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu16BeepVolumeRegList,	U,	U,	0EH,	026H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	0AH,	05H,	00H,	00H,	00H,	00H

	PUBLIC	_COMMAND
	PUBLIC	_gu8_Sound_Type
	PUBLIC	_gu8PlayVoice_Count
	PUBLIC	_gu8_VoiceVolumeLevel
	PUBLIC	_gu8Voice_Actor
	PUBLIC	_gu16_Voice_Address
	PUBLIC	_gu16VoiceDelay
	PUBLIC	_F_OneMoreSound
	PUBLIC	_F_Beep_Sound
	PUBLIC	_F_PlayVoice
	PUBLIC	_gu8_F_Voice_Play_ForCommu
	PUBLIC	_gu16_Voice_Address_ForCommu
	PUBLIC	_gu8_Voice_VolumeLevel_ForCommu
	PUBLIC	_gu8_VoiceTestttt
	PUBLIC	_gu32_Count_VoiceTest
	PUBLIC	_gu16VoiceVolumeRegList
	PUBLIC	_gu16BeepVolumeRegList
	PUBLIC	_Initial_Voice
	PUBLIC	_SetVoiceLevel
	PUBLIC	_Get_Sound_Type
	PUBLIC	_VoiceStop
	PUBLIC	_Play_Voice
	PUBLIC	_ProcessVoice
	PUBLIC	_SEND_SPI_COMMAND
	PUBLIC	_Delay

@@BITS	BSEG

@@CNST	CSEG	MIRRORP

@@R_INIT	CSEG	UNIT64KP
	DW	02AH	; 42
	DW	027H	; 39
	DW	024H	; 36
	DW	021H	; 33
	DW	01FH	; 31
	DW	036H	; 54
	DW	030H	; 48
	DW	02AH	; 42
	DW	024H	; 36
	DW	01FH	; 31

@@INIT	DSEG	BASEP
_gu16VoiceVolumeRegList:	DS	(10)
_gu16BeepVolumeRegList:	DS	(10)

@@DATA	DSEG	BASEP
_COMMAND:	DS	(2)
_gu8_Sound_Type:	DS	(1)
_gu8PlayVoice_Count:	DS	(1)
_gu8_VoiceVolumeLevel:	DS	(1)
_gu8Voice_Actor:	DS	(1)
_gu16_Voice_Address:	DS	(2)
_gu16VoiceDelay:	DS	(2)
_F_OneMoreSound:	DS	(1)
_F_Beep_Sound:	DS	(1)
_F_PlayVoice:	DS	(1)
_gu8_F_Voice_Play_ForCommu:	DS	(1)
_gu16_Voice_Address_ForCommu:	DS	(2)
_gu8_Voice_VolumeLevel_ForCommu:	DS	(1)
_gu8_VoiceTestttt:	DS	(1)
_gu32_Count_VoiceTest:	DS	(4)

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
; line     8
; line     9
; line    10
; line    15
; line    17
; line    18
; line    19
; line    20
; line    21
; line    22
; line    24
; line    25
; line    26
; line    27
; line    28
; line    34

@@CODEL	CSEG
_Initial_Voice:
$DGL	1,20
??bf_Initial_Voice:
; line    36
$DGL	0,3
	movw	ax,#0190H	; 400 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line    37
$DGL	0,4
	clr1	P0.1						;[INF] 3, 2
; line    39
$DGL	0,6
	movw	ax,#0EA60H	; -5536 			;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line    40
$DGL	0,7
	set1	P0.1						;[INF] 3, 2
; line    43
$DGL	0,10
	movw	ax,#0E260H	; -7584 			;[INF] 3, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line    44
$DGL	0,11
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
; line    47
$DGL	0,14
	movw	ax,#0E305H	; -7419 			;[INF] 3, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line    48
$DGL	0,15
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
; line    49
$DGL	0,16
??ef_Initial_Voice:
	ret							;[INF] 1, 6
??ee_Initial_Voice:
; line    54
_SetVoiceLevel:
$DGL	1,26
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_SetVoiceLevel:
; line    55
$DGL	0,2
	mov	a,[hl]	; mu8Val 				;[INF] 1, 1
	mov	!_gu8_Sound_Type,a				;[INF] 3, 1
; line    56
$DGL	0,3
	cmp0	!_gu8_Sound_Type				;[INF] 3, 1
	sknz							;[INF] 2, 1
; line    57
??bb00_SetVoiceLevel:
; line    58
$DGL	0,5
	oneb	!_F_OneMoreSound				;[INF] 3, 1
??eb00_SetVoiceLevel:
; line    59
?L0005:
?L0006:
; line    60
$DGL	0,7
??ef_SetVoiceLevel:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_SetVoiceLevel:
; line    65
_Get_Sound_Type:
$DGL	1,37
??bf_Get_Sound_Type:
; line    66
$DGL	0,2
	mov	x,!_gu8_Sound_Type				;[INF] 3, 1
	clrb	a						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
; line    67
?L0008:
; line    67
$DGL	0,3
??ef_Get_Sound_Type:
	ret							;[INF] 1, 6
??ee_Get_Sound_Type:
; line    73
_VoiceStop:
$DGL	1,43
??bf_VoiceStop:
; line    74
$DGL	0,2
	movw	ax,#0E210H	; -7664 			;[INF] 3, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line    75
$DGL	0,3
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
; line    76
$DGL	0,4
??ef_VoiceStop:
	ret							;[INF] 1, 6
??ee_VoiceStop:
; line    82
_Play_Voice:
$DGL	1,49
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_Play_Voice:
; line    83
$DGL	0,2
	oneb	!_F_PlayVoice					;[INF] 3, 1
; line    84
$DGL	0,3
	movw	ax,[hl]	; mu16MemoryAddress 			;[INF] 1, 1
	movw	!_gu16_Voice_Address,ax				;[INF] 3, 1
; line    85
$DGL	0,4
	call	!!_VoiceStop					;[INF] 4, 3
; line    86
$DGL	0,5
??ef_Play_Voice:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_Play_Voice:
; line    92
_ProcessVoice:
$DGL	1,56
??bf_ProcessVoice:
; line    99
$DGL	0,8
	cmp	!_gu8_VoiceTestttt,#01H	; 1 			;[INF] 4, 1
	sknz							;[INF] 2, 1
; line   100
??bb00_ProcessVoice:
; line   101
$DGL	0,10
	br	$!?L0014					;[INF] 3, 3
??eb00_ProcessVoice:
; line   102
?L0015:
?L0016:
; line   106
$DGL	0,15
	cmp0	!_F_PlayVoice					;[INF] 3, 1
	sknz							;[INF] 2, 1
	br	$!?L0017					;[INF] 3, 3
; line   107
??bb01_ProcessVoice:
; line   164
$DGL	0,73
	mov	x,!_gu8_VoiceVolumeLevel			;[INF] 3, 1
	clrb	a						;[INF] 1, 1
	addw	ax,ax						;[INF] 1, 1
	addw	ax,#loww (_gu16BeepVolumeRegList)		;[INF] 3, 1
	movw	de,ax						;[INF] 1, 1
	movw	ax,[de]						;[INF] 1, 1
	add	a,#0E1H	; 225 					;[INF] 2, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   166
$DGL	0,75
	clrb	!_F_PlayVoice					;[INF] 3, 1
; line   168
$DGL	0,77
	movw	ax,#0190H	; 400 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   170
$DGL	0,79
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
; line   171
$DGL	0,80
	movw	ax,#0190H	; 400 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   177
$DGL	0,86
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	cmpw	ax,#0100H	; 256 				;[INF] 3, 1
	bnc	$?L0019						;[INF] 2, 4
; line   178
??bb02_ProcessVoice:
; line   179
$DGL	0,88
	movw	ax,#0E400H	; -7168 			;[INF] 3, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   180
$DGL	0,89
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
; line   182
$DGL	0,91
	movw	ax,#0190H	; 400 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   183
$DGL	0,92
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	add	a,#0E0H	; 224 					;[INF] 2, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   184
$DGL	0,93
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
??eb02_ProcessVoice:
; line   187
$DGL	0,96
	br	$!?L0020					;[INF] 3, 3
?L0019:
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	cmpw	ax,#0200H	; 512 				;[INF] 3, 1
	bnc	$?L0021						;[INF] 2, 4
; line   188
??bb03_ProcessVoice:
; line   189
$DGL	0,98
	movw	ax,#0E401H	; -7167 			;[INF] 3, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   190
$DGL	0,99
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
; line   192
$DGL	0,101
	movw	ax,#0190H	; 400 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   193
$DGL	0,102
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	dec	a						;[INF] 1, 1
	add	a,#0E0H	; 224 					;[INF] 2, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   194
$DGL	0,103
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
??eb03_ProcessVoice:
; line   199
$DGL	0,108
	br	$!?L0022					;[INF] 3, 3
?L0021:
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	cmpw	ax,#0300H	; 768 				;[INF] 3, 1
	bnc	$?L0023						;[INF] 2, 4
; line   200
??bb04_ProcessVoice:
; line   201
$DGL	0,110
	movw	ax,#0E402H	; -7166 			;[INF] 3, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   202
$DGL	0,111
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
; line   204
$DGL	0,113
	movw	ax,#0190H	; 400 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   205
$DGL	0,114
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	sub	a,#022H	; 34 					;[INF] 2, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   206
$DGL	0,115
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
??eb04_ProcessVoice:
; line   209
$DGL	0,118
	br	$!?L0024					;[INF] 3, 3
?L0023:
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	cmpw	ax,#0400H	; 1024 				;[INF] 3, 1
	bnc	$?L0025						;[INF] 2, 4
; line   210
??bb05_ProcessVoice:
; line   211
$DGL	0,120
	movw	ax,#0E403H	; -7165 			;[INF] 3, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   212
$DGL	0,121
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
; line   214
$DGL	0,123
	movw	ax,#0190H	; 400 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   215
$DGL	0,124
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	sub	a,#023H	; 35 					;[INF] 2, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   216
$DGL	0,125
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
??eb05_ProcessVoice:
; line   219
$DGL	0,128
	br	$!?L0026					;[INF] 3, 3
?L0025:
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	cmpw	ax,#0500H	; 1280 				;[INF] 3, 1
	bnc	$?L0027						;[INF] 2, 4
; line   220
??bb06_ProcessVoice:
; line   221
$DGL	0,130
	movw	ax,#0E404H	; -7164 			;[INF] 3, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   222
$DGL	0,131
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
; line   224
$DGL	0,133
	movw	ax,#0190H	; 400 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   225
$DGL	0,134
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	sub	a,#024H	; 36 					;[INF] 2, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   226
$DGL	0,135
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
??eb06_ProcessVoice:
; line   229
$DGL	0,138
	br	$?L0028						;[INF] 2, 3
?L0027:
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	cmpw	ax,#0600H	; 1536 				;[INF] 3, 1
	bnc	$?L0029						;[INF] 2, 4
; line   230
??bb07_ProcessVoice:
; line   231
$DGL	0,140
	movw	ax,#0E405H	; -7163 			;[INF] 3, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   232
$DGL	0,141
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
; line   234
$DGL	0,143
	movw	ax,#0190H	; 400 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   235
$DGL	0,144
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	sub	a,#025H	; 37 					;[INF] 2, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   236
$DGL	0,145
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
??eb07_ProcessVoice:
; line   239
$DGL	0,148
	br	$?L0030						;[INF] 2, 3
?L0029:
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	cmpw	ax,#0700H	; 1792 				;[INF] 3, 1
	bnc	$?L0031						;[INF] 2, 4
; line   240
??bb08_ProcessVoice:
; line   241
$DGL	0,150
	movw	ax,#0E406H	; -7162 			;[INF] 3, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   242
$DGL	0,151
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
; line   244
$DGL	0,153
	movw	ax,#0190H	; 400 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   245
$DGL	0,154
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	sub	a,#026H	; 38 					;[INF] 2, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   246
$DGL	0,155
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
??eb08_ProcessVoice:
; line   249
$DGL	0,158
	br	$?L0032						;[INF] 2, 3
?L0031:
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	cmpw	ax,#0800H	; 2048 				;[INF] 3, 1
	bnc	$?L0033						;[INF] 2, 4
; line   250
??bb09_ProcessVoice:
; line   251
$DGL	0,160
	movw	ax,#0E407H	; -7161 			;[INF] 3, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   252
$DGL	0,161
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
; line   254
$DGL	0,163
	movw	ax,#0190H	; 400 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   255
$DGL	0,164
	movw	ax,!_gu16_Voice_Address				;[INF] 3, 1
	sub	a,#027H	; 39 					;[INF] 2, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   256
$DGL	0,165
	call	!!_SEND_SPI_COMMAND				;[INF] 4, 3
??eb09_ProcessVoice:
; line   258
?L0033:
; line   259
??bb0A_ProcessVoice:
??eb0A_ProcessVoice:
; line   261
?L0034:
?L0032:
?L0030:
?L0028:
?L0026:
?L0024:
?L0022:
?L0020:
??eb01_ProcessVoice:
; line   266
$DGL	0,175
	br	$?L0018						;[INF] 2, 3
?L0017:
; line   267
??bb0B_ProcessVoice:
; line   269
$DGL	0,178
	oneb	!_gu8PlayVoice_Count				;[INF] 3, 1
??eb0B_ProcessVoice:
; line   270
?L0018:
; line   272
$DGL	0,181
	clrb	!_F_Beep_Sound					;[INF] 3, 1
; line   276
?L0014:
; line   276
$DGL	0,185
??ef_ProcessVoice:
	ret							;[INF] 1, 6
??ee_ProcessVoice:
; line   282
_SEND_SPI_COMMAND:
$DGL	1,110
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_SEND_SPI_COMMAND:
; line   283
$DGL	0,2
	clrw	ax						;[INF] 1, 1
	movw	[hl],ax	; i 					;[INF] 1, 1
; line   285
$DGL	0,4
	clr1	P0.2						;[INF] 3, 2
; line   291
$DGL	0,10
	movw	ax,#05DC0H	; 24000 			;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   294
$DGL	0,13
	clr1	P0.4						;[INF] 3, 2
; line   297
$DGL	0,16
?L0037:
	movw	ax,[hl]	; i 					;[INF] 1, 1
	cmpw	ax,#010H	; 16 				;[INF] 3, 1
	or1	CY,a.7						;[INF] 2, 1
	bnc	$?L0038						;[INF] 2, 4
; line   298
??bb00_SEND_SPI_COMMAND:
; line   299
$DGL	0,18
	clr1	P0.4						;[INF] 3, 2
; line   301
$DGL	0,20
	movw	ax,#0A0H	; 160 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   303
$DGL	0,22
	movw	ax,!_COMMAND					;[INF] 3, 1
	and	a,#080H	; 128 					;[INF] 2, 1
	clrb	x						;[INF] 1, 1
	or	a,x						;[INF] 2, 1
	bz	$?L0039						;[INF] 2, 4
; line   304
??bb01_SEND_SPI_COMMAND:
; line   305
$DGL	0,24
	set1	P0.3						;[INF] 3, 2
??eb01_SEND_SPI_COMMAND:
; line   307
$DGL	0,26
	br	$?L0040						;[INF] 2, 3
?L0039:
; line   308
??bb02_SEND_SPI_COMMAND:
; line   309
$DGL	0,28
	clr1	P0.3						;[INF] 3, 2
??eb02_SEND_SPI_COMMAND:
; line   310
?L0040:
; line   312
$DGL	0,31
	movw	ax,!_COMMAND					;[INF] 3, 1
	addw	ax,ax						;[INF] 1, 1
	movw	!_COMMAND,ax					;[INF] 3, 1
; line   314
$DGL	0,33
	movw	ax,#0A0H	; 160 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   316
$DGL	0,35
	set1	P0.4						;[INF] 3, 2
; line   317
$DGL	0,36
	incw	[hl+0]	; i 					;[INF] 3, 2
; line   319
$DGL	0,38
	movw	ax,#08H	; 8 					;[INF] 3, 1
	cmpw	ax,[hl+0]	; i 				;[INF] 3, 1
	bnz	$?L0041						;[INF] 2, 4
; line   320
??bb03_SEND_SPI_COMMAND:
; line   321
$DGL	0,40
	movw	ax,#0280H	; 640 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
??eb03_SEND_SPI_COMMAND:
; line   323
$DGL	0,42
	br	$?L0042						;[INF] 2, 3
?L0041:
; line   324
??bb04_SEND_SPI_COMMAND:
; line   325
$DGL	0,44
	movw	ax,#0140H	; 320 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
??eb04_SEND_SPI_COMMAND:
; line   326
?L0042:
??eb00_SEND_SPI_COMMAND:
; line   327
$DGL	0,46
	br	$?L0037						;[INF] 2, 3
?L0038:
; line   329
$DGL	0,48
	clr1	P0.3						;[INF] 3, 2
; line   330
$DGL	0,49
	movw	ax,#08H	; 8 					;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   332
$DGL	0,51
	set1	P0.2						;[INF] 3, 2
; line   334
$DGL	0,53
	movw	ax,#0140H	; 320 				;[INF] 3, 1
	call	!!_Delay					;[INF] 4, 3
; line   335
$DGL	0,54
??ef_SEND_SPI_COMMAND:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_SEND_SPI_COMMAND:
; line   341
_Delay:
$DGL	1,137
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_Delay:
; line   342
$DGL	0,2
?L0045:
	movw	ax,[hl]	; mu8Time 				;[INF] 1, 1
	decw	ax						;[INF] 1, 1
	movw	[hl],ax	; mu8Time 				;[INF] 1, 1
	or	a,x						;[INF] 2, 1
	bz	$?L0046						;[INF] 2, 4
; line   343
??bb00_Delay:
; line   344
$DGL	0,4
	nop							;[INF] 1, 1
??eb00_Delay:
; line   385
$DGL	0,45
	br	$?L0045						;[INF] 2, 3
?L0046:
; line   386
$DGL	0,46
??ef_Delay:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_Delay:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE

@@FIX	DSEG	BASEP

	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\Source\Voice_NXD1005.c
;
; $FUNC Initial_Voice(34)
;	void=(void)
;	CODE SIZE= 41 bytes, CLOCK_SIZE= 28 clocks, STACK_SIZE= 4 bytes
;
; $CALL Delay(36)
;	void=(unsigned int:ax)
;
; $CALL Delay(39)
;	void=(unsigned int:ax)
;
; $CALL SEND_SPI_COMMAND(44)
;	void=(void)
;
; $CALL SEND_SPI_COMMAND(48)
;	void=(void)
;
; $FUNC SetVoiceLevel(54)
;	void=(unsigned char mu8Val:x)
;	CODE SIZE= 20 bytes, CLOCK_SIZE= 16 clocks, STACK_SIZE= 4 bytes
;
; $FUNC Get_Sound_Type(65)
;	bc=(void)
;	CODE SIZE= 6 bytes, CLOCK_SIZE= 9 clocks, STACK_SIZE= 0 bytes
;
; $FUNC VoiceStop(73)
;	void=(void)
;	CODE SIZE= 11 bytes, CLOCK_SIZE= 11 clocks, STACK_SIZE= 4 bytes
;
; $CALL SEND_SPI_COMMAND(75)
;	void=(void)
;
; $FUNC Play_Voice(82)
;	void=(unsigned int mu16MemoryAddress:ax)
;	CODE SIZE= 19 bytes, CLOCK_SIZE= 17 clocks, STACK_SIZE= 8 bytes
;
; $CALL VoiceStop(85)
;	void=(void)
;
; $FUNC ProcessVoice(92)
;	void=(void)
;	CODE SIZE= 377 bytes, CLOCK_SIZE= 231 clocks, STACK_SIZE= 4 bytes
;
; $CALL Delay(168)
;	void=(unsigned int:ax)
;
; $CALL SEND_SPI_COMMAND(170)
;	void=(void)
;
; $CALL Delay(171)
;	void=(unsigned int:ax)
;
; $CALL SEND_SPI_COMMAND(180)
;	void=(void)
;
; $CALL Delay(182)
;	void=(unsigned int:ax)
;
; $CALL SEND_SPI_COMMAND(184)
;	void=(void)
;
; $CALL SEND_SPI_COMMAND(190)
;	void=(void)
;
; $CALL Delay(192)
;	void=(unsigned int:ax)
;
; $CALL SEND_SPI_COMMAND(194)
;	void=(void)
;
; $CALL SEND_SPI_COMMAND(202)
;	void=(void)
;
; $CALL Delay(204)
;	void=(unsigned int:ax)
;
; $CALL SEND_SPI_COMMAND(206)
;	void=(void)
;
; $CALL SEND_SPI_COMMAND(212)
;	void=(void)
;
; $CALL Delay(214)
;	void=(unsigned int:ax)
;
; $CALL SEND_SPI_COMMAND(216)
;	void=(void)
;
; $CALL SEND_SPI_COMMAND(222)
;	void=(void)
;
; $CALL Delay(224)
;	void=(unsigned int:ax)
;
; $CALL SEND_SPI_COMMAND(226)
;	void=(void)
;
; $CALL SEND_SPI_COMMAND(232)
;	void=(void)
;
; $CALL Delay(234)
;	void=(unsigned int:ax)
;
; $CALL SEND_SPI_COMMAND(236)
;	void=(void)
;
; $CALL SEND_SPI_COMMAND(242)
;	void=(void)
;
; $CALL Delay(244)
;	void=(unsigned int:ax)
;
; $CALL SEND_SPI_COMMAND(246)
;	void=(void)
;
; $CALL SEND_SPI_COMMAND(252)
;	void=(void)
;
; $CALL Delay(254)
;	void=(unsigned int:ax)
;
; $CALL SEND_SPI_COMMAND(256)
;	void=(void)
;
; $FUNC SEND_SPI_COMMAND(282)
;	void=(void)
;	CODE SIZE= 125 bytes, CLOCK_SIZE= 92 clocks, STACK_SIZE= 8 bytes
;
; $CALL Delay(291)
;	void=(unsigned int:ax)
;
; $CALL Delay(301)
;	void=(unsigned int:ax)
;
; $CALL Delay(314)
;	void=(unsigned int:ax)
;
; $CALL Delay(321)
;	void=(unsigned int:ax)
;
; $CALL Delay(325)
;	void=(unsigned int:ax)
;
; $CALL Delay(330)
;	void=(unsigned int:ax)
;
; $CALL Delay(334)
;	void=(unsigned int:ax)
;
; $FUNC Delay(341)
;	void=(unsigned int mu8Time:ax)
;	CODE SIZE= 18 bytes, CLOCK_SIZE= 23 clocks, STACK_SIZE= 4 bytes

; Target chip : R5F100PG
; Device file : V1.14 
