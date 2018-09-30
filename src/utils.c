//
// Created by Wojcik98 on 30.09.18.
//

#include "utils.h"

volatile u32 timeLeft;

void delayDecrement() {
    if (timeLeft) timeLeft--;
}

void delay(u32 time) {
    timeLeft = time;

    while (timeLeft);
}