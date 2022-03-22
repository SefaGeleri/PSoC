#include "project.h"
#include <stdio.h>

int main(void)
{    
    uint16 sliderval;
    uint16 oldsliderval = 0xFFFF;
    char msg[10];
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();
    CapSense_Start();
    CapSense_InitializeAllBaselines();
    CapSense_ScanEnabledWidgets();

    for(;;)
    {
        if (!CapSense_IsBusy())
        {
            sliderval = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0__LS) ;
            if(sliderval != 0xFFFF && sliderval != oldsliderval)
            {
                sprintf(msg, "%3d\r\n", sliderval);
                UART_UartPutString(msg);
                oldsliderval = sliderval;
            }
            CapSense_UpdateEnabledBaselines();
            CapSense_ScanEnabledWidgets();
        }
    }
}

/* [] END OF FILE */
