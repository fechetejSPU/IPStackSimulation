#include "network.h"
#include <iostream>
#include <string>

using namespace std;

string networkAddon = "NET_HDR|";

void sendNetworkLayer(string outputMessage) {
    myMessage = networkAddon + outputMessage;
}

void receiveNetworkLayer(string outputMessage) {
    size_t p = -1;
    string tempAddon = networkAddon;
    while ((p = outputMessage.find(networkAddon)) != string::npos)
        outputMessage.replace(p, tempAddon.length(), "");
    myMessage = outputMessage;
}
