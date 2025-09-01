#include "Network.h"
#include <iostream>

SOCKET ListenSocket = INVALID_SOCKET;

bool InitNetwork(int port) {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (result != 0) return false;

    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        WSACleanup();
        return false;
    }

    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = INADDR_ANY;
    service.sin_port = htons(port);

    if (bind(ListenSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR) {
        closesocket(ListenSocket);
        WSACleanup();
        return false;
    }

    if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
        closesocket(ListenSocket);
        WSACleanup();
        return false;
    }

    return true;
}

void CleanupNetwork() {
    closesocket(ListenSocket);
    WSACleanup();
}

SOCKET AcceptSocket() {
    SOCKET clientSocket = accept(ListenSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET) return INVALID_SOCKET;
    return clientSocket;
}