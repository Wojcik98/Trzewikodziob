//
// Created by Wojcik98 on 30.09.18.
//

#include <stm32f4xx.h>
#include <stdbool.h>
#include "motors.h"
#include "math.h"
#include "pid.h"
#include "sensors.h"
#include "menu.h"
#include "ui.h"
#include "race.h"
#include "settings.h"

volatile bool isRace = false;

u16 sensors[12];
bool sensBool[12];

void race() {
    updateError();
    isRace = true;

    while (!(SW_1 || SW_2 || SW_3)) {
        updateError();
        if (getBatt() < BATT_THRESHOLD) {
            LED_2_ON;
        }
    }

    isRace = false;
    setPwm(0, 0);
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
        setSpeed(set_targetVTr_16 >> 1);
        noSensFlag = true;
    } else if (noSensFlag && isLineInCenter()) {
        setSpeed(set_targetVTr_16);
        noSensFlag = false;
    }

    rotate(error);  // TODO scale error, so it corresponds to real life angle, prob just weights
}

bool isLineInCenter() {
    bool result = false;
    for (u8 i = LINE_CENTER_BEGIN; i <= LINE_CENTER_END; i++) {
        result = result || sensBool[i];
    }
    return result;
}
