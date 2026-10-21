; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:58

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile Source\timer.c -oDefaultBuild -_msgoff -nq -
;             i. -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no -g2
; In-file   : Source\timer.c
; Asm-file  : DefaultBuild\timer.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		01C2H,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, timer.c
$DGS	MOD_NAM, timer,		00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	GLV_SYM, _Timer_Initialize,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	026H,	01H,	00H
$DGS	BEG_FUN, ??bf_Timer_Initialize,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0DH,		00H,	026H
$DGS	END_FUN, ??ef_Timer_Initialize,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	GLV_SYM, _Timer_Base_Timer,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	04AH,	01H,	00H
$DGS	BEG_FUN, ??bf_Timer_Base_Timer,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 015H,		00H,	02CH
$DGS	STA_SYM, _count,	?L0005,	U,	0EH,	03H,	00H,	00H
$DGS	STA_SYM, _count_1ms,	?L0006,	U,	0CH,	03H,	00H,	00H
$DGS	BEG_BLK, ??bb00_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 08H,		00H,	030H
$DGS	END_BLK, ??eb00_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	BEG_BLK, ??bb01_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0CH,		00H,	034H
$DGS	END_BLK, ??eb01_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0EH
$DGS	BEG_BLK, ??bb02_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 014H,		00H,	036H
$DGS	BEG_BLK, ??bb03_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 015H,		00H,	03AH
$DGS	END_BLK, ??eb03_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 017H
$DGS	BEG_BLK, ??bb04_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 020H,		00H,	03CH
$DGS	BEG_BLK, ??bb05_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 026H,		00H,	042H
$DGS	END_BLK, ??eb05_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 029H
$DGS	END_BLK, ??eb04_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02AH
$DGS	BEG_BLK, ??bb06_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 030H,		00H,	00H
$DGS	END_BLK, ??eb06_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 032H
$DGS	END_BLK, ??eb02_Timer_Base_Timer,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 033H
$DGS	END_FUN, ??ef_Timer_Base_Timer,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 034H
$DGS	GLV_SYM, _Timer_Process,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	06DH,	01H,	00H
$DGS	BEG_FUN, ??bf_Timer_Process,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 04EH,		00H,	053H
$DGS	STA_SYM, _mu8_Counter1s,	?L0024,	U,	0CH,	03H,	00H,	00H
$DGS	STA_SYM, _mu8_Counter10s,	?L0025,	U,	0CH,	03H,	00H,	00H
$DGS	STA_SYM, _mu8_Counter1min,	?L0026,	U,	0CH,	03H,	00H,	00H
$DGS	STA_SYM, _mu8_Counter10min,	?L0027,	U,	0CH,	03H,	00H,	00H
$DGS	STA_SYM, _mu8_Counter1h,	?L0028,	U,	0CH,	03H,	00H,	00H
$DGS	BEG_BLK, ??bb00_Timer_Process,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	055H
$DGS	BEG_BLK, ??bb01_Timer_Process,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0FH,		00H,	057H
$DGS	BEG_BLK, ??bb02_Timer_Process,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 016H,		00H,	059H
$DGS	BEG_BLK, ??bb03_Timer_Process,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01CH,		00H,	05BH
$DGS	BEG_BLK, ??bb04_Timer_Process,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 022H,		00H,	05DH
$DGS	BEG_BLK, ??bb05_Timer_Process,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 028H,		00H,	00H
$DGS	END_BLK, ??eb05_Timer_Process,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02BH
$DGS	END_BLK, ??eb04_Timer_Process,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02CH
$DGS	END_BLK, ??eb03_Timer_Process,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02DH
$DGS	END_BLK, ??eb02_Timer_Process,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02EH
$DGS	END_BLK, ??eb01_Timer_Process,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02FH
$DGS	END_BLK, ??eb00_Timer_Process,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 030H
$DGS	END_FUN, ??ef_Timer_Process,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 031H
$DGS	GLV_SYM, _Time1ms,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	09CH,	01H,	00H
$DGS	BEG_FUN, ??bf_Time1ms,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 084H,		02H,	072H
$DGS	AUT_VAR, _i,		01H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 011H,		00H,	076H
$DGS	END_BLK, ??eb00_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 011H
$DGS	BEG_BLK, ??bb01_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 012H,		00H,	07AH
$DGS	END_BLK, ??eb01_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 012H
$DGS	BEG_BLK, ??bb02_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 013H,		00H,	07EH
$DGS	END_BLK, ??eb02_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 013H
$DGS	BEG_BLK, ??bb03_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 014H,		00H,	082H
$DGS	END_BLK, ??eb03_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 014H
$DGS	BEG_BLK, ??bb04_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 015H,		00H,	086H
$DGS	END_BLK, ??eb04_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 015H
$DGS	BEG_BLK, ??bb05_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 016H,		00H,	08AH
$DGS	END_BLK, ??eb05_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 016H
$DGS	BEG_BLK, ??bb06_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 017H,		00H,	08EH
$DGS	END_BLK, ??eb06_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 017H
$DGS	BEG_BLK, ??bb07_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 018H,		00H,	092H
$DGS	END_BLK, ??eb07_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 018H
$DGS	BEG_BLK, ??bb08_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 019H,		00H,	096H
$DGS	END_BLK, ??eb08_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 019H
$DGS	BEG_BLK, ??bb09_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01CH,		00H,	00H
$DGS	END_BLK, ??eb09_Time1ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 01EH
$DGS	END_FUN, ??ef_Time1ms,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 01FH
$DGS	GLV_SYM, _Time10ms,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	0C6H,	01H,	00H
$DGS	BEG_FUN, ??bf_Time10ms,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0A8H,		00H,	0A0H
$DGS	BEG_BLK, ??bb00_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	0A4H
$DGS	END_BLK, ??eb00_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	BEG_BLK, ??bb01_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 04H,		00H,	0A8H
$DGS	END_BLK, ??eb01_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	BEG_BLK, ??bb02_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 05H,		00H,	0ACH
$DGS	END_BLK, ??eb02_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	BEG_BLK, ??bb03_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 06H,		00H,	0B0H
$DGS	END_BLK, ??eb03_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	BEG_BLK, ??bb04_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	0B4H
$DGS	END_BLK, ??eb04_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 07H
$DGS	BEG_BLK, ??bb05_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 08H,		00H,	0B8H
$DGS	END_BLK, ??eb05_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 08H
$DGS	BEG_BLK, ??bb06_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	0BCH
$DGS	END_BLK, ??eb06_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 09H
$DGS	BEG_BLK, ??bb07_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0AH,		00H,	0C0H
$DGS	END_BLK, ??eb07_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	BEG_BLK, ??bb08_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0BH,		00H,	00H
$DGS	END_BLK, ??eb08_Time10ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0BH
$DGS	END_FUN, ??ef_Time10ms,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0CH
$DGS	GLV_SYM, _Time100ms,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	0F0H,	01H,	00H
$DGS	BEG_FUN, ??bf_Time100ms,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0B9H,		00H,	0CAH
$DGS	BEG_BLK, ??bb00_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	0CEH
$DGS	END_BLK, ??eb00_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	BEG_BLK, ??bb01_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 04H,		00H,	0D2H
$DGS	END_BLK, ??eb01_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	BEG_BLK, ??bb02_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 05H,		00H,	0D6H
$DGS	END_BLK, ??eb02_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	BEG_BLK, ??bb03_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 06H,		00H,	0DAH
$DGS	END_BLK, ??eb03_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	BEG_BLK, ??bb04_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	0DEH
$DGS	END_BLK, ??eb04_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 07H
$DGS	BEG_BLK, ??bb05_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 08H,		00H,	0E2H
$DGS	END_BLK, ??eb05_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 08H
$DGS	BEG_BLK, ??bb06_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	0E6H
$DGS	END_BLK, ??eb06_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 09H
$DGS	BEG_BLK, ??bb07_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0AH,		00H,	0EAH
$DGS	END_BLK, ??eb07_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	BEG_BLK, ??bb08_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0BH,		00H,	00H
$DGS	END_BLK, ??eb08_Time100ms,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0BH
$DGS	END_FUN, ??ef_Time100ms,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0CH
$DGS	GLV_SYM, _Time1s,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	011AH,	01H,	00H
$DGS	BEG_FUN, ??bf_Time1s,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0CAH,		00H,	0F4H
$DGS	BEG_BLK, ??bb00_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	0F8H
$DGS	END_BLK, ??eb00_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	BEG_BLK, ??bb01_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 04H,		00H,	0FCH
$DGS	END_BLK, ??eb01_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	BEG_BLK, ??bb02_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 05H,		00H,	0100H
$DGS	END_BLK, ??eb02_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	BEG_BLK, ??bb03_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 06H,		00H,	0104H
$DGS	END_BLK, ??eb03_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	BEG_BLK, ??bb04_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	0108H
$DGS	END_BLK, ??eb04_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 07H
$DGS	BEG_BLK, ??bb05_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 08H,		00H,	010CH
$DGS	END_BLK, ??eb05_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 08H
$DGS	BEG_BLK, ??bb06_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	0110H
$DGS	END_BLK, ??eb06_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 09H
$DGS	BEG_BLK, ??bb07_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0AH,		00H,	0114H
$DGS	END_BLK, ??eb07_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	BEG_BLK, ??bb08_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0BH,		00H,	00H
$DGS	END_BLK, ??eb08_Time1s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0BH
$DGS	END_FUN, ??ef_Time1s,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0CH
$DGS	GLV_SYM, _Time10s,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	0144H,	01H,	00H
$DGS	BEG_FUN, ??bf_Time10s,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0DBH,		00H,	011EH
$DGS	BEG_BLK, ??bb00_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	0122H
$DGS	END_BLK, ??eb00_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	BEG_BLK, ??bb01_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 04H,		00H,	0126H
$DGS	END_BLK, ??eb01_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	BEG_BLK, ??bb02_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 05H,		00H,	012AH
$DGS	END_BLK, ??eb02_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	BEG_BLK, ??bb03_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 06H,		00H,	012EH
$DGS	END_BLK, ??eb03_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	BEG_BLK, ??bb04_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	0132H
$DGS	END_BLK, ??eb04_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 07H
$DGS	BEG_BLK, ??bb05_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 08H,		00H,	0136H
$DGS	END_BLK, ??eb05_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 08H
$DGS	BEG_BLK, ??bb06_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	013AH
$DGS	END_BLK, ??eb06_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 09H
$DGS	BEG_BLK, ??bb07_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0AH,		00H,	013EH
$DGS	END_BLK, ??eb07_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	BEG_BLK, ??bb08_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0BH,		00H,	00H
$DGS	END_BLK, ??eb08_Time10s,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0BH
$DGS	END_FUN, ??ef_Time10s,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0CH
$DGS	GLV_SYM, _Time1min,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	016EH,	01H,	00H
$DGS	BEG_FUN, ??bf_Time1min,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0ECH,		00H,	0148H
$DGS	BEG_BLK, ??bb00_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	014CH
$DGS	END_BLK, ??eb00_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	BEG_BLK, ??bb01_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 04H,		00H,	0150H
$DGS	END_BLK, ??eb01_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	BEG_BLK, ??bb02_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 05H,		00H,	0154H
$DGS	END_BLK, ??eb02_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	BEG_BLK, ??bb03_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 06H,		00H,	0158H
$DGS	END_BLK, ??eb03_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	BEG_BLK, ??bb04_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	015CH
$DGS	END_BLK, ??eb04_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 07H
$DGS	BEG_BLK, ??bb05_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 08H,		00H,	0160H
$DGS	END_BLK, ??eb05_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 08H
$DGS	BEG_BLK, ??bb06_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	0164H
$DGS	END_BLK, ??eb06_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 09H
$DGS	BEG_BLK, ??bb07_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0AH,		00H,	0168H
$DGS	END_BLK, ??eb07_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	BEG_BLK, ??bb08_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0BH,		00H,	00H
$DGS	END_BLK, ??eb08_Time1min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0BH
$DGS	END_FUN, ??ef_Time1min,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0CH
$DGS	GLV_SYM, _Time10min,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	0198H,	01H,	00H
$DGS	BEG_FUN, ??bf_Time10min,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0FDH,		00H,	0172H
$DGS	BEG_BLK, ??bb00_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	0176H
$DGS	END_BLK, ??eb00_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	BEG_BLK, ??bb01_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 04H,		00H,	017AH
$DGS	END_BLK, ??eb01_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	BEG_BLK, ??bb02_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 05H,		00H,	017EH
$DGS	END_BLK, ??eb02_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	BEG_BLK, ??bb03_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 06H,		00H,	0182H
$DGS	END_BLK, ??eb03_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	BEG_BLK, ??bb04_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	0186H
$DGS	END_BLK, ??eb04_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 07H
$DGS	BEG_BLK, ??bb05_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 08H,		00H,	018AH
$DGS	END_BLK, ??eb05_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 08H
$DGS	BEG_BLK, ??bb06_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	018EH
$DGS	END_BLK, ??eb06_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 09H
$DGS	BEG_BLK, ??bb07_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0AH,		00H,	0192H
$DGS	END_BLK, ??eb07_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	BEG_BLK, ??bb08_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0BH,		00H,	00H
$DGS	END_BLK, ??eb08_Time10min,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0BH
$DGS	END_FUN, ??ef_Time10min,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0CH
$DGS	GLV_SYM, _Time1h,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	01C2H,	01H,	00H
$DGS	BEG_FUN, ??bf_Time1h,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 010EH,		00H,	019CH
$DGS	BEG_BLK, ??bb00_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	01A0H
$DGS	END_BLK, ??eb00_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	BEG_BLK, ??bb01_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 04H,		00H,	01A4H
$DGS	END_BLK, ??eb01_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	BEG_BLK, ??bb02_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 05H,		00H,	01A8H
$DGS	END_BLK, ??eb02_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05H
$DGS	BEG_BLK, ??bb03_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 06H,		00H,	01ACH
$DGS	END_BLK, ??eb03_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	BEG_BLK, ??bb04_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	01B0H
$DGS	END_BLK, ??eb04_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 07H
$DGS	BEG_BLK, ??bb05_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 08H,		00H,	01B4H
$DGS	END_BLK, ??eb05_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 08H
$DGS	BEG_BLK, ??bb06_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	01B8H
$DGS	END_BLK, ??eb06_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 09H
$DGS	BEG_BLK, ??bb07_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0AH,		00H,	01BCH
$DGS	END_BLK, ??eb07_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	BEG_BLK, ??bb08_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0BH,		00H,	00H
$DGS	END_BLK, ??eb08_Time1h,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0BH
$DGS	END_FUN, ??ef_Time1h,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0CH
$DGS	GLV_SYM, _gu8_Counter10ms,	U,	U,	0100CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Counter100ms,	U,	U,	0100CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_FlagTime100ms,	U,	U,	0100CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_FlagTime1000ms,	U,	U,	0100CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Counter_1msTimerCheck,	U,	U,	0100CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Counter_MainLoopCheck,	U,	U,	0100CH,	026H,	00H,	00H
$DGS	GLV_SYM, _F_1ms_for_InputDigital,	U,	U,	0100CH,	026H,	00H,	00H
$DGS	GLV_SYM, _F_10ms_for_InputDigital,	U,	U,	0100CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_DisplayPWM_Count_1ms,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_SEGMENT_CMD,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_OperationStep,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _Seg_Control,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _DisplayOut,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _FadeProcess,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _DisplayControl,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _SafetyLoop,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _gu8_TimerEffluentKey,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerKeyProhibit,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu16_TimerRecWait,	U,	U,	0EH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu16_TimerTraWait,	U,	U,	0EH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerTrahalt,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerRecInt_Check,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _DisplayControl_Data,	U,	U,	08H,	02H,	01H,	03H
$DGS	AUX_STR, 014H,		00H,	0110H,	022H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerFlic,	U,	U,	0100CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerFlic_S2,	U,	U,	0100CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerHWWait,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_Timer_ProhibitSW,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_Timer_ShortSW,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu16_TimerKeyDecide,	U,	U,	0EH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerError_Time,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerFOTA_Display,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerBootDisplay,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerVersionDisplay,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_Timer_LongSW,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerKeyOnBreak,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerTraWait_TimeShort,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu16_TimerOper_1s,	U,	U,	0EH,	02H,	00H,	00H

	EXTRN	_gu8_DisplayPWM_Count_1ms
	EXTRN	_gu8_Main_SEGMENT_CMD
	EXTRN	_gu8_OperationStep
	EXTRN	_Seg_Control
	EXTRN	_DisplayOut
	EXTRN	_FadeProcess
	EXTRN	_DisplayControl
	EXTRN	_SafetyLoop
	EXTRN	_gu8_TimerEffluentKey
	EXTRN	_gu8_TimerKeyProhibit
	EXTRN	_gu16_TimerRecWait
	EXTRN	_gu16_TimerTraWait
	EXTRN	_gu8_TimerTrahalt
	EXTRN	_gu8_TimerRecInt_Check
	EXTRN	_DisplayControl_Data
	EXTRN	_gu8_TimerFlic
	EXTRN	_gu8_TimerFlic_S2
	EXTRN	_gu8_TimerHWWait
	EXTRN	_gu8_Timer_ProhibitSW
	EXTRN	_gu8_Timer_ShortSW
	EXTRN	_gu16_TimerKeyDecide
	EXTRN	_gu8_TimerError_Time
	EXTRN	_gu8_TimerFOTA_Display
	EXTRN	_gu8_TimerBootDisplay
	EXTRN	_gu8_TimerVersionDisplay
	EXTRN	_gu8_Timer_LongSW
	EXTRN	_gu8_TimerKeyOnBreak
	EXTRN	_gu8_TimerTraWait_TimeShort
	EXTRN	_gu16_TimerOper_1s
	PUBLIC	_gu8_Counter10ms
	PUBLIC	_gu8_Counter100ms
	PUBLIC	_gu8_FlagTime100ms
	PUBLIC	_gu8_FlagTime1000ms
	PUBLIC	_gu8_Counter_1msTimerCheck
	PUBLIC	_gu8_Counter_MainLoopCheck
	PUBLIC	_F_1ms_for_InputDigital
	PUBLIC	_F_10ms_for_InputDigital
	PUBLIC	_Timer_Initialize
	PUBLIC	_Timer_Base_Timer
	PUBLIC	_Timer_Process
	PUBLIC	_Time1ms
	PUBLIC	_Time10ms
	PUBLIC	_Time100ms
	PUBLIC	_Time1s
	PUBLIC	_Time10s
	PUBLIC	_Time1min
	PUBLIC	_Time10min
	PUBLIC	_Time1h

@@BITS	BSEG

@@CNST	CSEG	MIRRORP

@@R_INIT	CSEG	UNIT64KP
	DW	00H	; 0
	DB	00H	; 0
	DB	(1)

@@INIT	DSEG	BASEP
?L0005:	DS	(2)
?L0006:	DS	(1)
	DS	(1)

@@DATA	DSEG	BASEP
_gu8_Counter10ms:	DS	(1)
_gu8_Counter100ms:	DS	(1)
_gu8_FlagTime100ms:	DS	(1)
_gu8_FlagTime1000ms:	DS	(1)
_gu8_Counter_1msTimerCheck:	DS	(1)
_gu8_Counter_MainLoopCheck:	DS	(1)
_F_1ms_for_InputDigital:	DS	(1)
_F_10ms_for_InputDigital:	DS	(1)
?L0024:	DS	(1)
?L0025:	DS	(1)
?L0026:	DS	(1)
?L0027:	DS	(1)
?L0028:	DS	(1)
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
_Timer_Initialize:
$DGL	1,32
??bf_Timer_Initialize:
; line    14
$DGL	0,2
	mov	!_gu8_Counter_1msTimerCheck,#0FFH	; 255 	;[INF] 4, 1
; line    15
$DGL	0,3
??ef_Timer_Initialize:
	ret							;[INF] 1, 6
??ee_Timer_Initialize:
; line    21
_Timer_Base_Timer:
$DGL	1,38
??bf_Timer_Base_Timer:
; line    22
; line    23
; line    25
$DGL	0,5
	ei							;[INF] 3, 4
; line    27
$DGL	0,7
	inc	!_gu8_DisplayPWM_Count_1ms			;[INF] 3, 2
	cmp	!_gu8_DisplayPWM_Count_1ms,#033H	; 51 	;[INF] 4, 1
	skc							;[INF] 2, 1
; line    28
??bb00_Timer_Base_Timer:
; line    29
$DGL	0,9
	oneb	!_gu8_DisplayPWM_Count_1ms			;[INF] 3, 1
??eb00_Timer_Base_Timer:
; line    30
?L0007:
?L0008:
; line    32
$DGL	0,12
	cmp	!_gu8_Main_SEGMENT_CMD,#01H	; 1 		;[INF] 4, 1
	bnz	$?L0011						;[INF] 2, 4
	cmp	!_gu8_OperationStep,#02H	; 2 		;[INF] 4, 1
	sknz							;[INF] 2, 1
?L0011:
??bb01_Timer_Base_Timer:
; line    33
$DGL	0,13
	call	!!_Seg_Control					;[INF] 4, 3
??eb01_Timer_Base_Timer:
; line    34
?L0009:
?L0010:
; line    36
$DGL	0,16
	call	!!_DisplayOut					;[INF] 4, 3
; line    37
$DGL	0,17
	call	!!_FadeProcess					;[INF] 4, 3
; line    39
$DGL	0,19
	inc	!?L0006	; count_1ms 				;[INF] 3, 2
	cmp	!?L0006,#05H	; count_1ms,5 			;[INF] 4, 1
	bc	$?L0012						;[INF] 2, 4
; line    40
??bb02_Timer_Base_Timer:
; line    41
$DGL	0,21
	cmp	!_gu8_Main_SEGMENT_CMD,#01H	; 1 		;[INF] 4, 1
	bnz	$?L0014						;[INF] 2, 4
	cmp	!_gu8_OperationStep,#02H	; 2 		;[INF] 4, 1
	skz							;[INF] 2, 1
??bb03_Timer_Base_Timer:
; line    42
$DGL	0,22
	call	!!_Seg_Control					;[INF] 4, 3
??eb03_Timer_Base_Timer:
; line    43
?L0014:
?L0015:
; line    44
$DGL	0,24
	clrb	!?L0006	; count_1ms 				;[INF] 3, 1
; line    46
$DGL	0,26
	call	!!_DisplayControl				;[INF] 4, 3
; line    48
$DGL	0,28
	call	!!_Time1ms					;[INF] 4, 3
; line    50
$DGL	0,30
	inc	!_gu8_Counter10ms				;[INF] 3, 2
; line    51
$DGL	0,31
	cmp	!_gu8_Counter10ms,#0AH	; 10 			;[INF] 4, 1
	bc	$?L0016						;[INF] 2, 4
; line    52
??bb04_Timer_Base_Timer:
; line    53
$DGL	0,33
	oneb	!_F_10ms_for_InputDigital			;[INF] 3, 1
; line    54
$DGL	0,34
	clrb	!_gu8_Counter10ms				;[INF] 3, 1
; line    55
$DGL	0,35
	call	!!_Time10ms					;[INF] 4, 3
; line    56
$DGL	0,36
	inc	!_gu8_Counter100ms				;[INF] 3, 2
; line    57
$DGL	0,37
	cmp	!_gu8_Counter100ms,#0AH	; 10 			;[INF] 4, 1
	bc	$?L0018						;[INF] 2, 4
; line    58
??bb05_Timer_Base_Timer:
; line    59
$DGL	0,39
	clrb	!_gu8_Counter100ms				;[INF] 3, 1
; line    60
$DGL	0,40
	oneb	!_gu8_FlagTime100ms				;[INF] 3, 1
??eb05_Timer_Base_Timer:
; line    61
?L0018:
?L0019:
??eb04_Timer_Base_Timer:
; line    62
?L0016:
?L0017:
; line    63
$DGL	0,43
	mov	!_gu8_Counter_1msTimerCheck,#0FFH	; 255 	;[INF] 4, 1
; line    65
$DGL	0,45
	dec	!_gu8_Counter_MainLoopCheck			;[INF] 3, 2
; line    67
$DGL	0,47
	cmp0	!_gu8_Counter_MainLoopCheck			;[INF] 3, 1
	sknz							;[INF] 2, 1
; line    68
??bb06_Timer_Base_Timer:
; line    69
$DGL	0,49
	call	!!_SafetyLoop					;[INF] 4, 3
??eb06_Timer_Base_Timer:
; line    70
?L0020:
?L0021:
??eb02_Timer_Base_Timer:
; line    71
?L0012:
?L0013:
; line    72
$DGL	0,52
??ef_Timer_Base_Timer:
	ret							;[INF] 1, 6
??ee_Timer_Base_Timer:
; line    78
_Timer_Process:
$DGL	1,74
??bf_Timer_Process:
; line    85
$DGL	0,8
	cmp	!_gu8_FlagTime100ms,#01H	; 1 		;[INF] 4, 1
	bnz	$?L0029						;[INF] 2, 4
; line    86
??bb00_Timer_Process:
; line    87
$DGL	0,10
	clrb	!_gu8_FlagTime100ms				;[INF] 3, 1
; line    88
$DGL	0,11
	call	!!_Time100ms					;[INF] 4, 3
; line    90
$DGL	0,13
	inc	!?L0024	; mu8_Counter1s 			;[INF] 3, 2
; line    91
$DGL	0,14
	cmp	!?L0024,#0AH	; mu8_Counter1s,10 		;[INF] 4, 1
	bc	$?L0031						;[INF] 2, 4
; line    92
??bb01_Timer_Process:
; line    93
$DGL	0,16
	clrb	!?L0024	; mu8_Counter1s 			;[INF] 3, 1
; line    94
$DGL	0,17
	oneb	!_gu8_FlagTime1000ms				;[INF] 3, 1
; line    95
$DGL	0,18
	call	!!_Time1s					;[INF] 4, 3
; line    97
$DGL	0,20
	inc	!?L0025	; mu8_Counter10s 			;[INF] 3, 2
; line    98
$DGL	0,21
	cmp	!?L0025,#0AH	; mu8_Counter10s,10 		;[INF] 4, 1
	bc	$?L0033						;[INF] 2, 4
; line    99
??bb02_Timer_Process:
; line   100
$DGL	0,23
	clrb	!?L0025	; mu8_Counter10s 			;[INF] 3, 1
; line   101
$DGL	0,24
	call	!!_Time10s					;[INF] 4, 3
; line   103
$DGL	0,26
	inc	!?L0026	; mu8_Counter1min 			;[INF] 3, 2
; line   104
$DGL	0,27
	cmp	!?L0026,#06H	; mu8_Counter1min,6 		;[INF] 4, 1
	bc	$?L0035						;[INF] 2, 4
; line   105
??bb03_Timer_Process:
; line   106
$DGL	0,29
	clrb	!?L0026	; mu8_Counter1min 			;[INF] 3, 1
; line   107
$DGL	0,30
	call	!!_Time1min					;[INF] 4, 3
; line   109
$DGL	0,32
	inc	!?L0027	; mu8_Counter10min 			;[INF] 3, 2
; line   110
$DGL	0,33
	cmp	!?L0027,#0AH	; mu8_Counter10min,10 		;[INF] 4, 1
	bc	$?L0037						;[INF] 2, 4
; line   111
??bb04_Timer_Process:
; line   112
$DGL	0,35
	clrb	!?L0027	; mu8_Counter10min 			;[INF] 3, 1
; line   113
$DGL	0,36
	call	!!_Time10min					;[INF] 4, 3
; line   115
$DGL	0,38
	inc	!?L0028	; mu8_Counter1h 			;[INF] 3, 2
; line   116
$DGL	0,39
	cmp	!?L0028,#06H	; mu8_Counter1h,6 		;[INF] 4, 1
	bc	$?L0039						;[INF] 2, 4
; line   117
??bb05_Timer_Process:
; line   118
$DGL	0,41
	clrb	!?L0028	; mu8_Counter1h 			;[INF] 3, 1
; line   119
$DGL	0,42
	call	!!_Time1h					;[INF] 4, 3
??eb05_Timer_Process:
; line   120
?L0039:
?L0040:
??eb04_Timer_Process:
; line   121
?L0037:
?L0038:
??eb03_Timer_Process:
; line   122
?L0035:
?L0036:
??eb02_Timer_Process:
; line   123
?L0033:
?L0034:
??eb01_Timer_Process:
; line   124
?L0031:
?L0032:
??eb00_Timer_Process:
; line   125
?L0029:
?L0030:
; line   126
$DGL	0,49
??ef_Timer_Process:
	ret							;[INF] 1, 6
??ee_Timer_Process:
; line   132
_Time1ms:
$DGL	1,109
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_Time1ms:
; line   146
$DGL	0,15
	oneb	!_F_1ms_for_InputDigital			;[INF] 3, 1
; line   148
??bb00_Time1ms:
??eb00_Time1ms:
; line   149
??bb01_Time1ms:
??eb01_Time1ms:
; line   150
??bb02_Time1ms:
??eb02_Time1ms:
; line   151
??bb03_Time1ms:
??eb03_Time1ms:
; line   152
??bb04_Time1ms:
??eb04_Time1ms:
; line   153
??bb05_Time1ms:
??eb05_Time1ms:
; line   154
$DGL	0,23
??bb06_Time1ms:
	cmp0	!_gu8_TimerEffluentKey				;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_TimerEffluentKey				;[INF] 3, 2
?L0043:
?L0044:
	cmp0	!_gu8_TimerKeyProhibit				;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_TimerKeyProhibit				;[INF] 3, 2
?L0045:
?L0046:
??eb06_Time1ms:
; line   155
$DGL	0,24
??bb07_Time1ms:
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu16_TimerRecWait				;[INF] 3, 1
	skz							;[INF] 2, 1
	decw	!_gu16_TimerRecWait				;[INF] 3, 2
?L0047:
?L0048:
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu16_TimerTraWait				;[INF] 3, 1
	skz							;[INF] 2, 1
	decw	!_gu16_TimerTraWait				;[INF] 3, 2
?L0049:
?L0050:
	cmp0	!_gu8_TimerTrahalt				;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_TimerTrahalt				;[INF] 3, 2
?L0051:
?L0052:
	cmp0	!_gu8_TimerRecInt_Check				;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_TimerRecInt_Check				;[INF] 3, 2
?L0053:
?L0054:
??eb07_Time1ms:
; line   156
??bb08_Time1ms:
??eb08_Time1ms:
; line   158
$DGL	0,27
	mov	[hl+1],#00H	; i,0 				;[INF] 3, 1
?L0055:
	mov	a,[hl+1]	; i 				;[INF] 2, 1
	cmp	a,#022H	; 34 					;[INF] 2, 1
	bnc	$?L0056						;[INF] 2, 4
; line   159
??bb09_Time1ms:
; line   160
$DGL	0,29
	mov	a,[hl+1]	; i 				;[INF] 2, 1
	clrb	x						;[INF] 1, 1
	shrw	ax,5						;[INF] 2, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_DisplayControl_Data+6[bc]			;[INF] 3, 1
	cmp0	a						;[INF] 1, 1
	bz	$?L0058						;[INF] 2, 4
	mov	a,[hl+1]	; i 				;[INF] 2, 1
	clrb	x						;[INF] 1, 1
	shrw	ax,5						;[INF] 2, 1
	addw	ax,#loww (_DisplayControl_Data)			;[INF] 3, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de+6]					;[INF] 2, 1
	dec	a						;[INF] 1, 1
	mov	[de+6],a					;[INF] 2, 1
?L0058:
?L0059:
??eb09_Time1ms:
; line   161
$DGL	0,30
?L0057:
	inc	[hl+1]	; i 					;[INF] 3, 2
	br	$?L0055						;[INF] 2, 3
?L0056:
; line   162
$DGL	0,31
??ef_Time1ms:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_Time1ms:
; line   168
_Time10ms:
$DGL	1,156
??bf_Time10ms:
; line   170
$DGL	0,3
??bb00_Time10ms:
	cmp0	!_gu8_TimerFlic					;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_TimerFlic					;[INF] 3, 2
?L0062:
?L0063:
	cmp0	!_gu8_TimerFlic_S2				;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_TimerFlic_S2				;[INF] 3, 2
?L0064:
?L0065:
??eb00_Time10ms:
; line   171
$DGL	0,4
??bb01_Time10ms:
	cmp0	!_gu8_TimerHWWait				;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_TimerHWWait				;[INF] 3, 2
?L0066:
?L0067:
??eb01_Time10ms:
; line   172
??bb02_Time10ms:
??eb02_Time10ms:
; line   173
??bb03_Time10ms:
??eb03_Time10ms:
; line   174
??bb04_Time10ms:
??eb04_Time10ms:
; line   175
$DGL	0,8
??bb05_Time10ms:
	cmp0	!_gu8_Timer_ProhibitSW				;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_Timer_ProhibitSW				;[INF] 3, 2
?L0068:
?L0069:
	cmp0	!_gu8_Timer_ShortSW				;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_Timer_ShortSW				;[INF] 3, 2
?L0070:
?L0071:
??eb05_Time10ms:
; line   176
$DGL	0,9
??bb06_Time10ms:
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu16_TimerKeyDecide			;[INF] 3, 1
	skz							;[INF] 2, 1
	decw	!_gu16_TimerKeyDecide				;[INF] 3, 2
?L0072:
?L0073:
??eb06_Time10ms:
; line   177
$DGL	0,10
??bb07_Time10ms:
	cmp0	!_gu8_TimerError_Time				;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_TimerError_Time				;[INF] 3, 2
?L0074:
?L0075:
??eb07_Time10ms:
; line   178
??bb08_Time10ms:
??eb08_Time10ms:
; line   179
$DGL	0,12
??ef_Time10ms:
	ret							;[INF] 1, 6
??ee_Time10ms:
; line   185
_Time100ms:
$DGL	1,198
??bf_Time100ms:
; line   187
$DGL	0,3
??bb00_Time100ms:
	cmp0	!_gu8_TimerFOTA_Display				;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_TimerFOTA_Display				;[INF] 3, 2
?L0078:
?L0079:
??eb00_Time100ms:
; line   188
$DGL	0,4
??bb01_Time100ms:
	cmp0	!_gu8_TimerBootDisplay				;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_TimerBootDisplay				;[INF] 3, 2
?L0080:
?L0081:
	cmp0	!_gu8_TimerVersionDisplay			;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_TimerVersionDisplay			;[INF] 3, 2
?L0082:
?L0083:
??eb01_Time100ms:
; line   189
??bb02_Time100ms:
??eb02_Time100ms:
; line   190
??bb03_Time100ms:
??eb03_Time100ms:
; line   191
??bb04_Time100ms:
??eb04_Time100ms:
; line   192
$DGL	0,8
??bb05_Time100ms:
	cmp0	!_gu8_Timer_LongSW				;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_Timer_LongSW				;[INF] 3, 2
?L0084:
?L0085:
??eb05_Time100ms:
; line   193
$DGL	0,9
??bb06_Time100ms:
	cmp0	!_gu8_TimerKeyOnBreak				;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_TimerKeyOnBreak				;[INF] 3, 2
?L0086:
?L0087:
??eb06_Time100ms:
; line   194
$DGL	0,10
??bb07_Time100ms:
	cmp0	!_gu8_TimerTraWait_TimeShort			;[INF] 3, 1
	skz							;[INF] 2, 1
	dec	!_gu8_TimerTraWait_TimeShort			;[INF] 3, 2
?L0088:
?L0089:
??eb07_Time100ms:
; line   195
??bb08_Time100ms:
??eb08_Time100ms:
; line   196
$DGL	0,12
??ef_Time100ms:
	ret							;[INF] 1, 6
??ee_Time100ms:
; line   202
_Time1s:
$DGL	1,240
??bf_Time1s:
; line   204
??bb00_Time1s:
??eb00_Time1s:
; line   205
??bb01_Time1s:
??eb01_Time1s:
; line   206
??bb02_Time1s:
??eb02_Time1s:
; line   207
??bb03_Time1s:
??eb03_Time1s:
; line   208
$DGL	0,7
??bb04_Time1s:
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu16_TimerOper_1s				;[INF] 3, 1
	skz							;[INF] 2, 1
	decw	!_gu16_TimerOper_1s				;[INF] 3, 2
?L0092:
?L0093:
??eb04_Time1s:
; line   209
??bb05_Time1s:
??eb05_Time1s:
; line   210
??bb06_Time1s:
??eb06_Time1s:
; line   211
??bb07_Time1s:
??eb07_Time1s:
; line   212
??bb08_Time1s:
??eb08_Time1s:
; line   213
$DGL	0,12
??ef_Time1s:
	ret							;[INF] 1, 6
??ee_Time1s:
; line   219
_Time10s:
$DGL	1,282
??bf_Time10s:
; line   221
??bb00_Time10s:
??eb00_Time10s:
; line   222
??bb01_Time10s:
??eb01_Time10s:
; line   223
??bb02_Time10s:
??eb02_Time10s:
; line   224
??bb03_Time10s:
??eb03_Time10s:
; line   225
??bb04_Time10s:
??eb04_Time10s:
; line   226
??bb05_Time10s:
??eb05_Time10s:
; line   227
??bb06_Time10s:
??eb06_Time10s:
; line   228
??bb07_Time10s:
??eb07_Time10s:
; line   229
??bb08_Time10s:
??eb08_Time10s:
; line   230
$DGL	0,12
??ef_Time10s:
	ret							;[INF] 1, 6
??ee_Time10s:
; line   236
_Time1min:
$DGL	1,324
??bf_Time1min:
; line   238
??bb00_Time1min:
??eb00_Time1min:
; line   239
??bb01_Time1min:
??eb01_Time1min:
; line   240
??bb02_Time1min:
??eb02_Time1min:
; line   241
??bb03_Time1min:
??eb03_Time1min:
; line   242
??bb04_Time1min:
??eb04_Time1min:
; line   243
??bb05_Time1min:
??eb05_Time1min:
; line   244
??bb06_Time1min:
??eb06_Time1min:
; line   245
??bb07_Time1min:
??eb07_Time1min:
; line   246
??bb08_Time1min:
??eb08_Time1min:
; line   247
$DGL	0,12
??ef_Time1min:
	ret							;[INF] 1, 6
??ee_Time1min:
; line   253
_Time10min:
$DGL	1,366
??bf_Time10min:
; line   255
??bb00_Time10min:
??eb00_Time10min:
; line   256
??bb01_Time10min:
??eb01_Time10min:
; line   257
??bb02_Time10min:
??eb02_Time10min:
; line   258
??bb03_Time10min:
??eb03_Time10min:
; line   259
??bb04_Time10min:
??eb04_Time10min:
; line   260
??bb05_Time10min:
??eb05_Time10min:
; line   261
??bb06_Time10min:
??eb06_Time10min:
; line   262
??bb07_Time10min:
??eb07_Time10min:
; line   263
??bb08_Time10min:
??eb08_Time10min:
; line   264
$DGL	0,12
??ef_Time10min:
	ret							;[INF] 1, 6
??ee_Time10min:
; line   270
_Time1h:
$DGL	1,408
??bf_Time1h:
; line   272
??bb00_Time1h:
??eb00_Time1h:
; line   273
??bb01_Time1h:
??eb01_Time1h:
; line   274
??bb02_Time1h:
??eb02_Time1h:
; line   275
??bb03_Time1h:
??eb03_Time1h:
; line   276
??bb04_Time1h:
??eb04_Time1h:
; line   277
??bb05_Time1h:
??eb05_Time1h:
; line   278
??bb06_Time1h:
??eb06_Time1h:
; line   279
??bb07_Time1h:
??eb07_Time1h:
; line   280
??bb08_Time1h:
??eb08_Time1h:
; line   281
$DGL	0,12
??ef_Time1h:
	ret							;[INF] 1, 6
??ee_Time1h:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE

@@FIX	DSEG	BASEP

	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\Source\timer.c
;
; $FUNC Timer_Initialize(13)
;	void=(void)
;	CODE SIZE= 5 bytes, CLOCK_SIZE= 7 clocks, STACK_SIZE= 0 bytes
;
; $FUNC Timer_Base_Timer(21)
;	void=(void)
;	CODE SIZE= 126 bytes, CLOCK_SIZE= 84 clocks, STACK_SIZE= 4 bytes
;
; $CALL Seg_Control(33)
;	void=(void)
;
; $CALL DisplayOut(36)
;	void=(void)
;
; $CALL FadeProcess(37)
;	void=(void)
;
; $CALL Seg_Control(42)
;	void=(void)
;
; $CALL DisplayControl(46)
;	void=(void)
;
; $CALL Time1ms(48)
;	void=(void)
;
; $CALL Time10ms(55)
;	void=(void)
;
; $CALL SafetyLoop(69)
;	void=(void)
;
; $FUNC Timer_Process(78)
;	void=(void)
;	CODE SIZE= 97 bytes, CLOCK_SIZE= 71 clocks, STACK_SIZE= 4 bytes
;
; $CALL Time100ms(88)
;	void=(void)
;
; $CALL Time1s(95)
;	void=(void)
;
; $CALL Time10s(101)
;	void=(void)
;
; $CALL Time1min(107)
;	void=(void)
;
; $CALL Time10min(113)
;	void=(void)
;
; $CALL Time1h(119)
;	void=(void)
;
; $FUNC Time1ms(132)
;	void=(void)
;	CODE SIZE= 101 bytes, CLOCK_SIZE= 68 clocks, STACK_SIZE= 4 bytes
;
; $FUNC Time10ms(168)
;	void=(void)
;	CODE SIZE= 58 bytes, CLOCK_SIZE= 35 clocks, STACK_SIZE= 0 bytes
;
; $FUNC Time100ms(185)
;	void=(void)
;	CODE SIZE= 49 bytes, CLOCK_SIZE= 30 clocks, STACK_SIZE= 0 bytes
;
; $FUNC Time1s(202)
;	void=(void)
;	CODE SIZE= 10 bytes, CLOCK_SIZE= 11 clocks, STACK_SIZE= 0 bytes
;
; $FUNC Time10s(219)
;	void=(void)
;	CODE SIZE= 1 bytes, CLOCK_SIZE= 6 clocks, STACK_SIZE= 0 bytes
;
; $FUNC Time1min(236)
;	void=(void)
;	CODE SIZE= 1 bytes, CLOCK_SIZE= 6 clocks, STACK_SIZE= 0 bytes
;
; $FUNC Time10min(253)
;	void=(void)
;	CODE SIZE= 1 bytes, CLOCK_SIZE= 6 clocks, STACK_SIZE= 0 bytes
;
; $FUNC Time1h(270)
;	void=(void)
;	CODE SIZE= 1 bytes, CLOCK_SIZE= 6 clocks, STACK_SIZE= 0 bytes

; Target chip : R5F100PG
; Device file : V1.14 
