/**
   Step #1: Fill in the address of PORTC and DDRC registers below
*/

#define PORTC_MEMORY_ADDRESS 0x28
#define DDRC_MEMORY_ADDRESS //fill in the DDRC address here

volatile uint8_t* portCPtr = (uint8_t*)(PORTC_MEMORY_ADDRESS);
volatile uint8_t* ddrcPtr = //complete the pointer here

void setup() {

  //set Digital Pin 13 as input
  pinMode(13, INPUT);

  //setup Serial port with default baud rate of 9600
  Serial.begin(9600);

  //wait 5s for Serial to spin up
  delay(5000);

  /**
     Step #2: Use a Serial.println statement to print out the contents
     of the DDRC register. DDRC[7] should read 0b as it is set to input.
	 (This has already been done for you)
  */
  Serial.print("Pin is input. DDRC: ");
  Serial.println(*ddrcPtr, BIN);

  //Set Digital Pin 13 as output
  pinMode(13, OUTPUT);


  /**
       Step #3: Use a Serial.println statement to print out the contents
       of the DDRC register. DDRC[7] should read 1b as it is set to output.
  */
  Serial.print("Pin is output. DDRC: ");
  //Your code here

}


void loop() {

  //turn on Digital Pin 13
  digitalWrite(13, HIGH);

  /**
     Step #4: Use a Serial.println statement to print out the contents
       of the PORTC register. PORTC[7] should read 1b as it is set to HIGH
  */
  Serial.print("Pin is HIGH. PORTC: ");
  //Your code here

  //delay 1s
  delay(1000);

  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  /**
    Step #5: Use a Serial.println statement to print out the contents
     of the PORTC register. PORTC[7] should read 0b as it is set to LOW
  */
  Serial.print("Pin is LOW. PORTC: ");
  //Your code here
  
  //delay
  delay(1000);                       // wait for a second
}