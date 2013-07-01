#include "Ports.h"

#ifndef _KeyboardLEDs_H_
#define _KeyboardLEDs_H_

enum {
    NumLockLED,
    CapsLockLED,
    ScrLockLED,
    ComposeLED,
    KanaLED,
} LED_t;

static void LEDs_Init(void) {
    LedLines_Init();
    LedLine[NumLockLED](LED_On);
    LedLine[CapsLockLED](LED_On);
    LedLine[ScrLockLED](LED_On);
    _delay_ms(1000);
    LedLine[NumLockLED](LED_Off);
    LedLine[CapsLockLED](LED_Off);
    LedLine[ScrLockLED](LED_Off);
};

#endif
