//
// Created by User on 09.06.2020.
//

#ifndef OOP_COURSE2_SEMESTER2_EXAM_NODE_H
#define OOP_COURSE2_SEMESTER2_EXAM_NODE_H

#include "Server.h"
#include "Book.h"

/**
 * Template Node structure that is used in the List structure
 */
template <class T>
class Node{
public:
    T data;             //Data that can contain and type of data
    Node* next;         //Pointer on the next element
    Node* prev;         //Pointer on the previous element

    /**
     * Default constructor
     */
    Node();
    /**
     * Function to generate random node
     */
    void generate();
};

//
// Created by User on 09.06.2020.
//

//#include "Node.h"


template<class T>
Node<T>::Node() {
    next = prev = nullptr;
}

template<class T>
void Node<T>::generate() {
    data = rand() % 1000;
}

template<>
void Node<std::string>::generate() {
    std::string s="";
    int l=rand()%10+1;
    for (int j=0;j<l;j++)
        s+= static_cast<char>(rand()%26+97);
    data = s;
}

template<>
void Node<Book>::generate() {
    data.random();
}

template<>
void Node<Server>::generate() {
    data.random();
}

#endif //OOP_COURSE2_SEMESTER2_EXAM_NODE_H
