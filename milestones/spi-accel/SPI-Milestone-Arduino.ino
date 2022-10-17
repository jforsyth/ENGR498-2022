#include <Arduino.h>

int csPin=7;

void setupADXL(int _CS_PIN)
{
  
  //***Step #0***
  csPin=_CS_PIN;
  
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

byte readRegister(byte address)
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

void writeRegister(byte address, byte value)
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

bool selfTest()
{
  
  //implement code to check if you can
  //read the DEVICE_ID register. Return TRUE if
  //the correct result is found, otherwise FALSE.
  
  return false;
}

void readMultiBytes(uint8_t baseAddress, int num, uint8_t data[])
{
  
  return;
}

int16_t getXAcceleteration()
{
  
  return 0;
}

int16_t getYAcceleteration()
{
  
  return 0;
}

int16_t getZAcceleteration()
{
  
  return 0;
}

float convertRawToFloat(int16_t value)
{
  
  return 0;
}


void setup() {

  //**Step #1: Initialize the ADXL345 and select your CS pin**
  setupADXL(7);
  
  //**Step #2: Perform a self-test to see if you can read
  //from the accelerometer. Device will not progress is self-test fails.
  bool success = selfTest();
  
  //infinite loop if self-test fails
  while(!success){}
    
}

void loop() {
  
  //read x-axis
  int16_t xAxis=getXAcceleteration();
  
  //read y-axis
  int16_t yAxis=getYAcceleteration();
  
  //read z-axis
  int16_t zAxis=getZAcceleteration();

  //your Arduino will hate this but we need to test....
  int magnitude = sqrt(xAxis*xAxis + yAxis*yAxis + zAxis*zAxis);
  
  //result should be ~1g when ADXL345 is not moving
  float acceleration = convertRawToFloat(magnitude);
  
}