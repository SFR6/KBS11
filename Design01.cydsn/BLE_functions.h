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

#ifndef __BLE_FUNCTIONS_H__
#define __BLE_FUNCTIONS_H__

#include "project.h"


void StackEventHandler (uint32 eventCode,void *eventParam);
 /*
 *  \Brief : This is an event callback function to receive events from the BLE Component
 *  \Return : None
 *  \param eventCode : Event from the CYBLE component
 *  \param eventParam: A structure instance for corresponding event type. The
 *                     list of event structure is described in the component
 *                     datasheet
 */    
    
    
    
void InitializeSystem(void);
 /*
 *  \Brief : This routine initializes all the components and firmware state
 *  \Return : None
 *  \param : None
 */



void EnterLowPowerMode(void);
 /*
 *  \Brief : This configures the BLESS and system in low power mode whenever possible
 *  \Return : None
 *  \param : None
 */



void DynamicADVPayloadUpdate(void); 
 /*
 *  \Brief : This routine dynamically updates the BLE advertisement packet
 *  \Return : None
 *  \param : None
 */


#endif
/* [] END OF FILE */
