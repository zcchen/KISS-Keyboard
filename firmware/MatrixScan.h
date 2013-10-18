#include "Ports.h"
//#include "Keycodes.h"
#include "KeyMatrix.h"
#include <util/delay.h>
#include <stdbool.h>
#include <inttypes.h>

#ifndef _MATRIX_SCAN_H_
#define _MATRIX_SCAN_H_

void matrixGetKeycode(uint16_t* matrixFlt,
                      uint8_t* keysGet_NoModifier_Ptr,
                      uint8_t* keysGet_ModifierPtr);

/*
 *Scan matrix, 
 *    8 high bits contains detect Ports. Little Ending.
 *    That means, the last bit in these is 1 if detect Line 1 gets true.
 *    8 low bits contain the active scan ports. Just as integer.
 *    That means, 0x0a means the scan line 11 is on at that time.  */
/*
 *uint16_t matrixFlt[16] = {
 *    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
 *    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
 *};
 */
extern uint16_t matrixFlt[scanLinesNum];

extern uint8_t keysGet_NoModifier[6];
extern uint8_t keysGet_Modifier;

extern bool matrix_Init_Done;
#endif
