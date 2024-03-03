/***************************************************************************//**
* \file .h
* \version 4.0
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in _EZI2C mode.
*  Do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_EZI2C_PVT_BMA2x2_I2C_H)
#define CY_SCB_EZI2C_PVT_BMA2x2_I2C_H

#include "BMA2x2_I2C_EZI2C.h"


/***************************************
*      EZI2C Private Vars
***************************************/

extern volatile uint8 BMA2x2_I2C_curStatus;
extern uint8 BMA2x2_I2C_fsmState;

/* Variables intended to be used with Buffer 1: Primary slave address */
extern volatile uint8 * BMA2x2_I2C_dataBuffer1;
extern uint16 BMA2x2_I2C_bufSizeBuf1;
extern uint16 BMA2x2_I2C_protectBuf1;
extern uint8 BMA2x2_I2C_offsetBuf1;
extern uint16 BMA2x2_I2C_indexBuf1;

#if(BMA2x2_I2C_SECONDARY_ADDRESS_ENABLE_CONST)
    extern uint8 BMA2x2_I2C_addrBuf1;
    extern uint8 BMA2x2_I2C_addrBuf2;

    /* Variables intended to be used with Buffer 2: Primary slave address */
    extern volatile uint8 * BMA2x2_I2C_dataBuffer2;
    extern uint16 BMA2x2_I2C_bufSizeBuf2;
    extern uint16 BMA2x2_I2C_protectBuf2;
    extern uint8 BMA2x2_I2C_offsetBuf2;
    extern uint16 BMA2x2_I2C_indexBuf2;
#endif /* (BMA2x2_I2C_SECONDARY_ADDRESS_ENABLE_CONST) */


/***************************************
*     Private Function Prototypes
***************************************/

#if(BMA2x2_I2C_SCB_MODE_EZI2C_CONST_CFG)
    void BMA2x2_I2C_EzI2CInit(void);
#endif /* (BMA2x2_I2C_SCB_MODE_EZI2C_CONST_CFG) */

void BMA2x2_I2C_EzI2CStop(void);
#if(BMA2x2_I2C_EZI2C_WAKE_ENABLE_CONST)
    void BMA2x2_I2C_EzI2CSaveConfig(void);
    void BMA2x2_I2C_EzI2CRestoreConfig(void);
#endif /* (BMA2x2_I2C_EZI2C_WAKE_ENABLE_CONST) */

#endif /* (CY_SCB__EZI2C_PVT_BMA2x2_I2C_H) */


/* [] END OF FILE */