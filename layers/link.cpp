#include "network.h"
#include "link.h"
#include <iostream>
#include <string>

using namespace std;

string linkAddon = "LINK_HDR|";

void sendLinkLayer(string outputMessage) {
    cout << "[Link Layer] Sending: " << outputMessage << endl;
    myMessage = linkAddon + outputMessage;

    // emulates sending it "over the wire" to another host
    cout << endl;
    receiveLinkLayer(myMessage);
}

void receiveLinkLayer(string outputMessage) {
    cout << "==== Receiving ====" << endl;
    cout << "[Link Layer] Receiving: " <<  outputMessage << endl;
    size_t p = -1;
    string tempAddon = linkAddon;
    while ((p = outputMessage.find(linkAddon)) != string::npos)
        outputMessage.replace(p, tempAddon.length(), "");
    myMessage = outputMessage;
    receiveNetworkLayer(myMessage);
}
