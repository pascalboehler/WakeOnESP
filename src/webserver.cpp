#include "webserver.h"

WebServer::WebServer(String title) {
    WebServer::title = title;
    Serial.println("I AM ALIVE");
}

String WebServer::generateWebsite(bool powerStatus) {

    WebServer::genHeader();

    return WebServer::updateSite(powerStatus);
}

String WebServer::updateSite(bool isOn) {
    WebServer::genBody(isOn);

    String webContent = "<!DOCTYPE html><html>" + WebServer::header + WebServer::body + "</html>";

    return webContent;
}

void WebServer::genHeader() {
    WebServer::header = "<head><title>" + WebServer::title + "</title></head>";
}

void WebServer::genBody(bool isOn) {
    WebServer::body = "<body><h1>Wake on ESP System</h1>";
    WebServer::body += "<h2>Current system status</h2>";
    WebServer::body += "<h3>The system is currently turned ";
    if (isOn) {
        WebServer::body += "on</h2>";
        WebServer::body += "<p><a href=\"/pc/off\"><button class=\"button\">Turn Off</button></a></p>";
    } else {
        WebServer::body += "off</h3>";
        WebServer::body += "<p><a href=\"/pc/on\"><button class=\"button\">Turn On</button></a></p>";
    }

    WebServer::body += "</body>";
    
}

void WebServer::areYouAlive() {
    Serial.println("Hey, I am ok and this is my title: " + WebServer::title);
}