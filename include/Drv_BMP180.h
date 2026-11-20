/*
 * Drv_BMP180.h
 *
 *  Created on: Mar 19, 2025
 *      Author: tmx37
 */

#ifndef DRV_BMP180_INC_DRVGY_BMP180_H_
#define DRV_BMP180_INC_DRVGY_BMP180_H_


/******************************************************************************
 * Includes
 *******************************************************************************/

#include "Drv_BMP180_Cfg.h"

/******************************************************************************
 * Module Typedefs
 ******************************************************************************/
typedef enum
{
	KELVIN,
	CELSIUS,
	FAHRENHEIT
} Drv_BMP180_TempUnit;

typedef enum
{
	PASCAL,
	HPASCAL
} Drv_BMP180_PresUnit;

typedef enum
{
	METER,
	FEET
} Drv_BMP180_AltUnit;

typedef uint32_t (*Drv_BMP180_WriteRegCB_t)(uint8_t DevAddr, uint8_t RegNdx, uint8_t *pDataBuffer, uint32_t DataSize);

typedef uint32_t (*Drv_BMP180_ReadRegCB_t)(uint8_t DevAddr, uint8_t RegNdx, uint8_t *pDataBuffer, uint32_t DataSize);

typedef uint32_t (*Drv_BMP180_IsDeviceReadyCB_t)(uint8_t DevAddr, uint8_t nTrials);

/**
 * BMP180 configuration istance
 */
typedef struct
{
	Drv_BMP180_WriteRegCB_t pfWriteRegistersI2cCB;
	Drv_BMP180_ReadRegCB_t pfReadRegisterI2cCB;
	Drv_BMP180_IsDeviceReadyCB_t pfIsDeviceReadyI2cCB;

	Drv_BMP180_AltUnit AltitudeUnit;
	Drv_BMP180_PresUnit PressureUnit;
	Drv_BMP180_TempUnit TemperatureUnit;

	uint8_t oversampling_setting;
} Drv_BMP180_Cfg_t;

/******************************************************************************
 * Function Definitions/Prototypes for PUBLIC functions
 *******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

GenUtl_Err_t Drv_BMP180_Init(const Drv_BMP180_Cfg_t *pConfigData);

int32_t getTemperature();

int32_t getPressure();

int32_t getAltitude();

GenUtl_Err_t isDeviceReady();

void setTemperatureUnit(Drv_BMP180_TempUnit unit);

void setPressureUnit(Drv_BMP180_PresUnit unit);

void setAltitudeUnit(Drv_BMP180_AltUnit unit);

int32_t convTemp(uint8_t value, Drv_BMP180_TempUnit unit);

int32_t convPres(uint8_t value, Drv_BMP180_PresUnit unit);

int32_t convAltitude(uint8_t value, Drv_BMP180_AltUnit unit);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* DRVGY_BMP180_INC_DRVGY_BMP180_H_ */

/*************** END OF FUNCTIONS *********************************************/
