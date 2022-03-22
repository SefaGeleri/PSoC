/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if(Pin_SW2_Read() == 0)
        {
            int i = 1;
        
            while(i)
            {
                if( i == 1)
                {
                    if(Pin_SW2_Read() == 0)
                    {
                        red_pin_Write(~red_pin_Read());
                        CyDelay(200);
                        red_pin_Write(~red_pin_Read());
                        i++;
                    }
                }
                
                else if(i == 2)
                {
                    if(Pin_SW2_Read() == 0)
                    {
                        green_pin_Write(~green_pin_Read());
                        CyDelay(200);
                        green_pin_Write(~green_pin_Read());
                        i++;                        
                    }
                }
                
                else if(i == 3)
                {
                    if(Pin_SW2_Read() == 0)
                    {
                        blue_pin_Write(~blue_pin_Read());
                        CyDelay(200);
                        blue_pin_Write(~blue_pin_Read());
                        i = 0;
                    }
                }
            }
        }
    }
}

/* [] END OF FILE */
