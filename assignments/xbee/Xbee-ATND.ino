//Use the #define statements below to "rename" the serial ports
//this should help better show where data is being received and sent.
#define USB Serial
#define Xbee Serial1

void setup() {

  //setup serial port connected to USB
  USB.begin(9600);

  //setup serial port connected to hard UART
  Xbee.begin(9600);

  delay(2000);

  USB.println("Hello world!");
}

void loop() {

  //send out AT command mode
  Xbee.print("+++");

  //wait for resposne
  while (Xbee.available() == 0) {}

  //read back the response from the Xbee
  while (Xbee.available() > 0)
  {
    char c = Xbee.read();
    USB.print(c);
  }

  //send back AT Network Discovery request
  Xbee.println("ATND");

  //wait for resposne
  while (Xbee.available() == 0) {}

  //read back the response from the Xbee
  while (Xbee.available() > 0)
  {
    char c = Xbee.read();
    USB.print(c);
  }
  USB.println("");


  delay(10000);
}