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
	
	
	//***Step #1***
	//call SPI.begin() to initialize the SPI interface
	
	
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
	
	
	
}

void ADXL345::writeRegister(uint8_t address, uint8_t value)
{
	  //set the CS pin low with DigitalWrite
  /** your code here **/
  
  //Use the SPI interface to transfer the address byte
  /** your code here **/
  
  //Use the SPI interface to transfer the value byte
  /** your code here **/
  
 //set the CS pin HIGH via DigitalWrite
  /** your code here **/
  
  return;
}

byte ADXL345::readRegister(uint8_t address)
{
	//set the MSB high in the address byte to indicate a read
  /** your code here **/
  
  //set the CS pin low with DigitalWrite
  /** your code here **/
  
  //Use the SPI interface to transfer the address byte
  /** your code here **/
  
  //Use the SPI interface to transfer a bogus packet.
  //the result/return of the transfer will be a read from the peripheral
  /** your code here **/
  
  //set the CS pin HIGH via DigitalWrite
  /** your code here **/
 
  //return the result of the read operation. Correctly return dummy value
  return 0x0;
}

bool ADXL345::selfTest()
{
	
	//implement code to check if you can
	//read the DEVICE_ID register. Return TRUE if
	//the correct result is found, otherwise FALSE.
	
	return false;
}

void ADXL345::readMultiBytes(uint8_t baseAddress, int num, uint8_t data[])
{
	
	return;
}

int16_t ADXL345::getXAcceleteration()
{
	
	return 0;
}

int16_t ADXL345::getYAcceleteration()
{
	
	return 0;
}

int16_t ADXL345::getZAcceleteration()
{
	
	return 0;
}

float ADXL345::convertRawToFloat(int16_t value)
{
	
	return 0;
}