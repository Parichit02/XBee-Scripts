#include <XBee.h>
XBee xbee = XBee();
void setup() {
  Serial1.begin(9600);
  xbee.setSerial(Serial1);
}
void loop() {
  uint8_t data[] = {'H','I'};
//  XBeeAddress64 addr64 = XBeeAddress64();
//  addr64.setMsb(13A200);//XXXXX -> Msb address of router/end node
//  addr64.setLsb(4106FEB4);//XXXXX -> Lsb address of router/end node 
  XBeeAddress64 addr64 = XBeeAddress64(0x0013a200, 0x4163D1D9); //SL and SH of the destination XBee
  ZBTxRequest zbTx = ZBTxRequest(addr64, data, sizeof(data));
  xbee.send(zbTx);

  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
}
