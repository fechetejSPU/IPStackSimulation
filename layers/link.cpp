#include "network.h"
#include "link.h"
#include <iostream>
#include <string>

using namespace std;

string linkAddon = "LINK_HDR|";

bool sendLinkLayer(string outputMessage) {
    cout << "[Link Layer] Sending: " << outputMessage << endl;
    myMessage = linkAddon + outputMessage;

    // emulates sending it "over the wire" to another host
    cout << endl;

    cout << "Would you like to emulate a \"drop\", "
        "or let the message pass through (leave blank and hit enter)? ";
    string action;
    getline(cin, action);
    if (action == "drop") {
        cout << "Dropping packet" << endl << endl;
        return false;
    }
    cout << endl;
    return receiveLinkLayer(myMessage);
}

bool receiveLinkLayer(string outputMessage) {
    cout << "==== Receiving ====" << endl;
    cout << "[Link Layer] Receiving: " <<  outputMessage << endl;
    size_t p = -1;
    string tempAddon = linkAddon;
    while ((p = outputMessage.find(linkAddon)) != string::npos)
        outputMessage.replace(p, tempAddon.length(), "");
    myMessage = outputMessage;
    return receiveNetworkLayer(myMessage);
}
