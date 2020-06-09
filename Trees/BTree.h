//
// Created by User on 09.06.2020.
//

#ifndef OOP_COURSE2_SEMESTER2_EXAM_BTREE_H
#define OOP_COURSE2_SEMESTER2_EXAM_BTREE_H

#include "ContainerInterface.h"
#include "Server.h"
#include "Book.h"


class BTreeNode
{
    int *keys;
    int t;
    BTreeNode **C;
    int n;
    bool leaf;
public:
    /**
     * Constructor
     * @param _t
     * @param _leaf
     */
    BTreeNode(int _t, bool _leaf);

    /**
     * A function to traverse all nodes in a subtree rooted with this node
     */
    void traverse();

    /**
     * A function to search a key in the subtree rooted with this node.
     * @param k
     * @return returns NULL if k is not present.
     */
    BTreeNode *search(int k);

    /**
     * A utility function to insert a new key in the subtree rooted with
     * @param k
     */
    void insertNonFull(int k);

    /**
     * A utility function to split the child y of this node. i is index of y in
     * @param i
     * @param y
     */
    void splitChild(int i, BTreeNode *y);


    /**
     * A function that returns the index of the first key that is greater
     * @param k
     * @return
     */
    int findKey(int k);

    /**
     * A wrapper function to remove the key k in subtree rooted with
     * @param k
     */
    void remove(int k);

    /**
     * A function to remove the key present in idx-th position in
     * @param idx
     */
    void removeFromLeaf(int idx);

    /**
     * A function to remove the key present in idx-th position in
     * @param idx
     */
    void removeFromNonLeaf(int idx);

    /**
     * A function to get the predecessor of the key- where the key
     * @param idx
     * @return
     */
    int getPred(int idx);

    /**
     * A function to get the successor of the key- where the key
     * @param idx
     * @return
     */
    int getSucc(int idx);

    /**
     * A function to fill up the child node present in the idx-th
     * @param idx
     */
    void fill(int idx);

    /**
     * A function to borrow a key from the C[idx-1]-th node and place
     * @param idx
     */
    void borrowFromPrev(int idx);

    /**
     * A function to borrow a key from the C[idx+1]-th node and place it
     * @param idx
     */
    void borrowFromNext(int idx);

    /**
     * A function to merge idx-th child of the node with (idx+1)th child of
     * @param idx
     */
    void merge(int idx);

};

template <class T>
class BTree : ContainerInterface<T>
{
    BTreeNode *root;
    int t;
public:
    /**
     * Constructor (Initializes tree as empty)
     *
     */
    BTree();

    /**
     * function to traverse the tree
     */
    void print();

    /**
     * function to search a key in this tree
     * @param k
     * @return
     */
    BTreeNode* search(int k);

    /**
     * The main function that inserts a new key in this B-Tree
     * @param k
     */
    void insert(int k);

    /**
     * The main function that removes a new key in thie B-Tree
     * @param k
     */
    void remove(int k);
};


#endif //OOP_COURSE2_SEMESTER2_EXAM_BTREE_H
