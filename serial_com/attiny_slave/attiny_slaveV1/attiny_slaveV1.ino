#include <Wire.h>
#include <microdome.h>

long dataReceived, dataSent;


void setup() {

  Wire.begin(0x44); // 0x44

  Serial.begin(115200);

  Wire.onReceive(receiveLong);
  Wire.onRequest(sendLong);
}

void loop() {

}

void receiveLong() {
  long bytes[sizeof(long)];

  byte index = 0;
  while (Wire.available())
    bytes[index++] = Wire.read();

  dataReceived = 0;
  for (int j = 0; j < sizeof(long); ++j)
    dataReceived += bytes[j] << 8 * j;

  Serial.print("Data received: ");
  Serial.println(dataReceived);
}


void sendLong() {
  dataSent = dataReceived; // return what was recieved --- just to test !!
  byte bytes[sizeof(long)];

  for (int j = 0; j < sizeof(long); ++j)
    bytes[j] = dataSent >> 8 * j;

  Serial.print("Data sent: ");
  Serial.println(dataSent);
  Wire.write(bytes, sizeof(long));

}



//////////////////////////////////////////////////////////////////////////////
///////////////// Main Fuctions /////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void all_leds_on() {
  dataReceived = 0;

  if (dataReceived == 1) {
    // Turn all LEDs On
  }

  // Checker of the operation
  // if (all_leds_on){
  dataSent = 1;
  //}
}


void setLedsOnTile(int tile) {
  dataReceived = 0;

  if (dataReceived == 2) {
    // Turn all LEDs On Tile Number tile
  }

  // Checker of the operation
  // if (all_leds_on){
  dataSent = 2;
  //}
}


void setLed(int ledNb) {
  dataReceived = 0;

  if (dataReceived == 3) {
    // Turn all LEDs On Tile Number ledNb
  }

  // Checker of the operation
  // if (all_leds_on){
  dataSent = 3;
  //}
}


void SecuChecker() {
  dataReceived = 0;

  // Checker of the operation
  // if (all_leds_on){

  // If Something went Wrong 
  dataSent = 4;
  //}
}
