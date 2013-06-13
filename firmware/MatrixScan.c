#include "MatrixScan.h"

/*
 *Scan matrix, 
 *    8 high bits contains detect Ports. Little Ending.
 *    That means, the last bit in these is 1 if detect Line 1 gets true.
 *    8 low bits contain the active scan ports. Just as integer.
 *    That means, 0x0a means the scan line 11 is on at that time.  */
uint16_t matrix1st[scanLines] = {
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
};
uint16_t matrix2nd[scanLines] = {
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
};
uint16_t matrixFlt[scanLines] = {
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
};
/*save function key and switches status*/
bool funcKeyStatus = false;
bool KeySwitchesBl[10];
/*save the temperature keys detected*/
uint8_t detectPorts_Keycodes[detectLines];
uint8_t keysGet_NoModifier[6];
uint8_t keysGet_Modifier;

/*matrix init status*/
bool matrix_Init_Done = false;

/*Init the keys matrix, let all ports ready*/
bool inline matrix_Init(void) {
    if (matrix_Init_Done)
        return matrix_Init_Done;
    else {
        scanLines_Init();
        detectLines_Init();
        matrix_Init_Done = true;
        return matrix_Init_Done;
    }
}

void inline matrix_Status_Init(void) {
    for (int8_t i = 0; i < scanLines; i++) {
        matrix1st[i] = 0xffff;
        matrix2nd[i] = 0xffff;
        matrixFlt[i] = 0xffff;
    }
    funcKeyStatus = false;
    for (int8_t i = 0; i < 10; i++)
        KeySwitchesBl[i] = false;
    for (int8_t i = 0; i < detectLines; i++)
        detectPorts_Keycodes[i] = 0x00;
    for (int8_t i = 0; i < 6; i++)
        keysGet_NoModifier[i] = 0x00;
    keysGet_Modifier = 0x00;
}

/*detect whether any signal get from detect ports*/
uint8_t inline detectPortsGet(void) {
    uint8_t tmpReturn = 0x00;
    for (int i = 0; i < detectLines; i++) {
        tmpReturn |= (detectLine[i]() << i);
    }
    return tmpReturn;
}

/*get the matrix status and save to the uint16_t matrix[16] array*/
void inline scanMatrix(uint16_t* matrixGet) {
    if (!matrix_Init_Done)
        matrix_Init();
    for (int i = 0; i < scanLines ; i++) {
        scanLine[i]();
        *(matrixGet + i) = (
                        (detectPortsGet() << 8 ) | i
                        );
    }
}

/*flite the random disturbance term out from the matrix status*/
void scanMatrixFlt(void) {
    matrix_Status_Init();
    scanMatrix (&matrix1st[0]);
    _delay_ms(10);
    scanMatrix (&matrix2nd[0]);
    for (int i = 0; i < scanLines ; i++) {
        matrixFlt[i] = matrix1st[i] & matrix2nd[i];
    }
}

void inline funcKeySwitchesGetStatus(uint16_t* matrixFltPtr) {
    for (int i = 0; i < scanLines; i++) {
        uint8_t scanLineAct = (*(matrixFltPtr + i) & 0x00ff);
        uint8_t detectBits = ((*(matrixFltPtr + i) & 0xff00) >> 8);
        if ( scanLineAct >= scanLines )
            return;
        else {
            for (int i = 0; i < detectLines; i++) {
                if ( ((detectBits & (1<<i)) != 0x00 ) && \
                     (N_KeyMatrix[i][scanLineAct] >= 0xf0 ) ) {
                    uint8_t j = (N_KeyMatrix[i][scanLineAct] & 0x0f);
                    if ( j <= 0x09 )
                        KeySwitchesBl[j] = true;
                    else{
                        if ( j == 0x0f )
                            funcKeyStatus = true;
                    }
                }
            }
        }
    }
}

/*get the keycodes except the modifiers from the matrix status element*/
/*NOTE: 已重写，因为Fn键和开关的问题*/
void inline detectPorts_KeycodesFunc(uint16_t matrixFltElm,
                                     uint8_t* detectPorts_KeycodesPtr) {
    if (matrixFltElm == 0xffff)
        return; //error happened.
    for (int i = 0; i < detectLines; i++) {
        detectPorts_Keycodes[i] = 0x00;
    }   // Initialize the array to return keys which has been pressed.
    uint8_t scanLineAct = (matrixFltElm & 0x00ff);
    uint8_t detectBits = ((matrixFltElm & 0xff00) >> 8);
    if ( ( scanLineAct >= scanLines ) || \
         ( detectBits == 0x00) )
        return;
    else {
        for (int i = 0; i < detectLines; i++) {
            if ( (detectBits & (1<<i)) != 0x00){
                if (funcKeyStatus)
                    *(detectPorts_KeycodesPtr + i) = \
                                         F_KeyMatrix[i][scanLineAct];
                else
                    for (int j= 0; j < 10; j++) {
                        if ((KeySwitchesBl[j]) && \
                                (i == KeySwitchesPtr[j]->detectLineNum) && \
                                (scanLineAct==KeySwitchesPtr[j]->scanLineNum)
                            )
                            *(detectPorts_KeycodesPtr + i) = \
                                             KeySwitchesPtr[j]->KeycodeNew;
                    };
                    *(detectPorts_KeycodesPtr + i) = \
                                         N_KeyMatrix[i][scanLineAct];
            }
            else
                *(detectPorts_KeycodesPtr + i) = 0x00;
        }
    }
}

/*get the modifiers bits from the matrix status element*/
uint8_t inline modifierBitSet(uint8_t keycode) {
    uint8_t mdfKeyBitRet = 0x00;
    switch (keycode) {
    case KEYCODE_LEFT_CONTROL :
        mdfKeyBitRet = (1 << 0); break;
    case KEYCODE_LEFT_SHIFT :
        mdfKeyBitRet = (1 << 1); break;
    case KEYCODE_LEFT_ALT :
        mdfKeyBitRet = (1 << 2); break;
    case KEYCODE_LEFT_GUI :
        mdfKeyBitRet = (1 << 3); break;
    case KEYCODE_RIGHT_CONTROL :
        mdfKeyBitRet = (1 << 4); break;
    case KEYCODE_RIGHT_SHIFT :
        mdfKeyBitRet = (1 << 5); break;
    case KEYCODE_RIGHT_ALT :
        mdfKeyBitRet = (1 << 6); break;
    case KEYCODE_RIGHT_GUI :
        mdfKeyBitRet = (1 << 7); break;
    default:
        mdfKeyBitRet = 0x00; break;
    }
    return mdfKeyBitRet;
}

void matrixGetKeycode(uint16_t* matrixFlt,
                      uint8_t* keysGet_NoModifier_Ptr,
                      uint8_t* keysGet_ModifierPtr) {
    scanMatrixFlt();
    funcKeySwitchesGetStatus(&matrixFlt[0]);
    int j = 0;
    for (int i = 0; i < scanLines; i++) {
        detectPorts_KeycodesFunc(*(matrixFlt + i), \
                                &detectPorts_Keycodes[0]);
        for (int i = 0; i < detectLines; i++) {
            if (detectPorts_Keycodes[i] != 0x00) {
                if ( modifierBitSet(detectPorts_Keycodes[i]) != 0x00)
                    *keysGet_ModifierPtr |= \
                                modifierBitSet(detectPorts_Keycodes[i]);
                else {
                    if ( j < 6 ) {
                        *(keysGet_NoModifier_Ptr + j) = \
                                detectPorts_Keycodes[i];
                        j++;
                    }
                }
            }
        }
    }
}

