//
// Created by Wojcik98 on 20.09.18.
//

#ifndef TRZEWIKODZIOB_ENCODERS_H
#define TRZEWIKODZIOB_ENCODERS_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_exti.h"

#define ENC_L_A_PIN GPIO_Pin_6
#define ENC_L_B_PIN GPIO_Pin_5
#define ENC_R_A_PIN GPIO_Pin_8
#define ENC_R_B_PIN GPIO_Pin_7
#define ENC_PORT GPIOB

#define ENC_PORT_SOURCE EXTI_PortSourceGPIOB
#define ENC_L_A_PIN_SOURCE EXTI_PinSource6
#define ENC_R_A_PIN_SOURCE EXTI_PinSource8

#define ENC_L_A_LINE EXTI_Line6
#define ENC_R_A_LINE EXTI_Line8

void encodersConfig();

#endif
