/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC16F1827
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.30 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA2 aliases
#define IO_RA2_TRIS                 TRISAbits.TRISA2
#define IO_RA2_LAT                  LATAbits.LATA2
#define IO_RA2_PORT                 PORTAbits.RA2
#define IO_RA2_ANS                  ANSELAbits.ANSA2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set DIO aliases
#define DIO_TRIS                 TRISBbits.TRISB2
#define DIO_LAT                  LATBbits.LATB2
#define DIO_PORT                 PORTBbits.RB2
#define DIO_WPU                  WPUBbits.WPUB2
#define DIO_ANS                  ANSELBbits.ANSB2
#define DIO_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define DIO_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define DIO_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define DIO_GetValue()           PORTBbits.RB2
#define DIO_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define DIO_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define DIO_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define DIO_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define DIO_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define DIO_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set CLK aliases
#define CLK_TRIS                 TRISBbits.TRISB5
#define CLK_LAT                  LATBbits.LATB5
#define CLK_PORT                 PORTBbits.RB5
#define CLK_WPU                  WPUBbits.WPUB5
#define CLK_ANS                  ANSELBbits.ANSB5
#define CLK_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define CLK_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define CLK_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define CLK_GetValue()           PORTBbits.RB5
#define CLK_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define CLK_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define CLK_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define CLK_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define CLK_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define CLK_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/