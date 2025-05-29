#include "application.h"
#include <iostream>
#include <string>

using namespace std;

string applicationAddon = "APP_HDR|";

void sendApplicationLayer(string outputMessage) {
    myMessage = applicationAddon + outputMessage;
}

void receiveApplicationLayer(string outputMessage) {
    size_t p = -1;
    string tempAddon = applicationAddon;
    while ((p = outputMessage.find(applicationAddon)) != string::npos)
        outputMessage.replace(p, tempAddon.length(), "");
    myMessage = outputMessage;
}
