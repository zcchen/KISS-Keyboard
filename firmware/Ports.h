//#include "Keyboard.h"
#include <inttypes.h>
#include <avr/io.h>

#ifndef _PORTS_H_
#define _PORTS_H_

typedef struct {
    uint8_t *ddr;
    uint8_t *port;
    uint8_t *pin;
    uint8_t offSet;
} IOBitSet;

//#define Ports_Init_Func
     //Initialize the scan & detect ports for keyboard.  
    static inline void scanPort_Init( volatile uint8_t *ddr,
                                      volatile uint8_t *port,
                                      uint8_t offSet)   {
        *ddr |= (1 << offSet);
        *port &= ~(1 << offSet);                        }
    static inline void detectPort_Init( volatile uint8_t *ddr,
                                        volatile uint8_t *port,
                                        uint8_t offSet) {
        *ddr &= ~(1 << offSet);
        *port |= (1 << offSet);                         }

     //Let the scan IO port in low viotage, aka, 0. 
    inline void scanPort_On( volatile uint8_t *Port,
                                    uint8_t offSet) {
        *Port &= ~(1 << offSet);                    }
     //Let the scan IO port in high viotage, aka, 1. 
    inline void scanPort_Off( volatile uint8_t *Port,
                                     uint8_t offSet) {
        *Port |= (1 << offSet);                      }

    /* Return the detect Port Bit   */
    /*    Low viotage 0 means true  */
    /*   High viotage 1 means false */
    uint8_t inline detectPort (volatile uint8_t *Pin,
                            uint8_t offSet) {
        return !((*Pin >> offSet) & 1);     }

//#ifdef Ports_Init_Func
void scanLines_Init(void);
void detectLines_Init(void);
//void inline scanLinesOff(void);
//#else
    //#error No lines in matrix has been defined.
//#endif
#define scanDetectLine
    #define scanLines     16
    #define detectLines   6

extern void (* scanLine[])(void);
extern uint8_t (* detectLine[])(void);

#endif
