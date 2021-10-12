/************************************
 * #pragma directives...
************************************/
#pragma config FEXTOSC = HS
#pragma config RSTOSC = EXTOSC_4PLL 
#pragma config WDTE = OFF        

/************************************
 * #include directives...
 ************************************/
#include <xc.h>

/************************************
 * #define directives...
 ************************************/
#define _XTAL_FREQ 64000000 

/************************************
/ main function
 * ...
************************************/
void main(void) {    
    // setup pin for output (connected to LED) RD7:LED1
    LATDbits.LATD7=0;   //set initial output state for LED1
    TRISDbits.TRISD7=0; //set TRIS value for pin 1 (output) TRIS 0 means output
    LATHbits.LATH3=0;   //set initial output state for LED2
    TRISHbits.TRISH3=0; //set TRIS value for pin 2 (output)
    
    // setup pin for input (connected to button) RF2: button1
    TRISFbits.TRISF2=1; //set TRIS value for pin 1 (input) TRIS 1 means input
    ANSELFbits.ANSELF2=0; //turn off analogue input on pin 1
    TRISFbits.TRISF3=1; //set TRIS value for pin 2 (input)
    ANSELFbits.ANSELF3=0; //turn off analogue input on pin 2
    
    while (1) { //infinite while loop - repeat forever
        
        //empty while loop (wait for button press)
        while (PORTFbits.RF2 && PORTFbits.RF3); //both not pressed
        
        if (!PORTFbits.RF2)  LATDbits.LATD7 = !LATDbits.LATD7; //toggle LED 1
        
        if (!PORTFbits.RF3)  LATHbits.LATH3 = !LATHbits.LATH3; //toggle LED 2
        
        __delay_ms(200); // call built in delay function 
    }
}