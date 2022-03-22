#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_Start();
    UART_UartPutString("Hello World");

    for(;;)
    {
        
    }
}

/* [] END OF FILE */
