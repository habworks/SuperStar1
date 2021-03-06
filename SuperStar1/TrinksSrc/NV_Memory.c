/** ****************************************************************************************************
 * @file 			NV Memory.c
 * @brief			This is the Source file used to support Non Volatile memory operation
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

#include "NV_Memory.h"



/** ****************************************************************************************************
* @brief Write a byte value to the NVM
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note This function must not be called before NVM has been unlocked
* @note After writing activity the NVM must be locked
* @note See Appendix A.3 of the STM32l0x2 Reference for additional details
*
* @param NVM_AddressOffset is an integer increment above the base NVM address
* @return True if write success
*
* WHY: It will be necessary to store and retrieve various characteristics about the board in NVRAM \n
*
* STEP 1: Check for valid offset \n
* STEP 2: Write the address at the offset value and wait for it to finish \n
* STEP 3: Test and return
* **************************************************************************************************** */
bool_t writeBasicByteNVM(uint32_t NVM_AddressOffset, uint8_t ByteValue)
{

	// STEP 1:
	// Check for valid offset
	if ((NVM_AddressOffset == 0) || (NVM_AddressOffset > SIZE_OF_DATA_EEPROM))
		return(false);

	// STEP 2:
	// Write the address at the offset value and wait for it to finish
	*(uint8_t *)(BASE_DATA_EEPROM_ADDRESS + NVM_AddressOffset) = ByteValue;
	while(FLASH->SR & FLASH_SR_BSY)
	{
	/* For future robust implementation, add here time-out management */
	}

	// STEP 3:
	// Test and return
	if  (*(uint8_t *)(BASE_DATA_EEPROM_ADDRESS + NVM_AddressOffset) != ByteValue)
	  return(false);
	else
	  return(true);

} // END OF writeBasicByteNVM


/** ****************************************************************************************************
* @brief Write a byte value to the NVM.  This is different than the function writeBasicByteNVM() as it
* includes the necessary lock and unlock of the NV memory.  As such this function can be used standalone
* within the application
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note This function must not be called before NVM has been unlocked
* @note After writing activity the NVM must be locked
* @note See Appendix A.3 of the STM32l0x2 Reference for additional details
*
* @param NVM_AddressOffset is an integer increment above the base NVM address
* @return True if write success
*
* WHY: It will be necessary to store and retrieve various characteristics about the board in NVRAM \n
*
* STEP 1: Check for valid offset \n
* STEP 2: Write the address at the offset value and wait for it to finish \n
* STEP 3: Test and return
* **************************************************************************************************** */
bool_t writeByteNVM(uint32_t NVM_AddressOffset, uint8_t ByteValue)
{

	// STEP 1:
	// Check for valid offset
	if ((NVM_AddressOffset == 0) || (NVM_AddressOffset > SIZE_OF_DATA_EEPROM))
		return(false);

	// STEP 2:
	// Write the address at the offset value and wait for it to finish
	unlockNVM();
	*(uint8_t *)(BASE_DATA_EEPROM_ADDRESS + NVM_AddressOffset) = ByteValue;
	while(FLASH->SR & FLASH_SR_BSY)
	{
	/* For future robust implementation, add here time-out management */
	}

	// STEP 3:
	// Test and return
	lockNVM();
	if  (*(uint8_t *)(BASE_DATA_EEPROM_ADDRESS + NVM_AddressOffset) != ByteValue)
		return(false);
	else
		return(true);

} // END OF writeByteNVM



/** ****************************************************************************************************
* @brief Read a byte value from the NVM
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note See Appendix A.3 of the STM32l0x2 Reference for additional details
*
* @param NVM_AddressOffset is an integer increment above the base NVM address
* @return The value of the byte at the offset address
*
* WHY: It will be necessary to store and retrieve various characteristics about the board in NVRAM \n
*
* STEP 1: Check for valid offset \n
* STEP 2: Read NVM and return
* **************************************************************************************************** */
uint8_t readByteNVM(uint32_t NVM_AddressOffset)
{

	// STEP 1:
	// Check for valid offset
	if ((NVM_AddressOffset == 0) || (NVM_AddressOffset > SIZE_OF_DATA_EEPROM))
		return(false);

	// STEP 2:
	// Read and return
	return(*(uint8_t *)(BASE_DATA_EEPROM_ADDRESS + NVM_AddressOffset));

} // END OF readByteNVM



/** ****************************************************************************************************
* @brief Write a float value to the NVM
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note This function is intended for general use within the application
* @note No other pre or post function calls are necessary
*
* @param NVM_AddressOffset is an integer increment above the base NVM address
* @return True if write success
*
* WHY: It will be necessary to store and retrieve various characteristics about the board in NVRAM \n
*
* STEP 1: Check for valid offset \n
* STEP 2: Unlock the NV memory \n
* STEP 3: Write the float as bytes starting at the base address \n
* STEP 4: If successful Lock the NV memory and return
* **************************************************************************************************** */
bool_t writeFloatNVM(uint32_t NVM_AddressOffset, float FloatValue)
{

	bool_t WriteStatus;
	uint32_t AddressOffsetPointer;
	Type_FloatAsByteArray FloatNumber;

	// STEP 1:
	// Check for valid offset
	if ((NVM_AddressOffset == 0) || (NVM_AddressOffset > SIZE_OF_DATA_EEPROM))
		return(false);

	// STEP 2
	// Unlock the NV memory
	unlockNVM();

	// STEP 3
	// Write the float as bytes starting at the base address
	FloatNumber.Float = FloatValue;

	for (uint8_t ByteIndex = 0; ByteIndex < sizeof(float); ByteIndex++)
	{
		AddressOffsetPointer = NVM_AddressOffset + ByteIndex;
		WriteStatus = writeBasicByteNVM(AddressOffsetPointer, (uint8_t)FloatNumber.Byte[ByteIndex]);
		if (WriteStatus == false)
		{
			lockNVM();
			return(false);
		}
	}

	// STEP 4
	// If successful Lock the NV memory and return
	lockNVM();
	return(true);

} // END OF FUNCTION writeFloatNVM



/** ****************************************************************************************************
* @brief Read a float value from the NVM
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note See Appendix A.3 of the STM32l0x2 Reference for additional details
*
* @param NVM_AddressOffset is an integer increment above the base NVM address
* @return The value of the float at the offset address
*
* WHY: It will be necessary to store and retrieve various characteristics about the board in NVRAM \n
*
* STEP 1: Check for valid offset \n
* STEP 2: Read NVM and return
* **************************************************************************************************** */
float readFloatNVM(uint32_t NVM_AddressOffset)
{

	uint32_t AddressOffsetPointer;
	Type_FloatAsByteArray FloatNumber;

	// STEP 1:
	// Check for valid offset
	if ((NVM_AddressOffset == 0) || (NVM_AddressOffset > SIZE_OF_DATA_EEPROM))
		return(false);

	// STEP 2:
	// Read NVM and return
	for (uint8_t ByteIndex = 0; ByteIndex < sizeof(float); ByteIndex++)
	{
		AddressOffsetPointer = NVM_AddressOffset + ByteIndex;
		FloatNumber.Byte[ByteIndex] = readByteNVM(AddressOffsetPointer);
	}
	return(FloatNumber.Float);

} // END OF readFloatNVM



/** ****************************************************************************************************
* @brief Unlock the NVM
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note See Appendix A.3 of the STM32l0x2 Reference for additional details
*
* @param void
* @return void
*
* WHY: The NVM must be unlocked before it can be written to \n
*
* STEP 1: Wait until no operation is on going \n
* STEP 2: Check if the PELOCK is unlocked and unlock
* **************************************************************************************************** */
__INLINE void unlockNVM(void)
{
	// STEP 1:
	// Wait until no operation is on going
	  while ((FLASH->SR & FLASH_SR_BSY) != 0)
	  {
		/* For future robust implementation, add here time-out management */
	  }

	  // STEP 2:
	  // Check if the PELOCK is unlocked and unlock
	  if ((FLASH->PECR & FLASH_PECR_PELOCK) != 0) /* (2) */
	  {
		FLASH->PEKEYR = FLASH_PEKEY1; /* (3) */
		FLASH->PEKEYR = FLASH_PEKEY2;
	  }

} // END OF unlockNVM



/** ****************************************************************************************************
* @brief Lock the NVM
*
* @author 			Hab S. Collector \n
* Last Edited By:  	Hab S. Collector \n
*
* @note See Appendix A.3 of the STM32l0x2 Reference for additional details
*
* @param void
* @return void
*
* WHY: The NVM must be unlocked before it can be written to and locked after\n
*
* STEP 1: Wait until no operation is on going \n
* STEP 2: Locks the NVM by setting PELOCK in PECR
* **************************************************************************************************** */
__INLINE void lockNVM(void)
{

	// STEP 1:
	// Wait until no operation is on going
	  while ((FLASH->SR & FLASH_SR_BSY) != 0)
	  {
		/* For future robust implementation, add here time-out management */
	  }

	  // STEP 2:
	  // Locks the NVM by setting PELOCK in PECR
	  FLASH->PECR |= FLASH_PECR_PELOCK;

} // END OF lockNVM


void flashMemoryPwrDwnWhenInSleep(void)
{
	FLASH->ACR |= FLASH_ACR_SLEEP_PD;
}
