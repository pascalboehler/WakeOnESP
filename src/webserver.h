#include <WiFi.h>
#include <Arduino.h>

class WebServer {
public:
    WebServer(String);
    String generateWebsite(bool powerStatus);
    String updateSite(bool powerStatus);
    void areYouAlive(void);

private:
    String title;
    String body;
    String header;
    void genHeader();
    void genBody(bool isOn);


};