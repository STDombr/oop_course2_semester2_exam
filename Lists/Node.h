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


#endif //OOP_COURSE2_SEMESTER2_EXAM_NODE_H
