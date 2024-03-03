/*******************************************************************************
* File Name: BMA2x2_I2C_SCBCLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_BMA2x2_I2C_SCBCLK_H)
#define CY_CLOCK_BMA2x2_I2C_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void BMA2x2_I2C_SCBCLK_StartEx(uint32 alignClkDiv);
#define BMA2x2_I2C_SCBCLK_Start() \
    BMA2x2_I2C_SCBCLK_StartEx(BMA2x2_I2C_SCBCLK__PA_DIV_ID)

#else

void BMA2x2_I2C_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void BMA2x2_I2C_SCBCLK_Stop(void);

void BMA2x2_I2C_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 BMA2x2_I2C_SCBCLK_GetDividerRegister(void);
uint8  BMA2x2_I2C_SCBCLK_GetFractionalDividerRegister(void);

#define BMA2x2_I2C_SCBCLK_Enable()                         BMA2x2_I2C_SCBCLK_Start()
#define BMA2x2_I2C_SCBCLK_Disable()                        BMA2x2_I2C_SCBCLK_Stop()
#define BMA2x2_I2C_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    BMA2x2_I2C_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define BMA2x2_I2C_SCBCLK_SetDivider(clkDivider)           BMA2x2_I2C_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define BMA2x2_I2C_SCBCLK_SetDividerValue(clkDivider)      BMA2x2_I2C_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define BMA2x2_I2C_SCBCLK_DIV_ID     BMA2x2_I2C_SCBCLK__DIV_ID

#define BMA2x2_I2C_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define BMA2x2_I2C_SCBCLK_CTRL_REG   (*(reg32 *)BMA2x2_I2C_SCBCLK__CTRL_REGISTER)
#define BMA2x2_I2C_SCBCLK_DIV_REG    (*(reg32 *)BMA2x2_I2C_SCBCLK__DIV_REGISTER)

#define BMA2x2_I2C_SCBCLK_CMD_DIV_SHIFT          (0u)
#define BMA2x2_I2C_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define BMA2x2_I2C_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define BMA2x2_I2C_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define BMA2x2_I2C_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << BMA2x2_I2C_SCBCLK_CMD_DISABLE_SHIFT))
#define BMA2x2_I2C_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << BMA2x2_I2C_SCBCLK_CMD_ENABLE_SHIFT))

#define BMA2x2_I2C_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define BMA2x2_I2C_SCBCLK_DIV_FRAC_SHIFT (3u)
#define BMA2x2_I2C_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define BMA2x2_I2C_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define BMA2x2_I2C_SCBCLK_DIV_REG        (*(reg32 *)BMA2x2_I2C_SCBCLK__REGISTER)
#define BMA2x2_I2C_SCBCLK_ENABLE_REG     BMA2x2_I2C_SCBCLK_DIV_REG
#define BMA2x2_I2C_SCBCLK_DIV_FRAC_MASK  BMA2x2_I2C_SCBCLK__FRAC_MASK
#define BMA2x2_I2C_SCBCLK_DIV_FRAC_SHIFT (16u)
#define BMA2x2_I2C_SCBCLK_DIV_INT_MASK   BMA2x2_I2C_SCBCLK__DIVIDER_MASK
#define BMA2x2_I2C_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_BMA2x2_I2C_SCBCLK_H) */

/* [] END OF FILE */
