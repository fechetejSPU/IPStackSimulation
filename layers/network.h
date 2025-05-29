#ifndef NETWORK_H
#define NETWORK_H
#include <string>

using namespace std;

extern string myMessage;
bool sendNetworkLayer(string outputMessage);
bool receiveNetworkLayer(string outputMessage);


#endif //NETWORK_H
