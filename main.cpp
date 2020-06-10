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
    w.show();
    return a.exec();



    return 0;
}
