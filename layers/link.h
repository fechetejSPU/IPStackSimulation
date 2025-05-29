#ifndef LINK_H
#define LINK_H
#include <string>

using namespace std;

extern string myMessage;
bool sendLinkLayer(string outputMessage);
bool receiveLinkLayer(string outputMessage);

#endif //LINK_H
