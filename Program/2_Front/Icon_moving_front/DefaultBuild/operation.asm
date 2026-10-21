; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:57

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile Source\operation.c -oDefaultBuild -_msgoff -
;             nq -i. -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no
;              -g2
; In-file   : Source\operation.c
; Asm-file  : DefaultBuild\operation.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		0A9H,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, operation.c
$DGS	MOD_NAM, operation,	00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	STR_STR, .18fake,	00H,	0FFFEH,	08H,	0AH,	01H,	00H
$DGS	AUX_TAG, 08H,		020H
$DGS	MEB_STR, _LED_Title,	00H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Operation_CMD,	01H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Display_CMD_Before,	02H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Display_CMD,	03H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Fade_PWM,	04H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Fade_PWM_Target,	05H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Fade_Timer,	06H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Fade_Timer_Target,	07H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	END_STR, .eos,		08H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 014H,		08H
$DGS	STR_STR, .17fake,	00H,	0FFFEH,	08H,	0AH,	01H,	00H
$DGS	AUX_TAG, 06H,		028H
$DGS	MEB_STR, _stepno,	00H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Display_CMD,	01H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _exe,		02H,	0FFFFH,	01H,	08H,	01H,	09H
$DGS	AUX_STR, 00H,		00H,	04H,	00H,	00H,	00H,	00H,	02H
$DGS	END_STR, .eos,		06H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 020H,		06H
$DGS	GLV_SYM, _Operation_Initialize,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	02EH,	01H,	00H
$DGS	BEG_FUN, ??bf_Operation_Initialize,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 024H,		00H,	02EH
$DGS	END_FUN, ??ef_Operation_Initialize,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	GLV_SYM, _Operation,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	03CH,	01H,	00H
$DGS	BEG_FUN, ??bf_Operation,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 02CH,		00H,	032H
$DGS	BEG_BLK, ??bb00_Operation,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	036H
$DGS	END_BLK, ??eb00_Operation,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 029H
$DGS	BEG_BLK, ??bb01_Operation,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 02BH,		00H,	00H
$DGS	END_BLK, ??eb01_Operation,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02DH
$DGS	END_FUN, ??ef_Operation,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 02EH
$DGS	STA_SYM, _OperationStep_00,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	046H,	01H,	00H
$DGS	BEG_FUN, ??bf_OperationStep_00,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 05FH,		00H,	040H
$DGS	BEG_BLK, ??bb00_OperationStep_00,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	00H
$DGS	END_BLK, ??eb00_OperationStep_00,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	END_FUN, ??ef_OperationStep_00,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	STA_SYM, _Ini_OperationStep_00,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	04CH,	01H,	00H
$DGS	BEG_FUN, ??bf_Ini_OperationStep_00,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 066H,		00H,	04CH
$DGS	END_FUN, ??ef_Ini_OperationStep_00,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	STA_SYM, _OperationStep_01,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	05AH,	01H,	00H
$DGS	BEG_FUN, ??bf_OperationStep_01,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 06FH,		00H,	050H
$DGS	BEG_BLK, ??bb00_OperationStep_01,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	054H
$DGS	END_BLK, ??eb00_OperationStep_01,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	BEG_BLK, ??bb01_OperationStep_01,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	00H
$DGS	END_BLK, ??eb01_OperationStep_01,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 09H
$DGS	END_FUN, ??ef_OperationStep_01,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	STA_SYM, _Ini_OperationStep_01,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	060H,	01H,	00H
$DGS	BEG_FUN, ??bf_Ini_OperationStep_01,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 07AH,		00H,	060H
$DGS	END_FUN, ??ef_Ini_OperationStep_01,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	STA_SYM, _OperationStep_02,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	06AH,	01H,	00H
$DGS	BEG_FUN, ??bf_OperationStep_02,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 082H,		00H,	064H
$DGS	BEG_BLK, ??bb00_OperationStep_02,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	00H
$DGS	END_BLK, ??eb00_OperationStep_02,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	END_FUN, ??ef_OperationStep_02,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	STA_SYM, _Ini_OperationStep_02,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	070H,	01H,	00H
$DGS	BEG_FUN, ??bf_Ini_OperationStep_02,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 089H,		00H,	070H
$DGS	END_FUN, ??ef_Ini_OperationStep_02,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	STA_SYM, _OperationStep_10,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	082H,	01H,	00H
$DGS	BEG_FUN, ??bf_OperationStep_10,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 091H,		00H,	074H
$DGS	BEG_BLK, ??bb00_OperationStep_10,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	078H
$DGS	END_BLK, ??eb00_OperationStep_10,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	BEG_BLK, ??bb01_OperationStep_10,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	07CH
$DGS	END_BLK, ??eb01_OperationStep_10,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 09H
$DGS	BEG_BLK, ??bb02_OperationStep_10,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0BH,		00H,	00H
$DGS	END_BLK, ??eb02_OperationStep_10,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0DH
$DGS	END_FUN, ??ef_OperationStep_10,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0EH
$DGS	STA_SYM, _Ini_OperationStep_10,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	088H,	01H,	00H
$DGS	BEG_FUN, ??bf_Ini_OperationStep_10,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0A0H,		00H,	088H
$DGS	END_FUN, ??ef_Ini_OperationStep_10,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	STA_SYM, _OperationStep_D0,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	09AH,	01H,	00H
$DGS	BEG_FUN, ??bf_OperationStep_D0,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0A8H,		00H,	08CH
$DGS	BEG_BLK, ??bb00_OperationStep_D0,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	090H
$DGS	END_BLK, ??eb00_OperationStep_D0,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	BEG_BLK, ??bb01_OperationStep_D0,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	094H
$DGS	END_BLK, ??eb01_OperationStep_D0,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	BEG_BLK, ??bb02_OperationStep_D0,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0CH,		00H,	00H
$DGS	END_BLK, ??eb02_OperationStep_D0,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0EH
$DGS	END_FUN, ??ef_OperationStep_D0,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0FH
$DGS	STA_SYM, _Ini_OperationStep_D0,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	0A0H,	01H,	00H
$DGS	BEG_FUN, ??bf_Ini_OperationStep_D0,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0B8H,		00H,	0A0H
$DGS	END_FUN, ??ef_Ini_OperationStep_D0,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	STA_SYM, _OperationStepNoSet,	U,	U,	01H,	03H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	0A9H,	01H,	00H
$DGS	BEG_FUN, ??bf_OperationStepNoSet,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0C3H,		02H,	0A9H
$DGS	FUN_ARG, _data,		00H,	0FFFFH,	0CH,	09H,	00H,	00H
$DGS	STA_SYM, _DT_OperationNumber,	?L0045,	U,	0500CH,	03H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	04H,	04H,	00H,	00H,	00H,	00H
$DGS	END_FUN, ??ef_OperationStepNoSet,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0FH
$DGS	GLV_SYM, _gu8_OperationStepNum,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_TimerOper_1s,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _Operation_Step,	U,	U,	08H,	026H,	01H,	03H
$DGS	AUX_STR, 020H,		00H,	01EH,	05H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _DisplayControl_Data,	U,	U,	08H,	02H,	01H,	03H
$DGS	AUX_STR, 014H,		00H,	0110H,	022H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _SafetyLoop,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _gu8_TimerBootDisplay,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerVersionDisplay,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _F_FirstCommunication,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _F_Communication_Error,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _F_FOTA_Display,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerFOTA_Display,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _F_FOTA_Display_forWIFI_LED_ONOFF,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _F_CommunicationCMD,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_OperationStep,	U,	U,	0CH,	02H,	00H,	00H

	EXTRN	_DisplayControl_Data
	EXTRN	_SafetyLoop
	EXTRN	_gu8_TimerBootDisplay
	EXTRN	_gu8_TimerVersionDisplay
	EXTRN	_F_FirstCommunication
	EXTRN	_F_Communication_Error
	EXTRN	_F_FOTA_Display
	EXTRN	_gu8_TimerFOTA_Display
	EXTRN	_F_FOTA_Display_forWIFI_LED_ONOFF
	EXTRN	_F_CommunicationCMD
	EXTRN	_gu8_OperationStep
	PUBLIC	_gu8_OperationStepNum
	PUBLIC	_gu16_TimerOper_1s
	PUBLIC	_Operation_Step
	PUBLIC	_Operation_Initialize
	PUBLIC	_Operation

@@BITS	BSEG

@@CNST	CSEG	MIRRORP
?L0045:	DB	00H	; 0
	DB	01H	; 1
	DB	02H	; 2
	DB	010H	; 16

@@R_INIT	CSEG	UNIT64KP
	DB	00H	; 0
	DB	03H	; 3
	DG	_OperationStep_00
	DB	01H	; 1
	DB	03H	; 3
	DG	_OperationStep_01
	DB	02H	; 2
	DB	02H	; 2
	DG	_OperationStep_02
	DB	010H	; 16
	DB	03H	; 3
	DG	_OperationStep_10
	DB	0D0H	; 208
	DB	04H	; 4
	DG	_OperationStep_D0

@@INIT	DSEG	BASEP
_Operation_Step:	DS	(30)

@@DATA	DSEG	BASEP
_gu8_OperationStepNum:	DS	(1)
	DS	(1)
_gu16_TimerOper_1s:	DS	(2)

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
; line     8
; line     9
; line    10
; line    11
; line    12
; line    14
; line    15
; line    16
; line    17
; line    18
; line    20
; line    22
; line    25
; line    26
; line    27
; line    28
; line    29
; line    36

@@CODEL	CSEG
_Operation_Initialize:
$DGL	1,40
??bf_Operation_Initialize:
; line    37
$DGL	0,2
	call	!!_Ini_OperationStep_00				;[INF] 4, 3
; line    38
$DGL	0,3
??ef_Operation_Initialize:
	ret							;[INF] 1, 6
??ee_Operation_Initialize:
; line    44
_Operation:
$DGL	1,46
??bf_Operation:
; line    45
$DGL	0,2
	cmp	!_gu8_OperationStepNum,#05H	; 5 		;[INF] 4, 1
	skc							;[INF] 2, 1
	br	$!?L0005					;[INF] 3, 3
; line    46
??bb00_Operation:
; line    47
$DGL	0,4
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	addw	ax,#loww (_Operation_Step)			;[INF] 3, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de+4]					;[INF] 2, 1
	mov	CS,a						;[INF] 2, 1
	movw	ax,[de+2]					;[INF] 2, 1
	call	ax						;[INF] 2, 3
; line    49
$DGL	0,6
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+1,a			;[INF] 3, 1
; line    50
$DGL	0,7
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+9,a			;[INF] 3, 1
; line    51
$DGL	0,8
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+17,a			;[INF] 3, 1
; line    52
$DGL	0,9
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+25,a			;[INF] 3, 1
; line    53
$DGL	0,10
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+33,a			;[INF] 3, 1
; line    54
$DGL	0,11
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+41,a			;[INF] 3, 1
; line    55
$DGL	0,12
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+49,a			;[INF] 3, 1
; line    56
$DGL	0,13
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+57,a			;[INF] 3, 1
; line    57
$DGL	0,14
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+65,a			;[INF] 3, 1
; line    58
$DGL	0,15
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+73,a			;[INF] 3, 1
; line    59
$DGL	0,16
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+81,a			;[INF] 3, 1
; line    60
$DGL	0,17
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+89,a			;[INF] 3, 1
; line    61
$DGL	0,18
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+97,a			;[INF] 3, 1
; line    62
$DGL	0,19
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+105,a			;[INF] 3, 1
; line    63
$DGL	0,20
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+113,a			;[INF] 3, 1
; line    64
$DGL	0,21
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+121,a			;[INF] 3, 1
; line    65
$DGL	0,22
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+129,a			;[INF] 3, 1
; line    66
$DGL	0,23
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+137,a			;[INF] 3, 1
; line    67
$DGL	0,24
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+145,a			;[INF] 3, 1
; line    68
$DGL	0,25
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+153,a			;[INF] 3, 1
; line    69
$DGL	0,26
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+161,a			;[INF] 3, 1
; line    70
$DGL	0,27
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+169,a			;[INF] 3, 1
; line    71
$DGL	0,28
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+177,a			;[INF] 3, 1
; line    72
$DGL	0,29
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+185,a			;[INF] 3, 1
; line    73
$DGL	0,30
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+193,a			;[INF] 3, 1
; line    74
$DGL	0,31
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+201,a			;[INF] 3, 1
; line    75
$DGL	0,32
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+209,a			;[INF] 3, 1
; line    76
$DGL	0,33
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+217,a			;[INF] 3, 1
; line    77
$DGL	0,34
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+225,a			;[INF] 3, 1
; line    78
$DGL	0,35
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+233,a			;[INF] 3, 1
; line    79
$DGL	0,36
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+241,a			;[INF] 3, 1
; line    80
$DGL	0,37
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+249,a			;[INF] 3, 1
; line    81
$DGL	0,38
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+257,a			;[INF] 3, 1
; line    82
$DGL	0,39
	mov	a,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	x,#06H	; 6 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_Operation_Step+1[bc]				;[INF] 3, 1
	mov	!_DisplayControl_Data+265,a			;[INF] 3, 1
??eb00_Operation:
; line    85
$DGL	0,42
	br	$?L0006						;[INF] 2, 3
?L0005:
; line    86
??bb01_Operation:
; line    87
$DGL	0,44
	call	!!_SafetyLoop					;[INF] 4, 3
??eb01_Operation:
; line    88
?L0006:
; line    89
$DGL	0,46
??ef_Operation:
	ret							;[INF] 1, 6
??ee_Operation:
; line    95
_OperationStep_00:
$DGL	1,60
??bf_OperationStep_00:
; line    96
$DGL	0,2
	cmp0	!_gu8_TimerBootDisplay				;[INF] 3, 1
	sknz							;[INF] 2, 1
; line    97
??bb00_OperationStep_00:
; line    98
$DGL	0,4
	call	!!_Ini_OperationStep_01				;[INF] 4, 3
??eb00_OperationStep_00:
; line    99
?L0009:
?L0010:
; line   100
$DGL	0,6
??ef_OperationStep_00:
	ret							;[INF] 1, 6
??ee_OperationStep_00:
; line   102
_Ini_OperationStep_00:
$DGL	1,70
??bf_Ini_OperationStep_00:
; line   103
$DGL	0,2
	mov	!_gu8_TimerBootDisplay,#014H	; 20 		;[INF] 4, 1
; line   104
$DGL	0,3
	clrw	ax						;[INF] 1, 1
	call	!!_OperationStepNoSet				;[INF] 4, 3
; line   105
$DGL	0,4
??ef_Ini_OperationStep_00:
	ret							;[INF] 1, 6
??ee_Ini_OperationStep_00:
; line   111
_OperationStep_01:
$DGL	1,76
??bf_OperationStep_01:
; line   112
$DGL	0,2
	cmp0	!_gu8_TimerVersionDisplay			;[INF] 3, 1
	bnz	$?L0015						;[INF] 2, 4
	cmp	!_F_FirstCommunication,#01H	; 1 		;[INF] 4, 1
	bnz	$?L0015						;[INF] 2, 4
; line   113
??bb00_OperationStep_01:
; line   114
$DGL	0,4
	call	!!_Ini_OperationStep_10				;[INF] 4, 3
??eb00_OperationStep_01:
; line   116
$DGL	0,6
	br	$?L0016						;[INF] 2, 3
?L0015:
	cmp	!_F_Communication_Error,#01H	; 1 		;[INF] 4, 1
	sknz							;[INF] 2, 1
; line   117
??bb01_OperationStep_01:
; line   118
$DGL	0,8
	call	!!_Ini_OperationStep_02				;[INF] 4, 3
??eb01_OperationStep_01:
; line   119
?L0017:
?L0018:
?L0016:
; line   120
$DGL	0,10
??ef_OperationStep_01:
	ret							;[INF] 1, 6
??ee_OperationStep_01:
; line   122
_Ini_OperationStep_01:
$DGL	1,90
??bf_Ini_OperationStep_01:
; line   123
$DGL	0,2
	onew	ax						;[INF] 1, 1
	call	!!_OperationStepNoSet				;[INF] 4, 3
; line   124
$DGL	0,3
??ef_Ini_OperationStep_01:
	ret							;[INF] 1, 6
??ee_Ini_OperationStep_01:
; line   130
_OperationStep_02:
$DGL	1,96
??bf_OperationStep_02:
; line   131
$DGL	0,2
	cmp0	!_F_Communication_Error				;[INF] 3, 1
	sknz							;[INF] 2, 1
; line   132
??bb00_OperationStep_02:
; line   133
$DGL	0,4
	call	!!_Ini_OperationStep_00				;[INF] 4, 3
??eb00_OperationStep_02:
; line   134
?L0023:
?L0024:
; line   135
$DGL	0,6
??ef_OperationStep_02:
	ret							;[INF] 1, 6
??ee_OperationStep_02:
; line   137
_Ini_OperationStep_02:
$DGL	1,106
??bf_Ini_OperationStep_02:
; line   138
$DGL	0,2
	movw	ax,#02H	; 2 					;[INF] 3, 1
	call	!!_OperationStepNoSet				;[INF] 4, 3
; line   139
$DGL	0,3
??ef_Ini_OperationStep_02:
	ret							;[INF] 1, 6
??ee_Ini_OperationStep_02:
; line   145
_OperationStep_10:
$DGL	1,112
??bf_OperationStep_10:
; line   146
$DGL	0,2
	cmp	!_F_FOTA_Display,#01H	; 1 			;[INF] 4, 1
	bnz	$?L0029						;[INF] 2, 4
; line   147
??bb00_OperationStep_10:
; line   148
$DGL	0,4
	call	!!_Ini_OperationStep_D0				;[INF] 4, 3
??eb00_OperationStep_10:
; line   150
$DGL	0,6
	br	$?L0030						;[INF] 2, 3
?L0029:
	cmp	!_F_Communication_Error,#01H	; 1 		;[INF] 4, 1
	sknz							;[INF] 2, 1
; line   151
??bb01_OperationStep_10:
; line   152
$DGL	0,8
	call	!!_Ini_OperationStep_02				;[INF] 4, 3
??eb01_OperationStep_10:
; line   154
?L0031:
; line   155
??bb02_OperationStep_10:
??eb02_OperationStep_10:
; line   157
?L0032:
?L0030:
; line   158
$DGL	0,14
??ef_OperationStep_10:
	ret							;[INF] 1, 6
??ee_OperationStep_10:
; line   160
_Ini_OperationStep_10:
$DGL	1,130
??bf_Ini_OperationStep_10:
; line   161
$DGL	0,2
	movw	ax,#03H	; 3 					;[INF] 3, 1
	call	!!_OperationStepNoSet				;[INF] 4, 3
; line   162
$DGL	0,3
??ef_Ini_OperationStep_10:
	ret							;[INF] 1, 6
??ee_Ini_OperationStep_10:
; line   168
_OperationStep_D0:
$DGL	1,136
??bf_OperationStep_D0:
; line   169
$DGL	0,2
	cmp0	!_F_FOTA_Display				;[INF] 3, 1
	bnz	$?L0037						;[INF] 2, 4
; line   170
??bb00_OperationStep_D0:
; line   171
$DGL	0,4
	call	!!_Ini_OperationStep_10				;[INF] 4, 3
??eb00_OperationStep_D0:
; line   173
$DGL	0,6
	br	$?L0038						;[INF] 2, 3
?L0037:
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu16_TimerOper_1s				;[INF] 3, 1
	bnz	$?L0039						;[INF] 2, 4
; line   174
??bb01_OperationStep_D0:
; line   175
$DGL	0,8
	clrb	!_F_FOTA_Display				;[INF] 3, 1
; line   176
$DGL	0,9
	call	!!_Ini_OperationStep_10				;[INF] 4, 3
??eb01_OperationStep_D0:
; line   178
?L0039:
; line   179
??bb02_OperationStep_D0:
??eb02_OperationStep_D0:
; line   181
?L0040:
?L0038:
; line   182
$DGL	0,15
??ef_OperationStep_D0:
	ret							;[INF] 1, 6
??ee_OperationStep_D0:
; line   184
_Ini_OperationStep_D0:
$DGL	1,154
??bf_Ini_OperationStep_D0:
; line   185
$DGL	0,2
	movw	ax,#0B4H	; 180 				;[INF] 3, 1
	movw	!_gu16_TimerOper_1s,ax				;[INF] 3, 1
; line   186
$DGL	0,3
	mov	!_gu8_TimerFOTA_Display,#01EH	; 30 		;[INF] 4, 1
; line   187
$DGL	0,4
	oneb	!_F_FOTA_Display_forWIFI_LED_ONOFF		;[INF] 3, 1
; line   188
$DGL	0,5
	mov	x,#04H	; 4 					;[INF] 2, 1
	call	!!_OperationStepNoSet				;[INF] 4, 3
; line   189
$DGL	0,6
??ef_Ini_OperationStep_D0:
	ret							;[INF] 1, 6
??ee_Ini_OperationStep_D0:
; line   195
_OperationStepNoSet:
$DGL	1,160
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_OperationStepNoSet:
; line   198
; line   199
; line   200
; line   201
; line   204
$DGL	0,10
	mov	a,[hl]	; data 					;[INF] 1, 1
	mov	!_gu8_OperationStepNum,a			;[INF] 3, 1
; line   206
$DGL	0,12
	oneb	!_F_CommunicationCMD				;[INF] 3, 1
; line   208
$DGL	0,14
	mov	b,!_gu8_OperationStepNum			;[INF] 3, 1
	mov	a,?L0045[b]	; DT_OperationNumber 		;[INF] 3, 1
	mov	!_gu8_OperationStep,a				;[INF] 3, 1
; line   209
$DGL	0,15
??ef_OperationStepNoSet:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_OperationStepNoSet:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE

@@FIX	DSEG	BASEP

	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\Source\operation.c
;
; $FUNC Operation_Initialize(36)
;	void=(void)
;	CODE SIZE= 5 bytes, CLOCK_SIZE= 9 clocks, STACK_SIZE= 4 bytes
;
; $CALL Ini_OperationStep_00(37)
;	void=(void)
;
; $FUNC Operation(44)
;	void=(void)
;	CODE SIZE= 476 bytes, CLOCK_SIZE= 232 clocks, STACK_SIZE= 4 bytes
;
; $CALL (47)
;	void=(void)
;
; $CALL SafetyLoop(87)
;	void=(void)
;
; $FUNC OperationStep_00(95)
;	void=(void)
;	CODE SIZE= 10 bytes, CLOCK_SIZE= 11 clocks, STACK_SIZE= 4 bytes
;
; $CALL Ini_OperationStep_01(98)
;	void=(void)
;
; $FUNC Ini_OperationStep_00(102)
;	void=(void)
;	CODE SIZE= 10 bytes, CLOCK_SIZE= 11 clocks, STACK_SIZE= 4 bytes
;
; $CALL OperationStepNoSet(104)
;	void=(int:ax)
;
; $FUNC OperationStep_01(111)
;	void=(void)
;	CODE SIZE= 28 bytes, CLOCK_SIZE= 27 clocks, STACK_SIZE= 4 bytes
;
; $CALL Ini_OperationStep_10(114)
;	void=(void)
;
; $CALL Ini_OperationStep_02(118)
;	void=(void)
;
; $FUNC Ini_OperationStep_01(122)
;	void=(void)
;	CODE SIZE= 6 bytes, CLOCK_SIZE= 10 clocks, STACK_SIZE= 4 bytes
;
; $CALL OperationStepNoSet(123)
;	void=(int:ax)
;
; $FUNC OperationStep_02(130)
;	void=(void)
;	CODE SIZE= 10 bytes, CLOCK_SIZE= 11 clocks, STACK_SIZE= 4 bytes
;
; $CALL Ini_OperationStep_00(133)
;	void=(void)
;
; $FUNC Ini_OperationStep_02(137)
;	void=(void)
;	CODE SIZE= 8 bytes, CLOCK_SIZE= 10 clocks, STACK_SIZE= 4 bytes
;
; $CALL OperationStepNoSet(138)
;	void=(int:ax)
;
; $FUNC OperationStep_10(145)
;	void=(void)
;	CODE SIZE= 23 bytes, CLOCK_SIZE= 22 clocks, STACK_SIZE= 4 bytes
;
; $CALL Ini_OperationStep_D0(148)
;	void=(void)
;
; $CALL Ini_OperationStep_02(152)
;	void=(void)
;
; $FUNC Ini_OperationStep_10(160)
;	void=(void)
;	CODE SIZE= 8 bytes, CLOCK_SIZE= 10 clocks, STACK_SIZE= 4 bytes
;
; $CALL OperationStepNoSet(161)
;	void=(int:ax)
;
; $FUNC OperationStep_D0(168)
;	void=(void)
;	CODE SIZE= 25 bytes, CLOCK_SIZE= 27 clocks, STACK_SIZE= 4 bytes
;
; $CALL Ini_OperationStep_10(171)
;	void=(void)
;
; $CALL Ini_OperationStep_10(176)
;	void=(void)
;
; $FUNC Ini_OperationStep_D0(184)
;	void=(void)
;	CODE SIZE= 20 bytes, CLOCK_SIZE= 14 clocks, STACK_SIZE= 4 bytes
;
; $CALL OperationStepNoSet(188)
;	void=(int:ax)
;
; $FUNC OperationStepNoSet(195)
;	void=(unsigned char data:x)
;	CODE SIZE= 24 bytes, CLOCK_SIZE= 17 clocks, STACK_SIZE= 4 bytes

; Target chip : R5F100PG
; Device file : V1.14 
