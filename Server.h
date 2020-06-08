//
// Created by User on 08.06.2020.
//

#ifndef OOP_COURSE2_SEMESTER2_EXAM_SERVER_H
#define OOP_COURSE2_SEMESTER2_EXAM_SERVER_H

#include <string>

using namespace std;

class Server {
private:
    string companyName; // VALUE
    string dataCenterAddress;
    string rackModel;
    string serverID;  // KEY

public:
    Server();
    Server(string, string, string, string);

    string get_serverID();
    string get_dataCenterAddress();
    string get_rackModel();
    string get_companyName();

    void set_companyName(string name);

    /**
     * Allows to get the answer of the operator "=="
    *
    * @param left  The parameter that would be passed on the left of the "<="
    * @param right The parameter that would be passed on the right of the "<="
    * @return The bool value that define the answer of the operator "<="
    */
    friend bool operator == (Server left, Server right);
};


#endif //OOP_COURSE2_SEMESTER2_EXAM_SERVER_H
