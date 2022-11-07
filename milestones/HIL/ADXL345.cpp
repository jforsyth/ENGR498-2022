/* 
* ADXL345.cpp
*
* Created: 10/7/2019
* Author: Jason Forsyth
*/


#include "ADXL345.h"

// default constructor
ADXL345::ADXL345()
{
	//DO NOTHING HERE
}

// default destructor
ADXL345::~ADXL345()
{
	//DO NOTHING HERE
}

void ADXL345::setup(int _CS_PIN, ADXL_RANGE _RANGE/*=ADXL_RANGE::TWO_G*/, ADXL_RESOLUTION _RESOLUTION/*=NORMAL_RESOLUTION*/)
{
	
	//***Step #0***
	//record where the CS is attached, the current range, and resolution
	//set the CS pin to be an OUTPUT HIGH
	csPin=_CS_PIN;
	currentRange=_RANGE;
	currentResolution=_RESOLUTION;
	pinMode(csPin,OUTPUT);
	digitalWrite(csPin,HIGH);
	
	//***Step #1***
	//call SPI.begin() to initialize the SPI interface
	SPI.begin();
	
	//***Step #2***
	//use SPI.setDataMode() to select the appropriate SPI mode for operations. 
	//See: https://www.arduino.cc/en/Reference/SPISetDataMode and the lecture notes
	SPI.setDataMode(SPI_MODE3);
	
	//***Step #3 (Optional) ***
	//write to the DATA_FORMAT register to adjust the sampling range
	
	//***Step #4 (Optional) ***
	//write to the DATA_FORMAT register to adjust the sampling range
	
	//***Step #5***
	//write to the MEASURE bit in the POWER_CLT register
	//to begin sampling. Ensure the write does not modify other bits by
	//reading the current value, modifying the data locally, and then writing
	//back the new register value.
	uint8_t ctlValue = readRegister(POWER_CLT);
	writeRegister(POWER_CLT,ctlValue|0x8u);
	
	
}

void ADXL345::writeRegister(uint8_t address, uint8_t value)
{
	//bring CS pin LOW to begin communication
	digitalWrite(csPin, LOW);
	
	//send address of register to be written
	SPI.transfer(address);
	
	//send new value to be written to the register
	SPI.transfer(value);
	
	//bring CS pin HIGH to end communication
	digitalWrite(csPin, HIGH);

	return;
}

byte ADXL345::readRegister(uint8_t address)
{
	//modify the address to set bit 7 HIGH to indicate a read
	address |= 0x80; //set MSB high for READ
	
	//bring the CS pin low to begin communication
	digitalWrite(csPin, LOW);
	
	//transfer the register address
	SPI.transfer(address);
	
	//transfer bogus data so the accelerometer can respond
	uint8_t rx = SPI.transfer(0x0);
	
	//bring CS pin HIGH to end communication
	digitalWrite(csPin, HIGH);
	
	//return the data read from the register
	return rx;
}

bool ADXL345::selfTest()
{
	
	//implement code to check if you can
	//read the DEVICE_ID register. Return TRUE if
	//the correct result is found, otherwise FALSE.
	
	byte deviceID = readRegister(DEVICE_ID_REG_ADDRESS);
	
	if(deviceID == 0xE5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ADXL345::readMultiBytes(uint8_t baseAddress, int num, uint8_t data[])
{
	
	//set bit 7 high for Read
  //set bit 6 high for multi-byte
  baseAddress |= 0xC0;

  digitalWrite(csPin, LOW);

  //following format of SparkFun reference
  SPI.transfer(baseAddress);
  for (int i = 0; i < num; i++)
  {
    data[i] = SPI.transfer(0x0);
  }
  digitalWrite(csPin, HIGH);
  
	return;
}

int16_t ADXL345::getXAcceleteration()
{
	byte x_lower = readRegister(X_DATA_0);
	byte x_upper = readRegister(X_DATA_1);
	
	int16_t xSample = (x_upper<<8)|x_lower;
	
	return xSample;
}

int16_t ADXL345::getYAcceleteration()
{
	
	byte y_lower = readRegister(Y_DATA_0);
	byte y_upper = readRegister(Y_DATA_1);
	
	int16_t ySample = (y_upper<<8)|y_lower;
	
	return ySample;
}

int16_t ADXL345::getZAcceleteration()
{
	
	byte z_lower = readRegister(Z_DATA_0);
	byte z_upper = readRegister(Z_DATA_1);
	
	int16_t zSample = (z_upper<<8)|z_lower;
	
	return zSample;
}

float ADXL345::convertRawToFloat(int16_t value)
{
	
	return (float)value / 256.0;
}