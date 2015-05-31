/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#define _XTAL_FREQ 8000000L

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

void main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();
    
    /* everything is an output */
    TRISIO = 0;
    
    /* turn off all pins */
    GPIO = 0x00000000;

    while(1)
    {
        __delay_ms(100);
    
        /* turn on GPIO pin 2 */
        GPIO = 0b00000100;
        
        __delay_ms(100);
    
        /* turn off GPIO pin 2 */
        GPIO = 0b00000000;
    }

}

