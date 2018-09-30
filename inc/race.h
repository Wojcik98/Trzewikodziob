//
// Created by Wojcik98 on 30.09.18.
//

#ifndef TRZEWIKODZIOB_RACE_H
#define TRZEWIKODZIOB_RACE_H

#include <stdbool.h>

void race(void);
void updateError(void);
bool isLineInCenter(void);

extern volatile bool isRace;

#endif //TRZEWIKODZIOB_RACE_H
