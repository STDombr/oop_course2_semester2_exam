cmake_minimum_required(VERSION 3.14)
project(oop_course2_semester2_exam)

set(CMAKE_CXX_STANDARD 14)
include_directories(Lists)
include_directories(Trees)
include_directories(Essences)

add_executable(oop_course2_semester2_exam main.cpp
        Essences/Server.cpp Essences/Server.h Essences/Book.cpp Essences/Book.h
        Lists/DLList.cpp Lists/DLList.h
        Lists/ContainerInterface.cpp Lists/ContainerInterface.h
        Lists/DLCircularList.cpp Lists/DLCircularList.h
        Lists/Node.cpp Lists/Node.h
        Trees/RBTree.cpp Trees/RBTree.h
        Trees/BTree.cpp Trees/BTree.h)
