//
// Created by Wojcik98 on 20.09.18.
//

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"
#include "misc.h"
#include "encoders.h"

void encodersConfig() {
    GPIO_InitTypeDef GPIO_InitStructure;
    EXTI_InitTypeDef EXTI_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    // Configure GPIO
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = ENC_L_A_PIN | ENC_L_B_PIN | ENC_R_A_PIN | ENC_R_B_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(ENC_PORT, &GPIO_InitStructure);

    // Configure interrupts
    // Connect EXTI Lines to pins
    SYSCFG_EXTILineConfig(ENC_PORT_SOURCE, ENC_L_A_PIN_SOURCE);
    SYSCFG_EXTILineConfig(ENC_PORT_SOURCE, ENC_R_A_PIN_SOURCE);

    // Init NVIC
    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    // Init EXTI
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;

    // Left encoder, input A
    EXTI_InitStructure.EXTI_Line = ENC_L_A_LINE;
    EXTI_Init(&EXTI_InitStructure);

    // Right encoder, input A
    EXTI_InitStructure.EXTI_Line = ENC_R_A_LINE;
    EXTI_Init(&EXTI_InitStructure);
}
