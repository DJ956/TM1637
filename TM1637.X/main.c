#include "main.h"
#include "i2c_pp.h"
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    IO_RA2_SetHigh();
    
    uint8_t data[] = {0xff, 0xff, 0xff, 0xff};
    uint8_t blank[] = {0x00, 0x00, 0x00, 0x00};
    
    data[0] = encode_digit(1);
    data[1] = encode_digit(2);
    data[2] = encode_digit(3);
    data[3] = encode_digit(4);
    
    
    set_brigthness(0x0f, 1);
    //set_segments(data, 4, 1);
    set_segments(data, 4, 0);
    bit_delay();
       
    while (1)
    {        
    }
}



/**
 End of File
*/