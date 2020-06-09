//
// Created by User on 08.06.2020.
//

#ifndef OOP_COURSE2_SEMESTER2_EXAM_DLLIST_H
#define OOP_COURSE2_SEMESTER2_EXAM_DLLIST_H

#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "ContainerInterface.h"
#include "Server.h"
#include "Book.h"
#include "Node.h"

using namespace std;

/**
 * Template interface structure for the List structure that is based on the linked list
 */
template <class T>
class DLList : ContainerInterface <T>  {
private:

    Node <T> *head, *tail;                     //two pointers on the first and the last node
    int node_sum;                              //number of the nodes in list

    /**
     * Returns the max int in the list
     *
     * @return the max int in the list
    */
    int get_max_int();

    /**
 * Function that swaps the data between indexes
 *
 * @param a Index a to swap
 * @param b Index b to swap
 */
    void swap(Node <T> *a, Node <T> *b);

    /**
     * Utility function for quicksort that sorts the linked list relatively to the pivot(< or > than pivot)
     *
     * @param start The start of the linked list to sort
     * @param finish The finish of the linked list to sort
     * @return the Index of the end of the sorted part of the linked list
     */
    Node <T>* partition_quicksort(Node <T>* start, Node <T>* finish);

    /**
     * Function that performs the quicksort algorithm
     *
     * @param start The start of the sublist to sort
     * @param finish The end of the sublist to sort
     */
    void _quicksort(Node <T>* start, Node <T>* finish);

    /**
     * The function that divides the linked list in two linked lists
     * The first linked list is saved in the **first, the second linked list is saved in the **second
     *
     * @param start The linked list to divide
     * @param first The first part of the input linked list
     * @param second The second part of the input linked list
     */
    void listsplit_mergesort(Node <T> *start, Node <T> **first, Node <T> **second);

    /**
     * The function that merges two linked lists in one
     *
     * @param first The first linked list
     * @param second The second linked list
     * @return The merged linked list
     */
    Node <T> *merge(Node <T> *first, Node <T> *second);


    /**
    * Function that performs the mergesort algorithm
    *
    * @param source The pointer on the linked list that would be sorted
    */
    void _mergesort(Node <T> **source);

    /**
    * Utility function for countingsort that fills the input arrays with zeros.
    *
    * @param in The input array to fill
    * @param length The length of this array
    */
    void fill_array_0(int in[], int length);
public:

    /**
     * Default constructor
     */
    DLList();

    /**
     * Function that get the data by index
     */
    T get_by_index(int index) override;

    /**
    * Returns the pointer on the tail of the list
    *
    * @return the pointer on the tail of the list
    */
    Node <T>* get_tail();

    /**
     * Returns the pointer on the head of the list
     *
     * @return the pointer on the head of the list
     */
    Node <T>* get_head();

    /**
    * Function that adds the Element to the List
    *
    * @param val The value that would be added to the List
    */
    void add_element(T val) override;

    /**
    * Function that adds the Node to the List
    *
    * @param val The value that would be added to the List
    */
    void add_node(Node<T> val) override;

    /**
     * Deletes the last element of the list
     *
     * @return the element in the tail of the list
     */
    bool pop_node() override;

    /**
     * Deletes the element from the list
     * @param element to delete
     * @return true if success
     */
    bool delete_node(T element) override ;

    /**
     * Checks whether the element is present in the list
     * @param element the element to check
     * @return true if present
     */
    bool is_present(T element) override;

    /**
     * Function returns the current size of the list
     */
    int get_curr_size() override;

    /**
    * Function that prints all the data from the list on the screen
    */
    void display() override;

    /**
    * Function that performs the selection sort algorithm
    */
    void selection_sort() override;

    /**
    * Function that basically calls the _quicksort function that is in private section
    */
    void quicksort() override;

    /**
     * Function that performs the counting sort algorithm. Uses default arguments for simple countingsort.
     * The default values are changed in radixsort algorithm as countingsort is a part of radix sort.
     * This sorting algorithm is valid only for the integers in [0,50)
     *
     * @param exp The default argument that equals 1 for the default countingsort. Contains the value that equals
     *        10^(exp-1) in radixsort algorithm where i is number of recursive iteration
     * @param max_int The default argument that equals 50 for the default countingsort. Means the maximum possible
     *        value for a sorted integer
     */
    void countingsort(int exp = 1, int max_int = 50) override;

    /**
    * Function that basically calls the _mergesort function that is in private section
    */
    void mergesort() override;
    /**
    * Function that performs the bucketsort sort algorithm
    */
    void bucketsort() override ;

    /**
     * operator [] gets the element of the input index
     * @param i input index
     * @return the element of the input index
     */
    T &operator[](int i) override;

    /**
     * @param name The KEY value tp find th server
     * @return the server with the inputted name
     */
    T* get_Server_by_serverID(string serverID) override;

    T* get_book_by_name(string name) override;

    bool change_companyName_by_serverID(string serverID, string newCompanyName) override;

    bool change_genre_by_name(string name, string newGenre) override ;

    bool add_Server_by_serverID(string serverID, string name, string dataCenter, string rackModel) override ;

    bool add_book_by_name(string company, string author, int year, string genre, string name) override ;

    bool delete_Server_by_serverID(string serverID) override;

    bool delete_book_by_name(string name) override ;

    bool generate(int amount) override;

    DLList<T>* get_part_start(int amount) ;

    DLList<T>* get_part_end(int amount) ;
};

/**
 * UNION OPERATION
 */
template <class T>
DLList<T> operator + (DLList<T> l1, DLList<T> l2);

/**
 * INTERSECT OPERATION
 */
template <class T>
DLList<T> operator * (DLList<T> l1, DLList<T> l2);

/**
 * EXCEPT OPERATION
 */
template <class T>
DLList<T> operator - (DLList<T> l1, DLList<T> l2);

/**
 * SYMMETRIC EXCEPT OPERATION
 */
template <class T>
DLList<T> operator % (DLList<T> l1, DLList<T> l2);

#endif //OOP_COURSE2_SEMESTER2_EXAM_DLLIST_H
