; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:56

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile Source\communication.c -oDefaultBuild -_msgo
;             ff -nq -i. -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild
;              -no -g2
; In-file   : Source\communication.c
; Asm-file  : DefaultBuild\communication.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		012EH,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, communication.c
$DGS	MOD_NAM, communication,	00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	SEC_NAM, @@VECT14,	U,	U,	00H,	078H,	00H,	00H
$DGS	STR_STR, .2fake,	00H,	0FFFEH,	08H,	0AH,	01H,	00H
$DGS	AUX_TAG, 01H,		029H
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
$DGS	AUX_EOS, 015H,		01H
$DGS	STR_STR, .4fake,	00H,	0FFFEH,	08H,	0AH,	01H,	00H
$DGS	AUX_TAG, 01H,		031H
$DGS	BIT_FLD, _lo,		00H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		04H
$DGS	BIT_FLD, _hi,		04H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		04H
$DGS	END_STR, .eos,		01H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 029H,		01H
$DGS	UNI_TAG, .5fake,	00H,	0FFFEH,	09H,	0CH,	01H,	00H
$DGS	AUX_TAG, 01H,		03AH
$DGS	MEB_UNI, _byte,		00H,	0FFFFH,	0CH,	0BH,	00H,	00H
$DGS	MEB_UNI, _Bit,		00H,	0FFFFH,	08H,	0BH,	01H,	00H
$DGS	AUX_STR, 015H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	MEB_UNI, _nibble,	00H,	0FFFFH,	08H,	0BH,	01H,	00H
$DGS	AUX_STR, 029H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	END_STR, .eos,		01H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 031H,		01H
$DGS	STR_STR, .13fake,	00H,	0FFFEH,	08H,	0AH,	01H,	00H
$DGS	AUX_TAG, 06H,		047H
$DGS	MEB_STR, _First,	00H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Second,	01H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Third,	02H,	0FFFFH,	0CH,	08H,	00H,	00H
$DGS	MEB_STR, _Level,	03H,	0FFFFH,	09H,	08H,	01H,	00H
$DGS	AUX_STR, 031H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	MEB_STR, _OnEdge,	04H,	0FFFFH,	09H,	08H,	01H,	00H
$DGS	AUX_STR, 031H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	MEB_STR, _OffEdge,	05H,	0FFFFH,	09H,	08H,	01H,	00H
$DGS	AUX_STR, 031H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	END_STR, .eos,		06H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 03AH,		06H
$DGS	STR_STR, .3fake,	00H,	0FFFEH,	08H,	0AH,	01H,	00H
$DGS	AUX_TAG, 02H,		06BH
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
$DGS	BIT_FLD, _b8,		08H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b9,		09H,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b10,		0AH,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b11,		0BH,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b12,		0CH,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b13,		0DH,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b14,		0EH,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	BIT_FLD, _b15,		0FH,	0FFFFH,	0CH,	012H,	01H,	00H
$DGS	AUX_BIT, 00H,		01H
$DGS	END_STR, .eos,		02H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 047H,		02H
$DGS	UNI_TAG, .15fake,	00H,	0FFFEH,	09H,	0CH,	01H,	00H
$DGS	AUX_TAG, 02H,		072H
$DGS	MEB_UNI, _WORD,		00H,	0FFFFH,	0EH,	0BH,	00H,	00H
$DGS	MEB_UNI, _BIT,		00H,	0FFFFH,	08H,	0BH,	01H,	00H
$DGS	AUX_STR, 047H,		00H,	02H,	00H,	00H,	00H,	00H,	00H
$DGS	END_STR, .eos,		02H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 06BH,		02H
$DGS	GLV_SYM, _Communication_Initialize,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	080H,	01H,	00H
$DGS	BEG_FUN, ??bf_Communication_Initialize,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 01EH,		00H,	076H
$DGS	BEG_BLK, ??bb00_Communication_Initialize,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 02H,		00H,	07AH
$DGS	END_BLK, ??eb00_Communication_Initialize,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02H
$DGS	BEG_BLK, ??bb01_Communication_Initialize,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03H,		00H,	00H
$DGS	END_BLK, ??eb01_Communication_Initialize,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	END_FUN, ??ef_Communication_Initialize,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	GLV_SYM, _CommunicationControl,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	086H,	01H,	00H
$DGS	BEG_FUN, ??bf_CommunicationControl,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 029H,		00H,	086H
$DGS	END_FUN, ??ef_CommunicationControl,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 04H
$DGS	GLV_SYM, _IntUartRx,	U,	U,	0E001H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	092H,	00H,	00H
$DGS	BEG_FUN, ??bf_IntUartRx,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 032H,		01AH,	08CH
$DGS	AUT_VAR, _recdata,	03H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	AUT_VAR, _work,		00H,	0FFFFH,	0EH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_IntUartRx,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	00H
$DGS	END_BLK, ??eb00_IntUartRx,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0FH
$DGS	END_FUN, ??ef_IntUartRx,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 015H
$DGS	GLV_SYM, _IntUartTx,	U,	U,	0E001H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	0A4H,	00H,	00H
$DGS	BEG_FUN, ??bf_IntUartTx,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 04CH,		04H,	096H
$DGS	BEG_BLK, ??bb00_IntUartTx,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 04H,		00H,	09AH
$DGS	END_BLK, ??eb00_IntUartTx,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 06H
$DGS	BEG_BLK, ??bb01_IntUartTx,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	09EH
$DGS	END_BLK, ??eb01_IntUartTx,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0CH
$DGS	BEG_BLK, ??bb02_IntUartTx,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0EH,		00H,	00H
$DGS	END_BLK, ??eb02_IntUartTx,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 010H
$DGS	END_FUN, ??ef_IntUartTx,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 011H
$DGS	GLV_SYM, _UartReceive,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	0C0H,	01H,	00H
$DGS	BEG_FUN, ??bf_UartReceive,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 062H,		04H,	0AAH
$DGS	FUN_ARG, _recdata,	02H,	0FFFFH,	0CH,	09H,	00H,	00H
$DGS	AUT_VAR, _mu8_test,	01H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_UartReceive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 05H,		00H,	0AEH
$DGS	END_BLK, ??eb00_UartReceive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	BEG_BLK, ??bb01_UartReceive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0DH,		00H,	0B0H
$DGS	BEG_BLK, ??bb02_UartReceive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0FH,		00H,	0B4H
$DGS	END_BLK, ??eb02_UartReceive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 012H
$DGS	BEG_BLK, ??bb03_UartReceive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 014H,		00H,	0BAH
$DGS	END_BLK, ??eb03_UartReceive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 016H
$DGS	END_BLK, ??eb01_UartReceive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 017H
$DGS	BEG_BLK, ??bb04_UartReceive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01DH,		00H,	00H
$DGS	END_BLK, ??eb04_UartReceive,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 01FH
$DGS	END_FUN, ??ef_UartReceive,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 020H
$DGS	GLV_SYM, _TXControl,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	0D0H,	01H,	00H
$DGS	BEG_FUN, ??bf_TXControl,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 087H,		02H,	0C6H
$DGS	AUT_VAR, _i,		01H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	AUT_VAR, _F_TraOnce,	00H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_TXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 06H,		00H,	0C8H
$DGS	BEG_BLK, ??bb01_TXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0EH,		00H,	00H
$DGS	END_BLK, ??eb01_TXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 010H
$DGS	END_BLK, ??eb00_TXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 026H
$DGS	END_FUN, ??ef_TXControl,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 033H
$DGS	GLV_SYM, _RXControl,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	0F1H,	01H,	00H
$DGS	BEG_FUN, ??bf_RXControl,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0BFH,		04H,	0D7H
$DGS	AUT_VAR, _result,	03H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	AUT_VAR, _work,		02H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	AUT_VAR, _i,		01H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_RXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0FH,		00H,	0D9H
$DGS	BEG_BLK, ??bb01_RXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 017H,		00H,	0DDH
$DGS	END_BLK, ??eb01_RXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 01AH
$DGS	BEG_BLK, ??bb02_RXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01FH,		00H,	0E1H
$DGS	END_BLK, ??eb02_RXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 026H
$DGS	BEG_BLK, ??bb03_RXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 028H,		00H,	0E7H
$DGS	END_BLK, ??eb03_RXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02AH
$DGS	END_BLK, ??eb00_RXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 02CH
$DGS	BEG_BLK, ??bb04_RXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 02FH,		00H,	0EBH
$DGS	END_BLK, ??eb04_RXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 035H
$DGS	BEG_BLK, ??bb05_RXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 038H,		00H,	00H
$DGS	END_BLK, ??eb05_RXControl,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 03BH
$DGS	END_FUN, ??ef_RXControl,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03CH
$DGS	GLV_SYM, _Crc_Check,	U,	U,	0CH,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	0102H,	01H,	00H
$DGS	BEG_FUN, ??bf_Crc_Check,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0100H,		06H,	0F8H
$DGS	AUT_VAR, _work1,	04H,	0FFFFH,	0EH,	01H,	00H,	00H
$DGS	AUT_VAR, _work2,	02H,	0FFFFH,	0EH,	01H,	00H,	00H
$DGS	AUT_VAR, _ret,		01H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_Crc_Check,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0AH,		00H,	0FCH
$DGS	END_BLK, ??eb00_Crc_Check,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0CH
$DGS	BEG_BLK, ??bb01_Crc_Check,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0EH,		00H,	00H
$DGS	END_BLK, ??eb01_Crc_Check,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 010H
$DGS	END_FUN, ??ef_Crc_Check,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 012H
$DGS	GLV_SYM, _Data_Parsing,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	010DH,	01H,	00H
$DGS	BEG_FUN, ??bf_Data_Parsing,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0117H,		02H,	0107H
$DGS	AUT_VAR, _mu16_buff,	00H,	0FFFFH,	0EH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_Data_Parsing,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 037H,		00H,	00H
$DGS	END_BLK, ??eb00_Data_Parsing,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 03DH
$DGS	END_FUN, ??ef_Data_Parsing,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 049H
$DGS	GLV_SYM, _SendData,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	0113H,	01H,	00H
$DGS	BEG_FUN, ??bf_SendData,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0165H,		02H,	0113H
$DGS	END_FUN, ??ef_SendData,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 032H
$DGS	GLV_SYM, _TraCrcCheck,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	011FH,	01H,	00H
$DGS	BEG_FUN, ??bf_TraCrcCheck,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 019CH,		04H,	0119H
$DGS	AUT_VAR, _i,		02H,	0FFFFH,	0EH,	01H,	00H,	00H
$DGS	AUT_VAR, _work,		00H,	0FFFFH,	0EH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_TraCrcCheck,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 06H,		00H,	00H
$DGS	END_BLK, ??eb00_TraCrcCheck,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 09H
$DGS	END_FUN, ??ef_TraCrcCheck,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	GLV_SYM, _Uart_SFR_Refresh,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	012EH,	01H,	00H
$DGS	BEG_FUN, ??bf_Uart_SFR_Refresh,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 01ABH,		02H,	0124H
$DGS	AUT_VAR, _work,		01H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	BEG_BLK, ??bb00_Uart_SFR_Refresh,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 08H,		00H,	0128H
$DGS	END_BLK, ??eb00_Uart_SFR_Refresh,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 08H
$DGS	BEG_BLK, ??bb01_Uart_SFR_Refresh,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09H,		00H,	00H
$DGS	END_BLK, ??eb01_Uart_SFR_Refresh,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 09H
$DGS	END_FUN, ??ef_Uart_SFR_Refresh,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0AH
$DGS	GLV_SYM, _@vect14,	U,	U,	00H,	026H,	00H,	00H
$DGS	GLV_SYM, _@vect16,	U,	U,	00H,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerError_Time,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_UartState,	U,	U,	09H,	026H,	01H,	00H
$DGS	AUX_STR, 031H,		00H,	01H,	00H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_CounterRecvCount,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_CounterTraDataCount,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Buffer_RecCrc,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Buffer_TraCrc,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Buffer_MCU_RecData,	U,	U,	09H,	026H,	01H,	03H
$DGS	AUX_STR, 031H,		00H,	039H,	039H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_Buffer_MCU_TraData,	U,	U,	09H,	026H,	01H,	03H
$DGS	AUX_STR, 031H,		00H,	011H,	011H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_Buffer_MCU_TraData_Backup,	U,	U,	09H,	026H,	01H,	03H
$DGS	AUX_STR, 031H,		00H,	0FH,	0FH,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_ErrorHistory,	U,	U,	0CH,	026H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	05H,	05H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_Ecode_ErrHistory,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_TimerRecWait,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_TimerTraWait,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerTraWait_TimeShort,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerTrahalt,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerRecInt_Check,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_CounterRXDError,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _F_Communication_Error,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _F_FirstCommunication,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_OperationStep,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_SEGMENT_CMD,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_SEGMENT_OXX,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_SEGMENT_XOX,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_SEGMENT_XXO,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_EFFLUENT,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_mL,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_FILTER_CHANGE,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_FAUCET,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_CON,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_1Bottle,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_2CUP,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_1CUP,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_HALFCUP,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_DEGREE,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_AMOUNT,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_COLD_BLUE,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_COLD_WHITE,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_COLD,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_PURE,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_HOT,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_HOTLOCK,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_WIFI,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_UV1,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_UV2,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_UV3,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_UV4,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_UV5,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_UV6,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_UV7,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_UV8,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_LED_UV9,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_Hot_TempBar_5,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_Hot_TempBar_4,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_Hot_TempBar_3,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_Hot_TempBar_2,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_Hot_TempBar_1,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_Percent,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_Main_ProgramVer,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_Main_Tx_Start,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_F_MainTransmitting,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_testttt,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_test_1111,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_test_2222,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_test_3333,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu32_test_commu_count,	U,	U,	0FH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu32_test_refresh_count,	U,	U,	0FH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_test_ddd,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_test_deed,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_test_de,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu32_test_comeeemu_count,	U,	U,	0FH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu32_test_refreseah_count,	U,	U,	0FH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu32_test_txcount,	U,	U,	0FH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu32_test_rxcount,	U,	U,	0FH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu32_test_tx_halt,	U,	U,	0FH,	026H,	00H,	00H
$DGS	GLV_SYM, _crc_table1,	U,	U,	0500EH,	026H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	0200H,	0100H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_F_Voice_Play_ForCommu,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu16_Voice_Address_ForCommu,	U,	U,	0EH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_Voice_VolumeLevel_ForCommu,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_VoiceVolumeLevel,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _Play_Voice,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _gu32_Count_VoiceTest,	U,	U,	0FH,	02H,	00H,	00H
$DGS	GLV_SYM, _F_FOTA_Display,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_Fade_Select,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_ON_DimmingPercent,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_DimmingPercent,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_DimmingPercent_Low,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_OperationStep,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _gu8_DigitalInput2,	U,	U,	08H,	02H,	01H,	00H
$DGS	AUX_STR, 03AH,		00H,	06H,	00H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu16_ShortKeyArray,	U,	U,	09H,	02H,	01H,	00H
$DGS	AUX_STR, 06BH,		00H,	02H,	00H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_DigitalInput,	U,	U,	08H,	02H,	01H,	00H
$DGS	AUX_STR, 03AH,		00H,	06H,	00H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_DigitalInput3,	U,	U,	08H,	02H,	01H,	00H
$DGS	AUX_STR, 03AH,		00H,	06H,	00H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _R_UART2_Stop,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _R_UART2_Create,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _R_UART2_Start,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H
$DGS	GLV_SYM, _@RTARG6,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@RTARG4,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@RTARG2,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@RTARG0,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@SEGDE,	U,	U,	00H,	02H,	00H,	00H
$DGS	GLV_SYM, _@SEGAX,	U,	U,	00H,	02H,	00H,	00H

	EXTRN	_@RTARG6
	EXTRN	_@RTARG4
	EXTRN	_@RTARG2
	EXTRN	_@RTARG0
	EXTRN	_@SEGDE
	EXTRN	_@SEGAX
	EXTRN	_gu8_F_Voice_Play_ForCommu
	EXTRN	_gu16_Voice_Address_ForCommu
	EXTRN	_gu8_Voice_VolumeLevel_ForCommu
	EXTRN	_gu8_VoiceVolumeLevel
	EXTRN	_Play_Voice
	EXTRN	_gu32_Count_VoiceTest
	EXTRN	_F_FOTA_Display
	EXTRN	_gu8_Fade_Select
	EXTRN	_gu8_ON_DimmingPercent
	EXTRN	_gu8_DimmingPercent
	EXTRN	_gu8_DimmingPercent_Low
	EXTRN	_gu8_OperationStep
	EXTRN	_gu8_DigitalInput2
	EXTRN	_gu16_ShortKeyArray
	EXTRN	_gu8_DigitalInput
	EXTRN	_gu8_DigitalInput3
	EXTRN	_R_UART2_Stop
	EXTRN	_R_UART2_Create
	EXTRN	_R_UART2_Start
	PUBLIC	_IntUartRx
	PUBLIC	_IntUartTx
	PUBLIC	_gu8_TimerError_Time
	PUBLIC	_gu8_UartState
	PUBLIC	_gu8_CounterRecvCount
	PUBLIC	_gu8_CounterTraDataCount
	PUBLIC	_gu8_Buffer_RecCrc
	PUBLIC	_gu8_Buffer_TraCrc
	PUBLIC	_gu8_Buffer_MCU_RecData
	PUBLIC	_gu8_Buffer_MCU_TraData
	PUBLIC	_gu8_Buffer_MCU_TraData_Backup
	PUBLIC	_gu8_ErrorHistory
	PUBLIC	_gu8_Ecode_ErrHistory
	PUBLIC	_gu16_TimerRecWait
	PUBLIC	_gu16_TimerTraWait
	PUBLIC	_gu8_TimerTraWait_TimeShort
	PUBLIC	_gu8_TimerTrahalt
	PUBLIC	_gu8_TimerRecInt_Check
	PUBLIC	_gu8_CounterRXDError
	PUBLIC	_F_Communication_Error
	PUBLIC	_F_FirstCommunication
	PUBLIC	_gu8_Main_OperationStep
	PUBLIC	_gu8_Main_SEGMENT_CMD
	PUBLIC	_gu8_Main_SEGMENT_OXX
	PUBLIC	_gu8_Main_SEGMENT_XOX
	PUBLIC	_gu8_Main_SEGMENT_XXO
	PUBLIC	_gu8_Main_LED_EFFLUENT
	PUBLIC	_gu8_Main_LED_mL
	PUBLIC	_gu8_Main_LED_FILTER_CHANGE
	PUBLIC	_gu8_Main_LED_FAUCET
	PUBLIC	_gu8_Main_LED_CON
	PUBLIC	_gu8_Main_LED_1Bottle
	PUBLIC	_gu8_Main_LED_2CUP
	PUBLIC	_gu8_Main_LED_1CUP
	PUBLIC	_gu8_Main_LED_HALFCUP
	PUBLIC	_gu8_Main_LED_DEGREE
	PUBLIC	_gu8_Main_LED_AMOUNT
	PUBLIC	_gu8_Main_LED_COLD_BLUE
	PUBLIC	_gu8_Main_LED_COLD_WHITE
	PUBLIC	_gu8_Main_LED_COLD
	PUBLIC	_gu8_Main_LED_PURE
	PUBLIC	_gu8_Main_LED_HOT
	PUBLIC	_gu8_Main_LED_HOTLOCK
	PUBLIC	_gu8_Main_LED_WIFI
	PUBLIC	_gu8_Main_LED_UV1
	PUBLIC	_gu8_Main_LED_UV2
	PUBLIC	_gu8_Main_LED_UV3
	PUBLIC	_gu8_Main_LED_UV4
	PUBLIC	_gu8_Main_LED_UV5
	PUBLIC	_gu8_Main_LED_UV6
	PUBLIC	_gu8_Main_LED_UV7
	PUBLIC	_gu8_Main_LED_UV8
	PUBLIC	_gu8_Main_LED_UV9
	PUBLIC	_gu8_Main_Hot_TempBar_5
	PUBLIC	_gu8_Main_Hot_TempBar_4
	PUBLIC	_gu8_Main_Hot_TempBar_3
	PUBLIC	_gu8_Main_Hot_TempBar_2
	PUBLIC	_gu8_Main_Hot_TempBar_1
	PUBLIC	_gu8_Main_Percent
	PUBLIC	_gu16_Main_ProgramVer
	PUBLIC	_gu8_Main_Tx_Start
	PUBLIC	_gu8_F_MainTransmitting
	PUBLIC	_gu8_testttt
	PUBLIC	_gu16_test_1111
	PUBLIC	_gu16_test_2222
	PUBLIC	_gu16_test_3333
	PUBLIC	_gu32_test_commu_count
	PUBLIC	_gu32_test_refresh_count
	PUBLIC	_gu16_test_ddd
	PUBLIC	_gu16_test_deed
	PUBLIC	_gu16_test_de
	PUBLIC	_gu32_test_comeeemu_count
	PUBLIC	_gu32_test_refreseah_count
	PUBLIC	_gu32_test_txcount
	PUBLIC	_gu32_test_rxcount
	PUBLIC	_gu32_test_tx_halt
	PUBLIC	_crc_table1
	PUBLIC	_Communication_Initialize
	PUBLIC	_CommunicationControl
	PUBLIC	_UartReceive
	PUBLIC	_TXControl
	PUBLIC	_RXControl
	PUBLIC	_Crc_Check
	PUBLIC	_Data_Parsing
	PUBLIC	_SendData
	PUBLIC	_TraCrcCheck
	PUBLIC	_Uart_SFR_Refresh
	PUBLIC	_@vect14
	PUBLIC	_@vect16

@@BITS	BSEG

@@CNST	CSEG	MIRRORP
_crc_table1:	DW	00H	; 0
	DW	01021H	; 4129
	DW	02042H	; 8258
	DW	03063H	; 12387
	DW	04084H	; 16516
	DW	050A5H	; 20645
	DW	060C6H	; 24774
	DW	070E7H	; 28903
	DW	08108H	; 33032
	DW	09129H	; 37161
	DW	0A14AH	; 41290
	DW	0B16BH	; 45419
	DW	0C18CH	; 49548
	DW	0D1ADH	; 53677
	DW	0E1CEH	; 57806
	DW	0F1EFH	; 61935
	DW	01231H	; 4657
	DW	0210H	; 528
	DW	03273H	; 12915
	DW	02252H	; 8786
	DW	052B5H	; 21173
	DW	04294H	; 17044
	DW	072F7H	; 29431
	DW	062D6H	; 25302
	DW	09339H	; 37689
	DW	08318H	; 33560
	DW	0B37BH	; 45947
	DW	0A35AH	; 41818
	DW	0D3BDH	; 54205
	DW	0C39CH	; 50076
	DW	0F3FFH	; 62463
	DW	0E3DEH	; 58334
	DW	02462H	; 9314
	DW	03443H	; 13379
	DW	0420H	; 1056
	DW	01401H	; 5121
	DW	064E6H	; 25830
	DW	074C7H	; 29895
	DW	044A4H	; 17572
	DW	05485H	; 21637
	DW	0A56AH	; 42346
	DW	0B54BH	; 46411
	DW	08528H	; 34088
	DW	09509H	; 38153
	DW	0E5EEH	; 58862
	DW	0F5CFH	; 62927
	DW	0C5ACH	; 50604
	DW	0D58DH	; 54669
	DW	03653H	; 13907
	DW	02672H	; 9842
	DW	01611H	; 5649
	DW	0630H	; 1584
	DW	076D7H	; 30423
	DW	066F6H	; 26358
	DW	05695H	; 22165
	DW	046B4H	; 18100
	DW	0B75BH	; 46939
	DW	0A77AH	; 42874
	DW	09719H	; 38681
	DW	08738H	; 34616
	DW	0F7DFH	; 63455
	DW	0E7FEH	; 59390
	DW	0D79DH	; 55197
	DW	0C7BCH	; 51132
	DW	048C4H	; 18628
	DW	058E5H	; 22757
	DW	06886H	; 26758
	DW	078A7H	; 30887
	DW	0840H	; 2112
	DW	01861H	; 6241
	DW	02802H	; 10242
	DW	03823H	; 14371
	DW	0C9CCH	; 51660
	DW	0D9EDH	; 55789
	DW	0E98EH	; 59790
	DW	0F9AFH	; 63919
	DW	08948H	; 35144
	DW	09969H	; 39273
	DW	0A90AH	; 43274
	DW	0B92BH	; 47403
	DW	05AF5H	; 23285
	DW	04AD4H	; 19156
	DW	07AB7H	; 31415
	DW	06A96H	; 27286
	DW	01A71H	; 6769
	DW	0A50H	; 2640
	DW	03A33H	; 14899
	DW	02A12H	; 10770
	DW	0DBFDH	; 56317
	DW	0CBDCH	; 52188
	DW	0FBBFH	; 64447
	DW	0EB9EH	; 60318
	DW	09B79H	; 39801
	DW	08B58H	; 35672
	DW	0BB3BH	; 47931
	DW	0AB1AH	; 43802
	DW	06CA6H	; 27814
	DW	07C87H	; 31879
	DW	04CE4H	; 19684
	DW	05CC5H	; 23749
	DW	02C22H	; 11298
	DW	03C03H	; 15363
	DW	0C60H	; 3168
	DW	01C41H	; 7233
	DW	0EDAEH	; 60846
	DW	0FD8FH	; 64911
	DW	0CDECH	; 52716
	DW	0DDCDH	; 56781
	DW	0AD2AH	; 44330
	DW	0BD0BH	; 48395
	DW	08D68H	; 36200
	DW	09D49H	; 40265
	DW	07E97H	; 32407
	DW	06EB6H	; 28342
	DW	05ED5H	; 24277
	DW	04EF4H	; 20212
	DW	03E13H	; 15891
	DW	02E32H	; 11826
	DW	01E51H	; 7761
	DW	0E70H	; 3696
	DW	0FF9FH	; 65439
	DW	0EFBEH	; 61374
	DW	0DFDDH	; 57309
	DW	0CFFCH	; 53244
	DW	0BF1BH	; 48923
	DW	0AF3AH	; 44858
	DW	09F59H	; 40793
	DW	08F78H	; 36728
	DW	09188H	; 37256
	DW	081A9H	; 33193
	DW	0B1CAH	; 45514
	DW	0A1EBH	; 41451
	DW	0D10CH	; 53516
	DW	0C12DH	; 49453
	DW	0F14EH	; 61774
	DW	0E16FH	; 57711
	DW	01080H	; 4224
	DW	0A1H	; 161
	DW	030C2H	; 12482
	DW	020E3H	; 8419
	DW	05004H	; 20484
	DW	04025H	; 16421
	DW	07046H	; 28742
	DW	06067H	; 24679
	DW	083B9H	; 33721
	DW	09398H	; 37784
	DW	0A3FBH	; 41979
	DW	0B3DAH	; 46042
	DW	0C33DH	; 49981
	DW	0D31CH	; 54044
	DW	0E37FH	; 58239
	DW	0F35EH	; 62302
	DW	02B1H	; 689
	DW	01290H	; 4752
	DW	022F3H	; 8947
	DW	032D2H	; 13010
	DW	04235H	; 16949
	DW	05214H	; 21012
	DW	06277H	; 25207
	DW	07256H	; 29270
	DW	0B5EAH	; 46570
	DW	0A5CBH	; 42443
	DW	095A8H	; 38312
	DW	08589H	; 34185
	DW	0F56EH	; 62830
	DW	0E54FH	; 58703
	DW	0D52CH	; 54572
	DW	0C50DH	; 50445
	DW	034E2H	; 13538
	DW	024C3H	; 9411
	DW	014A0H	; 5280
	DW	0481H	; 1153
	DW	07466H	; 29798
	DW	06447H	; 25671
	DW	05424H	; 21540
	DW	04405H	; 17413
	DW	0A7DBH	; 42971
	DW	0B7FAH	; 47098
	DW	08799H	; 34713
	DW	097B8H	; 38840
	DW	0E75FH	; 59231
	DW	0F77EH	; 63358
	DW	0C71DH	; 50973
	DW	0D73CH	; 55100
	DW	026D3H	; 9939
	DW	036F2H	; 14066
	DW	0691H	; 1681
	DW	016B0H	; 5808
	DW	06657H	; 26199
	DW	07676H	; 30326
	DW	04615H	; 17941
	DW	05634H	; 22068
	DW	0D94CH	; 55628
	DW	0C96DH	; 51565
	DW	0F90EH	; 63758
	DW	0E92FH	; 59695
	DW	099C8H	; 39368
	DW	089E9H	; 35305
	DW	0B98AH	; 47498
	DW	0A9ABH	; 43435
	DW	05844H	; 22596
	DW	04865H	; 18533
	DW	07806H	; 30726
	DW	06827H	; 26663
	DW	018C0H	; 6336
	DW	08E1H	; 2273
	DW	03882H	; 14466
	DW	028A3H	; 10403
	DW	0CB7DH	; 52093
	DW	0DB5CH	; 56156
	DW	0EB3FH	; 60223
	DW	0FB1EH	; 64286
	DW	08BF9H	; 35833
	DW	09BD8H	; 39896
	DW	0ABBBH	; 43963
	DW	0BB9AH	; 48026
	DW	04A75H	; 19061
	DW	05A54H	; 23124
	DW	06A37H	; 27191
	DW	07A16H	; 31254
	DW	0AF1H	; 2801
	DW	01AD0H	; 6864
	DW	02AB3H	; 10931
	DW	03A92H	; 14994
	DW	0FD2EH	; 64814
	DW	0ED0FH	; 60687
	DW	0DD6CH	; 56684
	DW	0CD4DH	; 52557
	DW	0BDAAH	; 48554
	DW	0AD8BH	; 44427
	DW	09DE8H	; 40424
	DW	08DC9H	; 36297
	DW	07C26H	; 31782
	DW	06C07H	; 27655
	DW	05C64H	; 23652
	DW	04C45H	; 19525
	DW	03CA2H	; 15522
	DW	02C83H	; 11395
	DW	01CE0H	; 7392
	DW	0CC1H	; 3265
	DW	0EF1FH	; 61215
	DW	0FF3EH	; 65342
	DW	0CF5DH	; 53085
	DW	0DF7CH	; 57212
	DW	0AF9BH	; 44955
	DW	0BFBAH	; 49082
	DW	08FD9H	; 36825
	DW	09FF8H	; 40952
	DW	06E17H	; 28183
	DW	07E36H	; 32310
	DW	04E55H	; 20053
	DW	05E74H	; 24180
	DW	02E93H	; 11923
	DW	03EB2H	; 16050
	DW	0ED1H	; 3793
	DW	01EF0H	; 7920

@@R_INIT	CSEG	UNIT64KP

@@INIT	DSEG	BASEP

@@DATA	DSEG	BASEP
_gu8_TimerError_Time:	DS	(1)
_gu8_UartState:	DS	(1)
_gu8_CounterRecvCount:	DS	(1)
_gu8_CounterTraDataCount:	DS	(1)
_gu8_Buffer_RecCrc:	DS	(2)
_gu8_Buffer_TraCrc:	DS	(2)
_gu8_Buffer_MCU_RecData:	DS	(57)
	DS	(1)
_gu8_Buffer_MCU_TraData:	DS	(17)
	DS	(1)
_gu8_Buffer_MCU_TraData_Backup:	DS	(15)
_gu8_ErrorHistory:	DS	(5)
_gu8_Ecode_ErrHistory:	DS	(1)
	DS	(1)
_gu16_TimerRecWait:	DS	(2)
_gu16_TimerTraWait:	DS	(2)
_gu8_TimerTraWait_TimeShort:	DS	(1)
_gu8_TimerTrahalt:	DS	(1)
_gu8_TimerRecInt_Check:	DS	(1)
_gu8_CounterRXDError:	DS	(1)
_F_Communication_Error:	DS	(1)
_F_FirstCommunication:	DS	(1)
_gu8_Main_OperationStep:	DS	(1)
_gu8_Main_SEGMENT_CMD:	DS	(1)
_gu8_Main_SEGMENT_OXX:	DS	(1)
_gu8_Main_SEGMENT_XOX:	DS	(1)
_gu8_Main_SEGMENT_XXO:	DS	(1)
_gu8_Main_LED_EFFLUENT:	DS	(1)
_gu8_Main_LED_mL:	DS	(1)
_gu8_Main_LED_FILTER_CHANGE:	DS	(1)
_gu8_Main_LED_FAUCET:	DS	(1)
_gu8_Main_LED_CON:	DS	(1)
_gu8_Main_LED_1Bottle:	DS	(1)
_gu8_Main_LED_2CUP:	DS	(1)
_gu8_Main_LED_1CUP:	DS	(1)
_gu8_Main_LED_HALFCUP:	DS	(1)
_gu8_Main_LED_DEGREE:	DS	(1)
_gu8_Main_LED_AMOUNT:	DS	(1)
_gu8_Main_LED_COLD_BLUE:	DS	(1)
_gu8_Main_LED_COLD_WHITE:	DS	(1)
_gu8_Main_LED_COLD:	DS	(1)
_gu8_Main_LED_PURE:	DS	(1)
_gu8_Main_LED_HOT:	DS	(1)
_gu8_Main_LED_HOTLOCK:	DS	(1)
_gu8_Main_LED_WIFI:	DS	(1)
_gu8_Main_LED_UV1:	DS	(1)
_gu8_Main_LED_UV2:	DS	(1)
_gu8_Main_LED_UV3:	DS	(1)
_gu8_Main_LED_UV4:	DS	(1)
_gu8_Main_LED_UV5:	DS	(1)
_gu8_Main_LED_UV6:	DS	(1)
_gu8_Main_LED_UV7:	DS	(1)
_gu8_Main_LED_UV8:	DS	(1)
_gu8_Main_LED_UV9:	DS	(1)
_gu8_Main_Hot_TempBar_5:	DS	(1)
_gu8_Main_Hot_TempBar_4:	DS	(1)
_gu8_Main_Hot_TempBar_3:	DS	(1)
_gu8_Main_Hot_TempBar_2:	DS	(1)
_gu8_Main_Hot_TempBar_1:	DS	(1)
_gu8_Main_Percent:	DS	(1)
_gu16_Main_ProgramVer:	DS	(2)
_gu8_Main_Tx_Start:	DS	(1)
_gu8_F_MainTransmitting:	DS	(1)
_gu8_testttt:	DS	(1)
	DS	(1)
_gu16_test_1111:	DS	(2)
_gu16_test_2222:	DS	(2)
_gu16_test_3333:	DS	(2)
_gu32_test_commu_count:	DS	(4)
_gu32_test_refresh_count:	DS	(4)
_gu16_test_ddd:	DS	(2)
_gu16_test_deed:	DS	(2)
_gu16_test_de:	DS	(2)
_gu32_test_comeeemu_count:	DS	(4)
_gu32_test_refreseah_count:	DS	(4)
_gu32_test_txcount:	DS	(4)
_gu32_test_rxcount:	DS	(4)
_gu32_test_tx_halt:	DS	(4)

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
; line   169
; line   170
; line   171
; line   172
; line   173
; line   174
; line   175
; line   176
; line   177
; line   178
; line   179
; line   180
; line   181
; line   182
; line   183
; line   184
; line   185
; line   186
; line   187
; line   188
; line   189
; line   190
; line   191
; line   192
; line   193
; line   194
; line   195
; line   196
; line   197
; line   198
; line   199
; line   200
; line   211
; line   213
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
; line    30

@@CODEL	CSEG
_Communication_Initialize:
$DGL	1,114
??bf_Communication_Initialize:
; line    31
$DGL	0,2
??bb00_Communication_Initialize:
	clr1	IF0H.0						;[INF] 3, 2
	clr1	MK0H.0						;[INF] 3, 2
	mov	a,!SOE1L					;[INF] 3, 1
	or	a,#01H	; 1 					;[INF] 2, 1
	mov	!SOE1L,a					;[INF] 3, 1
	mov	a,!SS1L						;[INF] 3, 1
	or	a,#01H	; 1 					;[INF] 2, 1
	mov	!SS1L,a						;[INF] 3, 1
??eb00_Communication_Initialize:
; line    32
$DGL	0,3
??bb01_Communication_Initialize:
	clr1	IF0H.1						;[INF] 3, 2
	clr1	MK0H.1						;[INF] 3, 2
	mov	a,!SS1L						;[INF] 3, 1
	or	a,#02H	; 2 					;[INF] 2, 1
	mov	!SS1L,a						;[INF] 3, 1
??eb01_Communication_Initialize:
; line    33
$DGL	0,4
	mov	!_gu8_TimerError_Time,#0C8H	; 200 		;[INF] 4, 1
; line    34
$DGL	0,5
	mov	!_gu8_TimerRecInt_Check,#01EH	; 30 		;[INF] 4, 1
; line    35
$DGL	0,6
??ef_Communication_Initialize:
	ret							;[INF] 1, 6
??ee_Communication_Initialize:
; line    41
_CommunicationControl:
$DGL	1,128
??bf_CommunicationControl:
; line    42
$DGL	0,2
	call	!!_TXControl					;[INF] 4, 3
; line    43
$DGL	0,3
	call	!!_RXControl					;[INF] 4, 3
; line    44
$DGL	0,4
??ef_CommunicationControl:
	ret							;[INF] 1, 6
??ee_CommunicationControl:
; line    50

@@BASE	CSEG	BASE
_IntUartRx:
$DGL	1,134
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
	subw	sp,#04H						;[INF] 2, 1
	movw	hl,sp						;[INF] 3, 1
??bf_IntUartRx:
; line    55
$DGL	0,6
	mov	!_gu8_TimerRecInt_Check,#01EH	; 30 		;[INF] 4, 1
; line    57
$DGL	0,8
	movw	ax,!SSR11					;[INF] 3, 1
	mov	a,x						;[INF] 1, 1
	and	a,#07H	; 7 					;[INF] 2, 1
	cmp0	a						;[INF] 1, 1
	bz	$?L0007						;[INF] 2, 4
; line    58
??bb00_IntUartRx:
; line    59
$DGL	0,10
	mov	a,RXD2						;[INF] 2, 1
	shrw	ax,8						;[INF] 2, 1
	movw	[hl],ax	; work 					;[INF] 1, 1
; line    60
$DGL	0,11
	mov	x,#07H	; 7 					;[INF] 2, 1
	movw	!SIR11,ax					;[INF] 3, 1
; line    61
$DGL	0,12
	call	!!_Uart_SFR_Refresh				;[INF] 4, 3
; line    62
$DGL	0,13
	incw	!_gu32_test_refresh_count			;[INF] 3, 2
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu32_test_refresh_count			;[INF] 3, 1
	sknz							;[INF] 2, 1
	incw	!_gu32_test_refresh_count+2			;[INF] 3, 2
?L0009:
; line    63
$DGL	0,14
	br	$?L0006						;[INF] 2, 3
??eb00_IntUartRx:
; line    64
?L0007:
?L0008:
; line    66
$DGL	0,17
	mov	a,RXD2						;[INF] 2, 1
	shrw	ax,8						;[INF] 2, 1
	movw	[hl],ax	; work 					;[INF] 1, 1
; line    67
$DGL	0,18
	mov	a,[hl]	; work 					;[INF] 1, 1
	mov	[hl+3],a	; recdata 			;[INF] 2, 1
; line    69
$DGL	0,20
	shrw	ax,8						;[INF] 2, 1
	call	!!_UartReceive					;[INF] 4, 3
; line    70
?L0006:
; line    70
$DGL	0,21
??ef_IntUartRx:
	addw	sp,#04H						;[INF] 2, 1
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
??ee_IntUartRx:
; line    76
_IntUartTx:
$DGL	1,146
	push	ax						;[INF] 1, 1
	push	bc						;[INF] 1, 1
??bf_IntUartTx:
; line    78
$DGL	0,3
	movw	ax,!SSR10					;[INF] 3, 1
	mov	a,x						;[INF] 1, 1
	and	a,#046H	; 70 					;[INF] 2, 1
	cmp0	a						;[INF] 1, 1
	skz							;[INF] 2, 1
; line    79
??bb00_IntUartTx:
; line    80
$DGL	0,5
	br	$?L0011						;[INF] 2, 3
??eb00_IntUartTx:
; line    81
?L0012:
?L0013:
; line    83
$DGL	0,8
	cmp	!_gu8_CounterTraDataCount,#0FH	; 15 		;[INF] 4, 1
	bnc	$?L0014						;[INF] 2, 4
; line    84
??bb01_IntUartTx:
; line    85
$DGL	0,10
	mov	b,!_gu8_CounterTraDataCount			;[INF] 3, 1
	mov	a,_gu8_Buffer_MCU_TraData[b]			;[INF] 3, 1
	mov	TXD2,a						;[INF] 2, 1
; line    86
$DGL	0,11
	inc	!_gu8_CounterTraDataCount			;[INF] 3, 2
??eb01_IntUartTx:
; line    88
$DGL	0,13
	br	$?L0015						;[INF] 2, 3
?L0014:
; line    89
??bb02_IntUartTx:
; line    90
$DGL	0,15
	clrb	!_gu8_F_MainTransmitting			;[INF] 3, 1
??eb02_IntUartTx:
; line    91
?L0015:
; line    92
?L0011:
; line    92
$DGL	0,17
??ef_IntUartTx:
	pop	bc						;[INF] 1, 1
	pop	ax						;[INF] 1, 1
	reti							;[INF] 2, 6
??ee_IntUartTx:
; line    98

@@CODEL	CSEG
_UartReceive:
$DGL	1,164
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_UartReceive:
; line    99
$DGL	0,2
	mov	[hl+1],#00H	; mu8_test,0 			;[INF] 3, 1
; line   101
$DGL	0,4
	mov	a,!_gu8_UartState				;[INF] 3, 1
	bf	a.1,$?L0018					;[INF] 3, 5
; line   102
??bb00_UartReceive:
; line   103
$DGL	0,6
	clr1	!_gu8_UartState.1				;[INF] 4, 2
; line   104
$DGL	0,7
	clrb	!_gu8_CounterRecvCount				;[INF] 3, 1
; line   105
$DGL	0,8
	call	!!_Uart_SFR_Refresh				;[INF] 4, 3
; line   106
$DGL	0,9
	br	$?L0017						;[INF] 2, 3
??eb00_UartReceive:
; line   107
?L0018:
?L0019:
; line   109
$DGL	0,12
	cmp0	!_gu8_CounterRecvCount				;[INF] 3, 1
	bnz	$?L0020						;[INF] 2, 4
; line   110
??bb01_UartReceive:
; line   111
$DGL	0,14
	mov	a,[hl+2]	; recdata 			;[INF] 2, 1
	cmp	a,#02H	; 2 					;[INF] 2, 1
	bz	$?L0022						;[INF] 2, 4
; line   112
??bb02_UartReceive:
; line   113
$DGL	0,16
	clrb	!_gu8_CounterRecvCount				;[INF] 3, 1
; line   114
$DGL	0,17
	br	$?L0017						;[INF] 2, 3
??eb02_UartReceive:
; line   116
$DGL	0,19
	br	$?L0023						;[INF] 2, 3
?L0022:
; line   117
??bb03_UartReceive:
; line   118
$DGL	0,21
	inc	[hl+1]	; mu8_test 				;[INF] 3, 2
??eb03_UartReceive:
; line   119
?L0023:
??eb01_UartReceive:
; line   120
?L0020:
?L0021:
; line   122
$DGL	0,25
	mov	b,!_gu8_CounterRecvCount			;[INF] 3, 1
	mov	a,[hl+2]	; recdata 			;[INF] 2, 1
	mov	_gu8_Buffer_MCU_RecData[b],a			;[INF] 3, 1
; line   124
$DGL	0,27
	inc	!_gu8_CounterRecvCount				;[INF] 3, 2
; line   125
$DGL	0,28
	cmp	!_gu8_CounterRecvCount,#037H	; 55 		;[INF] 4, 1
	skc							;[INF] 2, 1
; line   126
??bb04_UartReceive:
; line   127
$DGL	0,30
	set1	!_gu8_UartState.1				;[INF] 4, 2
??eb04_UartReceive:
; line   128
?L0024:
?L0025:
; line   129
?L0017:
; line   129
$DGL	0,32
??ef_UartReceive:
	addw	sp,#04H						;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_UartReceive:
; line   135
_TXControl:
$DGL	1,192
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_TXControl:
; line   137
$DGL	0,3
	mov	[hl+0],#00H	; F_TraOnce,0 			;[INF] 3, 1
; line   139
$DGL	0,5
	cmp	!_gu8_Main_Tx_Start,#01H	; 1 		;[INF] 4, 1
	bnz	$?L0028						;[INF] 2, 4
	cmp0	!_gu8_F_MainTransmitting			;[INF] 3, 1
	bnz	$?L0028						;[INF] 2, 4
; line   140
??bb00_TXControl:
; line   141
$DGL	0,7
	incw	!_gu32_test_txcount				;[INF] 3, 2
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu32_test_txcount				;[INF] 3, 1
	sknz							;[INF] 2, 1
	incw	!_gu32_test_txcount+2				;[INF] 3, 2
?L0030:
; line   143
$DGL	0,9
	clrb	!_gu8_Main_Tx_Start				;[INF] 3, 1
; line   144
$DGL	0,10
	oneb	!_gu8_F_MainTransmitting			;[INF] 3, 1
; line   146
$DGL	0,12
	clrb	!_gu8_testttt					;[INF] 3, 1
; line   147
$DGL	0,13
	mov	[hl+1],#00H	; i,0 				;[INF] 3, 1
?L0031:
	mov	a,[hl+1]	; i 				;[INF] 2, 1
	cmp	a,#0FH	; 15 					;[INF] 2, 1
	bnc	$?L0032						;[INF] 2, 4
; line   148
??bb01_TXControl:
; line   149
$DGL	0,15
	mov	a,[hl+1]	; i 				;[INF] 2, 1
	mov	c,a						;[INF] 1, 1
	mov	_gu8_Buffer_MCU_TraData[c],#00H	; 0 		;[INF] 4, 1
??eb01_TXControl:
; line   150
$DGL	0,16
?L0033:
	inc	[hl+1]	; i 					;[INF] 3, 2
	br	$?L0031						;[INF] 2, 3
?L0032:
; line   152
$DGL	0,18
	call	!!_SendData					;[INF] 4, 3
; line   154
$DGL	0,20
	movw	ax,#0C8H	; 200 				;[INF] 3, 1
	movw	!_gu16_TimerTraWait,ax				;[INF] 3, 1
; line   155
$DGL	0,21
	clrb	!_gu8_CounterTraDataCount			;[INF] 3, 1
; line   156
$DGL	0,22
	clr1	!_gu8_UartState.3				;[INF] 4, 2
; line   157
$DGL	0,23
	set1	!_gu8_UartState.4				;[INF] 4, 2
; line   158
$DGL	0,24
	mov	!_gu8_TimerTrahalt,#0C8H	; 200 		;[INF] 4, 1
; line   160
$DGL	0,26
	mov	a,!_gu8_Buffer_MCU_TraData			;[INF] 3, 1
	mov	TXD2,a						;[INF] 2, 1
; line   161
$DGL	0,27
	inc	!_gu8_CounterTraDataCount			;[INF] 3, 2
??eb00_TXControl:
; line   172
?L0028:
?L0029:
; line   185
$DGL	0,51
??ef_TXControl:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_TXControl:
; line   191
_RXControl:
$DGL	1,208
	push	hl						;[INF] 1, 1
	subw	sp,#04H						;[INF] 2, 1
	movw	hl,sp						;[INF] 3, 1
??bf_RXControl:
; line   204
$DGL	0,14
	mov	a,!_gu8_UartState				;[INF] 3, 1
	bf	a.1,$?L0036					;[INF] 3, 5
; line   205
??bb00_RXControl:
; line   206
$DGL	0,16
	clr1	!_gu8_UartState.1				;[INF] 4, 2
; line   207
$DGL	0,17
	clrb	!_gu8_CounterRecvCount				;[INF] 3, 1
; line   209
$DGL	0,19
	incw	!_gu32_test_rxcount				;[INF] 3, 2
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu32_test_rxcount				;[INF] 3, 1
	sknz							;[INF] 2, 1
	incw	!_gu32_test_rxcount+2				;[INF] 3, 2
?L0038:
; line   210
$DGL	0,20
	clrw	ax						;[INF] 1, 1
	movw	!_gu8_Buffer_RecCrc,ax				;[INF] 3, 1
; line   212
$DGL	0,22
	mov	[hl+1],a	; i 				;[INF] 2, 1
?L0039:
	mov	a,[hl+1]	; i 				;[INF] 2, 1
	cmp	a,#035H	; 53 					;[INF] 2, 1
	bnc	$?L0040						;[INF] 2, 4
; line   213
??bb01_RXControl:
; line   214
$DGL	0,24
	mov	x,!_gu8_Buffer_RecCrc+1				;[INF] 3, 1
	clrb	a						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,[hl+1]	; i 				;[INF] 2, 1
	shrw	ax,8						;[INF] 2, 1
	addw	ax,#loww (_gu8_Buffer_MCU_RecData)		;[INF] 3, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de]						;[INF] 1, 1
	xor	c,a						;[INF] 2, 1
	mov	a,c						;[INF] 1, 1
	mov	[hl+2],a	; work 				;[INF] 2, 1
; line   215
$DGL	0,25
	movw	ax,!_gu8_Buffer_RecCrc				;[INF] 3, 1
	shlw	ax,8						;[INF] 2, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,[hl+2]	; work 				;[INF] 2, 1
	shrw	ax,7						;[INF] 2, 1
	addw	ax,#mirlw (_crc_table1)				;[INF] 3, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de]						;[INF] 1, 1
	xor	a,c						;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	mov	a,[de+1]					;[INF] 2, 1
	xor	a,b						;[INF] 2, 1
	movw	!_gu8_Buffer_RecCrc,ax				;[INF] 3, 1
??eb01_RXControl:
; line   216
$DGL	0,26
?L0041:
	inc	[hl+1]	; i 					;[INF] 3, 2
	br	$?L0039						;[INF] 2, 3
?L0040:
; line   218
$DGL	0,28
	call	!!_Crc_Check					;[INF] 4, 3
	mov	a,c						;[INF] 1, 1
	mov	[hl+3],a	; result 			;[INF] 2, 1
; line   220
$DGL	0,30
	dec	a						;[INF] 1, 1
	bnz	$?L0042						;[INF] 2, 4
; line   221
??bb02_RXControl:
; line   222
$DGL	0,32
	oneb	!_gu8_Main_Tx_Start				;[INF] 3, 1
; line   223
$DGL	0,33
	clrb	!_F_Communication_Error				;[INF] 3, 1
; line   224
$DGL	0,34
	oneb	!_F_FirstCommunication				;[INF] 3, 1
; line   225
$DGL	0,35
	clrb	!_gu8_CounterRXDError				;[INF] 3, 1
; line   226
$DGL	0,36
	mov	!_gu8_TimerError_Time,#0C8H	; 200 		;[INF] 4, 1
; line   227
$DGL	0,37
	call	!!_Data_Parsing					;[INF] 4, 3
??eb02_RXControl:
; line   229
$DGL	0,39
	br	$?L0043						;[INF] 2, 3
?L0042:
; line   230
??bb03_RXControl:
; line   231
$DGL	0,41
	call	!!_Uart_SFR_Refresh				;[INF] 4, 3
??eb03_RXControl:
; line   232
?L0043:
??eb00_RXControl:
; line   234
?L0036:
?L0037:
; line   236
$DGL	0,46
	cmp0	!_gu8_TimerError_Time				;[INF] 3, 1
	bnz	$?L0044						;[INF] 2, 4
; line   237
??bb04_RXControl:
; line   238
$DGL	0,48
	clrb	!_gu8_CounterRecvCount				;[INF] 3, 1
; line   239
$DGL	0,49
	inc	!_gu8_CounterRXDError				;[INF] 3, 2
; line   240
$DGL	0,50
	call	!!_Uart_SFR_Refresh				;[INF] 4, 3
; line   242
$DGL	0,52
	mov	!_gu8_TimerError_Time,#0C8H	; 200 		;[INF] 4, 1
??eb04_RXControl:
; line   243
?L0044:
?L0045:
; line   245
$DGL	0,55
	cmp	!_gu8_CounterRXDError,#05H	; 5 		;[INF] 4, 1
	bc	$?L0046						;[INF] 2, 4
; line   246
??bb05_RXControl:
; line   247
$DGL	0,57
	mov	!_gu8_CounterRXDError,#05H	; 5 		;[INF] 4, 1
; line   248
$DGL	0,58
	oneb	!_F_Communication_Error				;[INF] 3, 1
??eb05_RXControl:
; line   249
?L0046:
?L0047:
; line   250
$DGL	0,60
??ef_RXControl:
	addw	sp,#04H						;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_RXControl:
; line   256
_Crc_Check:
$DGL	1,241
	push	hl						;[INF] 1, 1
	subw	sp,#06H						;[INF] 2, 1
	movw	hl,sp						;[INF] 3, 1
??bf_Crc_Check:
; line   261
$DGL	0,6
	mov	x,!_gu8_Buffer_MCU_RecData+53			;[INF] 3, 1
	clrb	a						;[INF] 1, 1
	movw	[hl+4],ax	; work1 			;[INF] 2, 1
; line   262
$DGL	0,7
	mov	x,!_gu8_Buffer_MCU_RecData+54			;[INF] 3, 1
	shlw	ax,8						;[INF] 2, 1
	movw	[hl+2],ax	; work2 			;[INF] 2, 1
; line   264
$DGL	0,9
	mov	a,[hl+4]	; work1 			;[INF] 2, 1
	or	a,[hl+2]	; work2 			;[INF] 2, 1
	mov	x,a						;[INF] 1, 1
	mov	a,[hl+5]	; work1 			;[INF] 2, 1
	or	a,[hl+3]	; work2 			;[INF] 2, 1
	cmpw	ax,!_gu8_Buffer_RecCrc				;[INF] 3, 1
	bnz	$?L0050						;[INF] 2, 4
; line   265
??bb00_Crc_Check:
; line   266
$DGL	0,11
	mov	[hl+1],#01H	; ret,1 			;[INF] 3, 1
??eb00_Crc_Check:
; line   268
$DGL	0,13
	br	$?L0051						;[INF] 2, 3
?L0050:
; line   269
??bb01_Crc_Check:
; line   270
$DGL	0,15
	mov	[hl+1],#00H	; ret,0 			;[INF] 3, 1
??eb01_Crc_Check:
; line   271
?L0051:
; line   272
$DGL	0,17
	mov	a,[hl+1]	; ret 				;[INF] 2, 1
	shrw	ax,8						;[INF] 2, 1
	movw	bc,ax						;[INF] 1, 1
; line   273
?L0049:
; line   273
$DGL	0,18
??ef_Crc_Check:
	addw	sp,#06H						;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_Crc_Check:
; line   279
_Data_Parsing:
$DGL	1,258
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_Data_Parsing:
; line   280
$DGL	0,2
	clrw	ax						;[INF] 1, 1
	movw	[hl],ax	; mu16_buff 				;[INF] 1, 1
; line   283
$DGL	0,5
	mov	a,!_gu8_Buffer_MCU_RecData+3			;[INF] 3, 1
	mov	!_gu8_Main_OperationStep,a			;[INF] 3, 1
; line   285
$DGL	0,7
	mov	a,!_gu8_Buffer_MCU_RecData+4			;[INF] 3, 1
	mov	!_gu8_Main_SEGMENT_CMD,a			;[INF] 3, 1
; line   286
$DGL	0,8
	mov	a,!_gu8_Buffer_MCU_RecData+5			;[INF] 3, 1
	mov	!_gu8_Main_SEGMENT_OXX,a			;[INF] 3, 1
; line   287
$DGL	0,9
	mov	a,!_gu8_Buffer_MCU_RecData+6			;[INF] 3, 1
	mov	!_gu8_Main_SEGMENT_XOX,a			;[INF] 3, 1
; line   288
$DGL	0,10
	mov	a,!_gu8_Buffer_MCU_RecData+7			;[INF] 3, 1
	mov	!_gu8_Main_SEGMENT_XXO,a			;[INF] 3, 1
; line   289
$DGL	0,11
	mov	a,!_gu8_Buffer_MCU_RecData+8			;[INF] 3, 1
	mov	!_gu8_Main_LED_EFFLUENT,a			;[INF] 3, 1
; line   290
$DGL	0,12
	mov	a,!_gu8_Buffer_MCU_RecData+9			;[INF] 3, 1
	mov	!_gu8_Main_LED_mL,a				;[INF] 3, 1
; line   291
$DGL	0,13
	mov	a,!_gu8_Buffer_MCU_RecData+10			;[INF] 3, 1
	mov	!_gu8_Main_LED_FILTER_CHANGE,a			;[INF] 3, 1
; line   292
$DGL	0,14
	mov	a,!_gu8_Buffer_MCU_RecData+11			;[INF] 3, 1
	mov	!_gu8_Main_LED_FAUCET,a				;[INF] 3, 1
; line   293
$DGL	0,15
	mov	a,!_gu8_Buffer_MCU_RecData+12			;[INF] 3, 1
	mov	!_gu8_Main_LED_CON,a				;[INF] 3, 1
; line   294
$DGL	0,16
	mov	a,!_gu8_Buffer_MCU_RecData+13			;[INF] 3, 1
	mov	!_gu8_Main_LED_1Bottle,a			;[INF] 3, 1
; line   295
$DGL	0,17
	mov	a,!_gu8_Buffer_MCU_RecData+14			;[INF] 3, 1
	mov	!_gu8_Main_LED_2CUP,a				;[INF] 3, 1
; line   296
$DGL	0,18
	mov	a,!_gu8_Buffer_MCU_RecData+15			;[INF] 3, 1
	mov	!_gu8_Main_LED_1CUP,a				;[INF] 3, 1
; line   297
$DGL	0,19
	mov	a,!_gu8_Buffer_MCU_RecData+16			;[INF] 3, 1
	mov	!_gu8_Main_LED_HALFCUP,a			;[INF] 3, 1
; line   298
$DGL	0,20
	mov	a,!_gu8_Buffer_MCU_RecData+17			;[INF] 3, 1
	mov	!_gu8_Main_LED_DEGREE,a				;[INF] 3, 1
; line   299
$DGL	0,21
	mov	a,!_gu8_Buffer_MCU_RecData+18			;[INF] 3, 1
	mov	!_gu8_Main_LED_AMOUNT,a				;[INF] 3, 1
; line   300
$DGL	0,22
	mov	a,!_gu8_Buffer_MCU_RecData+19			;[INF] 3, 1
	mov	!_gu8_Main_LED_COLD_BLUE,a			;[INF] 3, 1
; line   301
$DGL	0,23
	mov	a,!_gu8_Buffer_MCU_RecData+20			;[INF] 3, 1
	mov	!_gu8_Main_LED_COLD_WHITE,a			;[INF] 3, 1
; line   302
$DGL	0,24
	mov	a,!_gu8_Buffer_MCU_RecData+21			;[INF] 3, 1
	mov	!_gu8_Main_LED_COLD,a				;[INF] 3, 1
; line   303
$DGL	0,25
	mov	a,!_gu8_Buffer_MCU_RecData+22			;[INF] 3, 1
	mov	!_gu8_Main_LED_PURE,a				;[INF] 3, 1
; line   304
$DGL	0,26
	mov	a,!_gu8_Buffer_MCU_RecData+23			;[INF] 3, 1
	mov	!_gu8_Main_LED_HOT,a				;[INF] 3, 1
; line   305
$DGL	0,27
	mov	a,!_gu8_Buffer_MCU_RecData+24			;[INF] 3, 1
	mov	!_gu8_Main_LED_HOTLOCK,a			;[INF] 3, 1
; line   306
$DGL	0,28
	mov	a,!_gu8_Buffer_MCU_RecData+25			;[INF] 3, 1
	mov	!_gu8_Main_LED_WIFI,a				;[INF] 3, 1
; line   307
$DGL	0,29
	mov	a,!_gu8_Buffer_MCU_RecData+26			;[INF] 3, 1
	mov	!_gu8_Main_LED_UV1,a				;[INF] 3, 1
; line   308
$DGL	0,30
	mov	a,!_gu8_Buffer_MCU_RecData+27			;[INF] 3, 1
	mov	!_gu8_Main_LED_UV2,a				;[INF] 3, 1
; line   309
$DGL	0,31
	mov	a,!_gu8_Buffer_MCU_RecData+28			;[INF] 3, 1
	mov	!_gu8_Main_LED_UV3,a				;[INF] 3, 1
; line   310
$DGL	0,32
	mov	a,!_gu8_Buffer_MCU_RecData+29			;[INF] 3, 1
	mov	!_gu8_Main_LED_UV4,a				;[INF] 3, 1
; line   311
$DGL	0,33
	mov	a,!_gu8_Buffer_MCU_RecData+30			;[INF] 3, 1
	mov	!_gu8_Main_LED_UV5,a				;[INF] 3, 1
; line   312
$DGL	0,34
	mov	a,!_gu8_Buffer_MCU_RecData+31			;[INF] 3, 1
	mov	!_gu8_Main_LED_UV6,a				;[INF] 3, 1
; line   313
$DGL	0,35
	mov	a,!_gu8_Buffer_MCU_RecData+32			;[INF] 3, 1
	mov	!_gu8_Main_LED_UV7,a				;[INF] 3, 1
; line   314
$DGL	0,36
	mov	a,!_gu8_Buffer_MCU_RecData+33			;[INF] 3, 1
	mov	!_gu8_Main_LED_UV8,a				;[INF] 3, 1
; line   315
$DGL	0,37
	mov	a,!_gu8_Buffer_MCU_RecData+34			;[INF] 3, 1
	mov	!_gu8_Main_LED_UV9,a				;[INF] 3, 1
; line   316
$DGL	0,38
	mov	a,!_gu8_Buffer_MCU_RecData+35			;[INF] 3, 1
	mov	!_gu8_Main_Hot_TempBar_5,a			;[INF] 3, 1
; line   317
$DGL	0,39
	mov	a,!_gu8_Buffer_MCU_RecData+36			;[INF] 3, 1
	mov	!_gu8_Main_Hot_TempBar_4,a			;[INF] 3, 1
; line   318
$DGL	0,40
	mov	a,!_gu8_Buffer_MCU_RecData+37			;[INF] 3, 1
	mov	!_gu8_Main_Hot_TempBar_3,a			;[INF] 3, 1
; line   319
$DGL	0,41
	mov	a,!_gu8_Buffer_MCU_RecData+38			;[INF] 3, 1
	mov	!_gu8_Main_Hot_TempBar_2,a			;[INF] 3, 1
; line   320
$DGL	0,42
	mov	a,!_gu8_Buffer_MCU_RecData+39			;[INF] 3, 1
	mov	!_gu8_Main_Hot_TempBar_1,a			;[INF] 3, 1
; line   321
$DGL	0,43
	mov	a,!_gu8_Buffer_MCU_RecData+40			;[INF] 3, 1
	mov	!_gu8_Main_Percent,a				;[INF] 3, 1
; line   324
$DGL	0,46
	mov	a,!_gu8_Buffer_MCU_RecData+41			;[INF] 3, 1
	mov	!_gu8_F_Voice_Play_ForCommu,a			;[INF] 3, 1
; line   326
$DGL	0,48
	mov	x,!_gu8_Buffer_MCU_RecData+42			;[INF] 3, 1
	clrb	a						;[INF] 1, 1
	movw	!_gu16_Voice_Address_ForCommu,ax		;[INF] 3, 1
; line   327
$DGL	0,49
	mov	a,!_gu8_Buffer_MCU_RecData+43			;[INF] 3, 1
	clrb	x						;[INF] 1, 1
	movw	[hl],ax	; mu16_buff 				;[INF] 1, 1
; line   328
$DGL	0,50
	addw	ax,!_gu16_Voice_Address_ForCommu		;[INF] 3, 1
	movw	!_gu16_Voice_Address_ForCommu,ax		;[INF] 3, 1
; line   330
$DGL	0,52
	mov	a,!_gu8_Buffer_MCU_RecData+44			;[INF] 3, 1
	mov	!_gu8_Voice_VolumeLevel_ForCommu,a		;[INF] 3, 1
; line   332
$DGL	0,54
	cmp	!_gu8_F_Voice_Play_ForCommu,#01H	; 1 	;[INF] 4, 1
	bnz	$?L0054						;[INF] 2, 4
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu16_Voice_Address_ForCommu		;[INF] 3, 1
	bz	$?L0054						;[INF] 2, 4
; line   333
??bb00_Data_Parsing:
; line   334
$DGL	0,56
	mov	a,!_gu8_Voice_VolumeLevel_ForCommu		;[INF] 3, 1
	mov	!_gu8_VoiceVolumeLevel,a			;[INF] 3, 1
; line   335
$DGL	0,57
	movw	ax,!_gu16_Voice_Address_ForCommu		;[INF] 3, 1
	call	!!_Play_Voice					;[INF] 4, 3
; line   336
$DGL	0,58
	clrb	!_gu8_F_Voice_Play_ForCommu			;[INF] 3, 1
; line   338
$DGL	0,60
	incw	!_gu32_Count_VoiceTest				;[INF] 3, 2
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu32_Count_VoiceTest			;[INF] 3, 1
	sknz							;[INF] 2, 1
	incw	!_gu32_Count_VoiceTest+2			;[INF] 3, 2
?L0056:
??eb00_Data_Parsing:
; line   339
?L0054:
?L0055:
; line   342
$DGL	0,64
	mov	a,!_gu8_Buffer_MCU_RecData+45			;[INF] 3, 1
	and	a,#01H	; 1 					;[INF] 2, 1
	mov	!_F_FOTA_Display,a				;[INF] 3, 1
; line   344
$DGL	0,66
	mov	a,!_gu8_Buffer_MCU_RecData+46			;[INF] 3, 1
	mov	!_gu8_Fade_Select,a				;[INF] 3, 1
; line   345
$DGL	0,67
	mov	a,!_gu8_Buffer_MCU_RecData+47			;[INF] 3, 1
	mov	!_gu8_ON_DimmingPercent,a			;[INF] 3, 1
; line   346
$DGL	0,68
	mov	a,!_gu8_Buffer_MCU_RecData+48			;[INF] 3, 1
	mov	!_gu8_DimmingPercent,a				;[INF] 3, 1
; line   347
$DGL	0,69
	mov	a,!_gu8_Buffer_MCU_RecData+49			;[INF] 3, 1
	mov	!_gu8_DimmingPercent_Low,a			;[INF] 3, 1
; line   349
$DGL	0,71
	mov	x,!_gu8_Buffer_MCU_RecData+50			;[INF] 3, 1
	clrb	a						;[INF] 1, 1
	movw	!_gu16_Main_ProgramVer,ax			;[INF] 3, 1
; line   350
$DGL	0,72
	mov	a,!_gu8_Buffer_MCU_RecData+51			;[INF] 3, 1
	clrb	x						;[INF] 1, 1
	or	a,!_gu16_Main_ProgramVer+1			;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	or	a,!_gu16_Main_ProgramVer			;[INF] 3, 1
	xch	a,x						;[INF] 1, 1
	movw	!_gu16_Main_ProgramVer,ax			;[INF] 3, 1
; line   351
$DGL	0,73
??ef_Data_Parsing:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_Data_Parsing:
; line   357
_SendData:
$DGL	1,269
	push	hl						;[INF] 1, 1
??bf_SendData:
; line   359
$DGL	0,3
	clrw	ax						;[INF] 1, 1
	movw	!_gu8_Buffer_TraCrc,ax				;[INF] 3, 1
; line   361
$DGL	0,5
	mov	!_gu8_Buffer_MCU_TraData,#02H	; 2 		;[INF] 4, 1
; line   362
$DGL	0,6
	mov	!_gu8_Buffer_MCU_TraData+1,#0F1H	; 241 	;[INF] 4, 1
; line   363
$DGL	0,7
	mov	!_gu8_Buffer_MCU_TraData+2,#011H	; 17 	;[INF] 4, 1
; line   364
$DGL	0,8
	mov	a,!_gu8_OperationStep				;[INF] 3, 1
	mov	!_gu8_Buffer_MCU_TraData+3,a			;[INF] 3, 1
; line   373
$DGL	0,17
	set1	!_gu8_DigitalInput2+3.0				;[INF] 4, 2
; line   374
$DGL	0,18
	movw	hl,#loww (_gu8_DigitalInput2+3)			;[INF] 3, 1
	mov1	CY,[hl].0					;[INF] 2, 1
	movw	hl,#loww (_gu8_Buffer_MCU_TraData+4)		;[INF] 3, 1
	mov1	[hl].0,CY					;[INF] 2, 2
; line   377
$DGL	0,21
	movw	hl,#loww (_gu16_ShortKeyArray)			;[INF] 3, 1
	mov1	CY,[hl].0					;[INF] 2, 1
	movw	hl,#loww (_gu8_Buffer_MCU_TraData+5)		;[INF] 3, 1
	mov1	[hl].0,CY					;[INF] 2, 2
; line   378
$DGL	0,22
	movw	hl,#loww (_gu16_ShortKeyArray)			;[INF] 3, 1
	mov1	CY,[hl].2					;[INF] 2, 1
	movw	hl,#loww (_gu8_Buffer_MCU_TraData+5)		;[INF] 3, 1
	mov1	[hl].1,CY					;[INF] 2, 2
; line   379
$DGL	0,23
	movw	hl,#loww (_gu16_ShortKeyArray)			;[INF] 3, 1
	mov1	CY,[hl].1					;[INF] 2, 1
	movw	hl,#loww (_gu8_Buffer_MCU_TraData+5)		;[INF] 3, 1
	mov1	[hl].2,CY					;[INF] 2, 2
; line   380
$DGL	0,24
	movw	hl,#loww (_gu16_ShortKeyArray)			;[INF] 3, 1
	mov1	CY,[hl].3					;[INF] 2, 1
	movw	hl,#loww (_gu8_Buffer_MCU_TraData+5)		;[INF] 3, 1
	mov1	[hl].3,CY					;[INF] 2, 2
; line   381
$DGL	0,25
	movw	hl,#loww (_gu16_ShortKeyArray)			;[INF] 3, 1
	mov1	CY,[hl].4					;[INF] 2, 1
	movw	hl,#loww (_gu8_Buffer_MCU_TraData+5)		;[INF] 3, 1
	mov1	[hl].4,CY					;[INF] 2, 2
; line   383
$DGL	0,27
	movw	hl,#loww (_gu8_DigitalInput+3)			;[INF] 3, 1
	mov1	CY,[hl].0					;[INF] 2, 1
	movw	hl,#loww (_gu8_Buffer_MCU_TraData+6)		;[INF] 3, 1
	mov1	[hl].0,CY					;[INF] 2, 2
; line   384
$DGL	0,28
	movw	hl,#loww (_gu8_DigitalInput+3)			;[INF] 3, 1
	mov1	CY,[hl].1					;[INF] 2, 1
	movw	hl,#loww (_gu8_Buffer_MCU_TraData+6)		;[INF] 3, 1
	mov1	[hl].1,CY					;[INF] 2, 2
; line   385
$DGL	0,29
	movw	hl,#loww (_gu8_DigitalInput+3)			;[INF] 3, 1
	mov1	CY,[hl].2					;[INF] 2, 1
	movw	hl,#loww (_gu8_Buffer_MCU_TraData+6)		;[INF] 3, 1
	mov1	[hl].2,CY					;[INF] 2, 2
; line   386
$DGL	0,30
	movw	hl,#loww (_gu8_DigitalInput+3)			;[INF] 3, 1
	mov1	CY,[hl].3					;[INF] 2, 1
	movw	hl,#loww (_gu8_Buffer_MCU_TraData+6)		;[INF] 3, 1
	mov1	[hl].3,CY					;[INF] 2, 2
; line   387
$DGL	0,31
	movw	hl,#loww (_gu8_DigitalInput3+3)			;[INF] 3, 1
	mov1	CY,[hl].0					;[INF] 2, 1
	movw	hl,#loww (_gu8_Buffer_MCU_TraData+6)		;[INF] 3, 1
	mov1	[hl].4,CY					;[INF] 2, 2
; line   390
$DGL	0,34
	mov	a,!_gu8_F_Voice_Play_ForCommu			;[INF] 3, 1
	mov	[hl+1],a					;[INF] 2, 1
; line   392
$DGL	0,36
	clrb	!_gu8_Buffer_MCU_TraData+8			;[INF] 3, 1
; line   393
$DGL	0,37
	clrb	!_gu8_Buffer_MCU_TraData+9			;[INF] 3, 1
; line   395
$DGL	0,39
	oneb	!_gu8_Buffer_MCU_TraData+10			;[INF] 3, 1
; line   396
$DGL	0,40
	mov	!_gu8_Buffer_MCU_TraData+11,#010H	; 16 	;[INF] 4, 1
; line   398
$DGL	0,42
	mov	!_gu8_Buffer_MCU_TraData+12,#03H	; 3 	;[INF] 4, 1
; line   399
$DGL	0,43
	call	!!_TraCrcCheck					;[INF] 4, 3
; line   400
$DGL	0,44
	mov	a,!_gu8_Buffer_TraCrc				;[INF] 3, 1
	mov	!_gu8_Buffer_MCU_TraData+13,a			;[INF] 3, 1
; line   401
$DGL	0,45
	movw	ax,!_gu8_Buffer_TraCrc				;[INF] 3, 1
	clrb	x						;[INF] 1, 1
	mov	!_gu8_Buffer_MCU_TraData+14,a			;[INF] 3, 1
; line   403
$DGL	0,47
	set1	!_gu8_UartState.3				;[INF] 4, 2
; line   405
$DGL	0,49
	clrw	ax						;[INF] 1, 1
	movw	!_gu16_ShortKeyArray,ax				;[INF] 3, 1
; line   406
$DGL	0,50
??ef_SendData:
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_SendData:
; line   412
_TraCrcCheck:
$DGL	1,275
	push	hl						;[INF] 1, 1
	subw	sp,#04H						;[INF] 2, 1
	movw	hl,sp						;[INF] 3, 1
??bf_TraCrcCheck:
; line   416
$DGL	0,5
	clrw	ax						;[INF] 1, 1
	movw	[hl+2],ax	; i 				;[INF] 2, 1
?L0061:
	movw	ax,[hl+2]	; i 				;[INF] 2, 1
	cmpw	ax,#0DH	; 13 					;[INF] 3, 1
	bnc	$?L0062						;[INF] 2, 4
; line   417
??bb00_TraCrcCheck:
; line   418
$DGL	0,7
	mov	x,!_gu8_Buffer_TraCrc+1				;[INF] 3, 1
	clrb	a						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	movw	ax,[hl+2]	; i 				;[INF] 2, 1
	addw	ax,#loww (_gu8_Buffer_MCU_TraData)		;[INF] 3, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de]						;[INF] 1, 1
	xor	c,a						;[INF] 2, 1
	movw	ax,bc						;[INF] 1, 1
	movw	[hl],ax	; work 					;[INF] 1, 1
; line   419
$DGL	0,8
	movw	ax,!_gu8_Buffer_TraCrc				;[INF] 3, 1
	shlw	ax,8						;[INF] 2, 1
	movw	bc,ax						;[INF] 1, 1
	movw	ax,[hl]	; work 					;[INF] 1, 1
	addw	ax,ax						;[INF] 1, 1
	addw	ax,#mirlw (_crc_table1)				;[INF] 3, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de]						;[INF] 1, 1
	xor	a,c						;[INF] 2, 1
	xch	a,x						;[INF] 1, 1
	mov	a,[de+1]					;[INF] 2, 1
	xor	a,b						;[INF] 2, 1
	movw	!_gu8_Buffer_TraCrc,ax				;[INF] 3, 1
??eb00_TraCrcCheck:
; line   420
$DGL	0,9
?L0063:
	incw	[hl+2]	; i 					;[INF] 3, 2
	br	$?L0061						;[INF] 2, 3
?L0062:
; line   421
$DGL	0,10
??ef_TraCrcCheck:
	addw	sp,#04H						;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_TraCrcCheck:
; line   427
_Uart_SFR_Refresh:
$DGL	1,287
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_Uart_SFR_Refresh:
; line   430
$DGL	0,4
	call	!!_R_UART2_Stop					;[INF] 4, 3
; line   431
$DGL	0,5
	call	!!_R_UART2_Create				;[INF] 4, 3
; line   432
$DGL	0,6
	call	!!_R_UART2_Start				;[INF] 4, 3
; line   434
$DGL	0,8
??bb00_Uart_SFR_Refresh:
	clr1	IF0H.0						;[INF] 3, 2
	clr1	MK0H.0						;[INF] 3, 2
	mov	a,!SOE1L					;[INF] 3, 1
	or	a,#01H	; 1 					;[INF] 2, 1
	mov	!SOE1L,a					;[INF] 3, 1
	mov	a,!SS1L						;[INF] 3, 1
	or	a,#01H	; 1 					;[INF] 2, 1
	mov	!SS1L,a						;[INF] 3, 1
??eb00_Uart_SFR_Refresh:
; line   435
$DGL	0,9
??bb01_Uart_SFR_Refresh:
	clr1	IF0H.1						;[INF] 3, 2
	clr1	MK0H.1						;[INF] 3, 2
	mov	a,!SS1L						;[INF] 3, 1
	or	a,#02H	; 2 					;[INF] 2, 1
	mov	!SS1L,a						;[INF] 3, 1
??eb01_Uart_SFR_Refresh:
; line   436
$DGL	0,10
??ef_Uart_SFR_Refresh:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_Uart_SFR_Refresh:

@@VECT14	CSEG	AT    0014H
_@vect14:
	DW	_IntUartTx
_@vect16:
	DW	_IntUartRx

@@CODE	CSEG	BASE

@@FIX	DSEG	BASEP

	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\Source\communication.c
;
; $FUNC Communication_Initialize(30)
;	void=(void)
;	CODE SIZE= 45 bytes, CLOCK_SIZE= 25 clocks, STACK_SIZE= 0 bytes
;
; $FUNC CommunicationControl(41)
;	void=(void)
;	CODE SIZE= 9 bytes, CLOCK_SIZE= 12 clocks, STACK_SIZE= 4 bytes
;
; $CALL TXControl(42)
;	void=(void)
;
; $CALL RXControl(43)
;	void=(void)
;
; $FUNC IntUartRx(50)
;	void=(void)
;	CODE SIZE= 120 bytes, CLOCK_SIZE= 85 clocks, STACK_SIZE= 30 bytes
;
; $CALL Uart_SFR_Refresh(61)
;	void=(void)
;
; $CALL UartReceive(69)
;	void=(int:ax)
;
; $FUNC IntUartTx(76)
;	void=(void)
;	CODE SIZE= 39 bytes, CLOCK_SIZE= 32 clocks, STACK_SIZE= 4 bytes
;
; $FUNC UartReceive(98)
;	void=(unsigned char recdata:x)
;	CODE SIZE= 74 bytes, CLOCK_SIZE= 57 clocks, STACK_SIZE= 10 bytes
;
; $CALL Uart_SFR_Refresh(105)
;	void=(void)
;
; $FUNC TXControl(135)
;	void=(void)
;	CODE SIZE= 97 bytes, CLOCK_SIZE= 62 clocks, STACK_SIZE= 8 bytes
;
; $CALL SendData(152)
;	void=(void)
;
; $FUNC RXControl(191)
;	void=(void)
;	CODE SIZE= 164 bytes, CLOCK_SIZE= 108 clocks, STACK_SIZE= 10 bytes
;
; $CALL Crc_Check(218)
;	bc=(void)
;
; $CALL Data_Parsing(227)
;	void=(void)
;
; $CALL Uart_SFR_Refresh(231)
;	void=(void)
;
; $CALL Uart_SFR_Refresh(240)
;	void=(void)
;
; $FUNC Crc_Check(256)
;	bc=(void)
;	CODE SIZE= 50 bytes, CLOCK_SIZE= 35 clocks, STACK_SIZE= 8 bytes
;
; $FUNC Data_Parsing(279)
;	void=(void)
;	CODE SIZE= 362 bytes, CLOCK_SIZE= 147 clocks, STACK_SIZE= 8 bytes
;
; $CALL Play_Voice(335)
;	void=(unsigned int:ax)
;
; $FUNC SendData(357)
;	void=(void)
;	CODE SIZE= 186 bytes, CLOCK_SIZE= 91 clocks, STACK_SIZE= 6 bytes
;
; $CALL TraCrcCheck(399)
;	void=(void)
;
; $FUNC TraCrcCheck(412)
;	void=(void)
;	CODE SIZE= 64 bytes, CLOCK_SIZE= 47 clocks, STACK_SIZE= 6 bytes
;
; $FUNC Uart_SFR_Refresh(427)
;	void=(void)
;	CODE SIZE= 56 bytes, CLOCK_SIZE= 37 clocks, STACK_SIZE= 8 bytes
;
; $CALL R_UART2_Stop(430)
;	void=(void)
;
; $CALL R_UART2_Create(431)
;	void=(void)
;
; $CALL R_UART2_Start(432)
;	void=(void)

; Target chip : R5F100PG
; Device file : V1.14 
