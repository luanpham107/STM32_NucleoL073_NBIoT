# 1 "c:\\Users\\luan\\Documents\\Laim_iotsolution\\stm32_dragino.ino"
/*

  Software serial multple serial test



 Receives from the hardware serial, sends to software serial.

 Receives from software serial, sends to hardware serial.



 The circuit:

 * RX is digital pin 10 (connect to TX of other device)

 * TX is digital pin 11 (connect to RX of other device)



 created back in the mists of time

 modified 25 May 2012

 by Tom Igoe

 based on Mikal Hart's example



 This example code is in the public domain.



 */
# 19 "c:\\Users\\luan\\Documents\\Laim_iotsolution\\stm32_dragino.ino"
# 20 "c:\\Users\\luan\\Documents\\Laim_iotsolution\\stm32_dragino.ino" 2

SoftwareSerial mySerial(10 , 11); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial2.begin(115200);
  while (!Serial2) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial2.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("AT");
}

void loop() { // run over and over
  if (mySerial.available()) {
    Serial2.write(mySerial.read());
  }
  if (Serial2.available()) {
    mySerial.write(Serial2.read());
  }
}
