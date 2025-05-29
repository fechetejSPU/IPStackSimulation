#include "transport.h"
#include "network.h"
#include "link.h"
#include <iostream>
#include <string>

using namespace std;

string networkAddon = "NET_HDR|";

void sendNetworkLayer(string outputMessage) {
    cout << "[Network Layer] Sending: " << outputMessage << endl;
    myMessage = networkAddon + outputMessage;
    sendLinkLayer(myMessage);
}

void receiveNetworkLayer(string outputMessage) {
    cout << "[Network Layer] Receiving: " <<  outputMessage << endl;
    size_t p = -1;
    string tempAddon = networkAddon;
    while ((p = outputMessage.find(networkAddon)) != string::npos)
        outputMessage.replace(p, tempAddon.length(), "");
    myMessage = outputMessage;
    receiveTransportLayer(myMessage);
}
