/*******************************************************************************
* File Name: BUT2.h  
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

#if !defined(CY_PINS_BUT2_ALIASES_H) /* Pins BUT2_ALIASES_H */
#define CY_PINS_BUT2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define BUT2_0			(BUT2__0__PC)
#define BUT2_0_PS		(BUT2__0__PS)
#define BUT2_0_PC		(BUT2__0__PC)
#define BUT2_0_DR		(BUT2__0__DR)
#define BUT2_0_SHIFT	(BUT2__0__SHIFT)
#define BUT2_0_INTR	((uint16)((uint16)0x0003u << (BUT2__0__SHIFT*2u)))

#define BUT2_INTR_ALL	 ((uint16)(BUT2_0_INTR))


#endif /* End Pins BUT2_ALIASES_H */


/* [] END OF FILE */
