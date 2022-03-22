#include "project.h"

CY_ISR(Pin_SW2_Handler)
{
    red_pin_Write(~red_pin_Read());
    CyDelay(200);
    red_pin_Write(~red_pin_Read());
    Pin_SW2_ClearInterrupt();
}
int main(void)
{
    CyGlobalIntEnable; 

    Pin_SW2_Int_StartEx(Pin_SW2_Handler);
    
    for(;;)
    {
   
    }
}

/* [] END OF FILE */
