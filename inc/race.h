//
// Created by Wojcik98 on 30.09.18.
//

#ifndef TRZEWIKODZIOB_RACE_H
#define TRZEWIKODZIOB_RACE_H

#include <stdbool.h>

#define LINE_CENTER_BEGIN 3
#define LINE_CENTER_END 8

void race(void);
void updateError(void);
bool isLineInCenter(void);

extern volatile bool isRace;

#endif //TRZEWIKODZIOB_RACE_H
