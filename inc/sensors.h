//
// Created by Wojcik98 on 22.09.18.
//

#ifndef TRZEWIKODZIOB_SENSORS_H
#define TRZEWIKODZIOB_SENSORS_H

#include <stm32f4xx.h>

#define S0 14
#define S1 7
#define S2 6
#define S3 5
#define S4 4
#define S5 2
#define S6 1
#define S7 0
#define S8 13
#define S9 12
#define S10 11
#define S11 10
#define ENH 3
#define BATT 9

void sensorsConfig(void);
u16 readADC(u8 channel);
u16 getBatt(void);
void getSensors(u16* sensors);

#endif //TRZEWIKODZIOB_SENSORS_H
