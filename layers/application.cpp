#include "application.h"
#include <iostream>
#include <string>

using namespace std;

void sendApplicationLayer(string outputMessage) {
    cout << "[Application Layer] Sending: " << outputMessage << endl;
}

void receiveApplicationLayer(string outputMessage) {
    cout << "[Application Layer] Receiving: APP_HDR|" << outputMessage << endl;
}

/*
Example of how program might run.

int main() {
    string myMessage = " ";
    cout << "Starting program..." << endl << endl;
    cout << "Enter your message: " << endl;
    cin >> myMessage;
    sendApplicationLayer(myMessage);
    receiveApplicationLayer(myMessage);
    cout << endl << "Program complete." << endl;
    return 0;
}

*/