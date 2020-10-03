// TODO: Trinks add a file comment header similar to the others
#ifndef _LED_CONTROL_H_
#define _LED_CONTROL_H_
#include "MainSupport.h"
#include "main.h"

// MACROS
#define ON_RLED1()				HAL_GPIO_WritePin(MC_RLED1_GPIO_Port, MC_RLED1_Pin, GPIO_PIN_SET);
#define OFF_RLED1()				HAL_GPIO_WritePin(MC_RLED1_GPIO_Port, MC_RLED1_Pin, GPIO_PIN_RESET);
#define ON_GLED1()				HAL_GPIO_WritePin(MC_GLED1_GPIO_Port, MC_GLED1_Pin, GPIO_PIN_SET);
#define OFF_GLED1()				HAL_GPIO_WritePin(MC_GLED1_GPIO_Port, MC_GLED1_Pin, GPIO_PIN_RESET);

#define ON_RLED2()				HAL_GPIO_WritePin(MC_RLED2_GPIO_Port, MC_RLED2_Pin, GPIO_PIN_SET);
#define OFF_RLED2()				HAL_GPIO_WritePin(MC_RLED2_GPIO_Port, MC_RLED2_Pin, GPIO_PIN_RESET);
#define ON_GLED2()				HAL_GPIO_WritePin(MC_GLED2_GPIO_Port, MC_GLED2_Pin, GPIO_PIN_SET);
#define OFF_GLED2()				HAL_GPIO_WritePin(MC_GLED2_GPIO_Port, MC_GLED2_Pin, GPIO_PIN_RESET);

#define ON_RLED3()				HAL_GPIO_WritePin(MC_RLED3_GPIO_Port, MC_RLED3_Pin, GPIO_PIN_SET);
#define OFF_RLED3()				HAL_GPIO_WritePin(MC_RLED3_GPIO_Port, MC_RLED3_Pin, GPIO_PIN_RESET);
#define ON_GLED3()				HAL_GPIO_WritePin(MC_GLED3_GPIO_Port, MC_GLED3_Pin, GPIO_PIN_SET);
#define OFF_GLED3()				HAL_GPIO_WritePin(MC_GLED3_GPIO_Port, MC_GLED3_Pin, GPIO_PIN_RESET);

#define ON_RLED4()				HAL_GPIO_WritePin(MC_RLED4_GPIO_Port, MC_RLED4_Pin, GPIO_PIN_SET);
#define OFF_RLED4()				HAL_GPIO_WritePin(MC_RLED4_GPIO_Port, MC_RLED4_Pin, GPIO_PIN_RESET);
#define ON_GLED4()				HAL_GPIO_WritePin(MC_GLED4_GPIO_Port, MC_GLED4_Pin, GPIO_PIN_SET);
#define OFF_GLED4()				HAL_GPIO_WritePin(MC_GLED4_GPIO_Port, MC_GLED4_Pin, GPIO_PIN_RESET);

#define ON_RLED5()				HAL_GPIO_WritePin(MC_RLED5_GPIO_Port, MC_RLED5_Pin, GPIO_PIN_SET);
#define OFF_RLED5()				HAL_GPIO_WritePin(MC_RLED5_GPIO_Port, MC_RLED5_Pin, GPIO_PIN_RESET);
#define ON_GLED5()				HAL_GPIO_WritePin(MC_GLED5_GPIO_Port, MC_GLED5_Pin, GPIO_PIN_SET);
#define OFF_GLED5()				HAL_GPIO_WritePin(MC_GLED5_GPIO_Port, MC_GLED5_Pin, GPIO_PIN_RESET);

#define ON_RLED6()				HAL_GPIO_WritePin(MC_RLED6_GPIO_Port, MC_RLED6_Pin, GPIO_PIN_SET);
#define OFF_RLED6()				HAL_GPIO_WritePin(MC_RLED6_GPIO_Port, MC_RLED6_Pin, GPIO_PIN_RESET);
#define ON_GLED6()				HAL_GPIO_WritePin(MC_GLED6_GPIO_Port, MC_GLED6_Pin, GPIO_PIN_SET);
#define OFF_GLED6()				HAL_GPIO_WritePin(MC_GLED6_GPIO_Port, MC_GLED6_Pin, GPIO_PIN_RESET);

#define ON_RLED7()				HAL_GPIO_WritePin(MC_RLED7_GPIO_Port, MC_RLED7_Pin, GPIO_PIN_SET);
#define OFF_RLED7()				HAL_GPIO_WritePin(MC_RLED7_GPIO_Port, MC_RLED7_Pin, GPIO_PIN_RESET);
#define ON_GLED7()				HAL_GPIO_WritePin(MC_GLED7_GPIO_Port, MC_GLED7_Pin, GPIO_PIN_SET);
#define OFF_GLED7()				HAL_GPIO_WritePin(MC_GLED7_GPIO_Port, MC_GLED7_Pin, GPIO_PIN_RESET);

#define ON_RLED8()				HAL_GPIO_WritePin(MC_RLED8_GPIO_Port, MC_RLED8_Pin, GPIO_PIN_SET);
#define OFF_RLED8()				HAL_GPIO_WritePin(MC_RLED8_GPIO_Port, MC_RLED8_Pin, GPIO_PIN_RESET);
#define ON_GLED8()				HAL_GPIO_WritePin(MC_GLED8_GPIO_Port, MC_GLED8_Pin, GPIO_PIN_SET);
#define OFF_GLED8()				HAL_GPIO_WritePin(MC_GLED8_GPIO_Port, MC_GLED8_Pin, GPIO_PIN_RESET);


#define GREEN_LED3_TOGGLE() 	HAL_GPIO_TogglePin(MC_GLED3_GPIO_Port, MC_GLED3_Pin);

// MACROS: Seven Segment
#define DIG_ONE_A()				HAL_GPIO_WritePin(MC_SEG_7A1_GPIO_Port, MC_SEG_7A1_Pin, GPIO_PIN_SET);
#define OFF_DIG_ONE_A()			HAL_GPIO_WritePin(MC_SEG_7A1_GPIO_Port, MC_SEG_7A1_Pin, GPIO_PIN_RESET);

#define DIG_ONE_B()				HAL_GPIO_WritePin(MC_SEG_8B1_GPIO_Port, MC_SEG_8B1_Pin, GPIO_PIN_SET);
#define OFF_DIG_ONE_B()			HAL_GPIO_WritePin(MC_SEG_8B1_GPIO_Port, MC_SEG_8B1_Pin, GPIO_PIN_RESET);

#define DIG_ONE_C()				HAL_GPIO_WritePin(MS_SEG_4C1_GPIO_Port, MS_SEG_4C1_Pin, GPIO_PIN_SET);
#define OFF_DIG_ONE_C()			HAL_GPIO_WritePin(MS_SEG_4C1_GPIO_Port, MS_SEG_4C1_Pin, GPIO_PIN_RESET);

#define DIG_ONE_D()				HAL_GPIO_WritePin(MC_SEG_2D1_GPIO_Port, MC_SEG_2D1_Pin, GPIO_PIN_SET);
#define OFF_DIG_ONE_D()			HAL_GPIO_WritePin(MC_SEG_2D1_GPIO_Port, MC_SEG_2D1_Pin, GPIO_PIN_RESET);

#define DIG_ONE_E()				HAL_GPIO_WritePin(MC_SEG_3E1_GPIO_Port, MC_SEG_3E1_Pin, GPIO_PIN_SET);
#define OFF_DIG_ONE_E()			HAL_GPIO_WritePin(MC_SEG_3E1_GPIO_Port, MC_SEG_3E1_Pin, GPIO_PIN_RESET);

#define DIG_ONE_F()				HAL_GPIO_WritePin(MC_SEG_9F1_GPIO_Port, MC_SEG_9F1_Pin, GPIO_PIN_SET);
#define OFF_DIG_ONE_F()			HAL_GPIO_WritePin(MC_SEG_9F1_GPIO_Port, MC_SEG_9F1_Pin, GPIO_PIN_RESET);

#define DIG_ONE_G()				HAL_GPIO_WritePin(MC_SEG_10G1_GPIO_Port, MC_SEG_10G1_Pin, GPIO_PIN_SET);
#define OFF_DIG_ONE_G()			HAL_GPIO_WritePin(MC_SEG_10G1_GPIO_Port, MC_SEG_10G1_Pin, GPIO_PIN_RESET);

#define POWER_ON_SENSOR_DP()	HAL_GPIO_WritePin(Sens_PWR_GPIO_Port, Sens_PWR_Pin, GPIO_PIN_SET);
#define POWER_OFF_SESNOR_DP()	HAL_GPIO_WritePin(Sens_PWR_GPIO_Port, Sens_PWR_Pin, GPIO_PIN_RESET);  // TODO: Trinks You spell this wrong

#define DIG_TENTH_A()			HAL_GPIO_WritePin(MC_SEG_7A2_GPIO_Port, MC_SEG_7A2_Pin, GPIO_PIN_SET);
#define OFF_DIG_TENTH_A()		HAL_GPIO_WritePin(MC_SEG_7A2_GPIO_Port, MC_SEG_7A2_Pin, GPIO_PIN_RESET);

#define DIG_TENTH_B()			HAL_GPIO_WritePin(MC_SEG_8B2_GPIO_Port, MC_SEG_8B2_Pin, GPIO_PIN_SET);
#define OFF_DIG_TENTH_B()		HAL_GPIO_WritePin(MC_SEG_8B2_GPIO_Port, MC_SEG_8B2_Pin, GPIO_PIN_RESET);

#define DIG_TENTH_C()			HAL_GPIO_WritePin(MC_SEG_4C2_GPIO_Port, MC_SEG_4C2_Pin, GPIO_PIN_SET);
#define OFF_DIG_TENTH_C()		HAL_GPIO_WritePin(MC_SEG_4C2_GPIO_Port, MC_SEG_4C2_Pin, GPIO_PIN_RESET);

#define DIG_TENTH_D()			HAL_GPIO_WritePin(MC_SEG_2D2_GPIO_Port, MC_SEG_2D2_Pin, GPIO_PIN_SET);
#define OFF_DIG_TENTH_D()		HAL_GPIO_WritePin(MC_SEG_2D2_GPIO_Port, MC_SEG_2D2_Pin, GPIO_PIN_RESET);

#define DIG_TENTH_E()			HAL_GPIO_WritePin(MC_SEG_3E2_GPIO_Port, MC_SEG_3E2_Pin, GPIO_PIN_SET);
#define OFF_DIG_TENTH_E()		HAL_GPIO_WritePin(MC_SEG_3E2_GPIO_Port, MC_SEG_3E2_Pin, GPIO_PIN_RESET);

#define DIG_TENTH_F()			HAL_GPIO_WritePin(MC_SEG_9F2_GPIO_Port, MC_SEG_9F2_Pin, GPIO_PIN_SET);
#define OFF_DIG_TENTH_F()		HAL_GPIO_WritePin(MC_SEG_9F2_GPIO_Port, MC_SEG_9F2_Pin, GPIO_PIN_RESET);

#define DIG_TENTH_G()			HAL_GPIO_WritePin(MC_SEG_10G2_GPIO_Port, MC_SEG_10G2_Pin, GPIO_PIN_SET);
#define OFF_DIG_TENTH_G()		HAL_GPIO_WritePin(MC_SEG_10G2_GPIO_Port, MC_SEG_10G2_Pin, GPIO_PIN_RESET);


// FUNCTION PROTOTYPES
void init_OSC32_InOutAsGPIO();
bool_t displayNumONE(uint8_t DigitToDisplayONE);
bool_t displayNumTENTH(uint8_t DigitToDisplayTENTH);
bool_t displayErrorCode(uint8_t ErrorCode);
void segONE_OFF (void);
void segTENTH_OFF (void);
void all_LedOFF (void);
void ledFLASH_test_1 (void);
void displayGo (void);
void displayStop (void);
void displayCaution (void);
void realDistance (float);
void startUpRoutine(void);
void ledOnPlacement(uint16_t RedLedByte, uint16_t GreenLedByte, uint16_t YellowLedByte);

#endif
/* need to test all LED for BOTH COLORS RED AND GREEN
 * gpioSET gpioRESET gpioTOGGLE
 */
