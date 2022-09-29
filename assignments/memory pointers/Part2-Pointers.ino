/**
   Step #1: Fill in the address of PORTC and DDRC registers below
*/

#define PORTC_MEMORY_ADDRESS //fill in the PORTC address here
#define DDRC_MEMORY_ADDRESS //fill in the DDRC address here

/**
   Step #2: Cast PORTC_MEMORY_ADDRESS and DDRC_MEMORY_ADDRESS as (uint8_t*) objects
*/
uint8_t* portCPtr = //complete the pointer here
uint8_t* ddrcPtr = //complete the pointer here

void setup() {

  /**
     Step 3: Instead of using the call pinMode(13,OUTPUT) write a 0x1 to
     bit 7 in the DDRC register. Follow the guide in the lecture notes to
     accomplish this. (This has already been done for you).
  */
  *ddrcPtr = *ddrcPtr | (0x1 << 7);
}

void loop() {
  /**
    Step 4: Instead of using the call digitalWrite(13,HIGH) write a 0x1 to
    bit 7 in the PORTC register. Follow the guide in the lecture notes to
    accomplish this.
  */
  //Your code here
  
  
  //delay 500ms
  delay(500);

  /**
    Step 5: Instead of using the call digitalWrite(13,LOW) clear bit 7
    in the PORTC register. Follow the guide in the lecture notes to
    accomplish this.
  */
  //Your code here

  //delay 500ms
  delay(500);
}