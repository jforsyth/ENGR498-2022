#include <Arduino.h>

//include header for the ADXL345 class
#include "ADXL345.h"

//create a static instance of the ADXL345 class
ADXL345 accel;

void setup() {

	//**Step #1: Initialize the ADXL345 and select your CS pin**
	accel.setup(7);
	
	//**Step #2: Perform a self-test to see if you can read
	//from the accelerometer. Device will not progress is self-test fails.
	bool success = accel.selfTest();
	
	//infinite loop if self-test fails
	while(!success){}
	
	Serial.begin(9600);
		
}

void loop() {
  
  
  //read x-axis
  volatile int16_t xAxis=accel.getXAcceleteration();
  
  //read y-axis
  volatile int16_t yAxis=accel.getYAcceleteration();
  
  //read z-axis
  volatile int16_t zAxis=accel.getZAcceleteration();

  //your Arduino will hate this but we need to test....(actually on the 32u4 it doesn't calculate this correctly unless all values are long)
  //256 should be ~1g
  volatile long magnitude = sqrt((long)xAxis*(long)xAxis + (long)yAxis*(long)yAxis + (long)zAxis*(long)zAxis);

  //print out all the accel data to serial
  Serial.print(xAxis); Serial.print(",");
  Serial.print(yAxis); Serial.print(",");
  Serial.print(zAxis);Serial.print(",");
  Serial.println(magnitude);

  delay(100);
}