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
    
    clear();
    
    data[0] = encode_digit(1);
    data[1] = encode_digit(9);
    data[2] = encode_digit(8);
    data[3] = encode_digit(4);
    
    
    set_brigthness(0x0f, 1);
    set_segments(data, 4, 0);
    
    uint8_t k = 0;
    while (1)
    {       
        for(uint8_t i = 0; i < 4; i++){
            data[i] = encode_digit(i + k);
        }
        
        set_segments(data, 4, 0);
        __delay_ms(1000);
        k++;
    }
}



/**
 End of File
*/