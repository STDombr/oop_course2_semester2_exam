cmake_minimum_required(VERSION 3.14)
project(oop_course2_semester2_exam)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

include_directories(Lists)
include_directories(Trees)
include_directories(Essences)
include_directories(Uis)

add_executable(oop_course2_semester2_exam main.cpp
        Essences/Server.cpp Essences/Server.h Essences/Book.cpp Essences/Book.h
        Lists/ContainerInterface.cpp Lists/ContainerInterface.h
        Lists/Node.cpp Lists/Node.h
        Uis/mainwindow.cpp Uis/mainwindow.h Uis/mainwindow.ui
        Uis/addelement.cpp Uis/addelement.h Uis/addelement.ui
        Uis/AddBook.cpp Uis/AddBook.h Uis/AddBook.ui
        Uis/AddServer.cpp Uis/AddServer.h Uis/AddServer.ui)

find_package(Qt5Widgets)

qt5_use_modules(oop_course2_semester2_exam Widgets)
