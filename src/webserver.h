#include <WiFi.h>

class WebServer {
public:
    WebServer(String);
    String generateWebsite(bool powerStatus);

private:
    String websiteContent;

};