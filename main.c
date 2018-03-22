#include "PICconfig.h"
#include "LCDterminal.h"
//#include "TouchScreen.h"
#include "GOL.h"
#include "uMedia.h"
#include <stdio.h> 
#include "xc.h"
#include "Graphics.h"
//#include "embedded.h"
//#include "resources.h"

void LCDdisp( int x, int y)
{  // p  integer offset (lines) above or below center
   // s  string
   // differs from MMB similar function by using Terminal mono space font
    
    // get center position
    y = _MAX_Y/2 - 1 + y;
    x = (_MAX_X)/2 - x;

    // set and print
    LCDSetXY( x, y); 
    
} // LCDString

void LCDString( int x, int y, char *s)
{  // p  integer offset (lines) above or below center
   // s  string
   // differs from MMB similar function by using Terminal mono space font
    
    // get center position
    y = _MAX_Y/2 - 1 + y;
    x = (_MAX_X - strlen( s))/2 - x;

    // set and print
    LCDSetXY( x, y); 
    LCDPutString( s);
} // LCDString

int main( void )
{
    
    char s[]="Engine";
    char t[]=" Temperature";
    char c[]="Rpm";
    char a[]="Fuel Tank Pressure";

    // 1. init the graphics
    LCDInit();
    Init();
    DisplayBacklightOn();

    LCDClear();
        
    int x,y;
    float temp,temp2,temp3,v;

    x=GetMaxX()/4;
    y=GetMaxY()/4;
        
    SetColor(ORANGE);
    Bevel(x-70,y-45,x+(GetMaxX()/4)+150,y+(GetMaxY()/4-50),5);
    LCDString(8,-4,s);
    LCDString(6,-3,t);
       
    SetColor(BLUE);
    Bevel(x-70,y+25,x+(GetMaxX()/4)+150,y+(GetMaxY()/4+30),5);
    LCDCenterString(1,c);
      
    SetColor(BRIGHTRED);
    Bevel(x-70,y+105,x+(GetMaxX()/4)+150,y+(GetMaxY()/4+110),5);
    LCDCenterString(5,a);
       
    while (1)
    {
        temp = temp_calc();
        v = (temp*3.3)/1023;
        temp2 = (v-0.5)/0.01;
        temp3 = (temp2*9/5)+32;
        LCDdisp(-5,-4);
        printf("%0.02f C",temp2);
        LCDdisp(-5,-3);
        printf("%0.02f F",temp3);

    }
} // main
