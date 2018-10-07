//
// Created by Wojcik98 on 07.10.18.
//

#ifndef TRZEWIKODZIOB_SETTINGS_H
#define TRZEWIKODZIOB_SETTINGS_H

#include <stm32f4xx.h>

#define M_S (1907270)
#define STANDARD_TR_ACC (1<<14)
#define STANDARD_ROT_V (1 << 29)
#define STANDARD_ROT_ACC (1<<17)

#define SLOW_SET 0
#define MEDIUM_SET 1
#define FAST_SET 2

typedef struct {
    u32 vTr, aTr;
    u32 vRot, aRot;
    u16 pTr, dTr;
    u16 pRot, dRot;
} setting;

extern s16 regPTr;
extern s16 regDTr;

extern s16 regPRot;
extern s16 regDRot;

extern s32 set_targetVTr_16;
extern s32 set_accTr_16;

extern s32 set_targetVRot_16;
extern s32 set_accRot_16;

extern s16 weights[12];

void loadSettings(u8 num);

#endif //TRZEWIKODZIOB_SETTINGS_H
