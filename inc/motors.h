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

#define M_R1_ON GPIOA->BSRRL = M_R1_Pin
#define M_R1_OFF GPIOA->BSRRH = M_R1_Pin

#define M_R2_ON GPIOB->BSRRL = M_R2_Pin
#define M_R2_OFF GPIOB->BSRRH = M_R2_Pin

#define M_L1_ON GPIOA->BSRRL = M_L1_Pin
#define M_L1_OFF GPIOA->BSRRH = M_L1_Pin

#define M_L2_ON GPIOA->BSRRL = M_L2_Pin
#define M_L2_OFF GPIOA->BSRRH = M_L2_Pin

#define M_L_FORWARD do {M_L1_ON; M_L2_OFF;} while (0)
#define M_L_BACKWARD do {M_L1_OFF; M_L2_ON;} while (0)

#define M_R_FORWARD do {M_R1_ON; M_R2_OFF;} while (0)
#define M_R_BACKWARD do {M_R1_OFF; M_R2_ON;} while (0)

#define PWM_R TIM1->CCR3
#define PWM_L TIM1->CCR2

#define PWM_TIM TIM1

#define PWM_PERIOD ((1<<16)-1)

void motorsConfig(void);
void setPwmL(s32 pwm);
void setPwmR(s32 pwm);
void setPwm(s32 pwmL, s32 pwmR);

#endif //TRZEWIKODZIOB_MOTORS_H
