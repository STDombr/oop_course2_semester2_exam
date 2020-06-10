#include <iostream>
#include <ctime>
#include <ContainerInterface.h>
#include <Book.h>
#include <Server.h>
#include <QtWidgets/QApplication>
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    srand(time(0));

    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    //return a.exec();

    ContainerInterface<int>* temp = new DLCircularList<int>();
    temp->generate(5);
    temp->display();
    temp->mergesort();
    temp->display();


    return 0;
}
