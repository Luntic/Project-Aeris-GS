#include "Player.h"
#include <iostream>

Player::Player(SOCKET socket, const std::string& id)
    : clientSocket(socket), accountId(id) {}

Player::~Player() {
    closesocket(clientSocket);
}

void Player::Send(const std::string& msg) {
    send(clientSocket, msg.c_str(), static_cast<int>(msg.size()), 0);
}

SOCKET Player::GetSocket() const {
    return clientSocket;
}

std::string Player::GetId() const {
    return accountId;
}