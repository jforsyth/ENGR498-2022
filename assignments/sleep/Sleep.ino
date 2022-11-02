#include <avr/sleep.h>
#include <avr/interrupt.h>

/**
 * Define relevant USB Interrupt Flags and bits
 */

#define UDINT_ADDRESS 0xE1
#define UDIEN_ADDRESS 0xE2

#define USBCON_ADDRESS 0xD8
#define USBINT_ADDRESS 0xDA


volatile uint8_t* UDINT_PTR = (uint8_t*)UDINT_ADDRESS;
volatile uint8_t* USBINT_PTR = (uint8_t*)USBINT_ADDRESS;

volatile uint8_t* USBCON_PTR = (uint8_t*)USBCON_ADDRESS;
volatile uint8_t* UDIEN_PTR = (uint8_t*)UDIEN_ADDRESS;

/**
 * Use this function to disable USB interrupts. However, you may
 * have challenges talking with the PC again to program the board.
 */
void disableUSBInterrupts()
{
   //clear bit 4 to disbale WAKEUPE Interrupt
  *UDIEN_PTR = *UDIEN_PTR & ~(0x10);

  //clear bit 0 to disbale WAKEUPE Interrupt
  *UDIEN_PTR = *UDIEN_PTR & ~(0x01);

  //clear bit 0 to disable VBUSTI Interrupt
  *USBCON_PTR = *USBCON_PTR & ~(0x1); 
}

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  //let the Serial spin up
  delay(1000);

  Serial.println("Hello world!");

  /**
     Place a long delay here so that the device is not always asleep.
     Failure to do so will cause the device to "brick" and you cannot
     re-program via the SPI bootloader
  */
  delayLoop();
}

void delayLoop()
{
  Serial.println("Begin the count down! Blink Fast!");
  long starTime = millis();
  const long totalDelay = 20000;

  bool timeExpired = (millis() - starTime) > totalDelay;
  while (!timeExpired)
  {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);

    timeExpired = (millis() - starTime) > totalDelay;

    Serial.print(".");
  }
  Serial.println("");
}

boolean ledState = false;

void loop() {

  /**
     Follow the process in the ATMEL documentation to do to sleep.
     Try out different sleep modes.
     https://www.microchip.com/webdoc/AVRLibcReferenceManual/group__avr__sleep.html
  */

  /** The 5 different modes are:
            SLEEP_MODE_IDLE         -the least power savings
            SLEEP_MODE_ADC
            SLEEP_MODE_PWR_SAVE
            SLEEP_MODE_STANDBY
            SLEEP_MODE_PWR_DOWN     -the most power savings

    you can call them via set_sleep_mode(SLEEP_MODE_IDLE);...etc.
  */

  
  //set the desired sleep mode
  //***YOUR CODE HERE TO SET THE SLEEP MODES***
  

  //stop interrupts (execute atomically)
  cli();

  //disable USB interrupts for good measure
  disableUSBInterrupts();

  boolean someCondition = true;
  if (someCondition)
  {

    //print message and delay so serial is flushed.
    Serial.println("Good night!");
    Serial.flush();
    delay(1000);

    //enable sleep mode by setting the sleep bit
    sleep_enable();

    //Normally we would re-enable interrupts. However, Arduino sets up lots
    //of interrupts that we would have to turn off for this to work. Right now
    //we're just going to "not wake up" so we can see power levels.
    
    /* FOR THE LAB TO WORK YOU MUST COMMENT OUT THE LINE BELOW! */
    sei();

    //execute the sleep instruction and actually go to sleep
    sleep_cpu();

    //WAKE UP! First thing to do is disable sleep so we
    //don't do it again.
    sleep_disable();
  }
  sei();

  Serial.println("I'm alive!");

  digitalWrite(13, ledState);
  ledState = !ledState;

  delayLoop();
}
