#include <Arduino.h>
#include <WiFi.h>
#include "webserver.h"
#include "datahelper.h"


// Some global variables (i know, bad practice etc.)

int powerPin = 12;

int powerLEDPin = 14;

// WebServer on port 80

WiFiServer server(80);

// Some HTML headers
String header;

unsigned long currentTime = millis();

WebServer webServer = WebServer("testing");

DataHelper datahelper;

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

  Serial.println("Initializing SPFISS...");

  datahelper = DataHelper();

  Serial.println("Connecting to WiFi...");

  Serial.println("Loading credentials...");

  std::array<char*, 2> credentials = datahelper.getWiFiCredentials();

  char* ssid = credentials[0];
  char* pass = credentials[0];

  Serial.println(ssid);

  Serial.println(pass);

  Serial.print("Connecting");

  WiFi.begin(ssid, pass);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("Connected");

  Serial.print("Your IP is: ");

  Serial.println(WiFi.localIP().toString());

  Serial.println("Initiating the webserver...");

  //webServer = WebServer("tets");

  webServer.areYouAlive();

  Serial.println("Setting pin modes...");
  
  pinMode(powerPin, OUTPUT);
  pinMode(powerLEDPin, INPUT);

  Serial.println("Checking initial power state...");

  delay(1000); // wait one second for esp to init => this just needs some time
  
  if (isPoweredOn()) {
    Serial.println("System already turned on");
  } else {
    Serial.println("System is not powered on");
  }

  Serial.println("Done.");

  Serial.println("The website code we will display: ");
  Serial.println(webServer.generateWebsite(isPoweredOn()));
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    char c = client.read();
    Serial.println();
    header += c;
  }

  Serial.print("The current power state is: ");
  if (isPoweredOn()) {
    Serial.println("on");
  } else {
    Serial.println("off");
  }
  delay(5000);
  Serial.println("The current website shown is: ");
  Serial.println(webServer.updateSite(isPoweredOn()));
}

