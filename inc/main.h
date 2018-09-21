#ifndef MAIN_H
#define MAIN_H

#include "stm32f4xx_gpio.h"

#define SW_1_Pin GPIO_Pin_13
#define SW_1_GPIO_Port GPIOC
#define SW_2_Pin GPIO_Pin_14
#define SW_2_GPIO_Port GPIOC
#define SW_3_Pin GPIO_Pin_15
#define SW_3_GPIO_Port GPIOC
#define LED_3_Pin GPIO_Pin_5
#define LED_3_GPIO_Port GPIOC
#define LED_2_Pin GPIO_Pin_0
#define LED_2_GPIO_Port GPIOB
#define LED_E_Pin GPIO_Pin_2
#define LED_E_GPIO_Port GPIOB
#define LED_S_Pin GPIO_Pin_10
#define LED_S_GPIO_Port GPIOB
#define SW_5_Pin GPIO_Pin_6
#define SW_5_GPIO_Port GPIOC
#define SW_4_Pin GPIO_Pin_7
#define SW_4_GPIO_Port GPIOC
#define PWM_R_Pin GPIO_Pin_9
#define PWM_R_GPIO_Port GPIOA
#define PWM_L_Pin GPIO_Pin_10
#define PWM_L_GPIO_Port GPIOA
#define M_L2_Pin GPIO_Pin_11
#define M_L2_GPIO_Port GPIOA
#define M_L1_Pin GPIO_Pin_12
#define M_L1_GPIO_Port GPIOA
#define M_R1_Pin GPIO_Pin_15
#define M_R1_GPIO_Port GPIOA
#define M_R2_Pin GPIO_Pin_3
#define M_R2_GPIO_Port GPIOB
#define IR_Pin GPIO_Pin_4
#define IR_GPIO_Port GPIOB
#define LED_1_Pin GPIO_Pin_9
#define LED_1_GPIO_Port GPIOB

typedef uint16_t u16;

#endif
