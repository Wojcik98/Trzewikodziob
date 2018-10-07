//
// Created by Wojcik98 on 30.09.18.
//

#ifndef TRZEWIKODZIOB_PID_H
#define TRZEWIKODZIOB_PID_H

#include <stm32f4xx.h>

void pid(void);
void setSpeed(s32 speed);
void rotate(s32 rotation);
void applySettings();

#endif //TRZEWIKODZIOB_PID_H
