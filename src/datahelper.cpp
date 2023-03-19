#include "datahelper.h"

DataHelper::DataHelper() {
    
    if (initFS() == 0) {
    Serial.println("Initalized FS");
  } else {
    Serial.println("Error occured initializing, abording startup");
    return;
  }

  if (loadDotEnv() == 0) {
    Serial.println("Loaded environment file");
  } else {
    Serial.println("Error loading environment files, aborting");
    return;
  }
}

int DataHelper::initFS() {
    if(!SPIFFS.begin(true)) {
        Serial.println("ERROR: ABORT. COULD NOT OPEN SPIFFS");
        return -1;
    }
    return 0;
}

int DataHelper::loadDotEnv() {
   File file = SPIFFS.open("/.env");
   //File file = SPIFFS.open("/test.txt");

    if(!file) {
        Serial.println("ERROR: ABORT MISSION. COULD NOT LOAD FILE");
        return -1;
    }

    // printing out the file (later will be handled by .env encoder)
    std::list<std::string> rawData;
    Serial.println("The file content");
    while (file.available()) {
        String curr = file.readString();
        Serial.print(curr);
        Serial.print(" ");
        rawData.push_back(curr.c_str()); // conv to cpp string and add it to the list
    }
    file.close();
    Serial.println("");
    dotEnvContent = parseDotEnvToMap(rawData); // convert it 
    if (dotEnvContent.size() == 0) { // it can not be empty, so if it is, error out
        return -1;
    }
    return 0;
}

std::map<std::string, std::string> DataHelper::parseDotEnvToMap(std::list<std::string> rawData) {
    for (std::string currLine : rawData) {
        Serial.println(currLine.c_str());
        
    }
    return {};
}

std::array<char*, 2> DataHelper::getWiFiCredentials() {
    return {"123", "345"};
}