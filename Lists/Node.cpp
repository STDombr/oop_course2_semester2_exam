//
// Created by User on 09.06.2020.
//

#include "Node.h"


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