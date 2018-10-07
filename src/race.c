//
// Created by Wojcik98 on 30.09.18.
//

#include <stm32f4xx.h>
#include <stdbool.h>
#include "math.h"
#include "pid.h"
#include "sensors.h"
#include "menu.h"
#include "ui.h"
#include "race.h"

volatile bool isRace = false;

u16 sensors[12];
bool sensBool[12];

s16 weights[12] = {-60, -50, -40, -30, -20, -10, 10, 20, 30, 40, 50, 60};    // TODO read from settings
s32 speed = (953635<<1);    // 1m/s, TODO read from settings

void race() {
    updateError();
    isRace = true;
    while (1) {  // TODO end condition
        updateError();
        if (getBatt() < BATT_THRESHOLD) {
            LED_2_ON;
        }
    }
    isRace = false;
}

void updateError() {
    static s16 prevError = 0;
    static bool noSensFlag = false;

    getSensors(sensors);    // TODO continuous reads
    for (u8 i = 0; i < 12; i++) {
        sensBool[i] = (sensors[i] > BLACK_THRESHOLD);
    }

    s16 error = 0, sensCnt = 0;
    for (u8 i = 0; i < 12; i++) {
        error += sensBool[i] * weights[i];
        sensCnt += sensBool[i];
    }

    if (sensCnt == 0) {
        error = prevError;
    } else {
        error = error / sensCnt;
        prevError = error;
    }

    if (sensCnt == 0 && !noSensFlag) {  // Slow down if out of line
        setSpeed(speed >> 1);
        noSensFlag = true;
    } else if (noSensFlag && isLineInCenter()) {
        setSpeed(speed);
        noSensFlag = false;
    }

    rotate(error);  // TODO scale error, so it corresponds to real life angle, prob just weights
}

bool isLineInCenter() {
    bool result = false;
    for (u8 i = 3; i <= 8; i++) {
        result = result || sensBool[i];
    }
    return result;
}
