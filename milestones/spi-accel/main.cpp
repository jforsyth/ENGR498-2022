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
		
}

void loop() {
  
	//read x-axis
	int16_t xAxis=accel.getXAcceleteration();
	
	//read y-axis
	int16_t yAxis=accel.getYAcceleteration();
	
	//read z-axis
	int16_t zAxis=accel.getZAcceleteration();

	//your Arduino will hate this but we need to test....
	int magnitude = sqrt(xAxis*xAxis + yAxis*yAxis + zAxis*zAxis);
	
	//result should be ~1g when ADXL345 is not moving
	float acceleration = accel.convertRawToFloat(magnitude);
}