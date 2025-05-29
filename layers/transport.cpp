#include "application.h"
#include "transport.h"
#include "network.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string transportAddon = "TRANS_HDR|";

string checksum(string message);

void sendTransportLayer(string outputMessage) {
    cout << "[Transport Layer] Sending: " << outputMessage << endl;

    bool success = false;
    while (not success) {
        // Since this is done recursively without concurrency,
        // can't use the normal method of having an ACK response to listen for.
        // Intead, I use return values to check if a message was recieved.
        myMessage = checksum(outputMessage) + transportAddon + outputMessage;
        success = sendNetworkLayer(myMessage);
        if (not success) {
            cout << "Failed to send message, retrying" << endl;
            cout << "[Transport Layer] Sending: " << outputMessage << endl;
        }
    }
}

bool receiveTransportLayer(string outputMessage) {
    cout << "[Transport Layer] Receiving: " <<  outputMessage << endl;

    string recievedChecksum = outputMessage.substr(0, 4);
    string data = outputMessage.substr(4+transportAddon.length());
    if (recievedChecksum != checksum(data)) {
        cout << "Corruption detected, rejecting message" << endl;
        return false;
    }
    receiveApplicationLayer(data);
    return true;
}

string checksum(string message) {
    int checksum = 0;
    for (int i = 0; i < message.length(); i += 2) {
        //get the ascii code of the two characters
        int section = message[i] & 0b11111111;
        section = section << 8;
        if (i+1 < message.length()) {
            section += message[i+1] & 0b11111111;
        }

        checksum += section;
        //handle overflow
        if (checksum > 0b1111111111111111) {
            checksum -= 0b10000000000000000;
            checksum += 1;
        }
    }
    // invert the checksum
    checksum = checksum ^ 0b1111111111111111;

    // convert to hex
    stringstream checksum_str;
    checksum_str << hex << setfill('0') << setw(4) << checksum;

    return checksum_str.str();
}
