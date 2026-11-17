 /*
 * DrvGY_BMP180_Cfg.c
 *
 *  Created on: Mar 19, 2025
 *      Author: tmx37
 */


 /******************************************************************************
 * Includes
 *******************************************************************************/

#include "Drv_BMP180_Cfg.h"
#include "Drv_BMP180.h"

 /******************************************************************************
  * Module Preprocessor Constants
  ******************************************************************************/

 /******************************************************************************
  * Module Preprocessor Macros
  ******************************************************************************/

 /******************************************************************************
  * Function Prototypes Private
  ******************************************************************************/

uint32_t MockWriteI2CReg(uint32_t I2cInst, uint8_t DevAddr, uint8_t RegNdx, uint8_t *pDataBuffer, uint32_t DataSize);
uint32_t MockReadI2CReg(uint32_t I2cInst, uint8_t DevAddr, uint8_t RegNdx, uint8_t *pDataBuffer, uint32_t DataSize);
uint32_t MockIsDeviceReady(uint32_t I2cInst, uint8_t DevAddr, uint8_t nTrials);

 /******************************************************************************
  * Module Variable Definitions
  ******************************************************************************/

static Drv_BMP180_Cfg_t mConfigData;

 /******************************************************************************
  * Function Definitions Private
  ******************************************************************************/

 /******************************************************************************
  * Function Definitions Public
  ******************************************************************************/

GenUtl_Err_t  DrvGYBMP180Cfg_Init(void)
{
	GenUtl_Err_t ErrCode;

	mConfigData.I2CInst = 0;
	mConfigData.pfWriteRegistersI2cCB = MockWriteI2CReg;
	mConfigData.pfReadRegisterI2cCB = MockReadI2CReg;
	mConfigData.pfIsDeviceReadyI2cCB = MockIsDeviceReady;
	mConfigData.oversampling_setting = 3;

	ErrCode = Drv_BMP180_Init(&mConfigData);
	return ErrCode;
}

uint32_t MockWriteI2CReg(uint32_t I2cInst, uint8_t DevAddr, uint8_t RegNdx, uint8_t *pDataBuffer, uint32_t DataSize)
{
  return OUT_OK;
}

uint32_t MockReadI2CReg(uint32_t I2cInst, uint8_t DevAddr, uint8_t RegNdx, uint8_t *pDataBuffer, uint32_t DataSize)
{
  return OUT_OK;
}

uint32_t MockIsDeviceReady(uint32_t I2cInst, uint8_t DevAddr, uint8_t nTrials)
{
  return OUT_OK;
}

void HAL_Delay(uint32_t Delay)
{
  (void)Delay;
}


/*** End of File **************************************************************/
