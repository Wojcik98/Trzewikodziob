//
// Created by Wojcik98 on 22.09.18.
//

#include <stm32f4xx_rcc.h>
#include <stm32f4xx_gpio.h>
#include "ui.h"

static void GPIO_Config(void);

static void RCC_Config(void);

void uiConfig() {
    GPIO_Config();
    RCC_Config();
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
