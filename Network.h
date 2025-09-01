#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>

// AERIS socket state
extern SOCKET ListenSocket;

// setup + shutdown
bool InitNetwork(int port);
void CleanupNetwork();

// accept player sockets
SOCKET AcceptSocket();