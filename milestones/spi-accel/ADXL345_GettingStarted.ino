#include <SPI.h>

//use pin #7 as CS
const int CS_PIN = 7;

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

void setup() {

  //setup SPI interface for CPOL=1, CPHA=1 or SPI_MODE_3 in Arduino
  SPI.begin();
  SPI.setDataMode(SPI_MODE3); //this works best. New SPI_TRANSACTION is not well documented

  //set CS pin to HIGH
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN,HIGH);
}

void loop() {

  //Step #1: Attempt to read from DEVICE ID REGISTER

  //Step #2: Check to see if value returned was correct

  //Step #3: Attempt to write to known register (try TAP_THRESH as we don't use that feature)

  //Step #4: Read back your written value from TAP_THRESH. It should be the same.

  //add delay so we don't blow up serial port
  delay(1000);
}
