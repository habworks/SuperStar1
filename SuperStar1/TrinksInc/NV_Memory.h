/** ****************************************************************************************************
 * @file 			NV Memory.h
 * @brief			This is the Header file used to support NV_Memory.C
 * ****************************************************************************************************
 * @author			Hab S. Collector \n
 * Last Edited By:	Hab S. Collector \n
 *
 * @date			7/18/20 \n
 * Last Edit Date:  7/18/20 \n
 * @version       	See Main.C
 *
 * @param Development_Environment \n
 * Hardware:		ST32LM082 \n
 * IDE:             Atollic TrueStudio, VER 9.3.0 \n
 * Compiler:        GCC \n
 * Editor Settings: 1 Tab = 4 Spaces, Recommended Courier New 11
 *
 * @note            This file supports the use of Non Volatile memory on STM32L010C6
 *                  This is a category 2 device as defined in ST Manual RM0451
 *                  See section 4.1, page 45 for memory map information
 * 					This is an embedded application
 *		            It will be necessary to consult the reference documents before you can review this code.
 *                  It is suggested that the documents be reviewed in the order shown.
 *			          SuperStar Technical Manual
 *				      SuperStar User Manual
 *
 * @copyright		IMR Engineering
 * **************************************************************************************************** */

#ifndef _NV_MEMORY_H_
#define _NV_MEMORY_H_

#include "MainSupport.h"
#include "stm32l0xx_hal.h"


// DEFINES: BASE MEMORY ADDRESS AND SIZE
#define	BASE_DATA_EEPROM_ADDRESS					((uint32_t)0x08080000)
#define SIZE_OF_DATA_EEPROM							((uint32_t)0x0100)
// DEFINES: MEMORY PARAMETERS OFFSET
#define MEMORY_OFFSET_ADC_CALIBRATION_PROGRAMED		1
#define SIZEOF_OFFSET_ADC_CALIBRATION_PROGRAMED		sizeof(uint8_t)
#define MEMORY_OFFSET_ZERO_DISTANCE_SET				MEMORY_OFFSET_ADC_CALIBRATION_PROGRAMED + SIZEOF_OFFSET_ADC_CALIBRATION_PROGRAMED
#define SIZEOF_OFFSET_ZERO_DISTANCE_SET				sizeof(uint8_t)
#define MEMORY_OFFSET_STOP_DISTANCE					MEMORY_OFFSET_ZERO_DISTANCE_SET + SIZEOF_OFFSET_ZERO_DISTANCE_SET
#define SIZEOF_OFFSET_STOP_DISTANCE					sizeof(float)
#define MEMORY_OFFSET_ADC_VDDA_VREF					MEMORY_OFFSET_STOP_DISTANCE + SIZEOF_OFFSET_STOP_DISTANCE
#define SIZEOF_OFFSET_ADC_VDDA_VREF					sizeof(float)
#define MEMORY_OFFSET_DIVIDER_RATIO					MEMORY_OFFSET_ADC_VDDA_VREF + SIZEOF_OFFSET_ADC_VDDA_VREF
#define SIZEOF_OFFSET_DIVIDER_RATIO					sizeof(double)
// DEFINES: MEMORY TEST
#define ADC_CALIBRATION_INSTALLED					((uint8_t)0xC1)		// Just an arbitrary value to test if calibration is installed
#define STOP_DISTANCE_SET							((uint8_t)0x1C)		// Just an arbitrary value to test if stop distance is set


// TYPEDEFS AND ENUM
typedef union
{
	uint8_t		Byte[4];
	float		Float;
}Type_FloatAsByteArray;


// FUNCTION PROTOTYPES
bool_t writeBasicByteNVM(uint32_t NVM_AddressOffset, uint8_t ByteValue);
bool_t writeByteNVM(uint32_t NVM_AddressOffset, uint8_t ByteValue);
bool_t writeFloatNVM(uint32_t NVM_AddressOffset, float FloatValue);
uint8_t readByteNVM(uint32_t NVM_ByteAddressOffset);
float readFloatNVM(uint32_t NVM_ByteAddressOffset);
void unlockNVM(void);
void lockNVM(void);
void flashMemoryPwrDwnWhenInSleep(void);


#endif
