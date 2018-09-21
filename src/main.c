#include "main.h"
#include "gpio.h"
#include "rcc.h"
#include "adc.h"
#include "encoders.h"

int main(void) {
    SystemInit();
    if (SysTick_Config(SystemCoreClock/1000)){
        while (1);
    }

    GPIO_Config();
    ADC_Config();
    RCC_Config();
    encodersConfig();

    while (1) {
    }
}
