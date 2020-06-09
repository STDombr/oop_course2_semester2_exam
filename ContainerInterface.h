//
// Created by User on 08.06.2020.
//

#ifndef OOP_COURSE2_SEMESTER2_EXAM_CONTAINERINTERFACE_H
#define OOP_COURSE2_SEMESTER2_EXAM_CONTAINERINTERFACE_H

#include <string>
#include "Node.h"

using namespace std;

/**
 * Template interface structure for the Container interface structure
 */
template <class T>
class ContainerInterface {
public:

    /**
     * Pure virtual function that adds the Element to the List
     *
     * @param val The value that would be added to the List
     */
    virtual void add_element(T val) = 0;

    /**
     * Pure virtual function that adds the Node to the List
     *
     * @param val The value that would be added to the List
     */
    virtual void add_node(Node<T> val) = 0;

    /**
     * Deletes the last element of the list
     *
     * @return the element in the tail of the list
     */
    virtual bool pop_node() = 0;

    /**
     * Deletes the element from the list
     * @param element to delete
     * @return true if success
     */
    virtual bool delete_node(T element) = 0;

    /**
     * Checks whether the element is present in the list
     * @param element the element to check
     * @return true if present
     */
    virtual bool is_present(T element) = 0;

    /**
      * Pure virtual function returns the current size of the list
      */
    virtual int get_curr_size() = 0;

    /**
     * Pure virtual function that prints all the data from the list on the screen
     */
    virtual void display() = 0;

    /**
     * Pure virtual function that get the data by index
     */
    virtual T get_by_index(int index) = 0;

    /**
    * Pure virtual function that performs the quicksort algorithm
    */
    virtual void quicksort() = 0;

    /**
    * Pure virtual function that performs the mergesort algorithm
    */
    virtual void mergesort() = 0;

    /**
    * Pure virtual function that performs the selection sort algorithm
    */
    virtual void selection_sort() = 0;

    /**
    * Pure virtual function that performs the bucketsort algorithm
    */
    virtual void bucketsort() = 0;
    /**
     * Pure virtual function that performs the counting sort algorithm. Uses default arguments for simple countingsort.
     * The default values are changed in radixsort algorithm as countingsort is a part of radix sort.
     * This sorting algorithm is valid only for the integers in [0,50)
     *
     * @param exp The default argument that equals 1 for the default countingsort. Contains the value that equals
     *        10^(exp-1) in radixsort algorithm where i is number of recursive iteration
     * @param max_int The default argument that equals 50 for the default countingsort. Means the maximum possible
     *        value for a sorted integer
     */
    virtual void countingsort(int exp = 1 , int max_int = 50) = 0;

    /**
     * operator [] gets the element of the input index
     * @param i input index
     * @return the element of the input index
     */
    virtual T &operator[](int i) = 0;

    /**
     * @param name The KEY value tp find th server
     * @return the server with the inputted name
     */
    virtual T* get_Server_by_serverID(string name) = 0;

    virtual bool change_companyName_by_serverID(string serverID, string newCompanyName) = 0;

    virtual bool add_Server_by_serverID(string serverID, string name, string dataCenter, string rackModel) = 0;

    virtual bool delete_Server_by_serverID(string serverID) = 0;

    virtual bool generate(int amount) = 0;

    virtual T* get_book_by_name(string name) = 0;

    virtual bool change_genre_by_name(string name, string newGenre) = 0;

    virtual bool add_book_by_name(string company, string author, int year, string genre, string name) = 0;

    virtual bool delete_book_by_name(string name) = 0;
};


#endif //OOP_COURSE2_SEMESTER2_EXAM_CONTAINERINTERFACE_H
