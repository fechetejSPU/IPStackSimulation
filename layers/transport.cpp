#include "transport.h"
#include <iostream>
#include <string>

using namespace std;

string transportAddon = "TRANS_HDR|";

void sendTransportLayer(string outputMessage) {
    myMessage = transportAddon + outputMessage;
}

void receiveTransportLayer(string outputMessage) {
    size_t p = -1;
    string tempAddon = transportAddon;
    while ((p = outputMessage.find(transportAddon)) != string::npos)
        outputMessage.replace(p, tempAddon.length(), "");
    myMessage = outputMessage;
}