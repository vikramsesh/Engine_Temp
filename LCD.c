#include "PICconfig.h"
#include "LCDterminal.h"
//#include "TouchScreen.h"
#include "GOL.h"
#include "uMedia.h"
#include <stdio.h>          // sprintf

int main( void )
{
    
    char s[]="Engine";
    char t[]=" Temperature";
    char c[]="Rpm";
    char a[]="Fuel Tank Pressure";
    char g[]="";

    // 1. init the graphics
    LCDInit();
    DisplayBacklightOn();

    LCDClear();
    
    while(1)
    {  int x,y,q,temp;
    float temp2,temp3,v;

        x=GetMaxX()/4;
        y=GetMaxY()/4;
        
        SetColor(ORANGE);
        Bevel(x-70,y-45,x+(GetMaxX()/4)+150,y+(GetMaxY()/4-50),5);
        LCDString(8,-4,s);
        LCDString(6,-3,t);
        temp = temp_calc();
        v = (temp*3.3)/1024;
        temp2 = (v-0.5)/0.01;
        temp3 = (temp2*9/5)+32;
        LCDdisp(-5,-4);
        printf("%0.02f C",temp2);
        LCDdisp(-5,-3);
        printf("%0.02f F",temp3);
        
        SetColor(BLUE);
        Bevel(x-70,y+25,x+(GetMaxX()/4)+150,y+(GetMaxY()/4+30),5);
        LCDCenterString(1,c);
      
        SetColor(BRIGHTRED);
        Bevel(x-70,y+105,x+(GetMaxX()/4)+150,y+(GetMaxY()/4+110),5);
        LCDCenterString(5,a);
}  
    
    
} 
// main




