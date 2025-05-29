#include "application.h"
#include "transport.h"
#include <iostream>
#include <string>

using namespace std;

string applicationAddon = "APP_HDR|";

void (*recieveCallback)(string) = nullptr;

void sendApplicationLayer(string outputMessage) {
    cout << "[Application Layer] Sending: " << outputMessage << endl;
    myMessage = applicationAddon + outputMessage;
    sendTransportLayer(myMessage);
}

void receiveApplicationLayer(string outputMessage) {
    cout << "[Application Layer] Receiving: " <<  outputMessage << endl;
    size_t p = -1;
    string tempAddon = applicationAddon;
    while ((p = outputMessage.find(applicationAddon)) != string::npos)
        outputMessage.replace(p, tempAddon.length(), "");
    myMessage = outputMessage;

    if (recieveCallback) {
        recieveCallback(myMessage);
    }
}

void setApplicationCallback(void (*callbackSetting)(string)) {
    recieveCallback = callbackSetting;
}
