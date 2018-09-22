#include "main.h"
#include "encoders.h"
#include "motors.h"
#include "sensors.h"
#include "ui.h"

int main(void) {
    SystemInit();
    if (SysTick_Config(SystemCoreClock/1000)){
        while (1);
    }

    encodersConfig();
    motorsConfig();
    sensorsConfig();
    uiConfig();

    while (1) {
    }
}
