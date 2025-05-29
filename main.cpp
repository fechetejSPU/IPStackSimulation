#include "layers/application.h"
#include "layers/transport.h"
#include "layers/link.h"
#include "layers/network.h"

#include <iostream>
#include <string>

using namespace std;

string myMessage;

int main() {
    cout << "Starting program..." << endl << endl;

    cout << "Enter your message: " << endl;
    getline(cin, myMessage);

    cout << endl << "Message sent: " << myMessage << endl << endl;

    cout << "==== Sending ====" << endl;
    cout << "[Application Layer] Sending: " << myMessage << endl;
    sendApplicationLayer(myMessage);
    cout << "[Transport Layer] Sending: " << myMessage << endl;
    sendTransportLayer(myMessage);
    cout << "[Network Layer] Sending: " << myMessage << endl;
    sendNetworkLayer(myMessage);
    cout << "[Link Layer] Sending: " << myMessage << endl;
    sendLinkLayer(myMessage);
    cout << endl;

    cout << "==== Receiving ====" << endl;
    cout << "[Link Layer] Receiving: " <<  myMessage << endl;
    receiveLinkLayer(myMessage);
    cout << "[Network Layer] Receiving: " <<  myMessage << endl;
    receiveNetworkLayer(myMessage);
    cout << "[Transport Layer] Receiving: " <<  myMessage << endl;
    receiveTransportLayer(myMessage);
    cout << "[Application Layer] Receiving: " <<  myMessage << endl;
    receiveApplicationLayer(myMessage);

    cout << endl << "Final message received: " << myMessage << endl;

    cout << endl << "Program complete." << endl;
    return 0;
}