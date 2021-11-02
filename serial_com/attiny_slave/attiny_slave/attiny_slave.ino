#include <TinyWire.h>
#include <microdome.h>

long dataReceived, dataSent;


void setup() {
  
  TinyWire.begin(0x44); 

  Serial.begin(115200); 

  TinyWire.onReceive( receiveLong ); 
  TinyWire.onRequest( sendLong ); 
}

void loop() {
  
}

void receiveLong() {
  long bytes[sizeof(long)]; 

  byte index = 0;
  while (TinyWire.available())
    bytes[index++] = TinyWire.read(); 

  dataReceived = 0; 
  for (int j = 0; j < sizeof(long); ++j)
     dataReceived += bytes[j] << 8 * j; 

  Serial.print("Data received: ");
  Serial.println(dataReceived); 
}

void sendLong(){
  dataSent = dataReceived; 
  byte bytes[sizeof(long)];

  for (int j= 0; j < sizeof(long); ++j)
    bytes[j] = dataSent >> 8 * j; 

  Serial.print("Data sent: "); 
  Serial.println(dataSent);
  TinyWire.send(bytes, sizeof(long)); 
  
}
