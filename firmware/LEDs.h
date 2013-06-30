#include "Ports.h"

#ifndef _KeyboardLEDs_H_
#define _KeyboardLEDs_H_

static void LEDs_Init(void) {
    LedLines_Init();
}

typedef enum {
    NumLockLED,
    CapsLockLED,
    ScrLockLED,
    Compose,
    Kana,
} LED_t;

static bool inline NumLockLED(bool onOff) {
    if (onOff)
        PORTC |= (1 << PORTC7);
    else
        PORTC &= ~(1 << PORTC7);
    return onOff;
}

static bool inline CapsLockLED(bool onOff) {
    if (onOff)
        PORTD &= ~(1 << PORTD5);
    else
        PORTD |= (1 << PORTD5);
    return onOff;
}

static bool inline ScrLockLED(bool onOff) {
    if (onOff)
        PORTB &= ~(1 << PORTB0);
    else
        PORTB |= (1 << PORTB0);
    return onOff;
}
#endif
