#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <string>

using namespace std;

extern string myMessage;
void sendTransportLayer(string outputMessage);
void receiveTransportLayer(string outputMessage);

#endif //TRANSPORT_H
