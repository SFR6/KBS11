
#include "project.h"
#include "bma2x2.h"
#include "bma2x2_support.h"
#include "BLE_functions.h"


/**
Defines for states of the LED 
And the accident
*/
#define LED_ON                                (0u)
#define LED_OFF                               (1u)
#define NO_ACC_STATE                          (0u)
#define ACC_STATE                             (1u)

/*Global variable used to know if an accident took place or not*/
volatile uint8 acc_flag = NO_ACC_STATE; 

/*Interrupt function for PIN1 which is linked to the accelerometer*/
CY_ISR (PIN1_Handler)
{
    /*Setting the drive mode for the LED1 to Strong Drive in order to wake it up from High Impedance*/
    LED1_SetDriveMode(LED1_DM_STRONG);
    
    /*Turning the LED on and changing the flag to 1 because an accident occurred*/
    LED1_Write(LED_ON);
    acc_flag = ACC_STATE;
    
    /*Making a soft reset to the accelerometer after the accident occurred*/
    u8 soft_reset = 0xB6;
    bma2x2_write_reg(0x14,&soft_reset,1);
    
    /*Clearing the dedicated interrupt on PIN1 which is linked to the accelerometer*/
    PIN1_ClearInterrupt();
}

int main (void)
{
    /*Initializing the BLE system, starting the I2C and PIN1 dedicated interrupt*/
    InitializeSystem();
    I2C_Start();
    PIN1_ISR_StartEx(PIN1_Handler);
    
    /*Declaring the bma2x2_t struct which will be used throughout the program*/
    struct bma2x2_t bma2x2;
    
    /**
    Declaring and initializing a variable which will be used to demonstrate
    How the accelerometer reads a certain register and what is the output
    */
    u8 reg_data = 0;
    
    /*Using the com_rslt variable to test the state of the accelerometer and see if everything is working properly*/
    BMA2x2_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    com_rslt = bma2x2_shock_setup(&bma2x2);
    
    /*If an error occurrs in the initial setup the LED will start to flash every quarter of a second*/
    if (com_rslt!=0)
    {
        for(;;)
        {
            LED1_Write(!LED1_Read());
            CyDelay(250);
        }
    }
    
    /*Function used to demonstrate how the accelerometer reads a certain register and what is the output*/
    bma2x2_read_reg(0x00,&reg_data,1);
    
    /*Stoping the I2C component after we don't need it anymore*/
    //I2C_Stop();
    
    for(;;)
    {
        /*If no accident has occurred yet the LED will flash rapidly while in Strong Drive mode*/
        if (!acc_flag)
        {
            LED1_SetDriveMode(LED1_DM_STRONG);
            LED1_Write(!LED1_Read());
        }
        
        /*The BLE will process the events and Payload will be updated depending on the state of the accident*/
        CyBle_ProcessEvents();
        DynamicADVPayloadUpdate();
        
        /*For Low-Power purposes, if no accident has occurred yet, the LED used will enter in High Impedance mode*/
        if (!acc_flag)
        {
            LED1_SetDriveMode(LED1_DM_ALG_HIZ);
        }
        
        /*The BLE component will also enter Low-Power mode the conserve energy as much as possible*/
        EnterLowPowerMode();
    }
    
}

