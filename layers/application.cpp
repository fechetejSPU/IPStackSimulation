#include "application.h"
#include <iostream>
#include <string>

using namespace std;

void sendApplicationLayer(string outputMessage) {
    cout << "[Application Layer] Sending: " << outputMessage;
}

void receiveApplicationLayer(string outputMessage) {
    cout << "[Application Layer] Receiving: APP_HDR|" << outputMessage;
}