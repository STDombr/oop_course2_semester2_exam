#include <iostream>
#include <DLList.h>

using namespace std;

int main() {

    DLList<int> ta;
    ta.generate(5);
    ta.display();
    return 0;
}