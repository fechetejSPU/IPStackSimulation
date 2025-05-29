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
    bool success = false;
    while (not success) {
        // Since this is done recursively without concurrency,
        // can't use the normal method of having an ACK response to listen for.
        // Intead, I use return values to check if a message was recieved.
        success = sendNetworkLayer(myMessage);
        if (not success) {
            cout << "Failed to send message, retrying" << endl;
            cout << "[Transport Layer] Sending: " << outputMessage << endl;
        }
    }
}

bool receiveTransportLayer(string outputMessage) {
    cout << "[Transport Layer] Receiving: " <<  outputMessage << endl;
    size_t p = -1;
    string tempAddon = transportAddon;
    while ((p = outputMessage.find(transportAddon)) != string::npos)
        outputMessage.replace(p, tempAddon.length(), "");
    myMessage = outputMessage;
    receiveApplicationLayer(myMessage);
    return true;
}
