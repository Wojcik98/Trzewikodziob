//
// Created by Wojcik98 on 21.09.18.
//

#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>
#include <math.h>
#include "motors.h"

static void GPIO_Config(void);

static void RCC_Config(void);

static void TIM_Config(void);

void motorsConfig() {
    RCC_Config();
    GPIO_Config();
    TIM_Config();
    M_L_FORWARD;
    PWM_L = 0;
    M_R_FORWARD;
    PWM_R = 0;
}

void setPwmL(s32 pwm) {
    if (pwm > 0) {
        M_L_FORWARD;
    } else {
        M_L_BACKWARD;
    }

    PWM_L = (u32) abs(pwm);
}

void setPwmR(s32 pwm) {
    if (pwm > 0) {
        M_R_FORWARD;
    } else {
        M_R_BACKWARD;
    }

    PWM_R = (u32) abs(pwm);
}

void setPwm(s32 pwmL, s32 pwmR) {
    setPwmL(pwmL);
    setPwmR(pwmR);
}

void GPIO_Config() {
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    // Direction control pins
    GPIO_InitStructure.GPIO_Pin = M_L1_Pin | M_L2_Pin | M_R1_Pin;
    GPIO_Init(M_L1_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = M_R2_Pin;
    GPIO_Init(M_R2_Port, &GPIO_InitStructure);

    // TIM1 PWM pins
    GPIO_InitStructure.GPIO_Pin = PWM_L_Pin | PWM_R_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(PWM_L_Port, &GPIO_InitStructure);

    // Set alternative functions
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_TIM1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_TIM1);
}

void TIM_Config() {
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    // Configure timer
    TIM_TimeBaseStructure.TIM_Period = PWM_PERIOD;
    TIM_TimeBaseStructure.TIM_Prescaler = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInit(PWM_TIM, &TIM_TimeBaseStructure);

    // Configure canals
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    //PWM canal 2
    TIM_OC2Init(PWM_TIM, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(PWM_TIM, TIM_OCPreload_Enable);
    //PWM canal 3
    TIM_OC3Init(PWM_TIM, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(PWM_TIM, TIM_OCPreload_Enable);

    // Enable timer and output
    TIM_ARRPreloadConfig(PWM_TIM, ENABLE);
    TIM_Cmd(PWM_TIM, ENABLE);
    TIM_CtrlPWMOutputs(PWM_TIM, ENABLE);
}

void RCC_Config() {
    // Enable GPIO clocks
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    // Enable TIM1 clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
}
