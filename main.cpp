#include <iostream>
#include <ctime>
#include <ContainerInterface.h>
#include <Book.h>
#include <Server.h>

using namespace std;

int main() {
    srand(time(0));
    DLList<Server> Vetalmon;
    Vetalmon.generate(2);
    Vetalmon.display();

    DLCircularList<Book> STDombr;
    STDombr.generate(2);
    STDombr.display();
    return 0;
}