//Use the #define statements below to "rename" the serial ports
//this should help better show where data is being received and sent.
#define Xbee Serial1

void setup() {

  //setup serial port connected to hard UART
  Xbee.begin(9600);

  pinMode(13,OUTPUT);

  digitalWrite(13,HIGH);

  delay(1000);
}

boolean ledState = false;
void loop()
{
  //send out a single character
  Xbee.write('@');

  //toggle the LED
  digitalWrite(13,ledState);
  ledState = !ledState;

  //do this every second
  delay(1000);

}