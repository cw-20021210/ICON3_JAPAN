; 78K0R C Compiler V2.72 Assembler Source        Date:22 Jul 2025 Time:09:26:45

; Command   : -cf100le -yC:\Program Files (x86)\Renesas Electronics\CS+\CACX\De
;             vice\RL78\Devicefile Source\adc.c -oDefaultBuild -_msgoff -nq -i.
;              -iSource -iSource\include -zpn -mm -mi0 -aDefaultBuild -no -g2
; In-file   : Source\adc.c
; Asm-file  : DefaultBuild\adc.asm
; Para-file : 

$PROCESSOR(F100LE)
$DEBUG
$NODEBUGA
$KANJICODE NONE
$TOL_INF	03FH, 0272H, 00H, 04000H, 00H, 00H, 00H

$DGS	FIL_NAM, .file,		056H,	0FFFEH,	03FH,	067H,	01H,	00H
$DGS	AUX_FIL, adc.c
$DGS	MOD_NAM, adc,		00H,	0FFFEH,	00H,	077H,	00H,	00H
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
$DGS	STR_STR, .29fake,	00H,	0FFFEH,	08H,	0AH,	01H,	00H
$DGS	AUX_TAG, 08H,		01DH
$DGS	MEB_STR, _TH_ADC_ADDRESS,	00H,	0FFFFH,	0EH,	08H,	01H,	01H
$DGS	AUX_STR, 00H,		00H,	02H,	00H,	00H,	00H,	00H,	01H
$DGS	MEB_STR, _DEGREE,	02H,	0FFFFH,	04H,	08H,	00H,	00H
$DGS	MEB_STR, _SHORT_DATA,	04H,	0FFFFH,	0EH,	08H,	00H,	00H
$DGS	MEB_STR, _OPEN_DATA,	06H,	0FFFFH,	0EH,	08H,	00H,	00H
$DGS	END_STR, .eos,		08H,	0FFFFH,	00H,	066H,	01H,	00H
$DGS	AUX_EOS, 014H,		08H
$DGS	GLV_SYM, _ADC_Initialize,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	023H,	01H,	00H
$DGS	BEG_FUN, ??bf_ADC_Initialize,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 0CH,		00H,	023H
$DGS	END_FUN, ??ef_ADC_Initialize,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03H
$DGS	GLV_SYM, _Input_AD_Change,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	044H,	01H,	00H
$DGS	BEG_FUN, ??bf_Input_AD_Change,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 014H,		02H,	02AH
$DGS	AUT_VAR, _mu8_i,	01H,	0FFFFH,	0CH,	01H,	00H,	00H
$DGS	STA_SYM, _Table_ADch,	?L0005,	U,	0500CH,	03H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	03H,	03H,	00H,	00H,	00H,	00H
$DGS	BEG_BLK, ??bb00_Input_AD_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 0BH,		00H,	02CH
$DGS	BEG_BLK, ??bb01_Input_AD_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 010H,		00H,	032H
$DGS	END_BLK, ??eb01_Input_AD_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 012H
$DGS	END_BLK, ??eb00_Input_AD_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 014H
$DGS	BEG_BLK, ??bb02_Input_AD_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 020H,		00H,	034H
$DGS	BEG_BLK, ??bb03_Input_AD_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 023H,		00H,	038H
$DGS	END_BLK, ??eb03_Input_AD_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 025H
$DGS	BEG_BLK, ??bb04_Input_AD_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 02AH,		00H,	03AH
$DGS	BEG_BLK, ??bb05_Input_AD_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 02DH,		00H,	00H
$DGS	END_BLK, ??eb05_Input_AD_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 035H
$DGS	END_BLK, ??eb04_Input_AD_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 036H
$DGS	END_BLK, ??eb02_Input_AD_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 037H
$DGS	END_FUN, ??ef_Input_AD_Change,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 03FH
$DGS	GLV_SYM, _Temperature_Change,	U,	U,	01H,	026H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	056H,	01H,	00H
$DGS	BEG_FUN, ??bf_Temperature_Change,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_BEG, 058H,		00H,	048H
$DGS	BEG_BLK, ??bb00_Temperature_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 017H,		00H,	04CH
$DGS	END_BLK, ??eb00_Temperature_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 019H
$DGS	BEG_BLK, ??bb01_Temperature_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01BH,		00H,	050H
$DGS	END_BLK, ??eb01_Temperature_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 01DH
$DGS	BEG_BLK, ??bb02_Temperature_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_BEG, 01FH,		00H,	00H
$DGS	END_BLK, ??eb02_Temperature_Change,	U,	U,	00H,	064H,	01H,	00H
$DGS	AUX_END, 021H
$DGS	END_FUN, ??ef_Temperature_Change,	U,	U,	00H,	065H,	01H,	00H
$DGS	AUX_END, 023H
$DGS	GLV_SYM, _MCUTemp_Table,	U,	U,	05004H,	026H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	032EH,	0197H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu8_CounterAdchannel,	U,	U,	0100CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_AdcRepeat,	U,	U,	0100CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu8_TimerAdcheck,	U,	U,	0100CH,	026H,	00H,	00H
$DGS	GLV_SYM, _gu16_NowAdc,	U,	U,	0100EH,	026H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	06H,	03H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu16_SumAdc,	U,	U,	0100EH,	026H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	06H,	03H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu16_ADCBackValue,	U,	U,	0100EH,	026H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	06H,	03H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gu16_AdcAverage,	U,	U,	0100EH,	026H,	01H,	03H
$DGS	AUX_STR, 00H,		00H,	06H,	03H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _gi16_MCUSensor,	U,	U,	08H,	026H,	01H,	00H
$DGS	AUX_STR, 014H,		00H,	08H,	00H,	00H,	00H,	00H,	00H
$DGS	GLV_SYM, _SafetyLoop,	U,	U,	01H,	02H,	01H,	02H
$DGS	AUX_FUN, 00H,		U,	U,	00H,	01H,	00H

	EXTRN	_SafetyLoop
	PUBLIC	_MCUTemp_Table
	PUBLIC	_gu8_CounterAdchannel
	PUBLIC	_gu8_AdcRepeat
	PUBLIC	_gu8_TimerAdcheck
	PUBLIC	_gu16_NowAdc
	PUBLIC	_gu16_SumAdc
	PUBLIC	_gu16_ADCBackValue
	PUBLIC	_gu16_AdcAverage
	PUBLIC	_gi16_MCUSensor
	PUBLIC	_ADC_Initialize
	PUBLIC	_Input_AD_Change
	PUBLIC	_Temperature_Change

@@BITS	BSEG

@@CNST	CSEG	MIRRORP
_MCUTemp_Table:	DW	01C2H	; 450
	DW	01C0H	; 448
	DW	01BFH	; 447
	DW	01BDH	; 445
	DW	01BCH	; 444
	DW	01BAH	; 442
	DW	01B9H	; 441
	DW	01B8H	; 440
	DW	01B6H	; 438
	DW	01B5H	; 437
	DW	01B3H	; 435
	DW	01B2H	; 434
	DW	01B1H	; 433
	DW	01B0H	; 432
	DW	01AFH	; 431
	DW	01AEH	; 430
	DW	01ACH	; 428
	DW	01ABH	; 427
	DW	01A9H	; 425
	DW	01A8H	; 424
	DW	01A6H	; 422
	DW	01A5H	; 421
	DW	01A4H	; 420
	DW	01A2H	; 418
	DW	01A1H	; 417
	DW	019FH	; 415
	DW	019EH	; 414
	DW	019DH	; 413
	DW	019CH	; 412
	DW	019BH	; 411
	DW	019AH	; 410
	DW	0198H	; 408
	DW	0197H	; 407
	DW	0195H	; 405
	DW	0194H	; 404
	DW	0192H	; 402
	DW	0191H	; 401
	DW	0190H	; 400
	DW	018EH	; 398
	DW	018DH	; 397
	DW	018BH	; 395
	DW	018AH	; 394
	DW	0188H	; 392
	DW	0187H	; 391
	DW	0186H	; 390
	DW	0184H	; 388
	DW	0183H	; 387
	DW	0181H	; 385
	DW	0180H	; 384
	DW	017FH	; 383
	DW	017EH	; 382
	DW	017DH	; 381
	DW	017CH	; 380
	DW	017AH	; 378
	DW	0179H	; 377
	DW	0177H	; 375
	DW	0176H	; 374
	DW	0174H	; 372
	DW	0173H	; 371
	DW	0172H	; 370
	DW	0170H	; 368
	DW	016FH	; 367
	DW	016DH	; 365
	DW	016CH	; 364
	DW	016AH	; 362
	DW	0169H	; 361
	DW	0168H	; 360
	DW	0166H	; 358
	DW	0165H	; 357
	DW	0163H	; 355
	DW	0162H	; 354
	DW	0161H	; 353
	DW	0160H	; 352
	DW	015FH	; 351
	DW	015EH	; 350
	DW	015CH	; 348
	DW	015BH	; 347
	DW	0159H	; 345
	DW	0158H	; 344
	DW	0156H	; 342
	DW	0155H	; 341
	DW	0154H	; 340
	DW	0152H	; 338
	DW	0151H	; 337
	DW	014FH	; 335
	DW	014EH	; 334
	DW	014DH	; 333
	DW	014CH	; 332
	DW	014BH	; 331
	DW	014AH	; 330
	DW	0148H	; 328
	DW	0147H	; 327
	DW	0145H	; 325
	DW	0144H	; 324
	DW	0142H	; 322
	DW	0141H	; 321
	DW	0140H	; 320
	DW	013EH	; 318
	DW	013DH	; 317
	DW	013BH	; 315
	DW	013AH	; 314
	DW	0138H	; 312
	DW	0137H	; 311
	DW	0136H	; 310
	DW	0134H	; 308
	DW	0133H	; 307
	DW	0131H	; 305
	DW	0130H	; 304
	DW	012FH	; 303
	DW	012EH	; 302
	DW	012DH	; 301
	DW	012CH	; 300
	DW	012AH	; 298
	DW	0129H	; 297
	DW	0127H	; 295
	DW	0126H	; 294
	DW	0124H	; 292
	DW	0123H	; 291
	DW	0122H	; 290
	DW	0120H	; 288
	DW	011FH	; 287
	DW	011DH	; 285
	DW	011CH	; 284
	DW	011AH	; 282
	DW	0119H	; 281
	DW	0118H	; 280
	DW	0116H	; 278
	DW	0115H	; 277
	DW	0113H	; 275
	DW	0112H	; 274
	DW	0111H	; 273
	DW	0110H	; 272
	DW	010FH	; 271
	DW	010EH	; 270
	DW	010CH	; 268
	DW	010BH	; 267
	DW	0109H	; 265
	DW	0108H	; 264
	DW	0106H	; 262
	DW	0105H	; 261
	DW	0104H	; 260
	DW	0102H	; 258
	DW	0101H	; 257
	DW	0FFH	; 255
	DW	0FEH	; 254
	DW	0FDH	; 253
	DW	0FCH	; 252
	DW	0FBH	; 251
	DW	0FAH	; 250
	DW	0F8H	; 248
	DW	0F7H	; 247
	DW	0F5H	; 245
	DW	0F4H	; 244
	DW	0F2H	; 242
	DW	0F1H	; 241
	DW	0F0H	; 240
	DW	0EEH	; 238
	DW	0EDH	; 237
	DW	0EBH	; 235
	DW	0EAH	; 234
	DW	0E8H	; 232
	DW	0E7H	; 231
	DW	0E6H	; 230
	DW	0E4H	; 228
	DW	0E3H	; 227
	DW	0E1H	; 225
	DW	0E0H	; 224
	DW	0DFH	; 223
	DW	0DEH	; 222
	DW	0DDH	; 221
	DW	0DCH	; 220
	DW	0DAH	; 218
	DW	0D9H	; 217
	DW	0D7H	; 215
	DW	0D6H	; 214
	DW	0D4H	; 212
	DW	0D3H	; 211
	DW	0D2H	; 210
	DW	0D0H	; 208
	DW	0CFH	; 207
	DW	0CDH	; 205
	DW	0CCH	; 204
	DW	0CAH	; 202
	DW	0C9H	; 201
	DW	0C8H	; 200
	DW	0C6H	; 198
	DW	0C5H	; 197
	DW	0C3H	; 195
	DW	0C2H	; 194
	DW	0C1H	; 193
	DW	0C0H	; 192
	DW	0BFH	; 191
	DW	0BEH	; 190
	DW	0BCH	; 188
	DW	0BBH	; 187
	DW	0B9H	; 185
	DW	0B8H	; 184
	DW	0B6H	; 182
	DW	0B5H	; 181
	DW	0B4H	; 180
	DW	0B2H	; 178
	DW	0B1H	; 177
	DW	0AFH	; 175
	DW	0AEH	; 174
	DW	0ADH	; 173
	DW	0ACH	; 172
	DW	0ABH	; 171
	DW	0AAH	; 170
	DW	0A8H	; 168
	DW	0A7H	; 167
	DW	0A5H	; 165
	DW	0A4H	; 164
	DW	0A2H	; 162
	DW	0A1H	; 161
	DW	0A0H	; 160
	DW	09EH	; 158
	DW	09DH	; 157
	DW	09BH	; 155
	DW	09AH	; 154
	DW	098H	; 152
	DW	097H	; 151
	DW	096H	; 150
	DW	094H	; 148
	DW	093H	; 147
	DW	091H	; 145
	DW	090H	; 144
	DW	08FH	; 143
	DW	08EH	; 142
	DW	08DH	; 141
	DW	08CH	; 140
	DW	08AH	; 138
	DW	089H	; 137
	DW	087H	; 135
	DW	086H	; 134
	DW	084H	; 132
	DW	083H	; 131
	DW	082H	; 130
	DW	080H	; 128
	DW	07FH	; 127
	DW	07DH	; 125
	DW	07CH	; 124
	DW	07AH	; 122
	DW	079H	; 121
	DW	078H	; 120
	DW	076H	; 118
	DW	075H	; 117
	DW	073H	; 115
	DW	072H	; 114
	DW	071H	; 113
	DW	070H	; 112
	DW	06FH	; 111
	DW	06EH	; 110
	DW	06CH	; 108
	DW	06BH	; 107
	DW	069H	; 105
	DW	068H	; 104
	DW	066H	; 102
	DW	065H	; 101
	DW	064H	; 100
	DW	062H	; 98
	DW	061H	; 97
	DW	05FH	; 95
	DW	05EH	; 94
	DW	05DH	; 93
	DW	05CH	; 92
	DW	05BH	; 91
	DW	05AH	; 90
	DW	058H	; 88
	DW	057H	; 87
	DW	055H	; 85
	DW	054H	; 84
	DW	052H	; 82
	DW	051H	; 81
	DW	050H	; 80
	DW	04EH	; 78
	DW	04DH	; 77
	DW	04BH	; 75
	DW	04AH	; 74
	DW	048H	; 72
	DW	047H	; 71
	DW	046H	; 70
	DW	044H	; 68
	DW	043H	; 67
	DW	041H	; 65
	DW	040H	; 64
	DW	03FH	; 63
	DW	03EH	; 62
	DW	03DH	; 61
	DW	03CH	; 60
	DW	03AH	; 58
	DW	039H	; 57
	DW	037H	; 55
	DW	036H	; 54
	DW	034H	; 52
	DW	033H	; 51
	DW	032H	; 50
	DW	030H	; 48
	DW	02FH	; 47
	DW	02DH	; 45
	DW	02CH	; 44
	DW	02AH	; 42
	DW	029H	; 41
	DW	028H	; 40
	DW	026H	; 38
	DW	025H	; 37
	DW	023H	; 35
	DW	022H	; 34
	DW	021H	; 33
	DW	020H	; 32
	DW	01FH	; 31
	DW	01EH	; 30
	DW	01CH	; 28
	DW	01BH	; 27
	DW	019H	; 25
	DW	018H	; 24
	DW	016H	; 22
	DW	015H	; 21
	DW	014H	; 20
	DW	012H	; 18
	DW	011H	; 17
	DW	0FH	; 15
	DW	0EH	; 14
	DW	0CH	; 12
	DW	0BH	; 11
	DW	0AH	; 10
	DW	08H	; 8
	DW	07H	; 7
	DW	05H	; 5
	DW	04H	; 4
	DW	03H	; 3
	DW	02H	; 2
	DW	01H	; 1
	DW	00H	; 0
	DW	0FFFEH	; 65534
	DW	0FFFDH	; 65533
	DW	0FFFBH	; 65531
	DW	0FFFAH	; 65530
	DW	0FFF8H	; 65528
	DW	0FFF7H	; 65527
	DW	0FFF6H	; 65526
	DW	0FFF4H	; 65524
	DW	0FFF3H	; 65523
	DW	0FFF1H	; 65521
	DW	0FFF0H	; 65520
	DW	0FFEFH	; 65519
	DW	0FFEEH	; 65518
	DW	0FFEDH	; 65517
	DW	0FFECH	; 65516
	DW	0FFEAH	; 65514
	DW	0FFE9H	; 65513
	DW	0FFE7H	; 65511
	DW	0FFE6H	; 65510
	DW	0FFE4H	; 65508
	DW	0FFE3H	; 65507
	DW	0FFE2H	; 65506
	DW	0FFE0H	; 65504
	DW	0FFDFH	; 65503
	DW	0FFDDH	; 65501
	DW	0FFDCH	; 65500
	DW	0FFDAH	; 65498
	DW	0FFD9H	; 65497
	DW	0FFD8H	; 65496
	DW	0FFD6H	; 65494
	DW	0FFD5H	; 65493
	DW	0FFD3H	; 65491
	DW	0FFD2H	; 65490
	DW	0FFD1H	; 65489
	DW	0FFD0H	; 65488
	DW	0FFCFH	; 65487
	DW	0FFCEH	; 65486
	DW	0FFCCH	; 65484
	DW	0FFCBH	; 65483
	DW	0FFC9H	; 65481
	DW	0FFC8H	; 65480
	DW	0FFC6H	; 65478
	DW	0FFC5H	; 65477
	DW	0FFC4H	; 65476
	DW	0FFC2H	; 65474
	DW	0FFC1H	; 65473
	DW	0FFBFH	; 65471
	DW	0FFBEH	; 65470
	DW	0FFBCH	; 65468
	DW	0FFBBH	; 65467
	DW	0FFBAH	; 65466
	DW	0FFB8H	; 65464
	DW	0FFB7H	; 65463
	DW	0FFB5H	; 65461
	DW	0FFB4H	; 65460
	DW	0FFB3H	; 65459
	DW	0FFB2H	; 65458
	DW	0FFB1H	; 65457
	DW	0FFB0H	; 65456
	DW	0FFAEH	; 65454
	DW	0FFADH	; 65453
	DW	0FFABH	; 65451
	DW	0FFAAH	; 65450
	DW	0FFA8H	; 65448
	DW	0FFA7H	; 65447
	DW	0FFA6H	; 65446
	DW	0FFA4H	; 65444
	DW	0FFA3H	; 65443
	DW	0FFA1H	; 65441
	DW	0FFA0H	; 65440
	DW	0FF9FH	; 65439
	DW	0FF9EH	; 65438
	DW	0FF9DH	; 65437
	DW	0FF9CH	; 65436
?L0005:	DB	00H	; 0
	DB	080H	; 128
	DB	080H	; 128
	DB	(1)

@@R_INIT	CSEG	UNIT64KP
	DW	loww (_gu16_AdcAverage+4)
	DW	00H	; 0
	DW	015H	; 21
	DW	03ECH	; 1004

@@INIT	DSEG	BASEP
_gi16_MCUSensor:	DS	(8)

@@DATA	DSEG	BASEP
_gu8_CounterAdchannel:	DS	(1)
_gu8_AdcRepeat:	DS	(1)
_gu8_TimerAdcheck:	DS	(1)
	DS	(1)
_gu16_NowAdc:	DS	(6)
_gu16_SumAdc:	DS	(6)
_gu16_ADCBackValue:	DS	(6)
_gu16_AdcAverage:	DS	(6)

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
; line   169
; line   175
; line   180
; line   181
; line   182
; line   183
; line   184
; line   185
; line   161
; line   166
; line   167
; line   204
; line   408
; line   409
; line   410
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
; line    27
; line    29
; line   109
; line   113
; line   109
; line   200
; line   227
; line   254
; line   281
; line   282
; line   284
; line   285
; line   287
; line   289
; line   290
; line   291
; line   293
; line   295
; line   296
; line   297
; line   298
; line   300
; line   301
; line   303
; line   334
; line   335
; line   340
; line   345
; line   346
; line   347
; line   348
; line   349
; line   350
; line    57
; line    59
; line    60
; line    65
; line    66
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
; line    48
; line    50
; line    51
; line    52
; line    53
; line    58
; line    59
; line    60
; line    61
; line    62
; line    63
; line    64
; line    65
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
; line   128
; line   135
; line   177
; line   178
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
; line    41
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
; line    66
; line    67
; line    68
; line    69
; line    70
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
; line    87
; line    88
; line    89
; line    90
; line    91
; line    92
; line    93
; line    94
; line    95
; line    96
; line    97
; line    98
; line    99
; line   112
; line   113
; line   114
; line   115
; line   116
; line   117
; line   118
; line   122
; line   124
; line    45
; line    46
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
; line    12

@@CODEL	CSEG
_ADC_Initialize:
$DGL	1,29
??bf_ADC_Initialize:
; line    13
$DGL	0,2
	mov	!_gu8_TimerAdcheck,#0C8H	; 200 		;[INF] 4, 1
; line    14
$DGL	0,3
??ef_ADC_Initialize:
	ret							;[INF] 1, 6
??ee_ADC_Initialize:
; line    20
_Input_AD_Change:
$DGL	1,35
	push	hl						;[INF] 1, 1
	push	ax						;[INF] 1, 1
	movw	hl,sp						;[INF] 3, 1
??bf_Input_AD_Change:
; line    22
; line    29
$DGL	0,10
	bt	IF1H.0,$?L0006					;[INF] 4, 5
; line    30
??bb00_Input_AD_Change:
; line    31
$DGL	0,12
	nop							;[INF] 1, 1
; line    32
$DGL	0,13
	nop							;[INF] 1, 1
; line    33
$DGL	0,14
	nop							;[INF] 1, 1
; line    34
$DGL	0,15
	cmp0	!_gu8_TimerAdcheck				;[INF] 3, 1
	sknz							;[INF] 2, 1
; line    35
??bb01_Input_AD_Change:
; line    36
$DGL	0,17
	call	!!_SafetyLoop					;[INF] 4, 3
??eb01_Input_AD_Change:
; line    37
?L0008:
?L0009:
; line    38
$DGL	0,19
	br	$!?L0004					;[INF] 3, 3
??eb00_Input_AD_Change:
; line    39
?L0006:
?L0007:
; line    40
$DGL	0,21
	mov	!_gu8_TimerAdcheck,#0C8H	; 200 		;[INF] 4, 1
; line    42
$DGL	0,23
	clr1	IF1H.0						;[INF] 3, 2
; line    43
$DGL	0,24
	clr1	ADM0.7						;[INF] 3, 2
; line    44
$DGL	0,25
	clr1	ADM0.0						;[INF] 3, 2
; line    46
$DGL	0,27
	movw	ax,ADCR						;[INF] 2, 1
	shrw	ax,6						;[INF] 2, 1
	movw	bc,ax						;[INF] 1, 1
	mov	x,!_gu8_CounterAdchannel			;[INF] 3, 1
	clrb	a						;[INF] 1, 1
	addw	ax,ax						;[INF] 1, 1
	addw	ax,#loww (_gu16_NowAdc)				;[INF] 3, 1
	movw	de,ax						;[INF] 1, 1
	movw	ax,bc						;[INF] 1, 1
	movw	[de],ax						;[INF] 1, 1
; line    48
$DGL	0,29
	inc	!_gu8_CounterAdchannel				;[INF] 3, 2
; line    50
$DGL	0,31
	cmp	!_gu8_CounterAdchannel,#03H	; 3 		;[INF] 4, 1
	bc	$?L0010						;[INF] 2, 4
; line    51
??bb02_Input_AD_Change:
; line    52
$DGL	0,33
	clrb	!_gu8_CounterAdchannel				;[INF] 3, 1
; line    53
$DGL	0,34
	mov	[hl+1],#00H	; mu8_i,0 			;[INF] 3, 1
?L0012:
	mov	a,[hl+1]	; mu8_i 			;[INF] 2, 1
	cmp	a,#03H	; 3 					;[INF] 2, 1
	bnc	$?L0013						;[INF] 2, 4
; line    54
??bb03_Input_AD_Change:
; line    55
$DGL	0,36
	mov	a,[hl+1]	; mu8_i 			;[INF] 2, 1
	clrb	x						;[INF] 1, 1
	shrw	ax,7						;[INF] 2, 1
	movw	bc,ax						;[INF] 1, 1
	movw	ax,_gu16_NowAdc[bc]				;[INF] 3, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,[hl+1]	; mu8_i 			;[INF] 2, 1
	clrb	x						;[INF] 1, 1
	shrw	ax,7						;[INF] 2, 1
	addw	ax,#loww (_gu16_SumAdc)				;[INF] 3, 1
	movw	de,ax						;[INF] 1, 1
	movw	ax,[de]						;[INF] 1, 1
	addw	ax,bc						;[INF] 1, 1
	movw	[de],ax						;[INF] 1, 1
??eb03_Input_AD_Change:
; line    56
$DGL	0,37
?L0014:
	inc	[hl+1]	; mu8_i 				;[INF] 3, 2
	br	$?L0012						;[INF] 2, 3
?L0013:
; line    58
$DGL	0,39
	inc	!_gu8_AdcRepeat					;[INF] 3, 2
; line    60
$DGL	0,41
	cmp	!_gu8_AdcRepeat,#08H	; 8 			;[INF] 4, 1
	bc	$?L0015						;[INF] 2, 4
; line    61
??bb04_Input_AD_Change:
; line    62
$DGL	0,43
	clrb	!_gu8_AdcRepeat					;[INF] 3, 1
; line    63
$DGL	0,44
	mov	[hl+1],#00H	; mu8_i,0 			;[INF] 3, 1
?L0017:
	mov	a,[hl+1]	; mu8_i 			;[INF] 2, 1
	cmp	a,#03H	; 3 					;[INF] 2, 1
	bnc	$?L0018						;[INF] 2, 4
; line    64
??bb05_Input_AD_Change:
; line    65
$DGL	0,46
	mov	a,[hl+1]	; mu8_i 			;[INF] 2, 1
	clrb	x						;[INF] 1, 1
	shrw	ax,7						;[INF] 2, 1
	movw	bc,ax						;[INF] 1, 1
	movw	ax,_gu16_SumAdc[bc]				;[INF] 3, 1
	shrw	ax,3						;[INF] 2, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,[hl+1]	; mu8_i 			;[INF] 2, 1
	clrb	x						;[INF] 1, 1
	shrw	ax,7						;[INF] 2, 1
	xchw	ax,bc						;[INF] 1, 1
	movw	_gu16_AdcAverage[bc],ax				;[INF] 3, 1
; line    70
$DGL	0,51
	mov	a,[hl+1]	; mu8_i 			;[INF] 2, 1
	clrb	x						;[INF] 1, 1
	shrw	ax,7						;[INF] 2, 1
	movw	bc,ax						;[INF] 1, 1
	clrw	ax						;[INF] 1, 1
	movw	_gu16_SumAdc[bc],ax				;[INF] 3, 1
??eb05_Input_AD_Change:
; line    72
$DGL	0,53
?L0019:
	inc	[hl+1]	; mu8_i 				;[INF] 3, 2
	br	$?L0017						;[INF] 2, 3
?L0018:
??eb04_Input_AD_Change:
; line    73
?L0015:
?L0016:
??eb02_Input_AD_Change:
; line    74
?L0010:
?L0011:
; line    76
$DGL	0,57
	set1	ADM0.0						;[INF] 3, 2
; line    77
$DGL	0,58
	mov	x,!_gu8_CounterAdchannel			;[INF] 3, 1
	clrb	a						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	mov	a,?L0005[bc]	; Table_ADch 			;[INF] 3, 1
	mov	ADS,a						;[INF] 2, 1
; line    78
$DGL	0,59
	nop							;[INF] 1, 1
; line    79
$DGL	0,60
	nop							;[INF] 1, 1
; line    80
$DGL	0,61
	set1	ADM0.7						;[INF] 3, 2
; line    81
$DGL	0,62
	clr1	IF1H.0						;[INF] 3, 2
; line    82
?L0004:
; line    82
$DGL	0,63
??ef_Input_AD_Change:
	pop	ax						;[INF] 1, 1
	pop	hl						;[INF] 1, 1
	ret							;[INF] 1, 6
??ee_Input_AD_Change:
; line    88
_Temperature_Change:
$DGL	1,68
??bf_Temperature_Change:
; line   109
$DGL	0,22
	movw	ax,!_gu16_AdcAverage+4				;[INF] 3, 1
	cmpw	ax,#044H	; 68 				;[INF] 3, 1
	bnc	$?L0022						;[INF] 2, 4
; line   110
??bb00_Temperature_Change:
; line   111
$DGL	0,24
	movw	ax,!_MCUTemp_Table				;[INF] 3, 1
	movw	!_gi16_MCUSensor+2,ax				;[INF] 3, 1
??eb00_Temperature_Change:
; line   113
$DGL	0,26
	br	$?L0023						;[INF] 2, 3
?L0022:
	movw	ax,!_gu16_AdcAverage+4				;[INF] 3, 1
	cmpw	ax,#01DBH	; 475 				;[INF] 3, 1
	bc	$?L0024						;[INF] 2, 4
; line   114
??bb01_Temperature_Change:
; line   115
$DGL	0,28
	movw	ax,!_MCUTemp_Table+812				;[INF] 3, 1
	movw	!_gi16_MCUSensor+2,ax				;[INF] 3, 1
??eb01_Temperature_Change:
; line   117
$DGL	0,30
	br	$?L0025						;[INF] 2, 3
?L0024:
; line   118
??bb02_Temperature_Change:
; line   119
$DGL	0,32
	movw	ax,!_gu16_AdcAverage+4				;[INF] 3, 1
	addw	ax,ax						;[INF] 1, 1
	movw	bc,ax						;[INF] 1, 1
	movw	ax,_MCUTemp_Table-136[bc]			;[INF] 3, 1
	movw	!_gi16_MCUSensor+2,ax				;[INF] 3, 1
??eb02_Temperature_Change:
; line   120
?L0025:
?L0023:
; line   122
$DGL	0,35
??ef_Temperature_Change:
	ret							;[INF] 1, 6
??ee_Temperature_Change:

@@CODE	CSEG	BASE

@@BASE	CSEG	BASE

@@FIX	DSEG	BASEP

	END


; *** Code Information ***
;
; $FILE D:\Project\ICON_FOTA\FRONT\Icon_2_0_Front_V1001_forMP_0xD451_220502\Sou
;	rce\adc.c
;
; $FUNC ADC_Initialize(12)
;	void=(void)
;	CODE SIZE= 5 bytes, CLOCK_SIZE= 7 clocks, STACK_SIZE= 0 bytes
;
; $FUNC Input_AD_Change(20)
;	void=(void)
;	CODE SIZE= 182 bytes, CLOCK_SIZE= 129 clocks, STACK_SIZE= 8 bytes
;
; $CALL SafetyLoop(36)
;	void=(void)
;
; $FUNC Temperature_Change(88)
;	void=(void)
;	CODE SIZE= 44 bytes, CLOCK_SIZE= 33 clocks, STACK_SIZE= 0 bytes

; Target chip : R5F100LE
; Device file : V1.14 
