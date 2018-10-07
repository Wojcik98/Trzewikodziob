//
// Created by Wojcik98 on 30.09.18.
//

#include "utils.h"
#include "race.h"
#include "menu.h"
#include "ui.h"

void menu() {
    if (SW_1) {
        blink(1, 500);
        race();
        blink(3, 500);
    }
}
