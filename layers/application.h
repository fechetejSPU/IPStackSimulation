#ifndef APPLICATION_H
#define APPLICATION_H
#include <string>

using namespace std;

extern string myMessage;
void sendApplicationLayer(string outputMessage);
void receiveApplicationLayer(string outputMessage);
void setApplicationCallback(void (*callbackSetting)(string));

#endif //APPLICATION_H
