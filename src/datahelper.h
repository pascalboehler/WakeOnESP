#include <Arduino.h>
#include <array>
#include <SPIFFS.h>

class DataHelper {
public:
    DataHelper();
    std::array<char*, 2> getWiFiCredentials();
    int loadDotEnv();
    int initFS();
};