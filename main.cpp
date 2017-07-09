#include "dirtyudp.h"
// -------------------------------------------------------------- //
// Demo app using my dirtyudp lib, which is a quick-and-dirty,    //
// object-oriented implementation of both halves of a UDP server. //
// -------------------------------------------------------------- //
// Compile with sender set to true to build an example UDP client //
// or set sender to false to build an example UDP server.         //
// -------------------------------------------------------------- //
int main(int argc, char** argv) {
  bool sender = true;
  if(sender) {
    char* message = "Whaasssssaaaaaap?";
    UdpSender* sender = new UdpSender("127.0.0.1", 9999, 1024);
    sender->Send(message, strlen(message));
  } else {
    UdpReceiver* receiver = new UdpReceiver(9999, 1024);
    while(1) receiver->Loop();
  }
  return 0;
}
