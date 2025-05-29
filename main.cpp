#include "layers/application.h"
#include "layers/transport.h"
#include "layers/link.h"
#include "layers/network.h"

#include <iostream>
#include <string>

using namespace std;

string myMessage;

void recieveMessage(string message);

int main() {
    cout << "Starting program..." << endl << endl;

    setApplicationCallback(recieveMessage);

    cout << "Enter your message: ";
    getline(cin, myMessage);

    cout << endl << "Message sent: " << myMessage << endl << endl;

    cout << "==== Sending ====" << endl;
    sendApplicationLayer(myMessage);


    cout << endl << "Program complete." << endl;
    return 0;
}

void recieveMessage(string message) {
    cout << endl << "Final message received: " << message << endl;
}
