//
// Created by Wojcik98 on 20.09.18.
//

#ifndef TRZEWIKODZIOB_ENCODERS_H
#define TRZEWIKODZIOB_ENCODERS_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_exti.h"

#define ENC_L_A_Pin GPIO_Pin_6
#define ENC_L_B_Pin GPIO_Pin_5
#define ENC_R_A_Pin GPIO_Pin_8
#define ENC_R_B_Pin GPIO_Pin_7
#define ENC_Port GPIOB

#define ENC_PortSource EXTI_PortSourceGPIOB
#define ENC_L_A_PinSource EXTI_PinSource6
#define ENC_R_A_PinSource EXTI_PinSource8

#define ENC_L_A_Line EXTI_Line6
#define ENC_R_A_Line EXTI_Line8

void encodersConfig(void);

#endif
