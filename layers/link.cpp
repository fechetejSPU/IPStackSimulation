#include "link.h"
#include <iostream>
#include <string>

using namespace std;

string linkAddon = "LINK_HDR|";

void sendLinkLayer(string outputMessage) {
    myMessage = linkAddon + outputMessage;
}

void receiveLinkLayer(string outputMessage) {
    size_t p = -1;
    string tempAddon = linkAddon;
    while ((p = outputMessage.find(linkAddon)) != string::npos)
        outputMessage.replace(p, tempAddon.length(), "");
    myMessage = outputMessage;
}
