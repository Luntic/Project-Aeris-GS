#pragma once
#include <winsock2.h>
#include <string>

class Player {
public:
    Player(SOCKET socket, const std::string& id);
    ~Player();

    void Send(const std::string& msg);
    SOCKET GetSocket() const;
    std::string GetId() const;

private:
    SOCKET clientSocket;
    std::string accountId;
};