//Use the #define statements below to "rename" the serial ports
//this should help better show where data is being received and sent.
#define Xbee Serial1

void setup() {
  //setup serial port connected to hard UART
  Xbee.begin(9600);

  //turn on the LED
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
}

boolean ledState = false;
void loop()
{

  //While things are on UART (coming from Xbee) send up to USB (PC)
  while (Xbee.available() > 0)
  {
    //read the byte from Xbee as character
    uint8_t c = Xbee.read();

    //send it back where it came from!
    Xbee.write(c);

    //change state of LED so we know something was received
    digitalWrite(13,ledState);

    //change state of LED
    ledState = !ledState;
  }

  //short delay so not to overload USB/Serial
  delay(10);

}