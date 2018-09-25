//
// Created by Wojcik98 on 20.09.18.
//

#include <stm32f4xx_rcc.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_exti.h>
#include <stm32f4xx_syscfg.h>
#include <misc.h>
#include "encoders.h"

static void GPIO_Config(void);

static void NVIC_Config(void);

static void EXTI_Config(void);

static void RCC_Config(void);

volatile s32 enkL = 0, enkR = 0;

void encodersConfig() {
    RCC_Config();
    GPIO_Config();
    NVIC_Config();
    EXTI_Config();
}

void GPIO_Config() {
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = ENC_L_A_Pin | ENC_L_B_Pin | ENC_R_A_Pin | ENC_R_B_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(ENC_Port, &GPIO_InitStructure);
}

static void NVIC_Config() {
    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void EXTI_Config() {
    EXTI_InitTypeDef EXTI_InitStructure;

    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;

    // Left encoder, input A
    EXTI_InitStructure.EXTI_Line = ENC_L_A_Line;
    EXTI_Init(&EXTI_InitStructure);

    // Right encoder, input A
    EXTI_InitStructure.EXTI_Line = ENC_R_A_Line;
    EXTI_Init(&EXTI_InitStructure);

    // Connect EXTI Lines to pins
    SYSCFG_EXTILineConfig(ENC_PortSource, ENC_L_A_PinSource);
    SYSCFG_EXTILineConfig(ENC_PortSource, ENC_R_A_PinSource);
}

void RCC_Config() {
    // Enable EXTI clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
}

void EXTI9_5_IRQHandler(void) {
    if (EXTI_GetITStatus(EXTI_Line6) != RESET) {    // Input A Forward-Counterclockwise, B first
        if (GPIOB->IDR & GPIO_Pin_5) {    //if B-h, then A-h => forward
            ++enkL;
        } else {                            //if B-l, then A-h => backward
            --enkL;
        }
        EXTI->PR = EXTI_Line6;
    }
    if (EXTI_GetITStatus(EXTI_Line8) != RESET) {    //Input A Forward-Clockwise, A first
        if (GPIOB->IDR & GPIO_Pin_7) {    //if B-h, then A-h => backward
            --enkR;
        } else {                            //if B-l, then A-h => forward
            ++enkR;
        }
        EXTI->PR = EXTI_Line8;
    }
}
