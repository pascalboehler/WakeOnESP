#include "datahelper.h"

DataHelper::DataHelper() {
    

}

int DataHelper::initFS() {
    if(!SPIFFS.begin(true)) {
        Serial.println("ERROR: ABORT. COULD NOT OPEN SPIFFS");
        return -1;
    }
    return 0;
}

int DataHelper::loadDotEnv() {
   // File file = SPIFFS.open("/.env");
   File file = SPIFFS.open("/test.txt");

    if(!file) {
        Serial.println("ERROR: ABORT MISSION. COULD NOT LOAD FILE");
        return -1;
    }

    // printing out the file (later will be handled by .env encoder)

    Serial.println("The file content");
    while (file.available()) {
        Serial.print(file.read());
    }
    file.close();
    return 0;
}

std::array<char*, 2> DataHelper::getWiFiCredentials() {
    return {"123", "345"};
}