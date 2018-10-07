//
// Created by Wojcik98 on 07.10.18.
//

#include "pid.h"
#include "settings.h"

s16 regPTr;
s16 regDTr;

s16 regPRot;
s16 regDRot;

s32 set_targetVTr_16;
s32 set_accTr_16;

s32 set_targetVRot_16;
s32 set_accRot_16;

setting preLoaded[3] = {
        {       // SLOW
                (u32) (0.75 * M_S), STANDARD_TR_ACC,    // Tr
                STANDARD_ROT_V, STANDARD_ROT_ACC,       // Rot
                200, 170,                               // PD Tr
                1000, 400                               // PD Rot
        },
        {    // MEDIUM
                1 * M_S,            STANDARD_TR_ACC,
                STANDARD_ROT_V, STANDARD_ROT_ACC,
                50,  50,
                900,  500
        },
        {    // FAST
                (u32) (1.25 * M_S), STANDARD_TR_ACC,
                STANDARD_ROT_V, STANDARD_ROT_ACC,
                50,  50,
                1900, 500
        }
};

s16 weights[12] = {-60, -50, -40, -30, -20, -10, 10, 20, 30, 40, 50, 60};

void loadSettings(u8 num) {
    if (num > 2) return;

    regPTr = preLoaded[num].pTr;
    regDTr = preLoaded[num].dTr;
    regPRot = preLoaded[num].pRot;
    regDRot = preLoaded[num].dRot;

    set_targetVTr_16 = preLoaded[num].vTr;
    set_accTr_16 = preLoaded[num].aTr;
    set_targetVRot_16 = preLoaded[num].vRot;
    set_accRot_16 = preLoaded[num].aRot;

    applySettings();
}
