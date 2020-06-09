#include <iostream>
#include <ctime>
#include "DLCircularList.h"

using namespace std;

int main() {
    srand(time(0));
    DLCircularList<int> D;
    D.generate(2);
    D.display();
    return 0;
}