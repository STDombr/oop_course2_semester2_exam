//
// Created by User on 08.06.2020.
//

#ifndef OOP_COURSE2_SEMESTER2_EXAM_RBTREE_H
#define OOP_COURSE2_SEMESTER2_EXAM_RBTREE_H

#include <string>
#include <iostream>
#include "Server.h"
#include "ContainerInterface.h"

template <class T>
class treeNode{
public:
    std::string color;
    T* key;
    int size;
    treeNode* left;
    treeNode* right;
    treeNode* prev;


    explicit treeNode(T* key);
    void print();

};

template <class T>
class RBTree : ContainerInterface<T>{
public:
    treeNode<T>* root=NULL;

    RBTree();
    void add(treeNode<T>* z);
    void print();
    void Remove(treeNode<T>* z);
    T* get_Server_by_serverID(std::string name) override;
    treeNode<T>* SearchElement(int rank);
    int SearchRank(std::string name);

private:
    T* SearchName(treeNode<T>* x,std::string name);
    treeNode<T>* SearchByRank(treeNode<T>* x,int rank);
    void show_tree_graph_aux(treeNode<T>* start, int space);
    void Transplant(treeNode<T>* u,treeNode<T>* v);
    treeNode<T>* TreeMin(treeNode<T>* x);
    void RemoveFix(treeNode<T>* x);
    void LeftRotate(treeNode<T>* x);
    void RightRotate(treeNode<T>* x);
    void AddFix(treeNode<T>* z);
    void SizeFix();
    void SizeFixFromRoot(treeNode<T>* x);
};


#endif //OOP_COURSE2_SEMESTER2_EXAM_RBTREE_H
