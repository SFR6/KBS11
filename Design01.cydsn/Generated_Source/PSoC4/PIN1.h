/*******************************************************************************
* File Name: PIN1.h  
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

#if !defined(CY_PINS_PIN1_H) /* Pins PIN1_H */
#define CY_PINS_PIN1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PIN1_aliases.h"


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
} PIN1_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PIN1_Read(void);
void    PIN1_Write(uint8 value);
uint8   PIN1_ReadDataReg(void);
#if defined(PIN1__PC) || (CY_PSOC4_4200L) 
    void    PIN1_SetDriveMode(uint8 mode);
#endif
void    PIN1_SetInterruptMode(uint16 position, uint16 mode);
uint8   PIN1_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PIN1_Sleep(void); 
void PIN1_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PIN1__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PIN1_DRIVE_MODE_BITS        (3)
    #define PIN1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PIN1_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PIN1_SetDriveMode() function.
         *  @{
         */
        #define PIN1_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PIN1_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PIN1_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PIN1_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PIN1_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PIN1_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PIN1_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PIN1_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PIN1_MASK               PIN1__MASK
#define PIN1_SHIFT              PIN1__SHIFT
#define PIN1_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PIN1_SetInterruptMode() function.
     *  @{
     */
        #define PIN1_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PIN1_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PIN1_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PIN1_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PIN1__SIO)
    #define PIN1_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PIN1__PC) && (CY_PSOC4_4200L)
    #define PIN1_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PIN1_USBIO_DISABLE              ((uint32)(~PIN1_USBIO_ENABLE))
    #define PIN1_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PIN1_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PIN1_USBIO_ENTER_SLEEP          ((uint32)((1u << PIN1_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PIN1_USBIO_SUSPEND_DEL_SHIFT)))
    #define PIN1_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PIN1_USBIO_SUSPEND_SHIFT)))
    #define PIN1_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PIN1_USBIO_SUSPEND_DEL_SHIFT)))
    #define PIN1_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PIN1__PC)
    /* Port Configuration */
    #define PIN1_PC                 (* (reg32 *) PIN1__PC)
#endif
/* Pin State */
#define PIN1_PS                     (* (reg32 *) PIN1__PS)
/* Data Register */
#define PIN1_DR                     (* (reg32 *) PIN1__DR)
/* Input Buffer Disable Override */
#define PIN1_INP_DIS                (* (reg32 *) PIN1__PC2)

/* Interrupt configuration Registers */
#define PIN1_INTCFG                 (* (reg32 *) PIN1__INTCFG)
#define PIN1_INTSTAT                (* (reg32 *) PIN1__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PIN1_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PIN1__SIO)
    #define PIN1_SIO_REG            (* (reg32 *) PIN1__SIO)
#endif /* (PIN1__SIO_CFG) */

/* USBIO registers */
#if !defined(PIN1__PC) && (CY_PSOC4_4200L)
    #define PIN1_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PIN1_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PIN1_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PIN1_DRIVE_MODE_SHIFT       (0x00u)
#define PIN1_DRIVE_MODE_MASK        (0x07u << PIN1_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PIN1_H */


/* [] END OF FILE */
