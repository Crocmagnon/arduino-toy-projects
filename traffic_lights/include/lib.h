//
// Created by Gabriel Augendre on 27/04/2021.
//

#ifndef TOY_PROJECTS_LIB_H
#define TOY_PROJECTS_LIB_H

#define GREEN 2
#define YELLOW 3
#define RED 4
#define BUZZER 5
#define BUTTON 6
#define BUZZ_DURATION 100
#define BUZZ_FREQUENCY 440

/**
 * Block until the button is pressed.
 */
void waitForButton();

/**
 * Make the buzzer beep n times.
 * @param n number of times the buzzer should beep.
 */
void beep(int n);

/**
 * Make the buzzer beep once.
 * See `beep(int)` for more control.
 */
void beep();

#endif //TOY_PROJECTS_LIB_H
