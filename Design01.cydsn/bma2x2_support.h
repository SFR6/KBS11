/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#ifndef __BMA2x2_SUPPORT_H__
#define __BMA2x2_SUPPORT_H__


#include "bma2x2.h"
#include "project.h"

#define I2C_TIMEOUT 100

    
    
    
s8 BMA2x2_I2C_bus_read(u8 dev_id, u8 reg_addr, u8 *reg_data, u8 len);
 /*	\Brief : The function is used as I2C bus write
 *	\Return : Status of the I2C write
 *	\param dev_id : The device address of the sensor
 *	\param reg_addr : Address of the first register,
 *              will data is going to be written
 *	\param reg_data : It is a value hold in the array,
 *		will be used for write the value into the register
 *	\param cnt : The no of byte of data to be write
 */



s8 BMA2x2_I2C_bus_write(u8 dev_id, u8 reg_addr, u8 *reg_data, u8 len);
 /* \Brief : The function is used as SPI bus write
 * \Return : Status of the SPI write
 * \param dev_id : The device address of the sensor
 * \param reg_addr : Address of the first register,
 *      will data is going to be written
 * \param reg_data : It is a value hold in the array,
 *	will be used for write the value into the register
 * \param cnt : The no of byte of data to be write
 */


s32 bma2x2_shock_setup(struct bma2x2_t *bma2x2);
 /* \Brief : The function is used as an initial setup for the accelerometer
 * \Return : Status of the accelerometer
 * \param *bma2x2 : The struct used for the accelerometer
 */

s8 I2C_routine(struct bma2x2_t *bma2x2);
 /*
 *	\Brief : This function is used to map the I2C bus read, write, delay and
 *	            device address with global structure bma2x2_t
 */


void BMA2x2_delay_msek(u32 msek);
 /*  \Brief : This function is an example for delay
 *	 \Return : communication result
 *   \param : None
 */
s32 bma2x2_data_readout_template(struct bma2x2_t *bma2x2);
 /*
 *  \Brief : struct bma2x2_t parameters can be accessed by using bma2x2
 *	            bma2x2_t having the following parameters
 *	            Bus write function pointer: BMA2x2_WR_FUNC_PTR
 *	            Bus read function pointer: BMA2x2_RD_FUNC_PTR
 *	            Burst read function pointer: BMA2x2_BRD_FUNC_PTR
 *	            Delay function pointer: delay_msec
 *	            I2C address: dev_addr
 *	            Chip id of the sensor: chip_id
 *  \Return : None
 *  \param *bma2x2 : The struct used for the accelerometer
 */



/*----------------------------------------------------------------------------*
*  V_BMA2x2RESOLUTION_u8R used for selecting the accelerometer resolution
 *	12 bit
 *	14 bit
 *	10 bit
*----------------------------------------------------------------------------*/
extern u8 V_BMA2x2RESOLUTION_u8R;



#endif
/* [] END OF FILE */
