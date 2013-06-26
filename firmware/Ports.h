//#include "Keyboard.h"
#include <inttypes.h>
#include <avr/io.h>

#ifndef _PORTS_H_
#define _PORTS_H_

typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    volatile uint8_t *pin;
    uint8_t IOoffSet;
    enum scanDetect_t {
        scanDetect_t_noUsed,
        scanDetect_t_scan,
        scanDetect_t_detect,
    } scanDetectPort;
    int8_t lineNum;
} IOBitSet;

//#define Ports_Init_Func
     //Initialize the scan & detect ports for keyboard.  
    static inline void scanPort_Init(IOBitSet *IOPortPtr)
    {
        *IOPortPtr->ddr |= (1 << IOPortPtr->IOoffSet);
        *IOPortPtr->port &= ~(1 << IOPortPtr->IOoffSet);
    }
    static inline void detectPort_Init(IOBitSet *IOPortPtr)
    {
        *IOPortPtr->ddr &= ~(1 << IOPortPtr->IOoffSet);
        *IOPortPtr->port |= (1 << IOPortPtr->IOoffSet);
    }

    /* Let the scan IO port in low viotage, aka, 1. */
    inline void scanPort_On(IOBitSet *IOPortPtr)
    {   *IOPortPtr->port |= (1 << IOPortPtr->IOoffSet);    }
     /* Let the scan IO port in high viotage, aka, 0. */
    inline void scanPort_Off(IOBitSet *IOPortPtr)
    {   *IOPortPtr->port &= ~(1 << IOPortPtr->IOoffSet);     }

    /* Return the detect Port Bit   */
    /*    Low viotage 0 means true  */
    /*   High viotage 1 means false */
    uint8_t inline detectPortRet (IOBitSet *IOPortPtr)
    {   return !((*IOPortPtr->pin >> IOPortPtr->IOoffSet) & 1);     }

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
