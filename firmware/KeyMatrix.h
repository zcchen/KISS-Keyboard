#include "Keycodes.h"
#include "Ports.h"
#include <inttypes.h>

#ifndef _KEY_MATRIX_H_
#define _KEY_MATRIX_H_

//Normal key map
extern uint8_t N_KeyMatrix[detectLinesNum][scanLinesNum];
//Fn key pressing key map
extern uint8_t F_KeyMatrix[detectLinesNum][scanLinesNum];
//Key switches pointer array.
extern struct KeySwitchStr* KeySwitchesPtr[10];

//if Key-switch on, change that key to another keycode.
struct KeySwitchStr {
    uint8_t detectLineNum;
    uint8_t scanLineNum;
    uint8_t KeyMatrixLayout;
    uint8_t KeycodeNew;
    uint8_t KeycodeOld;
};

#ifndef KeySwitchDef
#ifndef KeyMatrixLayoutEquOne
#define KeyMatrixLayoutEquOne(a) (a==1 ?1 : 0xFF)
#endif
#ifndef KeyMatrixLayoutEquZero
#define KeyMatrixLayoutEquZero(a) (a==0 ?0 : 0xFF)
#endif
/*KeyMatrixLayout = 0, if it is in normal layout;
 *                = 1, if it is in Function layout.  */
#define KeySwitchDef(detectLineNum, scanLineNum, \
                     KeyMatrixLayout, KeycodeNew) \
    {detectLineNum, scanLineNum, \
        (KeyMatrixLayoutEquOne(KeyMatrixLayout) & \
         KeyMatrixLayoutEquZero(KeyMatrixLayout) ), \
        KeycodeNew}
#endif

#endif
