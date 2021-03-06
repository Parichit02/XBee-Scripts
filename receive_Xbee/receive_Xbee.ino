#include <XBee.h>
XBee xbee = XBee();
XBeeResponse response = XBeeResponse();
ZBRxResponse rx = ZBRxResponse();

void flashLed(int pin, int times, int wait) {
    
    for (int i = 0; i < times; i++) {
      digitalWrite(pin, HIGH);
      delay(wait);
      digitalWrite(pin, LOW);
      
      if (i + 1 < times) {
        delay(wait);
      }
    }
}
void setup() {
  
  Serial1.begin(9600);
  xbee.begin(Serial1);
  pinMode(13, OUTPUT);  
  flashLed(13, 10,100);
  Serial.begin(9600);
}

void loop() {
String sample;
  xbee.readPacket(); 
    if (xbee.getResponse().isAvailable()) {
      flashLed(13,5,100);
//      Serial.println(xbee.getResponse().getApiId());
      if (xbee.getResponse().getApiId() == ZB_RX_RESPONSE) {
        xbee.getResponse().getZBRxResponse(rx);
        for (int i = 0; i < rx.getDataLength(); i++) {
          sample += (char)rx.getData(i);
        }
//        flashLed(13,10,100);
        Serial.println(sample);
      }
    }else if (xbee.getResponse().isError()) {
      Serial.println("Error reading packet.  Error code: ");  
      Serial.println(xbee.getResponse().getErrorCode());
  } 
  delay(100);
}
