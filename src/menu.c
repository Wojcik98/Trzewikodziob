//
// Created by Wojcik98 on 30.09.18.
//

#include "utils.h"
#include "race.h"
#include "menu.h"
#include "ui.h"

void menu() {
    if (SW_1) {
        LED_1_ON;
        delay(200);
        LED_1_OFF;

        race();

        LED_3_ON;
        delay(200);
        LED_3_OFF;
    }
}
