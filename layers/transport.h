#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <string>

using namespace std;

extern string myMessage;
void sendTransportLayer(string outputMessage);
bool receiveTransportLayer(string outputMessage);

#endif //TRANSPORT_H
