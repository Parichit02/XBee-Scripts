#include <XBee.h>

// create the XBee object
XBee xbee = XBee();

uint8_t payload[2];
// SH + SL Address of receiving XBee
XBeeAddress64 addr64 = XBeeAddress64(0x0013A200, 0x4106FEB4);


int pin5 = 0;

void setup() {
Serial1.begin(9600);
xbee.setSerial(Serial1);
pinMode(13, OUTPUT);
}

void loop() {
payload[0] = 0x00;
payload[1] = 0x01;

delay(3000);
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
xbee.send(zbTx);

digitalWrite(13, HIGH);
delay(1000);
digitalWrite(13, LOW);
delay(100);
}
