//
// Created by Wojcik98 on 22.09.18.
//

#include <stm32f4xx_rcc.h>
#include <stm32f4xx_gpio.h>
#include "utils.h"
#include "ui.h"

static void GPIO_Config(void);

static void RCC_Config(void);

void uiConfig() {
    RCC_Config();
    GPIO_Config();

    LED_1_OFF;
    LED_2_OFF;
    LED_3_OFF;
}

void blink(u8 led, u16 time) {
    switch (led) {
        case 1:
            LED_1_ON;
            delay(time);
            LED_1_OFF;
            delay(time);
            break;
        case 2:
            LED_2_ON;
            delay(time);
            LED_2_OFF;
            delay(time);
            break;
        case 3:
            LED_3_ON;
            delay(time);
            LED_3_OFF;
            delay(time);
            break;
        default:
            break;
    }
}

void GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    // GPIO
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Pin = SW_1_Pin | SW_2_Pin | SW_3_Pin | SW_4_Pin | SW_5_Pin;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Pin = LED_1_Pin | LED_2_Pin;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Pin = LED_3_Pin;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void RCC_Config() {
    // Enable GPIO clocks
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
}
