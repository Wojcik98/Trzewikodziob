//
// Created by Wojcik98 on 21.09.18.
//

#ifndef TRZEWIKODZIOB_MOTORS_H
#define TRZEWIKODZIOB_MOTORS_H

#include "stm32f4xx_gpio.h"

#define PWM_R_Pin GPIO_Pin_9
#define PWM_R_Port GPIOA
#define PWM_L_Pin GPIO_Pin_10
#define PWM_L_Port GPIOA
#define M_L2_Pin GPIO_Pin_11
#define M_L2_Port GPIOA
#define M_L1_Pin GPIO_Pin_12
#define M_L1_Port GPIOA
#define M_R1_Pin GPIO_Pin_15
#define M_R1_Port GPIOA
#define M_R2_Pin GPIO_Pin_3
#define M_R2_Port GPIOB

#define PWM_TIM TIM1

#define PWM_PERIOD ((1<<16)-1)

void motorsConfig(void);

#endif //TRZEWIKODZIOB_MOTORS_H
