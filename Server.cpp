//
// Created by User on 08.06.2020.
//

#include "Server.h"

#include <utility>

Server::Server() = default;

Server::Server(string name, string dataCenter, string rackModel, string serverID) {
    this->companyName = std::move(name);
    this->dataCenterAddress = std::move(dataCenter);
    this->rackModel = std::move(rackModel);
    this->serverID = std::move(serverID);

}

string Server::get_serverID() {
    return serverID;
}

void Server::set_companyName(string name) {
    this->companyName = std::move(name);
}

bool operator==(Server left, Server right) {
    return (left.serverID == right.serverID);
}

string Server::get_dataCenterAddress() {
    return dataCenterAddress;
}

string Server::get_rackModel() {
    return rackModel;
}

string Server::get_companyName() {
    return companyName;
}
