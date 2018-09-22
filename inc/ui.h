//
// Created by Wojcik98 on 22.09.18.
//

#ifndef TRZEWIKODZIOB_UI_H
#define TRZEWIKODZIOB_UI_H

#define LED_1_Pin GPIO_Pin_9
#define LED_1_Port GPIOB
#define LED_2_Pin GPIO_Pin_0
#define LED_2_Port GPIOB
#define LED_3_Pin GPIO_Pin_5
#define LED_3_Port GPIOC

#define LED_1_ON LED_1_Port->BSRRH = LED_1_Pin
#define LED_1_OFF LED_1_Port->BSRRL = LED_1_Pin

#define LED_2_ON LED_2_Port->BSRRH = LED_2_Pin
#define LED_2_OFF LED_2_Port->BSRRL = LED_2_Pin

#define LED_3_PIN GPIO_Pin_5
#define LED_3_ON LED_3_Port->BSRRH = LED_3_PIN
#define LED_3_OFF LED_3_Port->BSRRL = LED_3_PIN

#define SW_1_Pin GPIO_Pin_13
#define SW_1_GPIO_Port GPIOC
#define SW_2_Pin GPIO_Pin_14
#define SW_2_GPIO_Port GPIOC
#define SW_3_Pin GPIO_Pin_15
#define SW_3_GPIO_Port GPIOC
#define SW_4_Pin GPIO_Pin_7
#define SW_4_GPIO_Port GPIOC
#define SW_5_Pin GPIO_Pin_6
#define SW_5_GPIO_Port GPIOC

void uiConfig(void);

#endif //TRZEWIKODZIOB_UI_H
