/*******************************************************************************
* File Name: BMA2x2_I2C_scl.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BMA2x2_I2C_scl_ALIASES_H) /* Pins BMA2x2_I2C_scl_ALIASES_H */
#define CY_PINS_BMA2x2_I2C_scl_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define BMA2x2_I2C_scl_0			(BMA2x2_I2C_scl__0__PC)
#define BMA2x2_I2C_scl_0_PS		(BMA2x2_I2C_scl__0__PS)
#define BMA2x2_I2C_scl_0_PC		(BMA2x2_I2C_scl__0__PC)
#define BMA2x2_I2C_scl_0_DR		(BMA2x2_I2C_scl__0__DR)
#define BMA2x2_I2C_scl_0_SHIFT	(BMA2x2_I2C_scl__0__SHIFT)
#define BMA2x2_I2C_scl_0_INTR	((uint16)((uint16)0x0003u << (BMA2x2_I2C_scl__0__SHIFT*2u)))

#define BMA2x2_I2C_scl_INTR_ALL	 ((uint16)(BMA2x2_I2C_scl_0_INTR))


#endif /* End Pins BMA2x2_I2C_scl_ALIASES_H */


/* [] END OF FILE */
