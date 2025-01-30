#include "ClientManager.h"
#include <algorithm>
#include <iostream>

ClientManager::~ClientManager() {
    for (Client* c : clientsList) {
        delete c;
    }
}

void ClientManager::addClient(const std::string& fName, const std::string& lName, const std::string& email, const std::string& phone) {
    Client* newClient = new Client(fName, lName, email, phone);
    clientsList.push_back(newClient);
}

void ClientManager::removeClient(Client* client) {
    auto it = std::find(clientsList.begin(), clientsList.end(), client);
    if (it != clientsList.end()) {
        delete *it;
        clientsList.erase(it);
    }
}

const std::vector<Client*>& ClientManager::getClients() const {
    return clientsList;
}

void ClientManager::addClientsFromFile(const std::vector<Client*>& clients) {
    clientsList = clients;
}

Client* ClientManager::findClientByLastName(const std::string& lastName) {
    for (Client* client : clientsList) {
        if (client->getLastName() == lastName) {
            return client;
        }
    }
    return nullptr;
}
