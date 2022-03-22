#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    PWM_1_Start();
    
    for(;;)
    {
        PWM_1_WriteCompare(100);
        CyDelay(50);
        PWM_1_WriteCompare(5000);
        CyDelay(50);
    }
}

/* [] END OF FILE */
