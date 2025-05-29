#include "application.h"
#include "transport.h"
#include "network.h"
#include <iostream>
#include <string>

using namespace std;

string transportAddon = "TRANS_HDR|";

void sendTransportLayer(string outputMessage) {
    cout << "[Transport Layer] Sending: " << outputMessage << endl;
    myMessage = transportAddon + outputMessage;
    sendNetworkLayer(myMessage);
}

void receiveTransportLayer(string outputMessage) {
    cout << "[Transport Layer] Receiving: " <<  outputMessage << endl;
    size_t p = -1;
    string tempAddon = transportAddon;
    while ((p = outputMessage.find(transportAddon)) != string::npos)
        outputMessage.replace(p, tempAddon.length(), "");
    myMessage = outputMessage;
    receiveApplicationLayer(myMessage);
}
