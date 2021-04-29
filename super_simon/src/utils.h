//
// Created by Gabriel Augendre on 29/04/2021.
//

#ifndef SUPER_SIMON_UTILS_H
#define SUPER_SIMON_UTILS_H

void activate(byte index);
void buzz(byte index, unsigned long duration = 0);
bool buttonIsPressed(byte index);
void deactivateAll();

#endif //SUPER_SIMON_UTILS_H
