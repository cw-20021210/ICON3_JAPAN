; 78K0R C Compiler V2.72 Assembler Source        Date: 4 Mar 2026 Time:20:49:56

; Command   : -cf100pg -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile Source\keycontrol.c -oDefaultBuild -_msgoff 
;             -nq -i. -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -n
;             o -g2
; In-file   : Source\keycontrol.c
; Asm-file  : DefaultBuild\keycontrol.asm
; Para-file : 

$PROCESSOR(F100PG)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		015AH,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, keycontrol.c
$DGS	MOD_NAM, keycontrol,	00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	STR_STR, .3fake,	00H,	0FFFEH,	08H,	0AH,	01H,	00H
$DGS	AUX_TAG, 02H,		06AH
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
$DGS	AUX_EOS, 046H,		02H
$DGS	UNI_TAG, .15fake,	00H,	0FFFEH,	09H,	0CH,	01H,	00H
$DGS	AUX_TAG, 02H,		071H
$DGS	MEB_UNI, _WORD,		00H,	0FFFFH,	0EH,	0BH,	00H,	00H
$DGS	MEB_UNI, _BIT,		00H,	0FFFFH,	08H,	0BH,	01H,	00H
$DGS	AUX_STR, 046H,		00H,	02H,	00H,	00H,	00H,	00H,	00H
$DGS	END_STR, .eos,		02H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 06AH,		02H
$DGS	STR_STR, .32fake,	00H,	0FFFEH,	08H,	0AH,	01H,	00H
$DGS	AUX_TAG, 014H,		080H
$DGS	MEB_STR, _KeyData,	00H,	0FFFFH,	0500CH,	08H,	00H,	00H
$DGS	MEB_STR, _KeyNum,	02H,	0FFFFH,	0500EH,	08H,	00H,	00H
$DGS	MEB_STR, _ShortKeyTime,	04H,	0FFFFH,	0500EH,	08H,	00H,	00H
$DGS	MEB_STR, _ShortKeyType,	06H,	0FFFFH,	0500CH,	08H,	00H,	00H
$DGS	MEB_STR, _LongKeyTime,	08H,	0FFFFH,	0500EH,	08H,	00H,	00H
$DGS	MEB_STR, _LongKeyType,	0AH,	0FFFFH,	0500CH,	08H,	00H,	00H
$DGS	MEB_STR, _VeryLongKeyTime,	0CH,	0FFFFH,	0500EH,	08H,	00H,	00H
$DGS	MEB_STR, _VeryLongKeyType,	0EH,	0FFFFH,	0500CH,	08H,	00H,	00H
$DGS	MEB_STR, _FCTLongKeyTime,	010H,	0FFFFH,	0500EH,	08H,	00H,	00H
$DGS	MEB_STR, _FCTLongKeyType,	012H,	0FFFFH,	0500CH,	08H,	00H,	00H
$DGS	MEB_STR, _OnBreak,	013H,	0FFFFH,	0500CH,	08H,	00H,	00H
$DGS	END_STR, .eos,		014H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 071H,		014H
$DGS	GLV_SYM, _KeyControl_Initialize,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	086H,	01H,	00H
$DGS	BEG_FUN, ??bf_KeyControl_Initialize,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 04CH,		00H,	086H
$DGS	END_FUN, ??ef_KeyControl_Initialize,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	GLV_SYM, _EffluentKey_Decide,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	0A1H,	01H,	00H
$DGS	BEG_FUN, ??bf_EffluentKey_Decide,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 06AH,		00H,	08BH
$DGS	STA_SYM, _EffluentKey_Step,	?L0005,	U,	0CH,	03H,	00H,	00H
$DGS	BEG_BLK, ??bb00_EffluentKey_Decide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07H,		00H,	08DH
$DGS	BEG_BLK, ??bb01_EffluentKey_Decide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0AH,		00H,	091H
$DGS	END_BLK, ??eb01_EffluentKey_Decide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0DH
$DGS	BEG_BLK, ??bb02_EffluentKey_Decide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 011H,		00H,	095H
$DGS	END_BLK, ??eb02_EffluentKey_Decide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 013H
$DGS	BEG_BLK, ??bb03_EffluentKey_Decide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 016H,		00H,	099H
$DGS	END_BLK, ??eb03_EffluentKey_Decide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 019H
$DGS	BEG_BLK, ??bb04_EffluentKey_Decide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01DH,		00H,	00H
$DGS	END_BLK, ??eb04_EffluentKey_Decide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 01FH
$DGS	END_BLK, ??eb00_EffluentKey_Decide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 024H
$DGS	END_FUN, ??ef_EffluentKey_Decide,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 025H
$DGS	GLV_SYM, _KeyDecide,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	015AH,	01H,	00H
$DGS	BEG_FUN, ??bf_KeyDecide,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 094H,		04H,	0ACH
$DGS	FUN_ARG, _p,		02H,	0FFFFH,	08H,	09H,	01H,	01H
$DGS	AUX_STR, 039H,		00H,	02H,	00H,	00H,	00H,	00H,	01H
$DGS	AUT_VAR, _i,		01H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	AUT_VAR, _data,		00H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	STA_SYM, _buf,		?L0023,	U,	0CH,	03H,	00H,	00H
$DGS	STA_SYM, _KeyPnt,	?L0024,	U,	08H,	03H,	01H,	01H
$DGS	AUX_STR, 071H,		00H,	02H,	00H,	00H,	00H,	00H,	01H
$DGS	BEG_BLK, ??bb00_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0DH,		00H,	0AEH
$DGS	BEG_BLK, ??bb01_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 012H,		00H,	0B0H
$DGS	BEG_BLK, ??bb02_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 014H,		00H,	0B2H
$DGS	BEG_BLK, ??bb03_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 016H,		00H,	0B4H
$DGS	BEG_BLK, ??bb04_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 018H,		00H,	0B8H
$DGS	END_BLK, ??eb04_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 01AH
$DGS	BEG_BLK, ??bb05_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01EH,		00H,	0BCH
$DGS	END_BLK, ??eb05_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 021H
$DGS	BEG_BLK, ??bb06_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 023H,		00H,	0BEH
$DGS	BEG_BLK, ??bb07_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 02FH,		00H,	0CAH
$DGS	END_BLK, ??eb07_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 032H
$DGS	END_BLK, ??eb06_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 034H
$DGS	END_BLK, ??eb03_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 035H
$DGS	END_BLK, ??eb02_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 036H
$DGS	END_BLK, ??eb01_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 037H
$DGS	BEG_BLK, ??bb08_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03BH,		00H,	0CCH
$DGS	BEG_BLK, ??bb09_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 03FH,		00H,	0CEH
$DGS	BEG_BLK, ??bb0A_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 044H,		00H,	0D4H
$DGS	END_BLK, ??eb0A_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 046H
$DGS	END_BLK, ??eb09_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 047H
$DGS	BEG_BLK, ??bb0B_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 054H,		00H,	0D8H
$DGS	END_BLK, ??eb0B_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 057H
$DGS	BEG_BLK, ??bb0C_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 059H,		00H,	0DCH
$DGS	END_BLK, ??eb0C_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 05CH
$DGS	BEG_BLK, ??bb0D_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 05EH,		00H,	0E0H
$DGS	END_BLK, ??eb0D_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 060H
$DGS	BEG_BLK, ??bb0E_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 062H,		00H,	0E6H
$DGS	END_BLK, ??eb0E_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 064H
$DGS	END_BLK, ??eb08_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 066H
$DGS	BEG_BLK, ??bb0F_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 068H,		00H,	0EAH
$DGS	END_BLK, ??eb0F_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 06BH
$DGS	BEG_BLK, ??bb10_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 06DH,		00H,	0EEH
$DGS	END_BLK, ??eb10_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 06FH
$DGS	BEG_BLK, ??bb11_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 071H,		00H,	0F2H
$DGS	END_BLK, ??eb11_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 073H
$DGS	BEG_BLK, ??bb12_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 077H,		00H,	0F4H
$DGS	BEG_BLK, ??bb13_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 079H,		00H,	0F8H
$DGS	END_BLK, ??eb13_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 07DH
$DGS	BEG_BLK, ??bb14_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 07FH,		00H,	0FEH
$DGS	END_BLK, ??eb14_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 082H
$DGS	END_BLK, ??eb12_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 083H
$DGS	BEG_BLK, ??bb15_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 085H,		00H,	0102H
$DGS	END_BLK, ??eb15_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 089H
$DGS	BEG_BLK, ??bb16_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 08BH,		00H,	0106H
$DGS	END_BLK, ??eb16_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 08EH
$DGS	BEG_BLK, ??bb17_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 090H,		00H,	010AH
$DGS	END_BLK, ??eb17_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 095H
$DGS	BEG_BLK, ??bb18_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 097H,		00H,	010EH
$DGS	END_BLK, ??eb18_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 099H
$DGS	BEG_BLK, ??bb19_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 09DH,		00H,	0110H
$DGS	BEG_BLK, ??bb1A_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0A0H,		00H,	0112H
$DGS	BEG_BLK, ??bb1B_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0A2H,		00H,	011AH
$DGS	END_BLK, ??eb1B_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0A5H
$DGS	END_BLK, ??eb1A_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0A7H
$DGS	END_BLK, ??eb19_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0A8H
$DGS	BEG_BLK, ??bb1C_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0AAH,		00H,	011EH
$DGS	END_BLK, ??eb1C_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0ADH
$DGS	BEG_BLK, ??bb1D_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0AFH,		00H,	0122H
$DGS	END_BLK, ??eb1D_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0B4H
$DGS	BEG_BLK, ??bb1E_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0B6H,		00H,	0126H
$DGS	END_BLK, ??eb1E_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0B8H
$DGS	BEG_BLK, ??bb1F_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0BCH,		00H,	0128H
$DGS	BEG_BLK, ??bb20_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0BFH,		00H,	012EH
$DGS	END_BLK, ??eb20_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0C3H
$DGS	END_BLK, ??eb1F_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0C4H
$DGS	BEG_BLK, ??bb21_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0C6H,		00H,	0132H
$DGS	END_BLK, ??eb21_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0CAH
$DGS	BEG_BLK, ??bb22_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0CCH,		00H,	0136H
$DGS	END_BLK, ??eb22_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0CFH
$DGS	BEG_BLK, ??bb23_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0D1H,		00H,	013AH
$DGS	END_BLK, ??eb23_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0D6H
$DGS	BEG_BLK, ??bb24_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0D8H,		00H,	013EH
$DGS	END_BLK, ??eb24_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0DAH
$DGS	BEG_BLK, ??bb25_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0DFH,		00H,	0142H
$DGS	END_BLK, ??eb25_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0E1H
$DGS	BEG_BLK, ??bb26_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0E5H,		00H,	0144H
$DGS	BEG_BLK, ??bb27_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0E7H,		00H,	0146H
$DGS	BEG_BLK, ??bb28_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0E9H,		00H,	0150H
$DGS	END_BLK, ??eb28_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0ECH
$DGS	END_BLK, ??eb27_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0EDH
$DGS	END_BLK, ??eb26_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0EEH
$DGS	END_BLK, ??eb00_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0F2H
$DGS	BEG_BLK, ??bb29_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0F7H,		00H,	0154H
$DGS	END_BLK, ??eb29_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0FAH
$DGS	BEG_BLK, ??bb2A_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0FEH,		00H,	00H
$DGS	END_BLK, ??eb2A_KeyDecide,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 0100H
$DGS	END_FUN, ??ef_KeyDecide,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 0101H
$DGS	GLV_SYM, _gu8_KeyControlStep,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_ShortKeyArray,	U,	U,	09H,	026H,	01H,	00H
$DGS	AUX_STR, 06AH,		00H,	02H,	00H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu16_TimerKeyDecide,	U,	U,	0EH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerKeyProhibit,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerKeyOnBreak,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _F_VeryLongKey_Rejection,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _F_ShortKeyProhibit,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerEffluentKey,	U,	U,	0CH,	026H,	00H,	00H
$DGS	GLV_SYM, _KeyArray,	U,	U,	08H,	026H,	01H,	03H
$DGS	AUX_STR, 071H,		00H,	050H,	04H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_DigitalInput3,	U,	U,	08H,	02H,	01H,	00H
$DGS	AUX_STR, 039H,		00H,	06H,	00H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_KeyOnBreak,	U,	U,	0CH,	02H,	00H,	00H
$DGS	GLV_SYM, _F_CommunicationCMD,	U,	U,	0CH,	02H,	00H,	00H

	EXTRN	_gu8_DigitalInput3
	EXTRN	_gu8_KeyOnBreak
	EXTRN	_F_CommunicationCMD
	PUBLIC	_gu8_KeyControlStep
	PUBLIC	_gu16_ShortKeyArray
	PUBLIC	_gu16_TimerKeyDecide
	PUBLIC	_gu8_TimerKeyProhibit
	PUBLIC	_gu8_TimerKeyOnBreak
	PUBLIC	_F_VeryLongKey_Rejection
	PUBLIC	_F_ShortKeyProhibit
	PUBLIC	_gu8_TimerEffluentKey
	PUBLIC	_KeyArray
	PUBLIC	_KeyControl_Initialize
	PUBLIC	_EffluentKey_Decide
	PUBLIC	_KeyDecide

@@BITS	BSEG

@@CNST	CSEG	MIRRORP

@@R_INIT	CSEG	UNIT64KP
	DB	01H	; 1
	DB	(1)
	DW	00H	; 0
	DW	05H	; 5
	DB	01H	; 1
	DB	(1)
	DW	064H	; 100
	DB	01H	; 1
	DB	(1)
	DW	00H	; 0
	DB	00H	; 0
	DB	(1)
	DW	00H	; 0
	DB	00H	; 0
	DB	00H	; 0
	DB	02H	; 2
	DB	(1)
	DW	01H	; 1
	DW	05H	; 5
	DB	01H	; 1
	DB	(1)
	DW	064H	; 100
	DB	01H	; 1
	DB	(1)
	DW	00H	; 0
	DB	00H	; 0
	DB	(1)
	DW	00H	; 0
	DB	00H	; 0
	DB	00H	; 0
	DB	04H	; 4
	DB	(1)
	DW	02H	; 2
	DW	05H	; 5
	DB	01H	; 1
	DB	(1)
	DW	064H	; 100
	DB	01H	; 1
	DB	(1)
	DW	00H	; 0
	DB	00H	; 0
	DB	(1)
	DW	00H	; 0
	DB	00H	; 0
	DB	00H	; 0
	DB	08H	; 8
	DB	(1)
	DW	03H	; 3
	DW	05H	; 5
	DB	01H	; 1
	DB	(1)
	DW	064H	; 100
	DB	01H	; 1
	DB	(1)
	DW	00H	; 0
	DB	00H	; 0
	DB	(1)
	DW	00H	; 0
	DB	00H	; 0
	DB	00H	; 0
	DB	00H	; 0
	DB	00H	; 0
	DW	00H	; 0

@@INIT	DSEG	BASEP
_KeyArray:	DS	(80)
?L0005:	DS	(1)
?L0023:	DS	(1)
?L0024:	DS	(2)

@@DATA	DSEG	BASEP
_gu8_KeyControlStep:	DS	(1)
	DS	(1)
_gu16_ShortKeyArray:	DS	(2)
_gu16_TimerKeyDecide:	DS	(2)
_gu8_TimerKeyProhibit:	DS	(1)
_gu8_TimerKeyOnBreak:	DS	(1)
_F_VeryLongKey_Rejection:	DS	(1)
_F_ShortKeyProhibit:	DS	(1)
_gu8_TimerEffluentKey:	DS	(1)
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
; line   127
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
; line    21
; line    54
; line    56
; line    57
; line    58
; line    59
; line    76

@@CODEL	CSEG
_KeyControl_Initialize:
$DGL	1,128
??bf_KeyControl_Initialize:
; line    77
$DGL	0,2
	clrb	!_gu8_KeyControlStep				;[INF] 3, 1
; line    78
$DGL	0,3
??ef_KeyControl_Initialize:
	ret							;[INF] 1, 6
??ee_KeyControl_Initialize:
; line   106
_EffluentKey_Decide:
$DGL	1,134
??bf_EffluentKey_Decide:
; line   107
; line   111
$DGL	0,6
	mov	x,!?L0005	; EffluentKey_Step 		;[INF] 3, 1
	clrb	a						;[INF] 1, 1
	subw	ax,#00H	; 0 					;[INF] 3, 1
	bz	$?L0007						;[INF] 2, 4
	subw	ax,#01H	; 1 					;[INF] 3, 1
	bz	$?L0008						;[INF] 2, 4
	subw	ax,#01H	; 1 					;[INF] 3, 1
	bz	$?L0009						;[INF] 2, 4
	br	$?L0010						;[INF] 2, 3
; line   112
??bb00_EffluentKey_Decide:
; line   113
?L0007:
; line   114
$DGL	0,9
	mov	a,!_gu8_DigitalInput3+4				;[INF] 3, 1
	bf	a.0,$?L0013					;[INF] 3, 5
; line   115
??bb01_EffluentKey_Decide:
; line   116
$DGL	0,11
	oneb	!?L0005	; EffluentKey_Step 			;[INF] 3, 1
; line   117
$DGL	0,12
	mov	!_gu8_TimerEffluentKey,#032H	; 50 		;[INF] 4, 1
??eb01_EffluentKey_Decide:
; line   118
?L0013:
?L0014:
; line   119
$DGL	0,14
	br	$?L0006						;[INF] 2, 3
; line   120
?L0008:
; line   121
$DGL	0,16
	mov	a,!_gu8_DigitalInput3+3				;[INF] 3, 1
	bt	a.0,$?L0015					;[INF] 3, 5
; line   122
??bb02_EffluentKey_Decide:
; line   123
$DGL	0,18
	clrb	!?L0005	; EffluentKey_Step 			;[INF] 3, 1
??eb02_EffluentKey_Decide:
; line   124
?L0015:
?L0016:
; line   126
$DGL	0,21
	cmp0	!_gu8_TimerEffluentKey				;[INF] 3, 1
	bnz	$?L0017						;[INF] 2, 4
; line   127
??bb03_EffluentKey_Decide:
; line   128
$DGL	0,23
	mov	!?L0005,#02H	; EffluentKey_Step,2 		;[INF] 4, 1
; line   129
$DGL	0,24
	set1	!_gu16_ShortKeyArray.4				;[INF] 4, 2
??eb03_EffluentKey_Decide:
; line   130
?L0017:
?L0018:
; line   131
$DGL	0,26
	br	$?L0006						;[INF] 2, 3
; line   132
?L0009:
; line   133
$DGL	0,28
	mov	a,!_gu8_DigitalInput3+3				;[INF] 3, 1
	bt	a.0,$?L0019					;[INF] 3, 5
; line   134
??bb04_EffluentKey_Decide:
; line   135
$DGL	0,30
	clrb	!?L0005	; EffluentKey_Step 			;[INF] 3, 1
??eb04_EffluentKey_Decide:
; line   136
?L0019:
?L0020:
; line   137
$DGL	0,32
	br	$?L0006						;[INF] 2, 3
; line   138
?L0010:
; line   139
$DGL	0,34
	clrb	!?L0005	; EffluentKey_Step 			;[INF] 3, 1
; line   140
??eb00_EffluentKey_Decide:
; line   141
?L0006:
; line   142
$DGL	0,37
??ef_EffluentKey_Decide:
	ret							;[INF] 1, 6
??ee_EffluentKey_Decide:
; line   148
_KeyDecide:
$DGL	1,161
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_KeyDecide:
; line   149
$DGL	0,2
	mov	[hl+1],#00H	; i,0 				;[INF] 3, 1
; line   150
$DGL	0,3
	movw	ax,[hl+2]	; p 				;[INF] 2, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de+3]					;[INF] 2, 1
	mov	[hl],a	; data 					;[INF] 1, 1
; line   151
; line   152
; line   159
$DGL	0,12
	mov	x,!_gu8_KeyControlStep				;[INF] 3, 1
	clrb	a						;[INF] 1, 1
	subw	ax,#00H	; 0 					;[INF] 3, 1
	bz	$?L0026						;[INF] 2, 4
	subw	ax,#01H	; 1 					;[INF] 3, 1
	sknz							;[INF] 2, 1
	br	$!?L0027					;[INF] 3, 3
	subw	ax,#01H	; 1 					;[INF] 3, 1
	sknz							;[INF] 2, 1
	br	$!?L0028					;[INF] 3, 3
	subw	ax,#01H	; 1 					;[INF] 3, 1
	sknz							;[INF] 2, 1
	br	$!?L0029					;[INF] 3, 3
	subw	ax,#07H	; 7 					;[INF] 3, 1
	sknz							;[INF] 2, 1
	br	$!?L0030					;[INF] 3, 3
	subw	ax,#0F5H	; 245 				;[INF] 3, 1
	sknz							;[INF] 2, 1
	br	$!?L0031					;[INF] 3, 3
	br	$!?L0032					;[INF] 3, 3
; line   160
??bb00_KeyDecide:
; line   161
?L0026:
; line   162
$DGL	0,15
	mov	!_gu8_TimerKeyOnBreak,#064H	; 100 		;[INF] 4, 1
; line   163
$DGL	0,16
	clrb	!_F_VeryLongKey_Rejection			;[INF] 3, 1
; line   164
$DGL	0,17
	mov	a,[hl]	; data 					;[INF] 1, 1
	cmp0	a						;[INF] 1, 1
	bz	$?L0035						;[INF] 2, 4
; line   165
??bb01_KeyDecide:
; line   166
$DGL	0,19
	mov	[hl+1],#00H	; i,0 				;[INF] 3, 1
?L0037:
	mov	a,[hl+1]	; i 				;[INF] 2, 1
	cmp	a,#04H	; 4 					;[INF] 2, 1
	bnc	$?L0038						;[INF] 2, 4
; line   167
??bb02_KeyDecide:
; line   168
$DGL	0,21
	mov	a,[hl+1]	; i 				;[INF] 2, 1
	mov	x,#014H	; 20 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_KeyArray[bc]					;[INF] 3, 1
	cmp	a,[hl]	; data 					;[INF] 1, 1
	bnz	$?L0040						;[INF] 2, 4
; line   169
??bb03_KeyDecide:
; line   170
$DGL	0,23
	mov	a,_KeyArray+19[bc]				;[INF] 3, 1
	dec	a						;[INF] 1, 1
	bnz	$?L0042						;[INF] 2, 4
	mov	a,_KeyArray[bc]					;[INF] 3, 1
	cmp	a,!_gu8_KeyOnBreak				;[INF] 3, 1
	sknz							;[INF] 2, 1
; line   171
??bb04_KeyDecide:
; line   172
$DGL	0,25
	br	$?L0038						;[INF] 2, 3
??eb04_KeyDecide:
; line   173
?L0042:
?L0043:
; line   174
$DGL	0,27
	mov	a,[hl]	; data 					;[INF] 1, 1
	mov	!?L0023,a	; buf 				;[INF] 3, 1
; line   175
$DGL	0,28
	mov	a,[hl+1]	; i 				;[INF] 2, 1
	mov	x,#014H	; 20 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	addw	ax,#loww (_KeyArray)				;[INF] 3, 1
	movw	!?L0024,ax	; KeyPnt 			;[INF] 3, 1
; line   176
$DGL	0,29
	movw	de,ax						;[INF] 1, 1
	movw	ax,[de+4]					;[INF] 2, 1
	or	a,x						;[INF] 2, 1
	bz	$?L0044						;[INF] 2, 4
; line   177
??bb05_KeyDecide:
; line   178
$DGL	0,31
	oneb	!_gu8_KeyControlStep				;[INF] 3, 1
; line   179
$DGL	0,32
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	movw	ax,[de+4]					;[INF] 2, 1
	movw	!_gu16_TimerKeyDecide,ax			;[INF] 3, 1
??eb05_KeyDecide:
; line   181
$DGL	0,34
	br	$?L0045						;[INF] 2, 3
?L0044:
; line   182
??bb06_KeyDecide:
; line   193
$DGL	0,46
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	movw	ax,[de+8]					;[INF] 2, 1
	or	a,x						;[INF] 2, 1
	bz	$?L0046						;[INF] 2, 4
; line   194
??bb07_KeyDecide:
; line   195
$DGL	0,48
	mov	!_gu8_KeyControlStep,#02H	; 2 		;[INF] 4, 1
; line   196
$DGL	0,49
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	movw	ax,[de+8]					;[INF] 2, 1
	movw	!_gu16_TimerKeyDecide,ax			;[INF] 3, 1
??eb07_KeyDecide:
; line   197
?L0046:
?L0047:
??eb06_KeyDecide:
; line   199
?L0045:
??eb03_KeyDecide:
; line   200
?L0040:
?L0041:
??eb02_KeyDecide:
; line   201
$DGL	0,54
?L0039:
	inc	[hl+1]	; i 					;[INF] 3, 2
	br	$?L0037						;[INF] 2, 3
?L0038:
??eb01_KeyDecide:
; line   202
?L0035:
?L0036:
; line   203
$DGL	0,56
	br	$!?L0025					;[INF] 3, 3
; line   204
?L0027:
; line   205
$DGL	0,58
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu16_TimerKeyDecide			;[INF] 3, 1
	skz							;[INF] 2, 1
	br	$!?L0048					;[INF] 3, 3
; line   206
??bb08_KeyDecide:
; line   209
$DGL	0,62
	cmp0	!_F_ShortKeyProhibit				;[INF] 3, 1
	bnz	$?L0050						;[INF] 2, 4
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+6]					;[INF] 2, 1
	dec	a						;[INF] 1, 1
	bz	$?L0052						;[INF] 2, 4
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+6]					;[INF] 2, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0050						;[INF] 2, 4
	movw	ax,[hl+2]	; p 				;[INF] 2, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de+5]					;[INF] 2, 1
	cmp	a,!?L0023	; buf 				;[INF] 3, 1
	bnz	$?L0050						;[INF] 2, 4
?L0052:
; line   210
??bb09_KeyDecide:
; line   211
$DGL	0,64
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+2]					;[INF] 2, 1
	mov	c,a						;[INF] 1, 1
	onew	ax						;[INF] 1, 1
	cmp0	c						;[INF] 1, 1
	bz	$?L0053						;[INF] 2, 4
?L0054:
	addw	ax,ax						;[INF] 1, 1
	dec	c						;[INF] 1, 1
	bnz	$?L0054						;[INF] 2, 4
?L0053:
	movw	!_gu16_ShortKeyArray,ax				;[INF] 3, 1
; line   212
$DGL	0,65
	mov	!_gu8_TimerKeyProhibit,#032H	; 50 		;[INF] 4, 1
; line   213
$DGL	0,66
	mov	!_gu8_KeyControlStep,#0FFH	; 255 		;[INF] 4, 1
; line   214
$DGL	0,67
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+6]					;[INF] 2, 1
	cmp0	a						;[INF] 1, 1
	sknz							;[INF] 2, 1
; line   215
??bb0A_KeyDecide:
; line   216
$DGL	0,69
	br	$!?L0025					;[INF] 3, 3
??eb0A_KeyDecide:
; line   217
?L0055:
?L0056:
??eb09_KeyDecide:
; line   218
?L0050:
?L0051:
; line   230
$DGL	0,83
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	movw	ax,[de+8]					;[INF] 2, 1
	or	a,x						;[INF] 2, 1
	bz	$?L0057						;[INF] 2, 4
; line   231
??bb0B_KeyDecide:
; line   232
$DGL	0,85
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	movw	ax,[de+8]					;[INF] 2, 1
	movw	bc,ax						;[INF] 1, 1
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	movw	ax,[de+4]					;[INF] 2, 1
	xchw	ax,bc						;[INF] 1, 1
	subw	ax,bc						;[INF] 1, 1
	xchw	ax,bc						;[INF] 1, 1
	movw	ax,bc						;[INF] 1, 1
	movw	!_gu16_TimerKeyDecide,ax			;[INF] 3, 1
; line   233
$DGL	0,86
	mov	!_gu8_KeyControlStep,#02H	; 2 		;[INF] 4, 1
??eb0B_KeyDecide:
; line   235
$DGL	0,88
	br	$?L0058						;[INF] 2, 3
?L0057:
	mov	a,[hl]	; data 					;[INF] 1, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0059						;[INF] 2, 4
; line   236
??bb0C_KeyDecide:
; line   237
$DGL	0,90
	mov	!_gu8_TimerKeyProhibit,#032H	; 50 		;[INF] 4, 1
; line   238
$DGL	0,91
	mov	!_gu8_KeyControlStep,#0FFH	; 255 		;[INF] 4, 1
??eb0C_KeyDecide:
; line   240
$DGL	0,93
	br	$?L0060						;[INF] 2, 3
?L0059:
	mov	a,!?L0023	; buf 				;[INF] 3, 1
	cmp	a,[hl]	; data 					;[INF] 1, 1
	skz							;[INF] 2, 1
; line   241
??bb0D_KeyDecide:
; line   242
$DGL	0,95
	clrb	!_gu8_KeyControlStep				;[INF] 3, 1
??eb0D_KeyDecide:
; line   244
?L0061:
; line   245
??bb0E_KeyDecide:
??eb0E_KeyDecide:
; line   247
?L0062:
?L0060:
?L0058:
??eb08_KeyDecide:
; line   250
$DGL	0,103
	br	$?L0049						;[INF] 2, 3
?L0048:
	mov	a,[hl]	; data 					;[INF] 1, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0063						;[INF] 2, 4
; line   251
??bb0F_KeyDecide:
; line   252
$DGL	0,105
	mov	!_gu8_TimerKeyProhibit,#032H	; 50 		;[INF] 4, 1
; line   253
$DGL	0,106
	mov	!_gu8_KeyControlStep,#0FFH	; 255 		;[INF] 4, 1
??eb0F_KeyDecide:
; line   255
$DGL	0,108
	br	$?L0064						;[INF] 2, 3
?L0063:
	mov	a,!?L0023	; buf 				;[INF] 3, 1
	cmp	a,[hl]	; data 					;[INF] 1, 1
	skz							;[INF] 2, 1
; line   256
??bb10_KeyDecide:
; line   257
$DGL	0,110
	clrb	!_gu8_KeyControlStep				;[INF] 3, 1
??eb10_KeyDecide:
; line   259
?L0065:
; line   260
??bb11_KeyDecide:
??eb11_KeyDecide:
; line   262
?L0066:
?L0064:
?L0049:
; line   263
$DGL	0,116
	br	$!?L0025					;[INF] 3, 3
; line   264
?L0028:
; line   265
$DGL	0,118
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu16_TimerKeyDecide			;[INF] 3, 1
	bnz	$?L0067						;[INF] 2, 4
; line   266
??bb12_KeyDecide:
; line   267
$DGL	0,120
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+10]					;[INF] 2, 1
	dec	a						;[INF] 1, 1
	bz	$?L0071						;[INF] 2, 4
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+10]					;[INF] 2, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0069						;[INF] 2, 4
	movw	ax,[hl+2]	; p 				;[INF] 2, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de+5]					;[INF] 2, 1
	cmp	a,!?L0023	; buf 				;[INF] 3, 1
	bnz	$?L0069						;[INF] 2, 4
?L0071:
; line   268
??bb13_KeyDecide:
; line   270
$DGL	0,123
	mov	!_gu8_TimerKeyProhibit,#032H	; 50 		;[INF] 4, 1
; line   271
$DGL	0,124
	mov	!_gu8_KeyControlStep,#0FFH	; 255 		;[INF] 4, 1
??eb13_KeyDecide:
; line   272
?L0069:
?L0070:
; line   273
$DGL	0,126
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	movw	ax,[de+12]					;[INF] 2, 1
	or	a,x						;[INF] 2, 1
	bz	$?L0072						;[INF] 2, 4
; line   274
??bb14_KeyDecide:
; line   275
$DGL	0,128
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	movw	ax,[de+12]					;[INF] 2, 1
	movw	bc,ax						;[INF] 1, 1
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	movw	ax,[de+8]					;[INF] 2, 1
	xchw	ax,bc						;[INF] 1, 1
	subw	ax,bc						;[INF] 1, 1
	xchw	ax,bc						;[INF] 1, 1
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	movw	ax,[de+4]					;[INF] 2, 1
	xchw	ax,bc						;[INF] 1, 1
	subw	ax,bc						;[INF] 1, 1
	xchw	ax,bc						;[INF] 1, 1
	movw	ax,bc						;[INF] 1, 1
	movw	!_gu16_TimerKeyDecide,ax			;[INF] 3, 1
; line   276
$DGL	0,129
	mov	!_gu8_KeyControlStep,#03H	; 3 		;[INF] 4, 1
??eb14_KeyDecide:
; line   277
?L0072:
?L0073:
??eb12_KeyDecide:
; line   279
$DGL	0,132
	br	$?L0068						;[INF] 2, 3
?L0067:
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+6]					;[INF] 2, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0074						;[INF] 2, 4
	movw	ax,[hl+2]	; p 				;[INF] 2, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de+5]					;[INF] 2, 1
	cmp	a,!?L0023	; buf 				;[INF] 3, 1
	bnz	$?L0074						;[INF] 2, 4
; line   280
??bb15_KeyDecide:
; line   281
$DGL	0,134
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+2]					;[INF] 2, 1
	mov	c,a						;[INF] 1, 1
	onew	ax						;[INF] 1, 1
	cmp0	c						;[INF] 1, 1
	bz	$?L0076						;[INF] 2, 4
?L0077:
	addw	ax,ax						;[INF] 1, 1
	dec	c						;[INF] 1, 1
	bnz	$?L0077						;[INF] 2, 4
?L0076:
	movw	!_gu16_ShortKeyArray,ax				;[INF] 3, 1
; line   282
$DGL	0,135
	mov	!_gu8_TimerKeyProhibit,#032H	; 50 		;[INF] 4, 1
; line   283
$DGL	0,136
	mov	!_gu8_KeyControlStep,#0FFH	; 255 		;[INF] 4, 1
??eb15_KeyDecide:
; line   285
$DGL	0,138
	br	$?L0075						;[INF] 2, 3
?L0074:
	mov	a,[hl]	; data 					;[INF] 1, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0078						;[INF] 2, 4
; line   286
??bb16_KeyDecide:
; line   287
$DGL	0,140
	mov	!_gu8_TimerKeyProhibit,#032H	; 50 		;[INF] 4, 1
; line   288
$DGL	0,141
	mov	!_gu8_KeyControlStep,#0FFH	; 255 		;[INF] 4, 1
??eb16_KeyDecide:
; line   290
$DGL	0,143
	br	$?L0079						;[INF] 2, 3
?L0078:
	mov	a,!?L0023	; buf 				;[INF] 3, 1
	cmp	a,[hl]	; data 					;[INF] 1, 1
	bz	$?L0080						;[INF] 2, 4
; line   291
??bb17_KeyDecide:
; line   294
$DGL	0,147
	oneb	!_F_ShortKeyProhibit				;[INF] 3, 1
; line   295
$DGL	0,148
	clrb	!_gu8_KeyControlStep				;[INF] 3, 1
??eb17_KeyDecide:
; line   297
?L0080:
; line   298
??bb18_KeyDecide:
??eb18_KeyDecide:
; line   300
?L0081:
?L0079:
?L0075:
?L0068:
; line   301
$DGL	0,154
	br	$!?L0025					;[INF] 3, 3
; line   302
?L0029:
; line   303
$DGL	0,156
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu16_TimerKeyDecide			;[INF] 3, 1
	bnz	$?L0082						;[INF] 2, 4
; line   304
??bb19_KeyDecide:
; line   306
$DGL	0,159
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+14]					;[INF] 2, 1
	dec	a						;[INF] 1, 1
	bz	$?L0086						;[INF] 2, 4
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+14]					;[INF] 2, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0084						;[INF] 2, 4
	movw	ax,[hl+2]	; p 				;[INF] 2, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de+5]					;[INF] 2, 1
	cmp	a,!?L0023	; buf 				;[INF] 3, 1
	bnz	$?L0084						;[INF] 2, 4
?L0086:
; line   307
??bb1A_KeyDecide:
; line   308
$DGL	0,161
	cmp0	!_F_VeryLongKey_Rejection			;[INF] 3, 1
	sknz							;[INF] 2, 1
; line   309
??bb1B_KeyDecide:
; line   311
$DGL	0,164
	mov	!_gu8_TimerKeyProhibit,#032H	; 50 		;[INF] 4, 1
??eb1B_KeyDecide:
; line   312
?L0087:
?L0088:
; line   313
$DGL	0,166
	mov	!_gu8_KeyControlStep,#0FFH	; 255 		;[INF] 4, 1
??eb1A_KeyDecide:
; line   314
?L0084:
?L0085:
??eb19_KeyDecide:
; line   316
$DGL	0,169
	br	$?L0083						;[INF] 2, 3
?L0082:
	mov	a,[hl]	; data 					;[INF] 1, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0089						;[INF] 2, 4
; line   317
??bb1C_KeyDecide:
; line   318
$DGL	0,171
	mov	!_gu8_TimerKeyProhibit,#032H	; 50 		;[INF] 4, 1
; line   319
$DGL	0,172
	mov	!_gu8_KeyControlStep,#0FFH	; 255 		;[INF] 4, 1
??eb1C_KeyDecide:
; line   321
$DGL	0,174
	br	$?L0090						;[INF] 2, 3
?L0089:
	mov	a,!?L0023	; buf 				;[INF] 3, 1
	cmp	a,[hl]	; data 					;[INF] 1, 1
	bz	$?L0091						;[INF] 2, 4
; line   322
??bb1D_KeyDecide:
; line   325
$DGL	0,178
	oneb	!_F_ShortKeyProhibit				;[INF] 3, 1
; line   326
$DGL	0,179
	clrb	!_gu8_KeyControlStep				;[INF] 3, 1
??eb1D_KeyDecide:
; line   328
?L0091:
; line   329
??bb1E_KeyDecide:
??eb1E_KeyDecide:
; line   331
?L0092:
?L0090:
?L0083:
; line   332
$DGL	0,185
	br	$!?L0025					;[INF] 3, 3
; line   333
?L0030:
; line   334
$DGL	0,187
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu16_TimerKeyDecide			;[INF] 3, 1
	bnz	$?L0093						;[INF] 2, 4
; line   335
??bb1F_KeyDecide:
; line   337
$DGL	0,190
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+18]					;[INF] 2, 1
	dec	a						;[INF] 1, 1
	bz	$?L0097						;[INF] 2, 4
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+18]					;[INF] 2, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0095						;[INF] 2, 4
	movw	ax,[hl+2]	; p 				;[INF] 2, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de+5]					;[INF] 2, 1
	cmp	a,!?L0023	; buf 				;[INF] 3, 1
	bnz	$?L0095						;[INF] 2, 4
?L0097:
; line   338
??bb20_KeyDecide:
; line   340
$DGL	0,193
	mov	!_gu8_TimerKeyProhibit,#032H	; 50 		;[INF] 4, 1
; line   341
$DGL	0,194
	mov	!_gu8_KeyControlStep,#0FFH	; 255 		;[INF] 4, 1
??eb20_KeyDecide:
; line   342
?L0095:
?L0096:
??eb1F_KeyDecide:
; line   344
$DGL	0,197
	br	$?L0094						;[INF] 2, 3
?L0093:
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+6]					;[INF] 2, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0098						;[INF] 2, 4
	movw	ax,[hl+2]	; p 				;[INF] 2, 1
	movw	de,ax						;[INF] 1, 1
	mov	a,[de+5]					;[INF] 2, 1
	cmp	a,!?L0023	; buf 				;[INF] 3, 1
	bnz	$?L0098						;[INF] 2, 4
; line   345
??bb21_KeyDecide:
; line   346
$DGL	0,199
	movw	de,!?L0024	; KeyPnt 			;[INF] 3, 1
	mov	a,[de+2]					;[INF] 2, 1
	mov	c,a						;[INF] 1, 1
	onew	ax						;[INF] 1, 1
	cmp0	c						;[INF] 1, 1
	bz	$?L0100						;[INF] 2, 4
?L0101:
	addw	ax,ax						;[INF] 1, 1
	dec	c						;[INF] 1, 1
	bnz	$?L0101						;[INF] 2, 4
?L0100:
	movw	!_gu16_ShortKeyArray,ax				;[INF] 3, 1
; line   347
$DGL	0,200
	mov	!_gu8_TimerKeyProhibit,#032H	; 50 		;[INF] 4, 1
; line   348
$DGL	0,201
	mov	!_gu8_KeyControlStep,#0FFH	; 255 		;[INF] 4, 1
??eb21_KeyDecide:
; line   350
$DGL	0,203
	br	$?L0099						;[INF] 2, 3
?L0098:
	mov	a,[hl]	; data 					;[INF] 1, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0102						;[INF] 2, 4
; line   351
??bb22_KeyDecide:
; line   352
$DGL	0,205
	mov	!_gu8_TimerKeyProhibit,#032H	; 50 		;[INF] 4, 1
; line   353
$DGL	0,206
	mov	!_gu8_KeyControlStep,#0FFH	; 255 		;[INF] 4, 1
??eb22_KeyDecide:
; line   355
$DGL	0,208
	br	$?L0103						;[INF] 2, 3
?L0102:
	mov	a,!?L0023	; buf 				;[INF] 3, 1
	cmp	a,[hl]	; data 					;[INF] 1, 1
	bz	$?L0104						;[INF] 2, 4
; line   356
??bb23_KeyDecide:
; line   359
$DGL	0,212
	oneb	!_F_ShortKeyProhibit				;[INF] 3, 1
; line   360
$DGL	0,213
	clrb	!_gu8_KeyControlStep				;[INF] 3, 1
??eb23_KeyDecide:
; line   362
?L0104:
; line   363
??bb24_KeyDecide:
??eb24_KeyDecide:
; line   365
?L0105:
?L0103:
?L0099:
?L0094:
; line   366
$DGL	0,219
	br	$?L0025						;[INF] 2, 3
; line   367
?L0031:
; line   368
$DGL	0,221
	clrb	!_F_ShortKeyProhibit				;[INF] 3, 1
; line   369
$DGL	0,222
	mov	a,[hl]	; data 					;[INF] 1, 1
	cmp0	a						;[INF] 1, 1
	bnz	$?L0106						;[INF] 2, 4
	cmp0	!_gu8_TimerKeyProhibit				;[INF] 3, 1
	sknz							;[INF] 2, 1
; line   370
??bb25_KeyDecide:
; line   371
$DGL	0,224
	clrb	!_gu8_KeyControlStep				;[INF] 3, 1
??eb25_KeyDecide:
; line   372
?L0106:
?L0107:
; line   375
$DGL	0,228
	mov	[hl+1],#00H	; i,0 				;[INF] 3, 1
?L0108:
	mov	a,[hl+1]	; i 				;[INF] 2, 1
	cmp	a,#04H	; 4 					;[INF] 2, 1
	bnc	$?L0109						;[INF] 2, 4
; line   376
??bb26_KeyDecide:
; line   377
$DGL	0,230
	mov	a,[hl+1]	; i 				;[INF] 2, 1
	mov	x,#014H	; 20 					;[INF] 2, 1
	mulu	x						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,_KeyArray[bc]					;[INF] 3, 1
	cmp	a,[hl]	; data 					;[INF] 1, 1
	bnz	$?L0111						;[INF] 2, 4
; line   378
??bb27_KeyDecide:
; line   379
$DGL	0,232
	mov	a,_KeyArray+19[bc]				;[INF] 3, 1
	dec	a						;[INF] 1, 1
	sknz							;[INF] 2, 1
	cmp0	!_gu8_TimerKeyOnBreak				;[INF] 3, 1
; line   380
??bb28_KeyDecide:
??eb28_KeyDecide:
; line   383
?L0113:
?L0114:
??eb27_KeyDecide:
; line   384
?L0111:
?L0112:
??eb26_KeyDecide:
; line   385
$DGL	0,238
?L0110:
	inc	[hl+1]	; i 					;[INF] 3, 2
	br	$?L0108						;[INF] 2, 3
?L0109:
; line   386
; line   387
?L0032:
; line   388
??eb00_KeyDecide:
; line   389
?L0025:
; line   391
$DGL	0,244
	call	!!_EffluentKey_Decide				;[INF] 4, 3
; line   393
$DGL	0,246
	cmp0	!_gu8_KeyControlStep				;[INF] 3, 1
	bnz	$?L0115						;[INF] 2, 4
; line   394
??bb29_KeyDecide:
; line   395
$DGL	0,248
	clrb	!?L0023	; buf 					;[INF] 3, 1
; line   396
$DGL	0,249
	clrw	ax						;[INF] 1, 1
	movw	!?L0024,ax	; KeyPnt 			;[INF] 3, 1
??eb29_KeyDecide:
; line   397
?L0115:
?L0116:
; line   400
$DGL	0,253
	clrw	ax						;[INF] 1, 1
	cmpw	ax,!_gu16_ShortKeyArray				;[INF] 3, 1
	skz							;[INF] 2, 1
; line   401
??bb2A_KeyDecide:
; line   402
$DGL	0,255
	oneb	!_F_CommunicationCMD				;[INF] 3, 1
??eb2A_KeyDecide:
; line   403
?L0117:
?L0118:
; line   404
$DGL	0,257
??ef_KeyDecide:
	addw	sp,#04H						;[INF] 2, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_KeyDecide:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE

@@FIX	DSEG	BASEP

	END


; *** Code Information ***
;
; $FILE C:\Users\20021210\Documents\GitHub\ICON_MOVING\Program\2_Front\Icon_mov
;	ing_front\Source\keycontrol.c
;
; $FUNC KeyControl_Initialize(76)
;	void=(void)
;	CODE SIZE= 4 bytes, CLOCK_SIZE= 7 clocks, STACK_SIZE= 0 bytes
;
; $FUNC EffluentKey_Decide(106)
;	void=(void)
;	CODE SIZE= 75 bytes, CLOCK_SIZE= 66 clocks, STACK_SIZE= 0 bytes
;
; $FUNC KeyDecide(148)
;	void=(pointer p:ax)
;	CODE SIZE= 764 bytes, CLOCK_SIZE= 557 clocks, STACK_SIZE= 10 bytes
;
; $CALL EffluentKey_Decide(391)
;	void=(void)

; Target chip : R5F100PG
; Device file : V1.14 
