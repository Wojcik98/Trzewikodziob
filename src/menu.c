//
// Created by Wojcik98 on 30.09.18.
//

#include "menu.h"
#include "race.h"
#include "settings.h"
#include "ui.h"
#include "utils.h"

void menu() {
    if (SW_1) {
        loadSettings(SLOW_SET);
        blink(1, 500);
        race();
        blink(3, 500);
    }
}
