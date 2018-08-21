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
  flashLed(13, 5,10);
  Serial1.begin(9600);
  xbee.begin(Serial1);
  Serial.begin(9600);
  
}
void loop() {
String sample;
  xbee.readPacket(); 
    if (xbee.getResponse().isAvailable()) {
      Serial.println(xbee.getResponse().getApiId());
      if (xbee.getResponse().getApiId() == ZB_RX_RESPONSE) {
        xbee.getResponse().getZBRxResponse(rx);
        for (int i = 0; i < rx.getDataLength(); i++) {
          sample += (char)rx.getData(i);
        }
        Serial.println(sample);
      }
    }else if (xbee.getResponse().isError()) {
      Serial.println("Error reading packet.  Error code: ");  
      Serial.println(xbee.getResponse().getErrorCode());
  } 
  delay(100);
}
