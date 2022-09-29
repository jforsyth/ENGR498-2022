/**
 * In this example we will utilize the internal ATMEL provided data structures
 * to turn the light ON and OFF. Instead of creating pointers to PORTC and DDRC we can reference
 * them directly as if they were variables. They aren't (actually) but reading or writing to 
 * the variable "DDRC" or "PORTC" will have the same effect as using the pointers.
 */
 
void setup() {

  /**
     Step 1: Instead of using the call pinMode(13,OUTPUT) write a 0x1 to
     bit 7 in the DDRC register. Follow the guide in the lecture notes to
     accomplish this. (This is already done for you)
  */
 DDRC = DDRC | (0x1 << 7);
}

void loop() {
  /**
    Step 2: Instead of using the call digitalWrite(13,HIGH) write a 0x1 to
    bit 7 in the PORTC register. Use the ATMEL data structs to accomplish this.
  */
   //Your code here

  //delay 500ms
  delay(500);

  /**
    Step 3: Instead of using the call digitalWrite(13,LOW) clear bit 7
    in the PORTC register. Use the ATMEL data structs to accomplish this.
  */
  //Your code here

  //delay 500ms
  delay(500);
}