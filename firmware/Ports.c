#include "Ports.h"

/*Scan Ports as below.*/
/* Scan Port Initialization */
void scanLines_Init(void) {
    scanPort_Init( &DDRF, &PORTF, PORTF0);      //A0
    scanPort_Init( &DDRF, &PORTF, PORTF1);
    scanPort_Init( &DDRF, &PORTF, PORTF4);
    scanPort_Init( &DDRF, &PORTF, PORTF5);
    scanPort_Init( &DDRF, &PORTF, PORTF6);
    scanPort_Init( &DDRF, &PORTF, PORTF7);      //A6
    scanPort_Init( &DDRD, &PORTD, PORTD2);      //0
    scanPort_Init( &DDRD, &PORTD, PORTD3);
    scanPort_Init( &DDRD, &PORTD, PORTD1);
    scanPort_Init( &DDRD, &PORTD, PORTD0);
    scanPort_Init( &DDRD, &PORTD, PORTD4);      //4
    scanPort_Init( &DDRC, &PORTC, PORTC6);      //5
    scanPort_Init( &DDRD, &PORTD, PORTD7);      //6
    scanPort_Init( &DDRE, &PORTE, PORTE6);      //7
    scanPort_Init( &DDRB, &PORTB, PORTB4);      //8
    scanPort_Init( &DDRB, &PORTB, PORTB5);      //9
}

void inline scanLinesOff(void) {
    scanPort_Off( &PORTF, PORTF0);      //A0
    scanPort_Off( &PORTF, PORTF1);
    scanPort_Off( &PORTF, PORTF4);
    scanPort_Off( &PORTF, PORTF5);
    scanPort_Off( &PORTF, PORTF6);
    scanPort_Off( &PORTF, PORTF7);      //A6
    scanPort_Off( &PORTD, PORTD2);      //0
    scanPort_Off( &PORTD, PORTD3);
    scanPort_Off( &PORTD, PORTD1);
    scanPort_Off( &PORTD, PORTD0);
    scanPort_Off( &PORTD, PORTD4);      //4
    scanPort_Off( &PORTC, PORTC6);      //5
    scanPort_Off( &PORTD, PORTD7);      //6
    scanPort_Off( &PORTE, PORTE6);      //7
    scanPort_Off( &PORTB, PORTB4);      //8
    scanPort_Off( &PORTB, PORTB5);      //9
}
void scanLine0(void) { scanLinesOff(); scanPort_On( &PORTF, PORTF0); }    //A0
void scanLine1(void) { scanLinesOff(); scanPort_On( &PORTF, PORTF1); }
void scanLine2(void) { scanLinesOff(); scanPort_On( &PORTF, PORTF4); }
void scanLine3(void) { scanLinesOff(); scanPort_On( &PORTF, PORTF5); }
void scanLine4(void) { scanLinesOff(); scanPort_On( &PORTF, PORTF6); }
void scanLine5(void) { scanLinesOff(); scanPort_On( &PORTF, PORTF7); }    //A6
void scanLine6(void) { scanLinesOff(); scanPort_On( &PORTD, PORTD2); }    //0
void scanLine7(void) { scanLinesOff(); scanPort_On( &PORTD, PORTD3); }
void scanLine8(void) { scanLinesOff(); scanPort_On( &PORTD, PORTD1); }
void scanLine9(void) { scanLinesOff(); scanPort_On( &PORTD, PORTD0); }
void scanLine10(void) { scanLinesOff(); scanPort_On( &PORTD, PORTD4); }    //4
void scanLine11(void) { scanLinesOff(); scanPort_On( &PORTC, PORTC6); }    //5
void scanLine12(void) { scanLinesOff(); scanPort_On( &PORTD, PORTD7); }    //6
void scanLine13(void) { scanLinesOff(); scanPort_On( &PORTE, PORTE6); }    //7
void scanLine14(void) { scanLinesOff(); scanPort_On( &PORTB, PORTB4); }    //8
void scanLine15(void) { scanLinesOff(); scanPort_On( &PORTB, PORTB5); }    //9
     /*and so on.*/

/* Function Pointer Array define */
void (* scanLine[])(void) = {
    scanLine0,  scanLine1,  scanLine2,  scanLine3,
    scanLine4,  scanLine5,  scanLine6,  scanLine7,
    scanLine8,  scanLine9,  scanLine10, scanLine11,
    scanLine12, scanLine13, scanLine14, scanLine15,
};
/*Scan Ports as above.-----END----.*/


/*Detect Ports as below.*/
void detectLines_Init(void) {
    detectPort_Init( &DDRB, &PORTB, PORTB1);    //SCK
    detectPort_Init( &DDRB, &PORTB, PORTB2);    //MOSI
    detectPort_Init( &DDRB, &PORTB, PORTB3);    //MISO
    detectPort_Init( &DDRB, &PORTB, PORTB6);    //10
    detectPort_Init( &DDRB, &PORTB, PORTB7);    //11
    detectPort_Init( &DDRD, &PORTD, PORTD6);    //12
}
uint8_t detectLine0(void)
    {return (detectPort( &PINB, PINB1)); }    //SCK
uint8_t detectLine1(void)
    {return (detectPort( &PINB, PINB2)); }    //MOSI
uint8_t detectLine2(void)
    {return (detectPort( &PINB, PINB3)); }    //MISO
uint8_t detectLine3(void)
    {return (detectPort( &PINB, PINB6)); }    //10
uint8_t detectLine4(void)
    {return (detectPort( &PINB, PINB7)); }    //11
uint8_t detectLine5(void)
    {return (detectPort( &PIND, PIND6)); }    //12
/* an so on. */

/* Function Pointer Array define */
uint8_t (* detectLine[])(void) = {
    detectLine0, detectLine1, detectLine2,
    detectLine3, detectLine4, detectLine5,
};
/*Detect Ports as above.-----END----.*/
