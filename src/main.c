#include "main.h"
#include "gpio.h"
#include "rcc.h"
#include "adc.h"

int main(void) {
    SystemInit();

    GPIO_Config();
    ADC_Config();
    RCC_Config();

    while (1) {
    }
}
