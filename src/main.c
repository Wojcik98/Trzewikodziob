#include "main.h"
#include "gpio.h"
#include "rcc.h"
#include "encoders.h"
#include "motors.h"
#include "sensors.h"

int main(void) {
    SystemInit();
    if (SysTick_Config(SystemCoreClock/1000)){
        while (1);
    }

    GPIO_Config();
    RCC_Config();
    encodersConfig();
    motorsConfig();
    sensorsConfig();

    while (1) {
    }
}
