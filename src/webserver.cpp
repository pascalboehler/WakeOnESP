#include "webserver.h"

WebServer::WebServer(String pathToFile) {
    WebServer::websiteContent = pathToFile;
}

String WebServer::generateWebsite(bool powerStatus) {

    return WebServer::websiteContent;
}