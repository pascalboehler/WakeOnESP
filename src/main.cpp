#include <Arduino.h>
#include <WiFi.h>


// Some global variables (i know, bad practice etc.)

int powerPin = 12;

int powerLEDPin = 14;

// WiFi credentias

const char* ssid = "NETWORK";
const char* pass = "PASSWORD";

// WebServer on port 80

WiFiServer server(80);

// Some HTML headers
String header;

unsigned long currentTime = millis();

//WebServer webServer = WebServer("test");

void shortPress() {
  digitalWrite(powerPin, HIGH);
  delay(500);
  digitalWrite(powerPin, LOW);
}

void longPress() {
  Serial.println("Performing long press action");
}

void pressReset() {
  Serial.println("Resetting your pc");
}

bool isPoweredOn() {
  if (digitalRead(powerLEDPin) == HIGH) {
    return true;
  }
  return false;
}

void setup() {
  // put your setup code here, to run once:
  // TODO: Setup WiFi

  Serial.begin(115200);

  Serial.println("Starting up system...");

  Serial.println("Connecting to WiFi...");

  Serial.println("Setting pin modes...");
  
  pinMode(powerPin, OUTPUT);
  pinMode(powerLEDPin, INPUT);

  Serial.println("Checking initial power state...");

  delay(1000); // wait one second for esp to init
  
  if (isPoweredOn()) {
    Serial.println("System already turned on");
  } else {
    Serial.println("System is not powered on");
  }

  Serial.println("Done.");
}

void loop() {
  Serial.print("The current power state is: ");
  if (isPoweredOn()) {
    Serial.println("on");
  } else {
    Serial.println("off");
  }
  delay(5000);
}

