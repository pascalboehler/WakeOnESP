#include "webserver.h"

WebServer::WebServer(String title) {
    WebServer::title = title;
    Serial.println("I AM ALIVE");
}

String WebServer::generateWebsite(bool powerStatus) {

    WebServer::genBody(powerStatus);
    WebServer::genHeader();

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

    } else {
        WebServer::body += "off</h3>";
    }

    WebServer::body += "</body>";
    
}

void WebServer::areYouAlive() {
    Serial.println("Hey, I am ok and this is my title: " + WebServer::title);
}