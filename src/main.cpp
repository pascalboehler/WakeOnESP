#include <Arduino.h>

int powerPin = 12;

void setup() {
  // put your setup code here, to run once:
  // TODO: Setup WiFi and Serial stuff

  Serial.begin(112000);

  
}

void loop() {

}

void powerOn() {
  Serial.println("Turning PC on... one moment");
}

void powerOff() {
  Serial.println("Turning PC off... one moment");
}

void longPress() {
  Serial.println("Performing long press action");
}

void pressReset() {
  Serial.println("Resetting your pc");
}