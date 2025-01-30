//
// Created by rolek on 09.01.2025.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_CLIENTMANAGER_H
#define PROJEKTPROGRAMOWANIE_WSTI_CLIENTMANAGER_H

#include "Client.h"
#include <vector>

class ClientManager {
private:
    std::vector<Client*> clientsList;

public:
    ClientManager() = default;
    ~ClientManager();

    void addClient(const std::string& fName, const std::string& lName, const std::string& email, const std::string& phone);
    void removeClient(Client* client);
    const std::vector<Client*>& getClients() const;
    void addClientsFromFile(const std::vector<Client*>& clients);

    Client* findClientByLastName(const std::string& lastName);
};

#endif

