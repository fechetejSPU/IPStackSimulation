#include "transport.h"
#include <iostream>
#include <string>

using namespace std;

void sendTransportLayer(string outputMessage) {
    cout << "[Transport Layer] Sending: APP_HDR|" << outputMessage << endl;
}

void receiveTransportLayer(string outputMessage) {
    cout << "[Transport Layer] Receiving: TRANS_HDR|APP_HDR|" << outputMessage << endl;
}