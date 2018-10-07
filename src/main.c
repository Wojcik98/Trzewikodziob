#include <race.h>
#include <pid.h>
#include "main.h"
#include "encoders.h"
#include "menu.h"
#include "motors.h"
#include "sensors.h"
#include "ui.h"
#include "utils.h"

int main(void) {
    SystemInit();
    setClockInterrupt();

    encodersConfig();
    motorsConfig();
    sensorsConfig();
    uiConfig();

    while (1) {
        menu();
    }
}

void setClockInterrupt() {
    // Set interrupt every 1ms
    if (SysTick_Config(SystemCoreClock / 1000)) {
        while (1);
    }
}

void SysTick_Handler(){
    delayDecrement();

    if (isRace) {
        pid();
    }
}
