#include "transport.h"
#include "network.h"
#include "link.h"
#include <iostream>
#include <string>

using namespace std;

string networkAddon = "NET_HDR|";

bool sendNetworkLayer(string outputMessage) {
    cout << "[Network Layer] Sending: " << outputMessage << endl;
    myMessage = networkAddon + outputMessage;
    return sendLinkLayer(myMessage);
}

bool receiveNetworkLayer(string outputMessage) {
    cout << "[Network Layer] Receiving: " <<  outputMessage << endl;
    size_t p = -1;
    string tempAddon = networkAddon;
    while ((p = outputMessage.find(networkAddon)) != string::npos)
        outputMessage.replace(p, tempAddon.length(), "");
    myMessage = outputMessage;
    return receiveTransportLayer(myMessage);
}
