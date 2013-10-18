#include "Ports.h"

/*Setup the struct Ports below*/
struct IOBitSet PortB0 = {     //RxLED
    .ddr        = &DDRB,
    .port       = &PORTB,
    .pin        = &PINB,
    .IOoffSet   = PORTB0,
    .PortUsage  = IOPortUsage_t_LED_LowOn,
    .lineNum    = 2,
};
struct IOBitSet PortB1 = {     //SCK
    .ddr        = &DDRB,
    .port       = &PORTB,
    .pin        = &PINB,
    .IOoffSet   = PORTB1,
    .PortUsage  = IOPortUsage_t_detect,
    .lineNum    = 0,
};
struct IOBitSet PortB2 = {     //MOSI
    .ddr        = &DDRB,
    .port       = &PORTB,
    .pin        = &PINB,
    .IOoffSet   = PORTB2,
    .PortUsage  = IOPortUsage_t_detect,
    .lineNum    = 1,
};
struct IOBitSet PortB3 = {     //MISO
    .ddr        = &DDRB,
    .port       = &PORTB,
    .pin        = &PINB,
    .IOoffSet   = PORTB3,
    .PortUsage  = IOPortUsage_t_detect,
    .lineNum    = 2,
};
struct IOBitSet PortB4 = {     //8
    .ddr        = &DDRB,
    .port       = &PORTB,
    .pin        = &PINB,
    .IOoffSet   = PORTB4,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 14,
};
struct IOBitSet PortB5 = {     //9
    .ddr        = &DDRB,
    .port       = &PORTB,
    .pin        = &PINB,
    .IOoffSet   = PORTB5,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 15,
};
struct IOBitSet PortB6 = {     //10
    .ddr        = &DDRB,
    .port       = &PORTB,
    .pin        = &PINB,
    .IOoffSet   = PORTB6,
    .PortUsage  = IOPortUsage_t_detect,
    .lineNum    = 3,
};
struct IOBitSet PortB7 = {     //11
    .ddr        = &DDRB,
    .port       = &PORTB,
    .pin        = &PINB,
    .IOoffSet   = PORTB7,
    .PortUsage  = IOPortUsage_t_detect,
    .lineNum    = 4,
};

struct IOBitSet PortC6 = {     //5
    .ddr        = &DDRC,
    .port       = &PORTC,
    .pin        = &PINC,
    .IOoffSet   = PORTC6,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 11,
};
struct IOBitSet PortC7 = {     //IO13, LED
    .ddr        = &DDRC,
    .port       = &PORTC,
    .pin        = &PINC,
    .IOoffSet   = PORTC7,
    .PortUsage  = IOPortUsage_t_LED_HighOn,
    .lineNum    = 0,
};

struct IOBitSet PortD0 = {     //3
    .ddr        = &DDRD,
    .port       = &PORTD,
    .pin        = &PIND,
    .IOoffSet   = PORTD0,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 9,
};
struct IOBitSet PortD1 = {     //2
    .ddr        = &DDRD,
    .port       = &PORTD,
    .pin        = &PIND,
    .IOoffSet   = PORTD1,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 8,
};
struct IOBitSet PortD2 = {     //0
    .ddr        = &DDRD,
    .port       = &PORTD,
    .pin        = &PIND,
    .IOoffSet   = PORTD2,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 6,
};
struct IOBitSet PortD3 = {     //1
    .ddr        = &DDRD,
    .port       = &PORTD,
    .pin        = &PIND,
    .IOoffSet   = PORTD3,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 7,
};
struct IOBitSet PortD4 = {     //4
    .ddr        = &DDRD,
    .port       = &PORTD,
    .pin        = &PIND,
    .IOoffSet   = PORTD4,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 10,
};
struct IOBitSet PortD5 = {     //TXLED
    .ddr        = &DDRD,
    .port       = &PORTD,
    .pin        = &PIND,
    .IOoffSet   = PORTD5,
    .PortUsage  = IOPortUsage_t_LED_LowOn,
    .lineNum    = 1,
};
struct IOBitSet PortD6 = {     //12
    .ddr        = &DDRD,
    .port       = &PORTD,
    .pin        = &PIND,
    .IOoffSet   = PORTD6,
    .PortUsage  = IOPortUsage_t_detect,
    .lineNum    = 5,
};
struct IOBitSet PortD7 = {     //6
    .ddr        = &DDRD,
    .port       = &PORTD,
    .pin        = &PIND,
    .IOoffSet   = PORTD7,
    .PortUsage  = IOPortUsage_t_detect,
    .lineNum    = 12,
};

struct IOBitSet PortE2 = {     //HWB
    .ddr        = &DDRE,
    .port       = &PORTE,
    .pin        = &PINE,
    .IOoffSet   = PORTD2,
    .PortUsage  = IOPortUsage_t_noUsed,
    .lineNum    = -1,
};
struct IOBitSet PortE6 = {     //7
    .ddr        = &DDRE,
    .port       = &PORTE,
    .pin        = &PINE,
    .IOoffSet   = PORTE6,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 13,
};

struct IOBitSet PortF0 = {     //A5
    .ddr        = &DDRF,
    .port       = &PORTF,
    .pin        = &PINF,
    .IOoffSet   = PORTF0,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 0,
};
struct IOBitSet PortF1 = {     //A4
    .ddr        = &DDRF,
    .port       = &PORTF,
    .pin        = &PINF,
    .IOoffSet   = PORTF1,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 1,
};
struct IOBitSet PortF4 = {     //A3
    .ddr        = &DDRF,
    .port       = &PORTF,
    .pin        = &PINF,
    .IOoffSet   = PORTF4,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 2,
};
struct IOBitSet PortF5 = {     //A2
    .ddr        = &DDRF,
    .port       = &PORTF,
    .pin        = &PINF,
    .IOoffSet   = PORTF5,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 3,
};
struct IOBitSet PortF6 = {     //A1
    .ddr        = &DDRF,
    .port       = &PORTF,
    .pin        = &PINF,
    .IOoffSet   = PORTF6,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 4,
};
struct IOBitSet PortF7 = {     //A0
    .ddr        = &DDRF,
    .port       = &PORTF,
    .pin        = &PINF,
    .IOoffSet   = PORTF7,
    .PortUsage  = IOPortUsage_t_scan,
    .lineNum    = 5,
};

struct IOBitSet* AllPorts[26] = {
    &PortB0,    &PortB1,    &PortB2,    &PortB3,
    &PortB4,    &PortB5,    &PortB6,    &PortB7,
    &PortC6,    &PortC7,
    &PortD0,    &PortD1,    &PortD2,    &PortD3,
    &PortD4,    &PortD5,    &PortD6,    &PortD7,
    &PortE2,    &PortE6,
    &PortF0,    &PortF1,
    &PortF4,    &PortF5,    &PortF6,    &PortF7,
};
struct IOBitSet* scanPorts[scanLinesNum];
struct IOBitSet* detectPorts[detectLinesNum];
struct IOBitSet* LedPorts[LedLinesNum];

void inline scanLines_Sort(void) {
    for (int i = 0; i < 26; i++) {
        if (AllPorts[i]->PortUsage == IOPortUsage_t_scan)
            scanPorts[AllPorts[i]->lineNum] = AllPorts[i];
    }
}

void inline detectLines_Sort(void) {
    for (int i = 0; i < 26; i++) {
        if (AllPorts[i]->PortUsage == IOPortUsage_t_detect)
            detectPorts[AllPorts[i]->lineNum] = AllPorts[i];
    }
}

void inline LedLines_Sort(void) {
    for (int i = 0; i < 26; i++) {
        if ((AllPorts[i]->PortUsage == IOPortUsage_t_LED_LowOn) || \
                (AllPorts[i]->PortUsage == IOPortUsage_t_LED_HighOn) )
            LedPorts[AllPorts[i]->lineNum] = AllPorts[i];
    }
}

/*Scan Ports as below.*/
/* Scan Port Initialization */
void scanLines_Init(void) {
    scanLines_Sort();
    for (int i = 0; i < scanLinesNum; i++) {
        scanPort_Init(scanPorts[i]);
    }
}

void inline scanLinesOff(void) {
    for (int i = 0; i < scanLinesNum; i++) {
        scanPort_Off(scanPorts[i]);
    }
}

void scanLine0(void)  { scanLinesOff(); scanPort_On( scanPorts[0]  ); }
void scanLine1(void)  { scanLinesOff(); scanPort_On( scanPorts[1]  ); }
void scanLine2(void)  { scanLinesOff(); scanPort_On( scanPorts[2]  ); }
void scanLine3(void)  { scanLinesOff(); scanPort_On( scanPorts[3]  ); }
void scanLine4(void)  { scanLinesOff(); scanPort_On( scanPorts[4]  ); }
void scanLine5(void)  { scanLinesOff(); scanPort_On( scanPorts[5]  ); }
void scanLine6(void)  { scanLinesOff(); scanPort_On( scanPorts[6]  ); }
void scanLine7(void)  { scanLinesOff(); scanPort_On( scanPorts[7]  ); }
void scanLine8(void)  { scanLinesOff(); scanPort_On( scanPorts[8]  ); }
void scanLine9(void)  { scanLinesOff(); scanPort_On( scanPorts[9]  ); }
void scanLine10(void) { scanLinesOff(); scanPort_On( scanPorts[10] ); }
void scanLine11(void) { scanLinesOff(); scanPort_On( scanPorts[11] ); }
void scanLine12(void) { scanLinesOff(); scanPort_On( scanPorts[12] ); }
void scanLine13(void) { scanLinesOff(); scanPort_On( scanPorts[13] ); }
void scanLine14(void) { scanLinesOff(); scanPort_On( scanPorts[14] ); }
void scanLine15(void) { scanLinesOff(); scanPort_On( scanPorts[15] ); }

/* Function Pointer Array define */
void (* scanLine[])(void) = {
    scanLine0,  scanLine1,  scanLine2,  scanLine3,
    scanLine4,  scanLine5,  scanLine6,  scanLine7,
    scanLine8,  scanLine9,  scanLine10, scanLine11,
    scanLine12, scanLine13, scanLine14, scanLine15,
};

/*Detect Ports as below.*/
void detectLines_Init(void) {
    detectLines_Sort();
    for (int i = 0; i < detectLinesNum; i++) {
        detectPort_Init(detectPorts[i]);
    }
}

uint8_t detectLine0(void)
    {return (detectPortRet( detectPorts[0] )); }    //SCK
uint8_t detectLine1(void)
    {return (detectPortRet( detectPorts[1] )); }    //MOSI
uint8_t detectLine2(void)
    {return (detectPortRet( detectPorts[2] )); }    //MISO
uint8_t detectLine3(void)
    {return (detectPortRet( detectPorts[3] )); }    //10
uint8_t detectLine4(void)
    {return (detectPortRet( detectPorts[4] )); }    //11
uint8_t detectLine5(void)
    {return (detectPortRet( detectPorts[5] )); }    //12

/* Function Pointer Array define */
uint8_t (* detectLine[])(void) = {
    detectLine0, detectLine1, detectLine2,
    detectLine3, detectLine4, detectLine5,
};
/*Detect Ports as above.-----END----.*/


/* LED Ports as below. */
void LedLines_Init(void) {
    LedLines_Sort();
    for (int i = 0; i < LedLinesNum; i++) {
        __LED_Init__(LedPorts[i]);
    }
}

void LedLine0(enum LEDctrl_t LEDctrl)
    { __LedPort_Ctrl__ (LedPorts[0], LEDctrl ); }
void LedLine1(enum LEDctrl_t LEDctrl)
    { __LedPort_Ctrl__ (LedPorts[1], LEDctrl ); }
void LedLine2(enum LEDctrl_t LEDctrl)
    { __LedPort_Ctrl__ (LedPorts[2], LEDctrl ); }

void (* LedLine[])(enum LEDctrl_t LEDctrl) = {
    LedLine0,   LedLine1,   LedLine2,
};
/* LED Ports as above.-----END----. */
