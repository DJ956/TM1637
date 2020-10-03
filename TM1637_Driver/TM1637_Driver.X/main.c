/*
 * Picprojects 2019-03-26
 * http://picprojects.org/
 * Controlling a TM1637 with a PIC16F18325
 * 
 * TM6137 test program
 * 
 * PIC16F18325 connections
 *            ____   
 *      Vdd 1|o   |14 Vss
 *          2|    |13 RAO/ICSPDAT
 *          3|    |12 RA1/ICSPCLK
 * MCLR/RA3 4|    |11
 *          5|    |10 RC0 CLK -> TM6137 LED Module
 *          6|    |9  RC1 DIO -> TM6137 LED Module
 *          7|____|8
 * 
 *  Project created with MPLAB X 5.15
 *  Compiled with XC8 2.05 - free version 
 * 
 *  Testing was done with a RobotDyn 4-Digit LED Display module
 *  4-Digit LED Display Tube, 7-segments, TM1637, 50x19mm 
 *  See https://robotdyn.com/
 *  Note:  You must remove the two 10nF capacitors (C3/C4) connecting the CLK 
 *  and DIO signals to ground on the LED module.   If you do not remove them
 *  the display will remain blank.
 */

#include "main.h"
#include "device_config.h"
#include "i2c_pp.h"

/* The TM6137 uses an I2C 'like' signalling method with two caveats:
 *  1. It does not use an I2C address so you can't have any other device on the bus.
 *  2. I2C sends data MSB first, the TM6137 expects data LSB first.
 *     Since this code uses the hardware MSSP module in the PIC, the data to be sent
 *     must be reversed before loading into the PICs MSSP buffer register. 
*/

#define WriteDispAddrAuto 0x02 //0100 0000
#define WriteDispAddrFix  0x22 //0100 0100
#define AddressZero       0x03 //1100 0000

// See TM1637 datasheet page 5
// Display control table        Data Byte   Reversed        
#define DisplayOn1        0x11 //10001000   00010001
#define DisplayOn2        0x91 //10001001   10010001
#define DisplayOn4        0x51 //10001010   01010001
#define DisplayOn10       0xD1 //10001011   11010001
#define DisplayOn11       0x31 //10001100   00110001
#define DisplayOn12       0xB1 //10001101   10110001
#define DisplayOn13       0x71 //10001110   01110001
#define DisplayOn14       0xF1 //10001111   11110001
#define DisplayOff        0x01 //10000000   00000001

// Segment data for digits 0 thru 9
uint8_t segdata[] = { 0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6 };

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    i2c1_init();
    
    struct {
        uint8_t secsUnit;
        uint8_t secsTen;
        uint8_t minsUnit;
        uint8_t minsTen;
    } timer;
    
    timer.minsUnit = 0;
    timer.minsTen  = 0;   
    timer.secsUnit = 0;
    timer.secsTen  = 0;
    
    // TM6137 datasheet refers to the common anode connection of
    // each 7-segment display digit as GRIDn 
    // 4-digit display viewed from front[grid1 grid2 grid3 grid4]
    uint8_t grid1;
    uint8_t grid2;
    uint8_t grid3;
    uint8_t grid4;
    
    while (1)
    {
        
        grid4 = segdata[timer.secsUnit];
        grid3 = segdata[timer.secsTen];
        grid2 = segdata[timer.minsUnit];
        // Centre ':' is segment8 (DP) of grid2. Since we need to reverse the
        // data we send, inclusive-or bit 1 with segment data to turn it on.
        if(timer.secsUnit & 1) grid2 |= 1; // turn on centre ':'
        
        grid1 = segdata[timer.minsTen];
        
        // Send data to TM6137 module using the MSSP1 Synchronous Serial Port 
        // See TM1637 datasheet Page 4
        // Write SRAM data in address auto increment 1 mode.
        i2c1_start();
        i2c1_write(WriteDispAddrAuto);
        i2c1_stop();
        
        i2c1_start();
        i2c1_write(AddressZero);
        i2c1_write(grid1); 
        i2c1_write(grid2); 
        i2c1_write(grid3); 
        i2c1_write(grid4);     
        i2c1_stop();
   
        i2c1_start();
        i2c1_write(DisplayOn4);
        i2c1_stop();
        
        // For something to put on the display, count up like minutes : seconds
        // this is not an accurate timer, it's just to get some activity on the
        // the LED display.
        timer.secsUnit++;
        if(timer.secsUnit == 10)
        {
            timer.secsUnit = 0;
            timer.secsTen++;
        }
        
        if(timer.secsTen == 6)
        {
            timer.secsTen = 0;
            timer.minsUnit++;
        }
        
        if(timer.minsUnit == 10)
        {
            timer.minsUnit = 0;
            timer.minsTen++;
        }
        if(timer.minsTen == 6)
        {
            timer.minsTen = 0;
        }

        __delay_ms(1000);
        
    }
}



/**
 End of File
*/