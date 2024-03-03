/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  This is source code for the PSoC 4 BLE dynamic broadcaster example project.
*
* Note:
*
* Owner:
*  KRIS@CYPRESS.COM
*
* Related Document:
*
* Hardware Dependency:
*  1. PSoC 4 BLE device
*  2. CY8CKIT-042 BLE Pioneer Kit
*
* Code Tested With:
*  1. PSoC Creator 3.1 SP1
*  2. ARM GCC 4.8.4
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "BLE_functions.h"

/***************************************
*        API Constants
***************************************/
//#define LED_ON                                      (0u)
//#define LED_OFF                                     (1u)

/***************************************
* Extern and constants required for 
* dynamic ADV payload update
***************************************/
#define ENABLE_DYNAMIC_ADV                          (1u)

#if ENABLE_DYNAMIC_ADV
    
extern CYBLE_GAPP_DISC_MODE_INFO_T cyBle_discoveryModeInfo;
extern uint8 acc_flag;
    
/* ADV payload dta structure */    
#define advPayload                                  (cyBle_discoveryModeInfo.advData->advData) 
    
#define MANUFACTURER_SPECIFIC_DYNAMIC_DATA_INDEX    (14u) /* index of the dynamic data in the ADV packet */

#endif

/***************************************
*        Function Prototypes
***************************************/
void InitializeSystem(void);
void EnterLowPowerMode(void);
void DynamicADVPayloadUpdate(void);
void StackEventHandler (uint32 eventCode,void *eventParam);


 /*
 *  \Brief : Main function
 *  \Return : None
 *  \param : None
 */
/*int main()
{
    Setup the system initially */
    //InitializeSystem();
    
    /* Three simple APIs that showcases dynamic ADV payload update */ 
    //for(;;)
    //{
        /* Single API call to service all the BLE stack events. Must be
         * called at least once in a BLE connection interval */
        //CyBle_ProcessEvents();

        /* Configure the system in lowest possible power modes during and between BLE ADV events */
        //EnterLowPowerMode();
        
        /* 
           LOW_POWER_NOTE - If you like to measure the current consumed by this project, following changes are to be 
           done to achieve lowest possible current number:
           1. Set the "Debug Select" option under Dynamic Broadcaster.cydwr -> System -> Programming/Debugging to GPIO 
           2. Comment out Advertising_LED_Write(LED_ON); line of code in StackEventHandler routine
        */

//#if ENABLE_DYNAMIC_ADV        
        //DynamicADVPayloadUpdate();
//#endif

    //}
//}

 /*
 *  \Brief : This routine initializes all the components and firmware state
 *  \Return : None
 *  \param : None
 */
void InitializeSystem(void)
{
    CYBLE_API_RESULT_T apiResult;

    CyGlobalIntEnable;

    apiResult = CyBle_Start(StackEventHandler); /* Init the BLE stack and register an applicaiton callback */

    if(apiResult != CYBLE_ERROR_OK)
    {
        /* BLE stack initialization failed, check your configuration */
        CYASSERT(0);
    }
    
    /* Set XTAL divider to 3MHz mode */
    CySysClkWriteEcoDiv(CY_SYS_CLK_ECO_DIV8); 
    
    /* ILO is no longer required, shut it down */
    CySysClkIloStop();
}

 /*
 *  \Brief : This configures the BLESS and system in low power mode whenever possible
 *  \Return : None
 *  \param : None
 */
void EnterLowPowerMode(void)
{
    CYBLE_BLESS_STATE_T blessState;
    uint8 intrStatus;
    
    /* Configure BLESS in Deep-Sleep mode */
    CyBle_EnterLPM(CYBLE_BLESS_DEEPSLEEP);
    
    /* Prevent interrupts while entering system low power modes */
    intrStatus = CyEnterCriticalSection();
    
    /* Get the current state of BLESS block */
    blessState = CyBle_GetBleSsState();
    
    /* If BLESS is in Deep-Sleep mode or the XTAL oscillator is turning on, 
     * then PSoC 4 BLE can enter Deep-Sleep mode (1.3uA current consumption) */
    if(blessState == CYBLE_BLESS_STATE_ECO_ON || 
        blessState == CYBLE_BLESS_STATE_DEEPSLEEP)
    {
        CySysPmDeepSleep();
    }
    else if(blessState != CYBLE_BLESS_STATE_EVENT_CLOSE)
    {
        /* If BLESS is active, then configure PSoC 4 BLE system in 
         * Sleep mode (~1.6mA current consumption) */
        CySysClkWriteHfclkDirect(CY_SYS_CLK_HFCLK_ECO);
        CySysClkImoStop();
        CySysPmSleep();
        CySysClkImoStart();
        CySysClkWriteHfclkDirect(CY_SYS_CLK_HFCLK_IMO);
    }
    else
    {
        /* Keep trying to enter either Sleep or Deep-Sleep mode */    
    }
    
    CyExitCriticalSection(intrStatus);
}
   
 /*
 *  \Brief : This routine dynamically updates the BLE advertisement packet
 *  \Return : None
 *  \param : None
 */
void DynamicADVPayloadUpdate(void)
{
    if(CyBle_GetBleSsState() == CYBLE_BLESS_STATE_EVENT_CLOSE)
    {

        /* Once the system enters Sleep/Deepsleep mode during advertisement, the source of wake-up is the next  
         * advertisement interval which has a wakeup interval of 1 advertisement (ADV) interval (1000ms). 
         */
        
        
        /* Dynamic payload will be continuously updated */
        advPayload[MANUFACTURER_SPECIFIC_DYNAMIC_DATA_INDEX] = acc_flag;

        
        CyBle_GapUpdateAdvData(cyBle_discoveryModeInfo.advData, cyBle_discoveryModeInfo.scanRspData);
        
    }
}

 /*
 *  \Brief : This is an event callback function to receive events from the BLE Component
 *  \Return : None
 *  \param eventCode : Event from the CYBLE component
 *  \param eventParam: A structure instance for corresponding event type. The
 *                     list of event structure is described in the component
 *                     datasheet
 */ 
void StackEventHandler(uint32 event, void *eventParam)
{
    switch(event)
    {
        /* Mandatory events to be handled by Find Me Target design */
        case CYBLE_EVT_STACK_ON:
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
            /* Start BLE advertisement for 30 seconds and update link
             * status on LEDs */
            CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            //Advertising_LED_Write(LED_ON);
          break;

        case CYBLE_EVT_GAPP_ADVERTISEMENT_START_STOP:
            if(CyBle_GetState() == CYBLE_STATE_DISCONNECTED)
            {
                /* Advertisement event timed out, go to low power
                 * mode (Hibernate mode) and wait for an external
                 * user event to wake up the device again */
                //Advertising_LED_Write(LED_OFF);
                //Hibernate_LED_Write(LED_ON);
                //PIN1_ClearInterrupt();
                //PIN1_ISR_ClearPending();
                //PIN1_ISR_Start();
                CySysPmHibernate();
            }
            break;

        default:
        break;
    }
}


/* [] END OF FILE */
