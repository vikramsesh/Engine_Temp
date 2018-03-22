/*
** Temp.c
** Converting the analog signal from a TC1047 Temperature Sensor
*/

#include <p24EP512GU810.h>
#include<embedded.h>
#include <embeddedShield.h>

#define TEMP_CH   9         // ch 9 = TC1047 Temperature sensor 
#define TEMPMASK  0xFFFF    // AN9 as analog input


int temp_calc()
{
    int temp,ref, j;
    
    initLEDs();
    Init();
    // 1. initializations
    initADC( TEMPMASK);  // initialize ADC Explorer16 inputs
    
    // 2. get the central bar reference
    temp = 0;
       
    for ( j= 16; j >0; j--)
         temp += readADC( TEMP_CH);  // read the temperature
    ref = temp >> 4;

    // 3.0 main loop
    
    
        // 3.1 get a new measurement
        temp = 0;
        for ( j= 16; j >0; j--)
        {
            temp += readADC( TEMP_CH);  // read the temperature
        }
        //temp=temp/16;
        temp >>= 4;                     // averaged over 16 values
        Delay_ms(200);               // 1/2 second
        
        return temp;

} // main
