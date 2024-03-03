/*******************************************************************************
* File Name: BUT.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BUT_H) /* Pins BUT_H */
#define CY_PINS_BUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BUT_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} BUT_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   BUT_Read(void);
void    BUT_Write(uint8 value);
uint8   BUT_ReadDataReg(void);
#if defined(BUT__PC) || (CY_PSOC4_4200L) 
    void    BUT_SetDriveMode(uint8 mode);
#endif
void    BUT_SetInterruptMode(uint16 position, uint16 mode);
uint8   BUT_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void BUT_Sleep(void); 
void BUT_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(BUT__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define BUT_DRIVE_MODE_BITS        (3)
    #define BUT_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BUT_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the BUT_SetDriveMode() function.
         *  @{
         */
        #define BUT_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define BUT_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define BUT_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define BUT_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define BUT_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define BUT_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define BUT_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define BUT_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define BUT_MASK               BUT__MASK
#define BUT_SHIFT              BUT__SHIFT
#define BUT_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BUT_SetInterruptMode() function.
     *  @{
     */
        #define BUT_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define BUT_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define BUT_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define BUT_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(BUT__SIO)
    #define BUT_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(BUT__PC) && (CY_PSOC4_4200L)
    #define BUT_USBIO_ENABLE               ((uint32)0x80000000u)
    #define BUT_USBIO_DISABLE              ((uint32)(~BUT_USBIO_ENABLE))
    #define BUT_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define BUT_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define BUT_USBIO_ENTER_SLEEP          ((uint32)((1u << BUT_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << BUT_USBIO_SUSPEND_DEL_SHIFT)))
    #define BUT_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << BUT_USBIO_SUSPEND_SHIFT)))
    #define BUT_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << BUT_USBIO_SUSPEND_DEL_SHIFT)))
    #define BUT_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(BUT__PC)
    /* Port Configuration */
    #define BUT_PC                 (* (reg32 *) BUT__PC)
#endif
/* Pin State */
#define BUT_PS                     (* (reg32 *) BUT__PS)
/* Data Register */
#define BUT_DR                     (* (reg32 *) BUT__DR)
/* Input Buffer Disable Override */
#define BUT_INP_DIS                (* (reg32 *) BUT__PC2)

/* Interrupt configuration Registers */
#define BUT_INTCFG                 (* (reg32 *) BUT__INTCFG)
#define BUT_INTSTAT                (* (reg32 *) BUT__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define BUT_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(BUT__SIO)
    #define BUT_SIO_REG            (* (reg32 *) BUT__SIO)
#endif /* (BUT__SIO_CFG) */

/* USBIO registers */
#if !defined(BUT__PC) && (CY_PSOC4_4200L)
    #define BUT_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define BUT_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define BUT_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define BUT_DRIVE_MODE_SHIFT       (0x00u)
#define BUT_DRIVE_MODE_MASK        (0x07u << BUT_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins BUT_H */


/* [] END OF FILE */
