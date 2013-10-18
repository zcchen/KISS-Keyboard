//#include "Keyboard.h"
#include <inttypes.h>
#include <avr/io.h>

#ifndef _PORTS_H_
#define _PORTS_H_

struct IOBitSet {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    volatile uint8_t *pin;
    uint8_t IOoffSet;
    enum IOPortUsage_t {
        IOPortUsage_t_noUsed     = 0x00,
        IOPortUsage_t_scan       = 0x01,
        IOPortUsage_t_detect     = 0x02,
        IOPortUsage_t_LED_LowOn  = 0xf3,
        IOPortUsage_t_LED_HighOn = 0xfc,
    } PortUsage;
    int8_t lineNum;
} ;

//#define Ports_Init_Func
//Initialize the LED ports for keyboard.  
static inline void __LED_Init__(struct IOBitSet *IOPortPtr) {
    *IOPortPtr->ddr |= (1 << IOPortPtr->IOoffSet);
    switch (IOPortPtr->PortUsage) {
    case IOPortUsage_t_LED_LowOn: //pull up this IO port
        *IOPortPtr->port |= (1 << IOPortPtr->IOoffSet); break;
    case IOPortUsage_t_LED_HighOn: //pull down this IO port
        *IOPortPtr->port &= ~(1 << IOPortPtr->IOoffSet); break;
    default:
        *IOPortPtr->port &= ~(1 << IOPortPtr->IOoffSet); break;
    }
}

//Initialize the scan & detect ports for keyboard.  
static inline void scanPort_Init(struct IOBitSet *IOPortPtr) {
    *IOPortPtr->ddr |= (1 << IOPortPtr->IOoffSet);
    *IOPortPtr->port &= ~(1 << IOPortPtr->IOoffSet);
}
static inline void detectPort_Init(struct IOBitSet *IOPortPtr) {
    *IOPortPtr->ddr &= ~(1 << IOPortPtr->IOoffSet);
    *IOPortPtr->port |= (1 << IOPortPtr->IOoffSet);
}

/* Let the scan IO port in low viotage, aka, 1. */
void inline scanPort_On(struct IOBitSet *IOPortPtr) {
    *IOPortPtr->port |= (1 << IOPortPtr->IOoffSet);
}
 /* Let the scan IO port in high viotage, aka, 0. */
void inline scanPort_Off(struct IOBitSet *IOPortPtr) {
    *IOPortPtr->port &= ~(1 << IOPortPtr->IOoffSet);
}

/* Return the detect Port Bit   */
/*    Low viotage 0 means true  */
/*   High viotage 1 means false */
uint8_t inline detectPortRet (struct IOBitSet *IOPortPtr) {
    return !((*IOPortPtr->pin >> IOPortPtr->IOoffSet) & 1);
}

/* */
enum LEDctrl_t {
    LED_Toggle,
    LED_On,
    LED_Off,
} ;

void inline __LedPort_Ctrl__ (struct IOBitSet *IOPortPtr,
                              enum LEDctrl_t LEDctrl) {
    if (LEDctrl == LED_On) {
        switch (IOPortPtr->PortUsage) {
        case IOPortUsage_t_LED_LowOn: //pull down this IO port
            *IOPortPtr->port &= ~(1 << IOPortPtr->IOoffSet); break;
        case IOPortUsage_t_LED_HighOn: //pull up this IO port
            *IOPortPtr->port |= (1 << IOPortPtr->IOoffSet); break;
        default:break;
        }
    } else if (LEDctrl == LED_Off) {
        switch (IOPortPtr->PortUsage) {
        case IOPortUsage_t_LED_LowOn: //pull up this IO port
            *IOPortPtr->port |= (1 << IOPortPtr->IOoffSet); break;
        case IOPortUsage_t_LED_HighOn: //pull down this IO port
            *IOPortPtr->port &= ~(1 << IOPortPtr->IOoffSet); break;
        default:break;
        }
    }
    else if (LEDctrl == LED_Toggle) {
        *IOPortPtr->port ^= (1 << IOPortPtr->IOoffSet);
    }
}

//#ifdef Ports_Init_Func
void scanLines_Init(void);
void detectLines_Init(void);
void LedLines_Init(void);
//void inline scanLinesOff(void);
//#else
    //#error No lines in matrix has been defined.
//#endif
#define scanDetectLine
    #define scanLinesNum    16
    #define detectLinesNum  6
    #define LedLinesNum     3

extern void (* scanLine[])(void);
extern uint8_t (* detectLine[])(void);
extern void (* LedLine[])(enum LEDctrl_t LEDctrl);

#endif
