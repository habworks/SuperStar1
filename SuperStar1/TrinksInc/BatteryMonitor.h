// TODO: Trinks add comment title block to page

#ifndef _BATTERY_MONITOR_H_
#define _BATTERY_MONITOR_H_

// DEFINES
#define ADC_FULL_SCALE_VALUE			0x03FF
#define VOLTAGE_DIVIDER_RA				57600.0
#define VOLTAGE_DIVIDER_RB				100000.0
#define DEFAULT_VOLTAGE_DIVIDER_RATIO	(float)(VOLTAGE_DIVIDER_RA/(VOLTAGE_DIVIDER_RA + VOLTAGE_DIVIDER_RB))
#define DEFAULT_VOLTAGE_VDDA_REFERENCE	3.300
#define BATTERY_NOMINAL_VOLTAGE			9.000


// FUNCTION PROTOTYPES
float readBatteryVoltage(void);

#endif
