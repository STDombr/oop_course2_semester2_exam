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
bool operator>=(Server left, Server right) {
    return (left.serverID >= right.serverID);
}
bool operator<=(Server left, Server right) {
    return (left.serverID <= right.serverID);
}
bool operator>(Server left, Server right) {
    return (left.serverID > right.serverID);
}
bool operator<(Server left, Server right) {
    return (left.serverID < right.serverID);
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

void Server::random() {
    char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    string temp1, temp2, temp3, temp4;
    int string_length;              //the length of the string
    string_length = rand() % 7 + 3;
    for(int k = 0; k < string_length; k++){
        temp1.push_back(alphanum[rand() % sizeof(alphanum)]); //adds a random symbol
        temp2.push_back(alphanum[rand() % sizeof(alphanum)]); //adds a random symbol
        temp3.push_back(alphanum[rand() % sizeof(alphanum)]); //adds a random symbol
        temp4.push_back(alphanum[rand() % sizeof(alphanum)]); //adds a random symbol
    }
    this->serverID = temp1;
    this->companyName = temp2;
    this->rackModel = temp3;
    this->dataCenterAddress = temp4;
}
