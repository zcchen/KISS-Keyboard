#include "Keycodes.h"
#include "Ports.h"
#include <inttypes.h>
#include <stdbool.h>

#ifndef _KEY_MATRIX_H_
#define _KEY_MATRIX_H_

typedef struct {
    uint8_t detectLineNum;
    uint8_t scanLineNum;
    uint8_t KeyMatrixLayout;
    uint8_t KeycodeNew;
} KeySwitchStr;

//if Key-switch on, change that key to another keycode.
/*
 *uint8_t inline KeySwitchKey (KeySwitchStr* KeySwitchPtr) {
 *    return KeySwitchPtr->KeycodeNew;
 *}
 */

//Normal key map
extern uint8_t N_KeyMatrix[detectLinesNum][scanLinesNum];
//Fn key pressing key map
extern uint8_t F_KeyMatrix[detectLinesNum][scanLinesNum];
//Key switches pointer array.
extern KeySwitchStr* KeySwitchesPtr[10];

#endif
