#include <Arduino.h>

//include header for the ADXL345 class
#include "ADXL345.h"

//create a static instance of the ADXL345 class
ADXL345 accel;

void setup() {

	Serial.begin(9600);
	
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

	//print out the results as a comma separated value
	Serial.print(xAxis);
	Serial.print(",");
	Serial.print(yAxis);
	Serial.print(",");
	Serial.println(zAxis);
	
	//sample the accel at 50Hz
	delay(50);
}